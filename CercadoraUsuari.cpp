#include "CercadoraUsuari.hpp"
#include <stdexcept>

PassarelaUsuari CercadoraUsuari::cercaPerSobrenom(const std::string& sobrenom) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenom + "'";
    sql::ResultSet* res = con.executeQuery(query);

    if (!res->next()) {
        delete res;
        throw std::runtime_error("Usuario no encontrado.");
    }

    PassarelaUsuari usuari(res->getString("sobrenom"), res->getString("nom"), 
                           res->getString("correu_electronic"), res->getString("contrasenya"));
    delete res;
    return usuari;
}
