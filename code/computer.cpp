#include "computer.h"
#include "datarepo.h"
#include <iostream>

computer:: computer(){
}

computer::computer(string newName, int newBuild, string newType, bool newWas){
    name = newName;
    build = newBuild;
    type = newType;
    was = newWas;
}

int computer::getId() const{
    return id;
}

string computer::getName() const{
    return name;
}

int computer::getBuild() const{
    return build;
}

string computer::getType() const{
    return type;
}

bool computer::getWas() const{
    return was;
}

void computer::setName(string newName){
    name = newName;
}

void computer::setBuild(int newBuild){
    build = newBuild;
}

void computer::setType(string newType){
    type = newType;
}

void computer::setWas(bool newWas){
    was = newWas;
}

void computer::setId(int newId){
    id = newId;
}

void computer::getInfo(){
    QSqlQuery query(db);

    query.prepare("SELECT * FROM computers WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.first()){
        name = query.value("name").toString().toStdString();
        build = query.value("build_year").toInt();
        type = query.value("type").toString().toStdString();
        was = query.value("was_built").toBool();
    }
}

void computer::save() {
    bool inTable = isInTable();
    QSqlQuery query(db);

    if (!inTable){
        query.prepare("INSERT INTO computers (name, build_year, type, was_built) "
                      "VALUES (:name, :build_year, :type, :was_built)");
        query.bindValue(":name",QString::fromStdString(name));
        query.bindValue(":build_year",build);
        query.bindValue(":type",QString::fromStdString(type));
        query.bindValue(":was_built",was);
        query.exec();
        id = query.lastInsertId().toInt();
    }else {
        query.prepare("UPDATE computers SET name = :name, build_year = :build_year, type = :type , was_built = :was_built WHERE id = :id;");
        query.bindValue(":name",QString::fromStdString(name));
        query.bindValue(":build_year",build);
        query.bindValue(":type",QString::fromStdString(type));
        query.bindValue(":was_built",was);
        query.bindValue(":id", id);
        query.exec();
    }
}

void computer::remove() {
    if (isInTable()){
        QSqlQuery query(db);

        query.prepare("DELETE FROM computers WHERE id = :id;");
        query.bindValue(":id", id);
        query.exec();
    }
}

bool computer::exists() {
    return isInTable();
}

bool computer::isInTable(){
    QSqlQuery query(db);

    query.prepare("SELECT * FROM computers WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.first()){
        return true;
    }
    return false;
}

vector<computer> computer::fetchAll(string orderBy){
    QSqlQuery query(db);

    vector<computer> computers;
    query.prepare("SELECT * FROM computers ORDER BY :order");
    query.bindValue(":order", QString::fromStdString(orderBy));
    query.exec();

    while(query.next()){
        computer cpu;
        cpu.setName(query.value("name").toString().toStdString());
        cpu.setBuild(query.value("build_year").toInt());
        cpu.setType(query.value("type").toString().toStdString());
        cpu.setWas(query.value("was_built").toBool());
        cpu.setId(query.value("id").toInt());
        computers.push_back(cpu);
    }
    return computers;
}

vector<computer> computer::fetchByName(string searchString, string orderBy){
    vector<computer> computers;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM computers WHERE name like :name ORDER BY :order");
    query.bindValue(":name", QString::fromStdString("%"+searchString+"%"));
    query.bindValue(":order", QString::fromStdString(orderBy));
    query.exec();

    while(query.next()){
        computer cpu;
        cpu.setName(query.value("name").toString().toStdString());
        cpu.setBuild(query.value("build_year").toInt());
        cpu.setType(query.value("type").toString().toStdString());
        cpu.setWas(query.value("was_built").toBool());
        cpu.setId(query.value("id").toInt());
        computers.push_back(cpu);
    }

    return computers;
}

vector<computer> computer::fetchByBuild(string searchString, string orderBy){
    vector<computer> computers;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM computers WHERE build_year = :build_year ORDER BY :order");
    query.bindValue(":build_year", QString::fromStdString(searchString));
    query.bindValue(":order", QString::fromStdString(orderBy));
    query.exec();

    while(query.next()){
        computer cpu;
        cpu.setName(query.value("name").toString().toStdString());
        cpu.setBuild(query.value("build_year").toInt());
        cpu.setType(query.value("type").toString().toStdString());
        cpu.setWas(query.value("was_built").toBool());
        cpu.setId(query.value("id").toInt());
        computers.push_back(cpu);
    }

    return computers;
}

vector<computer> computer::fetchByType(string searchString, string orderBy){
    vector<computer> computers;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM computers WHERE type like :type ORDER BY :order");
    query.bindValue(":type", QString::fromStdString("%"+searchString+"%"));
    query.bindValue(":order", QString::fromStdString(orderBy));
    query.exec();

    while(query.next()){
        computer cpu;
        cpu.setName(query.value("name").toString().toStdString());
        cpu.setBuild(query.value("build_year").toInt());
        cpu.setType(query.value("type").toString().toStdString());
        cpu.setWas(query.value("was_built").toBool());
        cpu.setId(query.value("id").toInt());
        computers.push_back(cpu);
    }

    return computers;
}

vector<computer> computer::fetchByWasBuilt(string searchString, string orderBy){
    vector<computer> computers;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM computers WHERE was_built = :was_built ORDER BY :order");
    query.bindValue(":was_built", QString::fromStdString(searchString));
    query.bindValue(":order", QString::fromStdString(orderBy));
    query.exec();

    while(query.next()){
        computer cpu;
        cpu.setName(query.value("name").toString().toStdString());
        cpu.setBuild(query.value("build_year").toInt());
        cpu.setType(query.value("type").toString().toStdString());
        cpu.setWas(query.value("was_built").toBool());
        cpu.setId(query.value("id").toInt());
        computers.push_back(cpu);
    }

    return computers;
}
