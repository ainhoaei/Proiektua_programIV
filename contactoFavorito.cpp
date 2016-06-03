#include "contactosCpp.h"
#include "contactoFavorito.h"
#include <iostream>
#include "DBConnector.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

contactoFavorito::contactoFavorito(string nombre, string apellido, int tlf, string direccion, string mote): contactosCpp(nombre, apellido, tlf, usuario)
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


contactoFavorito* contactoFavorito::meterContacto(contactoFavorito *f, int total, string usuario)
{
	contactosCpp contacto[100];

	contacto->meterContacto(&contacto[total], usuario);

	f->setNombre(contacto->getNombre());
	f->setApellido(contacto->getApellido());
	f->setTlf(contacto->getTlf());
	f->setUsuario(contacto->getUsuario());

	char dir[100];
    cout << "Direccion: " << endl;
    cin.getline(dir, sizeof(dir));  //ESPAZIOK KONTUN HARTZEKO!
    if(cin.getline(dir, sizeof(dir)))
    {
    	f->direccion =(char *)malloc((strlen(dir) + 1) * sizeof(char)); 	
    }
    

    string direccion(dir);

    f->direccion = direccion;



	string mote;
	cout << "Mote:" << endl;
	cin >> mote;
	f->mote = mote.substr(0,39);

	return f;
}