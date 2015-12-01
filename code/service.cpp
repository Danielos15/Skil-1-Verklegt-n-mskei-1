#include <vector>
#include <string>
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
    //while (true) {
        //Infinit loop until user wants to quit.

        //Logic goes here::
        //getUserInput();
        interface.renderVector(scientists);
        option = "desc";
        sortByName();
        interface.renderVector(scientists);

        //if (function == "quit" || function == "exit"){
            //break; // exit if user wants to.
        //}
    //}
}

void service::getFunction(){
    unsigned int functionSepPos = input.find(" ");
    function = input.substr(0, functionSepPos);
    input.erase(0,functionSepPos+1);
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
