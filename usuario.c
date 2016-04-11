#include <stdio.h>
#include "usuario.h"
#include <string.h>
#include <stdlib.h>

/*void imprimir(Usuario *u, int total)
{
	int i = 0;
	printf("total: %d\n", total);
	for (i; i<total; i++){
		printf("bai!\n");
		printf("\nNUM USUARIO %d:\nNombre: %s, Contrasenya: %s\n", i+1, u[i].nombre, u[i].contrasenya);
	}
}
*/

int EscribirEnFichero (Usuario *u, int total){

	FILE *fichero;
	fichero = fopen("usuario.txt", "a"); // edo ab???

	if(fichero == NULL){
    	printf("\nError de apertura del fichero\n");
    }

    int i;
    for(i=0; i<total; i++)
    {
        fprintf(fichero, "%s\n", u[i].nombre);
       	fprintf(fichero, "%s\n", u[i].contrasenya);
    }


    //cerrar fichero
	fclose(fichero);

	printf("USUARIO REGISTRADO!\n");

	return total;

}



int LeerDesdeFichero (Usuario *u, int total){

	FILE *fichero;
	char c;
	fichero = fopen("usuario.txt", "r");

	//leer mientras no se llegue al final del fichero EOF
    while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        if (c == '\n')
            total++; //berez, irakurtzeko no es necesario
        putchar(c);
    }
    //cerrar fichero
    fclose(fichero);

    printf("El fichero tiene %i lineas\n", total-1); 
    //total-1 egiten det azkeneko \n ere kontuan hartzen duelakobestela eta linea bat gehiago 
    //kontatzen duelako

	return 0;

}

/*int print(Usuario *u)
{
	printf("Nombre: %s / Contrasenya: %s\n", u->nombre, u->contrasenya);

	return 0;
}*/