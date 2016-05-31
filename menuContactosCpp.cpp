#include "contactosCpp.h"
#include "contactoEmp.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menu.h"
#include "menuLoginCpp.h"
#include "menuContactosCpp.h"
#include <iostream>
#include <stdio.h>
#include "string.h"
#include <string> 
#include <stdlib.h>

using namespace std;

#define MAX_LENGTH 40


int menuContactosCpp::menuContactos()
{

    DBConnector dbConnector("test.sqlite");
	int result = 0;
	int opc=0;
    contactoEmp e[100];
     int total = 0;
     do{

     	//Persona *p1 = new Persona("Juanito", 15); //La clase es abstracta
     	
   
        cout << "\nMENU CONTACTOS: Seleccione el tipo de contacto que deseas insertar " << endl;
        cout << "1. Empresa  2. Favorito  3. Conocido" << endl;
        cin >> opc;
      

        switch(opc){
            case 1:  
            			 
             			e->meterContacto(&e[total], total);
                        result = dbConnector.insertarContactoEmp(e->getNombre(), e->getApellido(), e->getTlf(), e->getEmp(), e->getPu(), e->getEmail());
                        total++;
                    

                    if ( result != SQLITE_OK) {
                         cout << "Error inserting new data. Already exists" << endl;
                        return result;
                    }
                    
                    break;
            /*        
            case 2:                     
                       result = dbConnector.insertarContactoEmp(nombre2, apellido2, tfl2, pueblo2, edad2);
                        //total++;
                    

                    if ( result != SQLITE_OK) {
                         cout << "Error inserting new data. Already exists" << endl;
                        return result;
                    }
                    
                    
                    break;
            case 3:  cout << "Adios!"<< endl; break;

            */
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

