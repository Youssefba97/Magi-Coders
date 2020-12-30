#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include <string.h>
#include <gtk/gtk.h>

enum
{
	CIN,
	NOM,
	PRENOM,
	SEXE,
	SERVICE,
	TEL,
	MAIL,
	COLUMNS
};

//////////////////////////////////
void ajouterClient()
{
FILE *f=NULL;
f=fopen("clients.txt","a");
if(f == NULL)
{
return; 
}
else
{
fprintf(f,"%s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.service,c.tel,c.mail);
fclose(f);
}
}



//////////////////////////////////
void resultContrat()
{
	
	strcpy(c.service,"");
	if (contrat[0]==1)
	strcat(c.service,"|Troupeaux");
	if (contrat[1]==1)
	strcat(c.service,"|Plantations");
	if (contrat[2]==1)
	strcat(c.service,"|Ouvriers");
	if (contrat[3]==1)
	strcat(c.service,"|Equipements");
}

//////////////////////////////////
void resultContratModif()
{
	
	strcpy(tempo.service,"");
	if (contrat[0]==1)
	strcat(tempo.service,"|Troupeaux");
	if (contrat[1]==1)
	strcat(tempo.service,"|Plantations");
	if (contrat[2]==1)
	strcat(tempo.service,"|Ouvriers");
	if (contrat[3]==1)
	strcat(tempo.service,"|Equipements");
}



//////////////////////////////////
void supprimerClient(char cinDelete[10])
{
	    FILE *f;
	    FILE *ftemp;
	    ftemp=NULL;
	    
	   
	    f=fopen("clients.txt","r+");
	    ftemp=fopen("inter.txt","w+");
	    if (f!=NULL)
	    {
		while(fscanf(f,"%s %s %s %s %s %s %s",c.cin,c.nom,c.prenom,c.sexe,c.service,c.tel,c.mail)!=EOF)
		{
		    if(strcmp(cinDelete,c.cin)!=0)
		    {
	      fprintf(ftemp,"%s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.service,c.tel,c.mail);
		    }
		}

	        fclose(f);
    		fclose(ftemp);

		remove("clients.txt");
		rename("inter.txt","clients.txt");
	    }
}





//////////////////////////////////
int chercherClient(char cinSearch[10])
{
 	    FILE *f;
	    
	   
	    f=fopen("clients.txt","r+");
	    if (f!=NULL)
	    {
		while(fscanf(f,"%s %s %s %s %s %s %s",c.cin,c.nom,c.prenom,c.sexe,c.service,c.tel,c.mail)!=EOF)
		{
		    if(strcmp(cinSearch,c.cin)==0)
		    {
		fclose(f) ;
	      	return 1;
		    }
		}
	    }
		fclose(f);
		return 0;

}







//////////////////////////////////
void modifierClient(char cinEdit[10])

{
 	    FILE *f;
	    FILE *ftemp;
	    ftemp=NULL;
	    
	   
	    f=fopen("clients.txt","r+");
	    ftemp=fopen("inter.txt","w+");
	    if (f!=NULL)
	    {
		while(fscanf(f,"%s %s %s %s %s %s %s",c.cin,c.nom,c.prenom,c.sexe,c.service,c.tel,c.mail)!=EOF)
		{
		    if(strcmp(cinEdit,c.cin)==0)
		    {
	      fprintf(ftemp,"%s %s %s %s %s %s %s\n",tempo.cin,tempo.nom,tempo.prenom,tempo.sexe,tempo.service,tempo.tel,tempo.mail);
		    }
		    else
			{ 
			fprintf(ftemp,"%s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.service,c.tel,c.mail);
			}
		}

	        fclose(f);
    		fclose(ftemp);

		remove("clients.txt");
		rename("inter.txt","clients.txt");
	    }
}



//////////////////////////////////
void afficherClient(GtkWidget *liste)

{
GtkCellRenderer *renderer; //Afficheur de cellule (qui contient texte,image,case a cocher)

GtkTreeViewColumn *column ; //Visualisation des colonnes

GtkTreeIter iter; // indicateur de la ligne ou nous sommes situés

GtkListStore *store; // creation du modele de type liste

char cin[20];
char nom[20];
char prenom[20];
char sexe[10];  
char service[50];
char tel[20];
char mail[50];

store = NULL ;

FILE *f ;

store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new ();								//cellule contenant du texte
	column =  gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL); //creation d'une colonne avec du texte
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			//associer la colonne a l'afficheur (gtktreeview)

	renderer = gtk_cell_renderer_text_new ();								
	column =  gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			

	renderer = gtk_cell_renderer_text_new ();								
	column =  gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			

	renderer = gtk_cell_renderer_text_new ();								
	column =  gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			

	renderer = gtk_cell_renderer_text_new ();								
	column =  gtk_tree_view_column_new_with_attributes("service",renderer,"text",SERVICE,NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			

	renderer = gtk_cell_renderer_text_new ();								
	column =  gtk_tree_view_column_new_with_attributes("tel",renderer,"text",TEL,NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			

	renderer = gtk_cell_renderer_text_new ();								
	column =  gtk_tree_view_column_new_with_attributes("mail",renderer,"text",MAIL,NULL); 
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);			


//Creation des 7 Colonnes
store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f = fopen("clients.txt", "r");

if(f==NULL)
{
	return;
}
else
{
	f = fopen("clients.txt", "a+");
		while(fscanf(f,"%s %s %s %s %s %s %s",cin,nom,prenom,sexe,service,tel,mail)!=EOF) 
			{
				gtk_list_store_append (store, &iter);

				gtk_list_store_set (store, &iter, 
				CIN, cin, 
				NOM, nom, 
				PRENOM, prenom,
				SEXE,sexe,
				SERVICE,service,
				TEL,tel,
				MAIL,mail,-1);
			}
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
			g_object_unref(store);

}
}
}




