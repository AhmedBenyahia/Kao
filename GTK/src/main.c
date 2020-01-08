#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//////////////////////////////////////////////////////////BUTTONS AND LAYOUT VARIABLES//////////////////////////////////////////////////////
GtkWidget *LPassword, *LEmail, *Connect, *Signup, *Exit;                                                            //Login Variables
GtkWidget *FName, *LName, *RPassword, *Password, *Email, *Creation, *Return,*Upload;                                                        //Signup Variables
GtkWidget *Yes, *No;                                                                                     //PopUp Exit variables
GtkWidget *OK, *CLOSE;                                                                                   //Waning whole Formula
GtkWidget *ok, *fermer;                                                                                  //no account popup
GtkWidget *OKK, *CLOSEE;                                                                                //Fill Login
GtkWidget *OKKK, *CLOSEEE;                                                                              //ACCOUNT CREATED
GtkWidget *NotOkay, *NotCancel, *NOT;
GtkWidget *OKUSED, *CLOSEUSED;                                                                          //USER USED
GtkWidget *PINOK, *PINCLOSE;                                                                            //Same PIn
GtkWidget *can, *okey;
GtkWidget *YES, *NO;                                                                                     //Exit POPUP
GtkWidget *Okay, *Cancel;                                                                                //Wrong password Pop-up
GtkWidget *SignImgs , *LoginImg ;
GtkLabel *FNameLabel, *LNameLabel, *EmailLabel, *PasswordLabel ;
GtkWidget *Changer, *RNPassword, *NPassword, *Acient;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////Windows///////////////////////////////////////////////////////////////////
GtkBuilder *builder;                                                                                    //the glade varialble
GtkWidget *LoginWindow, *Sign, *Warning, *SamePin, *Photo;                                                        //The windows Used
GtkWidget *AccountCreated, *AccountError, *AccountEmpty, *UserUsed, *Profile;                                       //The windows Used
GtkWidget *LengthError, *Exit, *notepad;                                                                 //The windows Used
GtkWidget *Wrongpassword, *NoAccount, *LogOut;                                                                              //The windows Used
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////Variables////////////////////////////////////////////////////////////////////////
bool test = false;                                                                                        //bool variable
char word[20], word1[4];                                                                                 //username and pass variable
FILE *fp;                                                                                               //Declaration of a File
char buffer[80], x[20];                                                                                  //buffr
char message[100][20];                                                                                  //all the users table
char messagepass[100][20];                                                                              //all the passwords
struct stat st;                                                                                         //struct of a file we used it to see whether a file is empty
int counterpasswordpopup = 0, counternopasswordpopup = 0, counterprofilepopup = 0;
gchar *filename;
GtkWidget *dialog;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////// THE FUNCTIONS USED //////////////////////////////////////////////////////
void popup_exit();                                                  //function of popupexit
void Signupwindow(GtkWidget *widget, gpointer window);               //function of signup window
void verifydataSign();                                              //function of verifies signup conditions
void verifydataLog();                                               //function of verifies Log conditions
int main(int argc, char *argv[]);                                   //main()
void Hide(GtkWidget *widget, gpointer window);                      //hide function
void ChangePw(char *variable);
void opendialog();
void openmultiple();
void openfile();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/***************************************************************************************
*                                                                                      *
*                                      SIGN UP WINDOW                                  *
*                                                                                      *
***************************************************************************************/

void Signupwindow(GtkWidget *widget,gpointer window){

    builder = gtk_builder_new_from_file("glade/window_main.glade");                                         //link the builder
    Sign = GTK_WIDGET(gtk_builder_get_object(builder, "Signup"));                                           //Signhe sign wondow

    FName           = GTK_WIDGET(gtk_builder_get_object(builder,"FName"));
    LName           = GTK_WIDGET(gtk_builder_get_object(builder,"LName"));                                        //link the glade buttons with c
    Password        = GTK_WIDGET(gtk_builder_get_object(builder,"Password"));                                         //link the glade buttons with c
    RPassword       = GTK_WIDGET(gtk_builder_get_object(builder,"RPassword"));                                        //link the glade buttons with c
    Email           = GTK_WIDGET(gtk_builder_get_object(builder,"Email"));
    Creation        = GTK_WIDGET(gtk_builder_get_object(builder,"Creation"));                                     //link the glade buttons with c
    Return          = GTK_WIDGET(gtk_builder_get_object(builder,"Return"));
    SignImgs        = GTK_WIDGET(gtk_builder_get_object(builder, "SignImgs"));                                      //link the glade buttons with c


    g_signal_connect(G_OBJECT(SignImgs),"clicked", G_CALLBACK (openmultiple),(gpointer) Signupwindow);
    g_signal_connect(G_OBJECT(Creation),"clicked", G_CALLBACK (verifydataSign), (gpointer)LoginWindow);      //link the button with a function ;
    g_signal_connect(G_OBJECT(Return),"clicked", G_CALLBACK (Hide), (gpointer)Sign);                         //link the button with a function ;
    g_signal_connect(G_OBJECT(Return),"released", G_CALLBACK (main), (gpointer)LoginWindow);                 //link the button with a function ;

    gtk_widget_show(Sign);                                                                                   //show the current window
}
/***************************************************************************************************************************************************/


