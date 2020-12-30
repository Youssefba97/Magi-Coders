#include<gtk/gtk.h>
#ifndef CLIENT_H_
#define CLIENT_H_



typedef struct
{
char cin[20];
char nom[20];
char prenom[20];
char sexe[10];  //radio
char service[50];
char tel[20];
char mail[50];
}client;

char sexe [10];
int contrat[4];
char cinDelete[10];
client c,tempo; 

void resultContrat();
void resultContratModif();
void ajouterClient();
void supprimerClient(char cinDelete[10]);
int chercherClient(char cinSearch[10]);
void modifierClient(char cinEdit[10]);
void afficherClient(GtkWidget *liste);
#endif

