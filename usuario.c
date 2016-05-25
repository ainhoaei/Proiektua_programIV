#include <stdio.h>
#include "menu.h"
#include <string.h>
#include <stdlib.h>

int EscribirEnFicheroUsuario (Usuario *u, int total){

	FILE *fichero;
	fichero = fopen("usuario.txt", "a"); 

	if(fichero == NULL){
    	printf("\nError de apertura del fichero\n");
    }

 
        fprintf(fichero, "%s#", u[total].nombre);
       	fprintf(fichero, "%s\n", u[total].contrasenya);


    //cerrar fichero
	fclose(fichero);

	printf("USUARIO REGISTRADO!\n");

    return 0;

}



int LeerDesdeFicheroUsuario (int total){

	FILE *fichero;
	char c;
	fichero = fopen("usuario.txt", "r");

	//leer mientras no se llegue al final del fichero EOF
    while ((c = fgetc(fichero)) != EOF) //EOF: End Of File
    {
        if (c == '#')
            putchar(c);

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



void clear_if_neededC (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }
}

void liberarMemoria (Usuario *u, int total){
    int i;
    for (i = 0; i < total; i++){
        free(u[i].nombre);
        free(u[i].contrasenya);
    }
}
