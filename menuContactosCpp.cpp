#include "contactosCpp.h"
#include "contactoEmp.h"
#include "contactoFavorito.h"
#include "DBConnector.h"
#include "menuLoginCpp.h"
#include "menuContactosCpp.h"
#include "menuPrincipalCpp.h"
#include "SubmenusCpp.h"

#include "sqlite3.h" //IMPORTANTE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

#define MAX_LENGTH 40


void menuEmpresa(string usuario)
{
    DBConnector dbConnector("test.sqlite");
    int result = 0;
    int opc=0;
    contactoEmp e[100];
    int total = 0;


    do{

        cout << "\nMENU CONTACTOS EMPRESA: Seleccione una operacion " << endl;
        cout << "1. Insertar Contacto  2. Ver Contacto  3. Eliminar Contacto  4. Salir"<< endl;
        cin >> opc;
      

        switch(opc){ 
            case 1:  e->meterContacto(&e[total], total, usuario);
                    result = dbConnector.insertarContactoEmp(e->getNombre(), e->getApellido(), e->getTlf(), e->getEmp(), e->getPu(), e->getEmail(), e->getUsuario());
                    total++;
                    if ( result != SQLITE_OK) {
                         cout << "Error inserting new data. Already exists" << endl;
                       
                    }
                    
                    break;

            case 2: dbConnector.verContactoEmp(usuario);
                    break;  

            case 3: int opcion;
                    dbConnector.mostrarContactoEmp(usuario); 
                    cin>>opcion;

                    dbConnector.eliminarContactoEmp(opcion, usuario);
                    break;

             case 4: break;
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc > 3);

    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
      
    }


}

void menuFavorito(string usuario)
{
    DBConnector dbConnector("test.sqlite");
    int result = 0;
    int opc=0;
    contactoFavorito f[100];
    int total = 0;

    do{

        cout << "\nMENU CONTACTOS FAVORITOS: Seleccione una operacion " << endl;
        cout << "1. Insertar Contacto  2. Ver Contacto  3. Eliminar Contacto  4. Salir" << endl;
        cin >> opc; 
      

        switch(opc){
            case 1:  
                         
                        f->meterContacto(&f[total], total, usuario);
                        result = dbConnector.insertarContactoFa(f->getNombre(), f->getApellido(), f->getTlf(), f->getDir(), f->getMote(), f->getUsuario());
                        total++;
                    

                    if ( result != SQLITE_OK) {
                         cout << "Error inserting new data. Already exists" << endl;
                       
                    }
                    
                    break;
            case 2:                     
                     dbConnector.verContactoFa(usuario);
                    
                    break;
                      
            case 3: 
                    int opcion;
                    dbConnector.mostrarContactoFa(usuario); 
                    cin>>opcion;

                    dbConnector.eliminarContactoFa(opcion, usuario);

                    break;

            case 4:  
                      break;
        
            
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;

        }
        } while (opc > 4);

    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
      
    }


    }


void SubmenusCpp::menuContacto(string usuario)
{
    //gero HAU PARAMETROZ PASAKOA 

    //string usuario= "aran";
    DBConnector dbConnector("test.sqlite");
	int result = 0;
	int opc=0;

     do{

     	//Persona *p1 = new Persona("Juanito", 15); //La clase es abstracta
     	
   
        cout << "\nMENU CONTACTOS: Seleccione el numero del tipo de contacto en el cual quieres realizar las operaciones " << endl;
        cout << "1. Empresa  2. Favorito  3. Salir" << endl;
        cin >> opc;
      

        switch(opc){
            case 1:   menuEmpresa(usuario);
                        break;

            case 2:  menuFavorito(usuario);  
                        break;

            case 3:  break;

            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }

    } while (opc != 3);


   
    if (result != SQLITE_OK) {
        cout << "Error getting all users"<< endl;
    }

}

