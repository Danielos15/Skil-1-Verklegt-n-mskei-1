#ifndef REPO
#define REPO
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "scientist.h"

using namespace std;

class repo
{
public:
    repo();
    repo(string filename);

    void setFile(string filename);
    void connect();
    void save();
    void add(scientist cpuSci);

    vector<scientist> fetchAll();
    vector<scientist> fetchByName(string search);
    vector<scientist> fetchBySex(string search);
    vector<scientist> fetchByBorn(string search);
    vector<scientist> fetchByDeath(string search);

private:
    string fileName;
    vector<scientist> dbtable;

    ifstream inputStream;
    ofstream outputStream;

};

#endif // REPO

