#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
	GtkWidget *window;
	gtk_init (&argc, &argv);
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_container_add (GTK_CONTAINER (window),
	gtk_label_new ("Hola"));
	gtk_widget_show_all (window);
	gtk_main ();
	return 0;
}

