#include "CercadoraCapitol.hpp"
#include "ConnexioBD.hpp"
#include <stdexcept>

PassarelaCapitol CercadoraCapitol::cercaPerTitolSerieCapitol(const std::string& titolSerie, int numTemporada, int numCapitol) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT * FROM capitol WHERE titol_serie = '" + titolSerie + "' AND numero_temporada = "
                        + std::to_string(numTemporada) + " AND numero = " + std::to_string(numCapitol);
    sql::ResultSet* res = con.executeQuery(query);

    if (!res->next()) {
        delete res;
        throw std::runtime_error("Capítulo no encontrado.");
    }

    std::string titolCapitol = res->getString("titol");
    std::string dataEstrena = res->getString("data_estrena");
    std::string qualificacio = res->getString("qualificacio");
    delete res;

    PassarelaCapitol capitol(titolSerie, numTemporada, numCapitol, titolCapitol, dataEstrena, qualificacio);
    return capitol;
}
