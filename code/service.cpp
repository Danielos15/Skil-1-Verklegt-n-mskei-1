#include <vector>
#include <string>
#include <sstream>
#include "service.h"
#include "scientist.h"
#include "ui.h"
#include "datarepo.h"
#include "computer.h"

service::service(){}

void service::init(){
    db.connect();

    scientists = sci_db.fetchAll();
    computers = cmp_db.fetchAll();
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

    // if User wants to render scientists
    if (function == "displaysc"){
        interface.renderScientists(scientists);
    }
    // if User wants to render computers
    else if(function == "displayco"){
        interface.renderComputers(computers);
    }

    // Add a scientist or a computer to the database.
    else if (function == "addsc"){
        addScientist();
    }else if(function == "addco"){
        addComputer();
    }

    // Get the help info.
    else if (function == "help"){
        getHelpInfo();
    }
    else if (function == "exit" || function == "quit"){
        // exit;
    }else {
        interface.renderText("Invalid command! try [help] to get more info \n");
    }
}

//Add new scientist to current results and to the database.
void service::addScientist(){
    string name,sex,gender,alive = "w";
    int born,death;

    //Get the name.
    interface.renderText("Enter Name: ");
    cin.ignore();
    name = interface.getLine();

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

// add a computer to the database

void service::addComputer(){
    string name,type;
    int build;
    bool was;

    //Get the name.
    interface.renderText("Enter Name: ");
    name = interface.getInput();

    //Get the Build year of the computer.
    interface.renderText("When was the computer built: ");
    build = interface.getInt();

    //Error checking for build year.
    while (build > 2015){
        interface.renderText("Computer not built yet, enter another year: ");
        build = interface.getInt();
    }

    //Get the type of the computer.
    interface.renderText("Enter the type of the computer: ");
    type = interface.getInput();


    //Was this machine ever built.
    interface.renderText("Was this machine ever built? y/n: ");
    string checkWas;
    cin.ignore();
    checkWas = interface.getInput();

    while(checkWas !=  "y" && checkWas != "n"){
        interface.renderText("Incorrect input, please only use y/n: ");
        checkWas = interface.getInput();
    }
    if (checkWas == "y"){
        was = true;
    }else {
        was = false;
    }

    // make a new computer.
    computer cmp(name,build,type,was);
    // add the computer to the database.
    cmp.save();
}

void service::getStartInfo(){
    interface.renderText("Welcome to the Computer scientist Ultimate database 5000! \n");
    interface.renderText("Here you can search the database for computer scientists and computers\n that have made a big impact in the field.\n");
    interface.renderText("Please type [help] to get more info. \n");
}

void service::getHelpInfo(){
    interface.renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - \n");
    interface.renderText("There are a few commands which interact with the database: \n");
    interface.renderText("[addsc]     : With this you can add a new computer scientist to the database. \n");
    interface.renderText("[addco]     : With this you can add a new computer to the database. \n");
    interface.renderText("[addre]     : With this you can add a relation between scientists and computers. \n");
    interface.renderText("[displaysc] : Display the scientists \n");
    interface.renderText("[displayco] : Display the computers \n");
    interface.renderText("[displayre] : Display the relation between scientists and computers \n");
    interface.renderText("[exit] or [quit] to close the database \n");
    interface.renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - \n");
}
