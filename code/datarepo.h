#ifndef DATAREPO
#define DATAREPO
#include <vector>
#include <string>
#include <QtSql>

using namespace std;

class datarepo {
public:
    datarepo();

    void connect();
    void close();

    QSqlQuery query(string queryString);

private:
    QSqlDatabase db;
};

#endif // DATAREPO

