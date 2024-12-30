#ifndef PASSARELAPELICULA_HPP
#define PASSARELAPELICULA_HPP

#include <string>
#include "ConnexioBD.hpp"

class PassarelaPelicula {
public:
    PassarelaPelicula(const std::string& titol, const std::string& dataEstrena, int duracio);

    void insereix();
    void modifica();
    void esborra();

    // Getters y setters
    std::string getTitol() const;
    void setTitol(const std::string& titol);
    std::string getDataEstrena() const;
    void setDataEstrena(const std::string& dataEstrena);
    int getDuracio() const;
    void setDuracio(int duracio);

private:
    std::string titol;
    std::string dataEstrena;
    int duracio;
};

#endif
