#ifndef CONTACTOS_H_
#define CONTACTOS_H_

//#define MAX_LENGTH 20
#define NUM_ELEMENTOS 5

typedef struct 
{
	char *nombre;
	char *apellido;

	char *email;
	char *empresa;
	int num_tlf;
	
}Contacto;

	int EscribirEnFichero (Contacto *c, int total);
    void insertarContacto(Contacto *c, int total);
    void imprimirListado();

    void liberarMemoria (Contacto *c, int total);
    int leerDesdeFichero ();


#endif