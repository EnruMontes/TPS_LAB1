#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}typedef Passenger;

Passenger cargarPasajeros();
void limpiar();
void menu();
int idProgresive();
int altaPasajeros(Passenger[], int);
int buscarLibre(Passenger[], int);
void modificarPasajero(Passenger[], int, int);
void ordenAscendentePorTipo(Passenger[],int);
void ordenDescendentePorTipo(Passenger[],int);
void mostrarId(Passenger[], int);
int initPassengers(Passenger[], int);
int findPassengerById(Passenger[], int, int);
int removePassenger(Passenger[], int, int);
int sortPassenger(Passenger[], int, int);
int sortPassengerByCode(Passenger[], int, int);
void printPassenger(Passenger[],int);
void ordenarPorId(Passenger[],int);
void ordenAscendentePorEstado(Passenger[], int);
void ordenDescendentePorEstado(Passenger[], int);
float totalPrecioPasajes(Passenger[], int);
float promedioPrecioPasajes(Passenger[], int);
int pasajerosPasanPromedio(Passenger[], int);
int hayPasajero(Passenger[],int);
int validarInt(int, int, int);
int validarString(char[]);
void stringCorrecto(char[], char[]);
int cargaForzada(Passenger[], Passenger[],int);



#endif /* ARRAYPASSENGER_H_ */
