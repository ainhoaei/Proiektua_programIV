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


void menuContactosCpp::menuEmpresa()
{
    DBConnector dbConnector("test.sqlite");
    int result = 0;
    int opc=0;
    contactoEmp e[100];
    int total = 0;

    do{

        cout << "\nMENU CONTACTOS EMPRESA: Seleccione una operacion " << endl;
        cout << "1. Insertar Contacto  2. Ver Contacto  3. Eliminar Contacto" << endl;
        cin >> opc;
      

        switch(opc){
            case 1:  
                         
                        e->meterContacto(&e[total], total);
                        result = dbConnector.insertarContactoEmp(e->getNombre(), e->getApellido(), e->getTlf(), e->getEmp(), e->getPu(), e->getEmail());
                        total++;
                    

                    if ( result != SQLITE_OK) {
                         cout << "Error inserting new data. Already exists" << endl;
                       
                    }
                    
                    break;
            case 2:                     
                     
                    dbConnector.mostrarContactoEmp();
                    break;
                    

                      
            case 3:  

                    dbConnector.mostrarContactoEmp(); 
                    break;

                     //Elegitu borratu nahi dezun kontaktua
                     //DBConnector::eliminarContactoEmp();

            
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc > 3);

    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
      
    }

}


int main()
{
    menuContactosCpp m;
    DBConnector dbConnector("test.sqlite");
	int result = 0;
	int opc=0;
    contactoEmp e[100];
     int total = 0;
     do{

     	//Persona *p1 = new Persona("Juanito", 15); //La clase es abstracta
     	
   
        cout << "\nMENU CONTACTOS: Seleccione el numero del tipo de contacto en el cual quieres realizar las operaciones " << endl;
        cout << "1. Empresa  2. Favorito" << endl;
        cin >> opc;
      

        switch(opc){
            case 1:   m.menuEmpresa();
                        break;

            case 2:  //m.menuFavoritos();  
                        break;

            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc != 3);


   
    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
        return result;
    }

    

	return 0;
}

