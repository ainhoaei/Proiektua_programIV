#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAR 200
#define MAX_FECHA 4

int main(void){
	
	setvbuf (stdout, 0, _IONBF, 0);



	int opcion;
    int total;
    total = 0;
    
    do{
    	avisoRecordatorio();
        printf("Seleccione la accion a realizar:\n1. Anyadir recordatorio\n2. Eliminar recordatorio\n3. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: recordatorio();break;
            case 2: break;
            case 3: break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 3 );

	return 0;
}


int recordatorio(){

	char recordatorio[MAX_CAR];
	char str[MAX_FECHA];
    char dia[MAX_FECHA];
    char mes[MAX_FECHA];
    char anyo[MAX_FECHA];
    char fecha[7];
    

	printf("");
    fgets(str, MAX_FECHA, stdin);
    clear_if_needed(str);
	//DIA
   
    int b=33;
   
    do{
	    printf ("Añade la FECHA del recordatorio (Introduzca los 2 digitos en cada apartado):\nDia: ");
	    fgets(str, MAX_FECHA, stdin);
	    clear_if_needed(str);
	   
	   b = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 31 
	    
	}while(b > 31);

	sscanf(str, "%s", dia); //eliminar el \n final

	//MES
	int m = 17;
	do{
	    printf("Num mes: ");
	    fgets(str, MAX_FECHA, stdin);
	    clear_if_needed(str);

	    m = atoi(str); //PARA QUE NO SE PUEDA ESCRIBIR MÁS DE 12 

	}while(m > 12);
	sscanf(str, "%s", mes);

	//ANYO
	int a = 10;
	do{
	    printf("Anyo: ");
	    fgets(str, MAX_FECHA, stdin);
	    clear_if_needed(str);

	    
	    a = atoi (str); //PARA QUE NO SE PUEDA ESCRIBIR MENOS DE 16

    }while (a < 16);
   sscanf(str, "%s", anyo);
    
    printf("\n");

    strcpy(fecha, mes);
    strcat(fecha, "/");
    strcat(fecha, dia);
    strcat(fecha,"/");
    strcat(fecha,anyo);
    strcat(fecha,": ");



	printf("Apunte su recordatorio:\n"); 
	
	scanf(" %[^\n]s", recordatorio); //honekin espazioak kontuan hartzen ditu!!!
	strcat(fecha,recordatorio);
	guardar(fecha);


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
  //strftime(buffer,80,"%x - %I:%M%p", info);
  return (char*)buffer;
}

int guardar(char nuevoRecordatorio[])
{
	
	FILE* f;
    int c;
    
	//abrir fichero para escritura "w"
	f = fopen("recordatorio.txt", "a");
    

	//escribir en fichero un string formateado 	
	//fprintf(f, "\n");

	fprintf(f, "%s\n", nuevoRecordatorio);
		
	//cerrar fichero
	fclose(f);

	return 0;
}

int clear_if_needed (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}

int avisoRecordatorio(){

	FILE* f;
	char date[8];
	strcpy(date,fecha());
    char read[MAX_CAR];

	int semaforo = 0;


	printf("-------------------------\n", date);
	 printf("Fecha de hoy: %s\n", date);

	//abrir fichero para lectura
	f = fopen("recordatorio.txt", "r");
       
	while(fgets(read, MAX_CAR, f)) {

				//strcmp ez zuen funtzionatzen beraz horrela egin dugu
		if(read[0]==date[0] && read[1]==date[1] && read[3]==date[3] && read[4]==date[4] && read[6]==date[6] && read[7]==date[7]){ 

			//&& read[1]==date[1] && read[3]==date[3] && read[4]==date[4] && read[6]==date[6] && read[7]==date[7]){

	    printf("*%s", read+10);
	    semaforo++;
		
		}
	 }
	
	if(semaforo>0)printf("Tienes %i recordatorio(s)\n", semaforo);
	if(semaforo==0)printf("No tienes recordatorios\n");

	printf("-------------------------");
	//cerrar fichero
	fclose(f);

	return 0;
}
