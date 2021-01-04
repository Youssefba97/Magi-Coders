#include<gtk/gtk.h>
#ifndef TREE_H_
#define TREE_H_
void Capteurtree(GtkWidget* treeview1,char*l);
void ChercherCapteur(GtkWidget* treeview2,char*l);
void Alarmantetree(GtkWidget* TreeViewAffichageAlarmante,char*l);
void Defectueuxtree(GtkWidget* treeview3,char*l);
void Afficherouvrier(GtkWidget* treeview1,char*l);
void Afficherouvrier1(GtkWidget* treeview1,char*l);
int Chercherouvrier(GtkWidget* treeview1,char*l,char*nom);
void afficherabsence(GtkWidget* treeview1,char*l);
#endif

