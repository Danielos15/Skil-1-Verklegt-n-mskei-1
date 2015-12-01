#include <QCoreApplication>
#include "repo.h"
#include "scientist.h"
#include "ui.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    repo test("test.csv");
    test.connect();

    ui name;
     name.getInput();


    return a.exec();
}

