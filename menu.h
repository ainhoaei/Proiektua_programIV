#ifndef MENU_H_
#define MENU_H_


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

typedef struct{
	int dia;
	int mes;
	int anyo;
} Fecha;

typedef struct {
	char *descp;
	Fecha fecha;
} Tarea;


void menuPrinci();
void menuContacto();
void menuDiario();
void menuRecordt();
void menuTarea();
int menua(char *nombre);


int EscribirEnFicheroUsuario(Usuario *u, int total);
void clear_if_neededC (char *str);
void liberarMemoria (Usuario *t, int total);


#endif
