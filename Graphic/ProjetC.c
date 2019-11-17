#include <gtk/gtk.h>
gboolean destroy (GtkWidget *widget){
    gtk_widget_destroy (widget);                                                                                 //destroy a button
    return TRUE;
}
/******************************************************************************
 *                             SIGN UP WINDOW
 * ****************************************************************************/
/*void Welcome (GtkWidget *widget){
GtkWidget *window;
 window = gtk_window_new ();
*/
void ADD_IMG(GtkWidget *button,gpointer window ){
    /*GtkWidget *dialog;
    //dialog=gtk_file_chooser_dialog_new("choose an img",GTK_WINDOW(window),GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,NULL);

GtkWidget *dialog;

dialog = gtk_file_chooser_dialog_new ("Save File",GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);
gtk_file_chooser_set_do_overwrite_confirmation (GTK_FILE_CHOOSER (dialog), TRUE);
*/
//GtkWidget *btn;

  button = gtk_file_chooser_button_new ("Select a file", GTK_FILE_CHOOSER_ACTION_OPEN);
  gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (button));
}

void SignUp(GtkWidget *widget){
    GtkWidget *window, *button, *box;

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "SIGN UP");                                                      //title second window
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);                                                //spacing between lines
    gtk_window_set_default_size(GTK_WINDOW(window),400,400);                                                    //default
    gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);                                          //center  
    g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), widget);
    GtkWidget *grid = gtk_grid_new();                     
    gtk_container_add(GTK_CONTAINER(window),grid);
    gtk_grid_set_row_spacing(GTK_GRID(grid),30);                                                                  //espacement bin les lignes
    gtk_grid_set_column_spacing(GTK_GRID(grid),5);                                                               //espacement bin les colones
    gtk_widget_set_valign(grid,GTK_ALIGN_CENTER);                                                                 //center ligne
    gtk_widget_set_halign(grid,GTK_ALIGN_CENTER);                                                                 //center colone
    int col=0,row=0;                                                                                            //preparation des places
    GtkWidget *label_user=gtk_label_new("UserName");                                                            //print USERNAME
    gtk_grid_attach(GTK_GRID(grid),label_user,col,row,1,1);                                                     //affecter il border
    col++;                                                                                                      //partie 2 du ligne 0 
    GtkWidget *entry_user=gtk_entry_new();                                                                      //input
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_user),"UserName");                                           //placeholder
    gtk_grid_attach(GTK_GRID(grid),entry_user,col,row,1,1);                                                     //affecter il bordor
    col=0;row++;                                                                                                //nouveau ligne
    GtkWidget *label_pass=gtk_label_new("PIN");                                                                 //print pin
    gtk_grid_attach(GTK_GRID(grid),label_pass,col,row,1,1);                                                     //bordor
    col++;                                                                                                      //2eme partie du ligne
    GtkWidget *entry_pass=gtk_entry_new();                                                                      //input
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_pass),"PIN");                                                //placeholder
    gtk_entry_set_max_length(GTK_ENTRY(entry_pass),4);                                                          //max 4 char
    gtk_entry_set_visibility(GTK_ENTRY(entry_pass),FALSE);                                                      //hash
    gtk_grid_attach(GTK_GRID(grid),entry_pass,col,row,1,1);                                                     //bordor

    col=0;row++;                                                                                                //nouveau ligne
      GtkWidget *label_pass1=gtk_label_new("Re-enter PIN");                                                     //print reenter PIN    
      gtk_grid_attach(GTK_GRID(grid),label_pass1,col,row,1,1);                                                  //bordor
        col++;                                                                                                  //2eme partie du ligne          
        GtkWidget *entry_pass1=gtk_entry_new();                                                                 //input
        gtk_entry_set_placeholder_text(GTK_ENTRY(entry_pass1),"PIN");                                           //placeholder
        gtk_entry_set_max_length(GTK_ENTRY(entry_pass1),4);                                                     //max 4 chars
        gtk_entry_set_visibility(GTK_ENTRY(entry_pass1),FALSE);                                                 //dashed
        gtk_grid_attach(GTK_GRID(grid),entry_pass1,col,row,1,1);                                                //bordor  

  col=0;row++;                                                                                                  //new line
    GtkWidget *btn1=gtk_button_new_with_label("Sign-up");                                                       //signup buton
    //gtk_widget_set_hexpand(btn1,FALSE);
    //gtk_widget_set_vexpand(btn1,FALSE);
    //gtk_widget_set_halign(btn1,GTK_ALIGN_CENTER);
    //gtk_widget_set_valign(btn1,GTK_ALIGN_CENTER);
    //gtk_widget_set_size_request(btn1,300,50);
    gtk_grid_attach(GTK_GRID(grid),btn1,col,row,2,1);                                                           //bordor

  gtk_widget_show_all(window);                                                                                  //print the window
}