/***************************************************************************************
*                                                                                      *
*                                   Main Login window                                  *
*                                                                                      *
***************************************************************************************/
int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("glade/window_main.glade");

    LoginWindow = GTK_WIDGET(gtk_builder_get_object(builder, "Login"));

    g_signal_connect(LoginWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);

    LEmail          = GTK_WIDGET(gtk_builder_get_object(builder,"LEmail"));                                       ///////////////////////////////////////////
    LPassword       = GTK_WIDGET(gtk_builder_get_object(builder,"LPassword"));
    Connect         = GTK_WIDGET(gtk_builder_get_object(builder,"Connect"));
    Signup          = GTK_WIDGET(gtk_builder_get_object(builder,"Signupbtn"));
    Exit            = GTK_WIDGET(gtk_builder_get_object(builder,"Exit"));
    LoginImg        = GTK_WIDGET(gtk_builder_get_object(builder, "LoginImg"));                                       //link all buttons of the login

    g_signal_connect(G_OBJECT(LoginImg),"clicked", G_CALLBACK (opendialog), (gpointer)LoginWindow);
    g_signal_connect(G_OBJECT(Connect),"clicked", G_CALLBACK (verifydataLog), (gpointer)LoginWindow);
    g_signal_connect(G_OBJECT(Signup),"clicked", G_CALLBACK (Signupwindow), (gpointer)LoginWindow);
    g_signal_connect(G_OBJECT(Signup),"released", G_CALLBACK (Hide), (gpointer)LoginWindow);
    g_signal_connect(G_OBJECT(Exit),"clicked", G_CALLBACK (popup_exit), (gpointer)LoginWindow);                 /////////////////////////////////////////

    g_object_unref(builder);

    gtk_widget_show_all(LoginWindow);
    gtk_main();

    return 0;
}

/********************************************************************************************************************************************************/

void openfile() {
    system("cd src && ./script.sh && ./Notepad && cd ..");
}
void opendialog() {
    gint id;

    NOT               = GTK_WIDGET(gtk_builder_get_object(builder,"NOT"));                                       ///////////////////////////////////////////
    NotOkay           = GTK_WIDGET(gtk_builder_get_object(builder,"NotOkay"));
    NotCancel         = GTK_WIDGET(gtk_builder_get_object(builder,"NotCancel"));

    g_signal_connect(G_OBJECT(NotCancel),"clicked", G_CALLBACK (Hide), (gpointer)LoginWindow);
    g_signal_connect(G_OBJECT(NotOkay),"clicked", G_CALLBACK (Hide), (gpointer)LoginWindow);


    dialog = gtk_file_chooser_dialog_new("Open An Image", NULL,GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,GTK_STOCK_CANCEL,GTK_RESPONSE_REJECT,NULL);

    id = gtk_dialog_run(GTK_DIALOG(dialog));
    if(GTK_RESPONSE_ACCEPT == id){
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
        if(strcmp(filename,"\0") != 0) {
            //        gtk_widget_show(Profile);
        }
        gtk_widget_hide(dialog);
    }
}

void openmultiple() {
    system(" cd src && ./script2.sh &&  ./mult && cd ..");
}
/********************************************************************************************
*                                                                                           *
*                              VERIFY SIGNUP CONDITIONS                                     *
*                                                                                           *
*********************************************************************************************/

