#include "CapaDePresentacio.hpp"
#include <locale>
#include <iostream>

void MenuUsuari(){
    std::locale::global(std::locale("es_ES.UTF-8"));
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int opcion = 0;
            std::cout << "\n--- Menú Usuario ---" << std::endl;
            std::cout << "1. Consultar perfil" << std::endl;
            std::cout << "2. Modificar perfil" << std::endl;
            std::cout << "3. Esborra usuari" << std::endl;
            std::cout << "4. Tornar" << std::endl;
            std::cout << "Escriu una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                presentacio.procesarConsultaPerfil();
                break;
            case 2:
                presentacio.procesarModificacionPerfil();
                break;
            case 3:
                presentacio.procesarEliminarCuenta();
                break;
            case 4:
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
}

void MenuVisualitzacio(){
    std::locale::global(std::locale("es_ES.UTF-8"));
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int opcion = 0;
            std::cout << "\n--- Menú Usuario ---" << std::endl;
            std::cout << "1. Visualitzar pel·lícula" << std::endl;
            std::cout << "2. Visualitzar capítol" << std::endl;
            std::cout << "3. Consultar visualitzacions" << std::endl;
            std::cout << "4. Tornar" << std::endl;
            std::cout << "Escriu una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                presentacio.procesarVisualizarPelicula();
                break;
            case 2:
                presentacio.procesarVisualizarCapitulo();
                break;
            case 3:
                presentacio.procesarConsultarVisualizaciones();
                break;
            case 4:
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
}


void MenuConsultes(){
    std::locale::global(std::locale("es_ES.UTF-8"));
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int opcion = 0;
            std::cout << "\n--- Menú Usuario ---" << std::endl;
            std::cout << "1. Properes estrenes" << std::endl;
            std::cout << "2. Últimes novetats" << std::endl;
            std::cout << "3. Pel·lícules més vistes" << std::endl;
            std::cout << "4. Tornar" << std::endl;
            std::cout << "Escriu una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                presentacio.procesarProximasEstrenos();
                break;
            case 2:
                presentacio.procesarUltimasNovedades();
                break;
            case 3:
                presentacio.procesarPeliculasMasVistas();
                break;
            case 4:
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
}



int main() {
    std::locale::global(std::locale("es_ES.UTF-8"));
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    int opcion = 0;
    while (true) {
        if (!presentacio.isUserLoggedIn()) {
            std::cout << "\n--- Menú Principal ---" << std::endl;
            std::cout << "1. Iniciar sesió" << std::endl;
            std::cout << "2. Registrarse" << std::endl;
            std::cout << "3. Sortir" << std::endl;
            std::cout << "Escriu una opció: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                presentacio.procesarIniciarSesion();
                break;
            case 2:
                presentacio.procesarRegistroUsuario();
                break;
            case 3:
                std::cout << "Sortint de la aplicació. ¡Fins la propera!" << std::endl;
                return 0;
            default:
                std::cout << "Opció no válida. Intenta-ho de nou." << std::endl;
            }
        }
        else {
            std::cout << "\n--- Menú Principal ---" << std::endl;
            std::cout << "1. Gestió usuaris" << std::endl;
            std::cout << "2. Visualitzar" << std::endl;
            std::cout << "3. Consultes" << std::endl;
            std::cout << "4. Tancar sessió" << std::endl;
            std::cout << "5. Sortir" << std::endl;
            std::cout << "Escriu una opció: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                MenuUsuari();
                break;
            case 2:
                MenuVisualitzacio();
                break;
            case 3:
                MenuConsultes();
                break;
            case 4:
                std::cout << "Sessió tencada correctament!" << std::endl;
                return 0;
            case 5:
                std::cout << "Sortint de la aplicació. ¡Fins la propera!" << std::endl;
                return 0;
            default:
                std::cout << "Opció no válida. Intenta-ho de nou." << std::endl;
            }
        }
    }

    return 0;
}