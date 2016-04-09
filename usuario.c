#include <stdio.h>
#include "usuario.h"
#include <string.h>
#include <stdlib.h>


/*char* getNombre(int i){
	return usuario[i].nombre;
}

char* getContrasenya(int i){
	return usuario[i].contrasenya;
}
*/
void imprimir(Usuario *u, int total)
{
	int i = 0;
	for (i; i<total; i++)
		printf("\nNUM USUARIO %d:\nNombre: %s, Contrasenya: %s\n", i+1, u[i].nombre, u[i].contrasenya);
}


int AbrirFichero(FILE *fichero){

    fichero = fopen("usuario.dat", "wb");

    if(fichero == NULL){
    	printf("\nError de apertura del fichero\n");
    }

    return 0;
}


int CerrarFichero(FILE *fichero){

	fclose (fichero);
	return 0;
}

int EscribirEnFichero (Usuario *u, int total){

	FILE *fichero;
	fichero = fopen("usuario.dat", "wb"); // edo ab???
	fputc (total, fichero);
	fwrite (u, sizeof(Usuario), total, fichero);


	CerrarFichero(fichero);

	printf("USUARIO REGISTRADO!\n");

	return 0;

}

Usuario* LeerDesdeFichero (Usuario *u, int total){

	FILE *fichero;
	int num_elemt;
	fichero = fopen("usuario.dat", "rb");

	total = fgetc(fichero);
	u = (Usuario*)malloc(total * sizeof(Usuario));
	fread(u, sizeof(Usuario), total, fichero);

	
	imprimir(u, total);
	

	CerrarFichero(fichero);


	return u;
}