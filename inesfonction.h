#ifndef OUVRIERS_H_
#define OUVRIERS_H_
typedef struct
{
char cin[8];
char presence[10];
int jour;
int mois;
int annee;
}Absenteisme;

typedef struct
{
char cin[8];
char nom[20];
char prenom[20];
char role[20] ; //jardinier.. etc
int jour; // jour de naissance de l'ouvrier
int mois; //mois de naissance de l'ouvrier
int annee; //mois de naissance de l'ouvrier
}Ouvrier;

void ajouter_ouvrier(Ouvrier O);
void supprimer_ouvrier(char *cin);
void chercher_ouvrier(char *cin);
void modifier_ouvrier(char *cin,Ouvrier tempo);
void marquer_absence (Absenteisme abs,int n); //n = taille de tableau des absents
void afficher_ouvriers();
#endif



