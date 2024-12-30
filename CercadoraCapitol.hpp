#ifndef CERCADORACAPITOL_HPP
#define CERCADORACAPITOL_HPP

#include "PassarelaCapitol.hpp"
#include <string>

class CercadoraCapitol {
public:
    static PassarelaCapitol cercaPerTitolSerieCapitol(const std::string& titolSerie, int numTemporada, int numCapitol);
};

#endif
