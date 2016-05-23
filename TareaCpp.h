#ifndef TAREACPP_H_
#define TAREACPP_H_

#include "Tarea.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class TareaCpp
{
	public:
		void modificarTarea();
		void eliminarTarea();
		Tarea* leerFichero(std::string nombre);

		//friend std::istream& operator>>(std::istream &in, Tarea &t);
};




#endif