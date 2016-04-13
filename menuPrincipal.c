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
            case 2: registrarse(&u[total], total); 
                    total ++;
                    EscribirEnFichero(u, total);
                    //LeerDesdeFichero(u, total);
                    break;
            case 3: printf("Adios!\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    } while (opc != 3);


    liberarMemoria(u, total);
}


int comprobarUsuarioRegistrado(Usuario *usuario, int total){


    // NOMBRE DE USUARIO BAKARRIK KONPROBATZEU!


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


    //int num = LeerDesdeFichero(usuario, total);
    
    //IGUALAR EL NOMBRE PARA TENER EL NOMBRE
    char *registrar;
    registrar = nombre;
    printf("%s\n", registrar);

    //LONGITUD DEL NOMBRE
    int longNombre = 0;
    longNombre = largo_cadena(nombre);
    printf("%i\n", longNombre);

//////////PARA COMPROBRAR EL NOMBRE Y LA CONTRASEÑA///////////
    //AÑADIR # AL NOMBRE
    char *b;
    b = "#";
    
    //CONCATENAR CON # Y LUEGO CON CONTRASENYA
    strcat(strcat(registrar, b), contrasenya);
    printf("%s\n", registrar);

    //registrar = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));

    int longitud = 0;
    longitud = largo_cadena(registrar);
    //printf("%i\n", largo_cadena(registrar));

    //registrar = (char *)malloc((longitud +1) * sizeof  (char));

/////////////////////////////////////////////////////////

    int i = 0;
    FILE *fichero;
    char c;

    fichero = fopen("usuario.txt", "r");
  
    int contar = 0;

//////////PARA COMPROBRAR SOLO EL NOMBRE///////////
    while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        if (c == '\n')
        {
            if(i == longNombre)
            {
                menua();
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
                if(registrar[i] == c)
                {
                    printf("bai!\n");
                    i++;
                    
                }
                        
            }
        }
    }
/////////////////////////////////////////////////////////

//////////PARA COMPROBRAR EL NOMBRE Y LA CONTRASEÑA///////////

    //NO FUNCIONA!

   /* while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        if (c == '\n'){
            if(contar == longitud)
                menua();

            else{
                contar = 0;
               // printf("ez\n");
            }
            
        }
       
        if (c != '\n')
        {
            if(registrar[i] == c){
               // printf("bai!\n");
                contar++;
            }
            else{
                contar = 0;
            }
               
        }


        i++;    

    }*/
////////////////////////////////////////////////

    fclose (fichero);
    free(contrasenya);
    free(nombre);

    return 0;

}


/* devuelve la cantidad de caracteres en cadena sin contar el '\0' */
int largo_cadena(char cadena[])
{
    int largo=0;
    while (cadena[largo]!='\0') largo++;
    return largo;
}



int registrarse(Usuario *usuario, int total){

    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];


    //GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);

    printf ("Escriba el nuevo nombre de usuario: \n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final
     
    
    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    usuario->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(usuario->nombre, frmt_str); //STRING COPY

    

    printf("Escriba la contrasenya para el usuario: \n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final

    //RESERVAR LA MEMORIA JUSTA
    usuario->contrasenya = (char *)malloc((strlen(frmt_str)+1) * sizeof(char));
    strcpy(usuario->contrasenya, frmt_str);


    return 0;
}