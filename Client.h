// **************************************************
// ** Fichier d'en-tête de la classe Client 
// ** Un cours est composé : 
// **	-> nom (string)
// **	-> num_tel (string)
// **	-> adresse (string)
// **
// ** La classe comporte les méthodes :
// **	-> Client(string, string, string);
// **	-> string get_nom();
// **	-> void set_nom(string);
// **	-> void afficher_client();
// **************************************************


#pragma once

#include <string>
#include <iostream>

using namespace std;

class Client
{
private : 
	string nom;
	string num_tel;
	string adresse;

public :
	Client(string, string, string);

	string get_nom();
	void set_nom(string);

	void afficher_client();

};

