#include <stdio.h>
#include "string.h"
#include <string>
#include <stdlib.h>
#include "Tarea.h"
#include "TareaCpp.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main ()
//menuTarea (string nombre)  //MAIN BEHARREN GERO HAU JARRI BEHAR DA!
{
    
    Tarea tarea[100];
    string nombre = "aran"; //HAU GERO KENDU IN BEHAR DA!
    int opcion;
    int total;
    total = 0;

    string x = "Tarea.txt";
    string nombreFichero = nombre + x;

    TareaCpp tareaCpp;
     

    

    do{
        cout <<"Seleccione la accion a realizar:\n1. Introducir tarea\n2. Ver tareas a realizar\n3. Modificar tarea (no operativo)\n4. Eliminar tarea (no operativo)\n5. Atras" << endl;
       cin >> opcion;

        switch(opcion){
            case 1: IntroducirTarea(&tarea[total]); 
                    EscribirEnFicheroTarea(tarea, total, nombre.c_str());
                   tareaCpp.leerFichero(nombre);
                    total++;
                    break;
            case 2: //fichero = fopen(nombreFichero, "r");
                    //if ( fichero == NULL )
                    //{
                      //printf("No hay tareas guardadas\n");
                    //}
                    //else
                    //{
                        LeerDesdeFicheroTarea(tarea, nombre.c_str());  
                    //}

                    break;
            case 3: 
                    break;
            case 4:  
                    break;
            case 5: break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 5 );
        
   // liberarMemoriaTarea(tarea, total);

}