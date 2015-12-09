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
    void getInfo();

    void setName(string newName);
    void setSex(string newSex);
    void setBorn(int newBirth);
    void setDeath(int newDeath);
    void setId(int newId);

    void save();
    void remove();


    vector<scientist> fetchAll(string orderBy);
    vector<scientist> fetchByName(string searchString, string orderBy);
    vector<scientist> fetchBySex(string searchString, string orderBy);
    vector<scientist> fetchByBorn(string searchString, string orderBy);
    vector<scientist> fetchByDeath(string searchString, string orderBy);

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
