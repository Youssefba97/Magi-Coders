#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "tree.h"
#include "fonctions.h"


void
on_ButtonSeConnecter_clicked           (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowwelcome, *windowconnexion;

windowconnexion=create_WindowConnexion();
windowwelcome=lookup_widget(windowauthen,"WindowWelcome");

gtk_widget_destroy(windowwelcome);
gtk_widget_show(windowconnexion);


}


void
on_ButtonInscrire_clicked              (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowwelcome, *windowinscri;

windowinscri=create_WindowInscription();
windowwelcome=lookup_widget(windowauthen,"WindowWelcome");

gtk_widget_destroy(windowwelcome);
gtk_widget_show(windowinscri);
}


void
on_ButtonRetour_clicked                (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowwelcome, *windowinscri;

windowwelcome=create_WindowWelcome();
windowinscri=lookup_widget(windowauthen,"WindowInscription");

gtk_widget_destroy(windowinscri);
gtk_widget_show(windowwelcome);
}


void
on_ButtonInscri_clicked                (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *labelverif, *labelexiste, *labelsuccess, *entrynom, *entryprenom, *entryusername, *entrypassword, *entryrole;
Inscrit I;
  
int jour,mois,annee=1;

//labels
labelverif=lookup_widget(windowauthen,"labelinscriptionerreur");
labelexiste=lookup_widget(windowauthen,"labelexisteinscrit");
labelsuccess=lookup_widget(windowauthen,"labelinscrit");

//entries
entrynom=lookup_widget(windowauthen,"EntryNom");
entryprenom=lookup_widget(windowauthen,"EntryPrenom");
entryusername=lookup_widget(windowauthen,"EntryUsername");
entrypassword=lookup_widget(windowauthen,"EntryPassword");
entryrole=lookup_widget(windowauthen,"comboboxentryrole");

//Récuperation du nom & controle de saisie
strcpy(I.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
if(strcmp(I.nom,"")==0){
gtk_widget_show(labelverif);
}
else
{
gtk_widget_set_visible(labelverif,FALSE);
}

//Récuperation du prenom & controle de saisie
strcpy(I.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
if(strcmp(I.prenom,"")==0){

gtk_widget_show(labelverif);
}
else
{

gtk_widget_set_visible(labelverif,FALSE);
}
//Récuperation du username & controle de saisie
strcpy(I.username, gtk_entry_get_text(GTK_ENTRY(entryusername)));
if(strcmp(I.username,"")==0){

gtk_widget_show(labelverif);
}
else
{

gtk_widget_set_visible(labelverif,FALSE);
}
//Récuperation du password & controle de saisie
strcpy(I.password, gtk_entry_get_text(GTK_ENTRY(entrypassword)));
if(strcmp(I.password,"")==0){

gtk_widget_show(labelverif);
}
else
{

gtk_widget_set_visible(labelverif,FALSE);
}

//Récuperation de la date
gtk_calendar_get_date(GTK_CALENDAR(lookup_widget(windowauthen,"calendardate")),
                       &annee,
                       &mois,
                       &jour);
//Récuperation du role
strcpy(I.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));


if(gtk_widget_get_visible(labelverif)==FALSE){
	if(inscrit_exist(I.username,I.password)==1){
	gtk_widget_set_visible(labelsuccess,FALSE);
	gtk_widget_show(labelexiste);
	}else{
	ajouter_inscrit(I,jour,mois,annee);
	
	gtk_widget_set_visible(labelexiste,FALSE);
	gtk_widget_show(labelsuccess);
	gtk_entry_set_text(GTK_ENTRY(entrynom),"");
	gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
	gtk_entry_set_text(GTK_ENTRY(entryusername),"");
	gtk_entry_set_text(GTK_ENTRY(entrypassword),"");
	}
}
}


void
on_Buttonlogin_clicked                 (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *username, *password,  *windowprop, *windowutil, *windowouv, *windowconnexion,*fail;
Inscrit I;
username=lookup_widget(windowauthen,"entryuser");
password=lookup_widget(windowauthen,"entrypass");
fail=lookup_widget(windowauthen,"labelfaillogin");
strcpy(I.username,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(I.password,gtk_entry_get_text(GTK_ENTRY(password)));
if (inscrit_exist(I.username,I.password)==1) {
	if (prop_exist(I.username,I.password)==1)
	{
	windowprop=create_WindowProprietaire();
	windowconnexion=lookup_widget(windowauthen,"WindowConnexion");
	gtk_widget_destroy(windowconnexion);
	gtk_widget_show(windowprop);
	}
	if (utilinscrit_exist(I.username,I.password)==1)
	{
	windowutil=create_WindowUtilisateur();
	windowconnexion=lookup_widget(windowauthen,"WindowConnexion");
	gtk_widget_destroy(windowconnexion);
	gtk_widget_show(windowutil);
	}
	if (ouvinscrit_exist(I.username,I.password)==1) 
	{
	windowouv=create_WindowOuvrier();
	windowconnexion=lookup_widget(windowauthen,"WindowConnexion");
	gtk_widget_destroy(windowconnexion);
	gtk_widget_show(windowouv);
	}
	}
else
{
gtk_widget_show(fail);
}

}


void
on_ButtonReturn_clicked                (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowwelcome, *windowconnexion;

windowwelcome=create_WindowWelcome();
windowconnexion=lookup_widget(windowauthen,"WindowConnexion");

gtk_widget_destroy(windowconnexion);
gtk_widget_show(windowwelcome);
}


void
on_ButtonQuitp_clicked                 (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowprop, *windowconnexion;

windowconnexion=create_WindowConnexion();
windowprop=lookup_widget(windowauthen,"WindowProprietaire");

gtk_widget_destroy(windowprop);
gtk_widget_show(windowconnexion);
}


void
on_ButtonGestiondesutilisateurs_clicked
                                        (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowprop, *windowutil, *p;
windowutil=create_WindowGestiondesutilisateurs();
windowprop=lookup_widget(windowauthen,"WindowProprietaire");
//mise àjour du tree
p=lookup_widget(windowutil,"treeviewutil")
;
AfficherUtilisateur(p,"utilisateurs.txt");

gtk_widget_destroy(windowprop);
gtk_widget_show(windowutil);
}


void
on_ButtonGestiondescapteurs_clicked    (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondesequipements_clicked
                                        (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondesouvriers_clicked    (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondesclients_clicked     (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondestroupeaux_clicked   (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_ButtonGestionducalendrier_clicked   (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_buttonAjoututil_clicked             (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *labelcin, *labelnom, *labelprenom, *labelverif, *labelexiste, *labelsuccess, *entrycin, *entrynom, *entryprenom, *entryage;
Utilisateur U;
  
int jour,mois,annee=1;

//labels
labelcin=lookup_widget(windowauthen,"labelcin");
labelnom=lookup_widget(windowauthen,"labelnomuti");
labelprenom=lookup_widget(windowauthen,"labelprenomutil");
labelverif=lookup_widget(windowauthen,"labelverifutil");
labelexiste=lookup_widget(windowauthen,"labelexiste");
labelsuccess=lookup_widget(windowauthen,"labelsuccess");
//entries
entrycin=lookup_widget(windowauthen,"entrycinutil");
entrynom=lookup_widget(windowauthen,"entrynomutil");
entryprenom=lookup_widget(windowauthen,"entryprenomutil");
entryage=lookup_widget(windowauthen,"spinbuttonutil");

//Récuperation du cin & controle de saisie
strcpy(U.cin, gtk_entry_get_text(GTK_ENTRY(entrycin)));
if(strcmp(U.cin,"")==0){
gtk_widget_show(labelcin);
gtk_widget_show(labelverif);
}
else
{
gtk_widget_set_visible(labelcin,FALSE);
gtk_widget_set_visible(labelverif,FALSE);
}
//Récuperation du nom & controle de saisie
strcpy(U.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
if(strcmp(U.nom,"")==0){
gtk_widget_show(labelnom);
gtk_widget_show(labelverif);
}
else
{
gtk_widget_set_visible(labelnom,FALSE);
gtk_widget_set_visible(labelverif,FALSE);
}

//Récuperation du prenom & controle de saisie
strcpy(U.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
if(strcmp(U.prenom,"")==0){
gtk_widget_show(labelprenom);
gtk_widget_show(labelverif);
}
else
{
gtk_widget_set_visible(labelprenom,FALSE);
gtk_widget_set_visible(labelverif,FALSE);
}
//Récuperation de la valeur
U.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryage));

//Récuperation de la date
gtk_calendar_get_date(GTK_CALENDAR(lookup_widget(windowauthen,"calendarutilisateur")),
                       &annee,
                       &mois,
                       &jour);



if(gtk_widget_get_visible(labelcin)==FALSE && gtk_widget_get_visible(labelnom)==FALSE && gtk_widget_get_visible(labelprenom)==FALSE && gtk_widget_get_visible(labelverif)==FALSE){
	if(utilisateur_exist(U.cin)==1){
	gtk_widget_set_visible(labelsuccess,FALSE);
	gtk_widget_show(labelexiste);
	}else{
	ajouter_utilisateur(U,jour,mois,annee);
	GtkWidget* p1=lookup_widget(windowauthen,"treeviewutil");
	AfficherUtilisateur(p1,"utilisateurs.txt");
	gtk_widget_set_visible(labelexiste,FALSE);
	gtk_widget_show(labelsuccess);
	gtk_entry_set_text(GTK_ENTRY(entrycin),"");
	gtk_entry_set_text(GTK_ENTRY(entrynom),"");
	gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryage),20);}
}
}


void
on_treeviewutil_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ButtonSupprimer_clicked             (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
	GtkTreeSelection *selection;
        GtkTreeModel  *model;
        GtkTreeIter iter;
        GtkWidget *p;
        GtkWidget *suc, *echec;
        gchar* cin;
        suc=lookup_widget(windowauthen,"labelsuccesssup");
	echec=lookup_widget(windowauthen,"labelfailsupp");
        p=lookup_widget(windowauthen,"treeviewutil");
	gtk_widget_set_visible(suc,FALSE);
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_widget_set_visible(echec,FALSE);
		gtk_tree_model_get (model,&iter,0,&cin,-1);
		gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

		supprimer_utilisateur(cin);// supprimer la ligne du fichier

           	gtk_widget_show(suc);
		}
	else
	{
		gtk_widget_show(echec);		
	}
}


void
on_buttonrecherche_clicked             (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *p, *success, *fail, *entrycin;
gchar *cin;
entrycin=lookup_widget(windowauthen,"entrycinutilrecherche");
cin=gtk_entry_get_text(GTK_ENTRY(entrycin));
p=lookup_widget(windowauthen,"treeviewutil");
success=lookup_widget(windowauthen,"labeltrouve");
fail=lookup_widget(windowauthen,"labelerreur");
if(strcmp(cin,"")==0){
AfficherUtilisateur(p,"utilisateurs.txt");
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(fail);
}
else{
chercher_utilisateur(cin);
AfficherUtilisateur(p,"utilisateurs_recherche.txt");
gtk_widget_set_visible(fail,FALSE);
gtk_widget_show(success);
}
}


void
on_buttonQuitutilisateur_clicked       (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowprop, *windowutil, *p;
windowprop=create_WindowProprietaire();
windowutil=lookup_widget(windowauthen,"WindowGestiondesutilisateurs");
//mise àjour du tree
p=lookup_widget(windowauthen,"treeviewutil");
AfficherUtilisateur(p,"utilisateurs.txt");
gtk_widget_destroy(windowutil);
gtk_widget_show(windowprop);
}


void
on_buttonGestiondesequipements_clicked
                                        (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_buttonGestiondescapteurs_clicked    (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_buttonGestiondesouvriers_clicked    (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_buttonGestiondesclients_clicked     (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_buttonGestiondestroupeaux_clicked   (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_buttonGestionducalendrier_clicked   (GtkWidget *windowauthen,
                                        gpointer         user_data)
{

}


void
on_ButtonQuitu_clicked                 (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowutil, *windowconnexion;
windowconnexion=create_WindowConnexion();
windowutil=lookup_widget(windowauthen,"WindowUtilisateur");
gtk_widget_destroy(windowutil);
gtk_widget_show(windowconnexion);
}


void
on_buttonmarquer_clicked               (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *username, *password, *entryabs, *marquer, *fail;
Absence A;
username=lookup_widget(windowauthen,"entryuserouvrier");
password=lookup_widget(windowauthen,"entrypasswordouvrier");
entryabs=lookup_widget(windowauthen,"comboboxentryouvrier");
marquer=lookup_widget(windowauthen,"labelmarquer");
fail=lookup_widget(windowauthen,"failmarquer");
strcpy(A.username,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(A.password,gtk_entry_get_text(GTK_ENTRY(password)));
strcpy(A.absence,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryabs)));
if (inscrit_exist(A.username,A.password)==1) {
ajouter_absence(A);
gtk_widget_set_visible(fail,FALSE);
gtk_widget_show(marquer);
}
else
{
gtk_widget_set_visible(marquer,FALSE);
gtk_widget_show(fail);
}
}


void
on_buttonQuitouvrier_clicked           (GtkWidget *windowauthen,
                                        gpointer         user_data)
{
GtkWidget *windowouv, *windowconnexion;
windowconnexion=create_WindowConnexion();
windowouv=lookup_widget(windowauthen,"WindowOuvrier");
gtk_widget_destroy(windowouv);
gtk_widget_show(windowconnexion);

}

