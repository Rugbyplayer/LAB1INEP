#include "CapaDePresentacio.hpp"
#include <locale>
#include <iostream>

int main() {
    std::locale::global(std::locale("es_ES.UTF-8"));
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    int opcion = 0;
    while (true) {
        if (!presentacio.isUserLoggedIn()) {
            std::cout << "\n--- Menú Principal ---" << std::endl;
            std::cout << "1. Iniciar sesión" << std::endl;
            std::cout << "2. Registrarse" << std::endl;
            std::cout << "4. Consultes" << std::endl;
            std::cout << "3. Sortir" << std::endl;
            std::cout << "Seleccione una opción: ";
            std::cin >> opcion;

            switch (opcion) {
            case 1:
                presentacio.procesarIniciarSesion();
                break;
            case 2:
                presentacio.procesarRegistroUsuario();

                break;
            case 3:

                break;
            case 4:
                std::cout << "Saliendo de la aplicación. ¡Hasta pronto!" << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
        }
        else {
            std::cout << "\n--- Menú Principal ---" << std::endl;
            std::cout << "1. Gestió usuaris" << std::endl;
            std::cout << "2. Visualizar" << std::endl;
            std::cout << "3. Consultes" << std::endl;
            std::cout << "4. Tancar sessió" << std::endl;
            std::cout << "5. Sortir" << std::endl;
            std::cout << "Seleccione una opción: ";
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
                std::cout << "Saliendo de la aplicación. ¡Hasta pronto!" << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
        }
    }

    return 0;
}
// Editat per Guillem-Sancho