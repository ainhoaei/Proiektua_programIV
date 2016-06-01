#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menuLoginCpp.h"
#include "UsuarioCpp.h"
#include <iostream>
#include <string>
#include "menuPrincipalCpp.h"

using namespace std;


string insertarNombre(UsuarioCpp *usuario){

    string nombre;
    cout << "Escriba el nuevo nombre de usuario: " << endl;
    cin >> nombre;
    usuario->setNombre(nombre.substr(0, 9));

    return usuario->getNombre();
}

string insertarContransenya (UsuarioCpp *usuario){

	string contrasenya;
   
    cout << "Escriba la contrasenya para el usuario: " << endl;
    cin >> contrasenya;

    usuario->setContrasenya(contrasenya.substr(0, 9));

    return usuario->getContrasenya();
}



//int main() {
void menuPrincipalCpp::menuPrinci ()
{

	DBConnector dbConnector("test.sqlite"); //INSTANCIA

    int result = 0;
	int total = 0; //eztakit total hau beharrezkoa dan!
    UsuarioCpp usu[50];

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
            case 1: nombre = insertarNombre(&usu[total]);
                    contrasenya = insertarContransenya(&usu[total]);

                    result = dbConnector.chequearUsuario((char*)nombre.c_str(), (char*)contrasenya.c_str());
                    if(result == 5)
                    //SI EXISTE EL USUARIO, ENTRAR
                    {
                        login.menuaCpp(nombre);
                        break;
                    }
                    if (result != 5){
                    //SI NO EXISTE EL USUARIO, INSERTAR
                        cout << "El nombre usuario y contrasenya incorrectas" << endl;
                    }

                    if ( result != SQLITE_OK) {
                        cout << "Error inserting new data. Already exists" << endl;
                        //return result;
                    }
                    break;

            case 2: nombre = insertarNombre(&usu[total]);
                    contrasenya = insertarContransenya(&usu[total]);

                    result = dbConnector.chequearUsuario((char*)nombre.c_str(), (char*)contrasenya.c_str());
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
                        //return result;
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

	//return 0;
}