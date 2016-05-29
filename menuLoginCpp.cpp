#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "menuLoginCpp.h"
#include <iostream>
#include "SubmenusCpp.h"

using namespace std;



//MENU LOGIN
int menuLoginCpp::menuaCpp(string nombre)
{

    setvbuf (stdout, 0, _IONBF, 0);

    SubmenusCpp menu;

    int opc = 0;

    cout << endl;
    do
    {
        cout << "MENU LOG IN: Seleccione una opcion" << endl;
        cout << "1. Diario/Agenda\n2. Tarea a realizar\n3. Contactos\n4. Recordatorios\n5. Salir de mi agenda" << endl;
        cin >> opc;
        
        
        switch(opc){
            case 1:// menuDiario(nombre); break;
            case 2: menu.menuTarea(nombre);  break;
            case 3: //menuContacto(nombre); break;
            case 4: //menuRecordt(nombre); break;
            case 5: cout << "Has salido de tu agenda personal" << endl;
                    cout << endl;
                    break;
            default: cout << "Numero erroneo. Introduzca de nuevo."<< endl; break;
        }
        
    } while (opc != 5);

    return 0;
}