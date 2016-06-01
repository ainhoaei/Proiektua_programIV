#include "contactosCpp.h"
#include "contactoFavorito.h"
#include <iostream>
#include "DBConnector.h"

using namespace std;

contactoFavorito::contactoFavorito(string nombre, string apellido, int tlf, string direccion, string mote): contactosCpp(nombre, apellido, tlf)
{
	this->direccion = direccion;
	this->mote = mote;
	
}
contactoFavorito::contactoFavorito(): contactosCpp()
{

}

contactoFavorito::~contactoFavorito()
{

}


string contactoFavorito::getDir() const
{
	return this->direccion;
}
string contactoFavorito::getMote() const
{
	return this->mote;
}


contactoFavorito* contactoFavorito::meterContacto(contactoFavorito *f, int total)
{
	contactosCpp contacto[100];

	contacto->meterContacto(&contacto[total]);

	f->setNombre(contacto->getNombre());
	f->setApellido(contacto->getApellido());
	f->setTlf(contacto->getTlf());
		   	
	   	string direccion;
		cout << "Direccion:" << endl;
		cin >> direccion;
		f->direccion = direccion.substr(0,69);
		

		string mote;
		cout << "Mote:" << endl;
		cin >> mote;
		f->mote = mote.substr(0,39);

		return f;
}