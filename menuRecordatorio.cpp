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
    
    int lista=0;
    int total=0;

    //SOLO MOSTRAR DEPENDIENDO DE LA FECHA PARA ELEGIR
    while (!ifs.eof())
    {
       
    //GETLINE lee una linea como fgets
    getline(ifs, file_hdr);
    ++total;

     if(fechaCompleta == file_hdr.substr(0,8)){

            cout << "["<< lista <<"] " << file_hdr << endl;
            ++lista;
        }

    }
    ifs.close();

    cout << "["<< lista <<"] " << "Cancelar" << endl;


   int eliminar;
   int elegir=0;
   string eliminarString;
   string* todoRecord = new string[total];
   //PASAMOS A UN ARRAY DE STRINGS PARA QUITAR LA ELEGIDA
    do{
         
        cout << "Seleccione el recordatorio que quiera eliminar" << endl;
        cin >> eliminar;

        if(eliminar< lista){

            ifstream ifs(nomFichero.c_str());
            int cont=0;
            while (!ifs.eof())
            {
            getline(ifs, file_hdr);
            
            todoRecord[cont]=file_hdr;
           // cout << todoRecord[cont] <<endl; //fuera
            //cout << "lenengo arraien ondo gordetzeu" <<elegir<<cont<<eliminar<<fechaCompleta<<file_hdr.substr(0,8)<<endl;//fuera
            

             if(fechaCompleta == file_hdr.substr(0,8)){
                    
                    if(elegir==eliminar){

                        eliminarString = file_hdr;
                        //cout << eliminarString <<endl;//fuera
                        //cout << "hau re ondo" << endl;//fuera
                        

                    }
                    elegir++;
                }
            cont++;

            }
            ifs.close();

            string* finRecord = new string[total-1];

            int e=0;
            for(int i=0; i<cont;i++){

                if(todoRecord[i]!=eliminarString && todoRecord[i]!= ""){

                    finRecord[e]=todoRecord[i];
                    
                    // cout << finRecord[e] <<endl;
                    //cout << "BESTE ARRAIA" <<endl;
                    e++;


                }
            }

            //ESCRIBIR LO NUEVO
            ofstream ofs(nomFichero.c_str(),  ofstream::out);

            for (int i = 0; i < e; i++)
                ofs << finRecord[i] << endl;

            ofs.close();

            delete finRecord;

            cout << "TU OPCION HA SIDO ELIMINADA ;)\n" << endl;

        break;
        }
    }while(eliminar != lista);


    
    delete todoRecord;
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
        cout <<"Seleccione la accion a realizar:\n1. Anyadir recordatorio (C)\n2. Eliminar recordatorio (c++)\n3. Atras" << endl;
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