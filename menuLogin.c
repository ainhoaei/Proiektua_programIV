#include "menu.h"
#include <stdio.h>

//MENU LOGIN
void menua()
{




    //LOGIN-a EGITEA FALTA DA HEMEN!!!!






	int opc = 0;
	char c;

    printf("\n");
    do
    {
        printf("MENU LOG IN: Seleccione una opcion \n");
    	printf("1. Diario/Agenda\n2. Tarea a realizar\n3. Contactos\n4. Recordatorios\n5. Salir de mi agenda\n");
    	scanf("%i",&opc);

    	switch(opc){
    		case 1: diario(); break;
    		case 2: tarea(); break;
    		case 3: contactos(); break;
    		case 4: recordatorios(); break;
    		case 5: printf("Has salido de tu agenda personal.\n");
    				printf("\n");
    				menuPrinci();
    				break;
    		default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
    	}

    } while (opc != 5);
}


//MENU DIARIO
int diario(){
    int opcion;
    do{
        printf("Seleccione la accion a realizar:\n1. Apuntar nota\n2. Ver notas\n3. Eliminar nota\n4. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: printf("opc 1.\n"); break;
            case 2: printf("opc 2.\n"); break;
            case 3: printf("opc 3\n"); break;
            case 4: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 4 );

    return 0;
}


//MENU TAREAS
int tarea(){
    int opcion;
    do{
        printf("Seleccione la accion a realizar:\n1. Ver tareas a realizar\n2. Modificar tarea\n3. Eliminar tarea\n4. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: printf("opc 1.\n"); break;
            case 2: printf("opc 2.\n"); break;
            case 3: printf("opc 3\n"); break;
            case 4: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 4 );

    return 0;
}


//MENU CONTACTOS
int contactos(){
    int opcion;
    do{
        printf("Seleccione la accion a realizar:\n1. Anyadir contactos\n2. Ver contactos\n3. Eliminar contacto\n4. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: printf("opc 1.\n"); break;
            case 2: printf("opc 2.\n"); break;
            case 3: printf("opc 3\n"); break;
            case 4: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 4 );

    return 0;
}


//MENU RECORDATORIOS
int recordatorios(){
    int opcion;
    do{
        printf("Seleccione la accion a realizar:\n1. Anyadir recordatorio\n2. Eliminar recordatorio\n3. Atras \n");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: printf("opc 1.\n"); break;
            case 2: printf("opc 2.\n"); break;
            case 3: printf("\n"); break;
            default: printf("Numero erroneo. Introduzca de nuevo.\n"); break;
        }

    }while( opcion != 3 );

    return 0;
}
