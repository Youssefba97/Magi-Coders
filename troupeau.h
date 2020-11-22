#ifndef TROUPEAU_H_
#define TROUPEAU_H_

typedef struct{
int jour;
int mois;
int annee;
}Date;

typedef struct{
char identifiant[30];
char type[30];
char sexe[30];
int etat; // 1 bonne santé 0 malade
Date date;
}Troupeau;


void ajouter_animal(Troupeau troupeau);
void modifier_animal(Troupeau troupeau);
void supprimer_animal(char * identifiant);
void chercher_animal(char * identifiant);
void afficher_troupeaux();
int Nombre_brebis();
int Nombre_veaux();


#endif

