// LAB1INEP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
void procesarRegistreUsuari() {
    string sobrenom, nom_complet;
    cout << "Introdueix el sobrenom: ";
    cin >> sobrenom;
    cout << "Introdueix el nom complet: ";
    cin.ignore(); // Per evitar problemes amb el buffer d'entrada
    getline(cin, nom_complet);

    if (!sobrenom.empty() && !nom_complet.empty()) {
        cout << "El registre de l'usuari " << nom_complet << " (" << sobrenom << ") s’ha processat correctament" << endl;
    }
    else {
        cout << "Error al registrar usuari" << endl;
    }
}

void procesarConsultaUsuari() {
    cout << "Consulta usuari operacio processada" << endl;
}

void procesarModificaUsuari() {
    cout << "Modificacio usuari operacio processada" << endl;
}

void procesarEsborraUsuari() {
    cout << "Esborrat usuari operacio processada" << endl;
}

// Funcions de processament de continguts
void procesarGestioPelicules() {
    cout << "Gestio pel·licules operacio processada" << endl;
}

void procesarGestioSeries() {
    cout << "Gestio series operacio processada" << endl;
}

// Funcions de processament de consultes
void procesarConsultaQualificacioEdat() {
    cout << "Consulta per qualificacio d’edat operacio processada" << endl;
}

void procesarUltimesNovetats() {
    cout << "Ultimes novetats operacio processada" << endl;
}

void procesarProximesEstrenes() {
    cout << "Proximes estrenes operacio processada" << endl;
}
void Consulta() {
    int opcio = 0;
    while (opcio != 4) {
        cout << "\nConsultes" << endl;
        cout << "1. Consulta per qualificacio d’edat" << endl;
        cout << "2. Ultimes novetats" << endl;
        cout << "3. Proximes estrenes" << endl;
        cout << "4. Tornar" << endl;
        cout << "Tria una opció: ";
        cin >> opcio;

        switch (opcio) {
        case 1:
            procesarConsultaQualificacioEdat();
            break;
        case 2:
            procesarUltimesNovetats();
            break;
        case 3:
            procesarProximesEstrenes();
            break;
        case 4:
            // Tornar al menú principal
            break;
        default:
            cout << "Opcio no valida, torna-ho a intentar." << endl;
        }
    }
}

void GestioContinguts() {
    int opcio = 0;
    while (opcio != 3) {
        cout << "\nGestio Continguts" << endl;
        cout << "1. Gestio pel·lícules" << endl;
        cout << "2. Gestio series" << endl;
        cout << "3. Tornar" << endl;
        cout << "Tria una opció: ";
        cin >> opcio;

        switch (opcio) {
        case 1:
            procesarGestioPelicules();
            break;
        case 2:
            procesarGestioSeries();
            break;
        case 3:
            // Tornar al menú principal
            break;
        default:
            cout << "Opcio no valida, torna-ho a intentar." << endl;
        }
    }
}


void GestioUsuari() {
    int num = 0;
    while (num != 5) {
        cout << "\nGestio Usuaris" << endl;
        cout << "1. Registre usuari" << endl;
        cout << "2. Consulta usuari" << endl;
        cout << "3. Modifica usuari" << endl;
        cout << "4. Esborra usuari" << endl;
        cout << "5. Tornar" << endl;
        cout << "Escull una numero: ";
        cin >> num;
        switch (num) {
        case 1:
            procesarRegistreUsuari();
            break;
        case 2:
            procesarConsultaUsuari();
            break;
        case 3:
            procesarModificaUsuari();
            break;
        case 4:
            procesarEsborraUsuari();
            break;
        case 5:
            // Tornar al menú principal
            break;
        default:
            cout << "Opcio no valida, torna-ho a intentar." << endl;
        }
    }
}


void menuPrincipal() {
    int opcio = 0;
    while (opcio != 4) {
        cout << "\nMenu Principal" << endl;
        cout << "1. Gestio usuaris" << endl;
        cout << "2. Gestio continguts" << endl;
        cout << "3. Consultes" << endl;
        cout << "4. Sortir" << endl;
        cout << "Escull una opcio: ";
        cin >> opcio;

        switch (opcio) {
        case 1:
            GestioUsuari();
            break;
        case 2:
            GestioContinguts();
            break;
        case 3:
            Consulta();
            break;
        case 4:
            cout << "Sortint de l'aplicacio. Fins aviat!" << endl;
            break;
        default:
            cout << "No a elegit una opcio viable." << endl;




        }
    }


}
int main()
{
    menuPrincipal();
    return 0;

}