#ifndef CAPADEPRESENTACIO_HPP
#define CAPADEPRESENTACIO_HPP

#include "CapaDeDomini.hpp"
#include <iostream>
#include <string>

class CapaDePresentacio {
private:
    bool userLoggedIn;        // Indica si hay un usuario logueado
    std::string loggedUser;   // Sobrenombre del usuario logueado
    CapaDePresentacio() : userLoggedIn(false) {}

public:
    static CapaDePresentacio& getInstance() {
        static CapaDePresentacio instance;
        return instance;
    }

    bool isUserLoggedIn() const { return userLoggedIn; }

    // Métodos para procesar los menús y casos de uso
    void procesarIniciarSesion();
    void procesarCerrarSesion();
    void procesarRegistroUsuario();
    void procesarConsultaPerfil();
    void procesarModificacionPerfil();
    void procesarEliminarCuenta();
    void procesarVisualizaciones();
    void procesarConsultas();
};

#endif
