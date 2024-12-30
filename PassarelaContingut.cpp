#include "PassarelaContingut.hpp"
#include <stdexcept>

PassarelaContingut::PassarelaContingut(const std::string& titol, const std::string& descripcio, 
                                       const std::string& qualificacio, const std::string& tipus)
    : titol(titol), descripcio(descripcio), qualificacio(qualificacio), tipus(tipus) {
    esPelicula = (tipus == "pelicula");
}

void PassarelaContingut::insereix() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES ('" 
                        + titol + "', '" + descripcio + "', '" + qualificacio + "', '" + tipus + "')";
    con.executeCommand(query);
    
    // Si el contenido es una película, también insertamos en la tabla `pelicula`
    if (esPelicula) {
        std::string queryPelicula = "INSERT INTO pelicula (titol) VALUES ('" + titol + "')";
        con.executeCommand(queryPelicula);
    }
}

void PassarelaContingut::modifica() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "UPDATE contingut SET descripcio = '" + descripcio + "', qualificacio = '" + qualificacio 
                        + "', tipus = '" + tipus + "' WHERE titol = '" + titol + "'";
    con.executeCommand(query);

    // Si el contenido es una película, actualizamos también en la tabla `pelicula`
    if (esPelicula) {
        std::string queryPelicula = "UPDATE pelicula SET titol = '" + titol + "' WHERE titol = '" + titol + "'";
        con.executeCommand(queryPelicula);
    }
}

void PassarelaContingut::esborra() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "DELETE FROM contingut WHERE titol = '" + titol + "'";
    con.executeCommand(query);

    // Si el contenido es una película, eliminamos también de la tabla `pelicula`
    if (esPelicula) {
        std::string queryPelicula = "DELETE FROM pelicula WHERE titol = '" + titol + "'";
        con.executeCommand(queryPelicula);
    }
}

std::string PassarelaContingut::getTitol() const { return titol; }
void PassarelaContingut::setTitol(const std::string& titol) { this->titol = titol; }

std::string PassarelaContingut::getDescripcio() const { return descripcio; }
void PassarelaContingut::setDescripcio(const std::string& descripcio) { this->descripcio = descripcio; }

std::string PassarelaContingut::getQualificacio() const { return qualificacio; }
void PassarelaContingut::setQualificacio(const std::string& qualificacio) { this->qualificacio = qualificacio; }

std::string PassarelaContingut::getTipus() const { return tipus; }
void PassarelaContingut::setTipus(const std::string& tipus) { this->tipus = tipus; }
