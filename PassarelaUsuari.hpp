#ifndef PASSARELAUSUARI_HPP
#define PASSARELAUSUARI_HPP

#include <string>
#include "ConnexioBD.h"

class PassarelaUsuari {
private:
    std::string sobrenom;
    std::string nom;
    std::string correu;
    std::string contrasenya;

public:
    PassarelaUsuari(const std::string& s, const std::string& n, const std::string& c, const std::string& passwd)
        : sobrenom(s), nom(n), correu(c), contrasenya(passwd) {}

    void insereix();
    void modifica();
    void cambiaContrasenya(const std::string& novaContrasenya);
    void esborra();

    // Métodos de acceso
    std::string obteNom() const { return nom; }
    std::string obteSobrenom() const { return sobrenom; }
    std::string obteCorreuElectronic() const { return correu; }
    std::string obteContrasenya() const { return contrasenya; }

    // Métodos de modificación
    void posaNom(const std::string& nouNom) { nom = nouNom; }
    void posaCorreuElectronic(const std::string& nouCorreu) { correu = nouCorreu; }

    void registraVisualizacion(int idUsuari, int idContingut, const std::string& dataVisualitzacio);
    std::vector<std::string> consultaVisualizaciones(int idUsuari);
};

#endif
