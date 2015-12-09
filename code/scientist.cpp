#include "scientist.h"
#include "datarepo.h"
#include <iostream>

scientist::scientist(){
}

scientist::scientist(string newName, string newSex, int newBorn, int newDeath){
    name = newName;
    sex = newSex;
    born = newBorn;
    death = newDeath;
}

int scientist::getId() const{
    return id;
}

string scientist::getName() const{
    return name;
}

string scientist::getSex() const{
    return sex;
}

int scientist::getBorn() const{
    return born;
}

int scientist::getDeath() const{
    return death;
}

void scientist::setName(string newName){
    name = newName;
}

void scientist::setSex(string newSex){
    sex = newSex;
}

void scientist::setBorn(int newBirth){
    born = newBirth;
}

void scientist::setDeath(int newDeath){
    death = newDeath;
}

void scientist::setId(int newId){
    id = newId;
}

void scientist::save() {
    bool inTable = isInTable();
    QSqlQuery query(db);

    if (!inTable){
        query.prepare("INSERT INTO scientists (name, sex, birth, death) "
                      "VALUES (:name, :sex, :born, :death)");
        query.bindValue(":name",QString::fromStdString(name));
        query.bindValue(":sex",QString::fromStdString(sex));
        query.bindValue(":born",born);
        query.bindValue(":death",death);
        query.exec();
        id = query.lastInsertId().toInt();
    }else {
        query.prepare("UPDATE scientists SET name = :name, sex = :sex, birth = :born , death = :death WHERE id = :id;");
        query.bindValue(":name",QString::fromStdString(name));
        query.bindValue(":sex",QString::fromStdString(sex));
        query.bindValue(":born",born);
        query.bindValue(":death",death);
        query.bindValue(":id", id);
        query.exec();
    }
}

void scientist::remove() {
    if (isInTable()){
        QSqlQuery query(db);

        query.prepare("DELETE FROM scientists WHERE id = :id;");
        query.bindValue(":id", id);
        query.exec();
    }
}


bool scientist::isInTable(){
    QSqlQuery query(db);

    query.prepare("SELECT * FROM scientists WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.first()){
        return true;
    }
    return false;
}

vector<scientist> scientist::fetchAll(){
    QSqlQuery query(db);

    vector<scientist> scientists;
    query.prepare("SELECT * FROM scientists");
    query.exec();

    while(query.next()){
        scientist sci;
        sci.setName(query.value("name").toString().toStdString());
        sci.setSex(query.value("sex").toString().toStdString());
        sci.setBorn(query.value("birth").toInt());
        sci.setDeath(query.value("death").toInt());
        sci.setId(query.value("id").toInt());
        scientists.push_back(sci);
    }
    return scientists;
}


vector<scientist> scientist::fetchByName(string searchString){
    vector<scientist> scientists;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM scientists WHERE name like :name");
    query.bindValue(":name", QString::fromStdString("%"+searchString+"%"));
    query.exec();

    while(query.next()){
        scientist sci;
        sci.setName(query.value("name").toString().toStdString());
        sci.setSex(query.value("sex").toString().toStdString());
        sci.setBorn(query.value("birth").toInt());
        sci.setDeath(query.value("death").toInt());
        sci.setId(query.value("id").toInt());
        scientists.push_back(sci);
    }

    return scientists;
}

vector<scientist> scientist::fetchBySex(string searchString){
    vector<scientist> scientists;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM scientists WHERE sex like :sex");
    query.bindValue(":sex", QString::fromStdString(searchString));
    query.exec();

    while(query.next()){
        scientist sci;
        sci.setName(query.value("name").toString().toStdString());
        sci.setSex(query.value("sex").toString().toStdString());
        sci.setBorn(query.value("birth").toInt());
        sci.setDeath(query.value("death").toInt());
        sci.setId(query.value("id").toInt());
        scientists.push_back(sci);
    }

    return scientists;
}

vector<scientist> scientist::fetchByBorn(string searchString){
    vector<scientist> scientists;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM scientists WHERE birth = :birth");
    query.bindValue(":birth", QString::fromStdString(searchString));
    query.exec();

    while(query.next()){
        scientist sci;
        sci.setName(query.value("name").toString().toStdString());
        sci.setSex(query.value("sex").toString().toStdString());
        sci.setBorn(query.value("birth").toInt());
        sci.setDeath(query.value("death").toInt());
        sci.setId(query.value("id").toInt());
        scientists.push_back(sci);
    }

    return scientists;
}

vector<scientist> scientist::fetchByDeath(string searchString){
    vector<scientist> scientists;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM scientists WHERE death = :death");
    query.bindValue(":death", QString::fromStdString(searchString));
    query.exec();

    while(query.next()){
        scientist sci;
        sci.setName(query.value("name").toString().toStdString());
        sci.setSex(query.value("sex").toString().toStdString());
        sci.setBorn(query.value("birth").toInt());
        sci.setDeath(query.value("death").toInt());
        sci.setId(query.value("id").toInt());
        scientists.push_back(sci);
    }

    return scientists;
}
