#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "troupeau.h"


void ajouter_animal(Troupeau troupeau){
FILE* f= fopen("troupeau.txt","a+");
if(f == NULL){
printf("Impossible d'ouvrir le fichier");
}else{
fprintf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,troupeau.etat,troupeau.date.jour,troupeau.date.mois,troupeau.date.annee);
}
fclose(f);
}


void modifier_animal(Troupeau nouveau){
FILE*f=fopen("troupeau.txt","r");
FILE*f1=fopen("ancien_troupeau.txt","w+");
Troupeau troupeau;

while(fscanf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,&troupeau.date.jour,&troupeau.date.mois,&troupeau.date.annee)!=EOF){
if(strcmp(troupeau.identifiant,nouveau.identifiant)!=0)
{
fprintf(f1,"%s %s %d %d %d %d\n",nouveau.type,nouveau.sexe,nouveau.etat,nouveau.date.jour,nouveau.date.mois,nouveau.date.annee);
}

}
fclose(f);
fclose(f1);
remove("troupeau.txt");
rename("ancien_troupeau.txt","troupeau.txt");
}

void supprimer_animal(char * identifiant){
FILE* f = fopen("troupeau.txt","r");

FILE*f1=NULL;
Troupeau troupeau;

f1=fopen("ancien_troupeau.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,&troupeau.date.jour,&troupeau.date.mois,&troupeau.date.annee)!=EOF){
if(strcmp(identifiant,troupeau.identifiant)!=0){
fprintf(f1,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,troupeau.etat,troupeau.date.jour,troupeau.date.mois,troupeau.date.annee);
}}
fclose(f);
fclose(f1);
remove("troupeau.txt");
rename("ancien_troupeau.txt","troupeau.txt");
}


void chercher_animal(char * identifiant){
FILE*f=fopen("troupeau.txt","r");
Troupeau troupeau;
while(fscanf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,&troupeau.date.jour,&troupeau.date.mois,&troupeau.date.annee)!=EOF)
{
if(strcmp(identifiant,troupeau.identifiant)==0){
printf("L'identfiant est %s\n",troupeau.identifiant);
printf("Le type est %s\n",troupeau.type);
printf("Le sexe est %s\n",troupeau.sexe);
printf("Le sexe est %d\n",troupeau.etat);
printf("Le date de naissance est %d/%d/%d\n",troupeau.date.jour,troupeau.date.mois,troupeau.date.annee);
}
}
fclose(f);
printf("L'animal est introuvable");
}


void afficher_troupeaux(){
FILE*f=fopen("troupeau.txt","r");
Troupeau troupeau;
int i=0;
while(fscanf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,&troupeau.date.jour,&troupeau.date.mois,&troupeau.date.annee)!=EOF)
{
printf("La fiche du troupeau %d\n",i+1);
printf("\n");
printf("L'identfiant est %s\n",troupeau.identifiant);
printf("Le type est %s\n",troupeau.type);
printf("Le sexe est %s\n",troupeau.sexe);
printf("Le sexe est %d\n",troupeau.etat);
printf("Le date de naissance est %d/%d/%d\n",troupeau.date.jour,troupeau.date.mois,troupeau.date.annee);
printf("\n");
i+=1;
}
fclose(f);
}

int Nombre_brebis(){
FILE*f=fopen("troupeau.txt","r");
Troupeau troupeau;
int nombre_brebis=0;
while(fscanf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,&troupeau.date.jour,&troupeau.date.mois,&troupeau.date.annee)!=EOF)
{
if(strcmp("Brebis",troupeau.type)==0){
nombre_brebis+=1;
}
}
fclose(f);
return nombre_brebis;
}


int Nombre_veaux(){
FILE*f=fopen("troupeau.txt","r");
Troupeau troupeau;
int nombre_veaux=0;
while(fscanf(f,"%s %s %s %d %d %d %d\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,&troupeau.date.jour,&troupeau.date.mois,&troupeau.date.annee)!=EOF)
{
if(strcmp("Veau",troupeau.type)==0){
nombre_veaux+=1;
}
}
fclose(f);
return nombre_veaux;
}


