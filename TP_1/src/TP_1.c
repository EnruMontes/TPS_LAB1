//Enrico Montes Div c
//Ejercicio TP_1

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
    setbuf(stdout,NULL);

    int opcion;
    int vuelos;
    int costos;
    int x;
    float y;
    float z;
    int km;
    float precioAerolineas;
    float precioLatam;
    costos=0;
    x=0;
    y=0;
    z=0;
    km=7090;
    precioAerolineas=162965;
    precioLatam=159339;


    do
    {
        opcion=pedirEntero(1,6,"Ingrese una opcion(1-6):\n\n"
                               "1_Ingresar Kilometros: \n"
                               "2_Ingresar Precio de Vuelos: \n"
                               "3_Calcular los costos: \n"
                               "4_Informar Resultados: \n"
                               "5_Carga forzada de datos: \n"
                               "6_Salir: \n",
                               "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
                               "Ingrese una opcion CORRECTA (1-6):\n\n"
                               "1_Ingresar Kilometros: (km=x)\n"
                               "2_Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n"
                               "3_Calcular los costos: \n"
                               "4_Informar Resultados: \n"
                               "5_Carga forzada de datos: \n"
                               "6_Salir: \n");

        switch(opcion)
        {
            case 1:
                limpiar();
                x=ingresoKilometros();
                limpiar();
                break;

                case 2:
                    limpiar();
                    vuelos=ingresoVuelos(vuelos);

                    switch(vuelos)
                    {
                        case 1:
                            y=vuelosPrecioAerolineas();
                            limpiar();
                            break;

                            case 2:
                                z=vuelosPrecioLatam();
                                limpiar();
                                break;
                    }
                    break;

                    case 3:
                        limpiar();
                        if(x==0)
                        {
                            printf("No se puede realizar cálculos si no se ingresaron los kilometros...\n\n");
                        }
                        else
                        {
                            if(y==0 || z==0)
                            {
                                printf("No se puede realizar cálculos si no estan ambos vuelos ingresados...\n\n");
                            }
                            else
                            {
                                printf("Costos calculados.\n\n");
                                costos=1;
                            }
                        }
                        system("pause");
                        limpiar();
                        break;

                        case 4:
                            limpiar();

                            if(x==0)
                            {
                                printf("No se ingresaron los kilometros...\n\n");
                            }
                            else
                            {
                                if(y==0 || z==0)
                                {
                                    printf("No se ingresaron los precios de ambos vuelos...\n\n");
                                }
                                else
                                {
                                    if(costos==0)
                                    {
                                        printf("No se calcularon los costos...\n\n");
                                    }
                                    else
                                    {
                                        informarResultados(x,y,z);
                                    }
                                }
                            }

                            system("pause");
                            limpiar();
                            break;

                            case 5:
                                limpiar();
                                informarResultados(km,precioAerolineas,precioLatam);
                                system("pause");
                                limpiar();
                                break;

                                case 6:
                                    limpiar();
                                    printf("--CONSOLA APAGADA--");
                                    break;
        }

    }while(opcion!=6);

    return 0;
}
