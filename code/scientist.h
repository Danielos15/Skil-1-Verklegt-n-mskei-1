#ifndef SCIENTIST
#define SCIENTIST
#include <vector>
#include <string>
#include <iostream>
#include <QtSql>

using namespace std;

class scientist
{
public:
    scientist();
    scientist(string newName, string newSex, int newBorn, int newDeath);

    int getId() const;
    string getName() const;
    string getSex() const;
    int getBorn() const;
    int getDeath() const;
    bool exists();

    void setName(string newName);
    void setSex(string newSex);
    void setBorn(int newBirth);
    void setDeath(int newDeath);
    void setId(int newId);

    void save();
    void remove();


    vector<scientist> fetchAll();
    vector<scientist> fetchByName(string name);
    vector<scientist> fetchBySex(string sex);
    vector<scientist> fetchByBorn(string birth);
    vector<scientist> fetchByDeath(string death);

private:
    QSqlDatabase db;

    int id;
    string name;
    string sex;
    int born;
    int death;

    bool isInTable();
};

#endif // SCIENTIST
