#ifndef USUARIOCPP_H_
#define USUARIOCPP_H_

#include <string>

using namespace std;


class UsuarioCpp
{
private:
	string nombre;
	string contrasenya;

public:
	UsuarioCpp(string nombre, string contrasenya);
	UsuarioCpp();
	~UsuarioCpp();

	string getNombre() const;
	string getContrasenya() const;

	void setNombre(string nombre);
	void setContrasenya (string contrasenya);
};


#endif