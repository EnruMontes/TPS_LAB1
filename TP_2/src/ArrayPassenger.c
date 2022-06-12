#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
static int idProgresivo=1000;

void limpiar()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int idProgresive()
{
	idProgresivo++;

    return idProgresivo;
}

int altaPasajeros(Passenger sPasajeros[], int size)
{
	int j;

	j=buscarLibre(sPasajeros,size);

	if(j!=-1)
	{
		sPasajeros[j]=cargarPasajeros();
	}

	return j;
}

int buscarLibre(Passenger sPasajeros[], int size)
{
	int j;
	j=-1;

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==1)
		{
			j=i;
			break;
		}
	}

	return j;
}

int initPassengers(Passenger sPasajeros[], int size)
{
	int j;
	j=-1;

	for(int i=0;i<size;i++)
	{
		sPasajeros[i].isEmpty=1;
		j=0;
	}

	return j;
}

void modificarPasajero(Passenger sPasajeros[], int size, int id)
{
	int posicion;
	int modificacion;
	posicion=findPassengerById(sPasajeros,size,id);

	printf("Seleccione que quiere modificar:\n"
			"1_ Nombre.\n"
			"2_ Apellido.\n"
			"3_ Precio de vuelo.\n"
			"4_ Tipo de pasajero.\n"
			"5_ Codigo de vuelo.\n");
	scanf("%d",&modificacion);
	modificacion=validarInt(modificacion, 1, 5);

	switch(modificacion)
	{
		case 1:
			limpiar();
			for(int i=0;i<size;i++)
			{
				if(i==posicion)
				{
					printf("Ingrese el nuevo nombre: ");
					fflush(stdin);
					gets(sPasajeros[i].name);
					stringCorrecto(sPasajeros[i].name, "nombre");
				}
			}
			break;

		case 2:
			limpiar();
			for(int i=0;i<size;i++)
			{
				if(i==posicion)
				{
					printf("Ingrese el nuevo apellido: ");
					fflush(stdin);
					gets(sPasajeros[i].lastName);
					stringCorrecto(sPasajeros[i].lastName, "apellido");
				}
			}
			break;

		case 3:
			limpiar();
			for(int i=0;i<size;i++)
			{
				if(i==posicion)
				{
					printf("Ingrese el nuevo precio: ");
					scanf("%f",&sPasajeros[i].price);
				}
			}
			break;

		case 4:
			limpiar();
			for(int i=0;i<size;i++)
			{
				if(i==posicion)
				{
					printf("Ingrese el nuevo tipo de pasajero (1-PRIMERA|2-ECONOMICA): ");
					scanf("%d",&sPasajeros[i].typePassenger);
					sPasajeros[i].typePassenger=validarInt(sPasajeros[i].typePassenger, 1, 2);
				}
			}
			break;

		case 5:
			limpiar();
			for(int i=0;i<size;i++)
			{
				if(i==posicion)
				{
					printf("Ingrese el nuevo codigo de vuelo: ");
					fflush(stdin);
					gets(sPasajeros[i].flycode);
				}
			}
			break;
	}

	printf("Modificacion realizada.\n");
}

int findPassengerById(Passenger sPasajeros[], int size, int id)
{
	int posicion;
	posicion=-1;

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].id==id)
		{
			posicion=i;
			break;
		}
	}

	return posicion;
}

int removePassenger(Passenger sPasajeros[], int size, int id)
{
	int ok;
	ok=-1;

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0 && sPasajeros[i].id==id)
		{
			sPasajeros[i].isEmpty=1;
			ok=0;
			break;
		}
	}

	return ok;
}

int sortPassenger(Passenger sPasajeros[], int size, int order)
{
	int ok;
	ok=-1;

	switch(order)
	{
		case 1:
			ordenAscendentePorTipo(sPasajeros,size);
			ok=0;
			break;
		case 2:
			ordenDescendentePorTipo(sPasajeros,size);
			ok=0;
			break;
		default:
			break;
	}

	return ok;
}

void ordenAscendentePorTipo(Passenger sPasajeros[],int size)
{
	Passenger auxiliar;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(sPasajeros[i].typePassenger<sPasajeros[j].typePassenger)
			{
				auxiliar=sPasajeros[i];
				sPasajeros[i]=sPasajeros[j];
				sPasajeros[j]=auxiliar;
			}
		}
	}

	for(int k=0;k<size;k++)
	{
		for(int l=k+1;l<size;l++)
		{
			if((strcmp(sPasajeros[k].lastName, sPasajeros[l].lastName)>0) && (sPasajeros[k].typePassenger==sPasajeros[l].typePassenger))
			{
				auxiliar=sPasajeros[k];
				sPasajeros[k]=sPasajeros[l];
				sPasajeros[l]=auxiliar;
			}
		}
	}
}

void ordenDescendentePorTipo(Passenger sPasajeros[],int size)
{
	Passenger auxiliar;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(sPasajeros[i].typePassenger>sPasajeros[j].typePassenger)
			{
				auxiliar=sPasajeros[i];
				sPasajeros[i]=sPasajeros[j];
				sPasajeros[j]=auxiliar;
			}
		}
	}

	for(int k=0;k<size;k++)
	{
		for(int l=k+1;l<size;l++)
		{
			if((strcmp(sPasajeros[k].lastName, sPasajeros[l].lastName)<0) && (sPasajeros[k].typePassenger==sPasajeros[l].typePassenger))
			{
				auxiliar=sPasajeros[k];
				sPasajeros[k]=sPasajeros[l];
				sPasajeros[l]=auxiliar;
			}
		}
	}
}

