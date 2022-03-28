#include "Gestion.h"
#include "Client.h"
#include "Techniciens.h"
#include "Intervention.h"


#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

// M�thode qui va cr�er un nombre al�atoire pour g�n�r�rer les identifiants d'une intervention
int Rand(int a, int b)
{
	int nRand;
	nRand = a + (int)((float)rand() * (b - a + 1) / (RAND_MAX - 1));
	return nRand;
}

// Constructeur vide
Gestion::Gestion()
{

}

// Ajout d'un client dans le vector list_clients
void Gestion::add_client(Client* c)
{
	list_clients.push_back(c);
	cout << "Client ajout� avec succ�s !! " << endl;
}

// Suppression d'un client en fonction de son nom
// On g�re l'erreur si le nom n'existe pas 
// On met �galement le distancier � jour -> on met des 0 si le client n'est plus dans la liste des clients
// On modifie son nom � "null"
void Gestion::del_client(string nom_client)
{
	int nb_c = 0;

	for (int i = 0; i < list_clients.size(); i++) {
		nb_c += 1;
		
		if (list_clients[i]->get_nom() == nom_client) {
			//list_clients[i] = nullptr;
			//list_clients.erase(list_clients.begin() + i);
			list_clients[i]->set_nom("Null");
			nb_c = 0;
			cout << "Client : " << nom_client << " supprim� !! " << endl;
		
			for (int j = 0; j < distancier.size(); j++) {
				distancier[j][i + 1] = 0;
				if (j == i) {
					for (int k = 0; k < distancier[j].size(); k++) {
						distancier[j][k] = 0;
						
					}
				}
			}
		}
	}
	if (nb_c == list_clients.size()) {
		cout << "Pas de client avec ce nom !!" << endl;
	}
}

// Ajout d'un techniciens au vector list_techs
void Gestion::add_techni(Techniciens* t)
{
	list_techs.push_back(t);
	cout << "Techniciens ajout� avec succ�s !! " << endl;
}

// Suppression d'un technicien en fonction de son nom
// On g�re l'erreur si le nom n'est pas connu
void Gestion::del_techni(string nom_techs)
{
	int nb_t = 0;

	for (int i = 0; i < list_techs.size(); i++) {
		nb_t += 1;

		if (list_techs[i]->get_nom() == nom_techs) {
			list_techs.erase(list_techs.begin() + i);
			nb_t = 0;
			cout << "Techniciens : " << nom_techs << " supprim�" << endl;
		}
	}
	if (nb_t == list_techs.size())
		cout << "Pas de techniciens avec ce nom" << endl;
}

// M�thode qui ajoute une ligne � la matrice distancier
void Gestion::add_distancier(vector<int> d)
{
	distancier.push_back(d);
}

// M�thode qui renvoie la distance entre deux clients
int Gestion::get_valeur_distancier(int a, int b)
{
	return distancier[a][b-1];
}


// M�thode qui modifie, quand on va rajouter un client, va :
//		-> rajouter la ligne en demandant les valeurs � rajouter
//		-> rajouter la colonne avec les bonnes valeurs
void Gestion::modif_distancier()
{
	vector<int> ligne_to_add;
	cout << "Donner la distance entre le client et l'entreprise ";
	int distance_ent;
	cin >> distance_ent;
	ligne_to_add.push_back(distance_ent);
	for (int i = 0; i < distancier.size(); i++) {
		cout << i << endl;
		
		cout << " Donner la distance entre le client et le client : " << list_clients[i]->get_nom() << " : ";
		int distance_to_add;
		cin >> distance_to_add;
		distancier[i].push_back(distance_to_add);
		ligne_to_add.push_back(distance_to_add);
	}
	distancier.push_back(ligne_to_add);
}

// M�thode qui affiche tous les clients 
void Gestion::afficher_client()
{
	for (Client* c : list_clients)
		c->afficher_client();
}

// M�thode qui affiche tous les techniciens
void Gestion::afficher_techniciens()
{
	for (Techniciens* t : list_techs)
		t->afficher_techniciens();
}

// M�thode qui affiche la matrice distancier
void Gestion::afficher_distancier()
{
	for (int k = 0; k < distancier.size(); k++){
		cout << list_clients[k]->get_nom() << " ";
		for (int items : distancier[k])
			cout << items << " ";
		cout << endl;
	}
}

// M�thode qui affiche tous les interventions
void Gestion::afficher_intervention()
{
	for (Intervention* inter : list_inter)
		inter->afficher();
}

// M�thode qui calcul le temps d'une intervention
void Gestion::calcule_tps_intervention(int id_int, string nom_c1, string nom_c2)
{ 
}

// M�thode qui calcul le temps d'un d�placement
void Gestion::calcule_tps_deplacement(string , string nom_c1, string nom_c2)
{
}

// M�thode qui ajoute une intervention en v�rifiant :
//		-> que le nom existe (fonctionnel)
//		-> que les comp�tences sont les bonnes (fonctionnel)
//		-> que la distance est minimal (non fonctionnel)
//		-> que les dur�es sont coh�rentes et minimal (non fonctionnel)
void Gestion::add_intervention(string nom_client, string duree, vector<int> competences)
{
	Client* c1 = nullptr;
	for (Client* cl : list_clients) {
		if (cl->get_nom() == nom_client) {
			c1 = cl;
		}
	}
	if (c1 == nullptr) {
		cout << "Le client n'existe pas" << endl;
	}
	else {

		// On parcours l'ensemble des comp�tences n�cessaire (donc le nbr d'ing�nieur)
		// On parcours la liste des techniciens disponible (qui ne sont pas d�j� sur l'intervention) 
		//		-> on regarde si la comp�tence demand�e et la comp�tence du techniciens sont les m�mes
		//			-> si oui on l'ajoute � l'intervention et on le supprime des techniciens disponibles
		//			-> sinon on continu
		// On ajoute l'intervention � la list_interv
		vector<Techniciens*> list_tech_avaible = list_techs;
		vector<Techniciens*> technis;
		
		int i = 0;
		for (int comp : competences) {

			bool satis = false;
			for (int i = 0; i < list_tech_avaible.size(); i++) {
				if (satis == false) {
					vector<int> list_comp = list_tech_avaible[i]->get_competences();
					for (int j = 0; j < list_comp.size(); j++) {

						if (list_comp[j] == comp && satis == false) {

							Techniciens* tch = list_tech_avaible[i];

							satis = true;

							list_tech_avaible.erase(list_tech_avaible.begin() + i);
							technis.push_back(tch);

						}
					}
				}
			}
		}
		for (Techniciens* tech : technis) {
			cout << "**" << endl;
			tech->afficher_techniciens();
			cout << "**" << endl;
		}

		// Gestion de l'erreur si on ne trouve pas de techniciens 
		if (technis.size() != competences.size()) {
			cout << "Il n'y a pas assez de techniciens libre dans la journ�e !" << endl;
		}
		// On ajoute l'intervention
		else {
			Intervention* inter = new Intervention(Rand(0, 100), duree, c1, technis);
			list_inter.push_back(inter);
			cout << "Intervention ajout� avec succ�s !!" << endl;
		}


	}
}

void Gestion::archiver_inter()
{
	ofstream fich("CR.txt");

	for (Intervention* inter : list_inter) {
		fich << inter->get_id() << " | " << inter->get_duree() << " | " << inter->get_client()->get_nom();
			for (Techniciens* tech : inter->get_techniciens()) {
				fich << " | " << tech->get_nom();
			}
	cout << endl;
	}
	
}

