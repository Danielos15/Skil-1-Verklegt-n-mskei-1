#include "scientist.h"
#include "datarepo.h"
#include <iostream>
#include <QSql>
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
void scientist::disable() {
    if (isInTable()){
        QSqlQuery query(db);

        query.prepare("UPDATE scientists SET active = 0 WHERE id = :id;");
        query.bindValue(":id", id);
        query.exec();
        active = 0;
    }
}

void scientist::enable() {
    if (isInTable()){
        QSqlQuery query(db);

        query.prepare("UPDATE scientists SET active = 1 WHERE id = :id;");
        query.bindValue(":id", id);
        query.exec();
        active = 1;
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
