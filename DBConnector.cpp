#include "sqlite3.h"
#include "DBConnector.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 100
#define ID 3

int DBConnector::getNum() const
{
	return this->num;
}

void DBConnector::setNum(int num)
{
	this->num = num;
}

int clear_if_neededCT (char *str)
{

    if (str[strlen(str) - 1] != '\n'){
        int c;
        while ((c = getchar()) != EOF && c != '\n');
    }

    return 0;
}

//////////////////////////////USUARIO////////////////////////////

int DBConnector::chequearUsuario(char* nombre, char* contrasenya)
{
	sqlite3_stmt *stmt;
	setNum(0);

	char sql[] = "select nombre, contrasenya from USUARIO";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char nombreBD[100];
	char contrasenyaBD[100];

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(nombreBD, (char *)sqlite3_column_text(stmt, 0));
			strcpy(contrasenyaBD, (char *)sqlite3_column_text(stmt, 1));

			if (strcmp(nombre, nombreBD)==0 && strcmp(contrasenya, contrasenyaBD)==0)
				setNum(5);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	

	return SQLITE_OK;
}


int DBConnector::insertarUsuario(std::string nombre, std::string contrasenya) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into USUARIO (id, nombre, contrasenya) values (NULL, ?, ?)"; //INSERTATZEZUNA ? JARRI
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

	result = sqlite3_bind_text(stmt, 2, contrasenya.c_str(), contrasenya.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into usuario table\n");
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



//////////////////////////////CONTACTOS////////////////////////////

int DBConnector::eliminarContactoEmp(int id, std::string usuario) {
//borra el contenido del ID que hemos seleccionado


    char sql[] = "delete from CONTACTOSEMP where id = ? and usuario = ?";

	sqlite3_stmt *stmt;

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;


//LE ESTAMOS PASANDO LA DIR DEL POINTER: &stmt

	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (DELETE)\n");




	result = sqlite3_bind_int(stmt, 1, id);

	if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, usuario.c_str(), strlen(usuario.c_str()), 0);

		if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

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


int DBConnector::eliminarContactoFa(int id, std::string usuario) {
//borra el contenido del ID que hemos seleccionado


    char sql[] = "delete from CONTACTOSFA where id = ? and usuario = ?";

	sqlite3_stmt *stmt;



	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;


	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	printf("SQL query prepared (DELETE)\n");


	result = sqlite3_bind_int(stmt, 1, id);

	if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, usuario.c_str(), strlen(usuario.c_str()), 0);

		if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

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



int DBConnector::insertarContactoEmp(std::string nombre, std::string apellido, int tlf, std::string empresa, std::string puesto, std::string email, std::string usuario) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into CONTACTOSEMP (id, nombre, apellido, telef, empresa, puesto, email, usuario) values (NULL, ?, ?, ?, ?, ?, ?, ?)"; //INSERTATZEZUNA ? JARRI
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

	result = sqlite3_bind_text(stmt, 2, apellido.c_str(), apellido.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 3, tlf);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, empresa.c_str(), empresa.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 5, puesto.c_str(), puesto.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 6, email.c_str(), email.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 7, usuario.c_str(), usuario.length(), SQLITE_STATIC);
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


int DBConnector::mostrarContactoEmp(std::string usuario) {
//MOSTRAR TODOS LOS USUARIOS QUE TENEMOS EN LA BD
	sqlite3_stmt *stmt;

	

	char sql[] = "select id, nombre, apellido from CONTACTOSEMP where usuario = ?";


	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, usuario.c_str(), strlen(usuario.c_str()), 0);

	if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char nombre[MAX];
	char apellido[MAX];
	int id;

	int i=0;

	printf("\n");
	printf("\n");
	printf("Elige el ID del contacto que desea eliminar:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);  // PARA ENTEROS
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));

			printf("Id: %d\t Nombre: %s\t\t Apellido: %s\n", id, nombre, apellido);

			i=1;
		}
	} while (result == SQLITE_ROW);


	if(i==0)
	{
		printf("No se encuentra ningun contacto\n");
	}


	int salir;
	char str[MAX];

	printf("\n");
	printf("\n");

	printf("[0] Cancelar");
	fgets(str, ID, stdin);
	clear_if_neededCT(str);
	sscanf(str, "%d", &salir);
	

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	if (salir==0)
	{
		return -1;
	}


	return SQLITE_OK;
}

