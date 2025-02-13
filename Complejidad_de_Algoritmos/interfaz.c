#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
//#include <stdio.h> 
#include <errno.h>

#define CHAR_BUF 5000

GtkWidget *window;
GtkWidget *window2;     /* Top‐level window */ 
GtkWidget *menubar;     /* To hold our sample "File" menu */ 
GtkWidget *menuitem;    /* Used for the "File","New","Open" MenuItems */ 
GtkWidget *submenu;     /* The actual "menu" holding "New", "Open" */ 
GtkAccelGroup *accel;   /* Our accel group */ 
GtkWidget *accel_label; /* Our GtkAccelLabel */ 

GtkWidget *vbox;
GtkWidget *vbox1;
GtkWidget *vbox2;
GtkWidget *hbox;
GtkWidget *hbox1;

GtkWidget *vbox2_1;
GtkWidget *hbox2_1;
GtkWidget *hbox2_2;
GtkWidget *hbox2_3;

GtkWidget *text_view;
GtkWidget *text_view2;
GtkWidget *entry;

GtkWidget *button;
GtkWidget *image;
GtkWidget *image2;
GtkWidget *label;

GtkTextTag *tag;


GtkTextBuffer *buf;
GtkTextBuffer *buf2;
int veces_generar_aut = 0, fil=0, col=0, Eaceptacion=0;

char *text;
char *filename;
gboolean if_automata = FALSE;
int cont = 0, ind_text = -1;
char* Estados;  /* puntero a vector char de estados */
char* Entrada;  /* puntero a vector char de entradas */
char **mat;
char* aceptacion;
int Eini;
gboolean val_mat_trans = TRUE;
char estado;

void funcion_parser();
char* crea_vector(int);
void genera_Grafo(char *ent, int lent, char *est, int lest, char ini, char *acep, int lacep, char **mat);

//static void menuitem_response (gchar *);

static void cargar_archivo(char *fname)
{
    FILE *f; 

    /* Iterator is an object that represents positions between two characters in a buffer */
    GtkTextIter p;

    char fbuf[CHAR_BUF];
    size_t l; /* read the contents of file in size_t l */
    
    if(!fname) 
    {    /* create file selection dialog */
    GtkWidget *dialog = gtk_file_selection_new("Abrir Archivo...");
    int resp = gtk_dialog_run(GTK_DIALOG(dialog));
    if(resp == GTK_RESPONSE_OK) 
        {   
    /* fname contains the file selected by the user */

            /* show the file selection dialog */
        fname = g_strdup(gtk_file_selection_get_filename(GTK_FILE_SELECTION(dialog)));
        gtk_widget_destroy(dialog);
    } 
    else 
        {
            /* cancel */
        gtk_widget_destroy(dialog);
        return;
    }
    }

    if(!(f = fopen(fname, "r"))) /* if file cannot be opened */
    {
        g_printerr("%s: %s\n", fname, g_strerror(errno));
        return;
    }


    /*if(fname != filename) 
    {
        gchar *wt = g_strdup_printf("Text Editor (%s)", fname);
        g_free(filename);
        filename = fname;*/
            /* set titlebar as the file name */
        /*gtk_window_set_title(GTK_WINDOW(window), wt);
        g_free(wt);
    }*/

    /* put the ending iterator in p of buffer */
    gtk_text_buffer_get_end_iter(buf, &p);

    while((l = fread(fbuf, 1, sizeof(fbuf), f)) > 0) 
    {
        /* only text files in Utf-8 format can be opened */
    
    GError *err = NULL;
    gsize br, bw;
    gchar *text_t;
    if(!(text_t = g_locale_to_utf8(fbuf, l, &br, &bw, &err))) 
    {
        g_printerr("File is not in UTF-8 format : %s\n", err->message);
        g_clear_error(&err);
            filename = NULL; /* If an invalid file is opened enter the file name as NULL */
        gtk_window_set_title(GTK_WINDOW(window), "Autómata... (Insert file name)");
        fclose(f);

        return;
    }
    gtk_text_buffer_insert(buf, &p, text_t, bw);
    g_free(text_t);
    }

    
    gtk_text_buffer_set_modified(buf, FALSE);
    
    gtk_text_buffer_get_start_iter(buf, &p);
    gtk_text_buffer_place_cursor(buf, &p);
    if(ferror(f)) 
    {
    g_printerr("%s: %s\n", fname, g_strerror(errno));
    fclose(f);
    return;
    }
    if(fclose(f) == EOF)
    g_printerr("%s: %s\n", fname, g_strerror(errno));
} 


