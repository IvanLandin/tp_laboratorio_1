#include "mostrar.h"

int MostrarMenu(int kilometrosIngresados, float precioAerolineas, float precioLatam)
{
	int opcionDelMenu;

	//Imprimo en consola las opciones del menú precedidas de un número que va a servir de seleccionador.
	printf("\n1. Ingresar kilometros: %dkm. \n",kilometrosIngresados);
	printf("2. Ingresar precio de vuelos.\n-Precio de vuelo Aerolíneas: $%.2f \n-Precio de vuelo Latam: $%.2f \n",precioAerolineas,precioLatam);
	printf("3. Calcular costos.\n");
	printf("4. Informar resultados.\n");
	printf("5. Carga forzada de datos.\n");
	printf("6. Salir.\n");
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
