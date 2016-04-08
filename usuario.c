#include <stdio.h>
#include "usuario.h"
#include <string.h>
#include <stdlib.h>



void AbrirFichero(const char *filename, const char *mode){
	
	FILE* fichero;
    fichero = fopen(filename, mode);

    if(fichero == NULL){
    	printf("\nError de apertura del fichero\n");
    }
}

void CerrarFichero(FILE* fichero){

	fclose (fichero);
}

void EscribirEnFichero (Usuario *u, int total){

	//fputs(nombre, fichero);
	//fputs (contrasenya, fichero);
	//fprintf(fichero, nombre, contrasenya);

}

void LeerDesdeFichero (FILE *fichero){
	char caracteres[100];
	int i = 0;
	while ((caracteres[i]=fgetc(fichero))!=EOF){
		printf("%s\n", caracteres[i]);
		i++;
	}

	/*int j=0;
	while (! feof(fichero)){
		fscanf(fichero,"%s", caracteres[j]);
		printf("%s\n", caracteres[j]);
		j++;
	}

	int k=0;
	for (k=0; k<5; k++){
		caracteres[k] = fgetc(fichero);
		printf("%s\n", caracteres[k]);
	}*/
	
}