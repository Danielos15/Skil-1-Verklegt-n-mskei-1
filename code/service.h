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
    repo connection;
    ui interface;

    void getUserInput();
    void getFunction();
    void addScientist();
    void sortList();
    void searchRepo();
    void sortByName();


};

#endif // SERVICE

