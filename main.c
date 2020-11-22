#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "troupeau.h"

void main()
{
Troupeau troupeau1,troupeau2;
char identifiant[30];
// test d'ajout d'un animal 1
printf("donner un id\n");
scanf("%s",troupeau1.identifiant);
printf("donner un type\n");
scanf("%s",troupeau1.type);
printf("donner un sexe\n");
scanf("%s",troupeau1.sexe);
printf("donner un etat\n");
scanf("%d",&troupeau1.etat);
printf("donner un jour\n");
scanf("%d",&troupeau1.date.jour);
printf("donner un mois\n");
scanf("%d",&troupeau1.date.mois);
printf("donner une annee\n");
scanf("%d",&troupeau1.date.annee);

// test d'ajout d'un animal 2
printf("donner un id\n");
scanf("%s",troupeau2.identifiant);
printf("donner un type\n");
scanf("%s",troupeau2.type);
printf("donner un sexe\n");
scanf("%s",troupeau2.sexe);
printf("donner un etat\n");
scanf("%d",&troupeau2.etat);
printf("donner un jour\n");
scanf("%d",&troupeau2.date.jour);
printf("donner un mois\n");
scanf("%d",&troupeau2.date.mois);
printf("donner une annee\n");
scanf("%d",&troupeau2.date.annee);

// test de modification d'un animal
printf("donner un id\n");
scanf("%s",troupeau1.identifiant);
printf("donner un type\n");
scanf("%s",troupeau1.type);
printf("donner un sexe\n");
scanf("%s",troupeau1.sexe);
printf("donner un etat\n");
scanf("%d",&troupeau1.etat);
printf("donner un jour\n");
scanf("%d",&troupeau1.date.jour);
printf("donner un mois\n");
scanf("%d",&troupeau1.date.mois);
printf("donner une annee\n");
scanf("%d",&troupeau1.date.annee);

modifier_animal(troupeau1);


// test de suppression d'un animal
printf("donner un id de l'animal à supprimer\n");
scanf("%s",identifiant);


supprimer_animal(identifiant);

// test de recherche d'un animal
printf("donner un id de l'animal à rechercher\n");
scanf("%s",identifiant);


supprimer_animal(identifiant);


// test de affichage troupeau
afficher_troupeaux();

// test de nombre de veaux
printf("le nombre de veaux est %d \n",nombre_veaux());

// test de nombre de brebis
printf("le nombre de veaux est %d \n",nombre_brebis());
}
