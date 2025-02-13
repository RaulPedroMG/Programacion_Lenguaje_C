/* comienzo del ejemplo helloworld */
#include <gtk/gtk.h>
/* Ésta es una llamada de respuesta (callback). Sus argumentos
son ignorados por en este ejemplo */
void hello (GtkWidget *widget, gpointer data)
{
	g_print ("Hello World\n");
}
gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	g_print ("delete event occured\n");
/* si se devuelve FALSE al administrador de llamadas "delete_event"
GTK emitirá
* la señal de destrucción "destroy". Esto es útil para diálogos pop
up del
* tipo: ¿Seguro que desea salir?*/
/* Cambiando TRUE por FALSE la ventana será destruida con
"delete_event"*/
	return (TRUE);
}
/* otra respuesta */
void destroy (GtkWidget *widget, gpointer data)
{
	gtk_main_quit ();
}
int main (int argc, char *argv[])
{
/* GtkWidget es el tipo de almacenamiento usado para los widgets */
	GtkWidget *window;
	GtkWidget *button;
/* En cualquier aplicación hay que realizar la siguiente llamada.
* Los argumentos son tomados de la línea de comandos y devueltos
* a la aplicación. */
	gtk_init (&argc, &argv);
/* creamos una ventana nueva */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
/* Cuando la ventana recibe la señal "delete_event" (emitida por el
gestor
* de ventanas, normalmente mediante la opción 'close', o en la barra
del
* título) hacemos que llame a la función delete_event() tal y como
ya hemos
* visto. Los datos pasados a la función de respuesta son NULL e
ignorados. */
	gtk_signal_connect (GTK_OBJECT (window), "delete_event",
	GTK_SIGNAL_FUNC (delete_event), NULL);
/* Aquí conectamos el evento "destroy" con el administrador de
señales. El
* evento se produce cuando llamamos a gtk_widget_destroy() desde la
ventana
* o si devolvemos 'FALSE' en la respuesta "delete_event". */
	gtk_signal_connect (GTK_OBJECT (window), "destroy",
	GTK_SIGNAL_FUNC (destroy), NULL);
/* establecemos el ancho del borde de la ventana. */
	gtk_container_border_width (GTK_CONTAINER (window), 10);
/* creamos un botón nuevo con la
etiqueta "Hello World" */
	button = gtk_button_new_with_label ("Hello World");
/* Cuando el botón recibe la señal "clicked" llama a la función
	hello() pasándole
* NULL como argumento. (La función ya ha sido definida arriba). */
	gtk_signal_connect (GTK_OBJECT (button), "clicked",
	GTK_SIGNAL_FUNC (hello), NULL);
/* Esto hará que la ventana sea destruida llamando a
	gtk_widget_destroy(window)
* cuando se produzca "clicked". Una vez mas la señal de destrucción
puede
* provenir del gestor de ventanas o de aquí. */
	gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
	GTK_SIGNAL_FUNC (gtk_widget_destroy),
	GTK_OBJECT (window));
/* Ahora empaquetamos el botón en la ventana (usamos un gtk container
). */
	gtk_container_add (GTK_CONTAINER (window), button);
/* El último paso es representar el nuevo widget... */
	gtk_widget_show (button);
/* y la ventana */
	gtk_widget_show (window);
/* Todas las aplicaciones basadas en GTK deben tener una llamada
	gtk_main()
* Ya que el control termina justo aquí y debe esperar a que suceda	algún evento */
	gtk_main ();
	return 0;
}
/* final del ejemplo*/
