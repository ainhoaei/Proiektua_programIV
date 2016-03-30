#include "menu.h"
#include <stdio.h>

void menua()
{

 	int opc = 0;

 	printf("MENU PRINCIPAL: Seleccione una opcion \n");
    do
    {
    	printf("1. Log int   2. Registrarse   3. Salir\n");
    	scanf("%i",&opc);

    	switch(opc){
    		case 1: printf("opc 1.\n"); break;
    		case 2: printf("opc 1.\n"); break;
    		case 3: printf("Adios!\n"); break;
    		default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
    	}

    } while (opc != 3);

}
