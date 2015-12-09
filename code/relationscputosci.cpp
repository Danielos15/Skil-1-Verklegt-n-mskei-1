#include "relationscputosci.h"
#include "scientist.h"
#include "computer.h"
#include "datarepo.h"
#include <QtSql>

relationsCpuToSci::relationsCpuToSci()
{

}

relationsCpuToSci::relationsCpuToSci(int newCpu_id, int newSci_id){
    cpu_id = newCpu_id;
    sci_id = newSci_id;
}

vector<scientist> relationsCpuToSci::fetchByCpuId(int cpu_id){
    vector<int> ids;
    vector<scientist> scientists;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM sci_to_cpu WHERE cpu_id = :id");
    query.bindValue(":id", cpu_id);
    query.exec();

    while(query.next()){
        int newInt = query.value("sci_id").toInt();
        ids.push_back(newInt);
    }

    for (unsigned int i = 0; i < ids.size(); i++){
        query.prepare("SELECT * FROM scientists WHERE id = :id");
        query.bindValue(":id", ids[i]);
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
    }

    return scientists;
}

vector<computer> relationsCpuToSci::fetchBySciId(int sci_id){
    vector<int> ids;
    vector<computer> computers;
    QSqlQuery query(db);

    query.prepare("SELECT * FROM sci_to_cpu WHERE sci_id = :id");
    query.bindValue(":id", sci_id);
    query.exec();

    while(query.next()){
        int newInt = query.value("cpu_id").toInt();
        ids.push_back(newInt);
    }

    for (unsigned int i = 0; i < ids.size(); i++){
        query.prepare("SELECT * FROM computers WHERE id = :id");
        query.bindValue(":id", ids[i]);
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
    }

    return computers;
}

void relationsCpuToSci::save() {
    QSqlQuery query(db);

    if (!isInTable()){
        query.prepare("INSERT INTO sci_to_cpu (cpu_id, sci_id) VALUES (:cpu_id, :sci_id)");
        query.bindValue(":cpu_id",cpu_id);
        query.bindValue(":sci_id",sci_id);
        query.exec();
    }
}

void relationsCpuToSci::remove() {
    if (isInTable()){
        QSqlQuery query(db);

        query.prepare("DELETE FROM sci_to_cpu WHERE cpu_id = :cpu_id AND sci_id = :sci_id");
        query.bindValue(":cpu_id", cpu_id);
        query.bindValue(":sci_id", sci_id);
        query.exec();
    }
}

bool relationsCpuToSci::isInTable(){
    QSqlQuery query(db);

    query.prepare("SELECT * FROM sci_to_cpu WHERE cpu_id = :cpu_id AND sci_id = :sci_id");
    query.bindValue(":sci_id", sci_id);
    query.bindValue(":cpu_id", cpu_id);
    query.exec();
    if (query.first()){
        return true;
    }
    return false;
}

bool relationsCpuToSci::exists() {
    return isInTable();
}

