#include "ingresoDeDatos.h"

int PedirEntero(char mensaje[])
{
	int respuesta;

	printf("%s", mensaje);
	scanf("%d", &respuesta);
	//Invoco a una función para validar el número en un rango.
	respuesta = ValidarEntero(respuesta, "Error, ingrese un número mayor a 25 km y menor a 20000 km: ", 25, 20000);

	return respuesta;
}
float PedirFlotante(char mensaje[])
{
	float respuesta;

	printf("%s", mensaje);
	scanf("%f", &respuesta);
	//Invoco a una función para validar el número en un rango.
	respuesta = ValidarFlotante(respuesta, "Error, el monto total no puede ser igual o menor a $0: ", 1);

	return respuesta;
}
int ValidarEntero(int numero, char mensajeError[], int limiteInferior, int limiteSuperior)
{
	while(numero<limiteInferior || numero>limiteSuperior)
	{
		printf("%s", mensajeError);
		scanf("%d", &numero);
	}

	return numero;
}
float ValidarFlotante(float numero, char mensajeError[], int limiteInferior)
{
	while(numero<limiteInferior)
	{
		printf("%s", mensajeError);
		scanf("%f", &numero);
	}

	return numero;
}
