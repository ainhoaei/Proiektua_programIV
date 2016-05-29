#include <string>
#include "diarioCpp.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;


DiarioCpp::DiarioCpp()
{

}

DiarioCpp::DiarioCpp(string fecha, string descp)
{
	this->fecha = fecha;
	this->descp = descp;
}

DiarioCpp::~DiarioCpp()
{
	
}

void DiarioCpp::setFecha(string fecha)
{
	this->fecha = fecha;
}

void DiarioCpp::setDescp(string descp)
{
	this->descp = descp;
}

string DiarioCpp::getDescp() const
{
	return descp;
}

string DiarioCpp::getFecha() const
{
	return fecha;
}



ostream& operator<<(std::ostream& out, const DiarioCpp& d)
{
	out << d.getFecha() << ": " <<d.getDescp() << endl;

	return out;
}

