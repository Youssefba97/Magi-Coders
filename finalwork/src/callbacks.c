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
#include "capteurs.h"
#include "fonction.h"
#include "client.h"
#include "equip.h"
#include "tree1.h"
#include "troupeau.h"
#include "auth.h"
#include "functions.h"
#include "tree2.h"
char SeasonChoice[50];
int Id_To_Modify; 
int i,j,k;
GtkWidget *eqag;
GtkWidget *treeaff;
GtkWidget *eg;
GtkWidget *output;



void
on_ButtonGestiondescapteurs_clicked    (GtkWidget *windowcap,
                                        gpointer         user_data)
{
GtkWidget *p, *p1, *p2, *p3;
GtkWidget *windowdash, *windowcapteur;

windowcapteur= create_WindowGestiondescapteurs();


p=lookup_widget(windowcapteur,"treeview1");
p1=lookup_widget(windowcapteur,"TreeViewAffichageAlarmante");
p2=lookup_widget(windowcapteur,"treeview2");
p3=lookup_widget(windowcapteur,"treeview3");

Capteurtree(p,"capteurs.txt");
Alarmantetree(p1,"alarmantes.txt");
ChercherCapteur(p2,"capteurs.txt");
Defectueuxtree(p3,"defectueux.txt");


windowdash=lookup_widget(windowcap,"WindowDashboard");

gtk_widget_hide(windowdash);
gtk_widget_show(windowcapteur);


}


void
on_ButtonGestiondesouvriers_clicked    (GtkWidget *button,
                                        gpointer         user_data)
{
GtkWidget *p,  *p2 ,*p3;
GtkWidget *windowdash, *windowouvrier;

windowouvrier= create_gestionouvriers();


p=lookup_widget(windowouvrier,"treeviewi1");

p2=lookup_widget(windowouvrier,"treeviewi2");
p3=lookup_widget(windowouvrier,"treeviewi3");

Afficherouvrier(p,"users.txt");

Afficherouvrier1(p2,"users.txt");
afficherabsence(p3,"absenteisme.txt");



windowdash=lookup_widget(button,"WindowDashboard");

gtk_widget_hide(windowdash);
gtk_widget_show(windowouvrier);
}


void
on_ButtonGestiondes__quipements_clicked
                                        (GtkWidget *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash, *windowequipements;

windowequipements= create_gequipements();



windowdash=lookup_widget(button,"WindowDashboard");

gtk_widget_hide(windowdash);
gtk_widget_show(windowequipements);
}


void
on_ButtonGestiondesclients_clicked     (GtkWidget *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash, *windowclient;

windowclient= create_gclients();



windowdash=lookup_widget(button,"WindowDashboard");

gtk_widget_hide(windowdash);
gtk_widget_show(windowclient);
}


void
on_ButtonGestiondestroupeaux_clicked   (GtkWidget *button,
                                        gpointer         user_data)
{
GtkWidget *p,  *p2;
GtkWidget *windowdash, *eq;

eq= create_gtroupeaux();


p=lookup_widget(eq,"treeview5");

p2=lookup_widget(eq,"treeview7");


AfficherAnimal(p,"troupeau.txt");

AfficherRechercheAnimal(p2,"troupeau.txt");



windowdash=lookup_widget(button,"WindowDashboard");

gtk_widget_hide(windowdash);
gtk_widget_show(eq);
}


void
on_ButtonGestionducalendrier_clicked   (GtkWidget *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash, *windowcalendrier;

windowcalendrier= create_CalendarMain();



windowdash=lookup_widget(button,"WindowDashboard");

gtk_widget_hide(windowdash);
gtk_widget_show(windowcalendrier);
}


void
on_ButtonQuit_clicked                  (GtkWidget *windowcap,
                                        gpointer         user_data)
{
GtkWidget *p, *p1, *p2, *p3;
GtkWidget *windowdash, *windowcapteur;
windowcapteur=lookup_widget(windowcap,"WindowGestiondescapteurs");
windowdash= create_WindowDashboard();
p=lookup_widget(windowcapteur,"treeview1");
Capteurtree(p,"capteurs.txt");
p1=lookup_widget(windowcapteur,"TreeViewAffichageAlarmante");
Alarmantetree(p1,"alarmantes.txt");
p2=lookup_widget(windowcapteur,"treeview2");
ChercherCapteur(p2,"capteurs.txt");
p3=lookup_widget(windowcapteur,"treeview3");
Defectueuxtree(p3,"defectueux.txt");
gtk_widget_destroy(windowcapteur);
gtk_widget_show(windowdash);
}


void
on_ButtonAjouter_clicked               (GtkWidget *windowcap,
                                        gpointer         user_data)
{
GtkWidget *id, *mar, *pos, *entryid, *entrymar, *entrypos, *entryty, *entryetat, *entryval, *fail, *success, *verif, *p, *p1, *p2, *p3;
Capteur C;

//les labels
id=lookup_widget(windowcap,"labelid");
mar=lookup_widget(windowcap,"labelma");
pos=lookup_widget(windowcap,"labelpos");
success=lookup_widget(windowcap,"labelsucess");
fail=lookup_widget(windowcap,"labelfail");
verif=lookup_widget(windowcap,"labelverif");

//entries
entryid=lookup_widget(windowcap,"EntryIdentifiant");
entrymar=lookup_widget(windowcap,"EntryMarque");
entrypos=lookup_widget(windowcap,"EntryPosition");
entryetat=lookup_widget(windowcap,"spinbuttonetat");
entryval=lookup_widget(windowcap,"spinbuttonvaleur");
entryty=lookup_widget(windowcap,"ComboBoxEntryType");

//Récuperation de l'identifiant & controle de saisie
strcpy(C.identifiant, gtk_entry_get_text(GTK_ENTRY(entryid)));
if(strcmp(C.identifiant,"")==0){
gtk_widget_show(id);
gtk_widget_show(verif);
}
else
{
gtk_widget_set_visible(id,FALSE);
gtk_widget_set_visible(verif,FALSE);
}

//Récuperation de la marque & controle de saisie
strcpy(C.marque, gtk_entry_get_text(GTK_ENTRY(entrymar)));
if(strcmp(C.marque,"")==0){
gtk_widget_show(mar);
gtk_widget_show(verif);
}
else
{
gtk_widget_set_visible(mar,FALSE);
gtk_widget_set_visible(verif,FALSE);
}
//Récuperation de la position & controle de saisie
strcpy(C.position, gtk_entry_get_text(GTK_ENTRY(entrypos)));
if(strcmp(C.position,"")==0){
gtk_widget_show(pos);
gtk_widget_show(verif);
}
else
{
gtk_widget_set_visible(pos,FALSE);
gtk_widget_set_visible(verif,FALSE);
}
//Récuperation du type 
strcpy(C.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryty)));
//Récuperation de la valeur
C.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryval));

