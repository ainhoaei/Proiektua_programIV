#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

int main() {
	DBConnector dbConnector("test.sqlite"); //INSTANCIA

	/*int result = dbConnector.eliminarUsuario();
	//BORRAR TODO EL CONTENIDO DE LA BD
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		return result;
	}*/

	int result = dbConnector.insertarUsuario("Jon", "kk");
	if (result != SQLITE_OK) {
		printf("Error inserting new data with id: 200. Already exists\n");
		return result;
	}

	result = dbConnector.mostrarUsuarios();
	if (result != SQLITE_OK) {
		printf("Error getting all countries\n");
		return result;
	}

	return 0;
}
