#ifndef UI
#define UI

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "scientist.h"
#include "computer.h"

using namespace std;

class ui
{
public:
    ui();

    string getInput();
    string getLine();
    int getInt();
    void renderText(string text);
    void renderScientists(vector<scientist> scientists);
    void renderComputers(vector<computer> computers);
    bool getYesOrNo();

    //Help functions
    void getStartInfo();
    void getHelpInfo();
};

#endif // UI

