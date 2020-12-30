/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_windowSmartFarm (void)
{
  GtkWidget *windowSmartFarm;
  GtkWidget *fixed1;
  GtkWidget *buttonQuitter;
  GtkWidget *alignment10;
  GtkWidget *hbox10;
  GtkWidget *image10;
  GtkWidget *label38;
  GtkWidget *notebook1;
  GtkWidget *fixedAjouter;
  GtkWidget *label9;
  GtkWidget *label10;
  GtkWidget *entryCin;
  GtkWidget *entryPrenom;
  GtkWidget *entryNom;
  GtkWidget *buttonAnnuler_;
  GtkWidget *alignment2;
  GtkWidget *hbox2;
  GtkWidget *image2;
  GtkWidget *label13;
  GtkWidget *entryTel;
  GtkWidget *entryMail;
  GtkWidget *label5;
  GtkWidget *label8;
  GtkWidget *label7;
  GtkWidget *label6;
  GtkWidget *label11;
  GtkWidget *label14;
  GtkWidget *radiobuttonSexeHomme;
  GSList *radiobuttonSexeHomme_group = NULL;
  GtkWidget *buttonConfirm;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *image1;
  GtkWidget *label12;
  GtkWidget *radiobuttonSexeFemme;
  GtkWidget *checkbuttonGestionTr;
  GtkWidget *checkbuttonGestionPl;
  GtkWidget *checkbuttonGestionOuv;
  GtkWidget *checkbuttonGestionEqui;
  GtkWidget *labelXPrenom;
  GtkWidget *labelXMail;
  GtkWidget *labelXNom;
  GtkWidget *labelXCin;
  GtkWidget *labelXTel;
  GtkWidget *label53;
  GtkWidget *labelAjouter;
  GtkWidget *fixedModif;
  GtkWidget *label16;
  GtkWidget *entryCinModifSearch;
  GtkWidget *entryPrenomModif;
  GtkWidget *entryNomModif;
  GtkWidget *label19;
  GtkWidget *label29;
  GtkWidget *label30;
  GtkWidget *label31;
  GtkWidget *label32;
  GtkWidget *entryCinModif;
  GtkWidget *entryTelModif;
  GtkWidget *label33;
  GtkWidget *entryMailModif;
  GtkWidget *label34;
  GtkWidget *hseparator1;
  GtkWidget *buttonAfficherModif;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label17;
  GtkWidget *radiobuttonHommeModif;
  GtkWidget *label15;
  GtkWidget *radiobuttonFemmeModif;
  GtkWidget *checkbuttonTroupModif;
  GtkWidget *checkbuttonPlantationModif;
  GtkWidget *checkbuttonOuvriersModif;
  GtkWidget *checkbuttonEquipModif;
  GtkWidget *buttonModifier;
  GtkWidget *alignment4;
  GtkWidget *hbox4;
  GtkWidget *image4;
  GtkWidget *label18;
  GtkWidget *labelVServiceM;
  GtkWidget *labelXTelM;
  GtkWidget *labelXEmailM;
  GtkWidget *labelXCinM;
  GtkWidget *labelXNomM;
  GtkWidget *labelXPrenomM;
  GtkWidget *labelXServiceM;
  GtkWidget *labelModifier;
  GtkWidget *fixed4;
  GtkWidget *entrySupprimer;
  GtkWidget *label35;
  GtkWidget *buttonSupprimer;
  GtkWidget *alignment8;
  GtkWidget *hbox8;
  GtkWidget *image8;
  GtkWidget *label36;
  GtkWidget *labelSupprimer;
  GtkWidget *fixed5;
  GtkWidget *treeview1;
  GtkWidget *buttonAfficherListe;
  GtkWidget *alignment11;
  GtkWidget *hbox11;
  GtkWidget *image11;
  GtkWidget *label42;
  GtkWidget *labelAfficherListe;

  windowSmartFarm = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (windowSmartFarm, 800, 800);
  gtk_window_set_title (GTK_WINDOW (windowSmartFarm), _("Smart farm"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (windowSmartFarm), fixed1);

  buttonQuitter = gtk_button_new ();
  gtk_widget_show (buttonQuitter);
  gtk_fixed_put (GTK_FIXED (fixed1), buttonQuitter, 640, 56);
  gtk_widget_set_size_request (buttonQuitter, 160, 56);

  alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment10);
  gtk_container_add (GTK_CONTAINER (buttonQuitter), alignment10);

  hbox10 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox10);
  gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

  image10 = gtk_image_new_from_stock ("gtk-stop", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image10);
  gtk_box_pack_start (GTK_BOX (hbox10), image10, FALSE, FALSE, 0);

  label38 = gtk_label_new_with_mnemonic (_("   Quitter"));
  gtk_widget_show (label38);
  gtk_box_pack_start (GTK_BOX (hbox10), label38, FALSE, FALSE, 0);

  notebook1 = gtk_notebook_new ();
  gtk_widget_show (notebook1);
  gtk_fixed_put (GTK_FIXED (fixed1), notebook1, 48, 136);
  gtk_widget_set_size_request (notebook1, 749, 597);

  fixedAjouter = gtk_fixed_new ();
  gtk_widget_show (fixedAjouter);
  gtk_container_add (GTK_CONTAINER (notebook1), fixedAjouter);

  label9 = gtk_label_new (_("Prenom :"));
  gtk_widget_show (label9);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label9, 56, 176);
  gtk_widget_set_size_request (label9, 81, 25);

  label10 = gtk_label_new (_("Nom :"));
  gtk_widget_show (label10);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label10, 64, 136);
  gtk_widget_set_size_request (label10, 81, 25);

  entryCin = gtk_entry_new ();
  gtk_widget_show (entryCin);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), entryCin, 136, 96);
  gtk_widget_set_size_request (entryCin, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryCin), 8226);

  entryPrenom = gtk_entry_new ();
  gtk_widget_show (entryPrenom);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), entryPrenom, 136, 176);
  gtk_widget_set_size_request (entryPrenom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryPrenom), 8226);

  entryNom = gtk_entry_new ();
  gtk_widget_show (entryNom);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), entryNom, 136, 136);
  gtk_widget_set_size_request (entryNom, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryNom), 8226);

  buttonAnnuler_ = gtk_button_new ();
  gtk_widget_show (buttonAnnuler_);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), buttonAnnuler_, 168, 480);
  gtk_widget_set_size_request (buttonAnnuler_, 128, 48);

  alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment2);
  gtk_container_add (GTK_CONTAINER (buttonAnnuler_), alignment2);

  hbox2 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox2);
  gtk_container_add (GTK_CONTAINER (alignment2), hbox2);

  image2 = gtk_image_new_from_stock ("gtk-undo", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox2), image2, FALSE, FALSE, 0);

  label13 = gtk_label_new_with_mnemonic (_("Annuler"));
  gtk_widget_show (label13);
  gtk_box_pack_start (GTK_BOX (hbox2), label13, FALSE, FALSE, 0);

  entryTel = gtk_entry_new ();
  gtk_widget_show (entryTel);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), entryTel, 424, 96);
  gtk_widget_set_size_request (entryTel, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryTel), 8226);

  entryMail = gtk_entry_new ();
  gtk_widget_show (entryMail);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), entryMail, 424, 136);
  gtk_widget_set_size_request (entryMail, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryMail), 8226);

  label5 = gtk_label_new (_("Ajouter un client"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label5, 272, 32);
  gtk_widget_set_size_request (label5, 169, 32);
  gtk_label_set_justify (GTK_LABEL (label5), GTK_JUSTIFY_CENTER);

  label8 = gtk_label_new (_("CIN :"));
  gtk_widget_show (label8);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label8, 66, 96);
  gtk_widget_set_size_request (label8, 81, 25);

  label7 = gtk_label_new (_("Sexe :"));
  gtk_widget_show (label7);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label7, 64, 216);
  gtk_widget_set_size_request (label7, 81, 25);

  label6 = gtk_label_new (_("Type de contrat :"));
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label6, 8, 256);
  gtk_widget_set_size_request (label6, 120, 32);

  label11 = gtk_label_new (_("N\302\260 Tel :"));
  gtk_widget_show (label11);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label11, 352, 96);
  gtk_widget_set_size_request (label11, 81, 25);

  label14 = gtk_label_new (_("E-mail :"));
  gtk_widget_show (label14);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label14, 352, 136);
  gtk_widget_set_size_request (label14, 81, 25);

  radiobuttonSexeHomme = gtk_radio_button_new_with_mnemonic (NULL, _("Homme"));
  gtk_widget_show (radiobuttonSexeHomme);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), radiobuttonSexeHomme, 136, 216);
  gtk_widget_set_size_request (radiobuttonSexeHomme, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobuttonSexeHomme), radiobuttonSexeHomme_group);
  radiobuttonSexeHomme_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobuttonSexeHomme));

  buttonConfirm = gtk_button_new ();
  gtk_widget_show (buttonConfirm);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), buttonConfirm, 384, 480);
  gtk_widget_set_size_request (buttonConfirm, 128, 48);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (buttonConfirm), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  image1 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox1), image1, FALSE, FALSE, 0);

  label12 = gtk_label_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (label12);
  gtk_box_pack_start (GTK_BOX (hbox1), label12, FALSE, FALSE, 0);

  radiobuttonSexeFemme = gtk_radio_button_new_with_mnemonic (NULL, _("Femme"));
  gtk_widget_show (radiobuttonSexeFemme);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), radiobuttonSexeFemme, 224, 216);
  gtk_widget_set_size_request (radiobuttonSexeFemme, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobuttonSexeFemme), radiobuttonSexeHomme_group);
  radiobuttonSexeHomme_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobuttonSexeFemme));

  checkbuttonGestionTr = gtk_check_button_new_with_mnemonic (_("Gestion des troupeaux "));
  gtk_widget_show (checkbuttonGestionTr);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), checkbuttonGestionTr, 160, 256);
  gtk_widget_set_size_request (checkbuttonGestionTr, 192, 32);

  checkbuttonGestionPl = gtk_check_button_new_with_mnemonic (_("Gestion du calendrier de\n plantation vegetale"));
  gtk_widget_show (checkbuttonGestionPl);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), checkbuttonGestionPl, 160, 288);
  gtk_widget_set_size_request (checkbuttonGestionPl, 192, 64);

  checkbuttonGestionOuv = gtk_check_button_new_with_mnemonic (_("Gestion des ouvriers"));
  gtk_widget_show (checkbuttonGestionOuv);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), checkbuttonGestionOuv, 160, 352);
  gtk_widget_set_size_request (checkbuttonGestionOuv, 192, 32);

  checkbuttonGestionEqui = gtk_check_button_new_with_mnemonic (_("Gestion des equipements"));
  gtk_widget_show (checkbuttonGestionEqui);
  gtk_fixed_put (GTK_FIXED (fixedAjouter), checkbuttonGestionEqui, 160, 400);
  gtk_widget_set_size_request (checkbuttonGestionEqui, 192, 32);

  labelXPrenom = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedAjouter), labelXPrenom, 304, 176);
  gtk_widget_set_size_request (labelXPrenom, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXPrenom), TRUE);

  labelXMail = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedAjouter), labelXMail, 584, 136);
  gtk_widget_set_size_request (labelXMail, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXMail), TRUE);

  labelXNom = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedAjouter), labelXNom, 304, 136);
  gtk_widget_set_size_request (labelXNom, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXNom), TRUE);

  labelXCin = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedAjouter), labelXCin, 304, 96);
  gtk_widget_set_size_request (labelXCin, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXCin), TRUE);

  labelXTel = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedAjouter), labelXTel, 584, 96);
  gtk_widget_set_size_request (labelXTel, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXTel), TRUE);

  label53 = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>Choisissez un type de contrat</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedAjouter), label53, 368, 256);
  gtk_widget_set_size_request (label53, 232, 32);
  gtk_label_set_use_markup (GTK_LABEL (label53), TRUE);

  labelAjouter = gtk_label_new (_("Ajouter"));
  gtk_widget_show (labelAjouter);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 0), labelAjouter);

  fixedModif = gtk_fixed_new ();
  gtk_widget_show (fixedModif);
  gtk_container_add (GTK_CONTAINER (notebook1), fixedModif);

  label16 = gtk_label_new (_("Modifier un client"));
  gtk_widget_show (label16);
  gtk_fixed_put (GTK_FIXED (fixedModif), label16, 200, 32);
  gtk_widget_set_size_request (label16, 241, 48);
  gtk_label_set_justify (GTK_LABEL (label16), GTK_JUSTIFY_CENTER);

  entryCinModifSearch = gtk_entry_new ();
  gtk_widget_show (entryCinModifSearch);
  gtk_fixed_put (GTK_FIXED (fixedModif), entryCinModifSearch, 152, 112);
  gtk_widget_set_size_request (entryCinModifSearch, 216, 40);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryCinModifSearch), 8226);

  entryPrenomModif = gtk_entry_new ();
  gtk_widget_show (entryPrenomModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), entryPrenomModif, 144, 296);
  gtk_widget_set_size_request (entryPrenomModif, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryPrenomModif), 8226);

  entryNomModif = gtk_entry_new ();
  gtk_widget_show (entryNomModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), entryNomModif, 144, 256);
  gtk_widget_set_size_request (entryNomModif, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryNomModif), 8226);

  label19 = gtk_label_new (_("Nom :"));
  gtk_widget_show (label19);
  gtk_fixed_put (GTK_FIXED (fixedModif), label19, 56, 256);
  gtk_widget_set_size_request (label19, 81, 25);

  label29 = gtk_label_new (_("CIN :"));
  gtk_widget_show (label29);
  gtk_fixed_put (GTK_FIXED (fixedModif), label29, 56, 216);
  gtk_widget_set_size_request (label29, 81, 25);

  label30 = gtk_label_new (_("Prenom :"));
  gtk_widget_show (label30);
  gtk_fixed_put (GTK_FIXED (fixedModif), label30, 48, 296);
  gtk_widget_set_size_request (label30, 81, 25);

  label31 = gtk_label_new (_("Sexe :"));
  gtk_widget_show (label31);
  gtk_fixed_put (GTK_FIXED (fixedModif), label31, 56, 336);
  gtk_widget_set_size_request (label31, 81, 25);

  label32 = gtk_label_new (_("Type de contrat :"));
  gtk_widget_show (label32);
  gtk_fixed_put (GTK_FIXED (fixedModif), label32, 0, 368);
  gtk_widget_set_size_request (label32, 120, 32);

  entryCinModif = gtk_entry_new ();
  gtk_widget_show (entryCinModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), entryCinModif, 144, 216);
  gtk_widget_set_size_request (entryCinModif, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryCinModif), 8226);

  entryTelModif = gtk_entry_new ();
  gtk_widget_show (entryTelModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), entryTelModif, 480, 216);
  gtk_widget_set_size_request (entryTelModif, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryTelModif), 8226);

  label33 = gtk_label_new (_("N\302\260 Tel :"));
  gtk_widget_show (label33);
  gtk_fixed_put (GTK_FIXED (fixedModif), label33, 400, 216);
  gtk_widget_set_size_request (label33, 81, 25);

  entryMailModif = gtk_entry_new ();
  gtk_widget_show (entryMailModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), entryMailModif, 480, 256);
  gtk_widget_set_size_request (entryMailModif, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entryMailModif), 8226);

  label34 = gtk_label_new (_("E-mail :"));
  gtk_widget_show (label34);
  gtk_fixed_put (GTK_FIXED (fixedModif), label34, 400, 256);
  gtk_widget_set_size_request (label34, 81, 25);

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_show (hseparator1);
  gtk_fixed_put (GTK_FIXED (fixedModif), hseparator1, 144, 168);
  gtk_widget_set_size_request (hseparator1, 512, 16);

  buttonAfficherModif = gtk_button_new ();
  gtk_widget_show (buttonAfficherModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), buttonAfficherModif, 392, 112);
  gtk_widget_set_size_request (buttonAfficherModif, 176, 40);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (buttonAfficherModif), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label17 = gtk_label_new_with_mnemonic (_("Afficher les donn\303\251es"));
  gtk_widget_show (label17);
  gtk_box_pack_start (GTK_BOX (hbox3), label17, FALSE, FALSE, 0);

  radiobuttonHommeModif = gtk_radio_button_new_with_mnemonic (NULL, _("Homme"));
  gtk_widget_show (radiobuttonHommeModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), radiobuttonHommeModif, 144, 336);
  gtk_widget_set_size_request (radiobuttonHommeModif, 88, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobuttonHommeModif), radiobuttonSexeHomme_group);
  radiobuttonSexeHomme_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobuttonHommeModif));

  label15 = gtk_label_new (_("CIN :"));
  gtk_widget_show (label15);
  gtk_fixed_put (GTK_FIXED (fixedModif), label15, 72, 120);
  gtk_widget_set_size_request (label15, 81, 25);
  gtk_misc_set_alignment (GTK_MISC (label15), 0.47, 0.5);

  radiobuttonFemmeModif = gtk_radio_button_new_with_mnemonic (NULL, _("Femme"));
  gtk_widget_show (radiobuttonFemmeModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), radiobuttonFemmeModif, 224, 336);
  gtk_widget_set_size_request (radiobuttonFemmeModif, 116, 24);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobuttonFemmeModif), radiobuttonSexeHomme_group);
  radiobuttonSexeHomme_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobuttonFemmeModif));

  checkbuttonTroupModif = gtk_check_button_new_with_mnemonic (_("Gestion des troupeaux "));
  gtk_widget_show (checkbuttonTroupModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), checkbuttonTroupModif, 152, 368);
  gtk_widget_set_size_request (checkbuttonTroupModif, 192, 32);

  checkbuttonPlantationModif = gtk_check_button_new_with_mnemonic (_("Gestion du calendrier de\n plantation vegetale"));
  gtk_widget_show (checkbuttonPlantationModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), checkbuttonPlantationModif, 152, 392);
  gtk_widget_set_size_request (checkbuttonPlantationModif, 192, 64);

  checkbuttonOuvriersModif = gtk_check_button_new_with_mnemonic (_("Gestion des ouvriers"));
  gtk_widget_show (checkbuttonOuvriersModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), checkbuttonOuvriersModif, 152, 448);
  gtk_widget_set_size_request (checkbuttonOuvriersModif, 192, 32);

  checkbuttonEquipModif = gtk_check_button_new_with_mnemonic (_("Gestion des equipements"));
  gtk_widget_show (checkbuttonEquipModif);
  gtk_fixed_put (GTK_FIXED (fixedModif), checkbuttonEquipModif, 152, 488);
  gtk_widget_set_size_request (checkbuttonEquipModif, 192, 32);

  buttonModifier = gtk_button_new ();
  gtk_widget_show (buttonModifier);
  gtk_fixed_put (GTK_FIXED (fixedModif), buttonModifier, 584, 112);
  gtk_widget_set_size_request (buttonModifier, 128, 40);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (buttonModifier), alignment4);

  hbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), hbox4);

  image4 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox4), image4, FALSE, FALSE, 0);

  label18 = gtk_label_new_with_mnemonic (_("Modifier"));
  gtk_widget_show (label18);
  gtk_box_pack_start (GTK_BOX (hbox4), label18, FALSE, FALSE, 0);

  labelVServiceM = gtk_label_new_with_mnemonic (_("<span foreground=\"green\"><b>v</b></span>"));
  gtk_widget_show (labelVServiceM);
  gtk_fixed_put (GTK_FIXED (fixedModif), labelVServiceM, 120, 368);
  gtk_widget_set_size_request (labelVServiceM, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelVServiceM), TRUE);

  labelXTelM = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedModif), labelXTelM, 640, 216);
  gtk_widget_set_size_request (labelXTelM, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXTelM), TRUE);

  labelXEmailM = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedModif), labelXEmailM, 640, 256);
  gtk_widget_set_size_request (labelXEmailM, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXEmailM), TRUE);

  labelXCinM = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedModif), labelXCinM, 304, 216);
  gtk_widget_set_size_request (labelXCinM, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXCinM), TRUE);

  labelXNomM = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedModif), labelXNomM, 304, 256);
  gtk_widget_set_size_request (labelXNomM, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXNomM), TRUE);

  labelXPrenomM = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>x</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedModif), labelXPrenomM, 304, 296);
  gtk_widget_set_size_request (labelXPrenomM, 24, 24);
  gtk_label_set_use_markup (GTK_LABEL (labelXPrenomM), TRUE);

  labelXServiceM = gtk_label_new_with_mnemonic (_("<span foreground=\"red\"><b>Choisissez un type de contrat</b></span>"));
  gtk_fixed_put (GTK_FIXED (fixedModif), labelXServiceM, 336, 348);
  gtk_widget_set_size_request (labelXServiceM, 240, 75);
  gtk_label_set_use_markup (GTK_LABEL (labelXServiceM), TRUE);

  labelModifier = gtk_label_new (_("Modifier"));
  gtk_widget_show (labelModifier);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 1), labelModifier);

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed4);

  entrySupprimer = gtk_entry_new ();
  gtk_widget_show (entrySupprimer);
  gtk_fixed_put (GTK_FIXED (fixed4), entrySupprimer, 160, 232);
  gtk_widget_set_size_request (entrySupprimer, 216, 40);
  gtk_entry_set_invisible_char (GTK_ENTRY (entrySupprimer), 8226);

  label35 = gtk_label_new (_("CIN :"));
  gtk_widget_show (label35);
  gtk_fixed_put (GTK_FIXED (fixed4), label35, 56, 240);
  gtk_widget_set_size_request (label35, 81, 25);
  gtk_misc_set_alignment (GTK_MISC (label35), 0.47, 0.5);

  buttonSupprimer = gtk_button_new ();
  gtk_widget_show (buttonSupprimer);
  gtk_fixed_put (GTK_FIXED (fixed4), buttonSupprimer, 416, 232);
  gtk_widget_set_size_request (buttonSupprimer, 136, 40);

  alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment8);
  gtk_container_add (GTK_CONTAINER (buttonSupprimer), alignment8);

  hbox8 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox8);
  gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

  image8 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image8);
  gtk_box_pack_start (GTK_BOX (hbox8), image8, FALSE, FALSE, 0);

  label36 = gtk_label_new_with_mnemonic (_("   Supprimer"));
  gtk_widget_show (label36);
  gtk_box_pack_start (GTK_BOX (hbox8), label36, FALSE, FALSE, 0);

  labelSupprimer = gtk_label_new (_("Supprimer"));
  gtk_widget_show (labelSupprimer);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 2), labelSupprimer);

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (notebook1), fixed5);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_fixed_put (GTK_FIXED (fixed5), treeview1, 120, 208);
  gtk_widget_set_size_request (treeview1, 512, 264);

  buttonAfficherListe = gtk_button_new ();
  gtk_widget_show (buttonAfficherListe);
  gtk_fixed_put (GTK_FIXED (fixed5), buttonAfficherListe, 264, 96);
  gtk_widget_set_size_request (buttonAfficherListe, 130, 48);

  alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment11);
  gtk_container_add (GTK_CONTAINER (buttonAfficherListe), alignment11);

  hbox11 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox11);
  gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

  image11 = gtk_image_new_from_stock ("gtk-go-down", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image11);
  gtk_box_pack_start (GTK_BOX (hbox11), image11, FALSE, FALSE, 0);

  label42 = gtk_label_new_with_mnemonic (_("Afficher"));
  gtk_widget_show (label42);
  gtk_box_pack_start (GTK_BOX (hbox11), label42, FALSE, FALSE, 0);

  labelAfficherListe = gtk_label_new (_("Liste des clients"));
  gtk_widget_show (labelAfficherListe);
  gtk_notebook_set_tab_label (GTK_NOTEBOOK (notebook1), gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook1), 3), labelAfficherListe);

  g_signal_connect ((gpointer) buttonAnnuler_, "clicked",
                    G_CALLBACK (on_buttonAnnuler__clicked),
                    NULL);
  g_signal_connect ((gpointer) radiobuttonSexeHomme, "toggled",
                    G_CALLBACK (on_radiobuttonSexeHomme_toggled),
                    NULL);
  g_signal_connect ((gpointer) buttonConfirm, "clicked",
                    G_CALLBACK (on_buttonConfirm_clicked),
                    NULL);
  g_signal_connect ((gpointer) radiobuttonSexeFemme, "toggled",
                    G_CALLBACK (on_radiobuttonSexeFemme_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonGestionTr, "toggled",
                    G_CALLBACK (on_checkbuttonGestionTr_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonGestionPl, "toggled",
                    G_CALLBACK (on_checkbuttonGestionPl_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonGestionOuv, "toggled",
                    G_CALLBACK (on_checkbuttonGestionOuv_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonGestionEqui, "toggled",
                    G_CALLBACK (on_checkbuttonGestionEqui_toggled),
                    NULL);
  g_signal_connect ((gpointer) buttonAfficherModif, "clicked",
                    G_CALLBACK (on_buttonAfficherModif_clicked),
                    NULL);
  g_signal_connect ((gpointer) radiobuttonHommeModif, "toggled",
                    G_CALLBACK (on_radiobuttonHommeModif_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobuttonFemmeModif, "toggled",
                    G_CALLBACK (on_radiobuttonFemmeModif_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonTroupModif, "toggled",
                    G_CALLBACK (on_checkbuttonTroupModif_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonPlantationModif, "toggled",
                    G_CALLBACK (on_checkbuttonPlantationModif_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonOuvriersModif, "toggled",
                    G_CALLBACK (on_checkbuttonOuvriersModif_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbuttonEquipModif, "toggled",
                    G_CALLBACK (on_checkbuttonEquipModif_toggled),
                    NULL);
  g_signal_connect ((gpointer) buttonModifier, "clicked",
                    G_CALLBACK (on_buttonModifier_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonSupprimer, "clicked",
                    G_CALLBACK (on_buttonSupprimer_clicked),
                    NULL);
  g_signal_connect ((gpointer) buttonAfficherListe, "clicked",
                    G_CALLBACK (on_buttonAfficherListe_clicked),
                    NULL);

  gtk_label_set_mnemonic_widget (GTK_LABEL (labelVServiceM), checkbuttonTroupModif);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowSmartFarm, windowSmartFarm, "windowSmartFarm");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonQuitter, "buttonQuitter");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment10, "alignment10");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox10, "hbox10");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image10, "image10");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label38, "label38");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, notebook1, "notebook1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, fixedAjouter, "fixedAjouter");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label9, "label9");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label10, "label10");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryCin, "entryCin");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryPrenom, "entryPrenom");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryNom, "entryNom");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonAnnuler_, "buttonAnnuler_");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment2, "alignment2");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image2, "image2");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label13, "label13");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryTel, "entryTel");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryMail, "entryMail");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label5, "label5");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label8, "label8");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label7, "label7");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label6, "label6");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label11, "label11");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label14, "label14");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, radiobuttonSexeHomme, "radiobuttonSexeHomme");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonConfirm, "buttonConfirm");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image1, "image1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label12, "label12");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, radiobuttonSexeFemme, "radiobuttonSexeFemme");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonGestionTr, "checkbuttonGestionTr");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonGestionPl, "checkbuttonGestionPl");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonGestionOuv, "checkbuttonGestionOuv");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonGestionEqui, "checkbuttonGestionEqui");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXPrenom, "labelXPrenom");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXMail, "labelXMail");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXNom, "labelXNom");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXCin, "labelXCin");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXTel, "labelXTel");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label53, "label53");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelAjouter, "labelAjouter");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, fixedModif, "fixedModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label16, "label16");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryCinModifSearch, "entryCinModifSearch");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryPrenomModif, "entryPrenomModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryNomModif, "entryNomModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label19, "label19");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label29, "label29");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label30, "label30");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label31, "label31");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label32, "label32");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryCinModif, "entryCinModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryTelModif, "entryTelModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label33, "label33");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entryMailModif, "entryMailModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label34, "label34");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hseparator1, "hseparator1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonAfficherModif, "buttonAfficherModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image3, "image3");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label17, "label17");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, radiobuttonHommeModif, "radiobuttonHommeModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label15, "label15");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, radiobuttonFemmeModif, "radiobuttonFemmeModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonTroupModif, "checkbuttonTroupModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonPlantationModif, "checkbuttonPlantationModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonOuvriersModif, "checkbuttonOuvriersModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, checkbuttonEquipModif, "checkbuttonEquipModif");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonModifier, "buttonModifier");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox4, "hbox4");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image4, "image4");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label18, "label18");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelVServiceM, "labelVServiceM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXTelM, "labelXTelM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXEmailM, "labelXEmailM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXCinM, "labelXCinM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXNomM, "labelXNomM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXPrenomM, "labelXPrenomM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelXServiceM, "labelXServiceM");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelModifier, "labelModifier");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, entrySupprimer, "entrySupprimer");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label35, "label35");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonSupprimer, "buttonSupprimer");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment8, "alignment8");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox8, "hbox8");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image8, "image8");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label36, "label36");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelSupprimer, "labelSupprimer");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, buttonAfficherListe, "buttonAfficherListe");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, alignment11, "alignment11");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, hbox11, "hbox11");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, image11, "image11");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, label42, "label42");
  GLADE_HOOKUP_OBJECT (windowSmartFarm, labelAfficherListe, "labelAfficherListe");

  return windowSmartFarm;
}

