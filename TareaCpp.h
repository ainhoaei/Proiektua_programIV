#ifndef TAREACPP_H_
#define TAREACPP_H_

#include "Tarea.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class TareaCpp
{
	private: 
		int dia;
		int mes;
		int anyo;
		std::string descp;
	public:
		TareaCpp();
		TareaCpp(int dia, int mes, int anyo, std::string descp);
		~TareaCpp();

		std::string getDescp() const;
		int getDia() const;
		int getMes() const;
		int getAnyo() const;

		void setDia(int dia);
		void setMes(int mes);
		void setAnyo(int anyo);
		void setDescp(std::string descp);


};

std::istream& operator>>(std::istream& in, TareaCpp& t);
std::ostream& operator<<(std::ostream& out, const TareaCpp& t);


#endif