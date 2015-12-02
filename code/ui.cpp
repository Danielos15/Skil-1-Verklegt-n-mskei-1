#include <string>
#include <iostream>
#include "ui.h"

ui::ui(){}

string ui::getInput(){
    string input;
    getline(cin,input);
    return input;
}

int ui::getInt(){
    int input;
    cin >> input;
    return input;
}

void ui::renderText(string text){

    cout << text;
}

void ui::getHelp(){
    string help,cmd;
    //ui::getHelp cmd;
    //getHelp(cin, help);
    //command >> cmd;
    if(cmd == "help" || cmd == "HELP" || cmd == "Help" || cmd == "?")
    {
            cout<< "The commands are: " << endl;
            cout<< "add: To add information"<< endl;
            cout<< "display: display information on screen"<< endl;
            cout<< "sort: sort the list"<< endl;
            cout<< "search: Type in a word to search the list"<< endl;
    }
    
    else if(cmd == "add"){
    
    
    }
}

void ui::renderVector(vector<scientist> scientists){
    cout << "Displaying current results..." << endl;
    cout << "-  -  -  -  -  -  -" << endl;

    for(unsigned int i = 0; i < scientists.size(); i++){
        cout << "  Name: " << scientists[i].getName() << endl;
        cout << "  Gender: " << scientists[i].getSex() << endl;
        cout << "  Year of birth: " << scientists[i].getBorn() << endl;
        if(scientists[i].getDeath() != "0"){
            cout << "  Year of death: " << scientists[i].getDeath() << endl;
        }
        cout << "-  -  -  -  -  -  -" << endl;
    }
}

