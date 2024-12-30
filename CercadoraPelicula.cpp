#include "CercadoraPelicula.hpp"
#include "ConnexioBD.hpp"
#include <stdexcept>

PassarelaPelicula CercadoraPelicula::cercaPerTitol(const std::string& titol) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "SELECT * FROM pelicula WHERE titol = '" + titol + "'";
    sql::ResultSet* res = con.executeQuery(query);

    if (!res->next()) {
        delete res;
        throw std::runtime_error("Película no encontrada.");
    }

    std::string dataEstrena = res->getString("data_estrena");
    int duracio = res->getInt("duracio");
    delete res;

    PassarelaPelicula pelicula(titol, dataEstrena, duracio);
    return pelicula;
}