//Récuperation de l'état
C.etat=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryetat));



if(gtk_widget_get_visible(id)==FALSE && gtk_widget_get_visible(mar)==FALSE && gtk_widget_get_visible(pos)==FALSE && gtk_widget_get_visible(verif)==FALSE){
	if(capteur_exist(C.identifiant)==1){
	gtk_widget_set_visible(success,FALSE);
	gtk_widget_show(fail);
	}	
	else{
	ajouter_capteur(C);
	//mise à jour du treeview
	p=lookup_widget(windowcap,"treeview1");
	Capteurtree(p,"capteurs.txt");
	p1=lookup_widget(windowcap,"TreeViewAffichageAlarmante");
	Alarmantetree(p1,"alarmantes.txt");
	p2=lookup_widget(windowcap,"treeview2");
	ChercherCapteur(p2,"capteurs.txt");
	p3=lookup_widget(windowcap,"treeview3");
	Defectueuxtree(p3,"defectueux.txt");
	//bien ajouté 
	gtk_widget_set_visible(fail,FALSE);
	gtk_widget_show(success);
	//vider les champs après ajout
	gtk_entry_set_text(GTK_ENTRY(entryid),"");
	gtk_entry_set_text(GTK_ENTRY(entrymar),"");
	gtk_entry_set_text(GTK_ENTRY(entrypos),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryetat),1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryval),0);
	}
}
}


void
on_ButtonSupprimer_clicked             (GtkWidget *windowcap,
                                        gpointer         user_data)
{
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p,*p1, *p2, *p3;
        GtkWidget *suc, *echec;
        gchar* id;
        suc=lookup_widget(windowcap,"labelsucess1");
	echec=lookup_widget(windowcap,"labelfail1");
        p=lookup_widget(windowcap,"treeview1");
	gtk_widget_set_visible(suc,FALSE);
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_widget_set_visible(echec,FALSE);
		gtk_tree_model_get (model,&iter,0,&id,-1);
		gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

		supprimer_capteur(id);// supprimer la ligne du fichier

           	gtk_widget_show(suc);
		p1=lookup_widget(windowcap,"TreeViewAffichageAlarmante");
		Alarmantetree(p1,"alarmantes.txt");
		p2=lookup_widget(windowcap,"treeview2");
		ChercherCapteur(p2,"capteurs.txt");
		p3=lookup_widget(windowcap,"treeview3");
		Defectueuxtree(p3,"defectueux.txt");}
	else
	{
		gtk_widget_show(echec);		
	}
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ButtonModifier_clicked              (GtkWidget *windowcap,
                                        gpointer         user_data)
{
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* id;
GtkWidget *entryid, *entrymar, *entrypos, *ty, *entryetat, *entryval, *fail, *success, *select, *verif1, *p, *p1, *p2, *p3;
Capteur C;

//les labels
success=lookup_widget(windowcap,"labelsuccess2");
fail=lookup_widget(windowcap,"labelfail2");
select=lookup_widget(windowcap,"labelselection");
verif1=lookup_widget(windowcap,"labelverif1");
//entries
entryid=lookup_widget(windowcap,"EntryId1");
entrymar=lookup_widget(windowcap,"EntryMa1");
entrypos=lookup_widget(windowcap,"EntryPos1");
entryetat=lookup_widget(windowcap,"spinbuttoneta");
entryval=lookup_widget(windowcap,"spinbuttonval");
ty=lookup_widget(windowcap,"ComboBoxEntryt1");

//Récuperation de l'identifiant & controle de saisie
strcpy(C.identifiant, gtk_entry_get_text(GTK_ENTRY(entryid)));
if(strcmp(C.identifiant,"")==0){
gtk_widget_show(verif1);
}
else
{
gtk_widget_set_visible(verif1,FALSE);
}

//Récuperation de la marque & controle de saisie
strcpy(C.marque, gtk_entry_get_text(GTK_ENTRY(entrymar)));
if(strcmp(C.marque,"")==0){
gtk_widget_show(verif1);
}
else
{
gtk_widget_set_visible(verif1,FALSE);
}
//Récuperation de la position & controle de saisie
strcpy(C.position, gtk_entry_get_text(GTK_ENTRY(entrypos)));
if(strcmp(C.position,"")==0){
gtk_widget_show(verif1);
}
else
{
gtk_widget_set_visible(verif1,FALSE);
}
//Récuperation de la valeur
C.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryval));

//Récuperation de l'état
C.etat=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryetat));

//Récuperation du type
strcpy(C.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));

if(gtk_widget_get_visible(verif1)==FALSE){
	p=lookup_widget(windowcap,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_widget_set_visible(select,FALSE);
		gtk_tree_model_get (model,&iter,0,&id,-1);
		if(capteur_exist(C.identifiant)==1 && strcmp(C.identifiant,id)!=0){
		gtk_widget_set_visible(success,FALSE);
		gtk_widget_show(fail);
		}
		else
		{
		modifier_capteur(C,id);
		//mise à jour du treeview
		Capteurtree(p,"capteurs.txt");
		p1=lookup_widget(windowcap,"TreeViewAffichageAlarmante");
		Alarmantetree(p1,"alarmantes.txt");
		p2=lookup_widget(windowcap,"treeview2");
		ChercherCapteur(p2,"capteurs.txt");
		p3=lookup_widget(windowcap,"treeview3");
		Defectueuxtree(p3,"defectueux.txt");
		//bien modifié
		gtk_widget_set_visible(fail,FALSE);
		gtk_widget_show(success);
		//vider les champs après modification
		gtk_entry_set_text(GTK_ENTRY(entryid),"");
		gtk_entry_set_text(GTK_ENTRY(entrymar),"");
		gtk_entry_set_text(GTK_ENTRY(entrypos),"");
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryetat),1);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryval),0);
		}
	}
	else{
	gtk_widget_show(select);
	}
}
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}


void
on_ButtonRechercher_clicked            (GtkWidget *windowcap,
                                        gpointer         user_data)
{

GtkWidget *p, *success, *fail, *id;
gchar *identifiant;
id=lookup_widget(windowcap,"EntryId2");
identifiant=gtk_entry_get_text(GTK_ENTRY(id));
p=lookup_widget(windowcap,"treeview2");
success=lookup_widget(windowcap,"labelsucess3");
fail=lookup_widget(windowcap,"labelfail3");
if(strcmp(identifiant,"")==0){
ChercherCapteur(p,"capteurs.txt");
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(fail);
}
else{
chercher_capteur(identifiant);
ChercherCapteur(p,"capteurs_recherche.txt");
gtk_widget_set_visible(fail,FALSE);
gtk_widget_show(success);
}
}


