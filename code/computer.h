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
    computer(string newName,string newBuild, string newType, string newWas);

    int getId() const;
    string getName() const;
    string getBuild() const;
    string getType() const;
    string getWas() const;
    bool isActive();

    void setName(string newName);
    void setBuild(string newSex);
    void setType(int newBirth);
    void setWas(int newDeath);
    void setId(int newId);

    void save();
    void remove();
    void disable();
    void enable();

    vector<computer> fetchAll();
    vector<computer> fetchActive();
    vector<computer> fetchByName(string name);
    vector<computer> fetchByBuild(string build);
    vector<computer> fetchByType(string type);
    vector<computer> fetchByWas(string was);

private:
    QSqlDatabase db;

    int id;
    string name;
    string build;
    string type;
    string was;
    bool active;

    bool isInTable();
};

#endif // COMPUTER_H



