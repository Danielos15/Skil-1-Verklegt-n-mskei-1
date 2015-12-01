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
    repo(string filename);
    void connect();
    void save();
    void add(scientist cpuSci);

    vector<scientist> fetchAll();
    vector<scientist> fetchByName(string search);
    vector<scientist> fetchBySex(string search);
    vector<scientist> fetchByBorn(string search);
    vector<scientist> fetchByDeath(string search);

private:
    vector<scientist> dbtable;
    string fileName;

    ifstream inputStream;
    ofstream outputStream;

};

#endif // REPO

