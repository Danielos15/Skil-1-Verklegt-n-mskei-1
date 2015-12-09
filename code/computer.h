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


    vector<computer> fetchAll();
    vector<computer> fetchByName(string searchString);
    vector<computer> fetchByBuild(string searchString);
    vector<computer> fetchByType(string searchString);
    vector<computer> fetchByWasBuilt(string searchString);

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
