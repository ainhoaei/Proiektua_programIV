#include <stdio.h>
#include "menu.h"
#include "usuario.h"

FILE *usuario;

//MENU PRINCIPAL
void menuPrinci()
{

 	int opc = 0;
	
    do
    {
        printf("MENU PRINCIPAL: Seleccione una opcion \n");
    	printf("1. Log in   2. Registrarse   3. Salir\n");
    	scanf("%i",&opc);

    	switch(opc){
    		case 1: menua(); break;
    		case 2: registrarse(); break;
    		case 3: printf("Adios!\n"); break;
    		default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
    	}

    } while (opc != 3);


}

int registrarse(){

    char nombre[15];
    char contrasenya[15];

    printf("Escriba el nuevo nombre de usuario:\n");
    scanf("%s",nombre);
    printf("Escriba la contrasenya para el usuario:\n");
    scanf("%s",contrasenya);
    printf("USUARIO REGISTRADO!\n");
    printf("\n");

    AbrirFichero("usuario.dat", "w");
    EscribirEnFichero(usuario, nombre, contrasenya);
    CerrarFichero(usuario);

    leerUsuarios();

    return 0;
}

int leerUsuarios(){
    FILE *archivo;
    char caracteres[100];

    AbrirFichero("usuario.dat", "w");
    LeerDesdeFichero(usuario);
}


