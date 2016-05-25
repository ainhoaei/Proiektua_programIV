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


istream& operator>>(istream &in, TareaCpp &t)
{
	int dia;
	int mes;
	int anyo;
	string fecha;
	string fecha2;
	string fecha3;
	string descp;

	in >> fecha;
	in >> descp;

	cout << fecha << endl;

	size_t found = fecha.find("/");
	dia = atoi(fecha.substr(0, found).c_str());

	fecha2 = fecha.substr(found+1,8);
	size_t found2 = fecha2.find("/");
	mes = atoi(fecha2.substr(0, found2).c_str());
	
	fecha3 = fecha2.substr(found2+1,fecha2.size());
	size_t found3 = fecha3.find("\n");
	anyo = atoi(fecha3.substr(0, found3).c_str());

	cout << descp << endl;

	t.setDia(dia);
	t.setMes(mes);
	t.setAnyo(anyo);
	t.setDescp(descp);



	return in;
}




ostream& operator<<(std::ostream& out, const TareaCpp& t)
{
	out << t.getDia() <<"/"<< t.getMes() << "/" << t.getAnyo() << endl;
	out << t.getDescp();

	return out;
}

