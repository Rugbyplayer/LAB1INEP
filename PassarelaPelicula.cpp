#include "PassarelaPelicula.hpp"
#include <stdexcept>

PassarelaPelicula::PassarelaPelicula(const std::string& titol, const std::string& dataEstrena, int duracio)
    : titol(titol), dataEstrena(dataEstrena), duracio(duracio) {}

void PassarelaPelicula::insereix() {
    ConnexioBD& con = ConnexioBD::getInstance();
    
    // Insertamos en la tabla `pelicula`
    std::string queryPelicula = "INSERT INTO pelicula (titol, data_estrena, duracio) VALUES ('" + titol + "', '" 
                                + dataEstrena + "', " + std::to_string(duracio) + ")";
    con.executeCommand(queryPelicula);
    
    // Insertamos el contenido en la tabla `contingut`
    std::string queryContingut = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES ('" 
                                + titol + "', '', '', 'pelicula')";
    con.executeCommand(queryContingut);
}

void PassarelaPelicula::modifica() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Actualizamos la película
    std::string queryPelicula = "UPDATE pelicula SET data_estrena = '" + dataEstrena + "', duracio = " 
                                + std::to_string(duracio) + " WHERE titol = '" + titol + "'";
    con.executeCommand(queryPelicula);
}

void PassarelaPelicula::esborra() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Eliminamos la película de la tabla `pelicula`
    std::string queryPelicula = "DELETE FROM pelicula WHERE titol = '" + titol + "'";
    con.executeCommand(queryPelicula);

    // Eliminamos el contenido de la tabla `contingut`
    std::string queryContingut = "DELETE FROM contingut WHERE titol = '" + titol + "'";
    con.executeCommand(queryContingut);
}

std::string PassarelaPelicula::getTitol() const { return titol; }
void PassarelaPelicula::setTitol(const std::string& titol) { this->titol = titol; }

std::string PassarelaPelicula::getDataEstrena() const { return dataEstrena; }
void PassarelaPelicula::setDataEstrena(const std::string& dataEstrena) { this->dataEstrena = dataEstrena; }

int PassarelaPelicula::getDuracio() const { return duracio; }
void PassarelaPelicula::setDuracio(int duracio) { this->duracio = duracio; }