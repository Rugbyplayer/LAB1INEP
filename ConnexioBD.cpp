#include "ConnexioBD.h"
#include <cppconn/exception.h>
#include <stdexcept>

// Constructor privado
ConnexioBD::ConnexioBD(const std::string& host, const std::string& user, const std::string& password, const std::string& schema) {
  
}

// Destructor
ConnexioBD::~ConnexioBD() {
    delete con;
}

// Implementación del Singleton
ConnexioBD& ConnexioBD::getInstance() {
    static ConnexioBD instance("tcp://ubiwan.epsevg.upc.edu:3306", "inep27", "ohZol1Wie9chah", "inep27");
    return instance;
}

// Ejecutar consultas SELECT
sql::ResultSet* ConnexioBD::executeQuery(const std::string& query) {
    try {
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(query);
        delete stmt;
        return res;
    }
    catch (sql::SQLException& e) {
        throw std::runtime_error("Error al ejecutar consulta: " + std::string(e.what()));
    }
}

// Ejecutar comandos INSERT, UPDATE, DELETE
void ConnexioBD::executeCommand(const std::string& command) {
    try {
        sql::Statement* stmt = con->createStatement();
        stmt->execute(command);
        delete stmt;
    }
    catch (sql::SQLException& e) {
        throw std::runtime_error("Error al ejecutar comando: " + std::string(e.what()));
    }
}