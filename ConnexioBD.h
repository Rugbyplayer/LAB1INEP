#ifndef CONNEXIOBD_H
#define CONNEXIOBD_H

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

    // Constructor privado para implementar Singleton
    ConnexioBD(const std::string& host, const std::string& user, const std::string& password, const std::string& schema);

public:
    static ConnexioBD& getInstance();  // Singleton
    ~ConnexioBD();                     // Destructor para liberar recursos

    // Métodos para ejecutar consultas y comandos
    sql::ResultSet* executeQuery(const std::string& query);  // SELECT
    void executeCommand(const std::string& command);         // INSERT, UPDATE, DELETE
};

#endif