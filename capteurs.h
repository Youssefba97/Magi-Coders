#ifndef CAPTEURS_H_
#define CAPTEURS_H_
typedef struct
{
char identifiant[20];
char marque[20];
char position[20];
int type; //0: pour température , 1: pour l'humidité
int etat; //1: en marche , -1:en panne
}Capteur;
void ajouter_capteur(Capteur C);
void supprimer_capteur(char *id);
void chercher_capteur(char *id);
void modifier_capteur(char *id,Capteur tempo);
int changer_etat_capteur(char *id ,int etat);
void afficher_capteurs();
#endif

