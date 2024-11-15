#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include "ConnexioBD.h"
#include <iostream>
#include <string>
using namespace std;
void procesarRegistreUsuari(ConnexioBD& connexio) {
    string sobrenom, nom_complet, correu;
    cout << "Introdueix el sobrenom: ";
    cin.ignore();
    getline(cin, sobrenom);
    cout << "Introdueix el nom complet: ";
    getline(cin, nom_complet);
    cout << "Introdueix el correu electronic: ";
    getline(cin, correu);

    if (!sobrenom.empty() && !nom_complet.empty() && !correu.empty()) {
        try {
            string sql = "INSERT INTO Usuari (sobrenom, nom, correu) VALUES ('" + sobrenom + "', '" + nom_complet + "', '" + correu + "')";
            connexio.executeCommand(sql);
            cout << "Usuari registrat correctament!" << endl;
        }
        catch (sql::SQLException& e) {
            cerr << "SQL Error: " << e.what() << endl;
        }
    }
    else {
        cout << "Error al registrar usuari: Tots els camps són obligatoris." << endl;
    }
}

// Consulta un usuario por sobrenombre
void procesarConsultaUsuari(ConnexioBD& connexio) {
    string sobrenom;
    cout << "Introdueix sobrenom: ";
    cin >> sobrenom;

    if (!sobrenom.empty()) {
        try {
            string sql = "SELECT * FROM Usuari WHERE sobrenom = '" + sobrenom + "'";
            sql::ResultSet* res = connexio.executeQuery(sql);

            if (res->next()) {
                cout << "Sobrenom: " << res->getString("sobrenom") << endl;
                cout << "Nom: " << res->getString("nom") << endl;
                cout << "Correu: " << res->getString("correu") << endl;
            }
            else {
                cout << "Usuari no trobat." << endl;
            }
            delete res;
        }
        catch (sql::SQLException& e) {
            cerr << "SQL Error: " << e.what() << endl;
        }
    }
    else {
        cout << "Error: Sobrenom no pot estar buit." << endl;
    }
}

// Modifica un usuario existente
void procesarModificaUsuari(ConnexioBD& connexio) {
    string sobrenom, nouNom, nouCorreu;

    cout << "Introdueix el sobrenom de l'usuari a modificar: ";
    cin >> sobrenom;
    cin.ignore();
    cout << "Introdueix el nou nom complet: ";
    getline(cin, nouNom);
    cout << "Introdueix el nou correu electronic: ";
    getline(cin, nouCorreu);

    if (!sobrenom.empty() && !nouNom.empty() && !nouCorreu.empty()) {
        try {
            string sql = "UPDATE Usuari SET nom = '" + nouNom + "', correu = '" + nouCorreu + "' WHERE sobrenom = '" + sobrenom + "'";
            connexio.executeCommand(sql);
            cout << "Usuari modificat correctament!" << endl;
        }
        catch (sql::SQLException& e) {
            cerr << "SQL Error: " << e.what() << endl;
        }
    }
    else {
        cout << "Error: Tots els camps són obligatoris." << endl;
    }
}

// Elimina un usuario
void procesarEsborraUsuari(ConnexioBD& connexio) {
    string sobrenom;

    cout << "Introdueix el sobrenom de l'usuari a esborrar: ";
    cin >> sobrenom;

    if (!sobrenom.empty()) {
        try {
            string sql = "DELETE FROM Usuari WHERE sobrenom = '" + sobrenom + "'";
            connexio.executeCommand(sql);
            cout << "Usuari esborrat correctament!" << endl;
        }
        catch (sql::SQLException& e) {
            cerr << "SQL Error: " << e.what() << endl;
        }
    }
    else {
        cout << "Error: El sobrenom no pot estar buit." << endl;
    }
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


void GestioUsuari(ConnexioBD& connexio) {
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
            procesarRegistreUsuari(connexio);
            break;
        case 2:
            procesarConsultaUsuari(connexio);
            break;
        case 3:
            procesarModificaUsuari(connexio);
            break;
        case 4:
            procesarEsborraUsuari(connexio);
            break;
        case 5:
            break;
        default:
            cout << "Opcio no valida, torna-ho a intentar." << endl;
           
        }
    }
}


void menuPrincipal() {
    ConnexioBD connexio("tcp://ubiwan.epsevg.upc.edu:3306", "inep27", "ohZol1Wie9chah", "inep27");

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
            GestioUsuari(connexio);
            break;
        case 2:
            cout << "Gestio continguts encara no implementada." << endl;
            break;
        case 3:
            cout << "Consultes encara no implementades." << endl;
            break;
        case 4:
            cout << "Sortint de l'aplicacio. Fins aviat!" << endl;
            break;
        default:
            cout << "No a elegit una opcio viable." << endl;

        }
    }
}

int main() {
    menuPrincipal();
    return 0;
}

// Editat per Guillem-Sancho