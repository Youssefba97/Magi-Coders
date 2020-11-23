#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ouvriers.h"
#include "ouvriers.c"
void main()
{
Ouvrier ouvrier1,ouvrier2;
Absenteisme abs;
char cin[8];
int n;
// test d'ajout d'un ouvrier numéro 1
printf("donner numero de cin de l''ouvrier: \n");
scanf("%s",ouvrier1.cin);
printf("donner son nom : \n");
scanf("%s",ouvrier1.nom);
printf("donner son prenom : \n");
scanf("%s",ouvrier1.prenom);
printf("donner son role dans la ferme : \n");
scanf("%s",ouvrier1.role);
printf("donner le jour de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier1.jour);
printf("donner le mois de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier1.mois);
printf("donner l''annee de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier1.annee);

// test d'ajout d'un ouvrier numéro 2
printf("donner numero de cin de l''ouvrier: \n");
scanf("%s",ouvrier2.cin);
printf("donner son nom : \n");
scanf("%s",ouvrier2.nom);
printf("donner son prenom : \n");
scanf("%s",ouvrier2.prenom);
printf("donner son role dans la ferme : \n");
scanf("%s",ouvrier2.role);
printf("donner le jour de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier2.jour);
printf("donner le mois de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier2.mois);
printf("donner l''annee de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier2.annee);
// test de modification d'un ouvrier
printf("donner numero de cin de l''ouvrier: \n");
scanf("%s",ouvrier1.cin);
printf("donner son nom : \n");
scanf("%s",ouvrier1.nom);
printf("donner son prenom : \n");
scanf("%s",ouvrier1.prenom);
printf("donner son role dans la ferme : \n");
scanf("%s",ouvrier1.role);
printf("donner le jour de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier1.jour);
printf("donner le mois de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier1.mois);
printf("donner l''annee de naissance de l''ouvrier: \n");
scanf("%d",&ouvrier1.annee);

modifier_ouvrier(cin,ouvrier1);


// test de suppression d'un ouvrier
printf("donner cin de l''ouvrier à supprimer: \n");
scanf("%s",cin);
supprimer_ouvrier(cin);

// test de recherche d'un ouvrier
printf("donner cin de l''ouvrier à chercher: \n");
scanf("%s",cin);
chercher_capteur(cin);


// test d'affichage capteurs
afficher_ouvriers();


// test de l
printf("donner la taille du tableau des absents : \n");
scanf("%d",&n);
marquer_absence(abs,n);
}
