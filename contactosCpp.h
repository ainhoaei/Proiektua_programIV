#ifndef _CONTACTOSCPP_H_
#define _CONTACTOSCPP_H_

#include <string>

using namespace std;

class contactosCpp
{
	

	string nombre;
	string apellido;
	int num_tlf;

	public:

	contactosCpp(string nombre, string apellido, int num_tlf);
	contactosCpp();
	virtual ~contactosCpp();

	string getNombre()const;
	string getApellido() const;
	int getTlf() const;

	void setNombre(string nombre);
	void setApellido(string apellido);
	void setTlf(int tlf);

	virtual int clear_if_needed (char *str);

	virtual contactosCpp* meterContacto(contactosCpp *c);
	//virtual modificarContacto()=0;
	//virtual eliminarContacto()=0;


};


/*
class contactoConocidos: public contactosCpp
{
	string pueblo;
	int edad;
};

class contactoFavorito: public contactosCpp
{
	string direccion;
	string mote;
};

*/
#endif

