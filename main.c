#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "troupeau.h"

void main()
{
Troupeau troupeau1,troupeau2;
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

ajouter_animal(troupeau1);

}
