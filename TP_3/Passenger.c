#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"
static int idProgresivo=1000;

Passenger* Passenger_new() //Constructor
{
	Passenger* unPasajero;
	unPasajero = (Passenger*) malloc(sizeof(Passenger)); //Crea el espacio en memoria dinamica
	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr) //Constructor
{
	Passenger* unPasajero;

	unPasajero = Passenger_new();

	int tipoPasajero;

	Passenger_setId(unPasajero, atoi(idStr));
	Passenger_setNombre(unPasajero, nombreStr);
	Passenger_setApellido(unPasajero, apellidoStr);
	Passenger_setPrecio(unPasajero, atof(precioStr));
	Passenger_setCodigoVuelo(unPasajero, codigoVueloStr);
	Passenger_setEstadoVuelo(unPasajero, estadoVueloStr);

	if(strcmp(tipoPasajeroStr, "EconomyClass") == 0)
	{
		tipoPasajero = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = 2;
		}
		else
		{
			if(strcmp(tipoPasajeroStr, "FirstClass") == 0)
			{
				tipoPasajero = 3;
			}
		}
	}

	Passenger_setTipoPasajero(unPasajero, tipoPasajero);

	if((idStr==NULL) && (nombreStr==NULL) && (apellidoStr==NULL) && (precioStr==NULL) && (codigoVueloStr==NULL) && (tipoPasajeroStr==NULL) && (estadoVueloStr==NULL))
	{
		Passenger_delete(unPasajero);

		if(unPasajero==NULL)
		{
			Passenger_delete(unPasajero);
		}
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this) //Destructor
{
	free(this);
}

void Passenger_printOne(Passenger* this)
{
	if(this!=NULL)
	{
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

		getId = Passenger_getId(this, &id);
		getNombre = Passenger_getNombre(this, nombre);
		getApellido = Passenger_getApellido(this, apellido);
		getPrecio = Passenger_getPrecio(this, &precio);
		getCodigoVuelo = Passenger_getCodigoVuelo(this, codigoVuelo);
		getTipoPasajero = Passenger_getTipoPasajero(this, &tipoPasajero);
		getEstadoVuelo = Passenger_getEstadoVuelo(this, estadoVuelo);

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

		if(getId==1 && getNombre==1 && getApellido==1 && getPrecio==1 && getCodigoVuelo==1 && getTipoPasajero==1 && getEstadoVuelo==1)
		{
			printf("%4d %15s %15s %12.2f %10s %20s %15s\n", id,
															nombre,
															apellido,
															precio,
															codigoVuelo,
															tipoPasajeroStr,
															estadoVuelo);
		}
	}

}


int Passenger_setId(Passenger* this,int id)
{
	int ok;
	ok=0;

	if(this!=NULL && id>0)
	{
		this->id = id;
		ok=1;
	}

	return ok;
}

int Passenger_getId(Passenger* this,int* id)
{
	int ok;
	ok=0;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		ok=1;
	}

	return ok;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int ok;
	ok=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		ok=1;
	}

	return ok;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int ok;
	ok=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		ok=1;
	}

	return ok;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int ok;
	ok=0;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		ok=1;
	}

	return ok;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int ok;
	ok=0;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		ok=1;
	}

	return ok;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int ok;
	ok=0;

	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		ok=1;
	}

	return ok;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int ok;
	ok=0;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		ok=1;
	}

	return ok;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ok;
	ok=0;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		ok=1;
	}

	return ok;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int ok;
	ok=0;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		ok=1;
	}

	return ok;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int ok;
	ok=0;

	if(this!=NULL && tipoPasajero>0)
	{
		this->tipoPasajero = tipoPasajero;
		ok=1;
	}

	return ok;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int ok;
	ok=0;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		ok=1;
	}

	return ok;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ok;
	ok=0;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		ok=1;
	}

	return ok;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int ok;
	ok=0;

	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		ok=1;
	}

	return ok;
}



int Passenger_CompareById(void* p1, void* p2)
{
	int ok;
	ok=0;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(pasajero1->id > pasajero2->id)
	{
		ok=1;
	}
	else
	{
		if(pasajero1->id < pasajero2->id)
		{
			ok=-1;
		}
	}

	return ok;
}

int Passenger_CompareByNombre(void* p1, void* p2)
{
	int ok;
	ok=-2;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(p1!=NULL && p2!=NULL)
	{
		ok = strcmp(pasajero1->nombre, pasajero2->nombre);
	}

	return ok;
}

int Passenger_CompareByApellido(void* p1, void* p2)
{
	int ok;
	ok=-2;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(p1!=NULL && p2!=NULL)
	{
		ok = strcmp(pasajero1->apellido, pasajero2->apellido);
	}

	return ok;
}

int Passenger_CompareByPrecio(void* p1, void* p2)
{
	int ok;
	ok=0;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(pasajero1->precio > pasajero2->precio)
	{
		ok=1;
	}
	else
	{
		if(pasajero1->precio < pasajero2->precio)
		{
			ok=-1;
		}
	}

	return ok;
}

int Passenger_CompareByCodigoVuelo(void* p1, void* p2)
{
	int ok;
	ok=-2;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(p1!=NULL && p2!=NULL)
	{
		ok = strcmp(pasajero1->codigoVuelo, pasajero2->codigoVuelo);
	}

	return ok;
}

int Passenger_CompareByTipoPasajero(void* p1, void* p2)
{
	int ok;
	ok=0;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(pasajero1->tipoPasajero > pasajero2->tipoPasajero)
	{
		ok=1;
	}
	else
	{
		if(pasajero1->tipoPasajero < pasajero2->tipoPasajero)
		{
			ok=-1;
		}
	}

	return ok;
}

int Passenger_CompareByEstadoVuelo(void* p1, void* p2)
{
	int ok;
	ok=-2;

	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	if(p1!=NULL && p2!=NULL)
	{
		ok = strcmp(pasajero1->estadoVuelo, pasajero2->estadoVuelo);
	}

	return ok;
}



void limpiar()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int ValidarEntero(int numero, int minimo, int maximo)
{
	while(numero<minimo || numero>maximo)
	{
		printf("Ingrese una opcion valida(%d-%d): ",minimo, maximo);
		scanf("%d",&numero);
	}

	return numero;
}

int idProgresive()
{
	idProgresivo++;

    return idProgresivo;
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
		printf("Ingrese un %s valido: ",mensaje);
		fflush(stdin);
		gets(string);
		ok=validarString(string);
	}
}
