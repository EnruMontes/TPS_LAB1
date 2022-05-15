/* Montes Enrico Div C
	TP N°2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#define TAM 2000

int main(void)
{
	setbuf(stdout, NULL);

	Passenger sPasajeros[TAM];
	Passenger sForzada[5]={{5001,"Enrico","Montes",14000,"ABC123",2,1,0},
						   {5002,"Pablo","Perez",17000,"ABC456",1,1,0},
						   {5003,"Graciela","Gonzales",15000,"ABC789",2,2,0},
						   {5004,"Gonzalo","Cerrato",21000,"ABC123",1,1,0},
						   {5005,"Martin","Turina",29000,"ABC789",1,2,0}};


	int opcion;
	int retorno;
	int id;
	int orden;
	int remover;
	int informar;
	float total;
	float promedio;
	int cantidadPromedio;
	int hay;
	int vuelta;
	int flag;
	flag=0;
	initPassengers(sPasajeros, TAM);

	do
	{
		limpiar();

		menu();
		scanf("%d",&opcion);
		opcion=validarInt(opcion, 1, 6);

		switch(opcion)
		{
			case 1:
				limpiar();

				retorno = altaPasajeros(sPasajeros,TAM);

				switch(retorno)
				{
					case -1:
						printf("No hay espacio disponible.\n");
						break;
					default:
						printf("Carga exitosa\n");
						break;
				}

				system("pause");
				break;

			case 2:
				limpiar();

				hay=hayPasajero(sPasajeros,TAM);

				if(hay==0)
				{
					printf("Ingrese el ID que quiere modificar: \n");
					ordenarPorId(sPasajeros,TAM);
					mostrarId(sPasajeros,TAM);
					scanf("%d",&id);

					limpiar();
					modificarPasajero(sPasajeros,TAM,id);
				}
				else
				{
					printf("No se puede modificar nada porque no se ingreso ningun pasajero.\n\n");
				}

				system("pause");
				break;

			case 3:
				limpiar();

				hay=hayPasajero(sPasajeros,TAM);

				if(hay==0)
				{
					printf("Ingrese el ID que quiere eliminar:\n");
					ordenarPorId(sPasajeros,TAM);
					mostrarId(sPasajeros,TAM);
					scanf("%d",&id);

					remover=removePassenger(sPasajeros,TAM,id);

					if(remover==0)
					{
						printf("Pasajero dado de baja correctamente.\n");
					}
					else
					{
						printf("No se ha podido remover el pasajero correctamente.\n");
					}
				}
				else
				{
					printf("No se puede dar de baja nada porque no se ingreso ningun pasajero.\n\n");
				}

				system("pause");
				break;

			case 4:
				limpiar();

				hay=hayPasajero(sPasajeros,TAM);

				if(hay==0)
				{
					printf("Elige una opcion para informar los pasajeros:\n"
							"1_ Informar en un listado por apellido y tipo de pasajeros.\n"
							"2_ Informar el total y promedio de los precios de los pasajes.\n"
							"3_ Informar en un listado por codigo y estado de vuelo.\n");
					scanf("%d",&informar);
					informar=validarInt(informar, 1, 3);

					switch(informar)
					{
						case 1:
							limpiar();

							printf("Ingrese un orden para informar los datos:\n"
									"1_ Orden Ascendente.\n"
									"2_ Orden Descendente.\n");
							scanf("%d",&orden);
							orden=validarInt(orden, 1, 2);

							sortPassenger(sPasajeros,TAM,orden);
							printPassenger(sPasajeros,TAM);
							break;

						case 2:
							limpiar();

							total=totalPrecioPasajes(sPasajeros, TAM);
							printf("El total de precio de los vuelos es: %.2f\n",total);

							promedio=promedioPrecioPasajes(sPasajeros, TAM);
							printf("El promedio de los precios de los vuelos es: %.2f\n",promedio);

							cantidadPromedio=pasajerosPasanPromedio(sPasajeros,TAM);
							printf("La cantidad de pasajeros que superaron el promedio de precio de vuelos fueron: %d\n",cantidadPromedio);

							break;

						case 3:
							limpiar();

							printf("Ingrese un orden para informar los datos:\n"
									"1_ Orden Ascendente.\n"
									"2_ Orden Descendente.\n");
							scanf("%d",&orden);
							orden=validarInt(orden, 1, 2);

							sortPassengerByCode(sPasajeros,TAM,orden);
							printPassenger(sPasajeros,TAM);
							break;
					}
				}
				else
				{
					printf("No se puede listar nada porque no se ingreso ningun pasajero.\n\n");
				}

				system("pause");
				break;
			case 5:
				limpiar();
				if(flag==0)
				{
					vuelta=cargaForzada(sPasajeros,sForzada,TAM);
				}

				if(vuelta==0 && flag==0)
				{
					printf("Se cargo correctamente los datos forzados.\n");
				}
				else
				{
					if(flag==0)
					{
						printf("No habia espacio para cargar a todos los pasajeros forzados.\n");
					}

					printf("Ya se cargaron los datos forzados.\n");
				}

				flag=1;

				system("pause");
				break;
		}


	}while(opcion!=6);


	limpiar();
	printf("-----CONSOLA APAGADA-----");

	return 0;
}