void
on_TreeViewAffichageAlarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ajouteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *entrycin, *entrynom, *entryprenom, *entrynumtel, *entrysalaire, *entrysexe, *CIN, *NOM, *PRENOM, *TEL ,*success , *fail , *p ,*p2 ,*p3 , *p4; 

ouvrier o ;
absenteisme a ;
a.absjan =0;
a.absfev =0;
a.absmar =0;
a.absav=0;
a.absmai=0;
a.absjuin=0;
a.absjuil=0;
a.absaout=0;
a.abssept=0;
a.absoct=0;
a.absnov=0;
a.absdec=0; 
p=lookup_widget(button,"treeviewi1");
p3=lookup_widget(button,"treeviewi2");
p4=lookup_widget(button,"treeviewi3");
//entries
entrycin=lookup_widget(button,"entrycini");
entrynom=lookup_widget(button,"entrynomi");
entryprenom=lookup_widget(button,"entryprenomi");
entrynumtel=lookup_widget(button,"entryteli");
entrysalaire=lookup_widget(button,"spinbuttonsalaire");
entrysexe=lookup_widget(button,"comboboxsexe");


//labels

CIN=lookup_widget(button,"cini");
NOM=lookup_widget(button,"nomi");
PRENOM=lookup_widget(button,"prenomi");
TEL=lookup_widget(button,"teli");
fail=lookup_widget(button,"labelexiste");
success=lookup_widget(button,"label11");

//récuperation des données 

strcpy(o.cin, gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(o.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(a.cin, gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(a.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(o.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(o.tel, gtk_entry_get_text(GTK_ENTRY(entrynumtel)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));
o.salaire=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrysalaire));

//controle de saisie 
if(strcmp(o.cin,"")==0){
gtk_widget_show(CIN);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(CIN,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(strcmp(o.nom,"")==0){
gtk_widget_show(NOM);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(NOM,FALSE);
gtk_widget_set_visible(success,FALSE);

}

if(strcmp(o.prenom,"")==0){
gtk_widget_show(PRENOM);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(PRENOM,FALSE);
gtk_widget_set_visible(success,FALSE);
}

if(strcmp(o.tel,"")==0){
gtk_widget_show(TEL);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(TEL,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(gtk_widget_get_visible(CIN)==FALSE && gtk_widget_get_visible(NOM)==FALSE && gtk_widget_get_visible(PRENOM)==FALSE && gtk_widget_get_visible(TEL)==FALSE){
         if(exist(o.cin)==1){
	gtk_widget_set_visible(success,FALSE);
	gtk_widget_show(fail);
        Afficherouvrier (p,"users.txt");
        Afficherouvrier1(p3,"users.txt");
        afficherabsence(p4,"absenteisme.txt");
}
       

 else {

	
         ajouter(o,a);
         //bien ajouté 
	gtk_widget_set_visible(fail,FALSE);
	gtk_widget_show(success);
	//vider les champs après ajout
	gtk_entry_set_text(GTK_ENTRY(entrycin),"");
	gtk_entry_set_text(GTK_ENTRY(entrynom),"");
	gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
        gtk_entry_set_text(GTK_ENTRY(entrynumtel),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrysalaire),500);
        //mise à jour du treeview 
       p2=lookup_widget(button,"treeviewi1");
	Afficherouvrier(p2,"users.txt");
        Afficherouvrier1(p3,"users.txt");
        afficherabsence(p4,"absenteisme.txt");}
}

}


void
on_modifieri2_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* cin;
GtkWidget *entrynom, *entryprenom, *entrytel, *entrysexe, *entrysalaire, *success,  *p , *p2;
ouvrier ov;

//les labels
success=lookup_widget(button,"succesi");

//entries

entrynom=lookup_widget(button,"entrynomi1");
entryprenom=lookup_widget(button,"entryprnomi1");
entrytel=lookup_widget(button,"entryteli1");
entrysalaire=lookup_widget(button,"spinbuttonsalaire2");
entrysexe=lookup_widget(button,"comboboxsexe2");



//Récuperation 
strcpy(ov.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));


strcpy(ov.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(ov.tel, gtk_entry_get_text(GTK_ENTRY(entrytel)));
ov.salaire=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrysalaire));
strcpy(ov.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));

         p2=lookup_widget(button,"treeviewi2");
	p=lookup_widget(button,"treeviewi1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		
                gtk_tree_model_get (model,&iter,0,&cin,-1);
                modifier(ov, cin );
		//mise à jour du treeview
		Afficherouvrier(p,"users.txt");
                Afficherouvrier1(p2,"users.txt");
		
		//bien modifié
		
		gtk_widget_show(success);
		//vider les champs après modification
		gtk_entry_set_text(GTK_ENTRY(entrynom),"");
		gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
		gtk_entry_set_text(GTK_ENTRY(entrytel),"");
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrysalaire),500);
		
		}


}


void
on_supprimeri1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p1  , *p2;
        gchar* cin;

        p1=lookup_widget(button,"treeviewi1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

          supprimer(cin);
          p2=lookup_widget(button,"treeviewi2");
          Afficherouvrier1(p2,"users.txt");
        }



}


void
on_chercheri_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char nom[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(button,"entrynomi2");
labelnom=lookup_widget(button,"labelnomii");
p1=lookup_widget(button,"treeviewi2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(nom,"")==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{

nb=Chercherouvrier(p1,"users.txt",nom);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(button,"nbi");
message=lookup_widget(button,"messageresi");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);

}


}


void
on_quitteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowdash, *windowouvrier;
windowouvrier=lookup_widget(button,"gestionouvriers");
windowdash= create_WindowDashboard();

gtk_widget_destroy(windowouvrier);
gtk_widget_show(windowdash);

}


void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(c.sexe,"femme");
}


void
on_checkbuttongtroupeaux_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[0]=1;
	}
		else 
	{
			 contrat[0]=0;
	}
}


void
on_checkbuttongcalendrier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[1]=1;
	}
	else 
	{
			 contrat[1]=0;
	}
}


void
on_checkbuttongequipement_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[3]=1;
	}
		else 
	{
			 contrat[3]=0;
	}
}


void
on_radiobuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(c.sexe,"homme");
}


void
on_checkbuttongouvrier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[2]=1;
	}
		else 
	{

			 contrat[2]=0;}

}


void
on_buttonajouetyo_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cin, *nom, *prenom,  *sexe, *service, *tel, *mail,*success,*nomx ,  *prenomx , *cinx , *telx , *mailx ;

client c ;
cinx=lookup_widget(button,"cinyo");
nomx=lookup_widget(button,"nomyo");
prenomx=lookup_widget(button,"prenomyo");
telx=lookup_widget(button,"telyo");
mailx=lookup_widget(button,"mailyo");
cin = lookup_widget (button, "entrycinyo");
nom = lookup_widget (button, "entrynomyo");
prenom = lookup_widget (button, "entryprenomyo");
tel = lookup_widget (button, "entrytelyo");
mail = lookup_widget (button, "entrymailyo");
success=lookup_widget(button,"labelsuccessyo");

