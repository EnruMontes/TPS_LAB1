#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int pedirEntero(int rangoMinimo, int rangoMaximo, char mensajeNormal[], char mensajeError[])
{
    int numero;

    printf(mensajeNormal);
    scanf("%d",&numero);
    numero=validarEntero(numero,rangoMinimo,rangoMaximo,mensajeError);

    return numero;
}

int validarEntero(int numero, int rangoMinimo, int rangoMaximo, char mensajeError[])
{
    while(numero<rangoMinimo || numero>rangoMaximo)
    {
        printf("%s",mensajeError);
        scanf("%d",&numero);
    }
    return numero;
}

void limpiar()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int ingresoKilometros()
{
    int x;

    printf("Ingrese los kilometros: ");
    scanf("%d",&x);
    x=validacionKilometros(x);

    return x;
}

int validacionKilometros(int km)
{
    while(km<=0)
    {
        printf("Ingrese un kilometraje valido(Mayor a 0): ");
        scanf("%d",&km);
    }
    return km;
}

int ingresoVuelos(int vuelos)
{

    printf("Para ingresar los precio vuelos Aerolineas(Marque 1): \n"
           "Para ingresar los precio vuelos Latam(Marque 2): \n");
    scanf("%d",&vuelos);

    vuelos=validacionIngresoVuelos(vuelos);

    return vuelos;
}

int validacionIngresoVuelos(int vuelos)
{
    while (vuelos!=1 && vuelos!=2)
    {
        limpiar();
        printf("Ingrese BIEN un numero de vuelo:\n"
               "Precio vuelos Aerolineas(Ingrese 1): \n"
               "Precio vuelos Latam(Ingrese 2): \n");
        scanf("%d",&vuelos);
    }

    return vuelos;
}

float vuelosPrecioAerolineas()
{
    float y;

    printf("Ingrese el precio:$");
    scanf("%f",&y);
    y=validacionPrecioVuelos(y);

    return y;
}

float vuelosPrecioLatam()
{
    float z;

    printf("Ingrese el precio:$");
    scanf("%f",&z);
    z=validacionPrecioVuelos(z);

    return z;
}

float validacionPrecioVuelos(float precio)
{
    while(precio<=0)
    {
        printf("Ingrese un precio valido(Mayor a 0):$");
        scanf("%f",&precio);
    }
    return precio;
}

float tarjetaDeDebito(float precio)
{
    float debito;

    debito=precio*0.9;

    return debito;
}

float tarjetaDeCredito(float precio)
{
    float credito;

    credito=precio*1.25;

    return credito;
}

float bitcoin(float precio)
{
    float bitcoin;

    bitcoin=precio/4606954.55;

    return bitcoin;
}

float precioUnitario(float precio, int km)
{
    float resultado;

    resultado=precio/(float)km;

    return resultado;
}

float diferenciaPrecios(float z, float y)
{
    float diferencia;

    if(z>y)
    {
        diferencia=z-y;
    }
    else
    {
        diferencia=y-z;
    }

    return diferencia;
}

void informarResultados(int x, float y, float z)
{
    printf("Kms Ingresados: %dkm\n\n"
           "Precio Latam: $%.2f\n"
           "a) Precio con tarjeta de débito: $%.2f\n"
           "b) Precio con tarjeta de crédito: $%.2f\n"
           "c) Precio pagando con bitcoin: $%fBTC\n"
           "d) Precio unitario: $%.2f\n\n"
           "Precio Aerolíneas: $%.2f\n"
           "a) Precio con tarjeta de débito: $%.2f\n"
           "b) Precio con tarjeta de crédito: $%.2f\n"
           "c) Precio pagando con bitcoin: %fBTC\n"
           "d) Precio unitario: $%.2f\n\n"
           "La diferencia de precio es: $%.2f\n\n",x,
           z,tarjetaDeDebito(z),tarjetaDeCredito(z),bitcoin(z),precioUnitario(z,x),
           y,tarjetaDeDebito(y),tarjetaDeCredito(y),bitcoin(y),precioUnitario(y,x),
           diferenciaPrecios(z,y));
}




