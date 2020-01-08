#include <string.h>
#include <libgen.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include<sys/wait.h>
#include<unistd.h>


    gchar *filename; 
    GtkFileChooser *dialogue;
     GtkWidget *dialog;
     GSList  *file;
    
int main(int argc, char *argv[]) {
    gint id;
    gtk_init(&argc, &argv);
    
    dialog = gtk_file_chooser_dialog_new("Open Multiple Images", NULL,GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,GTK_STOCK_CANCEL,GTK_RESPONSE_REJECT,NULL);
    
    gtk_file_chooser_set_select_multiple (GTK_FILE_CHOOSER(dialog),1);
      id = gtk_dialog_run(GTK_DIALOG(dialog));
      if(GTK_RESPONSE_ACCEPT == id){    
          if(gtk_file_chooser_get_select_multiple (GTK_FILE_CHOOSER(dialog)));
               file = gtk_file_chooser_get_files (GTK_FILE_CHOOSER(dialog));
      }


}
//gtk_font_selection_dialog_new("Choose A Font");