strcpy(c.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));

if(strcmp(c.cin,"")==0){
gtk_widget_show(cinx);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(cinx,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(strcmp(c.nom,"")==0){
gtk_widget_show(nomx);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(nomx,FALSE);
gtk_widget_set_visible(success,FALSE);

}

if(strcmp(c.prenom,"")==0){
gtk_widget_show(prenomx);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(prenomx,FALSE);
gtk_widget_set_visible(success,FALSE);
}

if(strcmp(c.tel,"")==0){
gtk_widget_show(telx);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(telx,FALSE);
gtk_widget_set_visible(success,FALSE);

}

if(strcmp(c.mail,"")==0){
gtk_widget_show(mailx);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(mailx,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if( gtk_widget_get_visible(cinx)==FALSE && gtk_widget_get_visible(nomx)==FALSE && gtk_widget_get_visible(prenomx)==FALSE && gtk_widget_get_visible(telx)==FALSE && gtk_widget_get_visible(mailx)==FALSE){
resultContrat();
ajouterClient();
	strcpy(c.service,"");

gtk_widget_show(success);}
}


void
on_radiobuttonfemme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tempo.sexe,"femme");
}




void
on_checkbuttoncalendrier1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[1]=1;
	}
		else 
	{
	 contrat[1]=0;
	}
}


void
on_checkbuttongequipement1_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[3]=1;
	}
		else 
	{
			 contrat[3]=0;
	}
}


void
on_buttonaffdonyo_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cin, *cinSearch, *nom, *prenom,  *sexe, *service, *tel, *mail;

		
		cinSearch = lookup_widget (button, "entrycinyo1");

		cin = lookup_widget (button, "entrycinyo2");
		nom = lookup_widget (button, "entrynomyo1");
		prenom = lookup_widget (button, "entryprenomyo1");
		tel = lookup_widget (button, "entrytelyo1");
		mail = lookup_widget (button, "entrymailyo1");


		if(chercherClient(gtk_entry_get_text(GTK_ENTRY(cinSearch))))
		{
			gtk_entry_set_text(GTK_ENTRY( cin ),c.cin);
			gtk_entry_set_text(GTK_ENTRY( nom ),c.nom);
			gtk_entry_set_text(GTK_ENTRY( prenom ),c.prenom);
			gtk_entry_set_text(GTK_ENTRY( tel ),c.tel);
			gtk_entry_set_text(GTK_ENTRY( mail ),c.mail);
		}
		else
		{
			gtk_entry_set_text(GTK_ENTRY( cin ),"not found");
			gtk_entry_set_text(GTK_ENTRY( nom ),"not found");
			gtk_entry_set_text(GTK_ENTRY( prenom ),"not found");
			gtk_entry_set_text(GTK_ENTRY( tel ),"not found");
			gtk_entry_set_text(GTK_ENTRY( mail ),"not found");
		}
}


void
on_buttonsupprimeryo_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

	  GtkWidget *cinDeleteP , *success;
          success=lookup_widget(button,"labelsuccessyo2");


  	cinDeleteP = lookup_widget(button, "entrycinyo3") ;
  	strcpy(cinDelete,gtk_entry_get_text(GTK_ENTRY(cinDeleteP)));
	supprimerClient(cinDelete);

       gtk_widget_show(success);
}


void
on_buttonquitteryo_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash, *windowclient;
windowclient=lookup_widget(button,"gclients");
windowdash= create_WindowDashboard();

gtk_widget_destroy(windowclient);
gtk_widget_show(windowdash);
}


void
on_buttonmodifieryo_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cin, *cinSearch, *nom, *prenom,  *sexe, *service, *tel, *mail,*success;

		success=lookup_widget(button,"labelsuccessyo2");
		cinSearch = lookup_widget (button, "entrycinyo1");

		cin = lookup_widget (button, "entrycinyo2");
		nom = lookup_widget (button, "entrynomyo1");
		prenom = lookup_widget (button, "entryprenomyo1");
		tel = lookup_widget (button, "entrytelyo1");
		mail = lookup_widget (button, "entrymailyo1");


		strcpy(tempo.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
		strcpy(tempo.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
		strcpy(tempo.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
		strcpy(tempo.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
		strcpy(tempo.mail, gtk_entry_get_text(GTK_ENTRY(mail)));

		resultContratModif();
		modifierClient(gtk_entry_get_text(GTK_ENTRY(cinSearch)));
		strcpy(c.service,"");
                 gtk_widget_show(success);

}


void
on_radiobuttonhomme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
strcpy(tempo.sexe,"homme");
}


void
on_checkbuttongtroupeau1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[0]=1;
	}
		else 
	{
			 contrat[0]=0;
	}
}




void
on_buttonafficheryo_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowliste_client ;
GtkWidget *treeview4;
windowliste_client=lookup_widget(button,"gclients");
treeview4=lookup_widget(windowliste_client,"treeview4");
afficherClient(treeview4);
}


void
on_checkbuttongouvrier1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{
	 contrat[2]=1;
	}
		else 
	{
			 contrat[2]=0;
	}
}




void
on_buttonactualiserye_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet, "gequipements");
gtk_widget_destroy(eqag);
eqag=create_gequipements();
gtk_widget_show(eqag);
}


void
on_buttonafficherye_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

treeaff=lookup_widget(button,"treeview5");
afficher_equipement(treeaff);
}


void
on_buttonsupprimerye_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *nom, *emsref, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *etat, *outpout;
  equipement e;
char ref[9];
int suppri;
  FILE* f;

  emsref=lookup_widget(objet, "entryrefye");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
   
   outpout=lookup_widget (objet,"errye");
   suppri=supprimer_equipement(e,ref);
  if (suppri==1)
   {
  gtk_label_set_text (GTK_LABEL(outpout),"equipement supprimé");
	
   }

}


void
on_buttonchercherye_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *emsref, *nom, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *etat;
  equipement e;
  char ref[9] ;
 

  
  emsref=lookup_widget(objet, "entryrefye1");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
  
  e=rechercher(ref);

  FILE* f;
  f=fopen("equip.txt","r");
 
  nom=lookup_widget (objet,"entrynomye1");
  marque=lookup_widget (objet,"entrymarqueye1");
  jour=lookup_widget (objet,"spinbuttonjourachat1");
  mois=lookup_widget (objet,"spinbuttonmoisachat1");
  annee=lookup_widget (objet,"spinbuttonannéeachat1");
  jourm=lookup_widget (objet,"spinbuttonjourmaint1");
  moism=lookup_widget (objet,"spinbuttonmoismaint1");
  anneem=lookup_widget (objet,"spinbuttonannéemaint1");
  etat=lookup_widget (objet,"entryetatye");
  gtk_entry_set_text (GTK_ENTRY(emsref),e.ref);
  gtk_entry_set_text (GTK_ENTRY(nom),e.nom);
  gtk_entry_set_text (GTK_ENTRY(marque),e.marque);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),e.jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),e.mois);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),e.annee);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(jourm),e.jourm);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(moism),e.moism);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(anneem),e.anneem);
  gtk_entry_set_text (GTK_ENTRY(etat),e.etat);
  
  
  

  
  fclose(f);
}


