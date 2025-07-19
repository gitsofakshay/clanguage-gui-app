#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Load the UI from Glade file
    GtkBuilder *builder = gtk_builder_new_from_file("main.ui");

    // Get window and widgets by ID
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    GtkWidget *button = GTK_WIDGET(gtk_builder_get_object(builder, "my_button"));

    // Connect signals
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(gtk_main_quit), NULL); // You can replace this with custom function

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
