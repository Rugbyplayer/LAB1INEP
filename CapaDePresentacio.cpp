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
        std::cout << "No fa falta implementar" << std::endl;
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

void CapaDePresentacio::procesarVisualizarPelicula() {
    std::string nombrePelicula;
    std::cout << "Introduce el nombre de la película para visualizar: ";
    std::cin.ignore(); // Para ignorar el salto de línea previo
    std::getline(std::cin, nombrePelicula);

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.visualizarPelicula(nombrePelicula); // Llamamos a la capa de dominio
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarVisualizarCapitulo() {
    std::cout << "No fa falta implementar" << std::endl;
}

void CapaDePresentacio::procesarConsultarVisualizaciones() {
    std::string usuario;
    std::cout << "Introduce el nombre de usuario para consultar sus visualizaciones: ";
    std::cin.ignore(); // Para ignorar el salto de línea previo
    std::getline(std::cin, usuario);

    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.consultarVisualizaciones(usuario); // Llamamos a la capa de dominio
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarProximasEstrenos() {
    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.consultarProximasEstrenas(); // Llamamos a la capa de dominio
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void CapaDePresentacio::procesarUltimasNovedades() {
    std::cout << "No fa falta implementar" << std::endl;
}

void CapaDePresentacio::procesarPeliculasMasVistas() {
    try {
        CapaDeDomini& domini = CapaDeDomini::getInstance();
        domini.consultarPeliculasMasVistas(); // Llamamos a la capa de dominio
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
