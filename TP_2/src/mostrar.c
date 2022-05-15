#include "mostrar.h"

int MostrarMenu(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[])
{
	int opcionDelMenu;

	//Imprimo en consola las opciones del men� precedidas de un n�mero que va a servir de seleccionador.
	printf("%s", mensaje1);
	printf("%s", mensaje2);
	printf("%s", mensaje3);
	printf("%s", mensaje4);
	printf("%s", mensaje5);
	printf("Elija una opci�n: ");

	//Guardo la opci�n en una variable.
	scanf("%d", &opcionDelMenu);

	return opcionDelMenu;
}

void MostrarResultados(int kilometrosIngresados, float precioAerolineas, float precioLatam, float debitoAerolineas, float creditoAerolineas, float bitcoinAerolineas, float unitarioAerolineas, float debitoLatam, float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaDePrecio)
{
	//Muestro los kilometros ingresados por par�metro.
	printf("\nKilometros ingresados: %d km.\n", kilometrosIngresados);

	//Muestro el precio de una aerol�nea ingresado por par�metro y calculo los diferentes m�todos de pago.
	printf("\nPrecio Aerol�neas Argentinas: $%.2f.\n", precioAerolineas);
	printf("\nPrecio final debito: $%.2f.", debitoAerolineas);
	printf("\nPrecio final credito: $%.2f.", creditoAerolineas);
	printf("\nPrecio bitcoin: $%.2f.", bitcoinAerolineas);
	printf("\nPrecio unitario: $%.2f.\n", unitarioAerolineas);

	//Muestro el precio de otra aerol�nea ingresado por par�metro y calculo los diferentes m�todos de pago.
	printf("\nPrecio Latam Airlines: $%.2f.\n", precioLatam);
	printf("\nPrecio final debito: $%.2f.", debitoLatam);
	printf("\nPrecio final credito: $%.2f.", creditoLatam);
	printf("\nPrecio bitcoin: $%.2f.", bitcoinLatam);
	printf("\nPrecio unitario: $%.2f.\n", unitarioLatam);

	//Calculo la diferencia de precio entre las dos aerol�neas.
	printf("\nDiferencia de precios: $%.2f.\n\n", diferenciaDePrecio);

	//Utilizo la funci�n Sleep para que el usuario pueda leer los resultados impresos en consola.
	Sleep(3000);
}
