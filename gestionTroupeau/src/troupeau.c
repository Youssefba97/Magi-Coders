#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "troupeau.h"


void ajouter_animal(Troupeau troupeau,int jour, int mois, int annee){
FILE* f= fopen("troupeau.txt","a+");
if(f == NULL){
printf("Impossible d'ouvrir le fichier");
}else{
char date[30];
snprintf(date, 30, "%d%s%d%s%d", jour, "/",mois,"/",annee);
fprintf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,troupeau.etat,date);
}


fclose(f);
}


void modifier_animal(Troupeau nouveau, char * identifiant, int jour, int mois, int annee){
FILE*f=fopen("troupeau.txt","r");
FILE*f1=fopen("ancien_troupeau.txt","w+");
Troupeau troupeau;

while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF){
if(strcmp(troupeau.identifiant,identifiant)==0)
{
char date[30];
snprintf(date, 30, "%d%s%d%s%d", jour, "/",mois,"/",annee);
fprintf(f1,"%s %s %s %d %s\n",nouveau.identifiant,nouveau.type,nouveau.sexe,nouveau.etat,date);
}else{
fprintf(f1,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,troupeau.etat,troupeau.date);
}

}
fclose(f);
fclose(f1);
remove("troupeau.txt");
rename("ancien_troupeau.txt","troupeau.txt");
}

void supprimer_animal(char * identifiant){
FILE* f = fopen("troupeau.txt","a+");

FILE*f1=fopen("ancien_troupeau.txt","w+");
Troupeau troupeau;
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF){
if(strcmp(identifiant,troupeau.identifiant)!=0){
fprintf(f1,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,troupeau.etat,troupeau.date);
}}
fclose(f);
fclose(f1);
remove("troupeau.txt");
rename("ancien_troupeau.txt","troupeau.txt");
}


void chercher_animal(char * identifiant){
remove("troupeau_recherche.txt");
FILE*f=fopen("troupeau.txt","r");
FILE*f1=fopen("troupeau_recherche.txt","a+");
Troupeau troupeau;
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF)
{
if(strcmp(identifiant,troupeau.identifiant)==0){
fprintf(f1,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,troupeau.etat,troupeau.date);
}
}
fclose(f);
fclose(f1);
}


int nombre_brebis(){
FILE*f=fopen("troupeau.txt","r");
Troupeau troupeau;
int nombre_brebis=0;
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF)
{
if(strcmp("Brebis",troupeau.type)==0){
nombre_brebis+=1;
}
}
fclose(f);
return nombre_brebis;
}


int nombre_veaux(){
FILE*f=fopen("troupeau.txt","r");
Troupeau troupeau;
int nombre_veaux=0;
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF)
{
if(strcmp("Veau",troupeau.type)==0){
nombre_veaux+=1;
}
}
fclose(f);
return nombre_veaux;
}


int animal_exist(char*identifiant){
FILE*f=NULL;
Troupeau troupeau;
f=fopen("troupeau.txt","r");
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF){
if(strcmp(troupeau.identifiant,identifiant)==0)return 1;
}
fclose(f);
return 0;
}


