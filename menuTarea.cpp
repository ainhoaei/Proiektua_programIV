#include <stdio.h>
#include <stdlib.h>
#include "Tarea.h"
#include "TareaCpp.h"
#include <iostream>
#include <string>
#include "string.h"
#include <vector>
#include <fstream>


using namespace std;


vector<TareaCpp> leerFichero(string nombre)
{
    string x = "Tarea.txt";
    string nombreFichero = nombre + x;
    vector<TareaCpp> vectorTarea;
    TareaCpp tarea;
    int i = 0;
    ifstream ifs(nombreFichero.c_str());
    string frase;

    while (ifs >> tarea){

        cout << "TAREA ["<< i <<"] " << endl;
        vectorTarea.push_back(tarea);
        i++;
        cout << "-------------------------------------------------------------"<< endl; 

    }

    cout << "Seleccione el numero ["<< i <<"] " << "para cancelar y salir" << endl; 
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;

    ifs.close();

    return vectorTarea;

}

void reescribirEnFichero (string nombre,  vector<TareaCpp> t)
{
    string x = "Tarea.txt";
    string nombreFichero = nombre + x;

    ofstream ofs (nombreFichero.c_str(), ofstream::out); 

    
    for (unsigned int i=0; i<t.size(); i++)
    {
        ofs << t[i] << endl;
    }
    cout << "Cambios gudardados!" << endl;
    cout << endl;

    ofs.close();



   
}

void modificarTarea(string nombre)
{
    unsigned int resp;
    vector<TareaCpp> tareaArray = leerFichero(nombre);
    do{
        cout << "Seleccione el numero de Tarea: " << endl;
        cin >> resp;
    }while (resp > tareaArray.size());



     if (resp == tareaArray.size()){
        return;
    }
    else {
        cout << "Introduzca la nuevo fecha:" << endl;
        int d = 33;
        do{
            cout << "Dia: ";
            cin >> d;
        }while(d > 31);
        tareaArray[resp].setDia(d);
        
        int m = 17;
        do{
            cout << "Mes: ";
            cin >> m;

        }while(m > 12);
        tareaArray[resp].setMes(m);
     
        int a = 10;
        do{
            cout << "Anyo: ";
            cin >> a;

        }while (a < 16);
        tareaArray[resp].setAnyo(a);

        string descp;
        cout << "Introduzca la nueva descripcion: " << endl;
        cin >> descp;
        tareaArray[resp].setDescp(descp);



        reescribirEnFichero(nombre, tareaArray);
    }

}

void eliminarTarea(string nombre)
{
    unsigned int resp;
    vector<TareaCpp> tareaArray = leerFichero(nombre);
    vector <TareaCpp> tareaAux;
    do{
        cout << "Seleccione el numero de Tarea: " << endl;
        cin >> resp;
    }while (resp > tareaArray.size());

    string x = "Tarea.txt";
        string nombreFichero = nombre + x;
     if( remove( nombreFichero.c_str() ) != 0 )
               cout << "Error deleting file" << endl;

    if (resp == tareaArray.size()){
        return;
    }
    else {
        for (unsigned int i=0; i<tareaArray.size(); i++)
        {
            if (i != resp)
            {
                tareaAux.push_back(tareaArray[i]);
            }

        }

        reescribirEnFichero(nombre, tareaAux);          
         

    }

    
}


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
        cout <<"Seleccione la accion a realizar:\n1. Introducir tarea (C)\n2. Ver tareas a realizar (C)\n3. Modificar tarea (C++)\n4. Eliminar tarea (C++)\n5. Atras" << endl;
       cin >> opcion;
        ifstream ifs (nombreFichero.c_str());
        switch(opcion){
            case 1: IntroducirTarea(&tarea[total]); 
                    EscribirEnFicheroTarea(tarea, total, nombre.c_str());
                    
                    total++;
                    break;
            case 2: if(ifs != NULL) {
                        LeerDesdeFicheroTarea(tarea, nombre.c_str());  
                    }
                    else{
                        cout << "No hay ninguna tarea guardada" << endl;
                    }
                    break;

            case 3: if(ifs != NULL) {
                        modificarTarea(nombre);
                        cout << endl;
                    }
                    else{
                        cout << "No hay ninguna tarea guardada" << endl;
                    }
                       
                    break;
            case 4: if(ifs != NULL) {
                        eliminarTarea(nombre);
                        
                       
                    }
                    else{
                        cout << "No hay ninguna tarea guardada" << endl;
                    } 

                    break;
            case 5: break;
            default: cout << "Numero erroneo. Introduzca de nuevo." << endl; break;
        }

    }while( opcion != 5 );

    return 0;
}