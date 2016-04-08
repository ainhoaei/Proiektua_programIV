#ifndef USUARIO_H_
#define USUARIO_H_


#define MAX_LENGTH 10

typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;


void AbrirFichero(FILE *fichero);
void CerrarFichero(FILE* fichero);
void EscribirEnFichero(FILE *fichero, Usuario *u, int total, char *w);
void LeerDesdeFichero(FILE *fichero, int total, char *w);

#endif