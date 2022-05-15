#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

Passenger cargarPasajeros()
{
	Passenger sPasajeros;

	printf("Ingresde el nombre del pasajero: ");
	fflush(stdin);
	gets(sPasajeros.name);
	stringCorrecto(sPasajeros.name, "nombre");
	printf("Ingrese el apellido del pasajero: ");
	fflush(stdin);
	gets(sPasajeros.lastName);
	stringCorrecto(sPasajeros.lastName, "apellido");
	printf("Ingrese el precio del vuelo: $");
	scanf("%f",&sPasajeros.price);
	printf("Ingrese el codigo de vuelo: ");
	fflush(stdin);
	gets(sPasajeros.flycode);
	printf("Ingrese el tipo de pasajero (1-PRIMERA|2-ECONOMICA): ");
	scanf("%d",&sPasajeros.typePassenger);
	sPasajeros.typePassenger=validarInt(sPasajeros.typePassenger, 1, 2);
	printf("Ingrese el estado del vuelo (1-ACTIVO|2-INACTIVO): ");
	scanf("%d",&sPasajeros.statusFlight);
	sPasajeros.statusFlight=validarInt(sPasajeros.statusFlight, 1, 2);
	sPasajeros.id=idProgresive();
	sPasajeros.isEmpty=0;

	return sPasajeros;
}

void menu()
{
	printf("Seleccione una opcion:\n"
			"1_ Alta de pasajero.\n"
			"2_ Modificacion de pasajero.\n"
			"3_ Baja de pasajero.\n"
			"4_ Informar pasajeros.\n"
			"5_ Carga forzada de datos.\n"
			"6_ Salir.\n");
}


int hayPasajero(Passenger sPasajeros[], int size)
{
	int ok;
	ok=-1;

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0)
		{
			ok=0;
		}
	}

	return ok;
}

int validarInt(int numero, int menor, int mayor)
{
	while(numero<menor || numero>mayor)
	{
		printf("Ingrese un numero valido(%d-%d): ",menor,mayor);
		fflush(stdin);
		scanf("%d",&numero);
	}

	return numero;
}

int validarString(char string[])
{
    int ok;
    ok = 1;

    for(int i = 0; i < strlen(string); i++)
    {
        if (isdigit(string[i]) || isalpha(string[i]) == 0)
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








