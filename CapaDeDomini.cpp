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
}

void CapaDeDomini::cerrarSesion() {
    usuarioLogueado.clear();
}

void CapaDeDomini::registrarUsuario(const std::string& nom, const std::string& sobrenom,
    const std::string& contrasenya, const std::string& correo) {
    PassarelaUsuari usuari(sobrenom, nom, correo, contrasenya);
    usuari.insereix();
}

DTOUsuari CapaDeDomini::consultarPerfil(const std::string& sobrenom) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    DTOUsuari dto;
    dto.nom = usuari.obteNom();
    dto.sobrenom = usuari.obteSobrenom();
    dto.correu = usuari.obteCorreuElectronic();

    return dto;
}

void CapaDeDomini::modificarPerfil(const std::string& sobrenom, const std::string& nuevoNom,
    const std::string& nuevoCorreo) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    if (!nuevoNom.empty()) {
        usuari.posaNom(nuevoNom);
    }
    if (!nuevoCorreo.empty()) {
        usuari.posaCorreuElectronic(nuevoCorreo);
    }

    usuari.modifica();
}

void CapaDeDomini::cambiarContrasenya(const std::string& sobrenom, const std::string& contrasenyaActual,
    const std::string& nuevaContrasenya) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    if (usuari.obteContrasenya() != contrasenyaActual) {
        throw std::runtime_error("Error: Contraseña actual incorrecta.");
    }

    usuari.cambiaContrasenya(nuevaContrasenya);
}

void CapaDeDomini::eliminarCuenta(const std::string& sobrenom, const std::string& contrasenya) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    if (usuari.obteContrasenya() != contrasenya) {
        throw std::runtime_error("Error: Contraseña incorrecta.");
    }

    usuari.esborra();
}

void CapaDeDomini::consultarProximasEstrenas() {
          
}

void CapaDeDomini::consultarUltimasNovedades() {
    std::cout << "Consulta de últimas novedades no implementada aún." << std::endl;
}

void CapaDeDomini::consultarPeliculasMasVistas() {
    std::cout << "Consulta de películas más vistas no implementada aún." << std::endl;
}