void
on_buttonmodifierye_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *emsref, *nom, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *etat;
  equipement e1;
  char ref[9] ;
 

  
  emsref=lookup_widget(objet, "entryrefye1");
  strcpy(ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
  
  e1=rechercher(ref);

  FILE* f;
  f=fopen("equip.txt","r");
 
  nom=lookup_widget (objet,"entrynomye1");
  marque=lookup_widget (objet,"entrymarqueye1");
  jour=lookup_widget (objet,"spinbuttonjourachat1");
  mois=lookup_widget (objet,"spinbuttonmoisachat1");
  annee=lookup_widget (objet,"spinbuttonannéeachat1");
  jourm=lookup_widget (objet,"spinbuttonjourmaint1");
  moism=lookup_widget (objet,"spinbuttonmoismaint1");
  anneem=lookup_widget (objet,"spinbuttonannéemaint1");
  etat=lookup_widget (objet,"entryetatye");
  
strcpy(e1.ref,gtk_entry_get_text(GTK_ENTRY(emsref)));
strcpy(e1.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(e1.marque,gtk_entry_get_text(GTK_ENTRY(marque)));
strcpy(e1.etat,gtk_entry_get_text(GTK_ENTRY(etat)));



e1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
e1.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
e1.jourm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourm));
e1.moism=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moism));
e1.anneem=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneem));




  modifier_equipement(e1);
  fclose(f);
}


void
on_buttonajouterye_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
equipement e;

GtkWidget *ref, *nom, *marque, *jour, *mois, *annee, *jourm, *moism, *anneem, *bon, *def;

eqag=lookup_widget(objet, "equipement");

ref=lookup_widget(objet, "entryrefye");
nom=lookup_widget(objet, "entrynomye");
marque=lookup_widget(objet, "entrymarqueye");
jour=lookup_widget(objet, "spinbuttonjourachat");
mois=lookup_widget(objet, "spinbuttonmoisachat");
annee=lookup_widget(objet, "spinbuttonannéeachat");
jourm=lookup_widget(objet, "spinbuttonajourmaint");
moism=lookup_widget(objet, "spinbuttonamoismaint");
anneem=lookup_widget(objet, "spinbuttonannéemaint");
bon=lookup_widget(objet, "radiobuttonabon");
def=lookup_widget(objet, "radiobuttonadef");

strcpy(e.ref,gtk_entry_get_text(GTK_ENTRY(ref)));
strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(e.marque,gtk_entry_get_text(GTK_ENTRY(marque)));

e.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
e.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
e.jourm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourm));
e.moism=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moism));
e.anneem=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneem));

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(bon)))
	{strcpy(e.etat,"bonne_etat");}
else	{strcpy(e.etat,"defectueux");}

ajouter_equipement(e);
}


void
on_buttonactualiserye1_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet, "gequipements");
gtk_widget_destroy(eqag);
eqag=create_gequipements();
gtk_widget_show(eqag);
}


void
on_buttonactualiseye2_clicked          (GtkButton       *objet,
                                        gpointer         user_data)
{
eqag=lookup_widget(objet, "gequipements");
gtk_widget_destroy(eqag);
eqag=create_gequipements();
gtk_widget_show(eqag);
}


void
on_buttonquitterye_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash, *windowequipements;
windowequipements=lookup_widget(button,"gequipements");
windowdash= create_WindowDashboard();

gtk_widget_destroy(windowequipements);
gtk_widget_show(windowdash);
}


void
on_buttonajouterm_clicked              (GtkButton       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{
GtkWidget *labelId, *labelType, *labelSexe, *labelEtat, *labelDate, *existe, *success, *identifiantEntry, *typeCombo, *sexeCombo, *spinButton;
Troupeau troupeau;
  char nombreBrebis[30];
  char nombreVeaux[30];
  int nbBrebis,nbVeaux;


int jour,mois,annee,pass=1;

//Labels
labelId=lookup_widget(window_gestion_troupeau_mb,"idm");
labelType=lookup_widget(window_gestion_troupeau_mb,"typem");
labelSexe=lookup_widget(window_gestion_troupeau_mb,"sexem");

existe=lookup_widget(window_gestion_troupeau_mb,"existem");
success=lookup_widget(window_gestion_troupeau_mb,"successm");

//Entries
identifiantEntry=GTK_ENTRY(lookup_widget(window_gestion_troupeau_mb,"entryidm"));
typeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"comboboxtypem"));
sexeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"comboboxsexem"));
spinButton=GTK_SPIN_BUTTON(lookup_widget(window_gestion_troupeau_mb,"spinbuttonetatm"));




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
gtk_calendar_get_date(GTK_CALENDAR(lookup_widget(window_gestion_troupeau_mb,"calendarm")),
                       &annee,
                       &mois,
                       &jour);



