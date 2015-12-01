#include "database.h"

#include <iostream>
#include <vector>

database::database(string filename){
    fileName = filename;
}

void database::connect(){
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

vector<cps> database::fetchAll(){
    return dbtable;
}

vector<cps> database::fetchByName(string search){
    vector<cps> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (dbtable[i].getName().find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}

vector<cps> database::fetchBySex(string search){
    vector<cps> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (dbtable[i].getSex().find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}

vector<cps> database::fetchByBorn(string search){
    vector<cps> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (dbtable[i].getBorn().find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}

vector<cps> database::fetchByDeath(string search){
    vector<cps> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (dbtable[i].getDeath().find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}
