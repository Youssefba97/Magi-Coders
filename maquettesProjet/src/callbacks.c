#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "tree.h"
#include "functions.h"


char SeasonChoice[50];
int Id_To_Modify;


				//main window : redirection to viewing

void
on_GoToCheckCalendar_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{	
	FILE *f =NULL;
	f=fopen("calendrier.txt","a+");

	//preparing the treeview

	GtkWidget *spring;
	GtkWidget *summer;
	GtkWidget *autumn;
	GtkWidget *winter;

	//accessing destination window
	GtkWidget *windowCheckCal;
	windowCheckCal = create_CheckCalendar ();

	//creating treeview
	spring=lookup_widget(windowCheckCal,"treeviewSpring");
	summer=lookup_widget(windowCheckCal,"treeviewSummer");
	autumn=lookup_widget(windowCheckCal,"treeviewAutumn");
	winter=lookup_widget(windowCheckCal,"treeviewWinter");

	SpringTreeView(spring,"calendrier.txt");
	SummerTreeView(summer,"calendrier.txt");
	AutumnTreeView(autumn,"calendrier.txt");
	WinterTreeView(winter,"calendrier.txt");
	
	fclose(f);

	GtkWidget *CalendarMain;
	CalendarMain=lookup_widget(button,"CalendarMain");

	gtk_widget_destroy (CalendarMain);
	gtk_widget_show (windowCheckCal);


}


				//main window : redirection to adding
void
on_GoToAddNewPlant_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *windowAdd;
	GtkWidget *CalendarMain;

	CalendarMain=lookup_widget(button,"CalendarMain");
	windowAdd = create_ChoosePlant ();

	gtk_widget_destroy (CalendarMain);
	gtk_widget_show (windowAdd);

}


				//exit button 1 : close app

void
on_ExitButton1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *CalendarMain;
	CalendarMain=lookup_widget(button,"CalendarMain");

	gtk_widget_destroy (CalendarMain);

}


				// exit button 2 : return to main + close check calendar

void
on_ExitButton2_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *CheckCalendar;	
	GtkWidget *windowMain;		


		
	CheckCalendar=lookup_widget(button,"CheckCalendar");
	windowMain = create_CalendarMain ();

		
	gtk_widget_destroy (CheckCalendar);	
	gtk_widget_show (windowMain);	

}


void
on_treeviewSpring_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


				//spring treeview edit

void
on_ButtonEditSP_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{	
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelSpEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSpDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSpDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSpring");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;
	
			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);

	CheckCal=lookup_widget(CheckCalendar,"CheckCalendar");
	EditPlant = create_EditPlant ();


	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);

        }
	
	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}

}


				//spring treeview delete

void
on_ButtonDeleteSP_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	
	GtkWidget *messageFD,*messageSD,*messageFE;
	messageFE=lookup_widget(CheckCalendar,"LabelSpEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSpDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSpDelS");
	
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSpring");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));

        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewSpring");
	SpringTreeView(newTree,"calendrier.txt");

	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);

        }
	
	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}

}


void
on_treeviewSummer_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ButtonEditSU_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelSmEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSmDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSmDelS");


	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSummer");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;	

			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);
		
	CheckCal=lookup_widget(CheckCalendar,"CheckCalendar");
	EditPlant = create_EditPlant ();

		
	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);
	}

	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}


}


void
on_ButtonDeleteSU_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelSmEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelSmDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelSmDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSummer");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewSummer");
	SummerTreeView(newTree,"calendrier.txt");
	
	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}

	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}


}


void
on_treeviewAutumn_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ButtonEditAU_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelAuEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelAuDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelAuDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewAutumn");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;	

			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);
		
	CheckCal=lookup_widget(CheckCalendar,"CheckCalendar");
	EditPlant = create_EditPlant ();

		
	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);
	}

	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}



}


void
on_ButtonDeleteAU_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelAuEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelAuDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelAuDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewAutumn");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewAutumn");
	AutumnTreeView(newTree,"calendrier.txt");

	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}


	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}


}


