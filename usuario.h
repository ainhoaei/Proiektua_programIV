#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct {
	char *contrasenya;
	char *nombre;
} Usuario;


void AbrirFichero(const char *filename, const char* mode);
void CerrarFichero(FILE* fichero);
void EscribirEnFichero(FILE *fichero, const char *nombre, const char *contrasenya);
void LeerDesdeFichero(FILE *fichero);

#endif