int DBConnector::verContactoEmp(std::string usuario) {
//MOSTRAR TODOS LOS USUARIOS QUE TENEMOS EN LA BD
	sqlite3_stmt *stmt;


	char sql[] = "select nombre, apellido, telef, empresa, puesto, email from CONTACTOSEMP where usuario =?";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, usuario.c_str(), strlen(usuario.c_str()), 0);

	if(result != SQLITE_OK)
	{
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[MAX];
	char apellido[MAX];
	int tlf;
	char empresa[MAX];
	char puesto[MAX];
	char email[MAX];

	int contador=1;
	int i=0;
	printf("\n");
	printf("\n");
	printf("Mostrar contactos de empresa:\n");
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 0));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 1));
			tlf = sqlite3_column_int(stmt, 2);  // PARA ENTEROS
			strcpy(empresa, (char *) sqlite3_column_text(stmt, 3));
			strcpy(puesto, (char *) sqlite3_column_text(stmt, 4));
			strcpy(email, (char *) sqlite3_column_text(stmt, 5));
			


			printf("Contacto [%d] \nNombre: %s\tApellido: %s\tNumero de telefono:%d\nEmpresa:%s\tPuesto:%s\tEmail:%s\n\n\n",contador, nombre, apellido, tlf, empresa, puesto, email);

			i=1;
		}

		contador++;

	} while (result == SQLITE_ROW);

	if(i==0)
	{
		printf("No se encuentra ningun contacto\n");
	}

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


int DBConnector::verContactoFa(std::string usuario) {
//MOSTRAR TODOS LOS USUARIOS QUE TENEMOS EN LA BD
	sqlite3_stmt *stmt;


	char sql[] = "select nombre, apellido, telef, direccion, mote from CONTACTOSFA where usuario = ?";
	//char sql[] = "select id, nombre, apellido from CONTACTOSEMP";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, usuario.c_str(), strlen(usuario.c_str()), 0);

	if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	char nombre[MAX];
	char apellido[MAX];
	int tlf;
	char direccion[MAX];
	char mote[MAX];
	
	int i=0;
	int contador=1;
	printf("\n");
	printf("Mostrar contactos de empresa:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 0));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 1));
			tlf = sqlite3_column_int(stmt, 2);  // PARA ENTEROS
			strcpy(direccion, (char *) sqlite3_column_text(stmt, 3));
			strcpy(mote, (char *) sqlite3_column_text(stmt, 4));
			
			printf("Contacto [%d] \nNombre: %s\tApellido: %s\tNumero de telefono:%d\tDireccion:%s\tMote:%s\n\n\n",contador, nombre, apellido, tlf, direccion, mote);

			i=1;
		}

		contador++;

	} while (result == SQLITE_ROW);

	if(i==0)
	{
		printf("No se encuentra ningun contacto\n");
	}

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

int DBConnector::mostrarContactoFa(std::string usuario) {
//MOSTRAR TODOS LOS USUARIOS QUE TENEMOS EN LA BD
	sqlite3_stmt *stmt;

	

	char sql[] = "select id, nombre, apellido from CONTACTOSFA where usuario = ?";


	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, usuario.c_str(), strlen(usuario.c_str()), 0);

	if(result != SQLITE_OK)
	{
		printf("Error binding parameter(DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	char nombre[MAX];
	char apellido[MAX];
	int id;

	int i=0;

	printf("\n");
	printf("\n");
	printf("Elige el ID del contacto que desea eliminar:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);  // PARA ENTEROS
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));

			printf("Id: %d\t Nombre: %s\t  Apellido: %s\n", id, nombre, apellido);

			i=1;
		}
	} while (result == SQLITE_ROW);


	if(i==0)
	{
		printf("No se encuentra ningun contacto\n");
	}


	int salir;
	char str[MAX];

	printf("\n");
	printf("\n");

	printf("[0] Cancelar");
	fgets(str, ID, stdin);
	clear_if_neededCT(str);
	sscanf(str, "%d", &salir);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	if (salir==0)
	{
		return -1;
	}

	return SQLITE_OK;
}

int DBConnector::insertarContactoFa(std::string nombre, std::string apellido, int tlf, std::string direccion, std::string mote, std::string usuario) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into CONTACTOSFA (id, nombre, apellido, telef, direccion, mote, usuario) values (NULL, ?, ?, ?, ?, ?, ?)"; //INSERTATZEZUNA ? JARRI
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

	result = sqlite3_bind_text(stmt, 2, apellido.c_str(), apellido.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 3, tlf);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, direccion.c_str(), direccion.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 5, mote.c_str(), mote.length(), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 6, usuario.c_str(), usuario.length(), SQLITE_STATIC);
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
	this->num=0;
	int result = sqlite3_open(dbFile.c_str(), &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");

	}
}

DBConnector::~DBConnector() {
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		printf("Error closing database\n");
		printf("%s\n", sqlite3_errmsg(db));
	}	

}


