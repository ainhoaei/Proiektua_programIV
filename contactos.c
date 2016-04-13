#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <stdlib.h>

#include "contactos.h"


#define MAX_CONTACTOS 	5
#define MAX_LENGTH	18
#define MAX_TLF 10


//MENU CONTACTOS

int main() // gero main en ordez contactos jarri behar da.
{

	Contacto c[MAX_CONTACTOS];

	//FILE *fichero_c;

    int opcion;
    int total = 0;

    do{
        printf("Seleccione la accion a realizar:\n1. Anyadir contactos\n2. Ver contactos\n3. Eliminar contacto\n4. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: if (total<MAX_CONTACTOS)
            		{
            			insertarContacto(&c[total], total);

            			total++;
            			escribirEnFichero(c, total);
					} else

					{
						printf("No se admiten mas asignaturas\n");
					}
					break;

            case 2: imprimirListado (c, total); break;
            case 3: leerDesdeFichero(); break;
            case 4: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 4 );

    //liberar memoria de todos los malloc que hemos hecho.

    liberarMemoria(c, total);

    return 0;
}

void insertarContacto(Contacto *c, int total)
{
	char str[MAX_LENGTH];
	char frmt_str [MAX_LENGTH];

	char str_tlf[MAX_TLF];


	//printf("");
	printf("Contacto [%d]\n", total +1);
	fgets(str, MAX_LENGTH, stdin);
	clear_if_needed (str);

	printf("Nombre: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_needed (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->nombre, frmt_str);



	printf("Apellido: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_needed (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->apellido = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->apellido, frmt_str);


	printf("Email: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_needed (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->email = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->email, frmt_str);

	
	printf("Empresa: \n");
	fgets (str, MAX_LENGTH, stdin);
	clear_if_needed (str);
	sscanf(str, "%s", frmt_str); // el scanf elimina el \n final

	//reservar la memoria justa para la cadena almacenada
	c->empresa = (char *)malloc((strlen(frmt_str) + 1) * sizeof(char)); //
	strcpy(c->empresa, frmt_str);

	printf("Numero de telefono: \n");
	fgets(str_tlf, MAX_TLF, stdin);
	clear_if_needed(str_tlf);
	sscanf(str_tlf, "%d", &c->num_tlf);
	printf("\n");



}

void liberarMemoria(Contacto *c, int total)//HACER EL FREE PORQUE UTILIZAMOS EL  malloc
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

int clear_if_needed (char *str){

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

int escribirEnFichero (Contacto *c, int total)
{


	FILE *fichero;
	fichero = fopen("contacto.txt", "a"); // 

	if(fichero == NULL){
        fclose(fichero);
        fichero = fopen("contacto.txt", "w");
        printf("ez!\n");
    }

	  int i;
    for(i=0; i<total; i++)
    {
        fprintf(fichero, "%s\n", c[i].nombre);
        fprintf(fichero, "%s\n", c[i].apellido);
        fprintf(fichero, "%s\n", c[i].email);
        fprintf(fichero, "%s\n", c[i].empresa);

       
    }

	

	CerrarFichero(fichero);

	printf("CONTACTO GUARDADO!\n");

	return 0;

}






//EZ DU ONDO FUNTZIONATZEN!




int leerDesdeFichero ()
{

	FILE *fichero;
	char a;
	fichero = fopen("contacto.txt", "r");

	while ((a = fgetc(fichero)) != EOF) //EOF: End Of File
    {
    
  
        //if (a == '\n')
            //total++; //berez, irakurtzeko no es necesario
         
        putchar(a);
    }
    //cerrar fichero
    fclose(fichero);

    printf("\n");


	return 0;
}