/**************************************************************************************
//                          LOGIN WINDOW
**************************************************************************************/
static void startApplication(GtkApplication *app,gpointer data) {
  GtkWidget *window=gtk_application_window_new(app);
  
  gtk_window_set_title(GTK_WINDOW(window),"Login Plateforme");                                                  //title
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);                                               //center
  //gtk_window_set_default_size(GTK_WINDOW(window),600,200);                                                      //size
/*
  //
  GtkWidget *layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window), layout);
    gtk_widget_show(layout);
  
  GtkWidget *image = gtk_image_new_from_file("/home/amine/Pictures/Wallpapers/1040734.jpg");
  gtk_layout_put(GTK_LAYOUT(layout), image, 0, 0);
  */
  gtk_container_set_border_width(GTK_CONTAINER(window),40);                                                     //border

  GtkWidget *grid = gtk_grid_new();                     
  gtk_container_add(GTK_CONTAINER(window),grid);
  gtk_grid_set_row_spacing(GTK_GRID(grid),30);                                                                  //espacement bin les lignes
  gtk_grid_set_column_spacing(GTK_GRID(grid),5);                                                               //espacement bin les colones
  gtk_widget_set_valign(grid,GTK_ALIGN_CENTER);                                                                 //center ligne
  gtk_widget_set_halign(grid,GTK_ALIGN_CENTER);                                                                 //center colone

  int col=0,row=0;                                                                                              //initialize
  GtkWidget *label_user=gtk_label_new("UserName");                                                              //print
  gtk_grid_attach(GTK_GRID(grid),label_user,col,row,1,1);                                                       //bordor
  col++;                                                                                                        //partie2
  GtkWidget *entry_user=gtk_entry_new();                                                                        //input
  gtk_entry_set_placeholder_text(GTK_ENTRY(entry_user),"UserName");                                             //placeholder
  gtk_grid_attach(GTK_GRID(grid),entry_user,col,row,1,1);                                                       //bordor
  col=0;row++;                                                                                                  //2eme partie
  GtkWidget *label_pass=gtk_label_new("PIN");                                                                   //print pin
  gtk_grid_attach(GTK_GRID(grid),label_pass,col,row,1,1);                                                       //bordor
  col++;                                                                                                        //2eme partie
  GtkWidget *entry_pass=gtk_entry_new();                                                                        //input
  gtk_entry_set_placeholder_text(GTK_ENTRY(entry_pass),"PIN");                                                  //placeholder    
  gtk_entry_set_max_length(GTK_ENTRY(entry_pass),4);                                                            //max 4 char  
  gtk_entry_set_visibility(GTK_ENTRY(entry_pass),FALSE);                                                        //hashed    
  gtk_grid_attach(GTK_GRID(grid),entry_pass,col,row,1,1);                                                       //bordor
  col=0;row++; 
  
  button = gtk_file_chooser_button_new ("Select a file", GTK_FILE_CHOOSER_ACTION_OPEN);
  gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (button),"/home"); 
  /*GtkWidget *btnn=gtk_button_new_with_label("Add-Image");
    gtk_grid_attach(GTK_GRID(grid),btnn,col,row,2,1);
  g_signal_connect(btnn,"clicked",G_CALLBACK(ADD_IMG),window);
  *///img=gtk_image_new_from_icon_name(GTK_STOCK_NEW,GTK_ICON_SIZE_DIALOG);
  col=0;row++;                                                                                                  //new line  
  GtkWidget *btn=gtk_button_new_with_label("Connect");                                                          //button
  //gtk_widget_set_size_request(btn,450,50);
  gtk_grid_attach(GTK_GRID(grid),btn,col,row,2,1);                                                              //bordor

  col=0;row++;                                                                                                  //new line
  GtkWidget *btn1=gtk_button_new_with_label("Sign-up");                                                         //button  
  gtk_grid_attach(GTK_GRID(grid),btn1,col,row,2,1);                                                             //bordor  
  g_signal_connect(G_OBJECT(btn1), "clicked", G_CALLBACK (SignUp), (gpointer) window);                          //appel function signup
  
  col=0;row++;                                                                                                  //new line
  GtkWidget *btn2=gtk_button_new_with_label("EXIT");                                                            //exit button
  g_signal_connect_swapped (btn2,"clicked", G_CALLBACK (gtk_widget_destroy), window);                           //leave the interface onclick
  gtk_grid_attach(GTK_GRID(grid),btn2,col,row,2,1);                                                             //bordor
  gtk_widget_show_all(window);                                                                                  //print console  
}
/*************************************************************************************
//                                Programme principal
*************************************************************************************/
int main(int argc,char *argv[]) {
  GtkApplication *app=gtk_application_new("facerecognition.gtk",G_APPLICATION_FLAGS_NONE);                      //app ID  
  g_signal_connect(app,"activate",G_CALLBACK(startApplication),NULL);                                           //appel Procedure
  int status=g_application_run(G_APPLICATION(app),argc,argv);                                                   
  g_object_unref(app);
  return status;
}