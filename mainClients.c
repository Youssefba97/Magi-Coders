#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "fonctions.c"





void main()
{


client client1,client2;
char id[30];

// test d'ajout d'un client 1

printf("donner un id\n");
scanf("%s",client1.id);
printf("nom \n");
scanf("%s",client1.nom);
printf("Prenom \n");
scanf("%s",client1.prenom);
printf("N° Tel\n");
scanf("%s",client1.tel);
printf("Mail \n");
scanf("%s",client1.mail);


// test d'ajout d'un client 2

printf("donner un id\n");
scanf("%s",client2.id);
printf("nom \n");
scanf("%s",client2.nom);
printf("Prenom \n");
scanf("%s",client2.prenom);
printf("N° Tel\n");
scanf("%s",client2.tel);
printf("Mail \n");
scanf("%s",client2.mail);


// test de modification d'un client

printf("modifier nom ? \n");
scanf("%s",client1.nom);
printf("Prenom prenom ? \n");
scanf("%s",client1.prenom);
printf("modifier N° Tel ?\n");
scanf("%s",client1.tel);
printf("modifier mail ?\n");
scanf("%s",client1.mail);


modifClient(id, client1);


// test de suppression d'un animal

printf("donner un id du client à supprimer\n");
scanf("%s",id);


SuppClient(id);

// test de recherche d'un animal

printf("donner un id du client à rechercher\n");
scanf("%s",id);


SuppClient(id);


// test de affichage client
afficherClient();

}
