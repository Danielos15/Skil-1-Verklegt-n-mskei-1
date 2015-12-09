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
    renderText("Displaying current Scientists... \n");
    for (int h = 0; h < numberPerLine; h++){
        renderText("-  -  -  -  -  -  -  -  ");
    }
    renderText("\n");
    for(unsigned int i = 0; i < scientists.size();){
        string lines[5];
        for (int x = 0; x < numberPerLine; x++){
            if (i < scientists.size()){
                lines[0] += "  Id: " + iTOs(scientists[i].getId());
                lines[1] += "  Name: " + scientists[i].getName();
                lines[2] += "  Gender: " + scientists[i].getSex();
                lines[3] += "  Year of birth: " + iTOs(scientists[i].getBorn());
                if(scientists[i].getDeath() != 0){
                    lines[4] += "  Year of death: " + iTOs(scientists[i].getDeath());
                }else {
                    lines[4] += "  Still alive";
                }
                int linesSize[5];
                linesSize[0] = lines[0].size();
                linesSize[1] = lines[1].size();
                linesSize[2] = lines[2].size();
                linesSize[3] = lines[3].size();
                linesSize[4] = lines[4].size();
                int highest = lines[0].size();
                for (int f = 1; f < 5; f++){
                    if (linesSize[f] > highest){
                        highest = linesSize[f];
                    }
                }
                for (int g = 0; g < 5; g++){
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
        renderText(lines[4] + "\n");
        for (int h = 0; h < numberPerLine; h++){
            renderText("-  -  -  -  -  -  -  -  ");
        }
        renderText("\n");
    }
}

void ui::renderComputers(vector<computer> computers){
    int numberPerLine = 4;
    renderText("Displaying current Computers... \n");
    for (int h = 0; h < numberPerLine; h++){
        renderText("-  -  -  -  -  -  -  -  ");
    }
    renderText("\n");
    for(unsigned int i = 0; i < computers.size();){
        string lines[5];
        for (int x = 0; x < numberPerLine; x++){
            if (i < computers.size()){
                lines[0] += "  Id: " + iTOs(computers[i].getId());
                lines[1] += "  Name: " + computers[i].getName();
                lines[2] += "  Build year: " + iTOs(computers[i].getBuild());
                lines[3] += "  Type : " + computers[i].getType();
                if(computers[i].getWas()){
                    lines[4] += "  Computer was built: ";
                }else{
                    lines[4] += "  Computer was not built: ";
                }
                int linesSize[5];
                linesSize[0] = lines[0].size();
                linesSize[1] = lines[1].size();
                linesSize[2] = lines[2].size();
                linesSize[3] = lines[3].size();
                linesSize[4] = lines[4].size();
                int highest = lines[0].size();
                for (int f = 1; f < 5; f++){
                    if (linesSize[f] > highest){
                        highest = linesSize[f];
                    }
                }
                for (int g = 0; g < 5; g++){
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
        renderText(lines[4] + "\n");
        for (int h = 0; h < numberPerLine; h++){
            renderText("-  -  -  -  -  -  -  -  ");
        }
        renderText("\n");
    }
}

void ui::getStartInfo(){
    renderText("Welcome to the Computer scientist Ultimate database 5000! \n");
    renderText("Here you can search the database for computer scientists and computers\n that have made a big impact in the field.\n");
    renderText("Please type [help] to get more info. \n");
}

void ui::getHelpInfo(){
    renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - - - - - - \n");
    renderText("There are a few commands which interact with the database: \n");
    renderText("[add]         : Add a new computer or a scientist to the database. \n");
    renderText("[edit]        : Edit an existing computer or a scientist in the database. \n");
    renderText("[remove]      : Remove a existing computer or a scientist from the database. \n");
    renderText("[display]     : Display the computers or scientists from the database. \n");
    renderText("[connected]   : See how computers and scientists are connected togather. \n");
    renderText("[connections] : Connect a computer and a scientist togather. \n");
    renderText("[exit] or [quit] to close the database. \n");
    renderText("- - - - - - - - - - - - HELP - - - - - - - - - - - - - - - - - - - - - - - \n");
}

bool ui::getYesOrNo(){
    string input;
    input = getInput();
    while(input != "y" && input != "n"){
        renderText("Invalid option, try again: ");
        input = getInput();
    }
    if (input == "y"){
        return true;
    }else{
        return false;
    }
}

void ui::renderConnectedCpu(scientist scientist, vector<computer> computers){
    string lines[5];
    int linesSize[5];
    int highest;

    lines[0] += "  Id: " + iTOs(scientist.getId());
    lines[1] += "  Name: " + scientist.getName();
    lines[2] += "  Gender: " + scientist.getSex();
    lines[3] += "  Year of birth: " + iTOs(scientist.getBorn());
    if(scientist.getDeath() != 0){
        lines[4] += "  Year of death: " + iTOs(scientist.getDeath());
    }else {
        lines[4] += "  Still alive";
    }

    for (int n = 0; n < 5; n++){
        linesSize[n] = lines[n].size();
    }
    highest = lines[0].size();
    for (int f = 1; f < 5; f++){
        if (linesSize[f] > highest){
            highest = linesSize[f];
        }
    }
    for (int g = 0; g < 5; g++){
        for (int p = linesSize[g]; p < highest;p++){
            lines[g] += " ";
        }
        lines[g] += "\t >> \t";
    }

    for(unsigned int i = 0; i < computers.size();i++){
        lines[0] += "  Id: " + iTOs(computers[i].getId());
        lines[1] += "  Name: " + computers[i].getName();
        lines[2] += "  Build year: " + iTOs(computers[i].getBuild());
        lines[3] += "  Type : " + computers[i].getType();
        if(computers[i].getWas()){
            lines[4] += "  Computer was built: ";
        }else{
            lines[4] += "  Computer was not built: ";
        }

        for (int n = 0; n < 5; n++){
            linesSize[n] = lines[n].size();
        }
        highest = lines[0].size();
        for (int f = 1; f < 5; f++){
            if (linesSize[f] > highest){
                highest = linesSize[f];
            }
        }
        for (int g = 0; g < 5; g++){
            for (int p = linesSize[g]; p < highest;p++){
                lines[g] += " ";
            }
            lines[g] += "\t";
        }
    }
    for (int m = 0; m < 5; m++){
        renderText(lines[m] + "\n");
    }
}

void ui::renderConnectedSci(computer cpu, vector<scientist> scientists){
    string lines[5];
    int linesSize[5];
    int highest;

    lines[0] += "  Id: " + iTOs(cpu.getId());
    lines[1] += "  Name: " + cpu.getName();
    lines[2] += "  Build year: " + iTOs(cpu.getBuild());
    lines[3] += "  Type : " + cpu.getType();
    if(cpu.getWas()){
        lines[4] += "  Computer was built: ";
    }else{
        lines[4] += "  Computer was not built: ";
    }
    for (int n = 0; n < 5; n++){
        linesSize[n] = lines[n].size();
    }
    highest = lines[0].size();
    for (int f = 1; f < 5; f++){
        if (linesSize[f] > highest){
            highest = linesSize[f];
        }
    }
    for (int g = 0; g < 5; g++){
        for (int p = linesSize[g]; p < highest;p++){
            lines[g] += " ";
        }
        lines[g] += "\t >> \t";
    }

    for(unsigned int i = 0; i < scientists.size();i++){
        lines[0] += "  Id: " + iTOs(scientists[i].getId());
        lines[1] += "  Name: " + scientists[i].getName();
        lines[2] += "  Gender: " + scientists[i].getSex();
        lines[3] += "  Year of birth: " + iTOs(scientists[i].getBorn());
        if(scientists[i].getDeath() != 0){
            lines[4] += "  Year of death: " + iTOs(scientists[i].getDeath());
        }else {
            lines[4] += "  Still alive";
        }

        for (int n = 0; n < 5; n++){
            linesSize[n] = lines[n].size();
        }
        highest = lines[0].size();
        for (int f = 1; f < 5; f++){
            if (linesSize[f] > highest){
                highest = linesSize[f];
            }
        }
        for (int g = 0; g < 5; g++){
            for (int p = linesSize[g]; p < highest;p++){
                lines[g] += " ";
            }
            lines[g] += "\t";
        }
    }
    for (int m = 0; m < 5; m++){
        renderText(lines[m] + "\n");
    }
}
