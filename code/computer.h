#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include <string>
#include <iostream>
#include <QtSql>

using namespace std;

class computer
{
public:
    computer();
    computer(string newName,int newBuild, string newType, bool newWas);

    int getId() const;
    string getName() const;
    int getBuild() const;
    string getType() const;
    bool getWas() const;
    bool exists();

    void setName(string newName);
    void setBuild(int newBuild);
    void setType(string newType);
    void setWas(bool newBuild);
    void setId(int newId);
    void getInfo();

    void save();
    void remove();


    vector<computer> fetchAll(string orderBy);
    vector<computer> fetchByName(string searchString, string orderBy);
    vector<computer> fetchByBuild(string searchString, string orderBy);
    vector<computer> fetchByType(string searchString, string orderBy);
    vector<computer> fetchByWasBuilt(string searchString, string orderBy);

private:
    QSqlDatabase db;

    int id;
    string name;
    int build;
    string type;
    bool was;

    bool isInTable();
};

#endif // COMPUTER_H
