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

int obtenerId(sPassenger* list, int len)
{
	int i;
	int idIncremental;
	idIncremental = 1000;

	for(i=0; i<len; i++)
	{
		if(list[i].id == idIncremental || list[i].isEmpty == FULL)
		{
			idIncremental++;
		}
		else
		{
			break;
		}
	}

	return idIncremental;
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
			if(listFlightStatus[i].flightCode != flightCodeIngresado && listFlightStatus[i].isEmpty == EMPTY)
			{
				strcpy(listFlightStatus[i].flightCode, flightCodeIngresado);
				idStatus = (rand() % (10003 - 10001 + 1)) + 10001;
				listFlightStatus[i].idStatus = idStatus;
				switch(idStatus)
				{
					case 10001:
						strcpy(listFlightStatus[i].descripcionStatus, "Activo");
					break;
					case 10002:
						strcpy(listFlightStatus[i].descripcionStatus, "Demorado");
					break;
					case 10003:
						strcpy(listFlightStatus[i].descripcionStatus, "Cancelado");
					break;
				}
				listFlightStatus[i].isEmpty = FULL;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int menuBaja(sPassenger* listPassenger, int lenPassenger)
{
	int retorno;
	int resultado;
	int id;
	int index;
	char confirmacion;

	retorno = -1;

	resultado = utn_getNumero(&id, "\nIngrese una id: ", "Error, la id no puede ser negativa. ", 0, 9999999, 5);
	if(resultado == 0)
	{
		index = findPassengerById(listPassenger, lenPassenger, id);
		if(index != -1)
		{
			do
			{
				utn_getCaracter(&confirmacion, "Id encontrada. ¿Desea dar de baja al pasajero? (s/n): ", "Error. Responda s/n. ", 5);
				confirmacion = tolower(confirmacion);
				fflush(stdin);

				switch(confirmacion)
				{
					case 's':
						if(removePassenger(listPassenger, lenPassenger, id, index) == 0)
						{
							printf("Se ha dado de baja al pasajero. \n\n");
						}
					break;

					case 'n':
						printf("Saliendo al menu principal...\n\n");
					break;

					default:
						printf("Opcion no disponible. Por favor, seleccione s/n. ");
					break;
				}
			}while(confirmacion != 's' && confirmacion != 'n');
		}
		else
		{
			printf("\nError. El ID ingresado no existe.\n");
		}
	}

	return retorno;
}

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
	}

	return retorno;
}

int menuModificar(sPassenger* listPassenger, int lenPassenger, sPassangerType* listTypePassenger, int lenType)
{
	int retorno;
	int opcionSubMenu;
	int resultado;
	int index;
	int id;

	retorno = -1;

	resultado = utn_getNumero(&id, "\nIngrese una id: ", "Error, la id no puede ser negativa. ", 0, 9999999, 5);
	if(resultado == 0)
	{
		index = findPassengerById(listPassenger, lenPassenger, id);
		if(index != -1)
		{
			do
			{
				resultado = utn_getNumero(&opcionSubMenu, "1. MODIFICAR NOMBRE.\n2. MODIFICAR APELLIDO.\n3. MODIFICAR PRECIO.\n4. MODIFICAR TIPO DE PASAJERO.\n5. MODIFICAR CODIGO DE VUELO\n6. SALIR.\nSELECCIONE UNA OPCION: ",
											"\nERROR. INGRESE UNA OPCION DISPONIBLE DEL MENU...\n\n",
											1, 6, 10);
				if(resultado == 0)
				{
					switch(opcionSubMenu)
					{
						case 1:
							if(modificarPassenger(listPassenger, "\nID encontrada. ¿Desea modificar el nombre del pasajero? (s/n): "))
							{
								modificarNombre(listPassenger, index);
							}
							retorno = 1;
						break;
						case 2:
							if(modificarPassenger(listPassenger, "\nID encontrada. ¿Desea modificar el apellido del pasajero? (s/n): "))
							{
								modificarApellido(listPassenger, index);
							}
							retorno = 1;
						break;
						case 3:
							if(modificarPassenger(listPassenger, "\nID encontrada. ¿Desea modificar el precio del vuelo? (s/n): "))
							{
								modificarPrecio(listPassenger, index);
							}
							retorno = 1;
						break;
						case 4:
							if(modificarPassenger(listPassenger, "\nID encontrada. ¿Desea modificar el tipo de pasajero? (s/n): "))
							{
								modificarTipoPasajero(listPassenger, listTypePassenger, lenType, index);
							}
							retorno = 1;
						break;
						case 5:
							if(modificarPassenger(listPassenger, "\nID encontrada. ¿Desea modificar el codigo de vuelo? (s/n): "))
							{
								modificarflightCode(listPassenger, index);
							}
							retorno = 1;
						break;
						case 6:
							printf("\nSALIENDO AL MENU PRINCIPAL...\n");
							retorno = 0;
						break;
						default:
							printf("\nOPCION NO DISPONIBLE.\n");
						break;
					}
				}
			}while(opcionSubMenu != 6);
		}
	}

	return retorno;
}

