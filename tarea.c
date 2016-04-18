#include <stdio.h>
#include "menu.h"
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH_DESCP 100
#define MAX_LENGTH 3


void clear_if_neededT (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }
}

int IntroducirTarea(Tarea *tarea, int total){

	char str[MAX_LENGTH];


    //Si no hacemos esto, hace \n y salta a la siguiente, sin poder escribir nada
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededT(str);


	//DIA
    int d = 33;
    do{
	    printf ("FECHA (Introduzca los 2 digitos en cada apartado):\nDia: ");
	    fgets(str, MAX_LENGTH, stdin);
	    clear_if_neededT(str);
	   
	    d = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 31 

	}while(d > 31);
	sscanf(str, "%d", &tarea->fecha.dia); //eliminar el \n final

	//MES
	int m = 17;
	do{
	    printf("Num mes: ");
	    fgets(str, MAX_LENGTH, stdin);
	    clear_if_neededT(str);

	    m = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 12 

	}while(m > 12);
	sscanf(str, "%d", &tarea->fecha.mes);

	//ANYO
	int a = 10;
	do{
	    printf("Anyo: ");
	    fgets(str, MAX_LENGTH, stdin);
	    clear_if_neededT(str);

	    a = atoi (str); //PARA QUE NO SE PUEDA ESCRIBIR MENOS DE 16

    }while (a < 16);
    sscanf(str, "%d", &tarea->fecha.anyo);


    //DESCRIPCION
    char str_descp[MAX_LENGTH_DESCP];
    char frmt_str_descp[MAX_LENGTH_DESCP];

    printf("Descripcion de la tarea (maximo 100 caracteres).\n");
    fgets(str_descp, MAX_LENGTH_DESCP, stdin);
    clear_if_neededT(str_descp);
    sscanf(str_descp, "%[^\n]s", frmt_str_descp); //%%[^\n]s -> para que deje escribir espacios

    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    tarea->descp = (char *)malloc((strlen(frmt_str_descp) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(tarea->descp, frmt_str_descp); //STRING COPY


    return 0;
}


int ModificarTarea(){
    printf("Esta opcion no esta disponible todavia.\n");
}


int EliminarTarea(){
    printf("Esta opcion no esta disponible todavia.\n");
}


int EscribirEnFicheroTarea (Tarea *t, int total, char *nombre){

	char *x;
    x = "Tarea";

    char *p;
    p = ".txt";

    char nombreFichero[20];

    strcpy(nombreFichero, nombre);
   

    strcat(nombreFichero, x);
    strcat(nombreFichero, p);

    printf("%s\n", nombreFichero);


    FILE *fichero;
	fichero = fopen(nombreFichero, "a");


		fprintf(fichero, "%i/", t[total].fecha.dia);
		fprintf(fichero, "%i/", t[total].fecha.mes);
		fprintf(fichero, "%i\n", t[total].fecha.anyo);
		fprintf(fichero, "%s\n", t[total].descp);



	fclose(fichero);

	printf("TAREA GUARDADA!\n");
	printf("\n");

    return 0;

}

/* devuelve la cantidad de caracteres en cadena sin contar el '\0' */
int largo_cadena(char cadena[])
{
    int largo=0;
    while (cadena[largo]!='\0') largo++;
    return largo;
}

int LeerDesdeFicheroTarea (Tarea *t, int total, char *nombre){

    char *p;
    p = "Tarea.txt";

    char nombreFichero[20];

    strcpy(nombreFichero, nombre);

    strcat(nombreFichero, p);


    int contar = 0;
	FILE *fichero;
	char c;
	fichero = fopen(nombreFichero, "r");

	while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
    	
    	if (c == '/')
    		putchar(c);
  
        if (c == '\n')
            contar++;
         
        putchar(c);
    }
    //cerrar fichero
    fclose(fichero);

    printf("\n");


	return 0;
}





void liberarMemoriaTarea (Tarea *t, int total){
    int i;
    for (i = 0; i < total; i++){
        free(t[i].descp);
    }

}



//int main(void)
void menuTarea(char *nombre)
{
    
    Tarea tarea[100];

    int opcion;
    int total;
    total = 0;

    do{
        printf("Seleccione la accion a realizar:\n1. Introducir tarea\n2. Ver tareas a realizar\n3. Modificar tarea (no operativo)\n4. Eliminar tarea (no operativo)\n5. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: IntroducirTarea(&tarea[total], total); 
                    EscribirEnFicheroTarea(tarea, total, nombre);
                    total++;
                    break;
            case 2: LeerDesdeFicheroTarea(tarea, total, nombre);
                    break;
            case 3: ModificarTarea(); 
                    break;
            case 4: EliminarTarea(); 
                    break;
            case 5: break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 5 );
        
    liberarMemoriaTarea(tarea, total);

    //return 0;
}