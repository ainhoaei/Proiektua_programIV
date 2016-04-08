#ifndef USUARIO_H_
#define USUARIO_H_


#define MAX_LENGTH 10

typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;


void AbrirFichero(const char *filename, const char* mode);
void CerrarFichero(FILE* fichero);
void EscribirEnFichero(Usuario *u, int total);
void LeerDesdeFichero(FILE *fichero);

#endif