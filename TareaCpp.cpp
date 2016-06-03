#include <string>
#include "Tarea.h"
#include "TareaCpp.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;


TareaCpp::TareaCpp()
{

}

TareaCpp::TareaCpp(int dia, int mes, int anyo, std::string descp)
{
	this->dia = dia;
	this->mes = mes;
	this->anyo = anyo;
	this->descp = descp;
}

TareaCpp::~TareaCpp()
{
	
}

void TareaCpp::setDia(int dia)
{
	this->dia = dia;
}
void TareaCpp::setMes(int mes)
{
	this->mes = mes;
}
void TareaCpp::setAnyo(int anyo)
{
	this->anyo = anyo;
}
void TareaCpp::setDescp(std::string descp)
{
	this->descp = descp;
}

string TareaCpp::getDescp() const
{
	return this->descp;
}

int TareaCpp::getDia() const
{
	return this->dia;
}
int TareaCpp::getMes() const
{
	return this->mes;
}
int TareaCpp::getAnyo() const
{
	return this->anyo;
}

ostream& operator<<(std::ostream& out, const TareaCpp& t)
{
	out << t.getDia() <<"/"<< t.getMes() << "/" << t.getAnyo() << endl;
	out << t.getDescp() << endl;


	return out;
}

