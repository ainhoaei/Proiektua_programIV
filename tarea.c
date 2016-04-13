#include <stdio.h>
#include "tarea.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH_DESCP 100
#define MAX_LENGTH 3

int main(void)
{
	
	Tarea tarea[100];

	int opcion;
    int total;
    total = 0;
    do{
        printf("Seleccione la accion a realizar:\n1. Introducir tarea\n2. Ver tareas a realizar\n3. Modificar tarea (sin funcionamiento)\n4. Eliminar tarea (sin funcionamiento)\n5. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: IntroducirTarea(&tarea[total], total);
					total++; 
					EscribirEnFichero(tarea, total);
					break;
            case 2: LeerDesdeFichero(tarea, total);
            		break;
            case 3: ModificarTarea(); 
            		break;
            case 4: EliminarTarea(); 
            		break;
            case 5: break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 5 );
		
    

	return 0;
}


int IntroducirTarea(Tarea *tarea, int total){

	char str[MAX_LENGTH];


//GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_needed(str);


	//DIA
    int d = 33;
    do{
	    printf ("FECHA (Introduzca los 2 digitos en cada apartado):\nDia: ");
	    fgets(str, MAX_LENGTH, stdin);
	    clear_if_needed(str);
	   
	    d = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 31 

	}while(d > 31);
	sscanf(str, "%d", &tarea->fecha.dia); //eliminar el \n final

	//MES
	int m = 17;
	do{
	    printf("Num mes: ");
	    fgets(str, MAX_LENGTH, stdin);
	    clear_if_needed(str);

	    m = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 12 

	}while(m > 12);
	sscanf(str, "%d", &tarea->fecha.mes);

	//ANYO
	int a = 10;
	do{
	    printf("Anyo: ");
	    fgets(str, MAX_LENGTH, stdin);
	    clear_if_needed(str);

	    a = atoi (str); //PARA QUE NO SE PUEDA ESCRIBIR MENOS DE 16

    }while (a < 16);
    sscanf(str, "%d", &tarea->fecha.anyo);


    //DESCRIPCION
    char str_descp[MAX_LENGTH_DESCP];
    char frmt_str_descp[MAX_LENGTH_DESCP];

    printf("Descripcion de la tarea (maximo 100 caracteres).\n");
    fgets(str_descp, MAX_LENGTH_DESCP, stdin);
    clear_if_needed(str_descp);
    sscanf(str_descp, "%[^\n]s", frmt_str_descp); //%%[^\n]s -> para que deje escribir espacios

    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    tarea->descp = (char *)malloc((strlen(frmt_str_descp) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(tarea->descp, frmt_str_descp); //STRING COPY
    
    liberarMemoria(tarea, total);

    return 0;
}


int ModificarTarea(){

}


int EliminarTarea(){

}


int EscribirEnFichero (Tarea *t, int total){

	FILE *fichero;
	fichero = fopen("tarea.txt", "a");
	
	if(fichero == NULL){
    	fclose(fichero);
		fichero = fopen("tarea.txt", "w");
		printf("ez!\n");
    }

	int i;
    for(i=0; i<total; i++)
    {
		fprintf(fichero, "%i/", t[i].fecha.dia);
		fprintf(fichero, "%i/", t[i].fecha.mes);
		fprintf(fichero, "%i\n", t[i].fecha.anyo);
		fprintf(fichero, "%s\n", t[i].descp);
    }


	fclose(fichero);

	printf("TAREA GUARDADA!\n");
	printf("\n");

	return 0;

}


int LeerDesdeFichero (Tarea *t, int total){

	FILE *fichero;
	char c;
	fichero = fopen("tarea.txt", "r");

	while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
    	
    	if (c == '/')
    		putchar(c);
  
        if (c == '\n')
            total++; //berez, irakurtzeko no es necesario
         
        putchar(c);
    }
    //cerrar fichero
    fclose(fichero);

    printf("\n");


	return 0;
}



void clear_if_needed (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }
}

void liberarMemoria (Tarea *t, int total){
    int i;
    for (i = 0; i < total; i++){
        free(t[i].descp);
    }

}