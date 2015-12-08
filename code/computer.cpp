#include "computer.h"
#include <iostream>

computer::computer(string newName, int newBuild, string newType, string newWas){
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

int computer::getBuild() const{
    return build;
}

string computer::getType() const{
    return type;
}

bool computer::getWas() const{
    return was;
}




void computer::setName(string newName){
    name = newName;
}

void computer::setBuild(string newBuild){
    build = newBuild;
}

<<<<<<< HEAD
void computer::setType(int newType){
    type = newType;
=======
void computer::setType(int NewType){
    type = NewType;
>>>>>>> origin/master
}

void computer::setWas(int newWas){
    was = newWas;
}

void computer::setId(int newId){
    id = newId;
}




