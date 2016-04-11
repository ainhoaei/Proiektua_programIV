#ifndef USUARIO_H_
#define USUARIO_H_


#define MAX_LENGTH 10
#define NUM_ELEMENTOS 2

typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;


int AbrirFichero(FILE *fichero);
int CerrarFichero(FILE* fichero);
int EscribirEnFichero(Usuario *u, int total);
int LeerDesdeFichero(Usuario *u, int total);

#endif