void printPassenger(Passenger sPasajeros[], int size)
{
	printf("|  ID  |    NOMBRE    |   APELLIDO   |   PRECIO    |  CODIGO  |     TIPO    |    ESTADO    |\n"
			"|      |              |              |             |          |  1-PRIMERA  |  1-ACTIVO    |\n"
			"|      |              |              |             |          | 2-ECONOMICA |  2-INACTIVO  |\n"
			"--------------------------------------------------------------------------------------------\n");

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0)
		{
			printf("| %-5d|",sPasajeros[i].id);
			printf(" %-13s|",sPasajeros[i].name);
			printf(" %-13s|",sPasajeros[i].lastName);
			printf(" $%-11.2f|",sPasajeros[i].price);
			printf(" %-9s|",sPasajeros[i].flycode);
			printf("      %-7d|",sPasajeros[i].typePassenger);
			printf("      %-8d|\n",sPasajeros[i].statusFlight);
		}
	}
	printf("\n");
}

void mostrarId(Passenger sPasajeros[], int size)
{
	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0)
		{
			printf("%d\n",sPasajeros[i].id);
		}
	}
}

void ordenarPorId(Passenger sPasajeros[], int size)
{
	Passenger auxiliar;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(sPasajeros[i].id>sPasajeros[j].id)
			{
				auxiliar=sPasajeros[i];
				sPasajeros[i]=sPasajeros[j];
				sPasajeros[j]=auxiliar;
			}
		}
	}
}

int sortPassengerByCode(Passenger sPasajeros[], int size, int order)
{
	int ok;
	ok=-1;

	switch(order)
	{
		case 1:
			ordenAscendentePorEstado(sPasajeros,size);
			ok=0;
			break;
		case 2:
			ordenDescendentePorEstado(sPasajeros,size);
			ok=0;
			break;
		default:
			break;
	}

	return ok;
}

void ordenAscendentePorEstado(Passenger sPasajeros[],int size)
{
	Passenger auxiliar;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(sPasajeros[i].statusFlight<sPasajeros[j].statusFlight)
			{
				auxiliar=sPasajeros[i];
				sPasajeros[i]=sPasajeros[j];
				sPasajeros[j]=auxiliar;
			}
		}
	}

	for(int k=0;k<size;k++)
	{
		for(int l=k+1;l<size;l++)
		{
			if((strcmp(sPasajeros[k].flycode, sPasajeros[l].flycode)>0) && (sPasajeros[k].statusFlight==sPasajeros[l].statusFlight))
			{
				auxiliar=sPasajeros[k];
				sPasajeros[k]=sPasajeros[l];
				sPasajeros[l]=auxiliar;
			}
		}
	}
}

void ordenDescendentePorEstado(Passenger sPasajeros[],int size)
{
	Passenger auxiliar;

	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(sPasajeros[i].statusFlight>sPasajeros[j].statusFlight)
			{
				auxiliar=sPasajeros[i];
				sPasajeros[i]=sPasajeros[j];
				sPasajeros[j]=auxiliar;
			}
		}
	}

	for(int k=0;k<size;k++)
	{
		for(int l=k+1;l<size;l++)
		{
			if((strcmp(sPasajeros[k].flycode, sPasajeros[l].flycode)<0) && (sPasajeros[k].statusFlight==sPasajeros[l].statusFlight))
			{
				auxiliar=sPasajeros[k];
				sPasajeros[k]=sPasajeros[l];
				sPasajeros[l]=auxiliar;
			}
		}
	}
}

float totalPrecioPasajes(Passenger sPasajeros[], int size)
{
	float total;
	total=0;

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0)
		{
			total+=sPasajeros[i].price;
		}
	}

	return total;
}

float promedioPrecioPasajes(Passenger sPasajeros[], int size)
{
	float total;
	int cantidad;
	float promedio;
	cantidad=0;
	total=totalPrecioPasajes(sPasajeros,size);

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0)
		{
			cantidad++;
		}
	}

	promedio=total/(float)cantidad;

	return promedio;
}

int pasajerosPasanPromedio(Passenger sPasajeros[], int size)
{
	int cantidad;
	float promedio;
	cantidad=0;
	promedio=promedioPrecioPasajes(sPasajeros, size);

	for(int i=0;i<size;i++)
	{
		if(sPasajeros[i].isEmpty==0 && sPasajeros[i].price>promedio)
		{
			cantidad++;
		}
	}
	return cantidad;
}

int cargaForzada(Passenger sPasajeros[], Passenger sForzada[],int size)
{
	int libre;
	int k;
	int vuelta;
	vuelta=-1;
	k=0;

	while(k<5)
	{
		libre=buscarLibre(sPasajeros, size);

		if(libre!=-1)
		{
			sPasajeros[libre].id=sForzada[k].id;
			strcpy(sPasajeros[libre].name,sForzada[k].name);
			strcpy(sPasajeros[libre].lastName,sForzada[k].lastName);
			sPasajeros[libre].price=sForzada[k].price;
			strcpy(sPasajeros[libre].flycode,sForzada[k].flycode);
			sPasajeros[libre].typePassenger=sForzada[k].typePassenger;
			sPasajeros[libre].statusFlight=sForzada[k].statusFlight;
			sForzada[k].isEmpty=0;
			sPasajeros[libre].isEmpty=sForzada[k].isEmpty;
			k++;
		}
		else
		{
			k=10;
		}
	}

	if(k==5)
	{
		vuelta=0;
	}

	return vuelta;
}












