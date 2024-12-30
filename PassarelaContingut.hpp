#ifndef PASSARELACONTINGUT_HPP
#define PASSARELACONTINGUT_HPP

#include <string>
#include "ConnexioBD.hpp"

class PassarelaContingut {
public:
    PassarelaContingut(const std::string& titol, const std::string& descripcio, 
                       const std::string& qualificacio, const std::string& tipus);
    
    void insereix();
    void modifica();
    void esborra();
    
    // Getters y setters
    std::string getTitol() const;
    void setTitol(const std::string& titol);
    std::string getDescripcio() const;
    void setDescripcio(const std::string& descripcio);
    std::string getQualificacio() const;
    void setQualificacio(const std::string& qualificacio);
    std::string getTipus() const;
    void setTipus(const std::string& tipus);

private:
    std::string titol;
    std::string descripcio;
    std::string qualificacio;
    std::string tipus;
    bool esPelicula; // Identifica si el contenido es una película o no
};

#endif
