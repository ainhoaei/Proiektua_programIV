#ifndef TAREA_H_
#define TAREA_H_

#define MAX_LENGTH_D_M  3  // MAXIMO, DOS DIGITOS EN DIA Y MES
#define MAX_LENGTH_DESCP 50  //MAXIMO, 50 CARACTERES EN LA DESCRIPCION DE CADA TAREA
#define MAX_LENGTH_NUM 3  //MAXIMO, TRES DIGITOS PARA EL CODIGO DE TAREA

#define MAX_TAREAS 10 //POR CADA FECHA, EL MAXIMO DE TAREAS SERA 10


typedef struct {
	char *descp;
	int num_tarea;
	int dia;
	int mes;
	int anyo;
} Tarea;

#endif