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
        else if (function == "add"){
            interface.renderText("From witch database table would you like to remove from? \n");
            interface.renderText("1: Scientists Table \n");
            interface.renderText("2: Computers Table \n");
            interface.renderText("Enter database table number: ");
            int choice = interface.getInt();
            while(choice > 2){
                interface.renderText("Unavalible option, try again: ");
                choice = interface.getInt();
            }
            if(choice == 1){
                addScientist();
            }else if(choice == 2){
                addComputer();
            }
    }


    // Remove from database, computer or Scientist
    else if(function == "remove"){
        interface.renderText("From witch database table would you like to remove from? \n");
        interface.renderText("1: Scientists Table \n");
        interface.renderText("2: Computers Table \n");
        interface.renderText("Enter database table number: ");
        cin.ignore();
        int inc = interface.getInt();
        while(inc > 2){
            interface.renderText("Unavalible option, try again: ");
            inc = interface.getInt();
        }
        int removeId = 0;
        if (inc == 1){
            interface.renderText("Select the ID of the instance in Scientists table to remove: ");
            removeId = interface.getInt();
            scientist sci;
            sci.setId(removeId);
            while(!sci.exists()){
                interface.renderText("Instance not found in database try anoter number: ");
                removeId = interface.getInt();
                sci.setId(removeId);
            }
            sci.remove();
            interface.renderText("Instance found in database and was removed");
        }else if (inc == 2){
            interface.renderText("Select the ID of the instance in Computers table to remove: ");
            removeId = interface.getInt();
            computer cpu;
            cpu.setId(removeId);
            while(!cpu.exists()){
                interface.renderText("Instance not found in database try anoter number: ");
                removeId = interface.getInt();
                cpu.setId(removeId);
            }
            cpu.remove();
            interface.renderText("Instance found in database and was removed");
        }
    }

    // Edit in the database, computer or Scientist
    else if(function == "edit"){
        interface.renderText("From witch database table would you like to edit from? \n");
        interface.renderText("1: Scientists Table \n");
        interface.renderText("2: Computers Table \n");
        interface.renderText("Enter database table number: ");
        cin.ignore();
        int inc = interface.getInt();
        while(inc > 2){
            interface.renderText("Unavalible option, try again: ");
            inc = interface.getInt();
        }
        int editId = 0;
        if (inc == 1){
            interface.renderText("Select the ID of the instance in Scientists table to edit: ");
            editId = interface.getInt();
            scientist sci;
            sci.setId(editId);
            while(!sci.exists()){
                interface.renderText("Instance not found in database try anoter number: ");
                editId = interface.getInt();
                sci.setId(editId);
            }
            //Edit function
            sci.getInfo();
            //Edit name?
            interface.renderText("Edit name y/n: ");
            cin.ignore();
            string edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter new name: ");
                cin.ignore();
                string name = interface.getLine();
                sci.setName(name);
            }
            //Edit gender?
            interface.renderText("Edit gender y/n: ");
            edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter new gender f/m: ");
                string gender = interface.getInput();
                while(gender != "f" && gender != "m"){
                    interface.renderText("Invalid option, try again f/m: ");
                    gender = interface.getInput();
                }
                if (gender == "m"){
                    gender = "Male";
                }else {
                    gender = "Female";
                }
                sci.setSex(gender);
            }

            //Edit birth?
            interface.renderText("Edit year of birth y/n: ");
            cin.ignore();
            edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter year of birth: ");
                int born = interface.getInt();
                while (born > 2015){
                    interface.renderText("Year not avalible, try again: ");
                    born = interface.getInt();
                }
                sci.setBorn(born);
            }
            //Edit death?
            interface.renderText("Edit year of death y/n: ");
            edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter year of death: ");
                int death = interface.getInt();
                while (sci.getBorn() > death || death > 2015){
                    interface.renderText("Person can't have died that year, try again: ");
                    death = interface.getInt();
                }
                sci.setDeath(death);
            }
            sci.save();
            interface.renderText("Instance found in database and was edited. \n");
        }else if (inc == 2){
            interface.renderText("Select the ID of the instance in Computers table to edit: ");
            int editId = interface.getInt();
            computer cpu;
            cpu.setId(editId);
            while(!cpu.exists()){
                interface.renderText("Instance not found in database try anoter number: ");
                editId = interface.getInt();
                cpu.setId(editId);
            }
            //Edit function
            cpu.getInfo();
            //Edit name?
            interface.renderText("Edit name y/n: ");
            cin.ignore();
            string edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter new name: ");
                cin.ignore();
                string name = interface.getLine();
                cpu.setName(name);
            }
            //Edit build_year?
            interface.renderText("Edit Build year y/n: ");
            edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter new build year: ");
                int build_year = interface.getInt();
                cpu.setBuild(build_year);
            }

            //Edit Type?
            interface.renderText("Edit type y/n: ");
            cin.ignore();
            edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Enter new type: ");
                cin.ignore();
                string type = interface.getLine();
                cpu.setType(type);
            }
            //Edit Was built?
            interface.renderText("Edit if it was built or not y/n: ");
            edit = interface.getInput();
            while(edit != "y" && edit != "n"){
                interface.renderText("Invalid option, try again: ");
                edit = interface.getInput();
            }
            if (edit == "y"){
                interface.renderText("Was it built or not y/n: ");
                string wasBuilt = interface.getInput();
                while(wasBuilt != "y" && wasBuilt != "n"){
                    interface.renderText("Invalid option, try again: ");
                    wasBuilt = interface.getInput();
                }
                if (wasBuilt == "y"){
                    cpu.setWas(true);
                }else {
                    cpu.setWas(false);
                }
            }
            cpu.save();
            interface.renderText("Instance found in database and was edited. \n");
        }
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
    interface.renderText("What year was the computer built: ");
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
    interface.renderText("Was this machine ever mass produced? y/n: ");
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
    interface.renderText("[add]     : Add a new computer or a scientist to the database. \n");
    interface.renderText("[edit]    : Here you can edit the database");
    interface.renderText("[remove]  : Here you can remove from the database");
    interface.renderText("[display] : Display from the database \n");
    interface.renderText("[exit] or [quit] to close the database \n");
    interface.renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - \n");
}
