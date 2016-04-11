#ifndef USUARIO_H_
#define USUARIO_H_


#define MAX_LENGTH 10
#define NUM_ELEMENTOS 2

typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;

void EscribirEnFichero(Usuario *u, int total);
void LeerDesdeFichero(Usuario *u, int total);
void clear_if_needed (char *str);
void liberarMemoria (Usuario *t, int total);

#endif