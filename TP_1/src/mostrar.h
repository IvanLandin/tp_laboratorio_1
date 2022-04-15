#include <stdio.h>
#include <windows.h>

/// \fn int MostrarMenu(int, float, float)
/// \brief Muestra al usuario las opciones del menú por consola.
/// \param int Los kilometros ingresados por el usuario. Son mostrados en el menú.
/// \param float El primer precio ingresado por el usuario. Es mostrado en el menú.
/// \param float El segundo precio ingresado por el usuario. Es mostrado en el menú.
/// \return int La función devuelve el número entero asignado a la opción seleccionada por el usuario.
int MostrarMenu(int, float, float);

/// \fn void MostrarResultados(int, float, float, float, float, float, float, float, float, float, float, float)
/// \brief Muestra por consola los resultados de las operaciones calculadas previamente.
/// \param int Los kilometros ingresados por el usuario.
/// \param float Precio ingresado de la empresa Aerolineas Argentinas.
/// \param float Precio ingresado de la empresa Latam Airlines.
/// \param float Resultado del cálculo del metodo de pago "debito" de la empresa Aerolineas Argentinas.
/// \param float Resultado del cálculo del metodo de pago "credito" de la empresa Aerolineas Argentinas.
/// \param float Resultado del cálculo del metodo de pago "bitcoin" de la empresa Aerolineas Argentinas.
/// \param float Resultado del cálculo de precio unitario (precio del vuelo / kilometros ingresados) de la empresa Aerolineas Argentinas.
/// \param float Resultado del cálculo del metodo de pago "debito" de la empresa Latam Airlines.
/// \param float Resultado del cálculo del metodo de pago "credito" de la empresa Latam Airlines.
/// \param float Resultado del cálculo del metodo de pago "bitcoin" de la empresa Latam Airlines.
/// \param float Resultado del cálculo de precio unitario (precio del vuelo / kilometros ingresados) de la empresa Latam Airlines.
/// \param float Resultado de la diferencia de precios entre ambas empresas.
void MostrarResultados(int, float, float, float, float, float, float, float, float, float, float, float);
