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

    service engine;
    engine.init();
    engine.run();

    /*datarepo db;

    db.connect();
    QSqlQuery query = db.query("Hello Wordl");

    while(query.next()){
        cout << "ID: " << query.value("id").toUInt() << endl;
        cout << "Name: " << query.value("name").toString().toStdString() << endl;
        cout << "Sex: " << query.value("sex").toString().toStdString() << endl;
    }
*/
    //scientist sci("Danni", "Male", 1988, 0);
    //sci.save();
    return a.exec();
}

