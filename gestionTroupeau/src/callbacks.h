#include <gtk/gtk.h>

int i,j,k;
GtkWidget* window_gestion_troupeau_mb;
void
on_button_ajouter_clicked              (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_treeview_1_mb_row_activated         (GtkWidget       *window_gestion_troupeau_mb,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_chercher_clicked             (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_treeview_2_mb_row_activated         (GtkWidget     *window_gestion_troupeau_mb,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
