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
    database();
    void connect(string filename);
    void save();
    void add(cps cpuSci);
    void remove();

    vector<cps> fetchAll();
    vector<cps> fetchByName();
    vector<cps> fetchByBorn();
    vector<cps> fetchByDeath();

private:
    vector<cps> dbtable;
    string fileName;

    ifstream inputStream;
    ofstream outputStream;

};

#endif // DATABASE

