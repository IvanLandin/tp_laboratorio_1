/*
 * menu.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Iván
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "passengerType.h"
#include "flightStatus.h"
#include "arrayPassenger.h"

#ifndef MENU_H_
#define MENU_H_

/// \fn int menuModificar(sPassenger*, int, sPassangerType*, int)
/// \brief Despliega un menu de opciones para que el usuario elija el campo a modificar de la estructura almacenada en la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param lenPassenger int
/// \param listTypePassenger sPassangerType*
/// \param lenType int
/// \return int Retorna 1 en caso de exito, 0 al salir al menu principal y -1 en caso de error
int menuModificar(sPassenger* listPassenger, int lenPassenger, sPassangerType* listTypePassenger, int lenType);

/// \fn int menuBaja(sPassenger*, int)
/// \brief Menu que maneja las bajas de pasajeros
/// \param listPassenger sPassenger*
/// \param lenPassenger int
/// \return int Retorna 1 en caso de exito, 0 al salir al menu principal y -1 en caso de error
int menuBaja(sPassenger* listPassenger, int lenPassenger);

/// \fn int menuDeOrden()
/// \brief Pide al usuario el ingreso de un numero que representa el orden ascendente (1) y descendente (2)
/// \return int Retorna 1 para orden ascendente, 0 para descendente y -1 al salir al menu principal
int menuDeOrden();

/// \fn int confirmarAccion(char[])
/// \brief Despliega un menu de opciones que pide la confirmacion del usuario para continuar con la accion
/// \param mensaje char[]
/// \return int Retorna 1 en caso de exito, 0 al salir al menu principal y -1 en caso de error
int confirmarAccion(char mensaje[]);

/// \fn int menuListar(sPassenger*, int, sPassangerType*, int, sFlightStatus*, int)
/// \brief Despliega un menu de opciones para que el usuario elija el metodo de ordenamiento e impresion de la lista de tipo sPassenger*
/// \param listPassengers sPassenger*
/// \param lenPassengers int
/// \param listType sPassangerType*
/// \param lenType int
/// \param listFlightStatus sFlightStatus*
/// \param lenStatus int
/// \return int Retorna 1 en caso de exito, 0 al salir al menu principal y -1 en caso de error
int menuListar(sPassenger* listPassengers, int lenPassengers, sPassangerType* listType, int lenType, sFlightStatus* listFlightStatus, int lenStatus);

#endif /* MENU_H_ */
