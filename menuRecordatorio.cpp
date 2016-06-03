#include <string>
#include "recordatorio.h"
#include "SubmenusCpp.h"
#include <iostream>
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
            

             if(fechaCompleta == file_hdr.substr(0,8)){
                    
                    if(elegir==eliminar){

                        eliminarString = file_hdr;
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

void SubmenusCpp::menuRecordatorio (string nombre)
{
    int opcion = 0;

    string x = "Recordatorio.txt";
    string nombreFichero = nombre + x;
     

    avisoRecordatorio(nombre.c_str()); 

    do{
        cout <<"Seleccione la accion a realizar:\n1. Anyadir recordatorio (C)\n2. Eliminar recordatorio (c++)\n3. Atras" << endl;
       cin >> opcion;
       ifstream ifs (nombreFichero.c_str());

       switch(opcion){
            case 1: recordatorio(nombre.c_str());break;
            case 2: if(ifs == NULL) {
                     cout <<"No hay notas guardadas\n"<<endl;
                    }
                    else
                    {
                        eliminarRecordatorio(nombre);
                    }
                    break;
            case 3: break;
            default: cout<< "Numero erroneo. Introduzca de nuevo.\n" << endl;break;
        }

    }while( opcion != 3 );


}