#include <gtk/gtk.h>

int i,j,k;
void
on_button_ajouter_clicked              (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_button_chercher_clicked             (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkWidget       *window_gestion_troupeau_mb,
                                        gpointer         user_data);


void        cell_edited_callback (GtkWidget *window_gestion_troupeau_mb,
                                  gchar               *path_string,
                                  gchar               *new_text,
                                  gpointer             user_data);


void
on_cell_toggled (GtkCellRendererToggle *cell,
                 gchar                 *path_string,
                 gpointer               user_data);


void
on_button_gestion_mb_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_button_gestion_mb_clicked           (GtkButton       *button,
                                        gpointer         user_data);
