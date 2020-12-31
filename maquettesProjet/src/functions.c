#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
#include <gtk/gtk.h>



int countLines()
{
    FILE *f=NULL; 
    int count = 0; 
    char c;
  

    f = fopen("calendrier.txt", "a+"); 
  
    // Check if file exists 
    if (f == NULL) 
    { 
        printf("Could not open file %s", f); 
        return 0; 
    } 
  
    for (c = getc(f); c != EOF; c = getc(f))

	{
	if (c == '\n')
		{
		count = count + 1; 
		}
	}
      
  
    fclose(f);
	return count;
  
    
}







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





                                    //delete plant from calendar


void DeletePlant(int id)
{
    FILE *f0=NULL;
    FILE *f1=NULL;

    Calendar C;

    f0=fopen("calendrier.txt","r");
    f1=fopen("provisoire.txt","w+");

    while(fscanf(f0,"%d %s %s %s %s\n",&C.identifier,C.plante,C.saison,C.encem,C.rec)!=EOF)
    {
        if(id!=C.identifier)
        {
            fprintf(f1,"%d %s %s %s %s\n",C.identifier,C.plante,C.saison,C.encem,C.rec);
        }

    }

    fclose(f0);
    fclose(f1);

    remove("calendrier.txt");
    rename("provisoire.txt","calendrier.txt");

}







                            //add new plants


void AddNewPlant(Calendar calendrier)

{
    FILE *f =NULL;

    f=fopen("calendrier.txt","a+");

    if(f!=NULL)
    {
        fprintf(f,"%d %s %s %s %s\n",calendrier.identifier,calendrier.plante,calendrier.saison,calendrier.encem,calendrier.rec);

        fclose(f);
    }

    else
    {
       // printf("Erreur : Fichier non trouvé");
    }

}



		//edit plant

void EditPlantingDate(int id, Date date)
{
    FILE *f0=NULL;
    FILE *f1=NULL;

    Calendar C;

    f0=fopen("calendrier.txt","r");
    f1=fopen("provisoire.txt","a+");

    while(fscanf(f0,"%d %s %s %s %s\n",&C.identifier,C.plante,C.saison,C.encem,C.rec)!=EOF)
    {
        if(id!=C.identifier)
        {
            fprintf(f1,"%d %s %s %s %s\n",C.identifier,C.plante,C.saison,C.encem,C.rec);
        }
	else
	{
		fprintf(f1,"%d %s %s %s %s\n",C.identifier,C.plante,C.saison,date.date1,date.date2);
	} 

    }

    fclose(f0);
    fclose(f1);

    remove("calendrier.txt");
    rename("provisoire.txt","calendrier.txt");
}