GtkWidget*
create_windowInscriValid__e (void)
{
  GtkWidget *windowInscriValid__e;
  GtkWidget *fixed6;
  GtkWidget *label39;

  windowInscriValid__e = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (windowInscriValid__e), _("Inscription Valid\303\251e"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (windowInscriValid__e), fixed6);

  label39 = gtk_label_new (_("Inscription Valid\303\251e"));
  gtk_widget_show (label39);
  gtk_fixed_put (GTK_FIXED (fixed6), label39, 96, 88);
  gtk_widget_set_size_request (label39, 208, 96);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowInscriValid__e, windowInscriValid__e, "windowInscriValid__e");
  GLADE_HOOKUP_OBJECT (windowInscriValid__e, fixed6, "fixed6");
  GLADE_HOOKUP_OBJECT (windowInscriValid__e, label39, "label39");

  return windowInscriValid__e;
}

GtkWidget*
create_windowModifValid__e (void)
{
  GtkWidget *windowModifValid__e;
  GtkWidget *fixed7;
  GtkWidget *label40;

  windowModifValid__e = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (windowModifValid__e), _("Modification Valid\303\251e"));

  fixed7 = gtk_fixed_new ();
  gtk_widget_show (fixed7);
  gtk_container_add (GTK_CONTAINER (windowModifValid__e), fixed7);

  label40 = gtk_label_new (_("Modification Valid\303\251e"));
  gtk_widget_show (label40);
  gtk_fixed_put (GTK_FIXED (fixed7), label40, 72, 96);
  gtk_widget_set_size_request (label40, 240, 88);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowModifValid__e, windowModifValid__e, "windowModifValid__e");
  GLADE_HOOKUP_OBJECT (windowModifValid__e, fixed7, "fixed7");
  GLADE_HOOKUP_OBJECT (windowModifValid__e, label40, "label40");

  return windowModifValid__e;
}

GtkWidget*
create_windowSuppValid__e (void)
{
  GtkWidget *windowSuppValid__e;
  GtkWidget *fixed8;
  GtkWidget *label41;

  windowSuppValid__e = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (windowSuppValid__e), _("Suppression Valid\303\251e"));

  fixed8 = gtk_fixed_new ();
  gtk_widget_show (fixed8);
  gtk_container_add (GTK_CONTAINER (windowSuppValid__e), fixed8);

  label41 = gtk_label_new (_("Suppression Valid\303\251e"));
  gtk_widget_show (label41);
  gtk_fixed_put (GTK_FIXED (fixed8), label41, 88, 72);
  gtk_widget_set_size_request (label41, 240, 104);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (windowSuppValid__e, windowSuppValid__e, "windowSuppValid__e");
  GLADE_HOOKUP_OBJECT (windowSuppValid__e, fixed8, "fixed8");
  GLADE_HOOKUP_OBJECT (windowSuppValid__e, label41, "label41");

  return windowSuppValid__e;
}
