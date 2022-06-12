#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Medicos.h"

sConsulta cargarConsulta(sMedico Medico[], int size)
{
	sConsulta Consulta;

	printf("Ingrese el nombre del paciente: ");
	fflush(stdin);
	gets(Consulta.nombrePaciente);
	stringCorrecto(Consulta.nombrePaciente, "nombre");

	printf("Ingrese el dia de la consulta (1-31): ");
	scanf("%d",&Consulta.fechaConsulta.dia);
	validarEntero(Consulta.fechaConsulta.dia, 1, 31);

	printf("Ingrese el mes de la consulta (1-12): ");
	scanf("%d",&Consulta.fechaConsulta.mes);
	validarEntero(Consulta.fechaConsulta.mes, 1, 12);

	printf("Ingrese el año de la consulta (2022-2024): ");
	scanf("%d",&Consulta.fechaConsulta.anio);
	validarEntero(Consulta.fechaConsulta.anio, 2022, 2024);

	/*printf("Ingrese el diagnostico (1-Gripe A, 2-Covid-19, 3-Pre infarto): ");
	scanf("%d",&Consulta.diagnostico);
	validarEntero(Consulta.diagnostico, 1, 3);*/

	printf("Ingrese el ID del medico que atiende su consulta: \n");
	printMedicos(Medico, size);
	scanf("%d",&Consulta.idMedico);
	validarEntero(Consulta.idMedico, 101, 104);

	Consulta.diagnostico=0;
	Consulta.idConsulta=idProgresive();
	Consulta.isEmpty=LLENO;

	return Consulta;
}


int validarEntero(int num, int minimo, int maximo)
{
	while(num < minimo || num > maximo)
	{
		printf("Ingrese una opcion valida (%d-%d): ",minimo ,maximo);
		fflush(stdin);
		scanf("%d",&num);
	}

	return num;
}

int validarString(char string[])
{
    int ok;
    ok = 1;

    for(int i = 0; i < strlen(string); i++)
    {
        if (isdigit(string[i]) == 1)
        {
        	ok = 0;
        }
    }

    return ok;
}

void stringCorrecto(char string[], char mensaje[])
{
	int ok;
	ok=validarString(string);

	while(ok==0)
	{
		printf("Ingrese un %s valido:",mensaje);
		fflush(stdin);
		gets(string);
		ok=validarString(string);
	}
}



void printConsultas(sConsulta Consulta[], int size)
{
	for(int i=0; i<size; i++)
	{
		if(Consulta[i].isEmpty==LLENO)
		{
			printf("%d|",Consulta[i].idConsulta);
			printf("%s|",Consulta[i].nombrePaciente);
			printf("%d|",Consulta[i].fechaConsulta.dia);
			printf("%d|",Consulta[i].fechaConsulta.mes);
			printf("%d|",Consulta[i].fechaConsulta.anio);
			printf("%d|",Consulta[i].diagnostico);
			printf("%d\n",Consulta[i].idMedico);
		}
	}
	printf("\n");
}

void printMedicos(sMedico Medico[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d|%s|%s\n",Medico[i].idMedico,Medico[i].nombreMedico,Medico[i].especialidad);
	}
}

/*int hayConsulta(sConsulta Consulta[], int size)
{
	int ok;
	ok=-1;

	for(int i=0; i<size; i++)
	{
		if(Consulta[i].isEmpty==VACIO)
		{
			ok=0;
		}
	}

	return ok;
}*/










