#include <stdio.h>

/// \fn float CalcularDebitoCredito(float, int)
/// \brief La función calcula aumentos o descuentos, dependiendo del signo del número ingresado en el porcentaje.
/// \param float Es el número a modificar en la operación.
/// \param int Es el número del porcentaje. Si el número ingresado es negativo, se va a hacer un descuento sobre el total; de lo contrario, se realizará un aumento.
/// \return float La función devuelve el resultado de la operación de aumento o descuento, según el caso.
float CalcularDebitoCredito(float, int);

/// \fn float CalcularBitcoin(float, float)
/// \brief Realiza la conversión del tipo de moneda inicial a bitcoins.
/// \param float Es el precio en la moneda ingresada por el usuario.
/// \param float Es el precio actual de un Bitcoin.
/// \return float La función devuelve el equivalente en Bitcoins del precio ingresado.
float CalcularBitcoin(float, float);

/// \fn float CalcularPrecioUnitario(float, int)
/// \brief La función calcula el precio unitario (por kilometro) del vuelo.
/// \param float Es el precio ingresado por el usuario.
/// \param int Son los kilometros ingresados por el usuario.
/// \return float La función devuelve el resultado de una división entre el precio ingresado y los kilometros ingresados.
float CalcularPrecioUnitario(float, int);

/// \fn float CalcularDiferencia(float, float)
/// \brief La función calcula la diferencia de dos precios ingresados por el usuario.
/// \param float Es el primer precio ingresado por el usuario.
/// \param float Es el segundo precio ingresado por el usuario.
/// \return float La función devuelve el resultado de la resta entre ambos precios.
float CalcularDiferencia(float, float);