if(gtk_widget_get_visible(labelId)==FALSE && gtk_widget_get_visible(labelType)==FALSE && gtk_widget_get_visible(labelSexe)==FALSE){
if(animal_exist(troupeau.identifiant)==1){
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(existe);
}else{
ajouter_animal(troupeau,jour,mois,annee);
GtkWidget* p1=lookup_widget(window_gestion_troupeau_mb,"treeview6");
AfficherAnimal(p1,"troupeau.txt");
GtkWidget* p2=lookup_widget(window_gestion_troupeau_mb,"treeview7");
AfficherRechercheAnimal(p2,"troupeau.txt");
gtk_widget_set_visible(existe,FALSE);
gtk_widget_show(success);
gtk_entry_set_text(identifiantEntry,"");
//supporté par la version GTK 2.4
//gtk_combo_box_set_active_id(sexeCombo,-1);
gtk_spin_button_set_value(spinButton,1);
  GtkWidget* p3=lookup_widget(window_gestion_troupeau_mb,"labelnbveaux");
  GtkWidget* p4=lookup_widget(window_gestion_troupeau_mb,"labelnbbrebis");
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
on_buttonmodifierm_clicked             (GtkButton       *window_gestion_troupeau_mb,
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
labelId=lookup_widget(window_gestion_troupeau_mb,"idm1");
labelType=lookup_widget(window_gestion_troupeau_mb,"typem1");
labelSexe=lookup_widget(window_gestion_troupeau_mb,"sexem1");

existe=lookup_widget(window_gestion_troupeau_mb,"existem1");
success=lookup_widget(window_gestion_troupeau_mb,"successm1");
labelSelection=lookup_widget(window_gestion_troupeau_mb,"selectm1");


//Entries
identifiantEntry=GTK_ENTRY(lookup_widget(window_gestion_troupeau_mb,"entryidma"));
typeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"comboboxtypem1"));
sexeCombo=GTK_COMBO_BOX(lookup_widget(window_gestion_troupeau_mb,"comboboxsexem1"));
spinButton=GTK_SPIN_BUTTON(lookup_widget(window_gestion_troupeau_mb,"spinbuttonetatm1"));




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
gtk_calendar_get_date(GTK_CALENDAR(lookup_widget(window_gestion_troupeau_mb,"calendarm1")),
                       &annee,
                       &mois,
                       &jour);



if(gtk_widget_get_visible(labelId)==FALSE && gtk_widget_get_visible(labelType)==FALSE && gtk_widget_get_visible(labelSexe)==FALSE){






        p1=lookup_widget(window_gestion_troupeau_mb,"treeview6");
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
        p2=lookup_widget(window_gestion_troupeau_mb,"treeview7");
           AfficherRechercheAnimal(p2,"troupeau.txt");
gtk_widget_set_visible(existe,FALSE);
gtk_widget_show(success);
gtk_entry_set_text(identifiantEntry,"");
gtk_spin_button_set_value(spinButton,1);
  GtkWidget* p3=lookup_widget(window_gestion_troupeau_mb,"labelnbveaux");
  GtkWidget* p4=lookup_widget(window_gestion_troupeau_mb,"labelnbbrebis");
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
on_buttonsupprimerm_clicked            (GtkButton       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p1, *p2;
        gchar* identifiant;

        p1=lookup_widget(window_gestion_troupeau_mb,"treeview6");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&identifiant,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_animal(identifiant);// supprimer la ligne du fichier
        p2=lookup_widget(window_gestion_troupeau_mb,"treeview7");
           AfficherRechercheAnimal(p2,"troupeau.txt");
}

}
void
on_buttonchercherm_clicked             (GtkButton       *window_gestion_troupeau_mb,
                                        gpointer         user_data)
{
GtkWidget *p;
gchar *identifiant;
identifiant=gtk_entry_get_text(GTK_ENTRY(lookup_widget(window_gestion_troupeau_mb,"entryidm2")));

p=lookup_widget(window_gestion_troupeau_mb,"treeview7");
if(strcmp(identifiant,"")==0){
AfficherRechercheAnimal(p,"troupeau.txt");
}else{
chercher_animal(identifiant);
AfficherRechercheAnimal(p,"troupeau_recherche.txt");
}
}


void
on_buttonquitterm_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash, *windowtroupeau;
windowtroupeau=lookup_widget(button,"gtroupeaux");
windowdash= create_WindowDashboard();

gtk_widget_destroy(windowtroupeau);
gtk_widget_show(windowdash);
}


void
on_buttonconnexion_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char nom[30] , mdp[30] , role [30];
GtkWidget *existe , *entrynom , *entrymdp , *entryrole;
GtkWidget *windowadmin, *auth , *windowdash;
auth=lookup_widget(button,"auth");
existe=lookup_widget(auth,"existef1");
entrynom=lookup_widget(auth,"entrynomf1");
entrymdp=lookup_widget(auth,"entrymdpf1");
entryrole=lookup_widget(auth,"comboboxentryf");
strcpy(nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(mdp, gtk_entry_get_text(GTK_ENTRY(entrymdp)));
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));
if (strcmp(nom,"admin")==0 && strcmp(mdp,"admin123")==0 && strcmp(role,"administrateur")==0){
windowadmin=create_admin();
gtk_widget_destroy(auth);
gtk_widget_show(windowadmin);}
else { if  ( verifierutilisateur(nom,mdp) == 1 &&  strcmp(role,"utilisateur")==0 ){
windowdash= create_WindowDashboard();

gtk_widget_destroy(auth);

gtk_widget_show(windowdash);}
else {gtk_widget_show(existe);}
}
}


void
on_buttongutilisateur_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadmin , *windowutilisateur ;
windowutilisateur=create_gutilisateurs();
windowadmin=lookup_widget(button,"admin");
gtk_widget_destroy(windowadmin);
gtk_widget_show(windowutilisateur);
}


void
on_buttontdb_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadmin , *windowdash;
windowadmin=lookup_widget(button,"admin");
windowdash= create_WindowDashboard();
gtk_widget_destroy(windowadmin);
gtk_widget_show(windowdash);
}


void
on_buttondeco1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowauth , *windowadmin ;
windowadmin=lookup_widget(button,"admin");
windowauth=create_auth();
gtk_widget_destroy(windowadmin);
gtk_widget_show(windowauth);
}


void
on_buttondeco_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowdash , *windowauth ;
windowdash=lookup_widget(button,"WindowDashboard");
windowauth=create_auth();
gtk_widget_destroy(windowdash);
gtk_widget_show(windowauth);
}


void
on_buttonajouterf_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *existe , *success , *erreur , *entrynom , *entrymdp ;
char nom[30] , mdp [30];
//label
existe=lookup_widget(button,"existef");
success=lookup_widget(button,"successf");
erreur=lookup_widget(button,"erreurf");
//entries
entrynom=lookup_widget(button,"entrynomf");
entrymdp=lookup_widget(button,"entrymdpf");

strcpy(nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
if(strcmp(nom,"")==0){
gtk_widget_show(erreur);

}
else
{
gtk_widget_set_visible(erreur,FALSE);

}
strcpy(mdp, gtk_entry_get_text(GTK_ENTRY(entrymdp)));
if(strcmp(mdp,"")==0){
gtk_widget_show(erreur);

}
else
{
gtk_widget_set_visible(erreur,FALSE);

}
if(gtk_widget_get_visible(erreur)==FALSE ){
	if(verifierutilisateur(nom,mdp)==1){
	gtk_widget_set_visible(success,FALSE);
	gtk_widget_show(existe);
	}	
	else{
	ajouterutilisateur(nom,mdp);
	
	//bien ajouté 
	gtk_widget_set_visible(existe,FALSE);
	gtk_widget_show(success);
	//vider les champs après ajout
	gtk_entry_set_text(GTK_ENTRY(entrynom),"");
	gtk_entry_set_text(GTK_ENTRY(entrymdp),"");
	
	}
}
}


void
on_buttonquitterf_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowadmin , *windowutilisateur ;
windowadmin=create_admin();
windowutilisateur=lookup_widget(button,"gutilisateurs");
gtk_widget_destroy(windowutilisateur);
gtk_widget_show(windowadmin);
}


void
on_ButtonDeleteSP_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;
	messageFE=lookup_widget(CheckCalendar,"LabelSpEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSpDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSpDelS");
	
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSpring");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));

        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewSpring");
	SpringTreeView(newTree,"calendrier.txt");

	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);

        }
	
	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}
}


