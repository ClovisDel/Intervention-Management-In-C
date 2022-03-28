// **************************************************
// ** Fichier d'en-tête de la classe Intervention
// ** Un cours est composé : 
// **	-> id (int)
// **	-> duree (string)
// **	-> client (Client*)
// **	-> techniciens vector<Techniciens*>
// **	-> heure_debut (string)
// **	-> minute_debut (string)
// **	-> heure_fin (string)
// **	-> heure_fin (string)
// **
// ** La classe comporte les méthodes :
// **	-> Intervention(int, string, Client*, vector<Techniciens*>);
// **	-> Client* get_client();
// **	-> int get_id();
// **	-> vector<Techniciens*> get_techniciens();
// **	-> string get_duree()
// **	-> string get_heure_debut();
// **	-> string get_minute_debut();
// **	-> string get_heure_fin();
// **	-> string get_minute_fin();
// **	-> void set_heure_debut(string);
// **	-> void set_minute_debut(string);
// **	-> void set_heure_fin(string);
// **	-> void set_minute_fin(string);
// **	-> void afficher();
// **************************************************

#pragma once
#include "Techniciens.h"
#include "Client.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Intervention
{
private :
	int id;
	string duree;
	Client* client;
	vector<Techniciens*> techniciens;

	string heure_debut;
	string minute_debut;
	string heure_fin;
	string minute_fin;

public :
	Intervention(int, string, Client*, vector<Techniciens*>);

	Client* get_client();
	int get_id();
	vector<Techniciens*> get_techniciens();
	
	string get_duree();

	string get_heure_debut();
	string get_minute_debut();
	string get_heure_fin();
	string get_minute_fin();
	void set_heure_debut(string);
	void set_minute_debut(string);
	void set_heure_fin(string);
	void set_minute_fin(string);

	void afficher();
};

