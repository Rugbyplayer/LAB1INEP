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

    void iniciarSesion(const std::string& sobrenom, const std::string& contrasenya);
    void cerrarSesion();


    void registrarUsuario(const std::string& nom, const std::string& sobrenom,
        const std::string& contrasenya, const std::string& correo);
    void consultarPerfil(const std::string& sobrenom);
    void eliminarCuenta(const std::string& sobrenom, const std::string& contrasenya);

    void procesarVisualizarPelicula();
    void procesarVisualizarCapitulo();
    void procesarConsultarVisualizaciones();

    void consultarProximasEstrenas();
    void consultarPeliculasMasVistas();
};

#endif