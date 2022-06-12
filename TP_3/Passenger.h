#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	int tipoPasajero;
	char estadoVuelo[20];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoVueloStr);
void Passenger_delete(Passenger* this);
void Passenger_printOne(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);


int Passenger_CompareById(void* p1, void* p2);
int Passenger_CompareByNombre(void* p1, void* p2);
int Passenger_CompareByApellido(void* p1, void* p2);
int Passenger_CompareByPrecio(void* p1, void* p2);
int Passenger_CompareByCodigoVuelo(void* p1, void* p2);
int Passenger_CompareByTipoPasajero(void* p1, void* p2);
int Passenger_CompareByEstadoVuelo(void* p1, void* p2);


void limpiar();
int ValidarEntero(int numero, int minimo, int maximo);
int idProgresive();
int validarString(char string[]);
void stringCorrecto(char string[], char mensaje[]);

#endif /* PASSENGER_H_ */
