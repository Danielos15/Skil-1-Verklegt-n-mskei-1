#include "scientist.h"
#include "datarepo.h"
#include <iostream>

scientist::scientist(string newName, string newSex, string newBorn, string newDeath = "0"){
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

string scientist::getBorn() const{
    return born;
}

string scientist::getDeath() const{
    return death;
}

void save() {
    datarepo db;
    db.connect();

    QSqlQuery query(db);
    if (id == NULL){
        query.prepare("INSERT INTO scientists (name, sex, born, death) "
                      "VALUES (:name, :sex, :born, :death)");
        query.bindValue(":name",name);
        query.bindValue(":sex",sex);
        query.bindValue(":born",born);
        query.bindValue(":death",death);
        query.exec();
    }else {
        query.prepare("UPDATE scientists SET name = :name, sex = :sex, birth = :born , death = :death WHERE id = :id;");
        query.bindValue(":name",name);
        query.bindValue(":sex",sex);
        query.bindValue(":born",born);
        query.bindValue(":death",death);
        query.bindValue(":id", id);
        query.exec();
    }
}

void remove() {

}



