#include "CapaDePresentacio.hpp"

void CapaDePresentacio::procesarIniciarSesion() {
    std::string sobrenom, contrasenya;
    std::cout << "Iniciar Sesio" << std::endl;
    std::cout << "Sobrenom: ";
    std::cin >> sobrenom;
    std::cout << "Contrasenya: ";
    std::cin >> contrasenya;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.iniciarSesion(sobrenom, contrasenya);
        loggedUser = sobrenom;
        userLoggedIn = true;
        std::cout << "Sesio iniciada correctament." << std::endl;
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
        std::cout << "Sesio tencada correctament." << std::endl;
    }
    else if(confirm =='N' || confirm== 'n'){
        std::cout << "Operacio cancelada. Tornant al menú anterior." << std::endl;
    }
}

void CapaDePresentacio::procesarRegistroUsuario() {
    std::string sobrenom, nom, contrasenya, correu;
    std::cout << "Registrar Usuari" << std::endl;
    std::cout << "Sobrenom: ";
    std::cin >> sobrenom;
    std::cout << "Nom: ";
    std::cin >> nom;
    std::cout << "Contrasenya: ";
    std::cin >> contrasenya;
    std::cout << "Correu Electrónic: ";
    std::cin >> correu;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.registrarUsuario(nom, sobrenom, contrasenya, correu);
        std::cout << "Usuari registrat correctament." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarConsultaPerfil() {
    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        auto perfil = domini.consultarPerfil(loggedUser);
        std::cout << "Perfil del Usuari" << std::endl;
        std::cout << "Nom: " << perfil.nom << std::endl;
        std::cout << "Sobrenom: " << perfil.sobrenom << std::endl;
        std::cout << "Correu: " << perfil.correu << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarModificacionPerfil() {
    std::cout << "La modificacio de l'uauari no esta implementada encara." << std::endl;
}

void CapaDePresentacio::procesarEliminarCuenta() {
    std::string contrasenya;
    std::cout << "Eliminar Compte" << std::endl;
    std::cout << "Introdueix la teva contrasenya per confirmar: ";
    std::cin >> contrasenya;

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.eliminarCuenta(loggedUser, contrasenya);
        userLoggedIn = false;
        loggedUser.clear();
        std::cout << "Cuenta eliminada correctament." << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}