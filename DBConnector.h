#include "sqlite3.h" //IMPORTANTE
#include <iostream>
#include <stdio.h>
#include <string.h>

//TENEMOS CODIGO DE C PERO FUNCIONARÁ IGUAL

class DBConnector {

private:
		sqlite3 *db;
		int num;

public:
	int mostrarUsuarios();

	int eliminarUsuario();

	int insertarUsuario(std::string nombre, std::string contrasenya);

	
	//int insertarContactoCon(std::string nombre, std::string apellido, int tlf, std::string pueblo, int edad);
	
	int insertarContactoEmp(std::string nombre, std::string apellido, int tlf, std::string empresa, std::string puesto, std::string email);
	int mostrarContactoEmp();
	int verContactoEmp();
	int eliminarContactoEmp(int id);


	int insertarContactoFa(std::string nombre, std::string apellido, int tlf, std::string direccion, std::string mote);
	int mostrarContactoFa();
	int verContactoFa();
	int eliminarContactoFa(int id);

	int chequearUsuario (char* nombre, char* contrasenya);
	//int chequearNombre(std::string nombre);
	//int chequearContrasenya(std::string contrasenya);

	DBConnector(std::string dbFile);

	~DBConnector();

	int getNum() const;
	void setNum(int num);
};