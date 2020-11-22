#include <stdio.h>
#include <stdlib.h>
#include <string.h>




                          //get task

int GetCalendarTask(char selectedTask)
{
    int task;

    if (strcmp(selectedTask,"ajouter")==0)
    {
        task=0;
    }
    else
    {
        task=1;
    }

    return task;
}


                        //displaying calendar


void DisplayCalendar(int n)
{
    calendar car;

    FILE *f=NULL;

    f=fopen("calendrier.txt","r");

    if(f!=NULL)
    {
        for (int i=0;i<n;i++)
        {
            fscanf(f,"%s %s %s",car.id[i],car.plant[i],car.season[i]);
            printf("id = %s / saison : %s / plante : %s\n",car.id[i],car.season[i],car.plant[i]);
        }

    fclose(f);
    }

    else
    {
        printf("Erreur : Fichier non trouvé");
    }
}


                                    //delete plant from calendar


void DeletePlant(char *id,int *n)
{
    FILE *f0=NULL;
    FILE *f1=NULL;

    calendar C;

    f0=fopen("calendrier.txt","r");
    f1=fopen("provisoire.txt","w+");

    while(fscanf(f0,"%s %s %s\n",C.id,C.plant,C.season)!=EOF)
    {
        if(strcmp(id,C.id)!=0)
        {
            fprintf(f1,"%s %s %s\n",C.id,C.plant,C.season);
        }

    }

    fclose(f0);
    fclose(f1);

    n--;
    remove("calendrier.txt");
    rename("provisoire.txt","calendrier.txt");

}


                            //get plant list




void getPlantsList(char saison)
{
    switch (saison)
    {
    case 'p':
        {
            printf("choix A\n");
            printf("choix B\n");
            printf("choix C\n");
            break;

        }

    case 'e':
        {
            printf("choix D\n");
            printf("choix E\n");
            printf("choix F\n");
            break;

        }

     case 'a':
        {
            printf("choix G\n");
            printf("choix H\n");
            printf("choix I\n");
            break;

        }

    case 'h':
        {
            printf("choix J\n");
            printf("choix K\n");
            printf("choix L\n");
            break;

        }
    }
}




                            //add new plants


int addNewPlant(calendar calendrier,int n)

{
    FILE *f =NULL;

    f=fopen("calendrier.txt","a+");

    if(f!=NULL)
    {
        fprintf("%s %s %s\n",calendrier.id,calendrier.plant,calendrier.season);

        fclose(f);
    }

    else
    {
        printf("Erreur : Fichier non trouvé");
    }

return n;
}

