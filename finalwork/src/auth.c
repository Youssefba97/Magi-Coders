#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
 





void ajouterutilisateur(char nom[30], char mdp[30] )
{
FILE *f=NULL;

f=fopen("utilisateurs.txt","a+");

if (f!=NULL)
{
fprintf(f,"%s %s\n",nom,mdp);
fclose(f);
}


else 
{printf("\n Erreur : Non trouvé");}

}






int verifierutilisateur(char nom[],char mdp[])
{


int found =-1;

FILE *f=NULL;

char user[20];
char pass[20];

f=fopen("utilisateurs.txt","r");

if (f!=NULL)
{
while(fscanf(f,"%s %s\n",user,pass)!=EOF)
{
if((strcmp(user,nom)==0)&&(strcmp(pass,mdp)==0))
{found=1;}
}
fclose(f);
}
else
{printf("\n not found");}
return found;

}


