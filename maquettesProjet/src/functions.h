#include <gtk/gtk.h>

typedef struct
{
char date1[20];
char date2[20];
}Date;


typedef struct
{
int identifier;
char plante[100];
char saison[20];
char encem [20];
char rec[20];
}Calendar;


int countLines();  //compte le nombre de lignes dans le fichier

int GetCalendarTask(char selectedTask); // va retourner une valeur de 0 ou 1 (0 => ajout d'un element ; 1 => affichage du calendrier)

void DisplayCalendar(GtkWidget *list); // si GetCalendar == 1 ; cette fonction va afficher le calendrier

void DeletePlant(int id); // si dans l'affichage , l'utilisateur a choisit de supprimer un/des élements, leurs id vont etre passé par ici 

void AddNewPlant(Calendar calendrier); // enregistre le choix dans le calendrier

void EditPlantingDate(int id, Date date); // modifie la date dans le fichier

