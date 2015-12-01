#include "cps.h"
#include <iostream>

cps::cps(string newName, string newSex, string newBorn, string newDeath = "0"){
    name = newName;
    sex = newSex;
    born = newBorn;
    death = newDeath;
}
string cps::getName(){
    return name;
}

string cps::getSex(){
    return sex;
}

string cps::getBorn(){
    return born;
}

string cps::getDeath(){
    return death;
}
