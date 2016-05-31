#ifndef _CONTACTOEMP_H_
#define _CONTACTOEMP_H

#include "contactosCpp.h"
#include <iostream>

using namespace std;

class contactoEmp: public contactosCpp
{
private:

	string empresa;
	string puesto;
	string email;

public:

	contactoEmp(string nombre, string apellido, int tlf, string empresa, string puesto, string email);
	contactoEmp();
	virtual ~contactoEmp();

	
	virtual contactoEmp* meterContacto(contactoEmp *c, int total);
	
	//void modificarContacto();

	string getEmp() const;
	string getPu() const;
	string getEmail() const;
};

#endif