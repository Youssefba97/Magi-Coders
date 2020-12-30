#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"
#include "fonctions.h"

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
int i;

void AfficherUtilisateur(GtkWidget* treeviewutil,char*l)
{

Utilisateur U;


        /* Creation du modele */
        adstore = gtk_list_store_new(5,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_STRING
                                     );
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %d %s\n",U.cin,U.nom,U.prenom,&U.age,U.date)!=EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,U.cin,
                            1,U.nom,
                            2,U.prenom,
                            3,U.age,
                            4,U.date,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("cin",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        /* Ajouter la 1ere colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewutil), adcolumn);



	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewutil), adcolumn);



	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        /* Ajouter la 3eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewutil), adcolumn);


	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("age",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewutil), adcolumn);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("date",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        /* Ajouter la 5eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewutil), adcolumn);
    


	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewutil),
                                  GTK_TREE_MODEL(adstore));

}
