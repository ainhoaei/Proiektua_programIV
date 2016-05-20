#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"

#define MAX_LENGTH 10
#define NUM_ELEMENTOS 2


void comprobarUsuarioRegistrado(Usuario *usuario){


    // SE COMPRUEBA EL NOMBRE DEL USUARIO


    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];

    char nombre[100];

    //GALDETU HAU!
    printf("\n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);


    printf ("Nombre de usuario: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
 
    strcpy(nombre, frmt_str); //STRING COPY

    printf ("Contrasenya de usuario: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str);

    strcat(nombre,"#"); //STRING COPY
    strcat(nombre, frmt_str); //STRING COPY

    FILE *fichero;

    fichero = fopen("usuario.txt", "r");

    char read[100];
    char nombre2[100];

    while(fgets(read, 100, fichero)) {

        sscanf(read, "%s", nombre2);

       
        

        //strcmp ez zuen funtzionatzen beraz horrela egin dugu
        if(strcmp(nombre, nombre2)==0){

            menua(nombre);
        
        }
        
     }


    fclose (fichero);
   // free(nombre);


}



int registrarse(Usuario *usuario){

    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];


    //GALDETU HAU!
    printf("\n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);

    printf ("Escriba el nuevo nombre de usuario: \n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final
     
    
    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    usuario->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(usuario->nombre, frmt_str); //STRING COPY

    

    printf("Escriba la contrasenya para el usuario: \n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final

    //RESERVAR LA MEMORIA JUSTA
    usuario->contrasenya = (char *)malloc((strlen(frmt_str)+1) * sizeof(char));
    strcpy(usuario->contrasenya, frmt_str);

    return 0;
}




//MENU PRINCIPAL
void menuPrinci()
{

    setvbuf (stdout, 0, _IONBF, 0);
    

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
            case 1: fichero = fopen("usuario.txt", "r");
                    if ( fichero == NULL )
                    {
                      printf("No hay usuarios registrados\n");
                    }
                    else
                    {
                        comprobarUsuarioRegistrado(&u[total]);
                            
                        
                    }
                    break;
            case 2: if(registrarse(&u[total])==0)
                    {
                        EscribirEnFicheroUsuario(u, total);
                        total ++;
                   }
                    else
                    {
                        printf("Este nombre de usuario no esta disponible.\n");
                    }
                        

                   
                    break;
            case 3: printf("Adios!\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    } while (opc != 3);


    liberarMemoria(u, total);
}




