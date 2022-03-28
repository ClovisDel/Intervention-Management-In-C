// **************************************************
// ** Fichier d'en-tête de la classe Gestion 
// ** Un cours est composé : 
// **	-> list_tech (vector<Techniciens*>)
// **	-> list_clients (vector<Clients*>)
// **	-> distancier (vector<vector<int>>)
// **	-> list_inter (vector<Intervention*>)
// **
// ** La classe comporte les méthodes :
// **	-> Gestion();
// **	->void add_client(Client*);
// **	->void del_client(string);
// **	->void add_techni(Techniciens*);
// **	->void del_techni(string);
// **	->void add_distancier(vector<int>);
// **	->int get_valeur_distancier(int, int);
// **	->void modif_distancier();
// **	->void afficher_client();
// **	->void afficher_techniciens();
// **	->void afficher_distancier();
// **	->void afficher_intervention();
// **	->void calcule_tps_intervention(int, string, string);
// **	->void calcule_tps_deplacement(string, string, string);
// **	->void add_intervention(string, string, vector<int>);
// **	-> void archiver_inter()
// **************************************************


#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Techniciens.h"
#include "Client.h"
#include "Intervention.h"

using namespace std;

class Gestion
{
private : 
	vector<Techniciens*> list_techs;
	vector<Client*> list_clients;
	vector<vector<int>> distancier;
	vector<Intervention*> list_inter;


public :
	Gestion();

	void add_client(Client*);
	void del_client(string);

	void add_techni(Techniciens*);
	void del_techni(string);
	
	void add_distancier(vector<int>);
	int get_valeur_distancier(int, int);
	void modif_distancier();

	void afficher_client();
	void afficher_techniciens();
	void afficher_distancier();
	void afficher_intervention();

	void calcule_tps_intervention(int, string, string);

	void calcule_tps_deplacement(string, string, string);

	void add_intervention(string, string, vector<int>);

	void archiver_inter();
};