void verifydataSign() {
    builder = gtk_builder_new_from_file("glade/window_main.glade");                                 ///////////////////////////////////////////
    Warning = GTK_WIDGET(gtk_builder_get_object(builder, "Warning"));
    SamePin = GTK_WIDGET(gtk_builder_get_object(builder, "SamePinError"));
    AccountCreated = GTK_WIDGET(gtk_builder_get_object(builder, "AccountCreated"));
    UserUsed = GTK_WIDGET(gtk_builder_get_object(builder, "UserUsed"));
    int i = 0, j = 0;

    Photo = GTK_WIDGET(gtk_builder_get_object(builder, "Image-enter"));
    OK = GTK_WIDGET(gtk_builder_get_object(builder, "OK"));
    CLOSE = GTK_WIDGET(gtk_builder_get_object(builder, "CLOSE"));

    OKKK = GTK_WIDGET(gtk_builder_get_object(builder, "OKKK"));
    CLOSEEE = GTK_WIDGET(gtk_builder_get_object(builder, "CLOSEEE"));

    OKUSED = GTK_WIDGET(gtk_builder_get_object(builder, "OKUSED"));
    CLOSEUSED = GTK_WIDGET(gtk_builder_get_object(builder, "CLOSEUSED"));

    PINOK = GTK_WIDGET(gtk_builder_get_object(builder, "PINOK"));
    PINCLOSE = GTK_WIDGET(gtk_builder_get_object(builder, "PINCLOSE"));


    g_signal_connect(G_OBJECT(OK), "clicked", G_CALLBACK(Hide), (gpointer) Warning);
    g_signal_connect(G_OBJECT(CLOSE), "clicked", G_CALLBACK(Hide), (gpointer) Warning);

    g_signal_connect(G_OBJECT(PINOK), "clicked", G_CALLBACK(Hide), (gpointer) SamePin);
    g_signal_connect(G_OBJECT(PINCLOSE), "clicked", G_CALLBACK(Hide),(gpointer) SamePin);           ////////////////LINK FONCTIONS ///////////////

    g_signal_connect(G_OBJECT(OKKK), "clicked", G_CALLBACK(Hide), (gpointer) AccountCreated);
    g_signal_connect(G_OBJECT(CLOSEEE), "clicked", G_CALLBACK(Hide), (gpointer) AccountCreated);

    g_signal_connect(G_OBJECT(CLOSEUSED), "clicked", G_CALLBACK(Hide), (gpointer) UserUsed);
    g_signal_connect(G_OBJECT(OKUSED), "clicked", G_CALLBACK(Hide), (gpointer) UserUsed);


    if (strcmp(gtk_entry_get_text(GTK_ENTRY(FName)), "\0") == 0 ||
        (strcmp(gtk_entry_get_text(GTK_ENTRY(LName)), "\0") == 0) ||
        (strcmp(gtk_entry_get_text(GTK_ENTRY(Email)), "\0") == 0) ||
        (strcmp(gtk_entry_get_text(GTK_ENTRY(Password)), "\0") == 0) ||
        (strcmp(gtk_entry_get_text(GTK_ENTRY(RPassword)), "\0") == 0))  //if the formilar isnt fully filled condition
        gtk_widget_show(Warning);

    else if (strcmp(gtk_entry_get_text(GTK_ENTRY(Password)), gtk_entry_get_text(GTK_ENTRY(RPassword))) != 0)            //if pin are similar condition
        gtk_widget_show(SamePin);

    else {
        fp = fopen("src/Data.txt", "ab");
        if (stat("src/Data.txt", &st) == 0) {
            if (st.st_size ==  0)
            {
                fputs(gtk_entry_get_text(GTK_ENTRY(Email)), fp);
                fputs("\n", fp);
                fputs(gtk_entry_get_text(GTK_ENTRY(Password)), fp);
                fputs("\n", fp);
                gtk_widget_show(AccountCreated);
                goto label;
            } else {
                fclose(fp);
                fp = fopen("src/Data.txt","r");                                                               //if its not empty read it
                while (fgets(buffer, 80, fp)) {
                    if (i % 2 != 0) {
                        i++;
                        continue;
                    }
                    strcpy(message[j],
                           buffer);                                                               //fill table message with user
                    i++;
                    j++;
                }
                for (int k = 0; k < j; k++) {
                    strncpy(word, message[k], strlen(message[k]) - 1);
                    if (strcmp(gtk_entry_get_text(GTK_ENTRY(Email)), word) ==0) {                            //compara the entred data with all users in file
                        test = true;
                    }
                }
                if (test) {
                    gtk_widget_show(UserUsed);                                                           //if there is a duplication alert
                    test = false;
                } else {
                    fclose(fp);                                                                         //else close file and open it as write privilege
                    fp = fopen("src/Data.txt", "ab");
                    fputs(gtk_entry_get_text(GTK_ENTRY(Email)), fp);
                    fputs("\n", fp);
                    fputs(gtk_entry_get_text(GTK_ENTRY(Password)), fp);
                    fputs("\n", fp);
                    label:
                    mkdir(gtk_entry_get_text(GTK_ENTRY(FName)), 0777);
                    gtk_widget_show(AccountCreated);
                }
                fclose(fp);                                                                             //close it again
            }
        }
    }
}