void
on_ButtonEditSP_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelSpEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSpDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSpDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSpring");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;
	
			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);

	CheckCal=lookup_widget(CheckCalendar,"CheckCalendar");
	EditPlant = create_EditPlant ();


	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);

        }
	
	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}
}


void
on_ButtonEditSU_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelSmEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSmDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSmDelS");


	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSummer");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;	

			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);
		
	CheckCal=lookup_widget(CheckCalendar,"CheckCalendar");
	EditPlant = create_EditPlant ();

		
	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);
	}

	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}
}


void
on_ButtonDeleteSU_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelSmEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSmDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSmDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSummer");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewSummer");
	SummerTreeView(newTree,"calendrier.txt");
	
	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}

	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}


}


void
on_ButtonEditAU_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelAuEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelAuDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelAuDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewAutumn");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;	

			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);
		
	CheckCal=lookup_widget(CheckCalendar,"CheckCalendar");
	EditPlant = create_EditPlant ();

		
	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);
	}

	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}

}


void
on_ButtonDeleteAU_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelAuEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelAuDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelAuDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewAutumn");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewAutumn");
	AutumnTreeView(newTree,"calendrier.txt");

	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}


	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}
}


void
on_ButtonEditWI_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelWEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelWDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelWDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewWinter");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;	


			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);

		
	CheckCal=lookup_widget(CheckCalendar,"treeviewWinter");
	EditPlant = create_EditPlant ();

		
	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);
	}

	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}
}


void
on_ButtonDeleteWI_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelWEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelWDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelWDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewWinter");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewWinter");
	WinterTreeView(newTree,"calendrier.txt");

	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}

	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
}	
}


void
on_ExitButton2_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CheckCalendar;	
	GtkWidget *windowMain;		


		
	CheckCalendar=lookup_widget(button,"CheckCalendar");
	windowMain = create_CalendarMain ();

		
	gtk_widget_destroy (CheckCalendar);	
	gtk_widget_show (windowMain);
}


void
on_GoToCheckCalendar_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f =NULL;
	f=fopen("calendrier.txt","a+");

	//preparing the treeview

	GtkWidget *spring;
	GtkWidget *summer;
	GtkWidget *autumn;
	GtkWidget *winter;

	//accessing destination window
	GtkWidget *windowCheckCal;
	windowCheckCal=create_CheckCalendar ();

	//creating treeview
	spring=lookup_widget(windowCheckCal,"treeviewSpring");
	summer=lookup_widget(windowCheckCal,"treeviewSummer");
	autumn=lookup_widget(windowCheckCal,"treeviewAutumn");
	winter=lookup_widget(windowCheckCal,"treeviewWinter");

	SpringTreeView(spring,"calendrier.txt");
	SummerTreeView(summer,"calendrier.txt");
	AutumnTreeView(autumn,"calendrier.txt");
	WinterTreeView(winter,"calendrier.txt");
	
	fclose(f);

	GtkWidget *CalendarMain;
	CalendarMain=lookup_widget(button,"CalendarMain");

	gtk_widget_destroy (CalendarMain);
	gtk_widget_show (windowCheckCal);
}


void
on_GoToAddNewPlant_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAdd;
	GtkWidget *CalendarMain;

	CalendarMain=lookup_widget(button,"CalendarMain");
	windowAdd = create_ChoosePlant ();

	gtk_widget_destroy (CalendarMain);
	gtk_widget_show (windowAdd);
}


void
on_ExitButton1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *CalendarMain , *windowdash;
	CalendarMain=lookup_widget(button,"CalendarMain");
       windowdash= create_WindowDashboard();
	gtk_widget_destroy (CalendarMain);
       

gtk_widget_show(windowdash);
}


void
on_ExitButton3_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ChoosePlant;	
	GtkWidget *windowMain;		

		
	ChoosePlant=lookup_widget(button,"ChoosePlant");
	windowMain = create_CalendarMain ();

		
	gtk_widget_destroy (ChoosePlant);	
	gtk_widget_show (windowMain);
}


void
on_RadioSpring_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice , "printemps");}
}


void
on_RadioSummer_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice, "été");}
}


void
on_RadioAutumn_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice, "automne");}
}


void
on_RadioWinter_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice , "hiver");}
}


void
on_ConfirmPlantButton_clicked          (GtkButton       *ChoosePlant,
                                        gpointer         user_data)
{
GtkWidget *plant,*cal1, *cal2,*messageFR,*messageFC,*messageS ;
	Calendarr C;
	int proceed =1;

	//setting up the labels for the errors
	messageFR=lookup_widget(ChoosePlant,"LabelErrorRadio");
	messageFC=lookup_widget(ChoosePlant,"LabelErrorCheckbox");
	messageS=lookup_widget(ChoosePlant,"LabelSuccessAdd");

	//declaring variables
	int id,j1,j2,m1,m2,a1,a2;
	char dateEnc[20];
	char dateRec[20];

	//this function counts how many lines there are in the file, this way, it gives a unique Id to each new entry
	id = countLines();

		//body of the add algorythm

	//getting values from the window
	plant=lookup_widget(ChoosePlant,"comboboxentry1");
	cal1=lookup_widget(ChoosePlant,"calendarPlanting");
	cal2=lookup_widget(ChoosePlant,"calendarHarvesting");

	gtk_calendar_get_date(GTK_CALENDAR(cal1),&a1,&m1,&j1);
	gtk_calendar_get_date(GTK_CALENDAR(cal2),&a2,&m2,&j2);

	snprintf(dateEnc, 20, "%d%s%d%s%d", j1, "/",m1+1,"/",a1);
	snprintf(dateRec, 20, "%d%s%d%s%d", j2, "/",m2+1,"/",a2);

	C.identifier=id;

	//setting up error messages

		//checking if radio isnt empty
	if (strcmp(SeasonChoice,"")==0)
	{
		gtk_widget_show (messageFR);
		gtk_widget_set_visible(messageFC,FALSE);
		gtk_widget_set_visible(messageS,FALSE);
		proceed = -1;
	}
	
	else
	{
		strcpy(C.plante,gtk_combo_box_get_active_text(GTK_COMBO_BOX(plant)));

		if (strcmp(C.plante,"")==0)
		{
			gtk_widget_show (messageFC);
			gtk_widget_set_visible(messageFR,FALSE);
			gtk_widget_set_visible(messageS,FALSE);
			proceed = -1;
		}

		else
		{
			strcpy(C.saison,SeasonChoice);
			strcpy(C.encem,dateEnc);
			strcpy(C.rec,dateRec);
		}
	}

	



	//writing in file if all checks are successful
	
	if(proceed==1)
	{
		AddNewPlant(C);
		
		//display of success message, while hiding previous error messages
		gtk_widget_show (messageS);
		gtk_widget_set_visible(messageFR,FALSE);
		gtk_widget_set_visible(messageFC,FALSE);
	}
}


