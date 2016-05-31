#include <stdio.h>
#include <stdlib.h>
#include "Tarea.h"
#include "TareaCpp.h"
#include "SubmenusCpp.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>


using namespace std;

int longitudFichero(string nombreFichero)
{
    ifstream ifs(nombreFichero.c_str());
    int num_lineas = 0;
    string frase;

    while (!ifs.eof())
    {
        getline(ifs, frase);

        num_lineas++;
    }

    ifs.close();

    return (num_lineas-1)/2;


}

vector<TareaCpp> leerFichero(string nombreFichero)
{

    TareaCpp *tarea = new TareaCpp[longitudFichero(nombreFichero)];
    int i = 1;
    int numTarea = 0;
    ifstream ifs(nombreFichero.c_str());
    vector<TareaCpp> vectorTarea;

    string frase;
    string dia;
    string mes;
    string anyo;

    while (!ifs.eof())
    {
        getline(ifs, frase);

        if(i%2 == 0)
        {
            tarea[numTarea].setDescp(frase);
            cout << tarea[numTarea].getDescp() << endl;

            vectorTarea.push_back(tarea[numTarea]);
            cout << "-------------------------------------------------------------" << endl;
            
            numTarea++; //cuenta las tareas que haya en el fichero
        }
            
    
        if(i%2 != 0)
        {
            if(frase != "")
            {
                cout << "TAREA ["<< numTarea <<"] " << endl;

                int dia;
                int mes;
                int anyo;
                string fecha;
                string fecha2;
                string fecha3;

                fecha = frase;

                size_t found = fecha.find("/");
                dia = atoi(fecha.substr(0, found).c_str());

                fecha2 = fecha.substr(found+1,8);
                size_t found2 = fecha2.find("/");
                mes = atoi(fecha2.substr(0, found2).c_str());
                
                fecha3 = fecha2.substr(found2+1,fecha2.size());
                size_t found3 = fecha3.find("\n");
                anyo = atoi(fecha3.substr(0, found3).c_str());

                cout << fecha << endl;

                tarea[numTarea].setDia(dia);
                tarea[numTarea].setMes(mes);
                tarea[numTarea].setAnyo(anyo);


            }
            
        }
        
        i++;
    }

    cout << "Seleccione el numero ["<< numTarea <<"] " << "para cancelar y salir" << endl; 
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;

    ifs.close();

    return vectorTarea;


}

void reescribirEnFichero (string nombreFichero,  vector<TareaCpp> t)
{
     ofstream ofs (nombreFichero.c_str(), ofstream::out);

   
        for (unsigned int i=0; i<t.size(); i++)
        {
            ofs << t[i];
        }
        cout << "Cambios gudardados!" << endl;
        cout << endl;
        ofs.close();
}

void modificarTarea(string nombreFichero)
{
    unsigned int resp;
    vector<TareaCpp> tareaArray = leerFichero(nombreFichero);
    do{
        cout << "Seleccione el numero de Tarea: " << endl;
        cin >> resp;
    }while (resp > tareaArray.size());



    if (resp == tareaArray.size())
    {
        return;
    }
    else 
    {
        cout << "Introduzca la nuevo fecha:" << endl;
        int d = 33;
        string dia;
        do{
            cout << "Dia: ";
            cin >> dia;
            d = atoi (dia.substr(0, 2).c_str());
        }while(d > 31);
        tareaArray[resp].setDia(d);
        
        int m = 17;
        string mes;
        do{
            cout << "Mes: ";
            cin >> mes;
            m = atoi (mes.substr(0, 2).c_str());
        }while(m > 12);
        tareaArray[resp].setMes(m);
     
        int a = 10;
        string anyo;
        do{
            cout << "Anyo: ";
            cin >> anyo;
            a = atoi (anyo.substr(0, 2).c_str());
        }while (a < 16);
        tareaArray[resp].setAnyo(a);

        char descp[100];
        cout << "Introduzca la nueva descripcion: " << endl;
        cin.getline(descp, sizeof(descp));  //ESPAZIOK KONTUN HARTZEKO!
        if (cin.getline(descp, sizeof(descp)))
        {
            tareaArray[resp].setDescp(descp);
        }
        

        reescribirEnFichero(nombreFichero, tareaArray);
    }

}

void eliminarTarea(string nombreFichero)
{
    unsigned int resp;
    vector<TareaCpp> tareaArray = leerFichero(nombreFichero);
    vector <TareaCpp> tareaAux;
    do{
        cout << "Seleccione el numero de Tarea: " << endl;
        cin >> resp;
    }while (resp > tareaArray.size());
     

    if (resp == tareaArray.size())
    {
        return;
    }
    else 
    {
        for (unsigned int i=0; i<tareaArray.size(); i++)
        {
            if (i != resp)
            {
                tareaAux.push_back(tareaArray[i]);
            }

        }

        reescribirEnFichero(nombreFichero, tareaAux);          
         

    }

    
}


void SubmenusCpp::menuTarea (string nombre)  //MAIN BEHARREN GERO HAU JARRI BEHAR DA!
//int main()
{
    
    Tarea* tarea = new Tarea();
    //string nombre = "aran"; //HAU GERO KENDU IN BEHAR DA!
    int opcion;
    int total;
    total = 0;

    string x = "Tarea.txt";
    string nombreFichero = nombre + x;
    ifstream ifs (nombreFichero.c_str());

        
    do{
        cout <<"Seleccione la accion a realizar:\n1. Introducir tarea (C)\n2. Ver tareas a realizar (C)\n3. Modificar tarea (C++)\n4. Eliminar tarea (C++)\n5. Atras" << endl;
        cin >> opcion;
    
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
                        modificarTarea(nombreFichero);
                        cout << endl;
                    }
                    else{
                        cout << "No hay ninguna tarea guardada" << endl;
                    }
                       
                    break;
            case 4: if(ifs != NULL) {
                        eliminarTarea(nombreFichero);
                        
                       
                    }
                    else{
                        cout << "No hay ninguna tarea guardada" << endl;
                    } 

                    break;
            case 5: break;
            default: cout << "Numero erroneo. Introduzca de nuevo." << endl; break;
        }

    }while( opcion != 5 );

    //return 0;
}