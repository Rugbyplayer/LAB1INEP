#include "CapaDePresentacio.hpp"
#include <locale>
#include <iostream>

int main() {
    std::locale::global(std::locale("es_ES.UTF-8"));
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();

    int opcio = 0;
    while (true) {
        if (!presentacio.isUserLoggedIn()) {
            std::wcout << L"\nMenú Principal" << std::endl;
            std::wcout << L"1. Iniciar sesión" << std::endl;
            std::wcout << L"2. Registrarse" << std::endl;
            std::wcout << L"3. Consultas" << std::endl;
            std::wcout << L"4. Salir" << std::endl;
            std::wcout << L"Elige una opción: ";
            std::cin >> opcio;

            switch (opcio) {
            case 1:
                presentacio.procesarIniciarSesion();
                break;
            case 2:
                presentacio.procesarRegistroUsuario();
                break;
            case 3:
                presentacio.procesarConsultas();
                break;
            case 4:
                std::wcout << L"Saliendo de la aplicación. ¡Hasta pronto!" << std::endl;
                return 0;
            default:
                std::wcout << L"Opción no válida, vuelve a intentarlo." << std::endl;
            }
        }
        else {
            std::wcout << L"\nMenú de Usuario" << std::endl;
            std::wcout << L"1. Consultar mi perfil" << std::endl;
            std::wcout << L"2. Modificar mi perfil" << std::endl;
            std::wcout << L"3. Visualizaciones" << std::endl;
            std::wcout << L"4. Consultas" << std::endl;
            std::wcout << L"5. Cerrar sesión" << std::endl;
            std::wcout << L"6. Eliminar cuenta" << std::endl;
            std::wcout << L"7. Salir" << std::endl;
            std::wcout << L"Elige una opción: ";
            std::cin >> opcio;

            switch (opcio) {
            case 1:
                presentacio.procesarConsultaPerfil();
                break;
            case 2:
                presentacio.procesarModificacionPerfil();
                break;
            case 3:
                presentacio.procesarVisualizaciones();
                break;
            case 4:
                presentacio.procesarConsultas();
                break;
            case 5:
                presentacio.procesarCerrarSesion();
                break;
            case 6:
                presentacio.procesarEliminarCuenta();
                break;
            case 7:
                std::wcout << L"Saliendo de la aplicación. ¡Hasta pronto!" << std::endl;
                return 0;
            default:
                std::wcout << L"Opción no válida, vuelve a intentarlo." << std::endl;
            }
        }
    }

    return 0;
}

// Editat per Guillem-Sancho