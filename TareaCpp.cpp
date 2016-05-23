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
		if(i%2 == 0){
			getline(ifs, frase);
			tarea[i].descp = new char[frase.size()+1];
			copy(frase.begin(), frase.end(), tarea[i].descp);
			tarea[i].descp[frase.size()] = '\0';

			cout << tarea[i].descp << '\n';
			cout << "------------------------------" << endl;
			numTarea++;
		}
			
			

		if(i%2 != 0){
			getline(ifs, frase);

			if(frase != "")
			{
				cout << "TAREA " << numTarea << ":" << endl;

				dia = frase.substr(0, 2);
				tarea[i].fecha.dia = atoi(dia.c_str());

				mes = frase.substr(3,5);
				tarea[i].fecha.mes = atoi(mes.c_str());
				
				anyo = frase.substr(6,8);
				tarea[i].fecha.anyo = atoi(anyo.c_str());

				cout << tarea[i].fecha.dia << '\n';
				cout << dia << " y " << frase.substr(0, 1) << '\n';
				cout << tarea[i].fecha.mes << '\n';
				cout << mes << " y " << frase.substr(3,4) << '\n';
				cout << tarea[i].fecha.anyo << '\n';
				cout << anyo << " y " << frase.substr(6,7) << '\n';
				
				//cout << frase << '\n';
			}
			
		}
			
		

		i++;
	}
	/*while (!ifs.eof())
	{
		if(i%2 == 0)
			ifs >> tarea[i].descp;
			

		if(i%2 != 0)
			getline(ifs, frase);
			

		//cout << tarea[i].fecha << " " << tarea[i].descp << endl;
		i++;
	}
	*/
	ifs.close();

	return tarea;

}
