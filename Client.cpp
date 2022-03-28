
#include "Client.h"

// Constructeur de l'objet Client
Client::Client(string nom, string num_tel, string adresse) {
    this->nom = nom;
    this->num_tel = num_tel;
    this->adresse = adresse;
}

// M�thode qui renvoie le nom du client
string Client::get_nom()
{
    return nom;
}

// M�thode qui modifie le nom du client � un nouveau (dans le cas o� il est supprim�)
void Client::set_nom(string new_nom)
{
    nom = new_nom;
}

// M�thode qui affiche les informations d'un client
void Client::afficher_client()
{
    cout << nom << " / " << num_tel << " / " << adresse << endl;
}
