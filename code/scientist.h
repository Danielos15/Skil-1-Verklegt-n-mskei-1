#ifndef SCIENTIST
#define SCIENTIST
#include <vector>
#include <string>
#include <iostream>
#include <QTsql>

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
    bool isActive();

    void setName(string newName);
    void setSex(string newSex);
    void setBorn(int newBirth);
    void setDeath(int newDeath);

    void save();
    void remove();
    void disable();
    void enable();

private:
    QSqlDatabase db;

    int id;
    string name;
    string sex;
    int born;
    int death;
    bool active;

    bool isInTable();
};

#endif // SCIENTIST
