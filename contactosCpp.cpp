#include "contactosCpp.h"
#include "contactosCpp.h"
#include "contactoEmp.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menu.h"
#include "menuLoginCpp.h"
//#include "UsuarioCpp.h"
#include <iostream>
#include <stdio.h>
#include "string.h"
#include <string>
#include <stdlib.h>

#define MAX_LENGTH 40
#define MAX_TLF 30


contactosCpp::contactosCpp(string nombre, string apellido, int num_tlf)
{
	this->nombre=nombre;
	this->apellido=apellido;
	this->num_tlf=num_tlf;

}

contactosCpp::contactosCpp()
{

}

contactosCpp::~contactosCpp()
{

}

int contactosCpp::clear_if_needed (char *str){

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}


contactosCpp* contactosCpp::meterContacto (contactosCpp *c)
{
		cout << "Inserte los siguientes datos: " << endl;
	   	cout << endl;

	    string nombre;
		cout << "Nombre: " << endl;
		cin >> nombre;
		c->nombre = nombre.substr(0, 39);


		string apell;
		cout << "Apellido:" << endl;
		cin >> apell;
		c->apellido = apell.substr(0, 39);

		string telef;
		cout << "Numero de telefono:" << endl;
		cin >> telef;
		c->num_tlf = atoi(telef.substr(0, 8).c_str());

	

		return c;

}



string contactosCpp::getNombre()const
{
	return this->nombre;
}

string contactosCpp::getApellido() const
{
	return this->apellido;
}

int contactosCpp::getTlf() const
{
	return this->num_tlf;
}

void contactosCpp::setNombre(string nombre)
{
	this->nombre= nombre;
}

void contactosCpp::setApellido(string apellido)
{
	this->apellido = apellido;
}

void contactosCpp::setTlf(int tlf)
{
	this->num_tlf= tlf;
}
	
/*
contactosCpp::insertarContacto()
{
	
}

*/
