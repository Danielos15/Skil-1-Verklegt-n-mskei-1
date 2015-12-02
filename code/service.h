#ifndef SERVICE
#define SERVICE
#include <vector>
#include <string>
#include "repo.h"
#include "ui.h"
#include <algorithm>

using namespace std;

class service
{
public:
    service();
    void init();
    void run();

private:
    vector<scientist> scientists;
    string input;
    string function;
    string option;
    string order;
    repo connection;
    ui interface;

    void getUserInput();
    void getFunction();

    void addScientist();

    //Sort functions
    void sortByName();
    void sortByGender();
    void sortByBirth();
    void sortByDeath();

    //Search functions
    void searchByName();
    void searchByGender();
    void searchByBirth();
    void searchByDeath();
};

#endif // SERVICE

