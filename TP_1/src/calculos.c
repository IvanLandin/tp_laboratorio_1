#include "calculos.h"

float CalcularDebitoCredito(float precioIngresado, int porcentaje)
{
	float modificador;
	float precioFinal;

	modificador = precioIngresado * porcentaje / 100;
	precioFinal = precioIngresado + modificador;

	return precioFinal;
}
float CalcularBitcoin(float precioIngresado, float valorDeBitcoin)
{
	float conversion;

	conversion = precioIngresado / valorDeBitcoin;

	return conversion;
}
float CalcularPrecioUnitario(float precioIngresado, int kilometrosIngresados)
{
	float precioUnitario;

	precioUnitario = precioIngresado / kilometrosIngresados;

	return precioUnitario;
}
float CalcularDiferencia(float precioIngresadoUno, float precioIngresadoDos)
{
	float diferencia;

	if(precioIngresadoUno > precioIngresadoDos)
	{
		diferencia = precioIngresadoUno - precioIngresadoDos;
	}
	else
	{
		diferencia = precioIngresadoDos - precioIngresadoUno;
	}

	return diferencia;
}
