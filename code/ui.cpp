#include <string>
#include <iostream>
#include "ui.h"

ui::ui(){}

string ui::getInput(){
    string input;
    getline(cin,input);
    return input;

}
