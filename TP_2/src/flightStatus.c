/*
 * flightStatus.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Iván
 */
#include "flightStatus.h"

int initFlightStatus(sFlightStatus* list, int len)
{
	int retorno;
	int i;
	i=0;
	retorno = -1;

	if(list != NULL)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}

int addFlightCodeToArray(sFlightStatus* listFlightStatus, int lenFlightStatus, char* flightCodeIngresado)
{
	int retorno;
	int i;
	int idStatus;

	retorno = -1;

	if(listFlightStatus != NULL && flightCodeIngresado != NULL)
	{
		for(i=0; i<lenFlightStatus; i++)
		{
			if(strcmp(listFlightStatus[i].flightCode, flightCodeIngresado)==0)
			{
				break;
			}
			else
			{
				if(listFlightStatus[i].isEmpty == EMPTY)
				{
					strcpy(listFlightStatus[i].flightCode, flightCodeIngresado);
					do
					{
						idStatus = (rand() % (10100 - 10001 + 1)) + 10001;
					}while(idStatus<10001 && idStatus>10100);
					listFlightStatus[i].idStatus = idStatus;

					if(idStatus<10034 && idStatus>10000)
					{
						strcpy(listFlightStatus[i].descripcionStatus, "Activo");
					}
					else
					{
						if(idStatus<10067 && idStatus>10033)
						{
							strcpy(listFlightStatus[i].descripcionStatus, "Demorado");
						}
						else
						{
							strcpy(listFlightStatus[i].descripcionStatus, "Cancelado");
						}
					}
					listFlightStatus[i].isEmpty = FULL;
					retorno = 0;
					break;
				}
			}

		}
	}

	return retorno;
}

int agregarCargaForzadaArray(sFlightStatus* listaDeFlightCodes)
{
	sFlightStatus auxListaDeFlightCodes [4] = {{"G56PI", 10001, "Activo", FULL}, {"54D6A", 10001, "Activo", FULL}, {"DQW54", 10069, "Demorado", FULL}, {"TYE49", 10099, "Cancelado", FULL}};
	int retorno = -1;

	if(listaDeFlightCodes!=NULL)
	{
		retorno = 0;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				if(listaDeFlightCodes[j].isEmpty == EMPTY)
				{
					listaDeFlightCodes[j] = auxListaDeFlightCodes[i];
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}
