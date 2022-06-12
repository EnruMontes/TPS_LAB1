#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Passenger.h"

/**********************************************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero.
     4. Modificar datos de pasajero.
     5. Baja de pasajero.
     6. Listar pasajeros.
     7. Ordenar pasajeros.
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir.
***********************************************************************************/



int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int ok;
	int flag=0;
	int flagDatos=0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	limpiar();
    	printf("Ingrese una opcion:\n"
    			"1_ Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"2_ Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    			"3_ Alta de pasajero.\n"
    			"4_ Modificar datos de pasajero.\n"
    			"5_ Baja de pasajero.\n"
    			"6_ Listar pasajeros.\n"
    			"7_ Ordenar pasajeros.\n"
    			"8_ Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    			"9_ Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    			"10_ Salir.\n");
    	scanf("%d",&opcion);
    	opcion = ValidarEntero(opcion, 1, 10);

        switch(opcion)
        {
            case 1:
            	limpiar();
            	if(flagDatos==0)
            	{
                    ok = controller_loadFromText("data.csv",listaPasajeros);

                    if(ok==1)
                    {
                    	printf("Se cargaron los datos correctamente.\n");
                    	flag=1;
                    	flagDatos=1;
                    }
                    else
                    {
                    	printf("Hubo un error al cargar los datos.\n");
                    }
            	}
            	else
            	{
            		printf("Ya se cargaron los datos, no se pueden cargar 2 veces.");
            	}

            	system("pause");
                break;

            case 2:
            	limpiar();
            	if(flagDatos==0)
            	{
                	ok = controller_loadFromBinary("data.bin", listaPasajeros);

                    if(ok==1)
                    {
                    	printf("Se cargaron los datos correctamente.\n");
                    	flag=1;
                    	flagDatos=1;
                    }
                    else
                    {
                    	printf("Hubo un error al cargar los datos.\n");
                    }
            	}
            	else
            	{
            		printf("Ya se cargaron los datos, no se pueden cargar 2 veces.");
            	}

            	system("pause");
            	break;

            case 3:
            	limpiar();
            	ok = controller_addPassenger(listaPasajeros);

                if(ok==1)
                {
                	printf("Se cargo el pasajero correctamente.\n");
                	flag=1;
                }
                else
                {
                	printf("Hubo un error al cargar el pasajero.\n");
                }

            	system("pause");
            	break;

            case 4:
            	limpiar();

            	if(flag==1)
            	{
                	ok = controller_editPassenger(listaPasajeros);

                    if(ok==1)
                    {
                    	printf("Se modifico correctamente el pasajero.\n");
                    }
                    else
                    {
                    	printf("Hubo un error al modificar el pasajero.\n"
                    			"Seguramente el ID ingresado no coincidia con ningun pasajero.\n\n");
                    }
            	}
            	else
            	{
            		printf("Se debe cargar por lo menos un pasajero para poder editarlo.\n");
            	}

            	system("pause");
            	break;

            case 5:
            	limpiar();
            	if(flag==1)
            	{
                	ok = controller_removePassenger(listaPasajeros);

                    if(ok==1)
                    {
                    	printf("Se elimino el pasajero correctamente.\n");
                    }
                    else
                    {
                    	printf("Hubo un error al eliminar el pasajero.\n"
                    			"Seguramente el ID ingresado no coincidia con ningun pasajero.\n\n");
                    }
            	}
            	else
            	{
            		printf("Se debe cargar al menos un pasajero para poder eliminarlo.\n");
            	}

            	system("pause");
            	break;

            case 6:
            	limpiar();
            	if(flag==1)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("Se debe cargar al menos un pasajero para poder listar.\n");
            	}

            	system("pause");
            	break;

            case 7:
            	limpiar();
            	if(flag==1)
            	{
            		ok = controller_sortPassenger(listaPasajeros);

            		if(ok==1)
            		{
            			printf("Se ordenaron correctamente los pasajeros.\n");
            		}
            		else
            		{
            			printf("Hubo un error al intentar ordenar los pasajeros.\n");
            		}
            	}
            	else
            	{
            		printf("Se debe cargar al menos un pasajero para poder odernarlos.\n");
            	}

            	system("pause");
            	break;

            case 8:
            	limpiar();

            	if(flag==1)
            	{
                	ok = controller_saveAsText("data.csv", listaPasajeros);

                    if(ok==1)
                    {
                    	printf("Se guardaron los datos correctamente.\n");
                    }
                    else
                    {
                    	printf("Hubo un error al guardar los datos.\n");
                    }
            	}
            	else
            	{
            		printf("Se debe cargar al menos un pasajero para poder guardarlo.\n");
            	}

            	system("pause");
            	break;

            case 9:
            	limpiar();

            	if(flag==1)
            	{
                	ok = controller_saveAsBinary("data.bin", listaPasajeros);

                    if(ok==1)
                    {
                    	printf("Se guardaron los datos correctamente.\n");
                    }
                    else
                    {
                    	printf("Hubo un error al guardar los datos.\n");
                    }
            	}
            	else
            	{
            		printf("Se debe cargar al menos un pasajero para poder guardarlo.\n");
            	}

            	system("pause");
            	break;
        }

    }while(opcion != 10);

    limpiar();
    printf("-----CONSOLA APAGADA-----");

    return 0;
}






