#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include <string>

using namespace std;

class computer
{
public:
    computer(string newName,string newBuild, string newType, string newWas);

    int getId() const;
    string getName() const;
    string getBuild() const;
    string getType() const;
    string getWas() const;

private:
    int id;
    string name;
    string build;
    string type;
    string was;

};

#endif // COMPUTER_H



