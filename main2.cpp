#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menu.h"
#include "menuLoginCpp.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define NUM_ELEMENTOS 2

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


char* insertarNombre(Usuario *usuario){

    char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];


   /* //GALDETU HAU!
    printf("\n");
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);*/

    cout << "Escriba el nuevo nombre de usuario: " << endl;
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final
     
    
    //RESERVAR LA MEMORIA JUSTA PARA LA CADENA ALMACENADA
    usuario->nombre = (char *)malloc((strlen(frmt_str) + 1) * sizeof  (char));
    //strlen: longitud de la cadena de frmt_str sin /0, por ello, le metemos un +1.
    strcpy(usuario->nombre, frmt_str); //STRING COPY

    return usuario->nombre;

}

char* insertarContransenya (Usuario *usuario){

	char str[MAX_LENGTH];
    char frmt_str[MAX_LENGTH];
   
    cout << "Escriba la contrasenya para el usuario: " << endl;
    fgets(str, MAX_LENGTH, stdin);
    clear_if_neededC(str);
    sscanf(str, "%s", frmt_str); //eliminar el \n final

    //RESERVAR LA MEMORIA JUSTA
    usuario->contrasenya = (char *)malloc((strlen(frmt_str)+1) * sizeof(char));
    strcpy(usuario->contrasenya, frmt_str);

    return usuario->contrasenya;
}

int main() {

	DBConnector dbConnector("test.sqlite"); //INSTANCIA

	Usuario u[50];
	int total = 0; //eztakit total hau beharrezkoa dan!


	/*int result = dbConnector.eliminarUsuario();
	//BORRAR TODO EL CONTENIDO DE LA BD
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		return result;
	}*/

	int result = 0;
	int opc=0;

    char nombre[50];
    char contrasenya[50];

    menuLoginCpp login;

     do
    {
        cout << "\nMENU PRINCIPAL: Seleccione una opcion " << endl;
        cout << "1. Log in   2. Registrarse   3. Salir" << endl;
        cin >> opc;

        switch(opc){
            case 1: strcpy(nombre, insertarNombre(&u[total]));
                    strcpy(contrasenya, insertarContransenya(&u[total]));

                    result = dbConnector.chequearUsuario(nombre, contrasenya);
                    if(result == 5)
                    //SI EXISTE EL USUARIO, ENTRAR
                    {
                        login.menuaCpp(nombre);
                    }
                    if (result != 5){
                    //SI NO EXISTE EL USUARIO, INSERTAR
                        cout << "El nombre usuario y contrasenya incorrectas" << endl;
                    }

                    if ( result != SQLITE_OK) {
                        cout << "Error inserting new data. Already exists" << endl;
                        return result;
                    }
                    break;

            case 2: strcpy(nombre, insertarNombre(&u[total]));
                    strcpy(contrasenya, insertarContransenya(&u[total]));

                    result = dbConnector.chequearUsuario(nombre, contrasenya);
                    if(result == 5)
                    {
                       cout << "El nombre usuario y contrasenya ya existen, intentelo de nuevo" << endl;
                    }
                    if (result != 5){
                    //SI NO EXISTE EL USUARIO, INSERTAR
                        result = dbConnector.insertarUsuario(nombre, contrasenya);
                        total++;
                    }

                    if ( result != SQLITE_OK) {
                         cout << "Error inserting new data. Already exists" << endl;
                        return result;
                    }
                    
                    break;
            case 3:  cout << "Adios!"<< endl; break;
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc != 3);


    result = dbConnector.mostrarUsuarios();
    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
        return result;
    }

     liberarMemoria(u, total);

	return 0;
}