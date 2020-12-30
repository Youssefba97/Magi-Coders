#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
//fonction ajouter absence
void ajouter_absence(Absence A){
FILE* f1=fopen("absenteisme.txt","a+");
if(f1==NULL){
printf("Impossible d'ouvrir le fichier");
}else{
fprintf(f1,"%s %s %s\n",A.username,A.password,A.absence);
}
fclose(f1);
}
//fonction ajout inscrit
void ajouter_inscrit(Inscrit I,int jour, int mois, int annee){
FILE *f=fopen("listedesinscrits.txt","a+");
FILE *f1=NULL;
FILE *f2=NULL;
FILE *f3=NULL;
if(f==NULL){
printf("Impossible d'ouvrir le fichier");
}else{
char date[30];
snprintf(date, 30, "%d%s%d%s%d", jour, "/",mois,"/",annee);
fprintf(f,"%s %s %s %s %s %s\n",I.nom,I.prenom,I.username,I.password,date,I.role);
	if (strcmp(I.role,"Proprietaire")==0){
	f1=fopen("proprietaire.txt","a+");
	fprintf(f1,"%s %s\n",I.username,I.password);
	fclose(f1);
	}
	if (strcmp(I.role,"Utilisateur")==0){
	f2=fopen("utilisateursinscrits.txt","a+");

	fprintf(f2,"%s %s\n",I.username,I.password);
	fclose(f2);
	}
	if (strcmp(I.role,"Ouvrier")==0){
	f3=fopen("ouvriersinscrits.txt","a+");
	fprintf(f3,"%s %s\n",I.username,I.password);
	fclose(f3);
	}
}
fclose(f);
}

//fonction exist inscrit
int inscrit_exist(char *username,char *password){
FILE*f=NULL;
Inscrit I;
f=fopen("listedesinscrits.txt","r");
while(fscanf(f,"%s %s %s %s %s %s\n",I.nom,I.prenom,I.username,I.password,I.date,I.role)!=EOF)
{
	if( (strcmp(I.username,username)==0) && (strcmp(I.password,password)==0) )
	return 1;
}
fclose(f);
return 0;
}
//fonction exist prop
int prop_exist(char *username,char *password){
FILE*f=NULL;
Inscrit I;
f=fopen("proprietaire.txt","r");
while(fscanf(f,"%s %s\n",I.username,I.password)!=EOF)
{
	if( (strcmp(I.username,username)==0) && (strcmp(I.password,password)==0) )
	return 1;
}
fclose(f);
return 0;
}
//fonction exist utilinscrit
int utilinscrit_exist(char *username,char *password){
FILE*f=NULL;
Inscrit I;
f=fopen("utilisateursinscrits.txt","r");
while(fscanf(f,"%s %s\n",I.username,I.password)!=EOF)
{
	if( (strcmp(I.username,username)==0) && (strcmp(I.password,password)==0) )
	return 1;
}
fclose(f);
return 0;
}
//fonction exist ouvinscrit
int ouvinscrit_exist(char *username,char *password){
FILE*f=NULL;
Inscrit I;
f=fopen("ouvriersinscrits.txt","r");
while(fscanf(f,"%s %s\n",I.username,I.password)!=EOF)
{
	if( (strcmp(I.username,username)==0) && (strcmp(I.password,password)==0) )
	return 1;
}
fclose(f);
return 0;
}
//ajout utilisateur
void ajouter_utilisateur(Utilisateur U,int jour, int mois, int annee){
FILE* f=fopen("utilisateurs.txt","a+");
if(f ==NULL){
printf("Impossible d'ouvrir le fichier");
}else{
char date[30];
snprintf(date, 30, "%d%s%d%s%d", jour, "/",mois,"/",annee);
fprintf(f,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,U.age,date);
}
fclose(f);
}

//fonction suprresion
void supprimer_utilisateur(char *cin){
FILE*f= fopen("utilisateurs.txt","a+");
FILE*f1=fopen("anciensutilisateurs.txt","w+");
Utilisateur U;
while(fscanf(f,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,&U.age,U.date)!=EOF){
if(strcmp(cin,U.cin)!=0){
fprintf(f1,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,U.age,U.date);
}}
fclose(f);
fclose(f1);
remove("utilisateurs.txt");
rename("anciensutilisateurs.txt","utilisateurs.txt");
}
//fonction chercher
void chercher_utilisateur(char *cin){
remove("utilisateurs_recherche.txt");
FILE*f=fopen("utilisateurs.txt","r");
FILE*f1=fopen("utilisateurs_recherche.txt","a+");
Utilisateur U;
while(fscanf(f,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,&U.age,U.date)!=EOF)
{
if(strcmp(cin,U.cin)==0){
fprintf(f1,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,U.age,U.date);

}
}
fclose(f);
fclose(f1);
}

//fonction exist utilisateur
int utilisateur_exist(char *cin){
FILE*f=NULL;
Utilisateur U;
f=fopen("utilisateurs.txt","r");
while(fscanf(f,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,&U.age,U.date)!=EOF)
{
	if(strcmp(U.cin,cin)==0)
	return 1;
}
fclose(f);
return 0;
}







