#include <stdio.h>
#include "usuario.h"



void AbrirFichero(const char *filename, const char *mode){
	
	FILE* fichero;
    fichero = fopen(filename, mode);

    /*if(fichero == null){
    	printf("\nError de apertura del fichero\n");
    }*/
}

int CerrarFichero(FILE* fichero){

	return fclose (fichero);
}

/*int EscribirEnFichero (FILE *fichero, const char nombre[], const char contrasenya[]){

	fputs(nombre, fichero);
	fputs (contrasenya, fichero);
	fprintf(fichero, nombre, contrasenya);

	return 0;
}

int LeerDesdeFichero (FILE *fichero){
	char caracteres[100];
	
	int i = 0;
	for (i=0; i<5; i++){
		caracteres[i] = fgetc(fichero);
		printf("%s\n", caracteres[i]);
	}
	
}*/