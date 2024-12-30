#include "CapaDeDomini.hpp"
#include "PassarelaUsuari.hpp"
#include "CercadoraUsuari.hpp"
#include <stdexcept>
#include <iostream>

void CapaDeDomini::iniciarSesion(const std::string& sobrenom, const std::string& contrasenya) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    if (usuari.obteContrasenya() != contrasenya) {
        throw std::runtime_error("Error: Contraseña incorrecta.");
    }
    usuarioLogueado = sobrenom;
    std::cout << "Sesión iniciada correctamente para el usuario: " << sobrenom << std::endl;
}

void CapaDeDomini::registrarUsuario(const std::string& nom, const std::string& sobrenom,
    const std::string& contrasenya, const std::string& correo, const std::string& subscripcion) {
    
    // Crear un objeto PassarelaUsuari y registrar el usuario con subscripción
    PassarelaUsuari nuevoUsuario(sobrenom, nom, correo, contrasenya, subscripcion);
    nuevoUsuario.insereix();  // Inserta el nuevo usuario en la base de datos

    std::cout << "Usuario registrado correctamente: " << sobrenom << std::endl;
}

DTOUsuari CapaDeDomini::consultarPerfil(const std::string& sobrenom) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    DTOUsuari dto;
    dto.nom = usuari.obteNom();
    dto.sobrenom = usuari.obteSobrenom();
    dto.correu = usuari.obteCorreuElectronic();
    dto.subscripcio = usuari.obteSubscripcio();  // Nuevo campo subscripción

    return dto;
}

void CapaDeDomini::eliminarCuenta(const std::string& sobrenom, const std::string& contrasenya) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    if (usuari.obteContrasenya() != contrasenya) {
        throw std::runtime_error("Error: Contraseña incorrecta.");
    }

    usuari.esborra();  // Elimina la cuenta
    std::cout << "Cuenta de " << sobrenom << " eliminada correctamente." << std::endl;
}


void CapaDeDomini::consultarProximasEstrenas() {
    std::cout << "Consulta de pr�ximas estrenas no implementada a�n." << std::endl;
}

void CapaDeDomini::consultarUltimasNovedades() {
    std::cout << "Consulta de �ltimas novedades no implementada a�n." << std::endl;
}

void CapaDeDomini::consultarPeliculasMasVistas() {
    std::cout << "Consulta de pel�culas m�s vistas no implementada a�n." << std::endl;
}