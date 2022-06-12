/*pedirEntero
int pedirEntero(int rangoMinimo, int rangoMaximo, char mensajeNormal[], char mensajeError[]);

int pedirEntero(int rangoMinimo, int rangoMaximo, char mensajeNormal[], char mensajeError[])
{
   int numero;

   printf(mensajeNormal);
   scanf("%d",&numero);
   numero=validarEntero(numero,rangoMinimo,rangoMaximo,mensajeError);

   return numero;
}
*/

/*validarEntero
int validarEntero(int numero, int rangoMinimo, int rangoMaximo, char mensajeError[]);

int validarEntero(int numero, int rangoMinimo, int rangoMaximo, char mensajeError[])
{
   while(numero<rangoMinimo || numero>rangoMaximo)
   {
      printf("%s",mensajeError);
      scanf("%d",&numero);
   }
   return numero;
}
*/

/*validarEntero 2.0
int validarInt(int numero, int menor, int mayor)

int validarInt(int numero, int menor, int mayor)
{
	while(numero<menor || numero>mayor)
	{
		printf("Ingrese un numero valido(%d-%d): ",menor,mayor);
		fflush(stdin);
		scanf("%d",&numero);
	}

	return numero;
}
*/

/*cargarVector
void cargarVector(int[], int);

void cargarVector(int vector[], int size)
{
   for(int i=0;i<size;i++)
   {
      vector[i]=pedirEntero();
   }
}
*/

/*mostrarVector
void mostrarVector(int[], int);

void mostrarVector(int vector[], int size)
{
   int contador;
   contador=0;
   printf("Los numeros son: ");

   for(int i=0; i<size; i++)
   {
      if(contador==size-1)
      {
         printf("%d",vector[i]);
         //contador++;
      }
      else
      {
         printf("%d-",vector[i]);
         contador++;
      }
   }
}
*/

/*validarParidad
int validarParidad(int); //1 par, 0 impar

int validarParidad(int numero)
{
   int resultado;
   resultado=0;

   if(numero%2==0)
   {
      resultado=1;
   }

   return resultado;
}
*/

/*validarSigno
int validarSigno(int); //1 positivo, 0 neutro, -1 negativo

int validarSigno(int numero)
{
   int resultado;
   resultado=0;

   if(numero<0)
   {
      resultado=-1;
   }
   else
   {
      if(resultado>0)
      {
         resultado=1;
      }
   }

   return resultado;
}
*/

/*BubbleSort Creciente
void ordenamientoCreciente(int[],int);

void ordenamientoCreciente(int vector[],int size)
{
   int auxiliar;

   for(int i=0;i<size;i++)
   {
      for(int j=i+1;j<size;j++)
      {
         if(vector[i]>vector[j])
         {
            auxiliar=vector[i];
            vector[i]=vector[j];
            vector[j]=auxiliar;
         }
      }
   }
}
*/

/*BubbleSort Decreciente
void ordenamientoDecreciente(int[],int);

void ordenamientoDecreciente(int vector[],int size)
{
   int auxiliar;

   for(int i=0;i<size;i++)
   {
      for(int j=i+1;j<size;j++)
      {
         if(vector[i]<vector[j])
         {
            auxiliar=vector[i];
            vector[i]=vector[j];
            vector[j]=auxiliar;
         }
      }
   }
}
*/
