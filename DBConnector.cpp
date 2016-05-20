#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

int DBConnector::mostrarUsuarios() {
//MOSTRAR TODOS LOS USUARIOS QUE TENEMOS EN LA BD
	sqlite3_stmt *stmt;

	char sql[] = "select nombre, contrasenya from USUARIO";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[100];
	char contrasenya[100];

	printf("\n");
	printf("\n");
	printf("Mostrando usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			//id = sqlite3_column_int(stmt, 0);   PARA ENTEROS
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 0));
			strcpy(contrasenya, (char *) sqlite3_column_text(stmt, 1));
			printf("Nombre: %s contrasenya: %s\n", nombre, contrasenya);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int DBConnector::eliminarUsuario() {
//borra TODO el contenido

	sqlite3_stmt *stmt;

	char sql[] = "delete from USUARIO";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
//LE ESTAMOS PASANDO LA DIR DEL POINTER: &stmt

	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");

	result = sqlite3_step(stmt);
//PARA EJECUTAR LA CONSULTA

	if (result != SQLITE_DONE) {
		printf("Error deleting data\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (DELETE)\n");

	return SQLITE_OK;
}



/*int DBConnector::insertarNombreUsuario(std::string nombre, std::string contrasenya) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into USUARIO (nombre, contrasenya) values (?, ?)";
	//values (NULL, ?) --> entero y char*

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre.c_str(), nombre.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}*/


int DBConnector::insertarUsuario(std::string nombre, std::string contrasenya) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into USUARIO (nombre, contrasenya) values (?, ?)"; //INSERTATZEZUNA ? JARRI
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	/*INT BADA!
	result = sqlite3_bind_int(stmt, 1, id);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}*/

	result = sqlite3_bind_text(stmt, 1, nombre.c_str(), nombre.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, contrasenya.c_str(), contrasenya.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

DBConnector::DBConnector(std::string dbFile) {
	this->db = NULL;
	int result = sqlite3_open("test.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");

	}
}

DBConnector::~DBConnector() {
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		printf("%s\n", sqlite3_errmsg(db));
	}	

	//delete[] db; 
}
