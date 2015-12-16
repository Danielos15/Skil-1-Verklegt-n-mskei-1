#include "scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <cstdlib>
#include <sstream>
#include <QString>
#include <QDebug>

using namespace std;

ScientistRepository::ScientistRepository()
{
    db = utils::getDatabaseConnection();
}

vector<Scientist> ScientistRepository::queryScientists(QString sqlQuery)
{
    vector<Scientist> scientists;

    db.open();

    if (!db.isOpen())
    {
        return scientists;
    }

    QSqlQuery query(db);

    if (!query.exec(sqlQuery))
    {
        return scientists;
    }

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        enum sexType sex = utils::intToSex(query.value("sex").toInt());
        int yearBorn = query.value("yearBorn").toInt();
        int yearDied = query.value("yearDied").toInt();
        string info = query.value("info").toString().toStdString();
        Scientist sci(id, name, sex, yearBorn, yearDied);
        sci.setInfo(info);
        scientists.push_back(sci);
    }

    db.close();

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        Scientist currentScientist = scientists.at(i);
        currentScientist.setComputers(queryComputersByScientist(currentScientist));
    }

    return scientists;
}

vector<Scientist> ScientistRepository::getAllScientists(string orderBy, bool orderAscending)
{
    string ascending = ((orderAscending) ? "ASC" : "DESC");

    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists ORDER BY " << orderBy << " " << ascending;

    return queryScientists(QString::fromStdString(sqlQuery.str()));
}

vector<Scientist> ScientistRepository::searchForScientists(string searchTerm)
{
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists WHERE name LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Scientists WHERE yearBorn LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Scientists WHERE yearDied LIKE '%" << searchTerm << "%'";

    return queryScientists(QString::fromStdString(sqlQuery.str()));
}

bool ScientistRepository::addScientist(Scientist scientist)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO Scientists (name, sex, yearBorn, yearDied, info) VALUES ("
             << "'" << scientist.getName() << "', "
             << scientist.getSex() << ", "
             << scientist.getYearBorn() << ", "
             << scientist.getYearDied() << ", "
             << "'" << scientist.getInfo() << "'"
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

bool ScientistRepository::removeScientist(int id)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM Scientists where Id = " << id;

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

std::vector<Computer> ScientistRepository::queryComputersByScientist(Scientist scientist)
{
    vector<Computer> computers;

    db.open();

    if (!db.isOpen())
    {
        return computers;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "SELECT c.* FROM ScientistComputerConnections scc ";
    sqlQuery << "JOIN Computers c ";
    sqlQuery << "ON c.id = scc.computerId ";
    sqlQuery << "WHERE scc.scientistId = " << scientist.getId();

    query.exec(QString::fromStdString(sqlQuery.str()));

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        enum computerType type = utils::intToComputerType(query.value("type").toInt());
        int yearBuilt = query.value("yearBuilt").toInt();
        bool was = query.value("wasBuilt").toBool();
        string info = query.value("name").toString().toStdString();

        Computer cpu(id, name, type, yearBuilt);
        cpu.setInfo(info);
        cpu.setWasBuilt(was);
        computers.push_back(cpu);
    }

    return computers;
}

Scientist ScientistRepository::fetchById(int id)
{
    QSqlQuery query(db);
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Scientists WHERE id = " << id;

    if (query.exec(QString::fromStdString(sqlQuery.str())))
    {
        query.next();
        unsigned int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        enum sexType sex = utils::intToSex(query.value("sex").toInt());
        int yearBorn = query.value("yearBorn").toInt();
        int yearDied = query.value("yearDied").toInt();
        string info = query.value("info").toString().toStdString();
        Scientist sci(id, name, sex, yearBorn, yearDied);
        sci.setInfo(info);

        return sci;
    }
    return Scientist();
}
