#include <gtk/gtk.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

    //////////////////////////////////////////////////////////BUTTONS AND LAYOUT VARIABLES//////////////////////////////////////////////////////
    GtkWidget *LPassword,*LEmail,*Connect,*Signup,*Exit;                                                            //Login Variables
    GtkWidget *FName,*LName,*RPassword,*Password,*Email,*Creation,*Return;                                                        //Signup Variables
    GtkWidget *Yes,*No;                                                                                     //PopUp Exit variables
    GtkWidget *OK,*CLOSE;                                                                                   //Waning whole Formula
    GtkWidget *ok,*fermer;                                                                                  //no account popup
    GtkWidget *OKK,*CLOSEE ;                                                                                //Fill Login
    GtkWidget *OKKK,*CLOSEEE ;                                                                              //ACCOUNT CREATED
    GtkWidget *OKUSED,*CLOSEUSED ;                                                                          //USER USED
    GtkWidget *PINOK,*PINCLOSE ;                                                                            //Same PIn
    GtkWidget *can,*okey ;
    GtkWidget *YES,*NO;                                                                                     //Exit POPUP            
    GtkWidget *Okay,*Cancel;                                                                                //Wrong password Pop-up
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////Windows///////////////////////////////////////////////////////////////////
    GtkBuilder *builder;                                                                                    //the glade varialble
    GtkWidget  *LoginWindow,*Sign,*Warning,*SamePin;                                                        //The windows Used
    GtkWidget  *AccountCreated,*AccountError,*AccountEmpty,*UserUsed,*Profile;                                       //The windows Used
    GtkWidget  *LengthError,*Exit,*notepad;                                                                 //The windows Used
    GtkWidget  *Wrongpassword,*NoAccount;                                                                              //The windows Used
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////Variables////////////////////////////////////////////////////////////////////////
    bool test=false;                                                                                        //bool variable
    char word[20],word1[4];                                                                                 //username and pass variable
    FILE *fp;                                                                                               //Declaration of a File
    char buffer[80],x[20];                                                                                  //buffr
    char message[100][20];                                                                                  //all the users table
    char messagepass[100][20];                                                                              //all the passwords
    struct stat st;                                                                                         //struct of a file we used it to see whether a file is empty    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////// THE FUNCTIONS USED //////////////////////////////////////////////////////
    void popup_exit();                                                  //function of popupexit        
    void Signupwindow(GtkWidget *widget,gpointer window);               //function of signup window
    void verifydataSign();                                              //function of verifies signup conditions
    void verifydataLog();                                               //function of verifies Log conditions
    int main(int argc, char *argv[]);                                   //main()
    void Hide (GtkWidget *widget,gpointer window);                      //hide function
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
            Return          = GTK_WIDGET(gtk_builder_get_object(builder,"Return"));                                       //link the glade buttons with c 
    
                       
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
            Exit            = GTK_WIDGET(gtk_builder_get_object(builder,"Exit"));                                       //link all buttons of the login 

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
        


                            /********************************************************************************************
                            *                                                                                           *
                            *                              VERIFY SIGNUP CONDITIONS                                     *
                            *                                                                                           *
                            *********************************************************************************************/

        void verifydataSign(){
            builder = gtk_builder_new_from_file("glade/window_main.glade");                                 ///////////////////////////////////////////
            Warning = GTK_WIDGET(gtk_builder_get_object(builder, "Warning"));                                               
            SamePin = GTK_WIDGET(gtk_builder_get_object(builder, "SamePinError"));
            AccountCreated = GTK_WIDGET(gtk_builder_get_object(builder, "AccountCreated"));
            UserUsed = GTK_WIDGET(gtk_builder_get_object(builder, "UserUsed"));
            int i=0,j=0;
            
                       
            OK      = GTK_WIDGET(gtk_builder_get_object(builder, "OK"));
            CLOSE   = GTK_WIDGET(gtk_builder_get_object(builder, "CLOSE"));
                                                                                                        
            OKKK      = GTK_WIDGET(gtk_builder_get_object(builder, "OKKK"));
            CLOSEEE   = GTK_WIDGET(gtk_builder_get_object(builder, "CLOSEEE"));

            OKUSED    = GTK_WIDGET(gtk_builder_get_object(builder,"OKUSED"));
            CLOSEUSED = GTK_WIDGET(gtk_builder_get_object(builder,"CLOSEUSED")); 

            PINOK     = GTK_WIDGET(gtk_builder_get_object(builder, "PINOK"));
            PINCLOSE   = GTK_WIDGET(gtk_builder_get_object(builder, "PINCLOSE"));
                                                                                                         

            g_signal_connect(G_OBJECT(OK),"clicked", G_CALLBACK (Hide),(gpointer) Warning);
            g_signal_connect(G_OBJECT(CLOSE),"clicked", G_CALLBACK (Hide), (gpointer)Warning);

            g_signal_connect(G_OBJECT(PINOK),"clicked", G_CALLBACK (Hide),(gpointer) SamePin);
            g_signal_connect(G_OBJECT(PINCLOSE),"clicked", G_CALLBACK (Hide), (gpointer)SamePin);           ////////////////LINK FONCTIONS ///////////////

            g_signal_connect(G_OBJECT(OKKK),"clicked", G_CALLBACK (Hide),(gpointer) AccountCreated);
            g_signal_connect(G_OBJECT(CLOSEEE),"clicked", G_CALLBACK (Hide), (gpointer)AccountCreated);

            g_signal_connect(G_OBJECT(CLOSEUSED),"clicked", G_CALLBACK (Hide),(gpointer) UserUsed);
            g_signal_connect(G_OBJECT(OKUSED),"clicked", G_CALLBACK (Hide), (gpointer)UserUsed);


            if(strcmp(gtk_entry_get_text(GTK_ENTRY(FName)),"\0")==0 || (strcmp(gtk_entry_get_text(GTK_ENTRY(LName)),"\0")==0) || (strcmp(gtk_entry_get_text(GTK_ENTRY(Email)),"\0")==0) || (strcmp(gtk_entry_get_text(GTK_ENTRY(Password)),"\0")==0)|| (strcmp(gtk_entry_get_text(GTK_ENTRY(RPassword)),"\0")==0) )  //if the formilar isnt fully filled condition 
                gtk_widget_show(Warning); 
                
            else if(strcmp(gtk_entry_get_text(GTK_ENTRY(Password)),gtk_entry_get_text(GTK_ENTRY(RPassword)))!=0)            //if pin are similar condition
                gtk_widget_show(SamePin);
            
            else
            {   
                fp=fopen("src/Data.txt","ab");                                                              //open file    
                if (stat("src/Data.txt",&st)==0) {
                    if(st.st_size==0)                                                                               //check file size if 0 fill it with data
                    {   
                        
                        fputs(gtk_entry_get_text(GTK_ENTRY(Email)),fp);                                             
                        fputs("\n",fp);
                        fputs(gtk_entry_get_text(GTK_ENTRY(Password)),fp);
                        fputs("\n",fp);
                        gtk_widget_show(AccountCreated);
                        fclose(fp);                                                                                 //filled with data and closed    
                    }
                    else{
                        fp=fopen("src/Data.txt","r");                                                               //if its not empty read it 
                        while(fgets(buffer,80,fp)){
                            if (i%2!=0)
                            {  
                                i++;
                                continue;
                            }
                            strcpy(message[j],buffer);                                                               //fill table message with user
                            i++;
                            j++;
                            }
                            for (int k=0;k<j;k++) {                                                                  
                                strncpy(word,message[k],strlen(message[k])-1);
                                if(strcmp(gtk_entry_get_text(GTK_ENTRY(Email)),word)==0){                            //compara the entred data with all users in file
                                    test=true;
                                    }
                            }
                            if(test){
                                gtk_widget_show(UserUsed);                                                           //if there is a duplication alert     
                                test=false;
                            }
                            else{
                                fclose(fp);                                                                         //else close file and open it as write privilege
                                fp=fopen("src/Data.txt","ab"); 
                                fputs(gtk_entry_get_text(GTK_ENTRY(Email)),fp);
                                fputs("\n",fp);
                                fputs(gtk_entry_get_text(GTK_ENTRY(Password)),fp);
                                fputs("\n",fp);
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

        void verifydataLog(){

            builder         = gtk_builder_new_from_file("glade/window_main.glade");
            AccountError    = GTK_WIDGET(gtk_builder_get_object(builder,"AccountError"));                          ///////////////////////////////////////////
            AccountEmpty    = GTK_WIDGET(gtk_builder_get_object(builder,"AccountEmpty"));
            Profile         = GTK_WIDGET(gtk_builder_get_object(builder,"Profile"));
            Wrongpassword   = GTK_WIDGET(gtk_builder_get_object(builder,"Wrongpassword"));
            NoAccount       = GTK_WIDGET(gtk_builder_get_object(builder,"NoAccount"));
            notepad         = GTK_WIDGET(gtk_builder_get_object(builder,"Notepad"));
            can             = GTK_WIDGET(gtk_builder_get_object(builder,"can"));
            okey            = GTK_WIDGET(gtk_builder_get_object(builder,"okey"));
            ok              = GTK_WIDGET(gtk_builder_get_object(builder,"ok"));                                     /////////////      LINK BUTTONS  //////////
            fermer          = GTK_WIDGET(gtk_builder_get_object(builder,"fermer"));  
            OKK             = GTK_WIDGET(gtk_builder_get_object(builder,"OKK"));                                                   // & windows
            CLOSEE          = GTK_WIDGET(gtk_builder_get_object(builder,"CLOSEE"));  
            Cancel          = GTK_WIDGET(gtk_builder_get_object(builder,"Cancel")); 
            Okay            = GTK_WIDGET(gtk_builder_get_object(builder,"Okay")); 
            Yes             = GTK_WIDGET(gtk_builder_get_object(builder,"YES"));
            No              = GTK_WIDGET(gtk_builder_get_object(builder,"NO"));                                    /////////////////////////////////////////////
            int i=0,j=0,p=0;

            g_signal_connect(G_OBJECT(Cancel),"clicked", G_CALLBACK (Hide), (gpointer)Wrongpassword);                           //link with functions
            g_signal_connect(G_OBJECT(Okay),"clicked", G_CALLBACK (Hide), (gpointer)Wrongpassword);                             //link with functions

            g_signal_connect(G_OBJECT(can),"clicked", G_CALLBACK (Hide), (gpointer)NoAccount);                           //link with functions
            g_signal_connect(G_OBJECT(okey),"clicked", G_CALLBACK (Hide), (gpointer)NoAccount);                             //link with functions

            g_signal_connect(G_OBJECT(ok),"clicked", G_CALLBACK (Hide), (gpointer)AccountError);                                //link with functions
            g_signal_connect(G_OBJECT(fermer),"clicked", G_CALLBACK (Hide), (gpointer)AccountError);                            //link with functions

            g_signal_connect(G_OBJECT(OKK),"clicked", G_CALLBACK (Hide), (gpointer)AccountEmpty);                               //link with functions
            g_signal_connect(G_OBJECT(CLOSEE),"clicked", G_CALLBACK (Hide), (gpointer)AccountEmpty);                            //link with functions

            
            if(strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)),"\0")==0 || strcmp(gtk_entry_get_text(GTK_ENTRY(LPassword)),"\0")==0){      //if name or pin arent filled condition
                gtk_widget_show(AccountEmpty);
            }
            
            if(strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)),"\0")!=0 && strcmp(gtk_entry_get_text(GTK_ENTRY(LPassword)),"\0")!=0 ){     //if both of them are filled condition
            
                fp=fopen("src/Data.txt","r");                                                                                   //open a file and only read         
                    while(fgets(buffer,80,fp)){                                                                                 //while there is a line enter to the loop
                        if(i%2==0){                                                                                             
                            strcpy(message[j],buffer);                                                                          //table message is being filled with names
                            j++;
                            i++;
                            continue;
                        }
                        if(i%2!=0){
                            strcpy(messagepass[p],buffer);                                                                      //table messagepass is being filled with password
                            p++;                                                                                                    
                            i++;
                            continue;
                        }
                    }
                fclose(fp);                                                                                                     //close file
                    
                    for (int k=0;k<j;k++){
                        
                        strncpy(word,message[k],strlen(message[k])-1);                                                          //this is used to delete the '\n' because when you get data from a file \n is the symbol of an end of line in buffer
                        strncpy(word1,messagepass[k],strlen(messagepass[k])-1);                                                 //this is used to delete the '\n' because when you get data from a file \n is the symbol of an end of line in buffer
                            
                            if(strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)),word)==0 && strcmp(gtk_entry_get_text(GTK_ENTRY(LPassword)),word1)!=0){
                                gtk_widget_show(Wrongpassword);
                            }
                            if(strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)),word)!=0){
                                gtk_widget_show(NoAccount);
                            }
                            
                            if(strcmp(gtk_entry_get_text(GTK_ENTRY(LEmail)),word)==0 && strcmp(gtk_entry_get_text(GTK_ENTRY(LPassword)),word1)==0) {    //if data corresponds to info in the file
                               // gtk_window_set_title(GTK_WINDOW(notepad),gtk_entry_get_text(GTK_ENTRY(Name)));                                  //open notepad and name it the name of a user
                               // gtk_widget_hide(AccountEmpty);
                               // gtk_widget_show(notepad);
                                  gtk_window_set_title(GTK_WINDOW(Profile),"Welcome");
                                  gtk_widget_show(Profile);
                            }
                    }
            }

        }
        
        //////////////////////////////////////////////////////////////////////////////////////
        ///                                  POP UP EXIT                                    //
        //////////////////////////////////////////////////////////////////////////////////////    

        void popup_exit(){
            builder  = gtk_builder_new_from_file("glade/window_main.glade");                                         ////////////////////////////////
            Exit     = GTK_WIDGET(gtk_builder_get_object(builder,"EXITPOPUP"));
            YES      = GTK_WIDGET(gtk_builder_get_object(builder,"YES"));
            NO       = GTK_WIDGET(gtk_builder_get_object(builder,"NO"));
                                                                                                                   
            g_signal_connect(G_OBJECT(YES),"clicked", G_CALLBACK (gtk_main_quit), (gpointer)Exit);                   //LINK POP UP EXIT BUTTONS TO ITS FUNCTIONS
            g_signal_connect(G_OBJECT(NO),"clicked", G_CALLBACK (Hide), (gpointer)Exit);

            gtk_widget_show(Exit);                                                                                   ///////////////////////////   
        }
         void Hide(GtkWidget *widget,gpointer window){
            gtk_widget_hide(window);                                                                                        //hide a window
        }
