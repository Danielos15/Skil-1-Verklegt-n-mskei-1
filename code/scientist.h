#ifndef SCIENTIST
#define SCIENTIST
#include <vector>
#include <string>

using namespace std;

class scientist
{
public:
    scientist(string newName, string newSex, string newBorn, string newDeath);

    int getId() const;
    string getName() const;
    string getSex() const;
    string getBorn() const;
    string getDeath() const;

    void save();
    void remove();

private:
    int id;
    string name;
    string sex;
    string born;
    string death;    
};

#endif // SCIENTIST
