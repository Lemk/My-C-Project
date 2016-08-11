#include <gtk/gtk.h>

static void on_window_closed (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{
    GtkWidget *window, *label;

    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK(on_window_closed), NULL);
    label = gtk_label_new (NULL);
    
    gtk_label_set_markup (GTK_LABEL(label),
            "<small>Kleiner Text</small>\n"
            "<big>Large</big>\n"
            "<b>Fett</b>\n"
            "<span foreground=\"#ff0000\">ROT</span>");
    
    gtk_label_set_angle (GTK_LABEL(label), 45);
    gtk_container_add (GTK_CONTAINER(window), label);
    gtk_window_set_title (GTK_WINDOW(window), "Mein kleines Fenster");
    gtk_window_set_default_size (GTK_WINDOW(window), 640, 480);
    gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
    gtk_widget_show_all (window);
    gtk_main ();

    return 0;
}
