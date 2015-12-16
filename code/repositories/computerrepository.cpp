#include "repositories/computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;

ComputerRepository::ComputerRepository()
{
    db = utils::getDatabaseConnection();
}

vector<Computer> ComputerRepository::queryComputers(QString sqlQuery)
{
    vector<Computer> computers;

    db.open();

    if (!db.isOpen())
    {
        return computers;
    }

    QSqlQuery query(db);

    if (!query.exec(sqlQuery))
    {
        return computers;
    }

    while (query.next())
    {
        int id = query.value("id").toUInt();
        string name = query.value("name").toString().toStdString();
        enum computerType type = utils::intToComputerType(query.value("type").toInt());
        int yearBuilt = query.value("yearBuilt").toInt();
        bool was = query.value("wasBuilt").toBool();
        string info = query.value("info").toString().toStdString();

        Computer cpu(id, name, type, yearBuilt);
        cpu.setInfo(info);
        cpu.setWasBuilt(was);
        computers.push_back(cpu);
    }

    db.close();

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        computers.at(i).setScientists(queryScientistsByComputer(computers.at(i)));
    }

    return computers;
}

vector<Computer> ComputerRepository::getAllComputers(string orderBy, bool orderAscending)
{
    string ascending = ((orderAscending) ? "ASC" : "DESC");

    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Computers ORDER BY " << orderBy << " " << ascending;

    return queryComputers(QString::fromStdString(sqlQuery.str()));
}

vector<Computer> ComputerRepository::searchForComputers(string searchTerm)
{
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Computers WHERE name LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Computers WHERE type LIKE '%" << searchTerm << "%"
           << "' UNION "
           << "SELECT * FROM Computers WHERE yearBuilt LIKE '%" << searchTerm << "%'";

    return queryComputers(QString::fromStdString(sqlQuery.str()));
}

bool ComputerRepository::addComputer(Computer computer)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "INSERT INTO Computers (name, type, yearBuilt, wasBuilt, info) VALUES ("
             << "'" << computer.getName() << "', "
             << computer.getType() << ", "
             << computer.getYearBuilt() << ", "
             << computer.wasBuilt() << ", "
             << "'" << computer.getInfo() << "'"
             << ")";

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

bool ComputerRepository::removeComputer(int id)
{
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "DELETE FROM Computers where Id = " << id;

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }
    sqlQuery.str("");
    sqlQuery << "DELETE FROM ScientistComputerConnections where computerId = " << id;
    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

bool ComputerRepository::editComputer(Computer computer, int id){
    db.open();

    if (!db.isOpen())
    {
        return false;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "UPDATE Computers SET "
             << "name = " << "'" << computer.getName() << "', "
             << "type = " << computer.getType() << ", "
             << "yearBuilt = " << computer.getYearBuilt() << ", "
             << "wasBuilt = " << computer.wasBuilt() << ", "
             << "info = " << "'" << computer.getInfo() << "' "
             << "WHERE id = " << id;

    if (!query.exec(QString::fromStdString(sqlQuery.str())))
    {
        return false;
    }

    db.close();

    return true;
}

Computer ComputerRepository::fetchById(int id)
{
    db.open();

    QSqlQuery query(db);
    stringstream sqlQuery;
    sqlQuery << "SELECT * FROM Computers WHERE id = " << id;

    if (query.exec(QString::fromStdString(sqlQuery.str())))
    {
        if(query.next()){
            int id = query.value("id").toUInt();
            string name = query.value("name").toString().toStdString();
            enum computerType type = utils::intToComputerType(query.value("type").toInt());
            int yearBuilt = query.value("yearBuilt").toInt();
            bool was = query.value("wasBuilt").toBool();
            string info = query.value("info").toString().toStdString();

            Computer cpu(id, name, type, yearBuilt);
            cpu.setInfo(info);
            cpu.setWasBuilt(was);
            return cpu;
        }
    }
    db.close();

    return Computer();
}

std::vector<Scientist> ComputerRepository::queryScientistsByComputer(Computer computer)
{
    vector<Scientist> scientists;

    db.open();

    if (!db.isOpen())
    {
        return scientists;
    }

    QSqlQuery query(db);

    stringstream sqlQuery;
    sqlQuery << "SELECT s.* FROM ScientistComputerConnections scc ";
    sqlQuery << "JOIN Scientists s ";
    sqlQuery << "ON s.id = scc.scientistId ";
    sqlQuery << "WHERE scc.computerId = " << computer.getId();

    query.exec(QString::fromStdString(sqlQuery.str()));

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

    return scientists;
}