void
on_treeviewWinter_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ButtonEditWI_clicked                (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelWEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelWDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelWDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *EditPlant, *CheckCal;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewSummer");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
	gtk_tree_model_get (model,&iter,0,&id,-1);
	Id_To_Modify=id;	


			//displaying messages
	gtk_widget_set_visible(messageFE,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageSD,FALSE);

		
	CheckCal=lookup_widget(CheckCalendar,"treeviewWinter");
	EditPlant = create_EditPlant ();

		
	gtk_widget_destroy (CheckCal);	
	gtk_widget_show (EditPlant);
	}

	else
	{
	gtk_widget_show(messageFE);

	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFD,FALSE);
	}


}


void
on_ButtonDeleteWI_clicked              (GtkButton       *CheckCalendar,
                                        gpointer         user_data)
{
	GtkWidget *messageFD,*messageSD,*messageFE;

	messageFE=lookup_widget(CheckCalendar,"LabelWEditF");
	messageFD=lookup_widget(CheckCalendar,"LabelWDelF");
	messageSD=lookup_widget(CheckCalendar,"LabelWDelS");

	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* plant, *newTree;
        gint* id;
        plant=lookup_widget(CheckCalendar,"treeviewWinter");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(plant));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           DeletePlant(id);// supprimer la ligne du fichier

	newTree=lookup_widget(CheckCalendar,"treeviewWinter");
	WinterTreeView(newTree,"calendrier.txt");

	//displaying messages
	gtk_widget_show(messageSD);
	gtk_widget_set_visible(messageFD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}

	else
	{
	gtk_widget_show(messageFD);
	gtk_widget_set_visible(messageSD,FALSE);
	gtk_widget_set_visible(messageFE,FALSE);
	}


}


				//exit current window and go to main

void
on_ExitButton3_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *ChoosePlant;	
	GtkWidget *windowMain;		

		
	ChoosePlant=lookup_widget(button,"ChoosePlant");
	windowMain = create_CalendarMain ();

		
	gtk_widget_destroy (ChoosePlant);	
	gtk_widget_show (windowMain);

}


				//beginning radio buttons

void
on_RadioAutumn_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

	if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice, "automne");}

}


void
on_RadioSummer_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

	if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice, "été");}

}


void
on_RadioSpring_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

	if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice , "printemps");}

}


void
on_RadioWinter_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

	if (gtk_toggle_button_get_active (GTK_RADIO_BUTTON(togglebutton)))
	{strcpy(SeasonChoice , "hiver");}

}
				//end radio buttons



				//beggining add plants

void
on_ConfirmPlantButton_clicked          (GtkButton       *ChoosePlant,
                                        gpointer         user_data)
{

	GtkWidget *plant,*cal1, *cal2,*messageFR,*messageFC,*messageS ;
	Calendar C;
	int proceed =1;

	//setting up the labels for the errors
	messageFR=lookup_widget(ChoosePlant,"LabelErrorRadio");
	messageFC=lookup_widget(ChoosePlant,"LabelErrorCheckbox");
	messageS=lookup_widget(ChoosePlant,"LabelSuccessAdd");

	//declaring variables
	int id,j1,j2,m1,m2,a1,a2;
	char dateEnc[20];
	char dateRec[20];

	//this function counts how many lines there are in the file, this way, it gives a unique Id to each new entry
	id = countLines();

		//body of the add algorythm

	//getting values from the window
	plant=lookup_widget(ChoosePlant,"comboboxentry1");
	cal1=lookup_widget(ChoosePlant,"calendarPlanting");
	cal2=lookup_widget(ChoosePlant,"calendarHarvesting");

	gtk_calendar_get_date(GTK_CALENDAR(cal1),&a1,&m1,&j1);
	gtk_calendar_get_date(GTK_CALENDAR(cal2),&a2,&m2,&j2);

	snprintf(dateEnc, 20, "%d%s%d%s%d", j1, "/",m1+1,"/",a1);
	snprintf(dateRec, 20, "%d%s%d%s%d", j2, "/",m2+1,"/",a2);

	C.identifier=id;

	//setting up error messages

		//checking if radio isnt empty
	if (strcmp(SeasonChoice,"")==0)
	{
		gtk_widget_show (messageFR);
		gtk_widget_set_visible(messageFC,FALSE);
		gtk_widget_set_visible(messageS,FALSE);
		proceed = -1;
	}
	
	else
	{
		strcpy(C.plante,gtk_combo_box_get_active_text(GTK_COMBO_BOX(plant)));

		if (strcmp(C.plante,"")==0)
		{
			gtk_widget_show (messageFC);
			gtk_widget_set_visible(messageFR,FALSE);
			gtk_widget_set_visible(messageS,FALSE);
			proceed = -1;
		}

		else
		{
			strcpy(C.saison,SeasonChoice);
			strcpy(C.encem,dateEnc);
			strcpy(C.rec,dateRec);
		}
	}

	



	//writing in file if all checks are successful
	
	if(proceed==1)
	{
		AddNewPlant(C);
		
		//display of success message, while hiding previous error messages
		gtk_widget_show (messageS);
		gtk_widget_set_visible(messageFR,FALSE);
		gtk_widget_set_visible(messageFC,FALSE);
	}
	


}
				//end add plant



