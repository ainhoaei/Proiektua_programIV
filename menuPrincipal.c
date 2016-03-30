#include "menu.h"
#include <stdio.h>


//MENU PRINCIPAL
int menuPrinci()
{

 	int opc = 0;
	
    do
    {
        printf("MENU PRINCIPAL: Seleccione una opcion \n");
    	printf("1. Log in   2. Registrarse   3. Salir\n");
    	scanf("%i",&opc);

    	switch(opc){
    		case 1: menua(); break;
    		case 2: printf("opc 2.\n"); break;
    		case 3: printf("Adios!\n"); break;
    		default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
    	}

    } while (opc != 3);

    return 0;
}
