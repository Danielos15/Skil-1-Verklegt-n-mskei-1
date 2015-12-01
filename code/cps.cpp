#include "scientist.h"
#include <iostream>

scientist::scientist(string newName, string newSex, string newBorn, string newDeath = "0"){
    name = newName;
    sex = newSex;
    born = newBorn;
    death = newDeath;
}
string scientist::getName(){
    return name;
}

string scientist::getSex(){
    return sex;
}

string scientist::getBorn(){
    return born;
}

string scientist::getDeath(){
    return death;
}