static gboolean guardar(char *fname)
{
    FILE *f;
    int ok = TRUE;
    
    if(!fname) 
    {
        GtkWidget *dialog = gtk_file_selection_new("Guardar como...");
        int resp = gtk_dialog_run(GTK_DIALOG(dialog));
        if(resp == GTK_RESPONSE_OK) {
            fname = g_strdup(
            gtk_file_selection_get_filename(GTK_FILE_SELECTION(dialog)));
            gtk_widget_destroy(dialog);
        } else {
            gtk_widget_destroy(dialog);
            return FALSE;
        }
    }

    if(!(f = fopen(fname, "w")))  /* Error opening file */
    {
        g_printerr("%s: %s\n", fname, g_strerror(errno));
        ok = FALSE;
    } else {
        GtkTextIter start, end, p;

        /* get the starting and ending position */

        gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buf), &start, &end);
        p = start;
        while(!gtk_text_iter_equal(&start, &end)) 
        {
            gchar *buf, *fbuf;
            gsize br, bw;
            GError *err = NULL;
            gtk_text_iter_forward_chars(&p, CHAR_BUF);
            buf = gtk_text_iter_get_slice(&start, &p);
            fbuf = g_locale_from_utf8(buf, -1, &br, &bw, &err);
            g_free(buf);

            if(!fbuf) 
            {
                g_printerr("Fallo UTF-8 conversión local: %s\n",
                   err->message);
                g_clear_error(&err);
                ok = FALSE;
                break;
            }
            fwrite(fbuf, bw, 1, f);
            g_free(fbuf);
            if(ferror(f)) {
                g_printerr("%s: %s\n", fname, g_strerror(errno));
                ok = FALSE;
                break;
            }
            start = p;
        }
        if(fclose(f) == EOF) 
        {
            g_printerr("%s: %s\n", fname, g_strerror(errno));
            ok = FALSE;
        }
    }
    if(ok) 
    {
        gtk_text_buffer_set_modified(buf, FALSE);
        if(fname != filename) {
            gchar *wt = g_strdup_printf("TextView (%s)", fname);
            g_free(filename);
            filename = fname;
            gtk_window_set_title(GTK_WINDOW(window), wt);
            g_free(wt);
        }
    }
    return ok;
}

static gboolean guardar_modificado(void)
{
    int resp;
    GtkWidget *dialog;

    if(!gtk_text_buffer_get_modified(GTK_TEXT_BUFFER(buf)))
    return TRUE;

    dialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_QUESTION,
                    GTK_BUTTONS_NONE,
                    "Hay cambios de texto. ¿Desea Guardar los cambios?");
    gtk_dialog_add_buttons(GTK_DIALOG(dialog), GTK_STOCK_YES, GTK_RESPONSE_YES,
               GTK_STOCK_NO, GTK_RESPONSE_NO,
               GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);
    resp = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    switch(resp) {
    case GTK_RESPONSE_YES:
    return guardar(filename);
    case GTK_RESPONSE_NO:
    return TRUE;
    case GTK_RESPONSE_CANCEL:
    case GTK_RESPONSE_DELETE_EVENT:
    return FALSE;
    default:
    g_printerr("Error %d de dialogo\n", resp);
    return FALSE;
    }
}

void abrir_archivo (GtkWidget *widget, gpointer data)
{
    if(guardar_modificado()) 
    {
        /* call save if modified wen user opens a new file */
        buf = gtk_text_buffer_new(gtk_text_buffer_get_tag_table(buf));
        gtk_text_view_set_buffer(GTK_TEXT_VIEW(text_view), buf);

        /* needed for freeing memory by the buffer wen a new buffer is created */
        g_object_unref(G_OBJECT(buf));
        cargar_archivo(NULL);
    }
}
void guardar_archivo_como (){
    guardar(NULL);
}

void guardar_archivo_txt ();
void obtener_texto_text_view ();

void guardar_archivo (){
    guardar(filename);
}

void salir (){
    if (guardar_modificado())
        gtk_widget_destroy(window);   
}

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    return !guardar_modificado();
}

static gboolean poner_image (){
    if(val_mat_trans == TRUE){
        gtk_image_set_from_file(GTK_IMAGE (image), "automata1.png");
    }
    else{
        gtk_image_set_from_file(GTK_IMAGE (image), NULL);
    }
}

static gboolean poner_image_reconocedor (){
    if(val_mat_trans == TRUE){
        gtk_image_set_from_file(GTK_IMAGE (image2), "automata1.png");
    }
    else{
        gtk_image_set_from_file(GTK_IMAGE (image2), NULL);
    }
}

void poner_boton_guardar_imagen (){
    
}

void generar_automata (GtkWidget *widget, gpointer data){
    if_automata = TRUE;
    obtener_texto_text_view();
    guardar_archivo_txt();
    funcion_parser();
    //gdk_threads_add_timeout(0000, poner_image, NULL);
    poner_image();
    //gdk_threads_add_timeout(1000, poner_image, NULL );
}

void trans(){
    int lacep=Eaceptacion;

    printf("\n Trans : long cadena de estradas %d ", col);
    printf("\n Trans : long cadena de estados %d ", fil);
    printf("\n Trans : long cadena de acep %d ", lacep);
    
    printf("funcion trans %c",estado);
    

    FILE *fp;
    char a[]="automataT";
    char aux[9];
    strcpy(aux,a);
    char ext[]=".dot";
    fp=fopen(strcat(a,ext),"w");
    int i,j;
    fprintf(fp,"%s","digraph g{");
    fprintf(fp,"\n%s","rankdir=\"LR\";size=\"5,7;\"\n");
    //fprintf(fp,"\n%s","rankdir=\"LR\";\n");
    //nodo en blanco
    fprintf(fp,"%s\n","\nnode [shape = point, color=white, fontcolor=white]; start;");
        //finales
    for(i=0;i<lacep;i++){
            fprintf(fp,"%s %c;\n","node [shape = doublecircle, color=black, fontcolor=black]",aceptacion[i]);
            
        }
    fprintf(fp,"node [shape = circle];");
    
    
    //funcion de transicion
    fprintf(fp,"%s %c;\n","start->",Eini);
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
                fprintf(fp,"%c %s %c %s %c %s;\n",Estados[i],"->",mat[i][j],"[label=\"",Entrada[j],"\"]");
            }
        }
    fprintf(fp,"%c %s",estado,"[color=red,style=filled];");
    fprintf(fp,"\n%s","}");
    fclose(fp);
    char p1[]="dot -Tpng ";
    char p3[]=" -o ";
    char p5[]=".png";
    strcat(p1,a);
    strcat(p1,p3);
    
    strcat(aux,p5);
    system(strcat(p1,aux));

}

