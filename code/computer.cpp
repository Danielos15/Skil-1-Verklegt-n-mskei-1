#include "computer.h"
#include <iostream>

computer::computer(string newName,string newBuild, string newType, string newWas){
    name = newName;
    build = newBuild;
    type = newType;
    was = newWas;
}

int computer::getId() const{
    return id;
}

string computer::getName() const{
    return name;
}

string computer::getBuild() const{
    return build;
}

string computer::getType() const{
    return type;
}

string computer::getWas() const{
    return was;
}




void computer::setName(string newName){
    name = newName;
}

void computer::setBuild(string newBuild){
    sex = newSex;
}

void computer::setType(int NewType){
    born = newBirth;
}

void computer::setWas(int newWas){
    death = newDeath;
}

void computer::setId(int newId){
    id = newId;
}




