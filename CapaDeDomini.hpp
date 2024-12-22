#ifndef CAPADEDOMINI_HPP
#define CAPADEDOMINI_HPP

#include <string>
#include "DTOUsuari.hpp"

class CapaDeDomini {
private:
    std::string usuarioLogueado;
    CapaDeDomini() {}

public:
    static CapaDeDomini& getInstance() {
        static CapaDeDomini instance;
        return instance;
    }

    // Gestión de sesiones
    void iniciarSesion(const std::string& sobrenom, const std::string& contrasenya);
    void cerrarSesion();

    // Gestión de usuarios
    void registrarUsuario(const std::string& nom, const std::string& sobrenom,
        const std::string& contrasenya, const std::string& correo);
    DTOUsuari consultarPerfil(const std::string& sobrenom);
    void modificarPerfil(const std::string& sobrenom, const std::string& nuevoNom,
        const std::string& nuevoCorreo);
    void eliminarCuenta(const std::string& sobrenom, const std::string& contrasenya);

    // Consultas
    void consultarProximasEstrenas(const std::string& sobrenom);
    void consultarUltimasNovedades(const std::string& sobrenom);
    void consultarMasVistas(const std::string& sobrenom);

    // Visualizaciones
    void consultarVisualizaciones(const std::string& sobrenom);
};

#endif