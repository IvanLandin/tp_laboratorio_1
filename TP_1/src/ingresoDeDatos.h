#include <stdio.h>

/// \fn int PedirEntero(char[])
/// \brief Pide al usuario el ingreso de un número entero.
/// \param char[] Es el mensaje que lee el usuario.
/// \return int La función devuelve un número entero.
int PedirEntero(char []);

/// \fn float PedirFlotante(char[])
/// \brief Pide al usuario el ingreso de un número flotante.
/// \param char[] Es el mensaje que lee el usuario.
/// \return float La función devuelve un número flotante.
float PedirFlotante(char []);

/// \fn int ValidarEntero(int, char[], int, int)
/// \brief Valida que un número entero se encuentre entre un rango de valores.
/// \param int Es el número a validar.
/// \param char[] Es el mensaje de error que lee el usuario en caso de ingresar un número no válido.
/// \param int Es el límite inferior del rango.
/// \param int Es el límite superior del rango.
/// \return int La función devuelve un número entero dentro del rango.
int ValidarEntero(int, char [], int, int);

/// \fn float ValidarFlotante(float, char[], int)
/// \brief Valida que un número flotante se encuentre entre un rango de valores.
/// \param float Es el número a validar.
/// \param char[] Es el mensaje de error que lee el usuario en caso de ingresar un número no válido.
/// \param int Es el límite inferior del rango.
/// \return float La función devuelve un número flotante dentro del rango.
float ValidarFlotante(float, char [], int);