void
on_ReturnToCalendar_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

	//preparing the treeview

	GtkWidget *spring;
	GtkWidget *summer;
	GtkWidget *autumn;
	GtkWidget *winter;

	//accessing destination window
	GtkWidget *windowCheckCal;
	windowCheckCal = create_CheckCalendar ();

	//creating treeview
	spring=lookup_widget(windowCheckCal,"treeviewSpring");
	summer=lookup_widget(windowCheckCal,"treeviewSummer");
	autumn=lookup_widget(windowCheckCal,"treeviewAutumn");
	winter=lookup_widget(windowCheckCal,"treeviewWinter");

	SpringTreeView(spring,"calendrier.txt");
	SummerTreeView(summer,"calendrier.txt");
	AutumnTreeView(autumn,"calendrier.txt");
	WinterTreeView(winter,"calendrier.txt");


	GtkWidget *ChoosePlant;
	ChoosePlant=lookup_widget(button,"ChoosePlant");

	gtk_widget_destroy (ChoosePlant);
	gtk_widget_show (windowCheckCal);

}


				//exit current window and go to main

void
on_ExitButton5_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *EditPlant;	
	GtkWidget *windowMain;		


		
	EditPlant=lookup_widget(button,"EditPlant");
	windowMain = create_CalendarMain ();

		
	gtk_widget_destroy (EditPlant);	
	gtk_widget_show (windowMain);

}


				//beggining edit plant

void
on_ButtonConfirmEdit_clicked           (GtkButton       *EditPlant,
                                        gpointer         user_data)
{
	GtkWidget *message;
	message=lookup_widget(EditPlant,"LabelSuccessEdit");

	GtkWidget *cal1, *cal2 ;
	Date date;

	int id,j1,j2,m1,m2,a1,a2;
	char dateEnc[20];
	char dateRec[20];

	cal1=lookup_widget(EditPlant,"calendarEditPlanting");
	cal2=lookup_widget(EditPlant,"calendarEditHarvesting");

	gtk_calendar_get_date(GTK_CALENDAR(cal1),&a1,&m1,&j1);
	gtk_calendar_get_date(GTK_CALENDAR(cal2),&a2,&m2,&j2);

	snprintf(dateEnc, 20, "%d%s%d%s%d", j1, "/",m1+1,"/",a1);
	snprintf(dateRec, 20, "%d%s%d%s%d", j2, "/",m2+1,"/",a2);

	strcpy(date.date1,dateEnc);
	strcpy(date.date2,dateRec);
	

	EditPlantingDate(Id_To_Modify,date);

	
	gtk_widget_show(message);


}

				//end edit plant

void
on_buttonReturnCal_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{


	//preparing the treeview

	GtkWidget *spring;
	GtkWidget *summer;
	GtkWidget *autumn;
	GtkWidget *winter;

	//accessing destination window
	GtkWidget *windowCheckCal;
	windowCheckCal = create_CheckCalendar ();

	//creating treeview
	spring=lookup_widget(windowCheckCal,"treeviewSpring");
	summer=lookup_widget(windowCheckCal,"treeviewSummer");
	autumn=lookup_widget(windowCheckCal,"treeviewAutumn");
	winter=lookup_widget(windowCheckCal,"treeviewWinter");

	SpringTreeView(spring,"calendrier.txt");
	SummerTreeView(summer,"calendrier.txt");
	AutumnTreeView(autumn,"calendrier.txt");
	WinterTreeView(winter,"calendrier.txt");


	GtkWidget *EditPlant;
	EditPlant=lookup_widget(button,"EditPlant");

	gtk_widget_destroy (EditPlant);
	gtk_widget_show (windowCheckCal);

}

