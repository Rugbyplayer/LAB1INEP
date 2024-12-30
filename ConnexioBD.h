#ifndef CONNEXIOBD_H
#define CONNEXIOBD_H

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>


class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    // Constructor privado para Singleton
    ConnexioBD(const std::string& host, const std::string& user, const std::string& password, const std::string& schema);

public:
    static ConnexioBD& getInstance();  // Singleton
    ~ConnexioBD();                     // Destructor para liberar recursos

    sql::ResultSet* executeQuery(const std::string& query);  // SELECT
    void executeCommand(const std::string& command);         // INSERT, UPDATE, DELETE
};

#endif