#include "sqlite3.h" //IMPORTANTE
#include "DBConnector.h"
#include "menuPrincipalCpp.h"



int main(void)
{
	//DBConnector dbConnector("test.sqlite"); //INSTANCIA
	
	menuPrincipalCpp menu;

	menu.menuPrinci();

	return 0;
}