#ifndef SERVICE
#define SERVICE
#include <vector>
#include <string>
#include "ui.h"
#include "datarepo.h"
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
    vector<computer> computers;

    string input;

    string function;
    string option;
    string order;

    // Other classes
    scientist sci_db;
    computer cmp_db;
    datarepo db;
    ui interface;

    void getUserInput();
    void getFunction();

    //Add a scientist to the database
    void addScientist();

    //Add a computer to the database
    void addComputer();

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

