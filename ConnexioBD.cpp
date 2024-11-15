#include "ConnexioBD.h"
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysql_driver.h>

ConnexioBD::ConnexioBD(const string& host, const string& user, const string& password, const string& schema) {
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(host, user, password);
    con->setSchema(schema);
}

ConnexioBD::~ConnexioBD() {
    if (con != nullptr) {
        con->close();
        delete con;
    }
}

sql::ResultSet* ConnexioBD::executeQuery(const string& query) {
    sql::Statement* stmt = con->createStatement();
    sql::ResultSet* res = stmt->executeQuery(query);
    delete stmt;
    return res;
}

void ConnexioBD::executeCommand(const string& command) {
    sql::Statement* stmt = con->createStatement();
    stmt->execute(command);
    delete stmt;
}