int buscar_cadena (char char_buscar, char cadena[], int numero_carac){
    int i = 0;
    while(cadena[i] != char_buscar && i < numero_carac) i++;
    if (cadena[i] == char_buscar)
        return i;
    else
        return -1;
}

static gboolean reconoce_cadena (){

    //char cadena[100];
    //char inicial = Eini;
    int longi_cad;
    int ind, ind2;
    //int val, otro;
    
    longi_cad=strlen(text);

    printf("\n*************************\n");

    //printf("\n\nLa longitud de la cadena es %d\n\n",longi_cad);//longitud de la cadena
    //sleep ("0.5");
    //int longi_estados = strlen(Estados);
    //printf("\n\nLa longitud de estados es %d\n\n",longi_estados);//longitud de la cadena

    //int longi_entrada = strlen(Entrada);
    //printf("\n\nLa longitud de entrada es %d\n\n",longi_entrada);//longitud de la cadena
    
    // validando la cadena
    /*k=0;
    while(band==0 && k <longi_cad){
        j=buscar_cadena(cadena[k], Entrada, longi_cad);
        //printf("\n\n******\n");
        printf("cadena[%d] = %c, el valor de j es :%d \n",k, cadena[k], j);
        if(j==-1){
            band=1;
            }
        k++;
    }*/
    //if(band==0){
    //i=0;
    //j=0;
    //while(i < longi_cad) printf("\n%c", text[i]), i++, printf("\n");
    //while(j < strlen(Entrada)) printf("\n%c", Entrada[j]), j++, printf("\n");
   
    //i = -1;
    //while(i <= longi_cad){
    if(ind_text == -1){
        estado = Eini;
        //trans(estado);
    } 
    else{
        if(ind_text <= longi_cad){
            printf("\n Estado : %c\n", estado);
            trans(estado);
            /*printf("\n Trans : long cadena de estradas %d ", col);
            printf("\n Trans : long cadena de estados %d ", fil);
            printf("\n Trans : long cadena de acep %d ", Eaceptacion);*/
        }
        if(ind_text < longi_cad){
            ind = buscar_cadena (estado, Estados, strlen(Estados));
            ind2 = buscar_cadena (text[ind_text], Entrada, strlen(Entrada));
            estado = mat[ind][ind2];
            //printf("\nLlegando antes del trans\n\n");
            //printf(" i : %d\n", i);
        }
    }
        
        //trans(estado);
    
        //i++;
    //}
    //printf("\n Estado : %c", estado);
    if (ind_text == -1)
    {
        trans(estado);
        gtk_image_set_from_file(GTK_IMAGE (image2), "automataT.png");
    }
    printf("\n ind_text : %d\n", ind_text);
    ind_text++;
    if(ind_text == (strlen(text)+2))
    {
        ind = buscar_cadena (estado, aceptacion, strlen(aceptacion));
        if(ind >= 0) printf("\nLa cadena es aceptada\n");
        else{printf("\nLa cadena no es aceptada\n");}
        printf("\n\n");
    }
    if(ind_text < strlen(text)){
        gdk_threads_init ();
    }
    //veces_generar_aut++;
    gdk_threads_leave();
    //}else{
    //    printf("\nLa cadena es incorrecta\n\n");
    //}
}

static gboolean pintar_letra(){
    //GtkTextTag *tag;
    GtkTextBuffer *buffer2;
    GtkTextIter start;
    GtkTextIter end;
    //char contador[2];
    //char *tag_char;

    buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW (text_view2));
    gtk_text_buffer_set_text (buffer2, text, -1);

    /*buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW (text_view2));
    printf("cont : %d de pintar\n\n", cont);*/
    /*GtkTextBuffer *buffer;
    GtkTextIter start;
    GtkTextIter end;
    GtkTextTag *tag;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (text_view2));

    tag = gtk_text_buffer_create_tag (buffer, "blue_foreground", "foreground", "green", NULL);

    gtk_text_buffer_get_iter_at_offset (buffer, &start, cont);
    gtk_text_buffer_get_iter_at_offset (buffer, &end, cont+1);
    gtk_text_buffer_apply_tag (buffer, tag, &start, &end);*/

    //contador = (char)(cont + 48);

    //strcpy(tag_char, contador);

    //printf("contador : %c de pintar\n\n", contador);
    
    if(cont < strlen(text)){
        gtk_text_buffer_get_iter_at_offset (buffer2, &start, cont);
        gtk_text_buffer_get_iter_at_offset (buffer2, &end, cont+1);
        
        gtk_text_buffer_apply_tag (buffer2, tag, &start, &end);    
    }else{
        gtk_text_buffer_set_text (buffer2, text, -1);
        cont--;
    }

    printf("cont = %d\n", cont);
    gtk_image_set_from_file(GTK_IMAGE (image2), "automataT.png");
    cont++;
    if(cont < strlen(text)){
        gdk_threads_init ();
    }
    //veces_generar_aut++;
    gdk_threads_leave();
}

