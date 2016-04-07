#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct {
	char *contrasenya;
	char *nombre;
} Usuario;


void AbrirFichero(const char *filename, const char* mode);
void CerrarFichero(FILE* fichero);
void EscribirEnFichero(Usuario *u, int total);
void LeerDesdeFichero(FILE *fichero);

#endif