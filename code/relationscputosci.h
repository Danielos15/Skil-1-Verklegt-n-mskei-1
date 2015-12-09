#ifndef RELATIONSCPUTOSCI_H
#define RELATIONSCPUTOSCI_H
#include <vector>
#include "scientist.h"
#include "computer.h"
#include <QtSql>

class relationsCpuToSci
{
public:
    relationsCpuToSci();
    relationsCpuToSci(int newCpu_id, int newSci_id);

    vector<scientist> fetchByCpuId(int cpu_id);
    vector<computer> fetchBySciId(int sci_id);

    void save();
    void remove();
    bool exists();

private:
    QSqlDatabase db;

    bool isInTable();
    int cpu_id;
    int sci_id;
};

#endif // RELATIONSCPUTOSCI_H
