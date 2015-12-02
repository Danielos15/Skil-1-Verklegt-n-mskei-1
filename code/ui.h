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
    int getInt();
    void renderText(string text);
    void renderVector(vector<scientist> scientists);
};

#endif // UI

