// **************************************************
// ** Sujet 5 : gestion des interventions ***********
// ** Author : Clovis Deletre ***********************
// ** Avec l'aide de C.VITRY, G.JADEAU, V.CHAUVEAU **
// **************************************************


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

using namespace std;


int main() {

	// On créer notre outil de gestion 
	Gestion gestion;


	cout << "***************************************************************" << endl;
	cout << "***************************************************************" << endl;
	cout << "******************* Outils de gestion d'interventions**********" << endl;
	cout << "***************************************************************" << endl;
	cout << "author : Clovis Delêtre ***************************************" << endl;
	cout << "***************************************************************" << endl;

	cout << "" << endl;
	cout << "Pour utiliser l'outil, entrez l'action que vous voulez réaliser." << endl;
	cout << "" << endl;
	cout << "" << endl;

	int choix = 998;
	while (choix != 999) {
		cout << "" << endl;
		cout << "" << endl;
		cout << "0 - Importer les données du fichiers Clients.txt," << endl;
		cout << "1 - Importer les données du fichiers Techniciens.txt" << endl;
		cout << "2 - Importer les données du fichiers Distancier.txt" << endl;
		cout << "3 - Afficher tous les clients, " << endl;
		cout << "4 - Afficher tous les techniciens " << endl;
		cout << "5 - Afficher le distancier " << endl;
		cout << "6 - Ajouter un client" << endl;
		cout << "7 - Supprmier un client" << endl;
		cout << "8 - Ajouter un technicien" << endl;
		cout << "9 - Supprimer un technicien" << endl;
		cout << "10 - Ajouter une intervention (en lui affectant les techniciens et lui donner une heure" << endl;
		cout << "11 - Afficher toutes les interventions " << endl;
		cout << "12 - Calculer le temps d’intervention d’un technicien (non fonctionnel)" << endl;
		cout << "13 - Calculer le temps de déplacement d’un technicien (non fonctionnel)" << endl;
		cout << "14 - Exporter les informations des informations sur CR.txt" << endl;
		cout << "999 - Arreter le programme " << endl;
		cout << "Entrez votre choix parmis les possibilités ci dessus : ";
		cin >> choix;

		// Importer les données du ficher Client.txt
		// On créer, pour chaque ligne, un objet Client()
		if (choix == 0) {
			ifstream file("Client.txt");
			string str;
			vector<string> lines;
			// On enregistre chaque ligne dans le vector lines
			while (getline(file, str)) {
				lines.push_back(str);
			}

			// Pour chaque lignes, on sépare en fonction des espaces et signes spéciaux
			for (string l : lines) {
				istringstream iss(l);
				string s;
				vector<string> words;
				while (getline(iss, s, ' ')) {
					words.push_back(s);
				}
				//for (int i = 0; i < words.size(); i++)
				//	cout << i << "" << words[i] << endl;

				//On enregistre chaque mot trouvé séparemment
				string nom = words[0];
				string num_tel = words[1];
				string adresse = words[2];
				Client* cc = new Client(nom, num_tel, adresse);
				gestion.add_client(cc);		//on ajoute le client

			}
		}
		
		// Importer les données du fichiers Techniciens.txt
		// On créer, pour chaque ligne, un objet Techniciens()
		else if (choix == 1) {
			ifstream file("Techniciens.txt");
			string str;
			vector<string> lines;
			// On enregistre chaque ligne dans le vector lines
			while (getline(file, str)) {
				lines.push_back(str);
			}

			// Pour chaque lignes, on sépare en fonction des espaces et signes spéciaux
			for (string l : lines) {
				istringstream iss(l);
				string s;
				vector<string> words;
				while (getline(iss, s, ' ')) {
					words.push_back(s);
				}
				//cout << words.size() << endl;
				//for (int i = 0; i < words.size(); i++)
				//	cout << i << "" << words[i] << endl;

				//On enregistre chaque mot trouvé séparemment
				string nom = words[0];
				string num_tel = words[1];
				vector<int> compt;
				for (int i = 2; i < words.size(); i++) {
					compt.push_back(stoi(words[i]));
				}
				Techniciens* t = new Techniciens(nom, num_tel, compt);
				gestion.add_techni(t);

				//gestion.add_client(cc);		//on ajoute le client
			}
		}

		// Importer les données du fichiers Distancier.txt
		// On créer une matrice de vector<int>
		// Chaque ligne correspond aux distances d'un client par rapport aux autres (et de l'entreprise)
		else if (choix == 2) {
			ifstream file("Distancier.txt");
			string str;
			vector<string> lines;
			// On enregistre chaque ligne dans le vector lines
			while (getline(file, str)) {
				lines.push_back(str);
			}

			// Pour chaque lignes, on sépare en fonction des espaces et signes spéciaux
			for (string l : lines) {
				istringstream iss(l);
				string s;
				vector<string> words;
				while (getline(iss, s, ' ')) {
					words.push_back(s);
				}

				//cout << words.size() << endl;
				//for (int i = 0; i < words.size(); i++)
					//cout << i << "" << words[i] << endl;

				//On enregistre chaque mot trouvé séparemment
				//string ent = words[0];
				//string a = words[1];
				//string b = words[2];
				//string c = words[3];
				//string d = words[4];
				//string e = words[5];
				//string f = words[6];
				vector<int> ad;
				for (int i = 0; i < words.size(); i++) {
					//cout << words[i] << endl;
					ad.push_back(stoi(words[i]));
				}


				gestion.add_distancier(ad);		//on ajoute la ligne au distancier
			}
		}

		// Afficher tous les clients 
		else if (choix == 3) {
			gestion.afficher_client();
		}
		
		// Afficher tous les techniciens
		else if (choix == 4) {
			gestion.afficher_techniciens();
		}

		// Afficher le distancier
		else if (choix == 5) {
			gestion.afficher_distancier();
		}

		// Ajouter un client 
		// On créer un client et on modifie la matrice distancier
		else if (choix == 6) {
			cout << "Entrer le nom du client : ";
			string nom;
			cin >> nom;
			cout << "Entrer le num de tel : ";
			string num_tel;
			cin >> num_tel;
			cout << "Entrer l'adresse : ";
			string adresse;
			cin >> adresse;
			Client* ccc = new Client(nom, num_tel, adresse);
			gestion.modif_distancier();
		}

		// Supprimer un client
		else if (choix == 7) {
			cout << "Entrer le nom du client : ";
			string nom_client_del;
			cin >> nom_client_del;
			gestion.del_client(nom_client_del);
		}

		// Ajouter un technicien
		else if (choix == 8) {
			cout << "Entrer le nom du technicien ";
			string nom_t_a;
			cin >> nom_t_a;
			cout << "Entrer le numéro de tel ";
			string num_tel_a;
			cin >> num_tel_a;

			vector<int> comp;
			cout << "Combien a-t-il de compétences ? ";
			int nbc;
			cin >> nbc;
			for (int i = 0; i < nbc; i++) {
				cout << "Quelle est la valeur de la compétence n°" << i + 1 << " : ";
				int comp_to_add;
				cin >> comp_to_add;
				comp.push_back(comp_to_add);
			}
			Techniciens* tech = new Techniciens(nom_t_a, num_tel_a, comp);
			gestion.add_techni(tech);
		}

		// Supprimer un technicien
		else if (choix == 9) {
		cout << "Entrer le nom du techniciens : ";
		string nom_tech_d;
		cin >> nom_tech_d;
		gestion.del_techni(nom_tech_d);
		}

		// Ajouter une intervention
		// on créer un vector de competences qui va permettre de sélectionner par la suite les techniciens voulus 
		// le vector va être de la forme {1,2,5,1,1} 
		else if (choix == 10) {
			cout << "Entrer le nom du client :";
			string nom_client;
			cin >> nom_client;
			cout << "Entrer la duree (sous le format XXhXX) :";
			string duree;
			cin >> duree;
			
			vector<int> competences_vec;
			cout << "Combien de techniciens(s) avez vous besoin ? ";
			int nbr_techni;
			cin >> nbr_techni;
			for (int i = 0; i < nbr_techni; i++) {
				cout << "Qu'elle doit être la compétence du technicien n°" << i+1 << " : ";
				int nb_competence;
				cin >> nb_competence;
				competences_vec.push_back(nb_competence);
			}
			gestion.add_intervention(nom_client, duree, competences_vec);
			gestion.afficher_intervention();
		}
		
		// Afficher toutes les interventions 
		else if (choix == 11) {
			gestion.afficher_intervention();
		}
		
		else if (choix == 12 || choix == 13) {
			cout << "Fonctio non fonctionnelle" << endl;
		}

		// Archiver le programme
		else if (choix == 14) {
			gestion.archiver_inter();
			cout << "Archivage avec succès !" << endl;
		}

		// Arreter le programme 
		else if (choix == 999) {

			exit(0);
		}
		
		// SI choix incorrect
		else {
			cout << "Choix incorrect !! " << endl;
		}
	}
}