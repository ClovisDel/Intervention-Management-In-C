// **************************************************
// ** Fichier d'en-t�te de la classe Technicien
// ** Un cours est compos� : 
// **	-> nom (string)
// **	-> num_tel (string)
// **	-> competences (vector<int>)
// **
// ** La classe comporte les m�thodes :
// **	-> Techniciens(string, string, vector<int>);
// **	-> string get_nom();
// **	-> vector<int> get_competences();
// **	-> int get_competences_size();
// **	-> void afficher_techniciens();
// **************************************************


#pragma once

#include <string>
#include <iostream>
#include <vector>


using namespace std;

class Techniciens
{
private :
	string nom;
	string num_tel;
	vector<int> competences;

public :
	Techniciens(string, string, vector<int>);

	string get_nom();
	vector<int> get_competences();
	int get_competences_size();

	void afficher_techniciens();
};

