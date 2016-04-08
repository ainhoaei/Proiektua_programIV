#ifndef USUARIO_H_
#define USUARIO_H_


#define MAX_LENGTH 10

typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;


int AbrirFichero(FILE *fichero);
int CerrarFichero(FILE* fichero);
int EscribirEnFichero(FILE *fichero, Usuario *u, int total, char *w);
int LeerDesdeFichero(FILE *fichero, int total, char *w);

#endif