/*
 * menu.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Iván
 */
#include "menu.h"

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
							if(confirmarAccion("\nID encontrada. ¿Desea modificar el nombre del pasajero? (s/n): "))
							{
								modificarNombre(listPassenger, index);
							}
							retorno = 1;
						break;
						case 2:
							if(confirmarAccion("\nID encontrada. ¿Desea modificar el apellido del pasajero? (s/n): "))
							{
								modificarApellido(listPassenger, index);
							}
							retorno = 1;
						break;
						case 3:
							if(confirmarAccion("\nID encontrada. ¿Desea modificar el precio del vuelo? (s/n): "))
							{
								modificarPrecio(listPassenger, index);
							}
							retorno = 1;
						break;
						case 4:
							if(confirmarAccion("\nID encontrada. ¿Desea modificar el tipo de pasajero? (s/n): "))
							{
								modificarTipoPasajero(listPassenger, listTypePassenger, lenType, index);
							}
							retorno = 1;
						break;
						case 5:
							if(confirmarAccion("\nID encontrada. ¿Desea modificar el codigo del vuelo? (s/n): "))
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

int menuBaja(sPassenger* listPassenger, int lenPassenger)
{
	int retorno;
	int resultado;
	int id;
	int index;

	retorno = -1;

	resultado = utn_getNumero(&id, "\nIngrese una id: ", "Error, la id no puede ser negativa. ", 0, 9999999, 5);
	if(resultado == 0)
	{
		index = findPassengerById(listPassenger, lenPassenger, id);
		if(index != -1)
		{
			retorno = confirmarAccion("\nID encontrada. ¿Desea dar de baja al pasajero? (s/n): ");
			if(retorno == 1)
			{
				removePassenger(listPassenger, lenPassenger, id, index);
			}
		}
		else
		{
			printf("\nError. El ID ingresado no existe.\n");
		}
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

int confirmarAccion(char mensaje[])
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

int menuListar(sPassenger* listPassengers, int lenPassengers, sPassangerType* listType, int lenType, sFlightStatus* listFlightStatus, int lenStatus)
{
	int retorno;
	int resultado;
	int opcionSubMenu;
	int orden;

	retorno = -1;

	do
	{
		resultado = utn_getNumero(&opcionSubMenu, "\n1. Listado de pasajeros por apellido.\n2. Total y promedio de precios.\n3. Listado de los pasajeros por Código de vuelo.\n4. Salir.\nSeleccione una opcion: ",
								"\nError. Ingrese una opcion valida del menu:\n\n",
								1, 4, 10);
		if(resultado == 0)
		{
			switch(opcionSubMenu)
			{
				case 1:
					orden = menuDeOrden(listPassengers, lenPassengers, orden, listType, lenType);
					if(orden != -1)
					{
						sortPassengersByName(listPassengers, lenPassengers, orden, listType, lenType);
						retorno = 1;
					}
				break;
				case 2:
					listPassengersAbovePriceAverage(listPassengers, lenPassengers, listType, lenType);
					retorno = 1;
				break;
				case 3:
					orden = menuDeOrden();
					if(orden != -1)
					{
						sortPassengersByCode(listPassengers, lenPassengers, orden, listFlightStatus, lenStatus);
						retorno = 1;
					}
				break;
				case 4:
					printf("\nSALIENDO AL MENU PRINCIPAL...\n\n");
					retorno = 0;
				break;
			}

		}
	}while(opcionSubMenu != 4);

	return retorno;
}
