/*
 * passengerType.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Iván
 */
#include "passengerType.h"

int listarPassengerTypes(sPassangerType* listType, int lenType)
{
	int retorno;
	retorno = -1;

	if(listType != NULL)
	{
		for(int i=0; i<lenType; i++)
		{
			printf("\n%d %-10s", listType[i].idPassangerType, listType[i].descripcionPassangerType);
		}
		retorno = 0;
	}

	return retorno;
}
