#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "capteurs.h"
#include "capteurs.c"
void main()
{
Capteur capteur1,capteur2;
char identifiant[20];
int etat;
// test d'ajout d'un capteur numéro 1
printf("donner un identifiant: \n");
scanf("%s",capteur1.identifiant);
printf("donner une marque: \n");
scanf("%s",capteur1.marque);
printf("donner la position dans la ferme: \n");
scanf("%s",capteur1.position);
printf("donner la valeur du capteur: \n");
scanf("%d",&capteur1.valeur);
printf("donner le type du capteur: \n");
scanf("%d",&capteur1.type);
printf("donner l'etat du capteur: \n");
scanf("%d",&capteur1.etat);


// test d'ajout d'un capteur numéro 2
printf("donner un identifiant: \n");
scanf("%s",capteur1.identifiant);
printf("donner une marque: \n");
scanf("%s",capteur1.marque);
printf("donner la position dans la ferme: \n");
scanf("%s",capteur1.position);
printf("donner la valeur du capteur: \n");
scanf("%d",&capteur2.valeur);
printf("donner le type du capteur: \n");
scanf("%d",&capteur1.type);
printf("donner l'etat du capteur: \n");
scanf("%d",&capteur1.etat);

// test de modification d'un capteur
printf("donner un identifiant: \n");
scanf("%s",capteur1.identifiant);
printf("donner une marque: \n");
scanf("%s",capteur1.marque);
printf("donner la position dans la ferme: \n");
scanf("%s",capteur1.position);
printf("donner la valeur du capteur: \n");
scanf("%d",&capteur1.valeur);
printf("donner le type du capteur: \n");
scanf("%d",&capteur1.type);
printf("donner l'etat du capteur: \n");
scanf("%d",&capteur1.etat);

modifier_capteur(identifiant,capteur1);


// test de suppression d'un capteur
printf("donner un identifiant du capteur à supprimer: \n");
scanf("%s",identifiant);
supprimer_capteur(identifiant);

// test de recherche d'un capteur
printf("donner un identifiant du capteur à chercher: \n");
scanf("%s",identifiant);
chercher_capteur(identifiant);


// test d'affichage capteurs
afficher_capteurs();


// test de changement d'état du capteur
printf("donner l'identifiant du capteur et son état: \n");
scanf("%s %d",identifiant,&etat);
changer_etat_capteur(identifiant,etat);
//test de capteurs à valeurs alarmantes
capteurs_a_valeurs_alarmantes();
}
