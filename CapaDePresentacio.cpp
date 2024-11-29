#include "CapaDePresentacio.hpp"
#include "CapaDeDomini.hpp"

void CapaDePresentacio::procesarRegistreUsuari(ConnexioBD& connexio) {
    string sobrenom, nom_complet, correu;
    cout << "Introdueix el sobrenom: ";
    cin.ignore();
    getline(cin, sobrenom);
    cout << "Introdueix el nom complet: ";
    getline(cin, nom_complet);
    cout << "Introdueix el correu electronic: ";
    getline(cin, correu);
    CapaDeDomini& domini = CapaDeDomini::getInstance();
    if (!sobrenom.empty() && !nom_complet.empty() && !correu.empty()) {
        try {
            domini.registrarUsuari(sobrenom, nom, correu)
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
void CapaDePresentacio::procesarConsultaUsuari(ConnexioBD& connexio) {
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
void CapaDePresentacio::procesarModificaUsuari(ConnexioBD& connexio) {
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
void CapaDePresentacio::procesarEsborraUsuari(ConnexioBD& connexio) {
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