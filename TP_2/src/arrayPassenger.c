#include "arrayPassenger.h"

int initPassengers(sPassenger* list, int len)
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

/// \fn int obtenerId()
/// \brief Genere numeros id no reutilizables
/// \return Retorna el id generado
static int obtenerId();
static int obtenerId()
{
	static int idIncremental = 1000;
	return idIncremental++;
}

sPassenger ingresarPassenger(sPassenger* listPassenger, int lenPassenger, sPassangerType* listType, int lenType)
{
	sPassenger unPasajero;

	unPasajero.id = obtenerId(listPassenger, lenPassenger);
	fflush(stdin);
	utn_getTexto(unPasajero.name, "Ingrese el nombre del pasajero: ", "Error. Por favor, ingrese menos de 51 caracteres. ", 1, sizeof(unPasajero.name));
	FormatearCadena(unPasajero.name);
	fflush(stdin);
	utn_getTexto(unPasajero.lastName, "Ingrese el apellido del pasajero: ", "Error. Por favor, ingrese menos de 51 caracteres. ", 1, sizeof(unPasajero.lastName));
	FormatearCadena(unPasajero.lastName);
	utn_getNumeroDecimal(&unPasajero.price, "Ingrese el precio del vuelo: ", "Error. El precio no puede ser negativo, o mayor o igual a $10000000. ", 0.99, 9999999.99, 5);
	utn_getAlfaNumerico(unPasajero.flightCode, "Ingrese el codigo de vuelo: ", "Error. Por favor, ingrese menos de 10 caracteres. ", 1, 10);
	strupr(unPasajero.flightCode);
	fflush(stdin);
	listarPassengerTypes(listType, lenType);
	utn_getNumero(&unPasajero.idPassangerType, "\nIngrese el tipo de pasajero: ", "Error. Por favor, ingrese una clase valida. ", 1, 3, 5);

	return unPasajero;
}

int addPassengerToArray(sPassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flightCode[])
{
	int retorno;
	int index;
	retorno = -1;

	index = BuscarLibre(list, len);

	if(index != -1)
	{
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].idPassangerType = typePassenger;
		strcpy(list[index].flightCode, flightCode);
		list[index].isEmpty = FULL;

		retorno = 0;
	}

	return retorno;
}

int BuscarLibre(sPassenger* list, int len)
{
	int i;
	int index;
	index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == EMPTY)
		{
			index = i;
			break;
		}
	}

	return index;
}

