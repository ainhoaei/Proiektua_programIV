#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "diario.h"
#include "diarioCpp.h"
#include <iostream>
#include <fstream>

using namespace std;


int numNotas(string nombreFichero){

    ifstream ifs(nombreFichero.c_str());
    string str;
    int num=0;

    while (!ifs.eof())
    {
        getline(ifs, str);
       num++;     
    
    }

      ifs.close();

      return num/2;

}

void leerNota(string nombreFichero){

DiarioCpp *diario = new DiarioCpp[numNotas(nombreFichero)];

 ifstream ifs(nombreFichero.c_str());
    string str;
    int num=0;

    while (!ifs.eof())
    {
        getline(ifs, str);

        if(str.substr(0,1) != "=" && str.substr(0,1) != "")
        {

            diario[num].setFecha(str.substr(0, 8));
            diario[num].setDescp(str.substr(10));

           cout << "[" << num << "] " << diario[num] << endl;
            
            num++;
        }
            
    
     }

     cout << "[" << num  << "]  Cancelar" << endl;

      ifs.close();

 }

 void reescribirNotas(string nombreFichero, int opc){

DiarioCpp *diario = new DiarioCpp[numNotas(nombreFichero)];

 ifstream ifs(nombreFichero.c_str());
    string str;
    int num=0;
    int cont=0;

    while (!ifs.eof())
    {
        getline(ifs, str);

        if(str.substr(0,1) != "=" && str.substr(0,1) != "")
        {
            if (opc!=num){
                diario[cont].setFecha(str.substr(0, 8));
                diario[cont].setDescp(str.substr(10));      

                //cout << cont << diario[cont] << endl;   
                cont++;  
            }
            
            
            num++;
        }
            
    
     }

      ifs.close();



      int e = num-1;
       ofstream ofs(nombreFichero.c_str(),  ofstream::out);

            for (int i = 0; i < e; i++){
                ofs << "========================================"<<endl;
                ofs << diario[i];
                //cout<<i<<endl;
            }

        ofs.close();


 }

void eliminarNota(string nombreFichero){

int opc;
    do{
        cout << "Elige la nota que quieras eliminar: " << endl;

        leerNota(nombreFichero);
        cin >> opc;

        if(opc==numNotas(nombreFichero))break;

    }while(opc > numNotas(nombreFichero) || opc<0);

    //cout << numNotas(nombreFichero)<<endl;
    if(opc < numNotas(nombreFichero))reescribirNotas(nombreFichero, opc);



}


int main(){
	
	

	string nombre = "jon"; //HAU GERO KENDU IN BEHAR DA!

    string x = "Nota.txt";
    string nombreFichero = nombre + x;
    
    //FILE *fichero;

	int opcion;
    do{
        cout << "Seleccione la accion a realizar:\n1. Apuntar nota(C)\n2. ver notas(C)\n3. Ver notas de dia especifico(C)\n4. Eliminar nota (C++)\n5. Atras \n" << endl;
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
            case 4: eliminarNota(nombreFichero);break;
            case 5: break;
            default: cout <<"Numero erroneo. Introduzca de nuevo.\n"<<endl; break;
        }

    }while( opcion != 5 );



    return 0;

}