void interaccion_Reconocedor(int i){
    //gdk_threads_add_timeout((i)*2000, pintar_letra, NULL);
    if(i <= strlen(text)){
        gdk_threads_add_timeout_seconds((i+1) * 3, pintar_letra, NULL);
    }
    if(i == 0){
        reconoce_cadena();
    }else{
        if(i == 1){
            gdk_threads_add_timeout_seconds((i+1), reconoce_cadena, NULL);
        }
        else{
            if(i == strlen(text)+1)
                gdk_threads_add_timeout_seconds(((((i-2)*2)+3)+i)+3, reconoce_cadena, NULL);
            else
                gdk_threads_add_timeout_seconds(((((i-2)*2)+3)+i), reconoce_cadena, NULL);
        }
    }
        
    //gdk_threads_leave();
    //printf("cont : %d de Inter\n\n", cont);
}

gboolean validar_cadena(){
    int band = 0, k=0, j;
    while(band==0 && k < strlen(text)){
        j=buscar_cadena(text[k], Entrada, (strlen(Entrada)-1));
        //printf("\n\n******\n");
        printf("cadena[%d] = %c, el valor de j es :%d \n",k, text[k], j);
        if(j==-1){
            band=1;
        }
        k++;
    }
    if (band == 0)
        return TRUE;
    else
        return FALSE;
}


void boton_Reconocer(){
    gdk_threads_init ();
    GtkTextBuffer *buffer;
    GtkTextIter start;
    GtkTextIter end;
    int i;
    text = "";
    cont = 0;
    ind_text = -1;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (text_view2));
    if(veces_generar_aut == 0)
        tag = gtk_text_buffer_create_tag (buffer, "green_foreground", "foreground", "blue", NULL);

    gtk_text_buffer_get_start_iter (buffer, &start);
    gtk_text_buffer_get_end_iter (buffer, &end);

    text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);

    if (validar_cadena() == TRUE){
        for (i = 0; i <= strlen(text)+1; ++i){
            interaccion_Reconocedor(i);
        }
        reconoce_cadena ();
    }
    else{
        printf("\n***La cadena es incorrecta***\n");
    }

    //for (i = 0; i <= strlen(text); ++i)
    //{   
        //pintar_letra();
        //interaccion_Reconocedor(i);
        //gtk_text_buffer_set_text (buffer, text, -1);
        //system("sleep 3");
    //}

    printf("\nEl text view contiene : \n%s\n con longitud de : %d\n\n", text, strlen(text));
    veces_generar_aut++;

    gdk_threads_init ();
    //while(cont < strlen(text)) gdk_threads_add_timeout(1000, interaccion_Reconocedor, NULL), ++cont;

}

void ventana_Reconocer(){
    if(gtk_text_buffer_get_modified(GTK_TEXT_BUFFER(buf)) ||  if_automata == TRUE)
    {
        PangoFontDescription *font_desc;
        //gtk_grab_remove(window);
        window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW (window2), GTK_WIN_POS_CENTER_ALWAYS); 
        gtk_widget_set_size_request (window2, 850, 650);
        //g_signal_connect(G_OBJECT (window2), "delete_event", G_CALLBACK (delete_event), window2);
        //g_signal_connect(G_OBJECT(window2), "destroy",G_CALLBACK(gtk_main_quit), NULL);
        
        gtk_window_set_title (GTK_WINDOW (window2), "Reconocer palabra del Autómata");

        vbox2_1 = gtk_vbox_new (FALSE, 0);
        hbox2_1 = gtk_hbox_new (FALSE, 0);
        hbox2_2 = gtk_hbox_new (FALSE, 0);
        hbox2_3 = gtk_hbox_new (FALSE, 0);

        label = gtk_label_new ("Nota : Si el Autómata de la imagen no es el deseado. \n                  Vuelva a generar el Autómata");

        gtk_box_pack_start (GTK_BOX (vbox2_1), label, FALSE, FALSE, 20);

        //label = gtk_label_new ("        Vuelve a cargar el Autómata");

        //gtk_box_pack_start (GTK_BOX (vbox2_1), label, TRUE, TRUE, 0);



        gtk_box_pack_start (GTK_BOX (vbox2_1), hbox2_1, FALSE, FALSE, 10);

        label = gtk_label_new ("       ");

        gtk_box_pack_start (GTK_BOX (hbox2_1), label, TRUE, TRUE, 5);

        image2 = gtk_image_new();

        gtk_widget_set_usize(GTK_WIDGET (image2), 650, 350);

        gtk_box_pack_start (GTK_BOX (hbox2_1), image2, TRUE, FALSE, 5);

        label = gtk_label_new ("       ");

        gtk_box_pack_start (GTK_BOX (hbox2_1), label, TRUE, TRUE, 5);

        poner_image_reconocedor();

/*_______________________________________________________________________*/

        gtk_box_pack_start (GTK_BOX (vbox2_1), hbox2_2, FALSE, FALSE, 10);

        label = gtk_label_new ("       ");

        gtk_box_pack_start (GTK_BOX (hbox2_2), label, TRUE, TRUE, 0);


        button = gtk_button_new_with_label ("Reconocer");

        gtk_box_pack_start (GTK_BOX (hbox2_2), button, FALSE, FALSE, 20);

        g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (boton_Reconocer), NULL);

        gtk_widget_show(button);

        label = gtk_label_new ("       ");

        gtk_box_pack_start (GTK_BOX (hbox2_2), label, TRUE, TRUE, 0);


