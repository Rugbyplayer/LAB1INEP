#include "CapaDePresentacio.hpp"

void CapaDePresentacio::procesarIniciarSesion() {
    std::string sobrenom, contrasenya;
    std::cout << "Iniciar Sesión" << std::endl;
    std::cout << "Sobrenombre: ";
    std::cin >> sobrenom;
    std::cout << "Contraseña: ";
    std::cin >> contrasenya;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.iniciarSesion(sobrenom, contrasenya);
        loggedUser = sobrenom;
        userLoggedIn = true;
        std::cout << "Sesión iniciada correctamente." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarCerrarSesion() {
    userLoggedIn = false;
    loggedUser.clear();
    std::cout << "Sesión cerrada." << std::endl;
}

void CapaDePresentacio::procesarRegistroUsuario() {
    std::string sobrenom, nom, contrasenya, correo;
    std::cout << "Registrar Usuario" << std::endl;
    std::cout << "Sobrenombre: ";
    std::cin >> sobrenom;
    std::cout << "Nombre: ";
    std::cin >> nom;
    std::cout << "Contraseña: ";
    std::cin >> contrasenya;
    std::cout << "Correo Electrónico: ";
    std::cin >> correo;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.registrarUsuario(nom, sobrenom, contrasenya, correo);
        std::cout << "Usuario registrado correctamente." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarConsultaPerfil() {
    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        auto perfil = domini.consultarPerfil(loggedUser);
        std::cout << "Perfil del Usuario" << std::endl;
        std::cout << "Nombre: " << perfil.nom << std::endl;
        std::cout << "Sobrenombre: " << perfil.sobrenom << std::endl;
        std::cout << "Correo: " << perfil.correu << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarModificacionPerfil() {
    std::string nuevoNom, nuevoCorreo;
    std::cout << "Modificar Perfil" << std::endl;
    std::cout << "Nuevo nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nuevoNom);
    std::cout << "Nuevo correo: ";
    std::getline(std::cin, nuevoCorreo);

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.modificarPerfil(loggedUser, nuevoNom, nuevoCorreo);
        std::cout << "Perfil actualizado correctamente." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarCambiarContrasenya() {
    std::string contrasenyaActual, nuevaContrasenya;
    std::cout << "Cambiar Contraseña" << std::endl;
    std::cout << "Contraseña actual: ";
    std::cin >> contrasenyaActual;
    std::cout << "Nueva contraseña: ";
    std::cin >> nuevaContrasenya;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.cambiarContrasenya(loggedUser, contrasenyaActual, nuevaContrasenya);
        std::cout << "Contraseña actualizada correctamente." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarEliminarCuenta() {
    std::string contrasenya;
    std::cout << "Eliminar Cuenta" << std::endl;
    std::cout << "Introduce tu contraseña para confirmar: ";
    std::cin >> contrasenya;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.eliminarCuenta(loggedUser, contrasenya);
        userLoggedIn = false;
        loggedUser.clear();
        std::cout << "Cuenta eliminada correctamente." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}