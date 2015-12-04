#include <QtSql>
#include "datarepo.h"

datarepo::datarepo(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Cpu_db.sqlite";
    db.setDatabaseName(dbName);
}

void datarepo::connect(){
    db.open();
}

void datarepo::close(){
    db.close();
}

QSqlQuery datarepo::query(string queryString){
    QSqlQuery query(db);
    query.exec("SELECT * FROM scientist");
    return query;
}