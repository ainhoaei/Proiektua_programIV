#ifndef DIARIOCPP_H_
#define DIARIOCPP_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class DiarioCpp
{
	private: 
		string fecha;
		string descp;
	public:
		DiarioCpp();
		DiarioCpp(string fecha, string descp);
		~DiarioCpp();

		string getDescp() const;
		string getFecha() const;
		

		void setFecha(string fecha);
		void setDescp(string descp);


};

ostream& operator<<(ostream& out, const DiarioCpp& d);


#endif