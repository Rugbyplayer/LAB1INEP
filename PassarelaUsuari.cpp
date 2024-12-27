#include "PassarelaUsuari.hpp"
#include <stdexcept>

void PassarelaUsuari::insereix() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic, contrasenya) VALUES ('" + sobrenom + 
                        "', '" + nom + "', '" + correu + "', '" + contrasenya + "')";
    con.executeCommand(query);
}

void PassarelaUsuari::modifica() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "UPDATE usuari SET nom = '" + nom + "', correu_electronic = '" + correu + 
                        "' WHERE sobrenom = '" + sobrenom + "'";
    con.executeCommand(query);
}

void PassarelaUsuari::cambiaContrasenya(const std::string& novaContrasenya) {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "UPDATE usuari SET contrasenya = '" + novaContrasenya + 
                        "' WHERE sobrenom = '" + sobrenom + "'";
    con.executeCommand(query);
}

void PassarelaUsuari::esborra() {
    ConnexioBD& con = ConnexioBD::getInstance();
    std::string query = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "'";
    con.executeCommand(query);
}
