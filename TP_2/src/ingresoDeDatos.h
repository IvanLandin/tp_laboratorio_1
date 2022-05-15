#include <stdio.h>

/// \fn int PedirEntero(char[])
/// \brief Pide al usuario el ingreso de un n�mero entero.
/// \param char[] Es el mensaje que lee el usuario.
/// \return int La funci�n devuelve un n�mero entero.
int PedirEntero(char []);

/// \fn float PedirFlotante(char[])
/// \brief Pide al usuario el ingreso de un n�mero flotante.
/// \param char[] Es el mensaje que lee el usuario.
/// \return float La funci�n devuelve un n�mero flotante.
float PedirFlotante(char []);

/// \fn int ValidarEntero(int, char[], int, int)
/// \brief Valida que un n�mero entero se encuentre entre un rango de valores.
/// \param int Es el n�mero a validar.
/// \param char[] Es el mensaje de error que lee el usuario en caso de ingresar un n�mero no v�lido.
/// \param int Es el l�mite inferior del rango.
/// \param int Es el l�mite superior del rango.
/// \return int La funci�n devuelve un n�mero entero dentro del rango.
int ValidarEntero(int, char [], int, int);

/// \fn float ValidarFlotante(float, char[], int)
/// \brief Valida que un n�mero flotante se encuentre entre un rango de valores.
/// \param float Es el n�mero a validar.
/// \param char[] Es el mensaje de error que lee el usuario en caso de ingresar un n�mero no v�lido.
/// \param int Es el l�mite inferior del rango.
/// \return float La funci�n devuelve un n�mero flotante dentro del rango.
float ValidarFlotante(float, char [], int);
