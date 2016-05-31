#include "sqlite3.h" //IMPORTANTE
#include <iostream>
#include <stdio.h>
#include <string.h>

//TENEMOS CODIGO DE C PERO FUNCIONARÁ IGUAL

class DBConnector {

private:
		sqlite3 *db;

public:
	int mostrarUsuarios();

	int eliminarUsuario();

	int insertarUsuario(std::string nombre, std::string contrasenya);

	int insertarContactoEmp(std::string nombre, std::string apellido, int tlf, std::string empresa, std::string puesto, std::string email);
	//int insertarContactoCon(std::string nombre, std::string apellido, int tlf, std::string pueblo, int edad);
	int insertarContactoFa(std::string nombre, std::string apellido, int tlf, std::string direccion, std::string mote);


	int mostrarContactoEmp();
	int verContactoEmp();
	int eliminarContactoEmp();

	int chequearUsuario(const char* nombre, char* contrasenya);

	DBConnector(std::string dbFile);

	~DBConnector();
};