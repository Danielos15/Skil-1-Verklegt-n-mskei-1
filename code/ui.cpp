#include <string>
#include <iostream>
#include "ui.h"

ui::ui(){}

string ui::getInput(){
    string input;
    getline(cin,input);
    return input;

}
string ui::getHelp(){
    string help;
    ui::getHelp cmd;
    getHelp(cin, help);
    command >> cmd;
    if(cmd == 'help'||'HELP' || 'Help' || '?')
    {
            cout<< "The commands are: " << endl;
            cout<< "add: To add information"<< endl;
            cout<< "display: display information on screen"<< endl;
            cout<< "sort: sort the list"<< endl;
            cout<< "search: Type in a word to search the list"<< endl;
    }
    
    else if(cmd == 'add')
    
    
    }
