#include <stdio.h>
#include "tarea.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CANT_ELEMENTOS 5


/*int main(void)
{
	
	Tarea *tarea;

	int opcion;
    int total;
    total = 0;
    do{
        printf("Seleccione la accion a realizar:\n1. Introducir tarea\n2. Ver tareas a realizar\n3. Modificar tarea\n4. Eliminar tarea\n5. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: IntroducirTarea(&tarea[total], total);
					total++; 
					
					break;
            case 2: 

            		//EZ DU ONDO FUNTZIONATZEN!


            LeerDesdeFichero(tarea, total);
            		break;
            





            case 3: ModificarTarea(); 
            		break;
            case 4: EliminarTarea(); 
            		break;
            case 5: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 5 );
		
    liberarMemoria(tarea, total);

	return 0;
}
*/

int IntroducirTarea(Tarea *tarea, int total){

	char str[MAX_LENGTH_D_M];


//GALDETU HAU!
    printf("");
    fgets(str, MAX_LENGTH_D_M, stdin);
    clear_if_needed(str);


	//DIA
    int d;
    do{
	    printf ("FECHA (Introduzca los 2 digitos en cada apartado):\nDia: ");
	    fgets(str, MAX_LENGTH_D_M, stdin);
	    clear_if_needed(str);
	    sscanf(str, "%d", &tarea->dia); //eliminar el \n final
	   
	    d = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 31 

	}while(d > 31);

	//MES
	int m;
	do{
	    printf("Num mes: ");
	    fgets(str, MAX_LENGTH_D_M, stdin);
	    clear_if_needed(str);
	    sscanf(str, "%d", &tarea->mes);

	    m = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 12 

	}while(m > 12);

	//ANYO
	int a;
	do{
	    printf("Anyo: ");
	    fgets(str, MAX_LENGTH_D_M, stdin);
	    clear_if_needed(str);
	    sscanf(str, "%d", &tarea->anyo);

	    a = atoi (str); //PARA QUE NO SE PUEDA ESCRIBIR MENOS DE 16

    }while (a < 16);



    //DESCRIPCION
    char str_descp[MAX_LENGTH_DESCP];
    char frmt_str_descp[MAX_LENGTH_DESCP];

    printf("Descripcion de la tarea (maximo 50 caracteres):\n");
    fgets(str_descp, MAX_LENGTH_DESCP, stdin);
    clear_if_needed(str_descp);
    sscanf(str_descp, "%s", frmt_str_descp);
    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    tarea->descp = (char *)malloc((strlen(frmt_str_descp) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(tarea->descp, frmt_str_descp); //STRING COPY


    imprimir(tarea, total);
    EscribirEnFichero(tarea, total);

    return 0;
}


int VerTareas(){

}


int ModificarTarea(){

}


int EliminarTarea(){

}



int imprimir(Tarea *t)
{
	int i = 0;

		printf("\nNUM TAREA %d:\n", i+1);
		printf("Fecha: %d/%d/%d\nDescripcion:\n", t->dia, t->mes, t->anyo);
		
	
	return 0;	
}


int AbrirFichero(FILE *fichero){

    fichero = fopen("tarea.dat", "wb");

    if(fichero == NULL){
    	printf("\nError de apertura del fichero\n");
    }

    return 0;
}


int CerrarFichero(FILE *fichero){

	fclose (fichero);
	return 0;
}

int EscribirEnFichero (Tarea *t, int total){

	//int CANT_ELEMENTOS = 5;
	FILE *fichero;
	fichero = fopen("tarea.dat", "wb"); // edo ab???
	fputc (CANT_ELEMENTOS, fichero);
	fwrite (t, sizeof(Tarea), CANT_ELEMENTOS, fichero);

	CerrarFichero(fichero);

	printf("TAREA GUARDADA!\n");

	return 0;

}






//EZ DU ONDO FUNTZIONATZEN!

int LeerDesdeFichero (Tarea *t, int total){

//LEER NUMEROS

	FILE *fichero;
	int num_elemt;
	fichero = fopen("tarea.dat", "rb");

	num_elemt = fgetc(fichero);
	t = (Tarea*)malloc(num_elemt * sizeof(Tarea));
	fread(t, sizeof(Tarea), num_elemt, fichero);

	
	//IMPRIMIR
	int i;
	for (i=0; i<num_elemt; i++){
		imprimir(&t[i]);
		printf("\n");
	}

//LEER CADENA
	char *descp;
	num_elemt = fgetc(fichero);	
	descp = (char*)malloc((num_elemt+1) *sizeof(char));
	fread(descp, sizeof(char), num_elemt, fichero);
	descp[num_elemt] = '\0';


	CerrarFichero(fichero);

	printf("%s\n", descp);

	free (t);
	free (descp);


	return 0;
}



int clear_if_needed (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}

int liberarMemoria (Tarea *t, int total){
    int i;
    for (i = 0; i < total; i++){
        free(t[i].descp);
    }

    return 0;
}