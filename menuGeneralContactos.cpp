#include "contactosCpp.h"
#include "contactoEmp.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menu.h"
#include "menuLoginCpp.h"
//#include "UsuarioCpp.h"
#include <iostream>
#include <stdio.h>
#include "string.h"
#include <string>
#include <stdlib.h>
#include "menuContactosCpp.h"

#define MAX_LENGTH 40


int main()
{

    DBConnector dbConnector("test.sqlite");
	int result = 0;
	int opc=0;
    //contactoEmp e[100];
    // int total = 0;rinh
    string nombre = "aran";

    menuContactosCpp c;
     do{

     	//Persona *p1 = new Persona("Juanito", 15); //La clase es abstracta
     	
   
        cout << "\nMENU CONTACTOS: Selecciona una opcion " << endl;
        cout << "1. Insertar Contacto  2. Ver Contactos  3. Eliminar Contacto" << endl;
        cin >> opc;
      

        switch(opc){
            case 1:  
            			c.menuContactos();
             			
                    
                    break;
                    
            case 2:                     
                     
                    dbConnector.mostrarContactoEmp();
                     //contactoEmp::modificarContacto();

                      
            case 3:  dbConnector.mostrarContactoEmp();

                     //Elegitu borratu nahi dezun kontaktua
                     //DBConnector::eliminarContactoEmp();

            
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc != 3);


    //result = dbConnector.mostrarUsuarios();
    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
        return result;
    }

     //liberarMemoria(u, total);

	return 0;
}

