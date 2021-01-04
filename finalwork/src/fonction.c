#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
 


void ajouter(ouvrier o , absenteisme a)
{
FILE *f=NULL;
FILE *f1=NULL ;

f=fopen("users.txt","a+");
f1=fopen("absenteisme.txt","a+");
if (f!=NULL && f1!=NULL)
{
fprintf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,o.salaire);
fprintf(f1,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",a.cin,a.nom,a.absjan,a.absfev,a.absmar,a.absav,a.absmai,a.absjuin,a.absjuil,a.absaout,a.abssept,a.absoct,a.absnov,a.absdec);
fclose(f);
fclose(f1);
}


else 
{printf("\n Erreur : Non trouvé");}

}





//fonction supprimer 
void supprimer(char*cin){
FILE*f=NULL;
FILE*f1=NULL;
ouvrier o ;
f=fopen("users.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,&o.salaire)!=EOF){
if(strcmp(cin,o.cin)!=0) 
fprintf(f1,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,o.salaire);
}
fclose(f);
fclose(f1);
remove("users.txt");
rename("ancien.txt","users.txt");
}




//fonction modifier

void modifier(ouvrier ov, char*cin ){
FILE*f=fopen("users.txt","r");
FILE*f1=fopen("ancienscap.txt","w+");
ouvrier o;
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,&o.salaire)!=EOF)
{
if(strcmp(o.cin,cin)==0)
{
fprintf(f1,"%s %s %s %s %s %d\n",cin,ov.nom,ov.prenom,ov.tel,ov.sexe,ov.salaire);
}
else{
fprintf(f1,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,o.salaire);
}
}
fclose(f);
fclose(f1);
remove("users.txt");
rename("ancienscap.txt","users.txt");
}


int exist(char*cin){
FILE*f=NULL;
ouvrier o;
f=fopen("users.txt","r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,&o.salaire)!=EOF)
{
	if(strcmp(o.cin,cin)==0)
	return 1;
}
fclose(f);
return 0;
}



void marquer(absenteisme a, char*cin ){
FILE*f=fopen("absenteisme.txt","r");
FILE*f1=fopen("ancienscap.txt","w+");
absenteisme ab;
while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",ab.cin,ab.nom,&ab.absjan,&ab.absfev,&ab.absmar,&ab.absav,&ab.absmai,&ab.absjuin,&ab.absjuil,&ab.absaout,&ab.abssept,&ab.absoct,&ab.absnov,&ab.absdec)!=EOF)
{
if(strcmp(ab.cin,cin)==0)
{
fprintf(f1,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",cin,a.nom,a.absjan,a.absfev,a.absmar,a.absav,a.absmai,a.absjuin,a.absjuil,a.absaout,a.abssept,a.absoct,a.absnov,a.absdec);
}
else{
fprintf(f1,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",ab.cin,ab.nom,ab.absjan,ab.absfev,ab.absmar,ab.absav,ab.absmai,ab.absjuin,ab.absjuil,ab.absaout,ab.abssept,ab.absoct,ab.absnov,ab.absdec);
}
}
fclose(f);
fclose(f1);
remove("absenteisme.txt");
rename("ancienscap.txt","absenteisme.txt");
}


/////////////////////////////////////////////////////////
absenteisme recuperer (absenteisme ab ,char*cin) 
{FILE*f=NULL ;
 
f=fopen("absenteisme.txt","r");
while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",ab.cin,ab.nom,&ab.absjan,&ab.absfev,&ab.absmar,&ab.absav,&ab.absmai,&ab.absjuin,&ab.absjuil,&ab.absaout,&ab.abssept,&ab.absoct,&ab.absnov,&ab.absdec)!=EOF)
{if( strcmp (ab.cin,cin)==0){
return(ab) ;} }
}

