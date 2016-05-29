#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "diario.h"
#include "diarioCpp.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	

	string nombre = "jon"; //HAU GERO KENDU IN BEHAR DA!

    string x = "Nota.txt";
    string nombreFichero = nombre + x;
    
    //FILE *fichero;

	int opcion;
    do{
        cout << "Seleccione la accion a realizar:\n1. Apuntar nota\n2. ver notas\n3. Ver notas de dia especifico\n4. Eliminar nota (C++)\n5. Atras \n" << endl;
        cin >> opcion;
        ifstream ifs (nombreFichero.c_str());

        switch(opcion){
            case 1: apuntarNota(nombre.c_str());break;
            case 2: if(ifs == NULL) {
                     cout <<"No hay notas guardadas\n"<<endl;
                    }
                    else
                    {
                        leer(nombre.c_str());  
                    }
                    break;
            case 3: verEspc(nombre.c_str());break;
            case 4: break;
            case 5: break;
            default: cout <<"Numero erroneo. Introduzca de nuevo.\n"<<endl; break;
        }

    }while( opcion != 5 );



    return 0;

}