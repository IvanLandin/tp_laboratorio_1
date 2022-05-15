#include "mostrar.h"

int MostrarMenu(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[])
{
	int opcionDelMenu;

	//Imprimo en consola las opciones del menú precedidas de un número que va a servir de seleccionador.
	printf("%s", mensaje1);
	printf("%s", mensaje2);
	printf("%s", mensaje3);
	printf("%s", mensaje4);
	printf("%s", mensaje5);
	printf("Elija una opción: ");

	//Guardo la opción en una variable.
	scanf("%d", &opcionDelMenu);

	return opcionDelMenu;
}

void MostrarResultados(int kilometrosIngresados, float precioAerolineas, float precioLatam, float debitoAerolineas, float creditoAerolineas, float bitcoinAerolineas, float unitarioAerolineas, float debitoLatam, float creditoLatam, float bitcoinLatam, float unitarioLatam, float diferenciaDePrecio)
{
	//Muestro los kilometros ingresados por parámetro.
	printf("\nKilometros ingresados: %d km.\n", kilometrosIngresados);

	//Muestro el precio de una aerolínea ingresado por parámetro y calculo los diferentes métodos de pago.
	printf("\nPrecio Aerolíneas Argentinas: $%.2f.\n", precioAerolineas);
	printf("\nPrecio final debito: $%.2f.", debitoAerolineas);
	printf("\nPrecio final credito: $%.2f.", creditoAerolineas);
	printf("\nPrecio bitcoin: $%.2f.", bitcoinAerolineas);
	printf("\nPrecio unitario: $%.2f.\n", unitarioAerolineas);

	//Muestro el precio de otra aerolínea ingresado por parámetro y calculo los diferentes métodos de pago.
	printf("\nPrecio Latam Airlines: $%.2f.\n", precioLatam);
	printf("\nPrecio final debito: $%.2f.", debitoLatam);
	printf("\nPrecio final credito: $%.2f.", creditoLatam);
	printf("\nPrecio bitcoin: $%.2f.", bitcoinLatam);
	printf("\nPrecio unitario: $%.2f.\n", unitarioLatam);

	//Calculo la diferencia de precio entre las dos aerolíneas.
	printf("\nDiferencia de precios: $%.2f.\n\n", diferenciaDePrecio);

	//Utilizo la función Sleep para que el usuario pueda leer los resultados impresos en consola.
	Sleep(3000);
}
