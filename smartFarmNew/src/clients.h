#include<gtk/gtk.h>
#ifndef CLIENTS_H_
#define CLIENTS_H_

char sexe [10];
int service[4]={0,0,0,0};


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

client c,tempo;

void resultContrat();
void ajouterClient();
void supprimerClient(char cin[10]);
void chercherClient(char cin[10]);
void modifierClient(char cin[10]);
void afficherClient();
#endif

