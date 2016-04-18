#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"


#define MAX_CONTACTOS 	5
#define MAX_LENGTH	18
#define MAX_TLF 10


void liberarMemoriaContacto(Contacto *c, int total)//HACER EL FREE PORQUE UTILIZAMOS EL  malloc
{
	int i;
	for (i = 0; i < total; i++)
	{
		free(c[i].nombre);
		free(c[i].apellido);
		free(c[i].email);
		free(c[i].empresa);

	}
			
		
}


void insertarContacto(Contacto *c, int total)
{
	char str[MAX_LENGTH];
	char frmt_str [MAX_LENGTH];

	char str_tlf[MAX_TLF];


	//printf("");
	printf("Contacto [%d]\n", total +1);
	fgets(str, MAX_LENGTH, stdin);
	clear_if_neededCT (str);

	printf("Nombre: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_neededCT (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->nombre, frmt_str);



	printf("Apellido: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_neededCT (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->apellido = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->apellido, frmt_str);


	printf("Email: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_neededCT (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->email = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->email, frmt_str);

	
	printf("Empresa: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_neededCT (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->empresa = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->empresa, frmt_str);

	printf("Numero de telefono: \n");
	fgets(str_tlf, MAX_TLF, stdin);
	clear_if_neededCT(str_tlf);
	sscanf(str_tlf, "%d", &c->num_tlf);
	printf("\n");



}



void imprimirListado(Contacto c[], int total)
{
	int i;

	printf("Listado de contactos\n\n");	
	for (i = 0; i < total; i++)
	{
		
		printf("Nombre: %s\n\n", c[i].nombre);// imprime el nombre
		printf("Apellido: %s\n\n", c[i].apellido);
		printf("Email: %s\n\n", c[i].email);
		printf("Empresa: %s\n\n", c[i].empresa);
		printf("Numero de telefono: %d\n\n", c[i].num_tlf);
		
	}
	printf("------------------------------\n");
}

int clear_if_neededCT (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}




int CerrarFichero(FILE *fichero){

	fclose (fichero);
	return 0;
}

int escribirEnFicheroContacto (Contacto *c, int total, char *nombre)
{

	char *p;
    p = "Contacto.txt";
    char nombreFichero[20];
    strcpy(nombreFichero, nombre);
    strcat(nombreFichero, p);


	FILE *fichero;
	fichero = fopen(nombreFichero, "a"); // 

	/*if(fichero == NULL){
        fclose(fichero);
        fichero = fopen("contacto.txt", "w");
        printf("ez!\n");
    }*/

	
        fprintf(fichero, "%s\n", c[total].nombre);
        fprintf(fichero, "%s\n", c[total].apellido);
        fprintf(fichero, "%s\n", c[total].email);
        fprintf(fichero, "%s\n", c[total].empresa);

	

	CerrarFichero(fichero);

	printf("CONTACTO GUARDADO!\n");

	return 0;

}



int leerDesdeFicheroContacto (char *nombre)
{

	char *p;
    p = "Contacto.txt";
    char nombreFichero[20];
    strcpy(nombreFichero, nombre);
    strcat(nombreFichero, p);



	FILE *fichero;
	char a;
	fichero = fopen(nombreFichero, "r");

	while ((a = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        putchar(a);
    }
    //cerrar fichero
    fclose(fichero);

    printf("\n");


	return 0;
}

//MENU CONTACTOS

void menuContacto(char *nombre) 
{

	Contacto c[MAX_CONTACTOS];


    int opcion;
    int total = 0;

    do{
        printf("Seleccione la accion a realizar:\n1. Anyadir contactos\n2. Ver contactos\n3. Eliminar contacto (no operativo)\n4. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: if (total<MAX_CONTACTOS)
            		{
            			insertarContacto(&c[total], total);

            			escribirEnFicheroContacto(c, total, nombre);
            			total++;
					} else

					{
						printf("No se admiten mas asignaturas\n");
					}
					break;

            case 2: leerDesdeFicheroContacto(nombre); break;
            case 3:  break;
            case 4: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 4 );

    //liberar memoria de todos los malloc que hemos hecho.

    liberarMemoriaContacto(c, total);

}