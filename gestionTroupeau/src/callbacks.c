#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "troupeau.h"
#include"tree.h"


void
on_button_ajouter_clicked              (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{ 
GtkWidget *labelId, *labelType, *labelSexe, *labelEtat, *labelDate, *existe, *success, *identifiantEntry, *typeCombo, *sexeCombo, *spinButton;
Troupeau troupeau;
  char nombreBrebis[30];
  char nombreVeaux[30];
  int nbBrebis,nbVeaux;


int jour,mois,annee,pass=1;

//Labels
labelId=lookup_widget(window_gestion_troupeau_mb,"label3");
labelType=lookup_widget(window_gestion_troupeau_mb,"label4");
labelSexe=lookup_widget(window_gestion_troupeau_mb,"label5");
labelEtat=lookup_widget(window_gestion_troupeau_mb,"label6");
labelDate=lookup_widget(window_gestion_troupeau_mb,"label7");
existe=lookup_widget(window_gestion_troupeau_mb,"label_echec_1_mb");
success=lookup_widget(window_gestion_troupeau_mb,"label_sucess_1_mb");

//Entries
identifiantEntry=GTK_ENTRY(lookup_widget(window_gestion_troupeau_mb,"entry_identifiant_1_mb"));
typeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"combo_type_1_mb"));
sexeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"combo_sexe_1_mb"));
spinButton=GTK_SPIN_BUTTON(lookup_widget(window_gestion_troupeau_mb,"spin_button_etat_1_mb"));




//Récuperation de l'identifiant et controle de saisie
strcpy(troupeau.identifiant,gtk_entry_get_text(identifiantEntry));
if(strcmp(troupeau.identifiant,"")==0){
 gtk_widget_show(labelId);}
else{
gtk_widget_set_visible(labelId,FALSE);
}


//Récuperation du type et controle de saisie
if(gtk_combo_box_get_active(typeCombo)==-1){
 gtk_widget_show(labelType);
}else{
gtk_widget_set_visible(labelType,FALSE);
}
strcpy(troupeau.type,gtk_combo_box_get_active_text(typeCombo));


//Récuperation du sexe et controle de saisie
if(gtk_combo_box_get_active(sexeCombo)==-1){
gtk_widget_show(labelSexe);
}else{
gtk_widget_set_visible(labelSexe,FALSE);
}
strcpy(troupeau.sexe,gtk_combo_box_get_active_text(sexeCombo));

//Récuperation de létat
troupeau.etat=gtk_spin_button_get_value_as_int(spinButton);

//Récuperation de la date
gtk_calendar_get_date(GTK_CALENDAR(lookup_widget(window_gestion_troupeau_mb,"calendar_mb1")),
                       &annee,
                       &mois,
                       &jour);



if(gtk_widget_get_visible(labelId)==FALSE && gtk_widget_get_visible(labelType)==FALSE && gtk_widget_get_visible(labelSexe)==FALSE){
if(animal_exist(troupeau.identifiant)==1){
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(existe);
}else{
ajouter_animal(troupeau,jour,mois,annee);
GtkWidget* p1=lookup_widget(window_gestion_troupeau_mb,"treeview_1_mb");
AfficherAnimal(p1,"troupeau.txt");
GtkWidget* p2=lookup_widget(window_gestion_troupeau_mb,"treeview_2_mb");
AfficherRechercheAnimal(p2,"troupeau.txt");
gtk_widget_set_visible(existe,FALSE);
gtk_widget_show(success);
gtk_entry_set_text(identifiantEntry,"");
//supporté par la version GTK 2.4
//gtk_combo_box_set_active_id(sexeCombo,-1);
gtk_spin_button_set_value(spinButton,1);
  GtkWidget* p3=lookup_widget(window_gestion_troupeau_mb,"label_nombre_veau_output_mb");
  GtkWidget* p4=lookup_widget(window_gestion_troupeau_mb,"label_nombre_brebis_output_mb");
  nbVeaux = nombre_veaux();
  snprintf(nombreVeaux, 30, "%d", nbVeaux);
  gtk_label_set_text(p3,nombreVeaux);
  nbBrebis = nombre_brebis();
  snprintf(nombreBrebis, 30, "%d", nbBrebis);
  gtk_label_set_text(p4,nombreBrebis);
}
}
}


