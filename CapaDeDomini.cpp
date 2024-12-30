#include "CapaDeDomini.hpp"
#include "PassarelaPelicula.hpp"
#include "CercadoraPelicula.hpp"
#include "PassarelaCapitol.hpp"
#include "CercadoraCapitol.hpp"
#include "ConnexioBD.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "CapaDeDomini.hpp"
#include "PassarelaUsuari.hpp"
#include "CercadoraUsuari.hpp"
#include "CercadoraPelicula.hpp"
#include "CercadoraCapitol.hpp"
#include <stdexcept>
#include <iostream>

#include "CapaDeDomini.hpp"
#include "PassarelaUsuari.hpp"
#include "CercadoraUsuari.hpp"
#include "PassarelaPelicula.hpp"
#include "PassarelaCapitol.hpp"
#include "CercadoraPelicula.hpp"
#include "CercadoraCapitol.hpp"
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

void CapaDeDomini::eliminarCuenta(const std::string& sobrenom, const std::string& contrasenya) {
    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(sobrenom);

    if (usuari.obteContrasenya() != contrasenya) {
        throw std::runtime_error("Error: Contraseña incorrecta.");
    }

    usuari.esborra();
}

void CapaDeDomini::procesarVisualizarPelicula() {
    std::string nombrePelicula;
    std::cout << "Introduce el nombre de la película para visualizar: ";
    std::cin.ignore(); // Para ignorar el salto de línea previo
    std::getline(std::cin, nombrePelicula);

    CercadoraPelicula cercadora;
    PassarelaPelicula pelicula = cercadora.cercaPerTitol(nombrePelicula);

    // Suponemos que existe una función para registrar visualización
    pelicula.registraVisualizacion(usuarioLogueado, nombrePelicula);
    std::cout << "Película '" << nombrePelicula << "' visualizada correctamente." << std::endl;
}

void CapaDeDomini::procesarVisualizarCapitulo() {
    std::string nombreSerie;
    int temporada, capitulo;
    std::cout << "Introduce el nombre de la serie: ";
    std::cin.ignore(); // Para ignorar el salto de línea previo
    std::getline(std::cin, nombreSerie);

    std::cout << "Introduce el número de temporada: ";
    std::cin >> temporada;

    std::cout << "Introduce el número de capítulo: ";
    std::cin >> capitulo;

    CercadoraCapitol cercadora;
    PassarelaCapitol capitol = cercadora.cercaPerTitolSerieCapitol(nombreSerie, temporada, capitulo);

    // Suponemos que existe una función para registrar visualización
    capitol.registraVisualizacion(usuarioLogueado, nombreSerie, temporada, capitulo);
    std::cout << "Capítulo '" << nombreSerie << " " << temporada << "x" << capitulo << "' visualizado correctamente." << std::endl;
}

void CapaDeDomini::procesarConsultarVisualizaciones() {
    std::string usuario;
    std::cout << "Introduce el nombre de usuario para consultar sus visualizaciones: ";
    std::cin.ignore(); // Para ignorar el salto de línea previo
    std::getline(std::cin, usuario);

    CercadoraUsuari cercador;
    PassarelaUsuari usuari = cercador.cercaPerSobrenom(usuario);

    // Aquí se deberían consultar todas las visualizaciones del usuario
    // Utilizamos las passarelas correspondientes para obtener las visualizaciones
    std::cout << "Consultando visualizaciones de " << usuario << "..." << std::endl;
}

void CapaDeDomini::consultarProximasEstrenas() {
    // Consulta las películas o series que están próximas a estrenarse
    std::cout << "Consultando próximas estrenos..." << std::endl;

    // Implementación de la consulta a la base de datos
    // Este es solo un placeholder, dependiendo de los datos en la base de datos
}

void CapaDeDomini::consultarPeliculasMasVistas() {
    std::cout << "Consultando películas más vistas..." << std::endl;

    // Aquí consultaríamos las películas más vistas a través de las Passarelas
    // Este es solo un placeholder, dependiendo de los datos en la base de datos
}