/***************************************************************************************************
*                                                                                                  *
*                                         VERIFY LOGIN CONDITIONS                                  *
*                                                                                                  *
****************************************************************************************************/

void verifydataLog() {

    builder = gtk_builder_new_from_file("glade/window_main.glade");
    AccountError = GTK_WIDGET(gtk_builder_get_object(builder,"AccountError"));
    AccountEmpty = GTK_WIDGET(gtk_builder_get_object(builder, "AccountEmpty"));
    Profile = GTK_WIDGET(gtk_builder_get_object(builder, "Profile"));
    Wrongpassword = GTK_WIDGET(gtk_builder_get_object(builder, "Wrongpassword"));
    NoAccount = GTK_WIDGET(gtk_builder_get_object(builder, "NoAccount"));
    notepad = GTK_WIDGET(gtk_builder_get_object(builder, "Notepad"));
    can = GTK_WIDGET(gtk_builder_get_object(builder, "can"));
    okey = GTK_WIDGET(gtk_builder_get_object(builder, "okey"));
    ok = GTK_WIDGET(gtk_builder_get_object(builder,"ok"));
    fermer = GTK_WIDGET(gtk_builder_get_object(builder, "fermer"));
    OKK = GTK_WIDGET(gtk_builder_get_object(builder, "OKK"));
    CLOSEE = GTK_WIDGET(gtk_builder_get_object(builder, "CLOSEE"));
    Cancel = GTK_WIDGET(gtk_builder_get_object(builder, "Cancel"));
    Okay = GTK_WIDGET(gtk_builder_get_object(builder, "Okay"));
    Yes = GTK_WIDGET(gtk_builder_get_object(builder, "YES"));
    No = GTK_WIDGET(gtk_builder_get_object(builder, "NO"));
    LNameLabel = GTK_LABEL(gtk_builder_get_object(builder, "LNameLabel"));
    FNameLabel = GTK_LABEL(gtk_builder_get_object(builder, "FNameLabel"));
    EmailLabel = GTK_LABEL(gtk_builder_get_object(builder, "EmailLabel"));
    PasswordLabel = GTK_LABEL(gtk_builder_get_object(builder, "PasswordLabel"));
    Changer = GTK_WIDGET(gtk_builder_get_object(builder, "Changer"));
    LogOut = GTK_WIDGET(gtk_builder_get_object(builder, "LogOut"));
    Upload = GTK_WIDGET(gtk_builder_get_object(builder, "Upload"));
    int i = 0, j = 0, p = 0;


    g_signal_connect(G_OBJECT(Cancel), "clicked", G_CALLBACK(Hide),(gpointer) Wrongpassword);                           //link with functions
    g_signal_connect(G_OBJECT(Okay), "clicked", G_CALLBACK(Hide),(gpointer) Wrongpassword);                             //link with functions

    g_signal_connect(G_OBJECT(LogOut), "clicked", G_CALLBACK(Hide),(gpointer) Profile);                                //link with functions
    g_signal_connect(G_OBJECT(LogOut), "released", G_CALLBACK(main), (gpointer) Profile);

    g_signal_connect(G_OBJECT(Changer), "released", G_CALLBACK(openfile), (gpointer) Profile);
    g_signal_connect(G_OBJECT(Upload), "released", G_CALLBACK(openmultiple), (gpointer) Profile);


    g_signal_connect(G_OBJECT(can), "clicked", G_CALLBACK(Hide),(gpointer) NoAccount);                                  //link with functions
    g_signal_connect(G_OBJECT(okey), "clicked", G_CALLBACK(Hide),(gpointer) NoAccount);                                 //link with functions

    g_signal_connect(G_OBJECT(ok), "clicked", G_CALLBACK(Hide),(gpointer) AccountError);                                //link with functions
    g_signal_connect(G_OBJECT(fermer), "clicked", G_CALLBACK(Hide),(gpointer) AccountError);                            //link with functions

    g_signal_connect(G_OBJECT(OKK), "clicked", G_CALLBACK(Hide),(gpointer) AccountEmpty);                               //link with functions
    g_signal_connect(G_OBJECT(CLOSEE), "clicked", G_CALLBACK(Hide),(gpointer) AccountEmpty);                            //link with functions


    printf("[INFO] email -%s-\n", gtk_entry_get_text(GTK_ENTRY(LEmail)));
    printf("[INFO] password -%s-\n", gtk_entry_get_text(GTK_ENTRY(LPassword)));


    if (strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)), "\0") == 0 ||
        strcmp(gtk_entry_get_text(GTK_ENTRY(LPassword)), "\0") == 0) {      //if name or pin arent filled condition
        printf("[INFO] Encoding img \"%s\"... \n", filename);
        if (strcmp(filename, "\0") != 0) {
            char buffer[10240];
            snprintf(buffer, sizeof(buffer), "base64 -w 0 '%s' > ./src/img.b64", filename);
            printf("[INFO] running script \"%s\"... \n", buffer);
            system(buffer);
            system("bash ./src/script5.sh ");
        } else {
            gtk_widget_show(AccountEmpty);
        }
    }

    if (strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)), "\0") != 0 &&
        strcmp(gtk_entry_get_text(GTK_ENTRY(LPassword)), "\0") != 0) {     //if both of them are filled condition

        char buffer[1024];
        snprintf(buffer, sizeof(buffer), "bash ./src/script4.sh %s %s", gtk_entry_get_text(GTK_ENTRY(LEmail)), gtk_entry_get_text(GTK_ENTRY(LPassword)));
        system(buffer);
    }

    // File empty or null
    if (0) {
        counternopasswordpopup = 1;
    } else {
        // Read from Data file
        // Also parse file to display profile info
//        fp = fopen("src/Data.txt","r");                                                                                   //open a file and only read
//        while (fgets(buffer, 80, fp)) {                                                                                 //while there is a line enter to the loop
//            if (i % 2 == 0) {
//                strcpy(message[j],
//                       buffer);                                                                          //table message is being filled with names
//                j++;
//                i++;
//                continue;
//            }
//            if (i % 2 != 0) {
//                strcpy(messagepass[p],
//                       buffer);                                                                      //table messagepass is being filled with password
//                p++;
//                i++;
//                continue;
//            }
//        }
//        fclose(fp);
        counterprofilepopup = 1;
    }
    if (counterprofilepopup == 1) {
        gtk_widget_show(Profile);
        counterprofilepopup = 0;
    }
    if (counterpasswordpopup == 1) {
        gtk_widget_show(Wrongpassword);
        counterpasswordpopup = 0;
    }
    if (counternopasswordpopup == 1) {
        gtk_widget_show(NoAccount);
        counternopasswordpopup = 0;
    }
}

//////////////////////////////////////////////////////////////////////////////////////
///                                  POP UP EXIT                                    //
//////////////////////////////////////////////////////////////////////////////////////

void popup_exit() {
    builder = gtk_builder_new_from_file("glade/window_main.glade");                                         ////////////////////////////////
    Exit = GTK_WIDGET(gtk_builder_get_object(builder, "EXITPOPUP"));
    YES = GTK_WIDGET(gtk_builder_get_object(builder, "YES"));
    NO = GTK_WIDGET(gtk_builder_get_object(builder, "NO"));

    g_signal_connect(G_OBJECT(YES), "clicked", G_CALLBACK(gtk_main_quit), (gpointer) Exit);                   //LINK POP UP EXIT BUTTONS TO ITS FUNCTIONS
    g_signal_connect(G_OBJECT(NO), "clicked", G_CALLBACK(Hide), (gpointer) Exit);

    gtk_widget_show(Exit);                                                                                   ///////////////////////////
}

void Hide(GtkWidget *widget, gpointer window) {
    gtk_widget_hide(window);                                                                                        //hide a window
}