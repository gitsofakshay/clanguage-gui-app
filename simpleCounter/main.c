#include <gtk/gtk.h>

// Global counter
int count = 0;

// Click event handler
void on_button_clicked(GtkButton *button, gpointer user_data) {
    GtkLabel *label = GTK_LABEL(user_data);

    // Update count
    count++;

    // Convert count to string and update label
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "Count: %d", count);
    gtk_label_set_text(label, buffer);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Load UI
    GtkBuilder *builder = gtk_builder_new_from_file("main.ui");

    // Get widgets
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    GtkWidget *button = GTK_WIDGET(gtk_builder_get_object(builder, "count_button"));
    GtkWidget *label = GTK_WIDGET(gtk_builder_get_object(builder, "count_label"));

    // Connect signals
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), label);

    // Show UI
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
