#include <QCoreApplication>
#include "repo.h"
#include "scientist.h"
#include "ui.h"
#include "service.h"
#include "datarepo.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    datarepo db;
    db.connect();

    //service engine;
    //engine.init();
    //engine.run();

    scientist sci("Adis", "Male", 1988, 0);
    sci.save();

    sci.setBorn(1989);
    sci.save();

    sci.setDeath(2014);
    sci.setSex("Female");
    sci.save();
    sci.disable();

    scientist sci2("Adis", "Male", 1988, 0);
    sci2.setName("Danni");
    sci2.setSex("Male");
    sci2.save();

    db.close();

    return a.exec();
}

