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
    int total=0;
    FILE *fichero;
	
    do
    {
        printf("\nMENU PRINCIPAL: Seleccione una opcion \n");
    	printf("1. Log in   2. Registrarse   3. Salir\n");
    	scanf("%i",&opc);

    	switch(opc){
    		case 1: fichero = fopen("usuario.dat", "rb");
                    if ( fichero == NULL )
                    {
                      printf("No hay usuarios registrados\n");
                    }
                    else
                    {
                        //comprobarUsuarioRegistrado(u, total); 
                        //EZ DET LORTZEN USUARIOA ESISTITZEN DEN KONPROBATZEA
                        menua();
                    }
                    break;
    		case 2: registrarse(&u[total], total); 
                    total ++;
                    EscribirEnFichero(u, total);
                   // LeerDesdeFichero(u, total);
                    break;
    		case 3: printf("Adios!\n"); break;
    		default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
    	}

    } while (opc != 3);


    liberarMemoria(u, total);
}


int comprobarUsuarioRegistrado(Usuario *usuario, int total){


    // EZ DU FUNTZIONATZEN!


    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];

    char *nombre;
    char *contrasenya;

    //GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);


    printf ("Nombre de usuario: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str);

    nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(nombre, frmt_str); //STRING COPY


    printf ("Contrasenya: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str);

    contrasenya = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(contrasenya, frmt_str); //STRING COPY

   /* Usuario *usuario2;
    usuario2->nombre = usuario->nombre;
    usuario2->contrasenya = usuario->contrasenya;*/

    //usuario = clone(LeerDesdeFichero(usuario, total));
    char *num;
    num = (char *)malloc ((strlen(frmt_str)+1) * sizeof(char));
    //strncpy(usuario->nombre, LeerDesdeFichero(usuario, total)->nombre, num);
    //int num = LeerDesdeFichero(usuario, total);
    int i;
   // 
    while (feof((FILE*)usuario))
    {
        /*if ((nombre == getNombre(i)) && (contrasenya == getContrasenya(i))){
            menua();
        }*/
        for(i=0; i<sizeof(usuario); i++){
            if(usuario[i].nombre == nombre){
                printf("SI\n");
            }
            else{
                printf("Nombre de usuario y contrasenya incorrectas.\n");
            }
        }
    }
    
    free(usuario);
    //menua();
    return 0;
}

int registrarse(Usuario *usuario, int total){

    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];


    //GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);

    printf ("Escriba el nuevo nombre de usuario: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final
     
    
    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    usuario->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(usuario->nombre, frmt_str); //STRING COPY

    

    printf("Escriba la contrasenya para el usuario:  ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final

    //RESERVAR LA MEMORIA JUSTA
    usuario->contrasenya = (char *)malloc((strlen(frmt_str)+1) * sizeof(char));
    strcpy(usuario->contrasenya, frmt_str);


    return 0;
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