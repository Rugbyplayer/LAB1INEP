#ifndef CERCADORAPELICULA_HPP
#define CERCADORAPELICULA_HPP

#include "PassarelaPelicula.hpp"
#include <string>

class CercadoraPelicula {
public:
    static PassarelaPelicula cercaPerTitol(const std::string& titol);
};

#endif
