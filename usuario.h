#ifndef USUARIO_H_
#define USUARIO_H_


typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;

int EscribirEnFicheroUsuario(Usuario *u, int total);
//int LeerDesdeFicheroUsuario(int total);
void clear_if_neededC (char *str);
void liberarMemoria (Usuario *t, int total);

#endif