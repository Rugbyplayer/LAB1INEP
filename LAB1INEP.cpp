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
            std::cout << "3. Salir" << std::endl;
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
                std::cout << "Saliendo de la aplicación. ¡Hasta pronto!" << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            }
        }
        else {
            std::cout << "\n--- Menú Usuario ---" << std::endl;
            std::cout << "1. Consultar perfil" << std::endl;
            std::cout << "2. Modificar perfil" << std::endl;
            std::cout << "3. Cambiar contraseña" << std::endl;
            std::cout << "4. Eliminar cuenta" << std::endl;
            std::cout << "5. Cerrar sesión" << std::endl;
            std::cout << "6. Salir" << std::endl;
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
                presentacio.procesarCambiarContrasenya();
                break;
            case 4:
                presentacio.procesarEliminarCuenta();
                break;
            case 5:
                presentacio.procesarCerrarSesion();
                break;
            case 6:
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