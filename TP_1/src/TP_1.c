/*
 ============================================================================
1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar Kil�metros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
- Precio vuelo Aerol�neas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de d�bito (descuento 10%)
b) Tarjeta de cr�dito (inter�s 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
4. Informar Resultados
�Latam:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerol�neas:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r �
5. Carga forzada de datos
La carga forzada se tiene que mostrar exactamente igual a la pantalla de resultados sin ingresar
ninguna opci�n previamente. Tiene que calcular todo al momento de apretar el bot�n con los
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
//Incluyo la biblioteca <windows.h>, para poder usar la funci�n Sleep y que el men� no termine el ciclo tan r�pido al usar las opciones 3 y 4.
#include <windows.h>
//Incluyo mis propias bibliotecas.
#include "menu.h"
#include "ingresoDeDatos.h"
#include "calculos.h"
#include "cargaForzada.h"

int main(void)
{
	setbuf(stdout,NULL);
	//Declaro variables.
	int opcionDelMenu;
	char continuar;
	int kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
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
	int banderaDeCalculos;

	//Inicializo las variables pertinentes.
	kilometrosIngresados=0;
	precioAerolineas=0;
	precioLatam=0;
	banderaDeCalculos=1;
	continuar = 's';
	valorDeBitcoin = 4606954.55;

	//Inicio el bucle do while, para que al menos una vez se muestre el men� de opciones, y el usuario pueda elegir mas de una opci�n en tiempo de ejecuci�n.
	do
	{
		//Imprimo en consola las opciones del men� precedidas de un n�mero que va a servir de seleccionador.
		printf("\n1. Ingresar kilometros: %dkm. \n",kilometrosIngresados);
		printf("2. Ingresar precio de vuelos.\n  	-Precio de vuelo Aerol�neas: $%.2f \n  	-Precio de vuelo Latam: $%.2f \n",precioAerolineas,precioLatam);
		printf("3. Calcular costos.\n");
		printf("4. Informar resultados.\n");
		printf("5. Carga forzada de datos.\n");
		printf("6. Salir.\n");
		printf("Elija una opci�n: ");

		//Guardo la opci�n en una variable.
		scanf("%d", &opcionDelMenu);

		//Utilizo el condicional switch para efectuar la operaci�n correspondiente a la elecci�n del usuario, valiendome del n�mero guardado en la variable opcionDelMenu.
		switch(opcionDelMenu)
		{
		case 1:
			//Solicito al usuario, ingrese los kilometros que reccore el vuelo.
			kilometrosIngresados = PedirEntero("\nIngrese los kilometros en total del vuelo: ");
			break;
		case 2:
			//Solicito al usuario, ingrese los precios de los vuelos.
			precioAerolineas = PedirFlotante("\nIngrese el precio total del vuelo por Aerol�neas Argentinas: ");
			precioLatam = PedirFlotante("\nIngrese el precio total del vuelo por Latam Airlines: ");
			break;
		case 3:
			//Los c�lculos solo se realizan si hay datos ingresados por el usuario.
			if(kilometrosIngresados != 0 && precioAerolineas != 0 && precioLatam != 0)
			{
				//Realizo los c�lculos en funciones y asigno los resultados a variables.
				precioDebitoAerolineas = CalcularDebitoCredito(precioAerolineas, -10);
				precioCreditoAerolineas = CalcularDebitoCredito(precioAerolineas, 25);
				precioUnitarioAerolineas = CalcularPrecioUnitario(precioAerolineas, kilometrosIngresados);
				precioBitcoinAerolineas = CalcularBitcoin(precioAerolineas, valorDeBitcoin);

				precioDebitoLatam = CalcularDebitoCredito(precioLatam, -10);
				precioCreditoLatam = CalcularDebitoCredito(precioLatam, 25);
				precioUnitarioLatam = CalcularPrecioUnitario(precioLatam, kilometrosIngresados);
				precioBitcoinLatam = CalcularBitcoin(precioLatam, valorDeBitcoin);

				diferenciaDePrecios = CalcularDiferencia(precioAerolineas, precioLatam);

				//Bajo la bandera que simboliza que se realizaron c�lculos para poder mostrarlos.
				banderaDeCalculos=0;

				printf("\nCalculando costos...\n\n");
				//Utilizo la funci�n Sleep para que el tiempo de respuesta del programa no sea tan corto y el usuario pueda leer los mensajes en pantalla.
				Sleep(1500);
			}
			else
			{
				printf("\nFaltan datos para calcular los m�todos de pago.\n");
			}
			break;
		case 4:
			//Los resultados solo se muestran si se realizaron las operaciones de la opci�n 3.
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
				printf("\nNo se pueden mostrar resultados, ya que a�n no se efectuaron los c�lculos.\n");
			}
			break;
		case 5:
			//Se cargan datos por defecto y se ejecutan las mismas funciones de las opciones 3 y 4.
			OperarCargaForzada( 162965,  159339,  valorDeBitcoin,  7090,  -10, 25);
			break;
		case 6:
			//La opcion cambia la bandera asociada al bucle while, finalizando el programa.
			continuar = 'n';
			break;
		default:
			printf("\nEl n�mero ingresado no corresponde con una opci�n v�lida. Por favor, selecciones una opci�n disponible: \n");
			break;
		}

	}while(continuar == 's');

	return EXIT_SUCCESS;
}