void
on_button_modifier_clicked             (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{




        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* identifiant;

GtkWidget *labelId, *labelType, *labelSexe, *labelEtat, *labelDate, *existe, *success, *identifiantEntry, *typeCombo, *sexeCombo, *spinButton, *p1, *p2, *labelSelection;
Troupeau troupeau;
  char nombreBrebis[30];
  char nombreVeaux[30];
  int nbBrebis,nbVeaux;


int jour,mois,annee,pass=1;

gtk_widget_set_visible(success,FALSE);
//Labels
labelId=lookup_widget(window_gestion_troupeau_mb,"label12");
labelType=lookup_widget(window_gestion_troupeau_mb,"label13");
labelSexe=lookup_widget(window_gestion_troupeau_mb,"label14");
labelEtat=lookup_widget(window_gestion_troupeau_mb,"label15");
labelDate=lookup_widget(window_gestion_troupeau_mb,"label16");
existe=lookup_widget(window_gestion_troupeau_mb,"label_echec_2_mb");
success=lookup_widget(window_gestion_troupeau_mb,"label_sucess_2_mb");
labelSelection=lookup_widget(window_gestion_troupeau_mb,"label19");


//Entries
identifiantEntry=GTK_ENTRY(lookup_widget(window_gestion_troupeau_mb,"entry_identifiant_2_mb"));
typeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"combo_type_2_mb"));
sexeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"combo_sexe_2_mb"));
spinButton=GTK_SPIN_BUTTON(lookup_widget(window_gestion_troupeau_mb,"spin_button_etat_2_mb"));




//Récuperation de l'identifiant et controle de saisie
strcpy(troupeau.identifiant,gtk_entry_get_text(identifiantEntry));
if(strcmp(troupeau.identifiant,"")==0){
 gtk_widget_show(labelId);}
else{
gtk_widget_set_visible(labelId,FALSE);
}


//Récuperation du type et controle de saisie
if(gtk_combo_box_get_active(typeCombo)==-1){
 gtk_widget_show(labelType);
}else{
gtk_widget_set_visible(labelType,FALSE);
}
strcpy(troupeau.type,gtk_combo_box_get_active_text(typeCombo));


//Récuperation du sexe et controle de saisie
if(gtk_combo_box_get_active(sexeCombo)==-1){
gtk_widget_show(labelSexe);
}else{
gtk_widget_set_visible(labelSexe,FALSE);
}
strcpy(troupeau.sexe,gtk_combo_box_get_active_text(sexeCombo));

//Récuperation de létat
troupeau.etat=gtk_spin_button_get_value_as_int(spinButton);

//Récuperation de la date
gtk_calendar_get_date(GTK_CALENDAR(lookup_widget(window_gestion_troupeau_mb,"calendar_mb2")),
                       &annee,
                       &mois,
                       &jour);



if(gtk_widget_get_visible(labelId)==FALSE && gtk_widget_get_visible(labelType)==FALSE && gtk_widget_get_visible(labelSexe)==FALSE){






        p1=lookup_widget(window_gestion_troupeau_mb,"treeview_1_mb");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  


gtk_widget_set_visible(labelSelection,FALSE);
gtk_tree_model_get (model,&iter,0,&identifiant,-1);
if(animal_exist(troupeau.identifiant)==1 && strcmp(troupeau.identifiant,identifiant)!=0){
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(existe);
}else{
           modifier_animal(troupeau,identifiant,jour,mois,annee);// modifier la ligne dans le fichier
          AfficherAnimal(p1,"troupeau.txt");
        p2=lookup_widget(window_gestion_troupeau_mb,"treeview_2_mb");
           AfficherRechercheAnimal(p2,"troupeau.txt");
gtk_widget_set_visible(existe,FALSE);
gtk_widget_show(success);
gtk_entry_set_text(identifiantEntry,"");
gtk_spin_button_set_value(spinButton,1);
  GtkWidget* p3=lookup_widget(window_gestion_troupeau_mb,"label_nombre_veau_output_mb");
  GtkWidget* p4=lookup_widget(window_gestion_troupeau_mb,"label_nombre_brebis_output_mb");
  nbVeaux = nombre_veaux();
  snprintf(nombreVeaux, 30, "%d", nbVeaux);
  gtk_label_set_text(p3,nombreVeaux);
  nbBrebis = nombre_brebis();
  snprintf(nombreBrebis, 30, "%d", nbBrebis);
  gtk_label_set_text(p4,nombreBrebis);
}




    }else{
gtk_widget_show(labelSelection);
}



}

}


