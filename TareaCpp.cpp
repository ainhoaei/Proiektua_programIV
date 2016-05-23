#include <string>
#include "Tarea.h"
#include "TareaCpp.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;


void TareaCpp::modificarTarea()
{

}

void TareaCpp::eliminarTarea()
{

}



/*istream& operator>>(istream &in, Tarea &t)
{
	char c; //para leer y descartar caracteres
	in >> t.descp >> c;
	return in;
}
*/


Tarea* TareaCpp::leerFichero(string nombre)
{
	string x = "Tarea.txt";
	string nombreFichero = nombre + x;

	Tarea *tarea = new Tarea[100];
	int i = 1;
	int numTarea = 0;
	ifstream ifs(nombreFichero.c_str());

	string frase;
	string dia;
	string mes;
	string anyo;

	while (!ifs.eof())
	{
		getline(ifs, frase);

		if(i%2 == 0)
		{
			tarea[i].descp = new char[frase.size()+1];
			copy(frase.begin(), frase.end(), tarea[i].descp);
			tarea[i].descp[frase.size()] = '\0';

			cout << tarea[i].descp << '\n';
			
			cout << "--------------------------------" << endl;
			
			numTarea++; //cuenta las tareas que haya en el fichero
		}
			
	
		if(i%2 != 0)
		{
			if(frase != "")
			{
				cout << "TAREA " << numTarea << ":" << endl;

				dia = frase.substr(0, 2);
				tarea[i].fecha.dia = atoi(dia.c_str());

				mes = frase.substr(3,5);
				tarea[i].fecha.mes = atoi(mes.c_str());
				
				anyo = frase.substr(6,8);
				tarea[i].fecha.anyo = atoi(anyo.c_str());

				cout << tarea[i].fecha.dia << "/" << tarea[i].fecha.mes << "/" << tarea[i].fecha.anyo << endl;

			}
			
		}
		
		i++;
	}

	ifs.close();

	return tarea;

}
