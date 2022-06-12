#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ok;
	int escaneo;
	ok=0;

	Passenger* unPasajero;
	char id[20];
	char nombre[50];
	char apellido[50];
	char precio[20];
	char codigoVuelo[20];
	char tipoPasajero[20];
	char estadoVuelo[20];
	char falsa[1000];

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%s",falsa); //Falsa lectura

		while(!feof(pFile))
		{
			escaneo = fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",id,
																						nombre,
																						apellido,
																						precio,
																						codigoVuelo,
																						tipoPasajero,
																						estadoVuelo);

			if(escaneo==7)
			{
				unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

				if(unPasajero!=NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
				}
			}


		}

		ok=1;
	}

    return ok;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int ok;
	int leyido;
	ok=0;

	Passenger* unPasajero;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		while(!feof(pFile))
		{
			unPasajero = Passenger_new();

			leyido = fread(unPasajero, sizeof(Passenger), 1, pFile);

			if(leyido==1)
			{
				ll_add(pArrayListPassenger, unPasajero);
				ok=1;
			}
		}
	}

    return ok;
}
