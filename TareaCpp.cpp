#include <string>
#include "Tarea.h"
#include "TareaCpp.h"
#include <iostream>
#include <vector>

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
	in >> t.fecha.dia >> c >> t.fecha.mes >> c >> t.fecha.anyo >> c;
	return in;
}

/*istream& operator>>(istream &in, Tarea &t)
{
	char c; //para leer y descartar caracteres
	in >> t.descp >> c;
	return in;
}


Tarea* TareaCpp::leerFichero(string nombre)
{
	string x = "Tarea.txt";
	string nombreFichero = nombre + x;

	Tarea* tarea;
	int i = 0;
	int aux = 0;

	ifstream ifs(nombreFichero);
	while (!ifs.eof())
	{
		if(i % 2 != 0)
			ifs >> tarea[i].fecha;
			

		if(i % 2 == 0)
			ifs >> tarea[i].descp;

		//cout << tarea[i].fecha << " " << tarea[i].descp << endl;
		i++;
	}

	ifs.close();

	return tarea;

}
*/