/*_______________________________________________________________________*/

        //entry = gtk_entry_new ();
        //buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
        text_view2 = gtk_text_view_new();

        font_desc = pango_font_description_from_string ("Arial 18");
        gtk_widget_modify_font (text_view2, font_desc);
        pango_font_description_free (font_desc);

        buf2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view2));
        //entry = truncate-multiline(FALSE);

        //gtk_widget_set_usize( GTK_WIDGET (text_view2), 100, 40);
        //gtk_widget_set_usize( GTK_WIDGET (text_view), 220, 575);


        gtk_box_pack_start (GTK_BOX (vbox2_1), hbox2_3, FALSE, TRUE, 10);

        label = gtk_label_new ("       ");

        gtk_box_pack_start (GTK_BOX (hbox2_3), label, TRUE, FALSE, 10);

        gtk_box_pack_start (GTK_BOX (hbox2_3), text_view2, TRUE, TRUE, 10);

        gtk_widget_show(text_view2);

        label = gtk_label_new ("       ");

        gtk_box_pack_start (GTK_BOX (hbox2_3), label, TRUE, FALSE, 10);
/*_______________________________________________________________________*/        
        
        gtk_container_add (GTK_CONTAINER (window2), vbox2_1);
        //gtk_container_add (GTK_CONTAINER (window2), hbox2_1);

        gtk_widget_show(vbox2_1);
        gtk_widget_show(hbox2_1);
        gtk_widget_show(window2); 
        gtk_widget_show_all(window2);
    }else
        printf("\n*** Es necesario generar el Autómata\n");

}

