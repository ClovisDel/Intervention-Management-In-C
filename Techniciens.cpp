#include "Techniciens.h"

// Constructeur de l'objet Techniciens
Techniciens::Techniciens(string nom, string num_tel, vector<int> competences)
{
	this->nom = nom;
	this->num_tel = num_tel;
	this->competences = competences;
}

// Méthode qui renvoie le nom du techniciens
string Techniciens::get_nom()
{
	return nom;
}

// Méthode qui renvoie la liste des compétences du techniciens
vector<int> Techniciens::get_competences()
{
	return competences;
}

// Méthode qui renvoie le nombre de compétences du techniciens
int Techniciens::get_competences_size()
{
	return competences.size();
}

// Méthode qui affiche les informations d'un techniciens
void Techniciens::afficher_techniciens()
{
	cout << nom << " / " << num_tel;
	for (int items : competences)
		cout << " / " << items;
	
}
