#include "cargaForzada.h"

void OperarCargaForzada(float precioAerolineas, float precioLatam, float valorDeBitcoin, int kilometrosIngresados, int unPorcentaje, int otroPorcentaje)
{
	//Declaro variables para almacenar los datos resultantes de las funciones.
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaDePrecios;

	//Muestro el precio de una aerolínea ingresado por parámetro y calculo los diferentes métodos de pago.
	precioDebitoAerolineas = CalcularDebitoCredito(precioAerolineas, unPorcentaje);
	precioCreditoAerolineas = CalcularDebitoCredito(precioAerolineas, otroPorcentaje);
	precioUnitarioAerolineas = CalcularPrecioUnitario(precioAerolineas, kilometrosIngresados);
	precioBitcoinAerolineas = CalcularBitcoin(precioAerolineas, valorDeBitcoin);

	//Muestro el precio de otra aerolínea ingresado por parámetro y calculo los diferentes métodos de pago.
	precioDebitoLatam = CalcularDebitoCredito(precioLatam, unPorcentaje);
	precioCreditoLatam = CalcularDebitoCredito(precioLatam, otroPorcentaje);
	precioUnitarioLatam = CalcularPrecioUnitario(precioLatam, kilometrosIngresados);
	precioBitcoinLatam = CalcularBitcoin(precioLatam, valorDeBitcoin);

	//Calculo la diferencia de precio entre las dos aerolíneas.
	diferenciaDePrecios = CalcularDiferencia(precioAerolineas, precioLatam);

	//Invoco a la funcion para mostrar los datos calculados.
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
