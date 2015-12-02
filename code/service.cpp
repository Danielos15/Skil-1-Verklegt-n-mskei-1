#include <vector>
#include <string>
#include <sstream>
#include "service.h"
#include "repo.h"
#include "scientist.h"
#include "ui.h"

service::service(){

}

void service::init(){
    //Setup database connection
    string databaseFile = "database.csv";
    connection.setFile(databaseFile);
    connection.connect();
    scientists = connection.fetchAll();
}

void service::run(){
    while (true) {
        //Infinit loop until user wants to quit.

        //Logic goes here::
        getUserInput();

        if (function == "quit" || function == "exit"){
            //break; // exit if user wants to.
        }
    }
}

void service::getFunction(){
    unsigned int functionSepPos = input.find(" ");
    function = input.substr(0, functionSepPos);
    input.erase(0,functionSepPos+1);

    if (function == "display"){
        interface.renderVector(scientists);
    }else if (function == "sort"){

    }else if (function == "search"){

    }else if (function == "add"){
        addScientist();
    }
}

void service::getUserInput(){
    input = interface.getInput();
    getFunction();
}

bool ascOrderName(const scientist sci1, const scientist sci2){return sci1.getName() < sci2.getName();}
bool descOrderName(const scientist sci1, const scientist sci2){return sci1.getName() > sci2.getName();}

bool ascOrderGender(const scientist sci1, const scientist sci2){return sci1.getSex() < sci2.getSex();}
bool descOrderGender(const scientist sci1, const scientist sci2){return sci1.getSex() > sci2.getSex();}

bool ascOrderBirth(const scientist sci1, const scientist sci2){return sci1.getBorn() < sci2.getBorn();}
bool descOrderBirth(const scientist sci1, const scientist sci2){return sci1.getBorn() > sci2.getBorn();}

bool ascOrderDeath(const scientist sci1, const scientist sci2){return sci1.getDeath() < sci2.getDeath();}
bool descOrderDeath(const scientist sci1, const scientist sci2){return sci1.getDeath() > sci2.getDeath();}

void service::sortByName() {
    if (option == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderName);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderName);
    }
}
void service::sortByGender() {
    if (option == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderGender);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderGender);
    }
}
void service::sortByBirth() {
    if (option == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderBirth);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderBirth);
    }
}
void service::sortByDeath() {
    if (option == "desc"){
        sort(scientists.begin(), scientists.end(), descOrderDeath);
    }else {
        sort(scientists.begin(), scientists.end(), ascOrderDeath);
    }
}

void service::addScientist(){
    string name,sex,gender,bornS,deathS,alive;
    int born,death;

    interface.renderText("Enter Name: ");
    name = interface.getInput();

    interface.renderText("What gender (m/f): ");
    sex = interface.getInput();
    do {
        if (sex != "m" && sex != "f") {
            interface.renderText("Gender selection not avalible, use either m/f: ");
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

    interface.renderText("What year was " + gender + " born: ");
    born = interface.getInt();

    while (born > 2015){
        interface.renderText("person not born yet, enter another year: ");
        born = interface.getInt();
    }
    ostringstream strm;
    strm << born;
    bornS = strm.str();

    interface.renderText("Is " + gender + " still alive (y/n): ");
    alive = interface.getInput();
    while (alive != "y" && alive != "n"){
        alive = interface.getInput();
    }
    if (alive == "y"){
        deathS = "0";
    }else {
        interface.renderText("What year did " + gender + " die: ");
        death = interface.getInt();
        while (death < born){
            interface.renderText(gender + " can't have died before birth \n");
            interface.renderText("try another year: ");
            death = interface.getInt();
        }
        strm << death;
        deathS = strm.str();
    }

    scientist sci(name,sex,bornS,deathS);
    scientists.push_back(sci);
    connection.add(sci);
}
