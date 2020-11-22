

typedef struct
{
char identifier[20];
char plante[20];
char saison[20];
}Calendar;




int GetCalendarTask(int selectedTask); // va retourner une valeur de 0 ou 1 (0 => ajout d'un element ; 1 => affichage du calendrier)

void DisplayCalendar(int n); // si GetCalendar == 1 ; cette fonction va afficher le calendrier

void DeletePlant(int *n, char *id); // si dans l'affichage , l'utilisateur a choisit de supprimer un/des élements, leurs id vont etre passé par ici 

void getPlantsList(char saison); // va afficher les choix des plantes pour la saison choisit

int AddNewPlant(calendar calendrier,int n); // enregistre le choix dans le calendrier