int main(int argc, char *argv[]) {
    PangoFontDescription *font_desc;
    //GdkRGBA rgba;
    //GdkColor *color;

    /* Secure glib */
    if( ! g_thread_supported() )
        gtk_thread_init( NULL );

    /* Secure gtk */
    gdk_threads_init();

    /* Obtain gtk's global lock */
    gdk_threads_enter();

    gtk_init(&argc, &argv); 
    /* Create top‐level window */ 
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER_ALWAYS); 
    gtk_widget_set_size_request (window, 1100, 650);
    g_signal_connect(G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), window);
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);


    gtk_window_set_title (GTK_WINDOW (window), "Autómata");
    vbox = gtk_vbox_new (FALSE, 0);
    vbox1 = gtk_vbox_new (FALSE, 0);
    vbox2 = gtk_vbox_new (FALSE, 0);
    hbox = gtk_hbox_new (FALSE, 0);
    hbox1 = gtk_hbox_new (FALSE, 0);

    /* Create our accel group, attach it to our top‐level window */ 
    accel = gtk_accel_group_new();
    //gtk_accel_set_border_width (GTK_ACCEL_LABEL (accel), 5);
    gtk_window_add_accel_group(GTK_WINDOW (window), accel); 
    /* The accels are added down below... */ 
    /* create the menu bar as the only widget in our "window" */ 
    menubar = gtk_menu_bar_new();
    //gtk_container_add(GTK_CONTAINER(window), menubar); 

    gtk_box_pack_start (GTK_BOX (vbox), menubar, FALSE, FALSE, 10);

    gtk_widget_show(menubar);
    
    


    /* Create the "File" GtkMenuItem */ 
    menuitem = gtk_menu_item_new_with_label("Archivo"); 
    gtk_menu_bar_append(GTK_MENU_BAR(menubar), menuitem); 

    gtk_widget_show(menuitem);

    


    /* Create the actual drop‐down menu (called "submenu") */ 
    submenu = gtk_menu_new(); 
    /* set it to be the submenu of "File" */ 
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), submenu);

    /* Create "New" entry in our submenu: */ 
    menuitem = gtk_menu_item_new_with_label("Abrir"); 
    gtk_menu_append(GTK_MENU(submenu), menuitem); 
    g_signal_connect_swapped (G_OBJECT (menuitem), "activate", G_CALLBACK (abrir_archivo), NULL);
    /* Finally, add an accelerator for "New" of CTRL‐N */ 
    gtk_widget_add_accelerator(menuitem, "activate", accel, 'O', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    
    /* Wrap up the "New" GtkMenuItem by showing it: */ 
    gtk_widget_show(menuitem);

    /* Create "New" entry in our submenu: */ 
    menuitem = gtk_menu_item_new_with_label("Guardar"); 
    gtk_menu_append(GTK_MENU(submenu), menuitem); 
    g_signal_connect_swapped (G_OBJECT (menuitem), "activate", G_CALLBACK (guardar_archivo), NULL);
    /* Finally, add an accelerator for "New" of CTRL‐N */ 
    gtk_widget_add_accelerator(menuitem, "activate", accel, 'G', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    /* Wrap up the "New" GtkMenuItem by showing it: */ 
    gtk_widget_show(menuitem);

    menuitem = gtk_menu_item_new_with_label("Guardar como..."); 
    gtk_menu_append(GTK_MENU(submenu), menuitem); 
    g_signal_connect_swapped (G_OBJECT (menuitem), "activate", G_CALLBACK (guardar_archivo_como), NULL);
    /* Finally, add an accelerator for "New" of CTRL‐N */ 
    //gtk_widget_add_accelerator(menuitem, "activate", accel, 'S', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    /* Wrap up the "New" GtkMenuItem by showing it: */ 
    gtk_widget_show(menuitem);

    /* Create "New" entry in our submenu: */ 
    menuitem = gtk_menu_item_new_with_label("Salir"); 
    gtk_menu_append(GTK_MENU(submenu), menuitem);
    g_signal_connect_swapped (G_OBJECT (menuitem), "activate", G_CALLBACK (salir), NULL);
    /* Finally, add an accelerator for "New" of CTRL‐N */ 
    gtk_widget_add_accelerator(menuitem, "activate", accel, 'W', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    //g_signal_connect(G_OBJECT (submenu), "clicked", G_CALLBACK (Delete), NULL);

    /* Wrap up the "New" GtkMenuItem by showing it: */ 
    gtk_widget_show(menuitem);






    menuitem = gtk_menu_item_new_with_label("Reconocer Palabra"); 
    gtk_menu_bar_append(GTK_MENU_BAR(menubar), menuitem);
    g_signal_connect_swapped (G_OBJECT (menuitem), "activate", G_CALLBACK (ventana_Reconocer), NULL);


    gtk_widget_show(menuitem);



    menuitem = gtk_menu_item_new_with_label("Acerca de"); 
    gtk_menu_bar_append(GTK_MENU_BAR(menubar), menuitem);

    gtk_widget_show(menuitem);

//___________________________________________________________________________

    text_view = gtk_text_view_new();
    font_desc = pango_font_description_from_string ("Arial 12");
    gtk_widget_modify_font (text_view, font_desc);
    pango_font_description_free (font_desc);

    //gdk_rgba_parse ("green", &rgba);
    //gdk_color_parse("green", &color);
    //gtk_widget_override_color (text_view, NULL, &rgba);


    entry = gtk_entry_new ();
    //buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    //entry = truncate-multiline(FALSE);

    //gtk_widget_set_usize( GTK_WIDGET (text_view), 220, 575);

    gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 10);
    gtk_box_pack_start (GTK_BOX (hbox), text_view, TRUE, TRUE, 10);
    
    //gtk_box_pack_start (GTK_BOX (vbox), text_view, FALSE, FALSE, 10);
    //gtk_widget_show(entry);

    //gtk_container_add (GTK_CONTAINER (window), hbox);
    //gtk_widget_show(hbox); 

//___________________________________________________________________________

    button = gtk_button_new_with_label ("Generar Autómata");

    gtk_box_pack_start (GTK_BOX (hbox), vbox1, FALSE, TRUE, 5);

    label = gtk_label_new ("       ");

    gtk_box_pack_start (GTK_BOX (vbox1), label, FALSE, FALSE, 20);

    label = gtk_label_new ("       ");

    gtk_box_pack_start (GTK_BOX (vbox1), label, FALSE, FALSE, 20);

    label = gtk_label_new ("       ");

    gtk_box_pack_start (GTK_BOX (vbox1), label, FALSE, FALSE, 20);

    label = gtk_label_new ("       ");

    gtk_box_pack_start (GTK_BOX (vbox1), label, FALSE, FALSE, 20);




    gtk_box_pack_start (GTK_BOX (vbox1), button, FALSE, FALSE, 20);

    gtk_widget_show(button);

    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (generar_automata), NULL);


//___________________________________________________________________________

    image = gtk_image_new();

    gtk_widget_set_usize( GTK_WIDGET (image), 620, 550);

    gtk_box_pack_start (GTK_BOX (hbox), vbox2, FALSE, FALSE, 15);

    gtk_box_pack_start (GTK_BOX (vbox2), image, TRUE, FALSE, 20);


//___________________________________________________________________________
    
    button = gtk_button_new_with_label ("Guardar imagen");

    gtk_box_pack_start (GTK_BOX (vbox2), hbox1, FALSE, FALSE, 0);

    label = gtk_label_new ("            ");

    gtk_box_pack_start (GTK_BOX (hbox1), label, FALSE, FALSE, 20);

    label = gtk_label_new ("            ");

    gtk_box_pack_start (GTK_BOX (hbox1), label, FALSE, FALSE, 20);

    label = gtk_label_new ("           ");

    gtk_box_pack_start (GTK_BOX (hbox1), label, FALSE, FALSE, 20);

    gtk_box_pack_start (GTK_BOX (hbox1), button, FALSE, FALSE, 0);


    label = gtk_label_new ("           ");    

    gtk_box_pack_start (GTK_BOX (vbox2), label, FALSE, FALSE, 2);

    label = gtk_label_new ("           ");    

    gtk_box_pack_start (GTK_BOX (vbox2), label, FALSE, FALSE, 2);



//___________________________________________________________________________    

    //gtk_container_add (GTK_CONTAINER (window), hbox);
    gtk_container_add (GTK_CONTAINER (window), vbox);
    gtk_widget_show(vbox2);
    gtk_widget_show(vbox1);
    gtk_widget_show(vbox);
    gtk_widget_show(hbox);
    gtk_widget_show(hbox1);


    //gtk_widget_show(menuitem2);
    
    /* Create a second GtkMenuItem ("Open") */ 
    /* Now with GtkAccelLabel... */ 
    //menuitem = gtk_menu_item_new();
    //accel_label = gtk_accel_label_new("Open"); 
    /* We attach it to 'menuitem', which is the GtkMenuItem */ 
    //gtk_accel_label_set_accel_widget(GTK_ACCEL_LABEL(accel_label), menuitem); 
    //gtk_container_add(GTK_CONTAINER(menuitem), accel_label); 
    //gtk_widget_show(accel_label); 
    /* All done‐‐add this menuitem to the submenu and show it... */ 
    //gtk_menu_append(GTK_MENU(submenu), menuitem); 
    //gtk_widget_show(menuitem); 
    /* Now, add an accelerator to the Open menuitem */ 
    //gtk_widget_add_accelerator(menuitem, "activate", accel, 'P', GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
    gdk_threads_leave();
    gtk_widget_show(window); 
    gtk_widget_show_all(window);
    gtk_main(); 
    //gdk_threads_leave();
    return 0;
}

