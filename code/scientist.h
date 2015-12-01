#ifndef SCIENTIST
#define SCIENTIST
#include <vector>
#include <string>

using namespace std;

class scientist
{
public:
    scientist(string newName, string newSex, string newBorn, string newDeath);
    string getName();
    string getSex();
    string getBorn();
    string getDeath();


private:
    string name;
    string sex;
    string born;
    string death;

};

#endif // SCIENTIST
