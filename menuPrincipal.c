#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"

#define MAX_LENGTH 10
#define NUM_ELEMENTOS 2


void comprobarUsuarioRegistrado(Usuario *usuario, int total){


    // SE COMPRUEBA EL NOMBRE DEL USUARIO


    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];

    char nombre[100];

    //GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);


    printf ("Nombre de usuario: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str);

  //  nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(nombre, frmt_str); //STRING COPY

    printf ("Contrasenya de usuario: ");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str);

    strcat(nombre,"#"); //STRING COPY
    strcat(nombre, frmt_str); //STRING COPY
    
    //printf("%s\n",nombre);

    //LONGITUD DEL NOMBRE
    int longNombre = 0;
    longNombre = largo_cadena(nombre);

    int i = 0;
    FILE *fichero;
    char c;

    fichero = fopen("usuario.txt", "r");
  
    int contar = 0;

    int result = 0;

    char read[100];
    char nombre2[100];

    while(fgets(read, 100, fichero)) {

        sscanf(read, "%s", nombre2);

       
        

        //strcmp ez zuen funtzionatzen beraz horrela egin dugu
        if(strcmp(nombre, nombre2)==0){

        menua(nombre);
        
        }
        
     }








//////////PARA COMPROBRAR SOLO EL NOMBRE///////////
  /* while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        if (c == '\n')
        {
            if(i == longNombre)
            {
                menua(nombre);
                return;
            }
            else
            {
                i = 0;
            }
        }
        else
        {
            if (c != '#')
            {
                if(nombre[i] == c)
                {
                    i++;
                    
                }
                        
            }
        }
    }*/
/////////////////////////////////////////////////////////

    fclose (fichero);
   // free(nombre);


}



int registrarse(Usuario *usuario, int total){

    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];


    //GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);

    printf ("Escriba el nuevo nombre de usuario: \n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final

 /* /////HAU IZANGO LITZAKE NOMBRE DE USUARIO KONPROBATZEKO///////////////



   //GUARDAR EL NOMBRE EN UNA VARIABLE
    char *nombre;
    nombre = str;
    nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));

*/
     
    
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


    int result = 0;  //EZ BADA HURRENGOA EGINGO, HAU BORRATU BEHAR DA ETA RETURN BAITA!
 /* /////HAU IZANGO LITZAKE NOMBRE DE USUARIO KONPROBATZEKO///////////////

    //LONGITUD DEL NOMBRE
    int longNombre = 0;
    longNombre = largo_cadena(nombre);

    int i = 0;
    FILE *fichero;
    char c;

    fichero = fopen("usuario.txt", "r");


     
//////////PARA COMPROBRAR SOLO EL NOMBRE///////////
  while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        if (c == '\n')
        {
            if(i == longNombre)
            {
                result = 1;
                return result;
            }
            else
            {
                i = 0;
                result = 0;
            }
        }
        else
        {
            if (c != '#')
            {
                if(nombre[i] == c)
                {
                    i++;
                    
                }
                        
            }
        }
    }
/////////////////////////////////////////////////////////

    free(nombre);

    fclose (fichero);
*/
    

    return result;
}




//MENU PRINCIPAL
void menuPrinci()
{

    setvbuf (stdout, 0, _IONBF, 0);
    

    Usuario u[50];
    int opc = 0;
    int total=0;
    FILE *fichero;


    char *nombre;
    nombre = "gorka";
    
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
                        comprobarUsuarioRegistrado(&u[total], total);
                            
                        
                    }
                    break;
            case 2: if(registrarse(&u[total], total)==0)
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




