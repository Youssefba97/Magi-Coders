#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "tree.h"
#include "troupeau.h"

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;


void AfficherAnimal(GtkWidget* treeview1,char*l)
{
g_printf("dans afficher animal");
DataToPass*data1 = malloc(sizeof(struct DataToPass));
DataToPass*data2 = malloc(sizeof(struct DataToPass));
DataToPass*data3 = malloc(sizeof(struct DataToPass));
DataToPass*data4 = malloc(sizeof(struct DataToPass));
DataToPass*data5 = malloc(sizeof(struct DataToPass));
Troupeau troupeau;

data1->treeview  = treeview1;
data2->treeview  = treeview1;
data3->treeview  = treeview1;
data4->treeview  = treeview1;
data5->treeview  = treeview1;


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
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,troupeau.identifiant,
                            1,troupeau.type,
                            2,troupeau.sexe,
                            3,troupeau.etat,
                            4,troupeau.date,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
         g_object_set(cellad, "editable", TRUE, NULL);
         data1->columnNumber = 0;
         g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,data1);
         adcolumn = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        
        /* Ajouter la 1ere colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        data2->columnNumber = 1;
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,data2);
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        data3->columnNumber = 2;
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback, data3);
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        /* Ajouter la 3eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        data4->columnNumber = 3;
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback, data4);
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        data5->columnNumber = 4;
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,data5);
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        /* Ajouter la 5eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
    


	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore));

}


void AfficherRechercheAnimal(GtkWidget* treeview1,char*l)
{

Troupeau troupeau;


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
while(fscanf(f,"%s %s %s %d %s\n",troupeau.identifiant,troupeau.type,troupeau.sexe,&troupeau.etat,troupeau.date)!=EOF)

        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,troupeau.identifiant,
                            1,troupeau.type,
                            2,troupeau.sexe,
                            3,troupeau.etat,
                            4,troupeau.date,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
         g_object_set(cellad, "editable", TRUE, NULL);
         g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,(gpointer) 0);
        adcolumn = gtk_tree_view_column_new_with_attributes("IDENTIFIANT",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        /* Ajouter la 1ere colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback, (gpointer)1);
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,(gpointer) 2);
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        /* Ajouter la 3eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,(gpointer) 3);
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAT",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        g_object_set(cellad, "editable", TRUE, NULL);
        g_signal_connect(cellad, "edited", (GCallback) cell_edited_callback,(gpointer) 4);
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        /* Ajouter la 5eme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
    


	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore));

}







