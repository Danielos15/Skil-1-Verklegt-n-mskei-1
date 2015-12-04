#include "scientist.h"
#include <iostream>

scientist::scientist(string newName, string newSex, string newBorn, string newDeath = "0"){
    name = newName;
    sex = newSex;
    born = newBorn;
    death = newDeath;
}

int scientist::getId() const{
    return id;
}

string scientist::getName() const{
    return name;
}

string scientist::getSex() const{
    return sex;
}

string scientist::getBorn() const{
    return born;
}

string scientist::getDeath() const{
    return death;
}