void guardar_archivo_txt (){
    FILE *fp;
    
    fp = fopen("Aut_temp.txt", "w"); //parametro para escritura al final y para file tipo texto
  
    fprintf(fp, "%s", text);
  
    fclose(fp);
}

void obtener_texto_text_view (){
    GtkTextBuffer *buffer;
    GtkTextIter start;
    GtkTextIter end;
    text = "";
    
    //GtkTextTag *tag;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (text_view));

    //if(veces_generar_aut == 0)
        //tag = gtk_text_buffer_create_tag (buffer, "green_foreground", "foreground", "green", NULL);

    gtk_text_buffer_get_start_iter (buffer, &start);
    gtk_text_buffer_get_end_iter (buffer, &end);

    //num_carac = gtk_text_buffer_get_char_count (buffer);

    text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);

    //gtk_text_buffer_get_iter_at_offset (buffer, &start, 0);
    //gtk_text_buffer_get_iter_at_offset (buffer, &end, strlen(text));
    //gtk_text_buffer_apply_tag (buffer, tag, &start, &end);

    //veces_generar_aut++;

    //gtk_text_buffer_set_text (buffer, "Este es nuevo texto", -1);

    //text = gtk_entry_get_text(GTK_ENTRY(entry));
    //text = gtk_text_view_get_text(GTK_TEXT_VIEW (text_view));
    //printf("\nEl text view contiene : %s\n", text);
    printf("\nEl text view contiene : \n%s\n", text);    
}

void obtener_texto_text_view_palabra (){
    GtkTextBuffer *buffer;
    GtkTextIter start;
    GtkTextIter end;
    text = "";
    
    GtkTextTag *tag;

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (text_view2));

    /*tag = gtk_text_buffer_create_tag (buffer, "blue_foreground", "foreground", "geen", NULL);

    gtk_text_buffer_get_iter_at_offset (buffer, &start, 1);
    gtk_text_buffer_get_iter_at_offset (buffer, &end, 2);
    gtk_text_buffer_apply_tag (buffer, tag, &start, &end);*/

    gtk_text_buffer_get_start_iter (buffer, &start);
    gtk_text_buffer_get_end_iter (buffer, &end);

    //num_carac = gtk_text_buffer_get_char_count (buffer);

    text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);


    //gtk_text_buffer_set_text (buffer, "Este es nuevo texto", -1);

    //text = gtk_entry_get_text(GTK_ENTRY(entry));
    //text = gtk_text_view_get_text(GTK_TEXT_VIEW (text_view));
    //printf("\nEl text view contiene : %s\n", text);
    printf("\nEl text view contiene : \n%s\n", text);    
}

/*void abrir_archivo (GtkWidget *widget, gpointer data)
{
    GtkWidget *pFileSelection;
    GtkWidget *pDialog;
    const gchar *sPath;*/

    /* Creación de la ventana de selección */
    //pFileSelection = gtk_file_selection_new("Abrir...");
    /* Limitar las acciones a esta ventana */
    //gtk_window_set_modal(GTK_WINDOW(pFileSelection), TRUE);

    /* Gestionar ventana */
    /*switch(gtk_dialog_run(GTK_DIALOG(pFileSelection)))
    {
        case GTK_RESPONSE_OK:*/
            /* Obtención del path */
            /*sPath = gtk_file_selection_get_filename(GTK_FILE_SELECTION(pFileSelection));
            pDialog = gtk_message_dialog_new(GTK_WINDOW(pFileSelection),
                GTK_DIALOG_MODAL,
                GTK_MESSAGE_INFO,
                GTK_BUTTONS_OK,
                "Path del fichero :\n%s", sPath);
            gtk_dialog_run(GTK_DIALOG(pDialog));
            gtk_widget_destroy(pDialog);
            break;
        default:
            break;
    }
    gtk_widget_destroy(pFileSelection);
}*/