int findPassengerById(sPassenger* list, int len, int idIngresado)
{
	int i;
	int index;

	index = -1;

	if(list != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FULL && list[i].id == idIngresado)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int removePassenger(sPassenger* list, int len, int id, int index)
{
	int retorno;

	retorno = -1;

	if(list[index].id == id)
	{
		list[index].isEmpty = EMPTY;
		retorno = 0;
	}

	return retorno;
}

int modificarNombre(sPassenger* listPassenger, int index)
{
	sPassenger auxiliarPassenger;
	int retorno;
	int resultado;
	retorno = 0;

	resultado = utn_getTexto(auxiliarPassenger.name, "Ingrese nuevamente el nombre del pasajero: ", "Error, el nombre solo puede ser alfabetico. ", 1, sizeof(auxiliarPassenger.name));
	if(resultado == 0)
	{
		FormatearCadena(auxiliarPassenger.name);
		strcpy(listPassenger[index].name, auxiliarPassenger.name);
		retorno = 1;
	}

	return retorno;
}

int modificarApellido(sPassenger* listPassenger, int index)
{
	sPassenger auxiliarPassenger;
	int retorno;
	int resultado;
	retorno = 0;

	resultado = utn_getTexto(auxiliarPassenger.lastName, "Ingrese nuevamente el apellido del pasajero: ", "Error, el nombre solo puede ser alfabetico. ", 1, sizeof(auxiliarPassenger.lastName));
	if(resultado == 0)
	{
		FormatearCadena(auxiliarPassenger.lastName);
		strcpy(listPassenger[index].lastName, auxiliarPassenger.lastName);
		retorno = 1;
	}

	return retorno;
}

int modificarPrecio(sPassenger* listPassenger, int index)
{
	sPassenger auxiliarPassenger;
	int retorno;
	int resultado;
	retorno = 0;

	fflush(stdin);
	resultado = utn_getNumeroDecimal(&auxiliarPassenger.price, "Ingrese nuevamente el precio del vuelo: ", "Error, el precio no puede ser menor a $1. ", 0.99, 9999999.99, 5);
	if(resultado == 0)
	{
		listPassenger[index].price = auxiliarPassenger.price;
		retorno = 1;
	}

	return retorno;
}

int modificarTipoPasajero(sPassenger* listPassenger, sPassangerType* listTypePassenger, int lenType, int index)
{
	sPassenger auxiliarPassenger;
	int retorno;
	int resultado;
	retorno = 0;

	fflush(stdin);
	listarPassengerTypes(listTypePassenger, lenType);
	resultado = utn_getNumero(&auxiliarPassenger.idPassangerType, "\nIngrese nuevamente el tipo de pasajero: ", "Error. Por favor, ingrese una clase valida. ", 1, 3, 5);
	if(resultado == 0)
	{
		listPassenger[index].idPassangerType = auxiliarPassenger.idPassangerType;
		retorno = 1;
	}

	return retorno;
}

int modificarflightCode(sPassenger* listPassenger, int index)
{
	sPassenger auxiliarPassenger;
	int retorno;
	int resultado;
	retorno = 0;

	fflush(stdin);
	resultado = utn_getAlfaNumerico(auxiliarPassenger.flightCode, "Ingrese nuevamente el codigo de vuelo: ", "Error. Por favor, ingrese menos de 10 caracteres. ", 1, 10);
	if(resultado == 0)
	{
		strupr(auxiliarPassenger.flightCode);
		strcpy(listPassenger[index].flightCode, auxiliarPassenger.flightCode);
		retorno = 1;
	}

	return retorno;
}

int sortPassengersByName(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType)
{
	//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero
	int retorno;
	retorno = -1;

	if(listPassenger != NULL && listType != NULL)
	{
		retorno = 0;
		ordenarAlfabeticamente(listPassenger, lenPassenger, order, listType, lenType);
		printf("\nPasajeros ordenados alfabeticamente:\n|  ID  |   APELLIDO    |    NOMBRE     |  PRECIO  |CODIGO VUELO| TIPO PASAJERO |\n|------|---------------|---------------|----------|------------|---------------|");

		for(int i=0; i<lenPassenger; i++)
		{
			for(int j=0; j<lenType; j++)
			{
				if(listPassenger[i].isEmpty == FULL && listPassenger[i].idPassangerType == listType[j].idPassangerType)
				{
					printf("\n|%-6d|%-15s|%-15s|$%-9.2f|%-12s|%-15s|", listPassenger[i].id,  listPassenger[i].lastName,  listPassenger[i].name,  listPassenger[i].price,  listPassenger[i].flightCode,  listType[j].descripcionPassangerType);
					retorno = 1;
					break;
				}
			}
		}
		printf("\n");
	}

	return retorno;
}

int ordenarAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType)
{
	int retorno = -1;
	char descripcionI [20];
	char descripcionJ [20];

	if(listPassenger!=NULL && listType!=NULL)
	{
		retorno = 0;

		for(int i=0; i<lenPassenger-1; i++)
		{
			for(int j=i+1; j<lenPassenger; j++)
			{
				switch(order)
				{
					case 0:
						if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)<0)
						{
							swap(listPassenger, i, j);
							retorno = 1;
							break;
						}
					break;
					case 1:
						if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)>0)
						{
							swap(listPassenger, i, j);
							retorno = 1;
							break;
						}
					break;
				}

				if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)==0)
				{
					compararTipoDePasajero(listPassenger, listType, lenType, i, descripcionI);
					compararTipoDePasajero(listPassenger, listType, lenType, j, descripcionJ);

					switch(order)
					{
						case 0:
							if(strcmp(descripcionI, descripcionJ)<0)
							{
								swap(listPassenger, i, j);
								retorno = 1;
								break;
							}
						break;
						case 1:
							if(strcmp(descripcionI, descripcionJ)>0)
							{
								swap(listPassenger, i, j);
								retorno = 1;
								break;
							}
						break;
					}
				}
			}
		}
	}

	return retorno;
}

int swap(sPassenger* listPassenger, int indexI, int indexJ)
{
	sPassenger auxiligarPassenger;
	int retorno = 0;

	if(listPassenger!=NULL)
	{
		auxiligarPassenger = listPassenger[indexI];
		listPassenger[indexI] = listPassenger[indexJ];
		listPassenger[indexJ] = auxiligarPassenger;

		retorno = 1;
	}

	return retorno;
}

