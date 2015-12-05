#include "scientist.h"
#include "datarepo.h"
#include <iostream>
#include <QSql>

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

    QSqlQuery query();

    if (id == NULL){
        /*
        query.prepare("INSERT INTO scientists (name, sex, born, death) "
                      "VALUES (:name, :sex, :born, :death)");
        query.bindValue(":name",name);
        query.bindValue(":sex",sex);
        query.bindValue(":born",born);
        query.bindValue(":death",death);
        query.exec();
        */
    }else {
        /*
        query.prepare("UPDATE scientists SET name = :name, sex = :sex, birth = :born , death = :death WHERE id = :id;");
        query.bindValue(":name",name);
        query.bindValue(":sex",sex);
        query.bindValue(":born",born);
        query.bindValue(":death",death);
        query.bindValue(":id", id);
        query.exec();
        */
    }
}

void remove() {

}



