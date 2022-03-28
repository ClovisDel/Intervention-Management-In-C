
#include "Intervention.h"

// Constructeur d'un objet Intervention()
Intervention::Intervention(int id, string duree, Client* client, vector<Techniciens*> techniciens)
{
	this->id = id;
	this->duree = duree;
	this->client = client;
	this->techniciens = techniciens;

	heure_debut = "XXhXX";
	minute_debut = "XXhXX";
	heure_fin = "XXhXX";
	minute_fin = "XXhXX";
}

// Méthode qui renvoie le client d'une intervention
Client* Intervention::get_client()
{
	return client;
}

// Méthode qui renvoie l'id d'une intervention
int Intervention::get_id()
{
	return id;
}

// Méthode qui renvoie l'ensemble des techniciens d'une intervention
vector<Techniciens*> Intervention::get_techniciens()
{
	return techniciens;
}

string Intervention::get_duree()
{
	return duree;
}

// Méthode qui renvoie l'heure de début d'une intervention
string Intervention::get_heure_debut()
{
	return heure_debut;
}

// Méthode qui renvoie la minute de début d'une intervention
string Intervention::get_minute_debut()
{
	return minute_debut;
}


// Méthode qui renvoie l'heure de fin d'une intervention
string Intervention::get_heure_fin()
{
	return heure_fin;
}


// Méthode qui renvoie la minute de fin d'une intervention
string Intervention::get_minute_fin()
{
	return minute_fin;
}


// Méthode qui modifie l'heure de début d'une intervention
void Intervention::set_heure_debut(string data)
{
	heure_debut = data;
}

// Méthode qui modifie la minute de début d'une intervention
void Intervention::set_minute_debut(string data)
{
	minute_debut = data;
}

// Méthode qui modifie l'heure de fin d'une intervention
void Intervention::set_heure_fin(string data)
{
	heure_fin = data;
}

// Méthode qui modifie la minute de fin d'une intervention
void Intervention::set_minute_fin(string data)
{
	minute_fin = data;
}

// Méthode qui affiche les informations d'une intervention en appelant les fonctions de Client et Techniciens
void Intervention::afficher()
{
	cout << id << " | " << duree << " | " << client->get_nom();
	for (Techniciens* tech : techniciens) {
		cout << " | ";
		tech->afficher_techniciens();
	}
}
