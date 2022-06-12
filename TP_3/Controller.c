#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int ok;
	ok=0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path,"r");

		parser_PassengerFromText(pFile, pArrayListPassenger);

		fclose(pFile);

		ok=1;
	}


    return ok;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger) //NO LO HICE TODAVIA
{
	int ok;
	ok=0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path,"rb");

		parser_PassengerFromBinary(pFile, pArrayListPassenger);

		fclose(pFile);

		ok=1;
	}


    return ok;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int ok;
	ok=0;

	if(pArrayListPassenger!=NULL)
	{
		Passenger* unPasajero;
		char id[20];
		char nombre[50];
		char apellido[50];
		char precio[20];
		char codigoVuelo[20];
		int tipoPasajero;
		char tipoPasajeroStr[20];
		char estadoVuelo[20];

		sprintf(id,"%d",idProgresive());

		printf("Ingrese un nombre: ");
		fflush(stdin);
		gets(nombre);
		stringCorrecto(nombre, "nombre");

		printf("Ingrese un apellido: ");
		fflush(stdin);
		gets(apellido);
		stringCorrecto(apellido, "apellido");

		printf("Ingrese un precio: ");
		fflush(stdin);
		gets(precio);

		printf("Ingrese un codigo de vuelo: ");
		fflush(stdin);
		gets(codigoVuelo);

		printf("Ingrese un tipo de pasajero (1-EconomyClass | 2-ExecutiveClass | 3-FirstClass): ");
		scanf("%d",&tipoPasajero);
		tipoPasajero = ValidarEntero(tipoPasajero, 1, 3);

		if(tipoPasajero == 1)
		{
			strcpy(tipoPasajeroStr,"EconomyClass");
		}
		else
		{
			if(tipoPasajero == 2)
			{
				strcpy(tipoPasajeroStr,"ExecutiveClass");
			}
			else
			{
				if(tipoPasajero == 3)
				{
					strcpy(tipoPasajeroStr,"FirstClass");
				}
			}
		}

		printf("Ingrese un estado de vuelo: ");
		fflush(stdin);
		gets(estadoVuelo);
		stringCorrecto(estadoVuelo, "estado de vuelo");

		unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajeroStr, estadoVuelo);

		if(unPasajero!=NULL)
		{
			ll_add(pArrayListPassenger, unPasajero);
			ok=1;
		}
	}

    return ok;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int ok;
	int id;
	int idAux;
	int len;
	int opcion;
	ok=0;

	Passenger* unPasajero;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	int tipoPasajero;
	char estadoVuelo[20];

	if(pArrayListPassenger!=NULL)
	{
		printf("Ingrese el ID que quiere modificar: ");
		fflush(stdin);
		scanf("%d",&id);

		printf("\nIngrese que quiere modificar:\n"
				"1_ Modificar el Nombre.\n"
				"2_ Modificar el Apellido.\n"
				"3_ Modificar el Precio.\n"
				"4_ Modificar el Codigo de Vuelo.\n"
				"5_ Modificar el Tipo de Pasajero.\n"
				"6_ Modificar el Estado de Vuelo.\n");
		fflush(stdin);
		scanf("%d",&opcion);
		opcion = ValidarEntero(opcion, 1, 6);

		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(int i=0; i<len; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);

				if(Passenger_getId(unPasajero, &idAux) == 1)
				{
					if(idAux == id)
					{
						switch(opcion)
						{
							case 1:
								limpiar();

								printf("Ingrese el nuevo nombre: ");
								fflush(stdin);
								gets(nombre);
								stringCorrecto(nombre, "nombre");
								Passenger_setNombre(unPasajero, nombre);

								ok=1;
								break;

							case 2:
								limpiar();

								printf("Ingrese el nuevo apellido: ");
								fflush(stdin);
								gets(apellido);
								stringCorrecto(apellido, "apellido");
								Passenger_setApellido(unPasajero, apellido);

								ok=1;
								break;

							case 3:
								limpiar();

								printf("Ingrese el nuevo precio: ");
								scanf("%f",&precio);
								Passenger_setPrecio(unPasajero, precio);

								ok=1;
								break;

							case 4:
								limpiar();

								printf("Ingrese el nuevo codigo de vuelo: ");
								fflush(stdin);
								gets(codigoVuelo);
								Passenger_setCodigoVuelo(unPasajero, codigoVuelo);

								ok=1;
								break;

							case 5:
								limpiar();

								printf("Ingrese el nuevo tipo de pasajero (1-EconomyClass | 2-ExecutiveClass | 3-FirstClass): ");
								scanf("%d",&tipoPasajero);
								tipoPasajero = ValidarEntero(tipoPasajero, 1, 3);
								Passenger_setTipoPasajero(unPasajero, tipoPasajero);

								ok=1;
								break;

							case 6:
								limpiar();

								printf("Ingrese el nuevo estado de vuelo: ");
								fflush(stdin);
								gets(estadoVuelo);
								stringCorrecto(estadoVuelo, "estado de vuelo");
								Passenger_setEstadoVuelo(unPasajero, estadoVuelo);

								ok=1;
								break;
						}
					}
				}
			}
		}
	}

    return ok;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int ok;
	int id;
	int idAux;
	int len;
	Passenger* unPasajero;
	ok=0;

	if(pArrayListPassenger!=NULL)
	{
		printf("Ingrese el ID que se quiere eliminar: ");
		scanf("%d",&id);

		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(int i=0; i<len; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger,i);

				if(Passenger_getId(unPasajero, &idAux) == 1)
				{
					if(id == idAux)
					{
						ll_remove(pArrayListPassenger, i);

						ok=1;
						break;
					}
				}
			}
		}
	}

    return ok;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	int len;
	int ok;
	ok=0;

	if(pArrayListPassenger!=NULL)
	{
		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(int i=0; i<len; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unPasajero!=NULL)
				{
					Passenger_printOne(unPasajero);
				}
			}
			ok=1;
		}
	}

    return ok;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int ok;
    int opcion;
    int orden;
    ok=0;

    if(pArrayListPassenger!=NULL)
    {
		printf("Ingrese que quiere ordenar:\n"
				"1_ Ordenar por ID.\n"
				"2_ Ordenar por Nombre.\n"
				"3_ Ordenar por Apellido.\n"
				"4_ Ordenar por Precio.\n"
				"5_ Ordenar por Codigo de Vuelo.\n"
				"6_ Ordenar por Tipo de Pasajero.\n"
				"7_ Ordenar por Estado de Vuelo.\n");
		scanf("%d",&opcion);
		opcion = ValidarEntero(opcion,1,7);

		switch(opcion)
		{
			case 1:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareById, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareById, 0);
						break;
				}

				ok=1;
				break;

			case 2:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByNombre, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByNombre, 0);
						break;
				}

				ok=1;
				break;

			case 3:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByApellido, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByApellido, 0);
						break;
				}

				ok=1;
				break;

			case 4:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByPrecio, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByPrecio, 0);
						break;
				}

				ok=1;
				break;

			case 5:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByCodigoVuelo, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByCodigoVuelo, 0);
						break;
				}

				ok=1;
				break;

			case 6:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByTipoPasajero, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByTipoPasajero, 0);
						break;
				}

				ok=1;
				break;

			case 7:
				printf("\nComo lo desea ordenar:\n"
						"1_ Ascendente.\n"
						"2_ Desendente.\n");
				scanf("%d",&orden);
				orden = ValidarEntero(orden, 1, 2);

				limpiar();

				switch(orden)
				{
					case 1:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByEstadoVuelo, 1);
						break;

					case 2:
						limpiar();
						printf("Ordenando los datos, porfavor espere.\n");
						ll_sort(pArrayListPassenger, Passenger_CompareByEstadoVuelo, 0);
						break;
				}

				ok=1;
				break;
		}
    }

    return ok;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int ok;
	int len;
	ok=0;

	Passenger* unPasajero;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	int tipoPasajero;
	char tipoPasajeroStr[20];
	char estadoVuelo[20];

	int getId;
	int getNombre;
	int getApellido;
	int getPrecio;
	int getCodigoVuelo;
	int getTipoPasajero;
	int getEstadoVuelo;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path, "w");

		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(int i=0; i<len; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				getId = Passenger_getId(unPasajero, &id);
				getNombre = Passenger_getNombre(unPasajero, nombre);
				getApellido = Passenger_getApellido(unPasajero, apellido);
				getPrecio = Passenger_getPrecio(unPasajero, &precio);
				getCodigoVuelo = Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
				getTipoPasajero = Passenger_getTipoPasajero(unPasajero, &tipoPasajero);
				getEstadoVuelo = Passenger_getEstadoVuelo(unPasajero, estadoVuelo);

				if(tipoPasajero == 1)
				{
					strcpy(tipoPasajeroStr,"EconomyClass");
				}
				else
				{
					if(tipoPasajero == 2)
					{
						strcpy(tipoPasajeroStr,"ExecutiveClass");
					}
					else
					{
						if(tipoPasajero == 3)
						{
							strcpy(tipoPasajeroStr,"FirstClass");
						}
					}
				}


				if(unPasajero!=NULL && getId==1 && getNombre==1 && getApellido==1 && getPrecio==1 && getCodigoVuelo==1 && getTipoPasajero==1 && getEstadoVuelo==1)
				{
					fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",id
														,nombre
														,apellido
														,precio
														,codigoVuelo
														,tipoPasajeroStr
														,estadoVuelo);
					ok=1;
				}
			}
		}

		fclose(pFile);
	}

    return ok;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int ok;
	int len;
	ok=0;

	Passenger* unPasajero;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		FILE* pFile = fopen(path, "wb");

		len = ll_len(pArrayListPassenger);

		if(len>0)
		{
			for(int i=0; i<len; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);

				if(unPasajero!=NULL)
				{
					fwrite(unPasajero, sizeof(Passenger),1,pFile);
					ok=1;
				}
			}
		}

		fclose(pFile);
	}

    return ok;
}

