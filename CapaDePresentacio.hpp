#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include "ConnexioBD.h"
#include <iostream>
#include <string>


void procesarRegistreUsuari(ConnexioBD& connexio);

void procesarModificaUsuari(ConnexioBD& connexio);

void procesarConsultaUsuari(ConnexioBD& connexio);

void procesarEsborraUsuari(ConnexioBD& connexio);