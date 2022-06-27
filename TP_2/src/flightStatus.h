/*
 * flightStatus.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Iván
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef FLIGHTSTATUS_H_
#define FLIGHTSTATUS_H_

#define EMPTY 0
#define FULL 1

typedef struct
{
	char flightCode[10];
	int idStatus;
	char descripcionStatus[20];
	int isEmpty;
}sFlightStatus;

/// \fn int initFlightStatus(sFlightStatus*, int)
/// \brief Inicializa el array de tipo sFlightStatus para que su estado (isEmpty) sea EMPTY
/// \param list sFlightStatus*
/// \param len int
/// \return int Retrona -1 en caso de error, 0 en caso de exito
int initFlightStatus(sFlightStatus* list, int len);

/// \fn int addFlightCodeToArray(sFlightStatus*, int, char*)
/// \brief Agrega los codigo de vuelo generados por el usuario al array de tipo sFlighStatus*
/// \param listFlightStatus sFlightStatus*
/// \param lenFlightStatus int
/// \param flightCodeIngresado char*
/// \return int Retrona -1 en caso de error, 0 en caso de exito
int addFlightCodeToArray(sFlightStatus* listFlightStatus, int lenFlightStatus, char* flightCodeIngresado);

/// \fn int agregarCargaForzadaArray(sFlightStatus*)
/// \brief Agrega los codigos de vuelo generados en carga forzada al array de tipo sFlightStatus*
/// \param listaDeFlightCodes sFlightStatus*
/// \return int Retrona 0 en caso de error, 1 en caso de exito y -1 si la lista es NULL
int agregarCargaForzadaArray(sFlightStatus* listaDeFlightCodes);

#endif /* FLIGHTSTATUS_H_ */
