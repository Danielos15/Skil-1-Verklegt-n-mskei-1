#include "scientist.h"
#include <iostream>

scientist::scientist(int newId,string newName, string newSex, string newBorn, string newDeath = "0"){
    id = newId;
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



