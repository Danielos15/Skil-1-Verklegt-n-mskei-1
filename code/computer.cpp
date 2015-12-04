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

