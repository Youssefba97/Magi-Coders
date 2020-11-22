
typedef struct
{
char id[20];
char nom[20];
char prenom[20];
char tel[13];
char mail[40];
}client;

	//  int lire_fichier(char filename[],client C[]);
	// void lireClient( client C[], int n);
void ajoutClient(client C);  // la sortie est la nouvelle taille du tableau
	//int enregistrer_fichier(char filename[],client C[], int n);
	// void chercherClient (client C[], int n , char id[]); // retourne l'indice du client avec l'id
void modifClient (char *id,client tempo);
void SuppClient(char *id);
void afficherClient();
void chercherClient (char *id);




