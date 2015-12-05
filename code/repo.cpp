#include "repo.h"
#include <iostream>
#include <sstream>
#include <vector>

repo::repo(){}
repo::repo(string filename){
    setFile(filename);
}

int sTOi(string in){
    int out;
    stringstream ss(in);
    if (!(ss >> out)){
        out = 0;
    }
    return out;
}

string iTOs(int in){
    string out;
    stringstream ss;
    ss << in;
    out = ss.str();
    return out;
}

void repo::setFile(string filename){
    fileName = filename;
}

void repo::connect(){
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

            scientist scientist(name,sex,sTOi(born),sTOi(death));
            dbtable.push_back(scientist);
        }
           inputStream.close();
    }else{
        cout << "Error: Could not open file" << endl;
    }
}

void repo::save(){
    outputStream.open(fileName.c_str());
    if (outputStream.is_open()){
        for (unsigned int i = 0; i < dbtable.size(); i++){
            outputStream << dbtable[i].getName() << ';' << dbtable[i].getSex() << ';' << dbtable[i].getBorn() << ';' << dbtable[i].getDeath() << endl;
        }
        outputStream.close();
    }else{
        cout << "Error: Could not save to file";
    }
}

void repo::add(scientist cpuSci){
    dbtable.push_back(cpuSci);
    save();
}

vector<scientist> repo::fetchAll(){
    return dbtable;
}

vector<scientist> repo::fetchByName(string search){
    vector<scientist> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (dbtable[i].getName().find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}

vector<scientist> repo::fetchBySex(string search){
    vector<scientist> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (dbtable[i].getSex().find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}

vector<scientist> repo::fetchByBorn(string search){
    vector<scientist> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (iTOs(dbtable[i].getBorn()).find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}

vector<scientist> repo::fetchByDeath(string search){
    vector<scientist> searchResults;
    for (unsigned int i = 0; i < dbtable.size(); i++){
        if (iTOs(dbtable[i].getDeath()).find(search) != std::string::npos) {
            searchResults.push_back(dbtable[i]);
        }
    }
    return searchResults;
}
