#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAR 200

/*int main(void){
	
	int opcion;
    int total;
    total = 0;
    do{
        printf("Seleccione la accion a realizar:\n1. Apuntar nota\n2. ver notas\n3. Eliminar nota\n4. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: apuntarNota();break;
            case 2: leer();break;
            case 3: break;
            case 4: break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 4 );

	return 0;
}*/


int guardar(char nuevaNota[])
{
	
	FILE* f;
    int c;

	//abrir fichero para escritura "w"
	f = fopen("nota.txt", "w");
       
	//escribir en fichero un string formateado 
	fprintf(f, "Nota del día:\n", MAX_CAR);
	for (c = 0; c < MAX_CAR; c++)
		fprintf(f, "%s\n", nuevaNota[c]);

	//cerrar fichero
	fclose(f);

	return 0;
}


int apuntarNota(){

char str[MAX_CAR];
char nota[MAX_CAR];


	printf("Apunte la nota de hoy:\n"); //despues de "hoy" deberia ir la fecha de hoy automaticamente

	//fgets(str, MAX_CAR, stdin);
	//clear_if_needed(str);
	//sscanf(str, "%s", nota);

	scanf("%s", nota);


	guardar(nota);


}




int clear_if_needed (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}


int leer()
{
	
	FILE* f;
        char c;

	int num_lines = 0;

	//abrir fichero para lectura
	f = fopen("nota.txt", "r");
       
	//leer mientras no se llegue al final del fichero EOF
	while ((c = fgetc(f)) != EOF)
	{ 
		putchar(c);
	}
	//cerrar fichero
	fclose(f);

	return 0;
}

