/*
 * passengerType.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Iván
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef PASSENGERTYPE_H_
#define PASSENGERTYPE_H_

typedef struct
{
	int idPassangerType;
	char descripcionPassangerType[20];
}sPassangerType;

/// \fn int listarPassengerTypes(sPassangerType*, int)
/// \brief Lista los tipos de pasajeros almacenados en el array de tipo sPassengerType
/// \param listType sPassangerType*
/// \param lenType int
/// \return int Retorna 0 en caso de exito y -1 si la lista es NULL
int listarPassengerTypes(sPassangerType* listType, int lenType);

#endif /* PASSENGERTYPE_H_ */
