#include <QCoreApplication>
#include "database.h"
#include "cps.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    database test;
    test.connect("test.csv");

    return a.exec();
}

