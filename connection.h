#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    QSqlDatabase db;
     bool testconnection=false;
public:
    Connection();
    bool createconnect();
    void closeConnection();
    //getters
        bool get_testConnection_Stat(){return  testconnection;}
};

#endif // CONNECTION_H