/********************************************************************************************** */
void funcion_parser(){
    //   char* Estados; /* puntero a vector char de estados */
    //char* Entrada;/* puntero a vector char de entradas */
       int i=0,j=0,val=0,k=0, otro=0, filcol=0;
       char vec_ele[4]={'a','b','c','d'};
       int contvec=0;
       int Einicial=0,contfilas=0;
     FILE *fp;
     char *line = NULL;
     size_t len = 0;
     ssize_t read;
       //char* aceptacion;/* puntero a vector char de estados de aceptacion */
       char inicial;/* puntero a char de estado inicial  */
       //char **mat;
         char aux;

     fp = fopen("Aut_temp.txt", "r");
     if (fp == NULL)
     exit(EXIT_FAILURE);
     while ((read = getline(&line, &len, fp)) != -1) {
       //printf("la longitud de la linea es  %zu :\n", read);
       printf("%s", line);
         if(line[0]=='#'){
            //printf("La linea inicia con gato y avanza a la siguiente :)\n");      
                }
                else{
                        if(contvec==0){ 
                        col=(read/2);// guarda la longitud del vector de entrada
                        Entrada=crea_vector(read);
                        j=0;
                        for(i=0; i<read; i++){
                            if(line[i]==','){
                            }else{
                            Entrada[j]=line[i]; 
                            j++;
                            }   
                        }
                        for(i=0; i<(read/2);i++){
                            printf("entrada[%d]=%c \n",i,Entrada[i]);       
                        }           
                        }
                        if(contvec==1){ 
                      fil=(read/2);// guarda la longitud del vector de estados
                        Estados=crea_vector(read);
                        j=0;            
                        for(i=0; i<read; i++){
                            if(line[i]==','){
                            }else{
                            Estados[j]=line[i]; 
                            j++;
                            }   
                        }
                        for(i=0; i<(read/2);i++){
                            printf("Estados[%d]=%c \n",i,Estados[i]);       
                        }
                        }
                    if (contvec==2){
                    Einicial=(read)-1;
                //  printf("reservo memoria de matriz ");
                    mat = (char **)malloc(fil*sizeof(char*)); 
                    for (i=0;i<fil;i++){
                        mat[i] = (char*)malloc(col*sizeof(char)); }
                    if(line[i]==','){
                            }else{
                                Einicial=line[0];   
                            }
                            printf("Einicial =%c \n",Einicial);
                            Eini = Einicial;
                    }// fin if
                if(contvec==3){ 
                Eaceptacion=(read)-1;   // guarda la longitud del vector de aceptacion  
                aceptacion=crea_vector(read);
                j=0;
                        for(i=0; i<read; i++){
                            if(line[i]==','){
                            }else{
                            aceptacion[j]=line[i];
                            j++;    
                            }   
                        }
                        for(i=0; i<(read/2);i++){
                            printf("aceptacion[%d]=%c \n",i,aceptacion[i]);     
                        }
            }

            if(contvec==4){
            contvec--;  
            //printf("Aquí vamos a leer la matriz de la funcion de transicion   ");
            int j=0;
            for (i=0; i<read; i++){
                if(line[i]==','){
                }
                else{
                   mat[contfilas][j]=line[i];   
                j++;
                }           
            }
            contfilas++;
            if(contfilas==fil){
            contvec=5;  
            //printf("Aqui sale de leyendo matriz");    
            }            
        } //fin if 

            contvec++;
           }// fin else
        }//fin while
        printf("\nLa matriz mat tiene los valores:\n");
        for (i=0; i<fil; i++){
                for (j=0; j<col; j++){
                printf(" %c ",mat[i][j]);               
                }
            printf("\n");
            } // fin for
/////////////////validando los valores de la matriz  .. sólo datos que estan en el vector de estados
        otro = 0;
        filcol = 0;
        for (i=0; i<fil; i++){
                for (j=0; j<col; j++){
                    aux = mat[i][j];
                    val=0;
                    for(k=0; k<fil && val==0; k++){
                        if(aux==Estados[k]){// si son iguales. el caracter fue encoontrado
                                val=1;
                                otro++;
                        }       
                        else{ val=0;
                        }   // el caracter no fue encontrado
                    }
                }
        }

    filcol=(fil*col);
    //printf("\n otro : %d \n", otro);
    //printf("\n filcol : %d \n", filcol);
    if(otro==filcol){// todos los caracteres han sido encontrados
        val_mat_trans = TRUE;
        //free(line);
    /// Llamado a la funcion generargrafo

        genera_Grafo (Entrada, col, Estados, fil, Einicial, aceptacion, Eaceptacion, mat);
    //exit(EXIT_SUCCESS);
        //printf("\n\n P : La longitud de entradas es : %d\n\n",strlen(Entrada));
        //printf("\n\n P : La longitud de estados es : %d\n\n",strlen(Estados));
    /* finalmente, libera la zona de memoria */
        //free(Entrada);
        //free(Estados);
        //free(aceptacion);
        //free(mat);
    }else{
        val_mat_trans = FALSE;
        //g_printf("\nEn la funcion de transicion existe un caracter que no se declaro en los estados ");
    }
}// fin funcion parser

void genera_Grafo (char *ent, int col, char *est, int fil, char ini, char *acep, int lacep, char **mat){
  printf("En funcion genera grafo\n\n");
    FILE *fp;
    char a[]="automata1";
    char aux[9];
    strcpy(aux,a);
    char ext[]=".dot";
    fp=fopen(strcat(a,ext),"w");
    int i,j;
    fprintf(fp,"%s","digraph g{");
    fprintf(fp,"\n%s","rankdir=\"LR\";size=\"5,7;\"\n");
    //nodo en blanco
    fprintf(fp,"%s\n","\nnode [shape = point, color=white, fontcolor=white]; start;");
        //finales
    for(i=0;i<lacep;i++){
            fprintf(fp,"%s %c;\n","node [shape = doublecircle, color=black, fontcolor=black]",acep[i]);
            
        }
    fprintf(fp,"node [shape = circle];");
    
    //funcion de transicion
    fprintf(fp,"%s %c\n","start->",ini);
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
                fprintf(fp,"%c %s %c %s %c %s;\n",est[i],"->",mat[i][j],"[label=\"",ent[j],"\"]");
            }
        }

    fprintf(fp,"\n%s","}");
    fclose(fp);
    char p1[]="dot -Tpng ";
    char p3[]=" -o ";
    char p5[]=".png";
    strcat(p1,a);
    strcat(p1,p3);
    
    

    strcat(aux,p5);
    system(strcat(p1,aux));


}

char* crea_vector(log){
    int N =(log/2)+1;
    /* reserva memoria para N caracteres */
    return (char*)malloc ( N*sizeof(char) );
}