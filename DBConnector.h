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

	int chequearUsuario(char* nombre, char* contrasenya);

	DBConnector(std::string dbFile);

	~DBConnector();
};