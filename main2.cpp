#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menu.h"
#include "menuLoginCpp.h"
#include "UsuarioCpp.h"
#include <iostream>
#include <stdio.h>
#include "string.h"
#include <string>
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 10
#define NUM_ELEMENTOS 2



void liberarMemoria (Usuario *u, int total){
    int i;
    for (i = 0; i < total; i++){
        free(u[i].nombre);
        free(u[i].contrasenya);
    }
}


string insertarNombre(UsuarioCpp *usuario){

    string nombre;
    cout << "Escriba el nuevo nombre de usuario: " << endl;
    cin >> nombre;
    usuario->setNombre(nombre.substr(0, 9));

    return usuario->getNombre();
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
    UsuarioCpp usu[50];

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

    string nombre2;
    string contrasenya2;

    menuLoginCpp login;

     do
    {
        cout << "\nMENU PRINCIPAL: Seleccione una opcion " << endl;
        cout << "1. Log in   2. Registrarse   3. Salir" << endl;
        cin >> opc;

        switch(opc){
            case 1: //strcpy(nombre, insertarNombre(&u[total]));
                    nombre2 = insertarNombre(&usu[total]);
                    strcpy(contrasenya, insertarContransenya(&u[total]));

                    result = dbConnector.chequearUsuario(nombre2.c_str(), contrasenya);
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

            case 2: //strcpy(nombre, insertarNombre(&u[total]));
                    nombre2 = insertarNombre(&usu[total]);
                    strcpy(contrasenya, insertarContransenya(&u[total]));

                    result = dbConnector.chequearUsuario(nombre2.c_str(), contrasenya);
                    if(result == 5)
                    {
                       cout << "El nombre usuario y contrasenya ya existen, intentelo de nuevo" << endl;
                    }
                    if (result != 5){
                    //SI NO EXISTE EL USUARIO, INSERTAR
                        contrasenya2 = contrasenya;
                        result = dbConnector.insertarUsuario(nombre2, contrasenya);
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