int modificarPassenger(sPassenger* listPassenger, char mensaje[])
{
	int retorno;
	int resultado;
	char opcion;

	retorno = -1;

	fflush(stdin);
	do
	{
		resultado = utn_getCaracter(&opcion, mensaje, "Error, por favor ingrese s/n. ", 5);
		opcion = tolower(opcion);
		if(resultado == 0)
		{
			switch(opcion)
			{
				case 's':
					retorno = 1;
				break;
				case 'n':
					printf("Saliendo al menu principal...\n");
					retorno = 0;
				break;
				default:
					printf("Opcion no disponible. Por favor, seleccione s/n.\n");
				break;
			}
		}
	}while(opcion != 's' && opcion != 'n');

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

int menuDeOrden()
{
	int resultado;
	int orden;

	resultado = utn_getNumero(&orden, "\n1. Orden ascendente.\n2. Orden descendente.\n3. Salir al menu principal.\n¿En que orden desea listar los pasajeros?: ", "Error, por favor ingrese solo valores numericos. ", 1, 3, 5);
	if(resultado == 0)
	{
		switch(orden)
		{
			case 1:
				orden = 1;
			break;
			case 2:
				orden = 0;
			break;
			case 3:
				printf("Saliendo al menu principal...");
				orden = -1;
			break;
			default:
				printf("Error, por favor seleccione una de las opciones disponibles. ");
			break;
		}
	}

	return orden;
}

int sortPassengersByName(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType)
{
	//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero
	int retorno;
	int i;
	int j;
	retorno = 0;

	if(listPassenger != NULL && listType != NULL)
	{
		ordenarAlfabeticamente(listPassenger, lenPassenger, order, listType, lenType);

		for(i=0; i<lenPassenger; i++)
		{
			for(j=0; j<lenType; j++)
			{
				if(listPassenger[i].isEmpty == FULL && listPassenger[i].idPassangerType == listType[j].idPassangerType)
				{
					printf("%d %4s %4s %4.2f %s %s\n", listPassenger[i].id,  listPassenger[i].lastName,  listPassenger[i].name,  listPassenger[i].price,  listPassenger[i].flightCode,  listType[j].descripcionPassangerType);
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}

int ordenarAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType)
{
	int i;
	int j;
	int retorno;
	char descripcionI [20];
	char descripcionJ [20];

	retorno = 0;

	for(i=0; i<lenPassenger-1; i++)
	{
		for(j=i+1; j<lenPassenger; j++)
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

	return retorno;
}

int swap(sPassenger* listPassenger, int indexI, int indexJ)
{
	sPassenger auxiligarPassenger;

	auxiligarPassenger = listPassenger[indexI];
	listPassenger[indexI] = listPassenger[indexJ];
	listPassenger[indexJ] = auxiligarPassenger;

	return 0;
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
	//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio
	int retorno;
	float promedioPrecios;
	int i;
	int j;

	retorno = -1;

	calcularPromedioPrecios(list, length, &promedioPrecios);

	for(i=0; i<length; i++)
	{
		for(j=0; j<lenType; j++)
		{
			if(list[i].price >= promedioPrecios && list[i].idPassangerType == listType[j].idPassangerType)
			{
				printf("\n%d %s %s %.2f %s %s", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].flightCode, listType[j].descripcionPassangerType);
				break;
			}
		}
	}
	printf("\nEl promedio de precios es $%.2f\n\n", promedioPrecios);

	return retorno;
}

int calcularPromedioPrecios(sPassenger* list, int length, float* promedioPrecio)
{
	int i;
	int contadorPasajeros;
	float acumuladorPrecio;
	int retorno;

	retorno = 0;
	contadorPasajeros = 0;
	acumuladorPrecio = 0;

	for(i=0; i<length; i++)
	{
		if(list[i].isEmpty == FULL)
		{
			contadorPasajeros++;
			acumuladorPrecio += list[i].price;
			retorno = 1;
		}
	}

	*promedioPrecio = acumuladorPrecio / (float)contadorPasajeros;

	return retorno;
}

int sortPassengersByCode(sPassenger* list, int len, int order, sFlightStatus* listStatus, int lenStatus)
{
	//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
	int retorno;
	int i;
	int j;
	retorno = 0;

	if(list != NULL && listStatus != NULL)
	{
		ordenarCogidosAlfabeticamente(list, len, order);
		for(i=0; i<len; i++)
		{
			for(j=0; j<lenStatus; j++)
			{
				if(list[i].isEmpty == FULL && strcmp(list[i].flightCode, listStatus[j].flightCode) && strcmp(listStatus[j].descripcionStatus, "Activo"))
				{
					printf("\n%d %s %s %s %.2f %s\n", list[i].id, list[i].flightCode, list[i].lastName, list[i].name, list[i].price, listStatus[j].descripcionStatus);
					break;
				}
			}
		}
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

int menuListar(sPassenger* listPassengers, int lenPassengers, sPassangerType* listType, int lenType, sFlightStatus* listFlightStatus, int lenStatus)
{
	int retorno;
	int resultado;
	int opcionSubMenu;
	int orden;

	retorno = -1;

	do
	{
		resultado = utn_getNumero(&opcionSubMenu, "1. Listado de pasajeros por apellido.\n2. Total y promedio de precios.\n3. Listado de los pasajeros por Código de vuelo.\n4. Salir.\nSeleccione una opcion: ",
								"\nError. Ingrese una opcion valida del menu:\n\n",
								1, 4, 10);
		if(resultado == 0)
		{
			switch(opcionSubMenu)
			{
				case 1:
					//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero
					orden = menuDeOrden(listPassengers, lenPassengers, orden, listType, lenType);
					if(orden != -1)
					{
						sortPassengersByName(listPassengers, lenPassengers, orden, listType, lenType);
					}
				break;
				case 2:
					//Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio
					listPassengersAbovePriceAverage(listPassengers, lenPassengers, listType, lenType);
				break;
				case 3:
					//Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
					orden = menuDeOrden();
					if(orden != -1)
					{
						sortPassengersByCode(listPassengers, lenPassengers, orden, listFlightStatus, lenStatus);
					}
				break;
				case 4:
					printf("\nSALIENDO AL MENU PRINCIPAL...\n");
				break;
			}
			retorno = 1;
		}
	}while(opcionSubMenu != 4);

	return retorno;
}

int cargaForzada()
{
	sPassenger listaDePasajeros[2000] = {{1000, "Julieta", "Perez", 156.50, "G56PI", 3, FULL}, {1001, "Juan", "Gonzalez", 235.00, "54D6A", 2, FULL}, {1002, "Maria", "Maldonado", 451.00, "DQW54", 1, FULL}, {1003, "Julia", "Gomez", 109.25, "DQW54", 3, FULL}, {1004, "Romina", "Zapata", 189.30, "TYE49", 2, FULL}};
	sPassangerType listaTipoPasajeros[3] = {{1, "Primera Clase"}, {2, "Clase Ejecutiva"}, {3, "Clase Economica"}};
	sFlightStatus listaDeFlightCodes [2000] = {{"G56PI", 1, "Activo", FULL}, {"54D6A", 1, "Activo", FULL}, {"DQW54", 2, "Demorado", FULL}, {"TYE49", 3, "Cancelado", FULL}};
	int retorno;
	retorno = -1;

	menuListar(listaDePasajeros, 2000, listaTipoPasajeros, 3, listaDeFlightCodes, 2000);

	return retorno;
}
