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
    char confirm;
    std::cout << "¿Seguro que quieres cerrar sesión? (S/N): ";
    std::cin >> confirm;
    if (confirm == 'S' || confirm == 's') {
        userLoggedIn = false;
        loggedUser.clear();
        std::cout << "Sesión cerrada." << std::endl;
    }
    else {
        std::cout << "Operación cancelada." << std::endl;
    }
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
    std::cout << "Nuevo nombre (deja vacío para mantener): ";
    std::cin.ignore(); // Limpia buffer
    std::getline(std::cin, nuevoNom);
    std::cout << "Nuevo correo electrónico (deja vacío para mantener): ";
    std::getline(std::cin, nuevoCorreo);

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.modificarPerfil(loggedUser, nuevoNom, nuevoCorreo);
        std::cout << "Perfil modificado correctamente." << std::endl;
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

void CapaDePresentacio::procesarVisualizaciones() {
    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.consultarVisualizaciones(loggedUser);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarConsultas() {
    std::cout << "Consulta de Contenidos" << std::endl;
    std::cout << "1. Próximas estrenas" << std::endl;
    std::cout << "2. Últimas novedades" << std::endl;
    std::cout << "3. Películas más vistas" << std::endl;
    int opcion;
    std::cin >> opcion;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        switch (opcion) {
        case 1:
            domini.consultarProximasEstrenas(loggedUser);
            break;
        case 2:
            domini.consultarUltimasNovedades(loggedUser);
            break;
        case 3:
            domini.consultarMasVistas(loggedUser);
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}