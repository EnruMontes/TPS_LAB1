#ifndef MEDICOS_H_
#define MEDICOS_H_
#define VACIO 0
#define LLENO 1

typedef struct
{
	int idMedico;
	char nombreMedico[50];
	char especialidad[20];

}sMedico;

typedef struct
{
	int dia;
	int mes;
	int anio;

}sFecha;

typedef struct
{
	int idConsulta;
	char nombrePaciente[50];
	sFecha fechaConsulta;
	int diagnostico;
	int idMedico;
	int isEmpty;

}sConsulta;



sConsulta cargarConsulta(sMedico Medico[], int size);
int validarEntero(int num, int minimo, int maximo);
int validarString(char string[]);
void stringCorrecto(char string[], char mensaje[]);
//int hayConsulta(sConsulta Consulta[], int size);    VALIDACION PARA DSP
void printConsultas(sConsulta Consulta[], int size);
void printMedicos(sMedico Medico[], int size);

void limpiar();
int idProgresive();
int initConsulta(sConsulta Consulta[], int size);
int altaConsulta(sConsulta Consulta[], int size, sMedico Medico[], int sizeMedico);
int buscarLibre(sConsulta Consulta[], int size);
int modificarConsulta(sConsulta Consulta[], int size, int id);
int buscarIdConsulta(sConsulta Consulta[], int size, int id);
int removeConsulta(sConsulta Consulta[], int size, int id);

#endif /* MEDICOS_H_ */
