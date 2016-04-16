#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAR 200

int main(void){
	
	setvbuf (stdout, 0, _IONBF, 0);



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
}


char* fecha (void)
{
  //devulve un char con la fecha de cuando se ejecuta

  time_t rawtime;
  struct tm *info;
  char *buffer;
  buffer=(char*)malloc(80);
  time( &rawtime );

  info = localtime( &rawtime );

  strftime(buffer,80,"%x - %I:%M%p", info);
  return (char*)buffer;
}

int guardar(char nuevaNota[])
{
	
	FILE* f;
    int c;
    
	//abrir fichero para escritura "w"
	f = fopen("nota.txt", "a");
    

	//escribir en fichero un string formateado 	
	fprintf(f, "========================================\n");
	fprintf(f, "Nota del dia: ");
	fprintf(f, fecha());
	fprintf(f, "\n");

	fprintf(f, "%s\n", nuevaNota);
		
	//cerrar fichero
	fclose(f);

	return 0;
}




int apuntarNota(){

char str[MAX_CAR];
char nota[MAX_CAR];



	printf("Apunte la nota de hoy:\n"); //despues de "hoy" deberia ir la fecha de hoy automaticamente
	
	//fflush(stdin);//sin sslush no funciona fgets, no se sabe por que
	
	//fgets(str, MAX_CAR, stdin);
	//clear_if_needed(str);
	//sscanf(str, "%s", nota);
	

	//scanf("%s", nota);
	scanf(" %[^\n]s", nota); //honekin espazioak kontuan hartzen ditu!!!

	guardar(nota);

	return 0;

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

