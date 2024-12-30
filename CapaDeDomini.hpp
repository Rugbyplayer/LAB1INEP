#ifndef CAPADEDOMINI_HPP
#define CAPADEDOMINI_HPP

#include <string>


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
   void consultarPerfil(const std::string& sobrenom);
    void modificarPerfil(const std::string& sobrenom, const std::string& nuevoNom,
        const std::string& nuevoCorreo);
    void eliminarCuenta(const std::string& sobrenom, const std::string& contrasenya);

    // Consultas adicionales (películas, estrenas, etc.)
    void consultarProximasEstrenas();
    void consultarUltimasNovedades();
    void consultarPeliculasMasVistas();
};

#endif