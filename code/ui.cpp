#include <string>
#include <iostream>
#include <sstream>
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

scientist ui::newScientist(){
    string name,sex,gender,bornS,deathS,alive;
    int born,death;
    cout << "Enter Name: ";
    cin >> name;

    cout << "What gender (m/f): ";
    cin >> sex;
    do {
        if (sex != "m" && sex != "f") {
            cout << "Gender selection not avalible, use either m/f: ";
            cin >> sex;
        }
        if (sex == "m"){
            gender = "he";
        }else if (sex == "f"){
            gender = "she";
        }
    }while(sex != "m" && sex != "f");

    cout << "What year was " << gender << " born: ";
    cin >> born;

    while (born > 2015){
        cout << "person not born yet, enter another year: ";
        cin >> born;
    }
    ostringstream strm;
    strm << born;
    bornS = strm.str();

    cout << "Is " << gender << " still alive (y/n): ";
    cin >> alive;
    while (alive != "y" && alive != "n"){
        cin >> alive;
    }
    if (alive == "y"){
        deathS = "0";
    }else {
        cout << "What year did " << gender << " die: ";
        cin >> death;
        while (death >= born){
            cout << "Then the person isn't dead yeat, select another year: ";
            cin >> death;
        }
        strm << death;
        deathS = strm.str();
    }

    scientist sci(name,sex,bornS,deathS);
    return sci;
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

