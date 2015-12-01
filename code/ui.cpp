#include "ui.h"

ui::ui(){

}

void ui::getInput(){
    cout << "Enter name, sex, birth year, and year of death in this order" << endl;

    string name, sex, birthyear, deathyear;

    getline(cin, name, ',');
    getline(cin, sex , ',');
    getline(cin, birthyear, ',');
    getline(cin, deathyear);



}
