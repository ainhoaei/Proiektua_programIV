#ifndef TAREA_H_
#define TAREA_H_


typedef struct{
	int dia;
	int mes;
	int anyo;
} Fecha;

typedef struct {
	char *descp;
	Fecha fecha;
} Tarea;

int IntroducirTarea(Tarea *tarea, int total);
int EscribirEnFichero (Tarea *t, int total);
int LeerDesdeFichero (Tarea *t, int total);
void clear_if_needed (char *str);
void liberarMemoria (Tarea *t, int total);

#endif