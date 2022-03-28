
#include "Client.h"

// Constructeur de l'objet Client
Client::Client(string nom, string num_tel, string adresse) {
    this->nom = nom;
    this->num_tel = num_tel;
    this->adresse = adresse;
}

// Méthode qui renvoie le nom du client
string Client::get_nom()
{
    return nom;
}

// Méthode qui modifie le nom du client à un nouveau (dans le cas où il est supprimé)
void Client::set_nom(string new_nom)
{
    nom = new_nom;
}

// Méthode qui affiche les informations d'un client
void Client::afficher_client()
{
    cout << nom << " / " << num_tel << " / " << adresse << endl;
}
