#include <string.h>
#include <libgen.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include<sys/wait.h>
#include<unistd.h>

    gchar *filename; 

int main(int argc, char *argv[]) {
    gint id;
    gtk_init(&argc, &argv);
    GtkWidget *dialog;
    
    dialog = gtk_file_chooser_dialog_new("Open An Image", NULL,GTK_FILE_CHOOSER_ACTION_OPEN,GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,GTK_STOCK_CANCEL,GTK_RESPONSE_REJECT,NULL);
    
      id = gtk_dialog_run(GTK_DIALOG(dialog));
      if(GTK_RESPONSE_ACCEPT == id){    
          filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
          g_print("%s",filename);
            

      }


}
//gtk_font_selection_dialog_new("Choose A Font");
