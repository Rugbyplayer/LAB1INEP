#ifndef CONNEXIOBD_H
#define CONNEXIOBD_H

#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <string>

using namespace std;

// Clase para gestionar la conexi�n a MySQL
class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

public:
    // Constructor: establece la conexi�n
    ConnexioBD(const string& host, const string& user, const string& password, const string& schema);

    // Destructor: cierra la conexi�n
    ~ConnexioBD();

    // Ejecuta una consulta SELECT y devuelve los resultados
    sql::ResultSet* executeQuery(const string& query);

    // Ejecuta comandos como INSERT, UPDATE, DELETE
    void executeCommand(const string& command);
};

#endif