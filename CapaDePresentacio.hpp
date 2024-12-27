#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP

#include "CapaDeDomini.hpp"
#include <iostream>
#include <string>

class CapaDePresentacio {
private:
    bool userLoggedIn;
    std::string loggedUser;
    CapaDePresentacio() : userLoggedIn(false) {}

public:
    static CapaDePresentacio& getInstance() {
        static CapaDePresentacio instance;
        return instance;
    }

    bool isUserLoggedIn() const { return userLoggedIn; }

    // Métodos para gestionar el sistema
    void procesarIniciarSesion();
    void procesarCerrarSesion();
    void procesarRegistroUsuario();
    void procesarConsultaPerfil();
    void procesarModificacionPerfil();
    void procesarCambiarContrasenya();
    void procesarEliminarCuenta();
};

#endif