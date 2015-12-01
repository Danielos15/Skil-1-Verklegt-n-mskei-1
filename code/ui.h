#ifndef UI
#define UI

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "scientist.h"

using namespace std;

class ui
{
public:
    ui();

    string getInput();
    void renderText(string text);
    int getInt();
    scientist newScientist();
    void getHelp();

private:

};

#endif // UI