void
on_ReturnToCalendar_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
//preparing the treeview

	GtkWidget *spring;
	GtkWidget *summer;
	GtkWidget *autumn;
	GtkWidget *winter;

	//accessing destination window
	GtkWidget *windowCheckCal;
	windowCheckCal = create_CheckCalendar ();

	//creating treeview
	spring=lookup_widget(windowCheckCal,"treeviewSpring");
	summer=lookup_widget(windowCheckCal,"treeviewSummer");
	autumn=lookup_widget(windowCheckCal,"treeviewAutumn");
	winter=lookup_widget(windowCheckCal,"treeviewWinter");

	SpringTreeView(spring,"calendrier.txt");
	SummerTreeView(summer,"calendrier.txt");
	AutumnTreeView(autumn,"calendrier.txt");
	WinterTreeView(winter,"calendrier.txt");


	GtkWidget *ChoosePlant;
	ChoosePlant=lookup_widget(button,"ChoosePlant");

	gtk_widget_destroy (ChoosePlant);
	gtk_widget_show (windowCheckCal);
}


void
on_buttonReturnCal_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
//preparing the treeview

	GtkWidget *spring;
	GtkWidget *summer;
	GtkWidget *autumn;
	GtkWidget *winter;

	//accessing destination window
	GtkWidget *windowCheckCal;
	windowCheckCal = create_CheckCalendar ();

	//creating treeview
	spring=lookup_widget(windowCheckCal,"treeviewSpring");
	summer=lookup_widget(windowCheckCal,"treeviewSummer");
	autumn=lookup_widget(windowCheckCal,"treeviewAutumn");
	winter=lookup_widget(windowCheckCal,"treeviewWinter");

	SpringTreeView(spring,"calendrier.txt");
	SummerTreeView(summer,"calendrier.txt");
	AutumnTreeView(autumn,"calendrier.txt");
	WinterTreeView(winter,"calendrier.txt");


	GtkWidget *EditPlant;
	EditPlant=lookup_widget(button,"EditPlant");

	gtk_widget_destroy (EditPlant);
	gtk_widget_show (windowCheckCal);
}


void
on_ButtonConfirmEdit_clicked           (GtkButton       *EditPlant,
                                        gpointer         user_data)
{
GtkWidget *message;
	message=lookup_widget(EditPlant,"LabelSuccessEdit");

	GtkWidget *cal1, *cal2 ;
	Dates date;

	int id,j1,j2,m1,m2,a1,a2;
	char dateEnc[20];
	char dateRec[20];

	cal1=lookup_widget(EditPlant,"calendarEditPlanting");
	cal2=lookup_widget(EditPlant,"calendarEditHarvesting");

	gtk_calendar_get_date(GTK_CALENDAR(cal1),&a1,&m1,&j1);
	gtk_calendar_get_date(GTK_CALENDAR(cal2),&a2,&m2,&j2);

	snprintf(dateEnc, 20, "%d%s%d%s%d", j1, "/",m1+1,"/",a1);
	snprintf(dateRec, 20, "%d%s%d%s%d", j2, "/",m2+1,"/",a2);

	strcpy(date.date1,dateEnc);
	strcpy(date.date2,dateRec);
	

	EditPlantingDate(Id_To_Modify,date);

	
	gtk_widget_show(message);
}


void
on_ExitButton5_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *EditPlant;	
	GtkWidget *windowMain;		


		
	EditPlant=lookup_widget(button,"EditPlant");
	windowMain = create_CalendarMain ();

		
	gtk_widget_destroy (EditPlant);	
	gtk_widget_show (windowMain);
}


void
on_buttonmarqueri_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* cin;
GtkWidget *entrymois, *prst,  *p ;
absenteisme a;
char mois[30], presence[30];


p=lookup_widget(button,"treeviewi3");
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		
                gtk_tree_model_get (model,&iter,0,&cin,-1);}
recuperer(a,cin);

prst=lookup_widget(button,"comboboxentry4");
entrymois=lookup_widget(button,"comboboxmoisi");



strcpy(mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrymois)));
strcpy(presence,gtk_combo_box_get_active_text(GTK_COMBO_BOX(prst)));


if (strcmp (presence,"absent(e)")==0 && strcmp(mois,"Janvier")==0 ){
          
                a.absjan= a.absjan+1;}


else  {a.absjan=a.absjan;} 



if(  strcmp (presence,"absent(e)")==0       &&  strcmp(mois,"Fevrier")==0)
               {a.absfev=a.absfev+1;}


else {a.absfev=a.absfev;}
 



if(strcmp (presence,"absent(e)")==0   && strcmp(mois,"Mars")==0)
                              {a.absmar=a.absmar+1;}
else 

         {a.absmar=a.absmar;}
     

if (strcmp (presence,"absent(e)")==0 && strcmp(mois,"Avril")==0)
                      {a.absav=a.absav+1;}

      else 
                 {a.absav=a.absav;}

 

if(strcmp (presence,"absent(e)")==0   && strcmp(mois,"Mai")==0)
               {a.absmai=a.absmai+1;}
else       
               {a.absmai=a.absmai;}


if(strcmp (presence,"absent(e)")==0     && strcmp(mois,"Juin")==0)
               {a.absjuin=a.absjuin+1;}

else       {a.absjuin=a.absjuin;}

if(strcmp (presence,"absent(e)")==0    && strcmp(mois,"Juillet")==0)
               {a.absjuil=a.absjuil + 1 ;}

else
             {a.absjuil=a.absjuil;}

if(strcmp (presence,"absent(e)")==0         && strcmp(mois,"Aout")==0)

               {a.absaout=a.absaout+1;} 

else                {a.absaout=a.absaout;} 
             
 
if(strcmp (presence,"absent(e)")==0    && strcmp(mois,"Septembre")==0)
               {a.abssept=a.abssept+1;} 
    
else     {a.abssept=a.abssept ;}

if(strcmp (presence,"absent(e)")==0  &&  strcmp(mois,"October")==0)
               {a.absoct=a.absoct+1;}
else             {a.absoct=a.absoct;}

if(strcmp (presence,"absent(e)")==0      &&  strcmp(mois,"Novembre")==0)
               {a.absnov=a.absnov+1;}
else     {a.absnov=a.absnov;}


if(strcmp (presence,"absent(e)")==0   && strcmp(mois,"Decembre")==0)
               {a.absdec=a.absdec+1;}
else 
                    {a.absdec=a.absdec;}



         
	
        
                
                marquer(a, cin );
		//mise à jour du treeview
		
		afficherabsence(p,"absenteisme.txt");
		
		
}


