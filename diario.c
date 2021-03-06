#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "diario.h"

#define MAX_CAR 200
#define MAX_FECHA 4

int clear_if_neededD (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}

void verEspc(const char *nombre){

	char str[MAX_FECHA];
    char dia[MAX_FECHA];
    char mes[MAX_FECHA];
    char anyo[MAX_FECHA];
    char fecha[7];
    

	printf("\n");
    fgets(str, MAX_FECHA, stdin);
    clear_if_neededD(str);
	//DIA
   
    int b=33;
   
    do{
	    printf ("FECHA (Introduzca los 2 digitos en cada apartado):\nDia: ");
	    fgets(str, MAX_FECHA, stdin);
	    clear_if_neededD(str);
	   
	   b = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 31 
	    
	}while(b > 31);

	sscanf(str, "%s", dia); //eliminar el \n final

	//MES
	int m = 17;
	do{
	    printf("Num mes: ");
	    fgets(str, MAX_FECHA, stdin);
	    clear_if_neededD(str);

	    m = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 12 

	}while(m > 12);
	sscanf(str, "%s", mes);

	//ANYO
	int a = 10;
	do{
	    printf("Anyo: ");
	    fgets(str, MAX_FECHA, stdin);
	    clear_if_neededD(str);

	    
	    a = atoi (str); //PARA QUE NO SE PUEDA ESCRIBIR MENOS DE 16

    }while (a < 16);
   sscanf(str, "%s", anyo);
    
    printf("\n");

    strcpy(fecha, mes);
    strcat(fecha, "/");
    strcat(fecha, dia);
    strcat(fecha,"/");
    strcat(fecha,anyo);
    printf("notas del dia %s:\n", fecha);


    char const *p;
    p = "Nota.txt";
    char nombreFichero[20];
    strcpy(nombreFichero, nombre);
    strcat(nombreFichero, p);


    char read[MAX_CAR];
	FILE* f;

	//abrir fichero para lectura
	f = fopen(nombreFichero, "r");
       
	

	while(fgets(read, MAX_CAR, f)) {

		

		//strcmp ez zuen funtzionatzen beraz horrela egin dugu
		if(read[0]==fecha[0] && read[1]==fecha[1] && read[3]==fecha[3] && read[4]==fecha[4] && read[6]==fecha[6] && read[7]==fecha[7]){

	    printf("%s", read+10);
		
		}
	 	
	 }

	 	printf("\n");

	    
	//cerrar fichero
	fclose(f);
	

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

  strftime(buffer,80,"%x", info);
  return (char*)buffer;
}

int guardar(char nuevaNota[], const char *nombre)
{

	char const *p;
    p = "Nota.txt";
    char nombreFichero[20];
    strcpy(nombreFichero, nombre);
    strcat(nombreFichero, p);
	
	FILE* f;
    
	//abrir fichero para escritura "w"
	f = fopen(nombreFichero, "a");
    

	//escribir en fichero un string formateado 	
	fprintf(f, "========================================\n");

	fprintf(f, fecha());


	fprintf(f, ": %s\n", nuevaNota);
		
	//cerrar fichero
	fclose(f);

	return 0;
}




void apuntarNota(const char *nombre){

	char nota[MAX_CAR];

	printf("Apunte la nota de hoy:\n"); //despues de "hoy" deberia ir la fecha de hoy automaticamente

	scanf(" %[^\n]s", nota); //honekin espazioak kontuan hartzen ditu!!!

	guardar(nota, nombre);



}



void leer(const char *nombre)
{
	char const *p;
    p = "Nota.txt";
    char nombreFichero[20];
    strcpy(nombreFichero, nombre);
    strcat(nombreFichero, p);

	FILE* f;
    char c;

	//abrir fichero para lectura
	f = fopen(nombreFichero, "r");
       
	//leer mientras no se llegue al final del fichero EOF
	while ((c = fgetc(f)) != EOF)
	{ 
		putchar(c);
	}
	//cerrar fichero
	fclose(f);

	printf("\n");

	
}

