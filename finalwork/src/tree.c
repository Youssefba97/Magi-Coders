#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "tree.h"
#include "capteurs.h"
#include "fonction.h" 
GtkListStore *adstore;//creation du modele de type liste
GtkTreeViewColumn *adcolumn;//visualisation des colonnes
GtkCellRenderer *cellad; //afficheur de cellule(text,image..)
FILE *f=NULL;
int i,j,k,m,s;
void Capteurtree(GtkWidget* treeview1,char*l)
{

Capteur C;
	
        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	//Creation de la 1ère colonne 
if(i==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

void Alarmantetree(GtkWidget* TreeViewAffichageAlarmante,char*l)
{

Capteur C;
	

        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	
if(k==0)
	{
	//Creation de la 1ère colonne
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);
	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);
	
	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);
	k++; }
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (TreeViewAffichageAlarmante),
                                  GTK_TREE_MODEL(adstore)  );
	
}


void ChercherCapteur(GtkWidget* treeview2,char*l)
{
Capteur C;
	
        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	//Creation de la 1ère colonne 
if(j==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);


	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview2),
                                  GTK_TREE_MODEL(adstore)); 
}

void Defectueuxtree(GtkWidget* treeview3,char*l)
{
Capteur C;
	
        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	//Creation de la 1ère colonne 
if(m==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);


	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	m++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview3),
                                  GTK_TREE_MODEL(adstore)); 
}


void Afficherouvrier(GtkWidget* treeview1,char*l)
{

ouvrier o;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,&o.salaire)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,o.cin,
                            1,o.nom,
                            2,o.prenom,
                            3,o.tel,
                            4,o.sexe,
                            5,o.salaire,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numéro cin",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numéro tel",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

      /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("salaire",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}





void Afficherouvrier1(GtkWidget* treeview1,char*l)
{

ouvrier o;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                      G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,&o.salaire)!=EOF)
        {GtkTreeIter pIter;
	
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                             0,o.cin,
                            1,o.nom,
                            2,o.prenom,
                            3,o.tel,
                            4,o.sexe,
                            5,o.salaire,
                            -1);}
        fclose(f);


	/* Creation de la 1ere colonne */
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numéro cin",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numéro tel",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

      




	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



int Chercherouvrier(GtkWidget* treeview1,char*l,char*nom)
{

ouvrier o ;
int nb=0;

        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,&o.salaire)!=EOF)
        {
	if( strcmp(nom,o.nom)==0){ nb++;
	GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,o.cin,
                            1,o.nom,
                            2,o.prenom,
                            3,o.tel,
                            4,o.sexe,
                            5,o.salaire
                            -1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numero din",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Prenom",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numéro de tel",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Sexe",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);




	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}











//////////////////////////////////////////////////////////////////////////////////////////////////






void afficherabsence(GtkWidget* treeview1,char*l)
{

absenteisme a;


        /* Creation du modele */
        adstore = gtk_list_store_new(14,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d\n",a.cin,a.nom,&a.absjan,&a.absfev,&a.absmar,&a.absav,&a.absmai,&a.absjuin,&a.absjuil,&a.absaout,&a.abssept,&a.absoct,&a.absnov,&a.absdec)!=EOF)
        {GtkTreeIter pIter;
	
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                             0,a.cin,
                            1,a.nom,
                            2,a.absjan,
                            3,a.absfev,
                            4,a.absmar,
                            5,a.absav,
                            6,a.absmai,
                            7,a.absjuin,
                            8,a.absjuil,
                            9,a.absaout,
                            10,a.abssept,
                            11,a.absoct,
                            12,a.absnov,
                            13,a.absdec,-1);}
        fclose(f);


	/* Creation de la 1ere colonne */
if(s==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("numéro cin",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Janvier",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("fevrier",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mars",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Avril",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        
       /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mai",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       /* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Juin",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        
        /* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Juillet",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        /* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Aout",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
        /* Creation de la 10eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Septembre",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);
	/* Ajouter la 10emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       /* Creation de la 11eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Octobre",
                                                            cellad,
                                                            "text", 11,
                                                            NULL);
	/* Ajouter la 11emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
/* Creation de la 12eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("novembre",
                                                            cellad,
                                                            "text", 12,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
       /* Creation de la 14eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Décembre",
                                                            cellad,
                                                            "text", 13,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);








      




	s++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}
