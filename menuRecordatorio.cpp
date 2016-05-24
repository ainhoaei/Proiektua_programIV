#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "recordatorio.h"
//#include "RecordatorioCpp.h"
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


void eliminarRecordatorio(string nombre)
{

    string dia;
    string mes;
    string anyo;

    cout <<"Escribe FECHA del recordatorio a eliminar(Introduzca los 2 digitos en cada apartado):\nDia: " << endl;
    cin >> dia;

    cout <<"Mes: " << endl;
    cin >> mes;

    cout <<"Anyo: " << endl;
    cin >> anyo;

    string fechaCompleta = mes + "/" + dia + "/" + anyo;
    string file_hdr;

    string nomFichero= nombre + "Recordatorio.txt";
    ifstream ifs(nomFichero.c_str());
 
    while (!ifs.eof())
    {
       
    //GETLINE lee una linea como fgets
    getline(ifs, file_hdr);

    cout << file_hdr << endl;

    }

    ifs.close();


}

int main ()
//menuTarea (string nombre)  //MAIN BEHARREN GERO HAU JARRI BEHAR DA!
{
    
    string nombre = "jon"; //HAU GERO KENDU IN BEHAR DA!
    int opcion;
   //int total;
    //total = 0;

    string x = "Recordatorio.txt";
    string nombreFichero = nombre + x;
     

    avisoRecordatorio(nombre.c_str()); 

    do{
        cout <<"Seleccione la accion a realizar:\n1. Anyadir recordatorio\n2. Eliminar recordatorio (c++)\n3. Atras" << endl;
       cin >> opcion;

       switch(opcion){
            case 1: recordatorio(nombre.c_str());break;
            case 2: eliminarRecordatorio(nombre);break;
            case 3: break;
            default: cout<< "Numero erroneo. Introduzca de nuevo.\n" << endl;break;
        }

    }while( opcion != 3 );

    return 0;

}