#include <stdio.h>
#include <windows.h>

/// \fn int MostrarMenu()
/// \brief Muestra al usuario las opciones del men� por consola.
/// \return int La funci�n devuelve el n�mero entero asignado a la opci�n seleccionada por el usuario.
int MostrarMenu(char [], char [], char [], char [], char []);

/// \fn void MostrarResultados(int, float, float, float, float, float, float, float, float, float, float, float)
/// \brief Muestra por consola los resultados de las operaciones calculadas previamente.
/// \param int Los kilometros ingresados por el usuario.
/// \param float Precio ingresado de la empresa Aerolineas Argentinas.
/// \param float Precio ingresado de la empresa Latam Airlines.
/// \param float Resultado del c�lculo del metodo de pago "debito" de la empresa Aerolineas Argentinas.
/// \param float Resultado del c�lculo del metodo de pago "credito" de la empresa Aerolineas Argentinas.
/// \param float Resultado del c�lculo del metodo de pago "bitcoin" de la empresa Aerolineas Argentinas.
/// \param float Resultado del c�lculo de precio unitario (precio del vuelo / kilometros ingresados) de la empresa Aerolineas Argentinas.
/// \param float Resultado del c�lculo del metodo de pago "debito" de la empresa Latam Airlines.
/// \param float Resultado del c�lculo del metodo de pago "credito" de la empresa Latam Airlines.
/// \param float Resultado del c�lculo del metodo de pago "bitcoin" de la empresa Latam Airlines.
/// \param float Resultado del c�lculo de precio unitario (precio del vuelo / kilometros ingresados) de la empresa Latam Airlines.
/// \param float Resultado de la diferencia de precios entre ambas empresas.
void MostrarResultados(int, float, float, float, float, float, float, float, float, float, float, float);
