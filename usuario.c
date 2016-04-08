#include <stdio.h>
#include "usuario.h"
#include <string.h>
#include <stdlib.h>




void AbrirFichero(FILE *fichero){

    fichero = fopen("usuario.dat", "wb");

    if(fichero == NULL){
    	printf("\nError de apertura del fichero\n");
    }
}


void CerrarFichero(FILE *fichero){

	fclose (fichero);
}

void EscribirEnFichero (FILE *fichero, Usuario *u, int total, char *w){


	//  EZ DET PROBRATU ONDO EGITEN DUEN


	fputc (total, fichero);
	fwrite (u, sizeof(Usuario), total, fichero);
	
	int len;
	len = strlen (w);
	fputc(len, fichero);
	fwrite (w, sizeof(char), len, fichero);

	

}

void LeerDesdeFichero (FILE *fichero, int total, char *w){
	

	//  EZ DET PROBRATU ONDO EGITEN DUEN



	total = fgetc(fichero);

	w = (char*)malloc((total+1) * sizeof(char));
	fread (w, sizeof(char), total, fichero);
	w[total] = '\0';

	CerrarFichero(fichero);

	printf("%s\n", w);

	free(w);

	
}