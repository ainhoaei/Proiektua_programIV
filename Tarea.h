#ifndef TAREA_H_
#define TAREA_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
	int dia;
	int mes;
	int anyo;
} Fecha;

typedef struct {
	char *descp;
	Fecha fecha;
} Tarea;


int IntroducirTarea(Tarea *tarea);
int EscribirEnFicheroTarea (Tarea *t, int total, const char *nombre);
int LeerDesdeFicheroTarea (Tarea *t, const char *nombre);


#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif

#endif
