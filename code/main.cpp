#include <QCoreApplication>
#include "repo.h"
#include "scientist.h"
#include "ui.h"
#include "service.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    service engine;
    engine.init();
    engine.run();;

    return a.exec();
}

