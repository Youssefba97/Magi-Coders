#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "functions.h"
#include "tree.h"


GtkListStore *adstore;		//create new list
GtkTreeViewColumn *adcolumn;	//show columns
GtkCellRenderer *cellad;	//show cell contents




					//Spring treeView

void SpringTreeView(GtkWidget* TreeView,char*filename)
{
Calendar C;
int i;
FILE *f=NULL;

        //creating model

        adstore = gtk_list_store_new(5,
				G_TYPE_INT,
				G_TYPE_STRING,
				G_TYPE_STRING,
                                G_TYPE_STRING,
				G_TYPE_STRING);

        //inserting elements

        f=fopen(filename,"r");

while(fscanf(f,"%d %s %s %s %s\n",&C.identifier,C.plante,C.saison,C.encem,C.rec)!=EOF)

        {
	if (strcmp(C.saison,"printemps")==0)
		{
			GtkTreeIter pIter;

			 //creating new line
			 gtk_list_store_append(adstore, &pIter);
			 //updating data
			 gtk_list_store_set(adstore, &pIter,
				            0,C.identifier,
				            1,C.plante,
				            2,C.saison,
				            3,C.encem,
				            4,C.rec,
				            -1);
		}
	}
        fclose(f);


	//creating line
if(i==0)
	//creating first column
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 2nd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("plante",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 3rd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("saison",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 4th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("encemencement",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 5th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("recolte",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);
    


	i++;
	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (TreeView),
                                  GTK_TREE_MODEL(adstore));


}



					//Summer treeView

void SummerTreeView(GtkWidget* TreeView,char*filename)
{
Calendar C;
int i;
FILE *f=NULL;

        //creating model

        adstore = gtk_list_store_new(5,
				G_TYPE_INT,
				G_TYPE_STRING,
				G_TYPE_STRING,
                                G_TYPE_STRING,
				G_TYPE_STRING);

        //inserting elements

        f=fopen(filename,"r");

while(fscanf(f,"%d %s %s %s %s\n",&C.identifier,C.plante,C.saison,C.encem,C.rec)!=EOF)

        {
	if (strcmp(C.saison,"été")==0)
		{
			GtkTreeIter pIter;

			 //creating new line
			 gtk_list_store_append(adstore, &pIter);
			 //updating data
			 gtk_list_store_set(adstore, &pIter,
				            0,C.identifier,
				            1,C.plante,
				            2,C.saison,
				            3,C.encem,
				            4,C.rec,
				            -1);
		}
	}
        fclose(f);


	//creating line
if(i==0)
	//creating first column
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 2nd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("plante",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 3rd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("saison",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 4th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("encemencement",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 5th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("recolte",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);
    


	i++;
	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (TreeView),
                                  GTK_TREE_MODEL(adstore));

}



					//Autumn treeView

void AutumnTreeView(GtkWidget* TreeView,char*filename)
{

Calendar C;
int i;
FILE *f=NULL;

        //creating model

        adstore = gtk_list_store_new(5,
				G_TYPE_INT,
				G_TYPE_STRING,
				G_TYPE_STRING,
                                G_TYPE_STRING,
				G_TYPE_STRING);

        //inserting elements

        f=fopen(filename,"r");

while(fscanf(f,"%d %s %s %s %s\n",&C.identifier,C.plante,C.saison,C.encem,C.rec)!=EOF)

        {
	if (strcmp(C.saison,"automne")==0)
		{
			GtkTreeIter pIter;

			 //creating new line
			 gtk_list_store_append(adstore, &pIter);
			 //updating data
			 gtk_list_store_set(adstore, &pIter,
				            0,C.identifier,
				            1,C.plante,
				            2,C.saison,
				            3,C.encem,
				            4,C.rec,
				            -1);
		}
	}
        fclose(f);


	//creating line
if(i==0)
	//creating first column
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 2nd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("plante",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 3rd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("saison",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 4th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("encemencement",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 5th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("recolte",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);
    


	i++;
	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (TreeView),
                                  GTK_TREE_MODEL(adstore));


}


					//winter treeView

void WinterTreeView(GtkWidget* TreeView,char*filename)
{

Calendar C;
int i;
FILE *f=NULL;

        //creating model

        adstore = gtk_list_store_new(5,
				G_TYPE_INT,
				G_TYPE_STRING,
				G_TYPE_STRING,
                                G_TYPE_STRING,
				G_TYPE_STRING);

        //inserting elements

        f=fopen(filename,"r");

while(fscanf(f,"%d %s %s %s %s\n",&C.identifier,C.plante,C.saison,C.encem,C.rec)!=EOF)

        {
	if (strcmp(C.saison,"hiver")==0)
		{
			GtkTreeIter pIter;

			 //creating new line
			 gtk_list_store_append(adstore, &pIter);
			 //updating data
			 gtk_list_store_set(adstore, &pIter,
				            0,C.identifier,
				            1,C.plante,
				            2,C.saison,
				            3,C.encem,
				            4,C.rec,
				            -1);
		}
	}
        fclose(f);


	//creating line
if(i==0)
	//creating first column
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 2nd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("plante",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);



	//creating 3rd column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("saison",
                                                            cellad,
                                                           "text", 2,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 4th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("encemencement",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);


	//creating 5th column
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("recolte",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
        //adding view
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeView), adcolumn);
    


	i++;
	}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (TreeView),
                                  GTK_TREE_MODEL(adstore));


}
