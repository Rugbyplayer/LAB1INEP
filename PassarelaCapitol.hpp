#ifndef PASSARELACAPITOL_HPP
#define PASSARELACAPITOL_HPP

#include <string>
#include "ConnexioBD.hpp"

class PassarelaCapitol {
public:
    PassarelaCapitol(const std::string& titolSerie, int numTemporada, int numCapitol, const std::string& titolCapitol, 
                     const std::string& dataEstrena, const std::string& qualificacio);

    void insereix();
    void modifica();
    void esborra();

    // Getters y setters
    std::string getTitolSerie() const;
    void setTitolSerie(const std::string& titolSerie);
    int getNumTemporada() const;
    void setNumTemporada(int numTemporada);
    int getNumCapitol() const;
    void setNumCapitol(int numCapitol);
    std::string getTitolCapitol() const;
    void setTitolCapitol(const std::string& titolCapitol);
    std::string getDataEstrena() const;
    void setDataEstrena(const std::string& dataEstrena);
    std::string getQualificacio() const;
    void setQualificacio(const std::string& qualificacio);

private:
    std::string titolSerie;
    int numTemporada;
    int numCapitol;
    std::string titolCapitol;
    std::string dataEstrena;
    std::string qualificacio;
};

#endif
