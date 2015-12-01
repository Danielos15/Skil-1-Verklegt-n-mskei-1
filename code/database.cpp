#include "database.h"

#include <iostream>
#include <vector>

database::database(){

}

void database::connect(string filename){
    fileName = filename;
    inputStream.open(fileName.c_str());
    string line;
    char sep = ';';

    if (inputStream.is_open()){
        while(getline(inputStream,line)){
            unsigned int sepPos = line.find(sep);
            string name = line.substr(0,sepPos);
            line.erase(0,sepPos+1);
            sepPos = line.find(sep);
            string sex = line.substr(0,sepPos);
            line.erase(0,sepPos+1);
            sepPos = line.find(sep);
            string born = line.substr(0,sepPos);
            line.erase(0,sepPos+1);
            sepPos = line.find(sep);
            string death = line.substr(0,sepPos);

            cps scientist(name,sex,born,death);
            dbtable.push_back(scientist);
        }
           inputStream.close();
    }else{
        cout << "Error: Could not open file";
    }
}

void database::save(){
    outputStream.open(fileName.c_str());
    if (outputStream.is_open()){
        for (unsigned int i = 0; i < dbtable.size(); i++){
            outputStream << dbtable[i].getName() << ';' << dbtable[i].getSex() << ';' << dbtable[i].getBorn() << ';' << dbtable[i].getDeath() << endl;
        }
        outputStream.close();
    }else{
        cout << "Error: Could not open file";
    }
}

void database::add(cps cpuSci){
    dbtable.push_back(cpuSci);
    save();
}

void database::remove(){

}

vector<cps> database::fetchAll(){

}

vector<cps> database::fetchByName(){

}

vector<cps> database::fetchByBorn(){

}

vector<cps> database::fetchByDeath(){

}
