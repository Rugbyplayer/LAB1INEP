#ifndef CERCADORAUSUARI_HPP
#define CERCADORAUSUARI_HPP

#include <string>
#include "PassarelaUsuari.hpp"

class CercadoraUsuari {
public:
    PassarelaUsuari cercaPerSobrenom(const std::string& sobrenom);
};

#endif