void
on_button_chercher_clicked             (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{
GtkWidget *p;
gchar *identifiant;
identifiant=gtk_entry_get_text(GTK_ENTRY(lookup_widget(window_gestion_troupeau_mb,"entry_identifiant_3_mb")));

p=lookup_widget(window_gestion_troupeau_mb,"treeview_2_mb");
if(strcmp(identifiant,"")==0){
AfficherRechercheAnimal(p,"troupeau.txt");
}else{
chercher_animal(identifiant);
AfficherRechercheAnimal(p,"troupeau_recherche.txt");
}

}


void
on_button_supprimer_clicked            (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{




        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p1, *p2;
        gchar* identifiant;

        p1=lookup_widget(window_gestion_troupeau_mb,"treeview_1_mb");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&identifiant,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_animal(identifiant);// supprimer la ligne du fichier
        p2=lookup_widget(window_gestion_troupeau_mb,"treeview_2_mb");
           AfficherRechercheAnimal(p2,"troupeau.txt");

    }



        

}



void cell_edited_callback (GtkWidget *window_gestion_troupeau_mb,
                                  gchar               *path_string,
                                  gchar               *new_text,
                                  gpointer             user_data){

        GtkWidget* p1,*p2;
GtkWidget *labelId,*existe, *success;
Troupeau troupeau;

DataToPass *d =user_data;
    g_print("%d\n", d->columnNumber);
labelId=lookup_widget(window_gestion_troupeau_mb,"label12");
existe=lookup_widget(window_gestion_troupeau_mb,"label_echec_2_mb");
success=lookup_widget(window_gestion_troupeau_mb,"label_sucess_2_mb");

if(strcmp(new_text,"")==0){
 gtk_widget_show(labelId);}
else{
gtk_widget_set_visible(labelId,FALSE);
}
if(animal_exist(new_text)==1 /*&& strcmp(new_text,identifiant)!=0*/){
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(existe);
}else{
modify_singleValue(new_text,path_string,d->columnNumber);
g_print("après modify");
p1=lookup_widget(window_gestion_troupeau_mb,"treeview_1_mb");
AfficherAnimal(d->treeview,"troupeau.txt");
p2=lookup_widget(window_gestion_troupeau_mb,"treeview_2_mb");
AfficherRechercheAnimal(p2,"troupeau.txt");
}
}


void
on_button_gestion_mb_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_gestion_troupeau_mb = create_window_gestion_troupeau_mb();
  char nombreBrebis[30];
  char nombreVeaux[30];
  int nbBrebis,nbVeaux;
  gtk_widget_show (window_gestion_troupeau_mb);
  GtkWidget* p1=lookup_widget(window_gestion_troupeau_mb,"treeview_1_mb");
  AfficherAnimal(p1,"troupeau.txt");
  GtkWidget* p2=lookup_widget(window_gestion_troupeau_mb,"treeview_2_mb");
  AfficherRechercheAnimal(p2,"troupeau.txt");
  GtkWidget* p3=lookup_widget(window_gestion_troupeau_mb,"label_nombre_veau_output_mb");
  GtkWidget* p4=lookup_widget(window_gestion_troupeau_mb,"label_nombre_brebis_output_mb");
  nbVeaux = nombre_veaux();
  snprintf(nombreVeaux, 30, "%d", nbVeaux);
  gtk_label_set_text(p3,nombreVeaux);
  nbBrebis = nombre_brebis();
  snprintf(nombreBrebis, 30, "%d", nbBrebis);
  gtk_label_set_text(p4,nombreBrebis);

}

