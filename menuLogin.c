#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"


//MENU LOGIN
int menua(char *nombre)
{

    setvbuf (stdout, 0, _IONBF, 0);

    int opc = 0;
    char c;

    printf("\n");
    do
    {
        printf("MENU LOG IN: Seleccione una opcion \n");
        printf("1. Diario/Agenda\n2. Tarea a realizar\n3. Contactos\n4. Recordatorios\n5. Salir de mi agenda\n");
        scanf("%i",&opc);

        switch(opc){
            case 1: menuDiario(nombre); break;
            case 2: menuTarea(nombre);  break;
            case 3: menuContacto(nombre); break;
            case 4: menuRecordt(nombre); break;
            case 5: printf("Has salido de tu agenda personal.\n");
                    printf("\n");
                    break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    } while (opc != 5);

    return 0;
}