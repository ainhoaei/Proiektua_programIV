#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "usuario.h"



//MENU PRINCIPAL
void menuPrinci()
{

    Usuario u[50];
 	int opc = 0;
    int total = 0;
	
    do
    {
        printf("MENU PRINCIPAL: Seleccione una opcion \n");
    	printf("1. Log in   2. Registrarse   3. Salir\n");
    	scanf("%i",&opc);

    	switch(opc){
    		case 1: //menua(); 
                    break;
    		case 2: registrarse(&u[total], total); 
                    liberarMemoria(u, total);
                    total ++;
                    break;
    		case 3: printf("Adios!\n"); break;
    		default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
    	}

    } while (opc != 3);


}

int registrarse(Usuario *usuario, int total){

    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];

    printf ("Escriba el nuevo nombre de usuario:\n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final
    
    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    usuario->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por     //ello, le metemos un +1.
    strcpy(usuario->nombre, frmt_str); //STRING COPY


    printf("Escriba la contrasenya para el usuario:\n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final

    //RESERVAR LA MEMORIA JUSTA
    usuario->contrasenya = (char *)malloc((strlen(frmt_str)+1) * sizeof(char));
    strcpy(usuario->contrasenya, frmt_str);

    printf("USUARIO REGISTRADO! nombre: %s  contrasenya: %s\n", usuario[0].nombre, usuario[0].contrasenya);
    printf("\n");

    //AbrirFichero("usuario.dat", "w");
    //EscribirEnFichero(usuario, nombre, contrasenya);
    //CerrarFichero(usuario);

    //leerUsuarios();

    return 0;
}



int leerUsuarios(){
    FILE *archivo;
    char caracteres[100];

    //AbrirFichero("usuario.dat", "w");
    //LeerDesdeFichero(usuario);
}

int clear_if_needed (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}

int liberarMemoria (Usuario *u, int total){
    int i;
    for (i = 0; i < total; i++){
        free(u[i].nombre);
        free(u[i].contrasenya);
    }

    return 0;
}