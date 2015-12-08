#include <vector>
#include <string>
#include <sstream>
#include "service.h"
#include "scientist.h"
#include "ui.h"
#include "datarepo.h"

service::service(){}

void service::init(){
    //Setup database connection
    //string databaseFile = "database.csv";
    //connection.setFile(databaseFile);
    //connection.connect();

    //get the database table
    //scientists = connection.fetchAll();

    db.connect();

    scientists = sci_db.fetchActive();
}

void service::run(){
    getStartInfo();
    while (true) {
        //Infinit loop until user wants to quit.

        // Get to know what the user wants.
        interface.renderText("Enter command: ");
        getUserInput();

        if (function == "quit" || function == "exit"){
            interface.renderText("Thank you for using our database, come back again soon. \n");
            break; // exit if user wants to.
            db.close();
        }
    }
}

void service::getUserInput(){
    input = interface.getInput();
    getFunction();
}

void service::getFunction(){
    // Find out what function user wanted.
    unsigned int functionSepPos = input.find(" ");
    function = input.substr(0, functionSepPos);
    input.erase(0,functionSepPos+1);

    // if User wants to render results
    if (function == "display"){
        interface.renderVector(scientists);
    }
    // If user wants to use Sort or Search
    else if (function == "sort" || function == "search"){
        //Get option
        interface.renderText("By what column? [name][gender][birth][death] \n");
        interface.renderText("Column: ");
        option = interface.getInput();
        while (option != "name" && option != "gender" && option != "birth" && option != "death"){
            interface.renderText("Not an avalible column, try again: [name][gender][birth][death] \n");
            interface.renderText("Column: ");
            option = interface.getInput();
        }
        if (function == "sort"){
            //getOrder
            interface.renderText("In what order? [asc][desc] \n");
            interface.renderText("Order: ");
            order = interface.getInput();
            while (order != "asc" && order != "desc"){
                interface.renderText("Not an avalible order, try again: [asc][desc] \n");
                interface.renderText("Order: ");
                order = interface.getInput();
            }
            //Calling requested function
            if (option == "name"){
                sortByName();
            }else if(option == "gender"){
                sortByGender();
            }else if (option == "birth"){
                sortByBirth();
            }else if (option == "death"){
                sortByDeath();
            }
            interface.renderText("Done sorting... \n");
        }else {
            //Get Search string from user
            interface.renderText("What to search for? \n");
            interface.renderText("Keyword: ");
            order = interface.getInput();

            //Searching in requested column.
            if (option == "name"){
                scientists = sci_db.fetchByName(order);
            }else if(option == "gender"){
                scientists = sci_db.fetchBySex(order);
            }else if (option == "birth"){
                scientists = sci_db.fetchByBorn(order);
            }else if (option == "death"){
                scientists = sci_db.fetchByDeath(order);
            }
        }

    }
    // Add scientist to the database.
    else if (function == "add"){
        addScientist();
    }
    // Get the help info.
    else if (function == "help"){
        getHelpInfo();
    }
    // Reset the search resault and get fresh from database.
    else if (function == "reset"){
        scientists = sci_db.fetchActive();
        interface.renderText("Results reset... \n");
    }else if (function == "exit" || function == "quit"){
        // exit;
    }else {
        interface.renderText("Invalid command! try [help] to get more info \n");
    }
}
//Setup for Ascending and Descending orders for Sort.
bool ascOrderName(const scientist sci1, const scientist sci2){return sci1.getName() < sci2.getName();}
bool descOrderName(const scientist sci1, const scientist sci2){return sci1.getName() > sci2.getName();}

bool ascOrderGender(const scientist sci1, const scientist sci2){return sci1.getSex() < sci2.getSex();}
bool descOrderGender(const scientist sci1, const scientist sci2){return sci1.getSex() > sci2.getSex();}

bool ascOrderBirth(const scientist sci1, const scientist sci2){return sci1.getBorn() < sci2.getBorn();}
bool descOrderBirth(const scientist sci1, const scientist sci2){return sci1.getBorn() > sci2.getBorn();}

bool ascOrderDeath(const scientist sci1, const scientist sci2){return sci1.getDeath() < sci2.getDeath();}
bool descOrderDeath(const scientist sci1, const scientist sci2){return sci1.getDeath() > sci2.getDeath();}

// All sort functions by column.
void service::sortByName() {
    if (order == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderName);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderName);
    }
}
void service::sortByGender() {
    if (order == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderGender);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderGender);
    }
}
void service::sortByBirth() {
    if (order == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderBirth);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderBirth);
    }
}
void service::sortByDeath() {
    if (order == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderDeath);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderDeath);
    }
}

//Add new scientist to current results and to the database.
void service::addScientist(){
    string name,sex,gender,alive = "w";
    int born,death;

    //Get the name.
    interface.renderText("Enter Name: ");
    name = interface.getInput();

    //Get the gender of the person.
    interface.renderText("What gender (m/f): ");
    sex = interface.getInput();
    do {
        if (sex != "m" && sex != "f") {
            interface.renderText("Gender selection not avalable, use either m/f: ");
            sex = interface.getInput();
        }
        if (sex == "m"){
            gender = "he";
            sex = "Male";
        }else if (sex == "f"){
            gender = "she";
            sex = "Female";
        }
    }while(sex != "Male" && sex != "Female");

    //Get year of birth.
    interface.renderText("What year was " + gender + " born: ");
    born = interface.getInt();

    while (born > 2015){
        interface.renderText("Person not born yet, enter another year: ");
        born = interface.getInt();
    }

    //See if person is still alive or not.
    interface.renderText("Is " + gender + " still alive (y/n): ");
    alive = interface.getInput();
    //If not alive, get year of death.
    while (alive != "y" && alive != "n"){
        alive = interface.getInput();
        if (alive != "y" && alive != "n"){
            interface.renderText("Please answer y/n: ");
        }
    }
    if (alive == "y"){
        death = 0;
    }else {
        interface.renderText("What year did " + gender + " die: ");
        death = interface.getInt();
        while (death < born || death > 2015){
            interface.renderText(gender + " can't have died that year \n");
            interface.renderText("try another year: ");
            death = interface.getInt();
        }
    }

    // make a new scientist.
    scientist sci(name,sex,born,death);
    // add him to the current results.
    scientists.push_back(sci);
    // add him to the database.
    sci.save();
}

void service::getStartInfo(){
    interface.renderText("Welcome to the Computer scientist Ultimate database 5000! \n");
    interface.renderText("Here you can search the database for computer scientists that \nhave made a big impact in the field.\n");
    interface.renderText("Please type [help] to get more info. \n");
}

void service::getHelpInfo(){
    interface.renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - \n");
    interface.renderText("There are a few commands which interact with the database: \n");
    interface.renderText("[add]     : With this you can add a new Computer scientist to the database, just make sure he/she is good enough. \n");
    interface.renderText("[sort]    : You can sort the database with the avalible columns and in either ascending or descending order. \n");
    interface.renderText("[search]  : Search which column you like with a keyword that you like and see what you find. \n");
    interface.renderText("[display] : The other functions would be no good if you couldn't display the results somehow, well this is the way. \n");
    interface.renderText("[reset]   : With this function you can undo all the sorting and searching filters that you have used and start over again \n");
    interface.renderText("[exit] or [quit] to close the database \n");
    interface.renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - \n");

}
