<<<<<<< HEAD
#include "PassarelaCapitol.hpp"
#include <stdexcept>

PassarelaCapitol::PassarelaCapitol(const std::string& titolSerie, int numTemporada, int numCapitol, 
                                   const std::string& titolCapitol, const std::string& dataEstrena, const std::string& qualificacio)
    : titolSerie(titolSerie), numTemporada(numTemporada), numCapitol(numCapitol), titolCapitol(titolCapitol), 
      dataEstrena(dataEstrena), qualificacio(qualificacio) {}

void PassarelaCapitol::insereix() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Insertamos en la tabla `capitol`
    std::string queryCapitol = "INSERT INTO capitol (titol_serie, numero_temporada, numero, titol, data_estrena, qualificacio) VALUES ('" 
                               + titolSerie + "', " + std::to_string(numTemporada) + ", " + std::to_string(numCapitol) + ", '"
                               + titolCapitol + "', '" + dataEstrena + "', '" + qualificacio + "')";
    con.executeCommand(queryCapitol);
    
    // Insertamos el contenido en la tabla `contingut`
    std::string queryContingut = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES ('" 
                                + titolCapitol + "', '', '" + qualificacio + "', 'serie')";
    con.executeCommand(queryContingut);
}

void PassarelaCapitol::modifica() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Actualizamos el capítulo
    std::string queryCapitol = "UPDATE capitol SET titol = '" + titolCapitol + "', data_estrena = '" + dataEstrena 
                               + "', qualificacio = '" + qualificacio + "' WHERE titol_serie = '" + titolSerie + "' AND "
                               "numero_temporada = " + std::to_string(numTemporada) + " AND numero = " + std::to_string(numCapitol);
    con.executeCommand(queryCapitol);
}

void PassarelaCapitol::esborra() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Eliminamos el capítulo de la tabla `capitol`
    std::string queryCapitol = "DELETE FROM capitol WHERE titol_serie = '" + titolSerie + "' AND numero_temporada = "
                               + std::to_string(numTemporada) + " AND numero = " + std::to_string(numCapitol);
    con.executeCommand(queryCapitol);

    // Eliminamos el contenido de la tabla `contingut`
    std::string queryContingut = "DELETE FROM contingut WHERE titol = '" + titolCapitol + "'";
    con.executeCommand(queryContingut);
}

std::string PassarelaCapitol::getTitolSerie() const { return titolSerie; }
void PassarelaCapitol::setTitolSerie(const std::string& titolSerie) { this->titolSerie = titolSerie; }

int PassarelaCapitol::getNumTemporada() const { return numTemporada; }
void PassarelaCapitol::setNumTemporada(int numTemporada) { this->numTemporada = numTemporada; }

int PassarelaCapitol::getNumCapitol() const { return numCapitol; }
void PassarelaCapitol::setNumCapitol(int numCapitol) { this->numCapitol = numCapitol; }

std::string PassarelaCapitol::getTitolCapitol() const { return titolCapitol; }
void PassarelaCapitol::setTitolCapitol(const std::string& titolCapitol) { this->titolCapitol = titolCapitol; }

std::string PassarelaCapitol::getDataEstrena() const { return dataEstrena; }
void PassarelaCapitol::setDataEstrena(const std::string& dataEstrena) { this->dataEstrena = dataEstrena; }

std::string PassarelaCapitol::getQualificacio() const { return qualificacio; }
=======
#include "PassarelaCapitol.hpp"
#include <stdexcept>

PassarelaCapitol::PassarelaCapitol(const std::string& titolSerie, int numTemporada, int numCapitol, 
                                   const std::string& titolCapitol, const std::string& dataEstrena, const std::string& qualificacio)
    : titolSerie(titolSerie), numTemporada(numTemporada), numCapitol(numCapitol), titolCapitol(titolCapitol), 
      dataEstrena(dataEstrena), qualificacio(qualificacio) {}

void PassarelaCapitol::insereix() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Insertamos en la tabla `capitol`
    std::string queryCapitol = "INSERT INTO capitol (titol_serie, numero_temporada, numero, titol, data_estrena, qualificacio) VALUES ('" 
                               + titolSerie + "', " + std::to_string(numTemporada) + ", " + std::to_string(numCapitol) + ", '"
                               + titolCapitol + "', '" + dataEstrena + "', '" + qualificacio + "')";
    con.executeCommand(queryCapitol);
    
    // Insertamos el contenido en la tabla `contingut`
    std::string queryContingut = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES ('" 
                                + titolCapitol + "', '', '" + qualificacio + "', 'serie')";
    con.executeCommand(queryContingut);
}

void PassarelaCapitol::modifica() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Actualizamos el capítulo
    std::string queryCapitol = "UPDATE capitol SET titol = '" + titolCapitol + "', data_estrena = '" + dataEstrena 
                               + "', qualificacio = '" + qualificacio + "' WHERE titol_serie = '" + titolSerie + "' AND "
                               "numero_temporada = " + std::to_string(numTemporada) + " AND numero = " + std::to_string(numCapitol);
    con.executeCommand(queryCapitol);
}

void PassarelaCapitol::esborra() {
    ConnexioBD& con = ConnexioBD::getInstance();

    // Eliminamos el capítulo de la tabla `capitol`
    std::string queryCapitol = "DELETE FROM capitol WHERE titol_serie = '" + titolSerie + "' AND numero_temporada = "
                               + std::to_string(numTemporada) + " AND numero = " + std::to_string(numCapitol);
    con.executeCommand(queryCapitol);

    // Eliminamos el contenido de la tabla `contingut`
    std::string queryContingut = "DELETE FROM contingut WHERE titol = '" + titolCapitol + "'";
    con.executeCommand(queryContingut);
}

std::string PassarelaCapitol::getTitolSerie() const { return titolSerie; }
void PassarelaCapitol::setTitolSerie(const std::string& titolSerie) { this->titolSerie = titolSerie; }

int PassarelaCapitol::getNumTemporada() const { return numTemporada; }
void PassarelaCapitol::setNumTemporada(int numTemporada) { this->numTemporada = numTemporada; }

int PassarelaCapitol::getNumCapitol() const { return numCapitol; }
void PassarelaCapitol::setNumCapitol(int numCapitol) { this->numCapitol = numCapitol; }

std::string PassarelaCapitol::getTitolCapitol() const { return titolCapitol; }
void PassarelaCapitol::setTitolCapitol(const std::string& titolCapitol) { this->titolCapitol = titolCapitol; }

std::string PassarelaCapitol::getDataEstrena() const { return dataEstrena; }
void PassarelaCapitol::setDataEstrena(const std::string& dataEstrena) { this->dataEstrena = dataEstrena; }

std::string PassarelaCapitol::getQualificacio() const { return qualificacio; }
>>>>>>> a64d954eefe6e14ba1521b6c4f7ee246d8566851
void PassarelaCapitol::setQualificacio(const std::string& qualificacio) { this->qualificacio = qualificacio; }