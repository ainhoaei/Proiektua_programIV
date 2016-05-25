#ifndef _CONTACTOSCPP_H_
#define _CONTACTOSCPP_H

class contactosCpp
{
	protected:

	string nombre;
	string apellido;
	int num_tlf;

	private:

	contactosCpp(string nombre, string apellido, int num_tlf);
	virtual ~contactosCpp();

	string getNombre()const;
	string getApellido() const;
	int getTlf() const;

	virtual insertarContacto()=0;
	virtual modificarContacto()=0;
	virtual eliminarContacto()=0;




};

class contactoEmpresa: public contactosCpp
{
	string empresa;
	string puesto;
};

class contactoConocidos: public contactosCpp
{
	string pueblo;
	int edad;
};

class contactoFavorito: public contactosCpp
{
	string helbidea;
	string ezizena;
};

#endif

