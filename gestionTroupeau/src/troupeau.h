#ifndef TROUPEAU_H_
#define TROUPEAU_H_

typedef struct{
char identifiant[30];
char type[30];
char sexe[30];
int etat; // 1 bonne santé 0 malade
char date[30];
}Troupeau;


void ajouter_animal(Troupeau troupeau,int jour, int mois, int annee);
void modifier_animal(Troupeau troupeau, char * identifiant, int jour, int mois, int annee);
void supprimer_animal(char * identifiant);
void chercher_animal(char * identifiant);
int nombre_brebis();
int nombre_veaux();


#endif

