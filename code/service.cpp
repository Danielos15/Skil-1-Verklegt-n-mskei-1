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
    while (true) {
        //Infinit loop until user wants to quit.

        //Logic goes here::
        getUserInput();

        if (function == "quit" || function == "exit"){
            break; // exit if user wants to.
        }
    }
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
