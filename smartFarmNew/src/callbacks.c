#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "client.h"

void
on_buttonAnnuler__clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbuttonGestionOuv_toggled       (GtkToggleButton *togglebutton,
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
on_checkbuttonGestionEqui_toggled      (GtkToggleButton *togglebutton,
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
on_radiobuttonSexeFemme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	strcpy(c.sexe,"femme");
}


void
on_checkbuttonGestionTr_toggled        (GtkToggleButton *togglebutton,
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
on_checkbuttonGestionPl_toggled        (GtkToggleButton *togglebutton,
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
on_radiobuttonSexeHomme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	strcpy(c.sexe,"homme");
}


void
on_buttonConfirm_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{	 	
GtkWidget *cin, *nom, *prenom,  *sexe, *service, *tel, *mail,*windowInscriValid__e, *windowInscriValide;



cin = lookup_widget (button, "entryCin");
nom = lookup_widget (button, "entryNom");
prenom = lookup_widget (button, "entryPrenom");
tel = lookup_widget (button, "entryTel");
mail = lookup_widget (button, "entryMail");


strcpy(c.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(c.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(c.mail, gtk_entry_get_text(GTK_ENTRY(mail)));


//Récuperation de la CIN et controle de saisie
strcpy(C.cin,gtk_entry_get_text(EntryCin));
if(strcmp(C.cin,"")==0){
 gtk_widget_show(labelXCin);}
else{
gtk_widget_set_visible(labelXCin,FALSE);
}

//Récuperation de la Nom et controle de saisie
strcpy(C.Nom,gtk_entry_get_text(EntryNom));
if(strcmp(C.Nom,"")==0){
 gtk_widget_show(labelXNom);}
else{
gtk_widget_set_visible(labelXNom,FALSE);
}

//Récuperation de la Prenom et controle de saisie
strcpy(C.Prenom,gtk_entry_get_text(EntryPrenom));
if(strcmp(C.Prenom,"")==0){
 gtk_widget_show(labelXPrenom);}
else{
gtk_widget_set_visible(labelXPrenom,FALSE);
}

//Récuperation de la Tel et controle de saisie
strcpy(C.Tel,gtk_entry_get_text(EntryTel));
if(strcmp(C.Tel,"")==0){
 gtk_widget_show(labelXTel);}
else{
gtk_widget_set_visible(labelXTel,FALSE);
}

//Récuperation de la Mail et controle de saisie
strcpy(C.Mail,gtk_entry_get_text(EntryMail));
if(strcmp(C.Mail,"")==0){
 gtk_widget_show(labelXMail);}
else{
gtk_widget_set_visible(labelXMail,FALSE);
}

resultContrat();
ajouterClient();
	strcpy(c.service,"");


windowInscriValid__e = create_windowInscriValid__e ();
  gtk_widget_show (windowInscriValid__e);
}



void
on_buttonAfficherModif_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
		GtkWidget *cin, *cinSearch, *nom, *prenom,  *sexe, *service, *tel, *mail;

		
		cinSearch = lookup_widget (button, "entryCinModifSearch");

		cin = lookup_widget (button, "entryCinModif");
		nom = lookup_widget (button, "entryNomModif");
		prenom = lookup_widget (button, "entryPrenomModif");
		tel = lookup_widget (button, "entryTelModif");
		mail = lookup_widget (button, "entryMailModif");


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
on_buttonModifier_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
		GtkWidget *cin, *cinSearch, *nom, *prenom,  *sexe, *service, *tel, *mail,*windowModifValid__e, *windowInscriValide;

		
		cinSearch = lookup_widget (button, "entryCinModifSearch");
		
		cin = lookup_widget (button, "entryCinModif");
		nom = lookup_widget (button, "entryNomModif");
		prenom = lookup_widget (button, "entryPrenomModif");
		tel = lookup_widget (button, "entryTelModif");
		mail = lookup_widget (button, "entryMailModif");

		strcpy(tempo.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
		strcpy(tempo.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
		strcpy(tempo.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
		strcpy(tempo.tel, gtk_entry_get_text(GTK_ENTRY(tel)));
		strcpy(tempo.mail, gtk_entry_get_text(GTK_ENTRY(mail)));

		resultContratModif();
		modifierClient(gtk_entry_get_text(GTK_ENTRY(cinSearch)));
		strcpy(c.service,"");


		  windowModifValid__e = create_windowModifValid__e ();
  		  gtk_widget_show (windowModifValid__e);
}


void
on_checkbuttonPlantationModif_toggled  (GtkToggleButton *togglebutton,
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
on_checkbuttonEquipModif_toggled       (GtkToggleButton *togglebutton,
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
on_radiobuttonHommeModif_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		strcpy(tempo.sexe,"homme");
}


void
on_radiobuttonFemmeModif_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	strcpy(tempo.sexe,"femme");
}


void
on_checkbuttonTroupModif_toggled       (GtkToggleButton *togglebutton,
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
on_buttonSupprimer_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
	  GtkWidget *cinDeleteP , *windowSuppValid__e;



  	cinDeleteP = lookup_widget(button, "entrySupprimer") ;
  	strcpy(cinDelete,gtk_entry_get_text(GTK_ENTRY(cinDeleteP)));
	supprimerClient(cinDelete);


	  windowSuppValid__e = create_windowSuppValid__e ();
  gtk_widget_show (windowSuppValid__e);

}



void
on_buttonAfficherListe_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *windowliste_client ;
GtkWidget *treeview1 ;
windowliste_client=lookup_widget(button,"windowSmartFarm");
treeview1=lookup_widget(windowliste_client,"treeview1");
afficherClient(treeview1);
}



void
on_checkbuttonOuvriersModif_toggled    (GtkToggleButton *togglebutton,
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



