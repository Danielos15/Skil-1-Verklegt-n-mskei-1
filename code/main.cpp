#include <QCoreApplication>
#include "repo.h"
#include "scientist.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    repo test("test.csv");
    test.connect();

    return a.exec();
}

