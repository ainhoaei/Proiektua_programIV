#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menuLoginCpp.h"
#include <iostream>
#include <string>
#include <string.h>
#include "menuPrincipalCpp.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;


string insertarNombre(){

    string nombre;
    cout << "Escriba el nuevo nombre de usuario: " << endl;
    cin >> nombre;

    return nombre;
}

string insertarContransenya (){

	string contrasenya;
   
    cout << "Escriba la contrasenya para el usuario: " << endl;
    cin >> contrasenya;

    return contrasenya;
}



//int main() {
int menuPrincipalCpp::menuPrinci ()
{

	DBConnector dbConnector("test.sqlite"); //INSTANCIA

    int result = 0;

	/*result = dbConnector.eliminarUsuario();
	//BORRAR TODO EL CONTENIDO DE LA BD
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		return result;
	}
    */
	
	int opc=0;

    string nombre;
    string contrasenya;

    menuLoginCpp login;
     do
    {
        cout << "\nMENU PRINCIPAL: Seleccione una opcion " << endl;
        cout << "1. Log in (C++)   2. Registrarse (C++)   3. Salir" << endl;
        cin >> opc;

        switch(opc){
            case 1: nombre = insertarNombre();
                    contrasenya = insertarContransenya();

                    result = dbConnector.chequearUsuario((char*)nombre.c_str(), (char*)contrasenya.c_str());

                    if (dbConnector.getNum() == 5 && result == SQLITE_OK)
                    //SI EXISTE EL USUARIO, ENTRAR
                    {
                        login.menuaCpp(nombre);
                        break;
                    }
                    if (dbConnector.getNum() != 5){
                    //SI NO EXISTE EL USUARIO, INSERTAR
                        cout << "El nombre usuario y contrasenya incorrectas" << endl;
                    }

                    break;

            case 2: nombre = insertarNombre();
                    contrasenya = insertarContransenya();

                    result = dbConnector.chequearUsuario((char*)nombre.c_str(), (char*)contrasenya.c_str());

                    if(dbConnector.getNum() == 5 && result == SQLITE_OK)
                    {
                       cout << "El nombre usuario y contrasenya ya existen, intentelo de nuevo" << endl;
                    }
                    if (dbConnector.getNum() != 5)
                    {
                    //SI NO EXISTE EL USUARIO, INSERTAR
                        result = dbConnector.insertarUsuario(nombre, contrasenya);
                        break;
                    }
                    
                    break;
            case 3: cout << "Adios!"<< endl; 
                    break;
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc != 3);


   /* result = dbConnector.mostrarUsuarios();
    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
        return result;
    }
    */
    //cout << "menuPrinci bukatu" << endl;


	return 0;
}