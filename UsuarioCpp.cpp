#include <iostream>
#include <string>
#include "UsuarioCpp.h"

using namespace std;

UsuarioCpp::UsuarioCpp(string nombre, string contrasenya)
{
	this->nombre = nombre;
	this->contrasenya = contrasenya;
}

UsuarioCpp::UsuarioCpp()
{
	
}

UsuarioCpp::~UsuarioCpp()
{

}

string UsuarioCpp::getNombre() const
{
	return this->nombre;
}

string UsuarioCpp::getContrasenya() const
{
	return this->contrasenya;
}

void UsuarioCpp::setNombre(string nombre)
{
	this->nombre = nombre;
}

void UsuarioCpp::setContrasenya (string contrasenya)
{
	this->contrasenya = contrasenya;
}
