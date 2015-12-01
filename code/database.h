#ifndef DATABASE
#define DATABASE
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "cps.h"

using namespace std;

class database
{
public:
    database(string filename);
    void connect();
    void save();
    void add(cps cpuSci);

    vector<cps> fetchAll();
    vector<cps> fetchByName(string search);
    vector<cps> fetchBySex(string search);
    vector<cps> fetchByBorn(string search);
    vector<cps> fetchByDeath(string search);

private:
    vector<cps> dbtable;
    string fileName;

    ifstream inputStream;
    ofstream outputStream;

};

#endif // DATABASE

