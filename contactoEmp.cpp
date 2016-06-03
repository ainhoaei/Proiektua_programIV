#include "contactosCpp.h"
#include "contactoEmp.h"
#include <iostream>
#include "DBConnector.h"

using namespace std;

contactoEmp::contactoEmp(string nombre, string apellido, int tlf, string empresa, string puesto, string email): contactosCpp(nombre, apellido, tlf, usuario)
{
	this->empresa = empresa;
	this->puesto = puesto;
	this->email= email;

}
contactoEmp::contactoEmp(): contactosCpp()
{

}

contactoEmp::~contactoEmp()
{

}


string contactoEmp::getEmp() const
{
	return this->empresa;
}
string contactoEmp::getPu() const
{
	return this->puesto;
}
string contactoEmp::getEmail() const
{
	return this->email;
}



contactoEmp* contactoEmp::meterContacto(contactoEmp *c, int total, string usuario)
{
	contactosCpp contacto[100];

	contacto->meterContacto(&contacto[total], usuario);

	c->setNombre(contacto->getNombre());
	c->setApellido(contacto->getApellido());
	c->setTlf(contacto->getTlf());
	c->setUsuario(contacto->getUsuario());

		   	
	   	string empresa;
		cout << "Empresa:" << endl;
		cin >> empresa;
		c->empresa = empresa.substr(0,39);
		

		string puesto;
		cout << "Puesto:" << endl;
		cin >> puesto;
		c->puesto = puesto.substr(0,39);

		string email;
		cout <<"Email:" << endl;
		cin >> email;
		c->email = email.substr(0,39);



		return c;
}
