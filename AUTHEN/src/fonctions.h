#include<gtk/gtk.h>
#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct{
char nom[30];
char prenom[30];
char username[30];
char password[30];
char date[30];
char role[30];
}Inscrit;
typedef struct{
char cin[30];
char nom[30];
char prenom[30];
int age; 
char date[30];
}Utilisateur;
typedef struct{
char username[30];
char password[30];
char absence[30];
}Absence;
void ajouter_absence(Absence A);
void ajouter_inscrit(Inscrit I,int jour, int mois, int annee);
int inscrit_exist(char *username, char *password);
int prop_exist(char *username,char *password);
int utilinscrit_exist(char *username,char *password);
int ouvinscrit_exist(char *username,char *password);
void ajouter_utilisateur(Utilisateur U,int jour, int mois, int annee);
void supprimer_utilisateur(char *cin);
void chercher_utilisateur(char *cin);
int utilisateur_exist(char *cin);
#endif
