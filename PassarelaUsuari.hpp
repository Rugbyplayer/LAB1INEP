#ifndef PASSARELAUSUARI_HPP
#define PASSARELAUSUARI_HPP

#include <string>
#include "ConnexioBD.h"

class PassarelaUsuari {
private:
    std::string sobrenom;
    std::string nom;
    std::string correu;
    std::string dataNaixement;
    std::string modalitatSubscripcio;
    int peliculesVisualitzades;
    int capitolsVisualitzats;

public:
    PassarelaUsuari(const std::string& s, const std::string& n, const std::string& c,
        const std::string& data, const std::string& modalitat,
        int pelicules, int capitols)
        : sobrenom(s), nom(n), correu(c), dataNaixement(data),
        modalitatSubscripcio(modalitat), peliculesVisualitzades(pelicules),
        capitolsVisualitzats(capitols) {}

    // Métodos para obtener datos.
    std::string obteSobrenom() const { return sobrenom; }
    std::string obteNom() const { return nom; }
    std::string obteCorreuElectronic() const { return correu; }
    std::string obteDataNaixement() const { return dataNaixement; }
    std::string obteModalitatSubscripcio() const { return modalitatSubscripcio; }
    int obtePeliculesVisualitzades() const { return peliculesVisualitzades; }
    int obteCapitolsVisualitzats() const { return capitolsVisualitzats; }
};

#endif
