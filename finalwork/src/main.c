/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"capteurs.h"

int
main (int argc, char *argv[])
{
  GtkWidget *auth;
  GtkWidget *WindowGestiondescapteurs/*, *p, *p1, *p2, *p3*/;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  auth = create_auth ();
  gtk_widget_show (auth);
  /*WindowGestiondescapteurs = create_WindowGestiondescapteurs ();
  gtk_widget_show (WindowGestiondescapteurs);
  p=lookup_widget(WindowGestiondescapteurs,"treeview1");
  Capteurtree(p,"capteurs.txt");
  p1=lookup_widget(WindowGestiondescapteurs,"TreeViewAffichageAlarmante");
  Alarmantetree(p1,"alarmantes.txt");
  p2=lookup_widget(WindowGestiondescapteurs,"treeview2");
  ChercherCapteur(p2,"capteurs.txt");
  p3=lookup_widget(WindowGestiondescapteurs,"treeview3");
  Defectueuxtree(p3,"defectueux.txt");*/
  gtk_main ();
  return 0;
}

