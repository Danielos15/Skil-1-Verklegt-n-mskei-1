#ifndef SCIENTIST
#define SCIENTIST
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class scientist
{
public:
    scientist(string newName, string newSex, int newBorn, int newDeath);

    int getId() const;
    string getName() const;
    string getSex() const;
    int getBorn() const;
    int getDeath() const;

    void setName(string newName);
    void setSex(string newSex);
    void setBorn(int newBirth);
    void setDeath(int newDeath);

    void save();
    void remove();

private:
    int id;
    string name;
    string sex;
    int born;
    int death;
};

#endif // SCIENTIST
