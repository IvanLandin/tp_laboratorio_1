#include "parser.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char idStr[10];
	char nombreStr[50];
	char apellidoStr[50];
	char tipoPasajeroStr[10];
	char precioStr[10];
	char codigoVueloStr[8];
	char flightStatusStr[20];
	int r;
	int retorno;
	Passenger* unPasajero;

	retorno = 0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		while(!feof(pFile))
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, flightStatusStr);
			if(r==7)
			{
				unPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, tipoPasajeroStr, precioStr, codigoVueloStr, flightStatusStr);
				if(unPasajero!=NULL)
				{
					if(ll_add(pArrayListPassenger, (Passenger*) unPasajero) == 0)
					{
						retorno = 1;
					}
				}
				else
				{
					retorno = 0;
					printf("Ocurrio un error al cargar los pasajeros.\n");
					break;
				}
			}
			else
			{
				retorno = 0;
				printf("Ocurrio un error al cargar los pasajeros.\n");
				break;
			}
		}
	}

    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* unPasajero;
	Passenger auxPasajero;
	char idStr[10];
	char nombreStr[50];
	char apellidoStr[50];
	char tipoPasajeroStr[10];
	char precioStr[10];
	char codigoVueloStr[8];
	char flightStatusStr[20];

	retorno = 0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		while(fread(&auxPasajero, sizeof(Passenger), 1, pFile) != 0)
		{
			itoa(auxPasajero.id, idStr, 10);
			strcpy(nombreStr, auxPasajero.nombre);
			strcpy(apellidoStr, auxPasajero.apellido);
			gcvt(auxPasajero.precio, 10, precioStr);
			itoa(auxPasajero.tipoPasajero, tipoPasajeroStr, 10);
			strcpy(codigoVueloStr, auxPasajero.codigoVuelo);
			strcpy(flightStatusStr, auxPasajero.statusFlight);

			unPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, tipoPasajeroStr, precioStr, codigoVueloStr, flightStatusStr);

			if(unPasajero!=NULL)
			{
				if(!ll_add(pArrayListPassenger, (Passenger*) unPasajero))
				{
					retorno = 1;
				}
				else
				{
					retorno = 0;
					printf("Ocurrio un error al cargar los pasajeros.\n");
					break;
				}
			}
			else
			{
				retorno = 0;
				printf("Ocurrio un error al cargar los pasajeros.\n");
				break;
			}
		}
	}

	return retorno;
}

int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero=NULL;
	Passenger unPasajeroAux;
	int lenLista;
	int retorno = 0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		lenLista = ll_len(pArrayListPassenger);
		for(int i=0; i<lenLista; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(!Passenger_GetData(unPasajero, &unPasajeroAux.id, unPasajeroAux.nombre, unPasajeroAux.apellido, &unPasajeroAux.tipoPasajero, &unPasajeroAux.precio, unPasajeroAux.codigoVuelo, unPasajeroAux.statusFlight))
			{
				printf("\nOcurrio un error al guardar la lista de pasajeros.\n\n");
				retorno = 0;
				break;
			}
			fprintf(pFile, "%d,%s,%s,%f,%s,%d,%s\n", unPasajeroAux.id, unPasajeroAux.nombre, unPasajeroAux.apellido, unPasajeroAux.precio, unPasajeroAux.codigoVuelo, unPasajeroAux.tipoPasajero, unPasajeroAux.statusFlight);
			retorno = 1;
		}
	}

	return retorno;
}

int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero=NULL;
	int lenLista;
	int retorno = 0;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		lenLista = ll_len(pArrayListPassenger);
		for(int i=0; i<lenLista; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(!fwrite(unPasajero, sizeof(Passenger), 1, pFile))
			{
				printf("\nOcurrio un error al guardar la lista de pasajeros.\n\n");
				retorno = 0;
				break;
			}
			retorno = 1;
		}
	}

	return retorno;
}
