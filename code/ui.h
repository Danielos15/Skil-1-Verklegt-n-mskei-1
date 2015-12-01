#ifndef UI
#define UI

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "cps.h"

using namespace std;

class ui
{
public:
    ui();

    void getInput();
    string getCommand();
    string getOption();
    string getValue();

private:
    string command;
    string option;
    string value;

};

#endif // UI

