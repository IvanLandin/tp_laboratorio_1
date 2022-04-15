/*
 ============================================================================
1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
La carga forzada se tiene que mostrar exactamente igual a la pantalla de resultados sin ingresar
ninguna opción previamente. Tiene que calcular todo al momento de apretar el botón con los
siguientes datos:
Km: 7090
Aerolineas Argentinas: $162965
Latam: $ 159339
(solo mostrar los resultados ya calculados)
6. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//Incluyo la biblioteca <windows.h>, para poder usar la función Sleep y que el menú no termine el ciclo tan rápido al usar las opciones 3 y 4.
#include <windows.h>
//Incluyo mis propias bibliotecas.
#include "ingresoDeDatos.h"
#include "calculos.h"
#include "cargaForzada.h"
#include "mostrar.h"

int main(void)
{
	setbuf(stdout,NULL);
	//Declaro variables.
	int opcionDelMenu;
	char continuar;
	int kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	int banderaDeCalculos;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaDePrecios;
	float valorDeBitcoin;

	//Inicializo las variables pertinentes.
	kilometrosIngresados=0;
	precioAerolineas=0;
	precioLatam=0;
	banderaDeCalculos=1;
	continuar = 's';
	valorDeBitcoin = 4606954.55;

	//Inicio el bucle do while, para que al menos una vez se muestre el menú de opciones, y el usuario pueda elegir mas de una opción en tiempo de ejecución.
	do
	{
		opcionDelMenu = MostrarMenu(kilometrosIngresados, precioAerolineas, precioLatam);

		//Utilizo el condicional switch para efectuar la operación correspondiente a la elección del usuario, valiendome del número guardado en la variable opcionDelMenu.
		switch(opcionDelMenu)
		{
		case 1:
			//Solicito al usuario, ingrese los kilometros que reccore el vuelo.
			kilometrosIngresados = PedirEntero("\nIngrese los kilometros en total del vuelo: ");
			break;
		case 2:
			//Solicito al usuario, ingrese los precios de los vuelos.
			precioAerolineas = PedirFlotante("\nIngrese el precio total del vuelo por Aerolíneas Argentinas: ");
			precioLatam = PedirFlotante("\nIngrese el precio total del vuelo por Latam Airlines: ");
			break;
		case 3:
			//Los cálculos solo se realizan si hay datos ingresados por el usuario.
			if(kilometrosIngresados != 0 && precioAerolineas != 0 && precioLatam != 0)
			{
				//Realizo los cálculos en funciones y asigno los resultados a variables.
				precioDebitoAerolineas = CalcularDebitoCredito(precioAerolineas, -10);
				precioCreditoAerolineas = CalcularDebitoCredito(precioAerolineas, 25);
				precioUnitarioAerolineas = CalcularPrecioUnitario(precioAerolineas, kilometrosIngresados);
				precioBitcoinAerolineas = CalcularBitcoin(precioAerolineas, valorDeBitcoin);

				precioDebitoLatam = CalcularDebitoCredito(precioLatam, -10);
				precioCreditoLatam = CalcularDebitoCredito(precioLatam, 25);
				precioUnitarioLatam = CalcularPrecioUnitario(precioLatam, kilometrosIngresados);
				precioBitcoinLatam = CalcularBitcoin(precioLatam, valorDeBitcoin);

				diferenciaDePrecios = CalcularDiferencia(precioAerolineas, precioLatam);

				//Bajo la bandera que simboliza que se realizaron cálculos para poder mostrarlos.
				banderaDeCalculos=0;

				printf("\nCalculando costos...\n\n");
				//Utilizo la función Sleep para que el tiempo de respuesta del programa no sea tan corto y el usuario pueda leer los mensajes en pantalla.
				Sleep(1500);
			}
			else
			{
				printf("\nFaltan datos para calcular los métodos de pago.\n");
			}
			break;
		case 4:
			//Los resultados solo se muestran si se realizaron las operaciones de la opción 3.
			if(banderaDeCalculos == 0)
			{
				MostrarResultados(kilometrosIngresados,
						precioAerolineas,
						precioLatam,
						precioDebitoAerolineas,
						precioCreditoAerolineas,
						precioBitcoinAerolineas,
						precioUnitarioAerolineas,
						precioDebitoLatam,
						precioCreditoLatam,
						precioBitcoinLatam,
						precioUnitarioLatam,
						diferenciaDePrecios);
			}
			else
			{
				printf("\nNo se pueden mostrar resultados, ya que aún no se efectuaron los cálculos.\n");
			}
			break;
		case 5:
			//Se cargan datos por defecto y se ejecutan las mismas funciones de las opciones 3 y 4.
			OperarCargaForzada( 162965,  159339,  valorDeBitcoin,  7090,  -10, 25);
			break;
		case 6:
			//La opcion cambia la bandera asociada al bucle while, finalizando el programa.
			printf("\n¡Gracias por usar nuestra aplicación!");
			continuar = 'n';
			break;
		default:
			printf("\nEl número ingresado no corresponde con una opción válida. Por favor, selecciones una opción disponible: \n");
			break;
		}

	}while(continuar == 's');

	return EXIT_SUCCESS;
}
