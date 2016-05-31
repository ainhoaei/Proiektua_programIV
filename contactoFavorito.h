#ifndef _CONTACTOFAVORITO_H_
#define _CONTACTOFAVORITO_H

#include "contactosCpp.h"
#include <iostream>

using namespace std;

class contactoFavorito: public contactosCpp
{
private:

	string direccion;
	string mote;


public:

	contactoFavorito(string nombre, string apellido, int tlf, string direccion, string mote);
	contactoFavorito();
	virtual ~contactoFavorito();

	
	virtual contactoFavorito* meterContacto(contactoFavorito *f, int total);


	string getDir() const;
	string getMote() const;

};

#endif