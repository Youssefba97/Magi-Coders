#include <gtk/gtk.h>


void
on_ButtonGestiondescapteurs_clicked    (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonGestiondesouvriers_clicked    (GtkWidget *button,
                                        gpointer         user_data);

void
on_ButtonGestiondes__quipements_clicked
                                        (GtkWidget *button,
                                        gpointer         user_data);

void
on_ButtonGestiondesclients_clicked     (GtkWidget *button,
                                        gpointer         user_data);

void
on_ButtonGestiondestroupeaux_clicked   (GtkWidget *button,
                                        gpointer         user_data);

void
on_ButtonGestionducalendrier_clicked   (GtkWidget *button,
                                        gpointer         user_data);

void
on_ButtonQuit_clicked                  (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonAjouter_clicked               (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonSupprimer_clicked             (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonModifier_clicked              (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonRechercher_clicked            (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_TreeViewAffichageAlarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifieri2_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimeri1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercheri_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonfemme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongtroupeaux_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongcalendrier_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongequipement_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonhomme_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongouvrier_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonajouetyo_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonfemme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongtroupeau1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttoncalendrier1_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongequipement1_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonaffdonyo_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimeryo_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonquitteryo_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifieryo_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobuttonhomme1_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongtroupeau1_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttongouvrier1_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficheryo_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttongouvrier1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonye_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonactualiserye_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficherye_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimerye_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonchercherye_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifierye_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouterye_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonactualiserye1_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonactualiseye2_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonquitterye_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouterm_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifierm_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimerm_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonchercherm_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonquitterm_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonconnexion_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttongutilisateur_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttontdb_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeco1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeco_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouterf_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonquitterf_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonDeleteSP_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonEditSP_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonEditSU_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonDeleteSU_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonEditAU_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonDeleteAU_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonEditWI_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonDeleteWI_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ExitButton2_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_GoToCheckCalendar_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_GoToAddNewPlant_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ExitButton1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ExitButton3_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_RadioSpring_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RadioSummer_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RadioAutumn_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RadioWinter_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ConfirmPlantButton_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_ReturnToCalendar_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonReturnCal_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonConfirmEdit_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_ExitButton5_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmarqueri_clicked              (GtkButton       *button,
                                        gpointer         user_data);
