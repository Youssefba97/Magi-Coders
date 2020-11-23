#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ouvriers.h"

//fonction ajout
void ajouter_ouvrier(Ouvrier O)
{
FILE *f=NULL;
f=fopen("ouvriers.txt","a+");
if(f ==!NULL)
{
printf("Impossible d'ouvrir le fichier");
}
else
{
    fprintf(f,"%s %s %s %s %d %d %d \n",O.cin,O.nom,O.prenom,O.role,O.jour,O.mois,O.annee);
}
fclose(f);
}
//fonction suprresion
void supprimer_ouvrier(char *cin)
{
FILE*f=NULL;
FILE*f1=NULL;
Ouvrier O;
f=fopen("ouvriers.txt","r");
f1=fopen("anciens.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d %d \n",O.cin,O.nom,O.prenom,O.role,&O.jour,&O.mois,&O.annee)!=EOF)
{
if(strcmp(cin,O.cin)!=0)
    fprintf(f1,"%s %s %s %s %d %d %d \n",O.cin,O.nom,O.prenom,O.role,O.jour,O.mois,O.annee);
}
fclose(f);
fclose(f1);
remove("ouvriers.txt");
rename("anciens.txt","ouvriers.txt");
}
//fonction chercher
void chercher_ouvrier(char *cin)
{
FILE*f=NULL;
Ouvrier O;
f=fopen("ouvriers.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d \n",O.cin,O.nom,O.prenom,O.role,&O.jour,&O.mois,&O.annee)!=EOF)
{
if(strcmp(cin,O.cin)!=0)
    {
	printf("Numéro de cin est: %s \n",O.cin);
	printf("Le nom est: %s \n",O.nom);
	printf("Le prénom est: %s \n",O.prenom);
	printf("Le role dans la ferme est: %s \n",O.role);
	printf("Jour de naissance: %d \n",O.jour);
    printf("Mois de naissance: %d \n",O.mois);
	printf("Annee de naissance: %d \n",O.annee);

	}
}
fclose(f);
printf("L''ouvrier n''existe pas ");
}
// fonction modifier
void modifier_ouvrier(char *cin,Ouvrier tempo)
{
FILE*f=NULL;
FILE*f1=NULL;
Ouvrier O;
f=fopen("ouvriers.txt","r");
f1=fopen("anciens.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d %d \n",O.cin,O.nom,O.prenom,O.role,&O.jour,&O.mois,&O.annee)!=EOF)
{
if(strcmp(cin,O.cin)!=0)
{
fprintf(f1,"%s %s %s %s %d %d %d \n",tempo.cin,tempo.nom,tempo.prenom,tempo.role,tempo.jour,tempo.mois,tempo.annee);
}
}
fclose(f);
fclose(f1);
remove("ouvriers.txt");
rename("anciens.txt","ouvriers.txt");
}
//fonction marquer absence
void marquer_absence (Absenteisme abs,int n) //n = taille de tableau des absents
{
FILE *f=NULL;
int i;
f=fopen("presence.txt","a+");
    if(f!=NULL)
    {

        for (i=0;i<n;i++)
        {
            fprintf(f,"%s %s %d %d %d /n",abs.cin,abs.presence,abs.jour,abs.mois,abs.annee);
        }

        fclose(f);
    }

    else
    {
        printf("Une erreur est survenue");
    }
}





//fonction afficher
void afficher_ouvriers()
{
FILE *f=NULL;
Ouvrier O;
int i=0;
f=fopen("ouvriers.txt","r");

if(f!=NULL)
{
    while (fscanf(f,"%s %s %s %s %d %d %d \n",O.cin,O.nom,O.prenom,O.role,&O.jour,&O.mois,&O.annee)!=EOF)
        {
            printf("La fiche d'ouvrier %d\n",i+1);
            printf("\n");
            printf("Numéro de cin de l''ouvrier est: %s \n",O.cin);
            printf("Le nom de l''ouvrier est: %s \n",O.nom);
            printf("Le prénom de l''ouvrier est: %s \n",O.prenom);
            printf("Le role de l''ouvrier dans la ferme est: %s \n",O.role);
            printf("Jour de naissance de l''ouvrier: %d \n",O.jour);
            printf("Mois de naissance de l''ouvrier: %d \n",O.mois);
            printf("Annee de naissance de l''ouvrier: %d \n",O.annee);
            printf("\n");
            i+=1;
        }

        fclose(f);
}
else
    {
        printf("Une erreur est survenue");
    }

}
