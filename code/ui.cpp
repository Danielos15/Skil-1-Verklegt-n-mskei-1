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

void ui::renderVector(vector<scientist> scientists){
    renderText("Displaying current results... \n");
    renderText("-  -  -  -  -  -  - \n");

    for(unsigned int i = 0; i < scientists.size(); i++){
        renderText("  Name: " + scientists[i].getName() + "\n");
        renderText("  Gender: " + scientists[i].getSex() + "\n");
        cout << "  Year of birth: " << scientists[i].getBorn() << "\n";
        if(scientists[i].getDeath() != 0){
            cout << "  Year of death: " << scientists[i].getDeath() << "\n";
        }
        renderText("-  -  -  -  -  -  - \n");
    }
}

