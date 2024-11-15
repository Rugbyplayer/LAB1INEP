#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
using namespace std;

void consulta_usuari(){
    sql::mysql::MySQL_Driver* driver=NULL;
    sql::Connection* con=NULL;
    sql::Statement* stmt=NULL;
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("URL_servidor:port","usuari", "contrasenya");
        con->setSchema("nom_base_dades");
        stmt = con->createStatement();
        string sql = "SELECT * FROM Usuari";
        sql::ResultSet* res=stmt->executeQuery(sql);
        while (res->next()) {
            cout << "Sobrenom: " << res->getString("sobrenom") << endl;
            cout << "Nom: " << res->getString("nom") << endl;
            cout << "Correu: " << res->getString("correu_electronic") << endl;
        }
        con->close();
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        if (con!=NULL) con->close();
    }
}