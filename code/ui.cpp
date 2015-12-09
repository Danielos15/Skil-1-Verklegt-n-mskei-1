#include <string>
#include <iostream>
#include <sstream>
#include "ui.h"

ui::ui(){}

string ui::getInput(){
    string input;
    cin >> input;
    return input;
}

int ui::getInt(){
    int input;
    string inString = getInput();
    stringstream ss(inString);
    if (!(ss >> input)){
        renderText("Not a valid number, try again: ");
        getInt();
    }
    return input;
}

string ui::getLine(){
    string input;
    getline(cin, input);
    return input;
}

string iTOs(int in){
    string out;
    stringstream ss;
    ss << in;
    out = ss.str();
    return out;
}

void ui::renderText(string text){
    cout << text;
}

void ui::renderScientists(vector<scientist> scientists){
    int numberPerLine = 4;
    renderText("Displaying current results... \n");
    for (int h = 0; h < numberPerLine; h++){
        renderText("-  -  -  -  -  -  -  -  ");
    }
    renderText("\n");
    for(unsigned int i = 0; i < scientists.size();){
        string lines[numberPerLine+1];
        for (int x = 0; x < numberPerLine; x++){
            if (i < scientists.size()){
                lines[0] += "  Name: " + scientists[i].getName();
                lines[1] += "  Gender: " + scientists[i].getSex();
                lines[2] += "  Year of birth: " + iTOs(scientists[i].getBorn());
                if(scientists[i].getDeath() != 0){
                    lines[3] += "  Year of death: " + iTOs(scientists[i].getDeath());
                }else {
                    lines[3] += "  Still alive";
                }
                int linesSize[4];
                linesSize[0] = lines[0].size();
                linesSize[1] = lines[1].size();
                linesSize[2] = lines[2].size();
                linesSize[3] = lines[3].size();
                int highest = lines[0].size();
                for (int f = 1; f < 4; f++){
                    if (linesSize[f] > highest){
                        highest = linesSize[f];
                    }
                }
                for (int g = 0; g < 4; g++){
                    for (int p = linesSize[g]; p < highest;p++){
                        lines[g] += " ";
                    }
                    lines[g] += "\t";
                }
                i++;
            }
        }
        renderText(lines[0] + "\n");
        renderText(lines[1] + "\n");
        renderText(lines[2] + "\n");
        renderText(lines[3] + "\n");
        for (int h = 0; h < numberPerLine; h++){
            renderText("-  -  -  -  -  -  -  -  ");
        }
        renderText("\n");
    }
}

void ui::renderComputers(vector<computer> computers){
    int numberPerLine = 4;
    renderText("Displaying current results... \n");
    for (int h = 0; h < numberPerLine; h++){
        renderText("-  -  -  -  -  -  -  -  ");
    }
    renderText("\n");
    for(unsigned int i = 0; i < computers.size();){
        string lines[numberPerLine+1];
        for (int x = 0; x < numberPerLine; x++){
            if (i < computers.size()){
                lines[0] += "  Name: " + computers[i].getName();
                lines[1] += "  Build year: " + iTOs(computers[i].getBuild());
                lines[2] += "  Type of Computer: " + computers[i].getType();
                if(computers[i].getWas()){
                    lines[3] += "  Computer was built: ";
                }else{
                    lines[3] += "  Computer was not built: ";
                }
                int linesSize[4];
                linesSize[0] = lines[0].size();
                linesSize[1] = lines[1].size();
                linesSize[2] = lines[2].size();
                linesSize[3] = lines[3].size();
                int highest = lines[0].size();
                for (int f = 1; f < 4; f++){
                    if (linesSize[f] > highest){
                        highest = linesSize[f];
                    }
                }
                for (int g = 0; g < 4; g++){
                    for (int p = linesSize[g]; p < highest;p++){
                        lines[g] += " ";
                    }
                    lines[g] += "\t";
                }
                i++;
            }
        }
        renderText(lines[0] + "\n");
        renderText(lines[1] + "\n");
        renderText(lines[2] + "\n");
        renderText(lines[3] + "\n");
        for (int h = 0; h < numberPerLine; h++){
            renderText("-  -  -  -  -  -  -  -  ");
        }
        renderText("\n");
    }
}

