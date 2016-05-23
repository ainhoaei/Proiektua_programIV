#ifndef MENU_H_
#define MENU_H_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	char *nombre;
	char *contrasenya;
} Usuario;


typedef struct 
{
	char *nombre;
	char *apellido;

	char *email;
	char *empresa;
	int num_tlf;
	
}Contacto;



void menuPrinci();
void menuContacto(char *nombre);
void menuDiario();
void menuRecordt();
void menuTarea();
int menua(char *nombre);


int EscribirEnFicheroUsuario(Usuario *u, int total);
void clear_if_neededC (char *str);
void liberarMemoria (Usuario *t, int total);

#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif

#endif

