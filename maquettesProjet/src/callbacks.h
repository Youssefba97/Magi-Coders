#include <gtk/gtk.h>


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
on_ExitButton2_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewSpring_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonEditSP_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_ButtonDeleteSP_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_treeviewSummer_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonEditSU_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_ButtonDeleteSU_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_treeviewAutumn_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonEditAU_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_ButtonDeleteAU_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_treeviewWinter_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonEditWI_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_ButtonDeleteWI_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data);

void
on_ExitButton3_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_RadioAutumn_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RadioSummer_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RadioSpring_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RadioWinter_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ConfirmPlantButton_clicked          (GtkButton       *ChoosePlant,
                                        gpointer         user_data);

void
on_ReturnToCalendar_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ExitButton5_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ButtonConfirmEdit_clicked           (GtkButton       *EditPlant,
                                        gpointer         user_data);

void
on_buttonReturnCal_clicked             (GtkButton       *button,
                                        gpointer         user_data);