int compararTipoDePasajero(sPassenger* listPassenger, sPassangerType* listType, int lenType, int index, char* pDescripcion)
{
	int i;
	int retorno;

	retorno = 0;

	for(i=0; i<lenType; i++)
	{
		if(listPassenger[index].idPassangerType == listType[i].idPassangerType)
		{
			strcpy(pDescripcion, listType[i].descripcionPassangerType);
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int listPassengersAbovePriceAverage(sPassenger* list, int length, sPassangerType* listType, int lenType)
{
	int retorno = -1;
	float promedioPrecios;
	float totalPrecios;

	if(list!=NULL && listType!=NULL)
	{
		retorno = 0;
		calcularPromedioPrecios(list, length, &promedioPrecios, &totalPrecios);

		printf("\nEl acumulado de los precios es: $%.2f\nEl promedio de precios es: $%.2f\nSuperan el promedio:\n|  ID  |   APELLIDO    |    NOMBRE     |  PRECIO  |CODIGO VUELO| TIPO PASAJERO |\n|------|---------------|---------------|----------|------------|---------------|", totalPrecios, promedioPrecios);

		for(int i=0; i<length; i++)
		{
			for(int j=0; j<lenType; j++)
			{
				if(list[i].price >= promedioPrecios && list[i].idPassangerType == listType[j].idPassangerType)
				{
					printf("\n|%-6d|%-15s|%-15s|$%-9.2f|%-12s|%-15s|", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].flightCode, listType[j].descripcionPassangerType);
					retorno = 1;
					break;
				}
			}
		}
		printf("\n");
	}

	return retorno;
}

int calcularPromedioPrecios(sPassenger* list, int length, float* promedioPrecio, float* totalPrecios)
{
	int contadorPasajeros;
	float acumuladorPrecio;
	int retorno = -1;

	if(list!=NULL)
	{
		retorno = 0;
		contadorPasajeros = 0;
		acumuladorPrecio = 0;

		for(int i=0; i<length; i++)
		{
			if(list[i].isEmpty == FULL)
			{
				contadorPasajeros++;
				acumuladorPrecio += list[i].price;
				retorno = 1;
			}
		}
		*totalPrecios = acumuladorPrecio;
		*promedioPrecio = acumuladorPrecio / (float)contadorPasajeros;
	}

	return retorno;
}

int sortPassengersByCode(sPassenger* list, int len, int order, sFlightStatus* listStatus, int lenStatus)
{
	//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
	int retorno;
	retorno = -1;

	if(list != NULL && listStatus != NULL)
	{
		retorno = 0;
		ordenarCogidosAlfabeticamente(list, len, order);

		printf("\nCodigos de vuelo ordenados alfabeticamente. Solo pasajeros en vuelos activos:\n|  ID  |CODIGO VUELO|   APELLIDO    |    NOMBRE     |  PRECIO  |ESTADO VUELO|\n|------|------------|---------------|---------------|----------|------------|");

		for(int i=0; i<len; i++)
		{
			for(int j=0; j<lenStatus; j++)
			{
				if(list[i].isEmpty == FULL && strcmp(list[i].flightCode, listStatus[j].flightCode)==0 && strcmp(listStatus[j].descripcionStatus, "Activo")==0)
				{
					printf("\n|%-6d|%-12s|%-15s|%-15s|$%-9.2f|%-12s|", list[i].id, list[i].flightCode, list[i].lastName, list[i].name, list[i].price, listStatus[j].descripcionStatus);
					retorno = 1;
					break;
				}
			}
		}
		printf("\n");
	}

	return retorno;
}

int ordenarCogidosAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order)
{
	int i;
	int j;
	int retorno;

	retorno = 0;

	for(i=0; i<lenPassenger-1; i++)
	{
		for(j=i+1; j<lenPassenger; j++)
		{
			switch(order)
			{
				case 0:
					if(strcmp(listPassenger[i].flightCode, listPassenger[j].flightCode)<0)
					{
						swap(listPassenger, i, j);
						retorno = 1;
						break;
					}
				break;
				case 1:
					if(strcmp(listPassenger[i].flightCode, listPassenger[j].flightCode)>0)
					{
						swap(listPassenger, i, j);
						retorno = 1;
						break;
					}
				break;
			}
		}
	}

	return retorno;
}

int cargaForzada(sPassenger* listaDePasajeros, int len, sFlightStatus* listaDeFlightCodes)
{
	int retorno = -1;

	if(listaDePasajeros!=NULL && listaDeFlightCodes!=NULL)
	{
		retorno = 0;
		sPassenger auxListaDePasajeros[5] = {{obtenerId(), "Julieta", "Perez", 156.50, "G56PI", 3, FULL}, {obtenerId(), "Juan", "Gonzalez", 235.00, "54D6A", 2, FULL}, {obtenerId(), "Maria", "Maldonado", 451.00, "DQW54", 1, FULL}, {obtenerId(), "Julia", "Gomez", 109.25, "DQW54", 3, FULL}, {obtenerId(), "Romina", "Zapata", 189.30, "TYE49", 2, FULL}};

		for(int i=0; i<5; i++)
		{
			for(int j=0; j<len; j++)
			{
				if(listaDePasajeros[j].isEmpty == EMPTY)
				{
					listaDePasajeros[j] = auxListaDePasajeros[i];
					retorno = 1;
					break;
				}
			}
		}
	}

	agregarCargaForzadaArray(listaDeFlightCodes);

	return retorno;
}
