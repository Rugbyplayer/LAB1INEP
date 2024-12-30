#include "CercadoraContingut.hpp"
#include "ConnexioBD.hpp"
#include <stdexcept>

PassarelaContingut CercadoraContingut::cercaPerTitol(const std::string& titol) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT * FROM contingut WHERE titol = '" + titol + "'";
    sql::ResultSet* res = con.executeQuery(query);

    if (!res->next()) {
        delete res;
        throw std::runtime_error("Contenido no encontrado.");
    }

    std::string descripcio = res->getString("descripcio");
    std::string qualificacio = res->getString("qualificacio");
    std::string tipus = res->getString("tipus");

    // Creamos el objeto de PassarelaContingut
    PassarelaContingut contingut(titol, descripcio, qualificacio, tipus);
    
    delete res;
    return contingut;
}
