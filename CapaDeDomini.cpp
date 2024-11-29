#include "CapaDeDomini.hpp"

void CapaDeDomini::registrarUsuari(string sobrenom, string nom, string correu){
    string sql = "INSERT INTO Usuari (sobrenom, nom, correu) VALUES ('" + sobrenom + "', '" + nom_complet + "', '" + correu + "')";
    connexio.executeCommand(sql);
}