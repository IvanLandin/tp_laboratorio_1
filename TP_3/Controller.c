#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;

	retorno = 0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL && parser_PassengerFromText(pFile, pArrayListPassenger))
		{
			retorno = 1;
		}
		fclose(pFile);
	}

    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;

	retorno = 0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile!=NULL && parser_PassengerFromBinary(pFile, pArrayListPassenger))
		{
			retorno = 1;
		}
		fclose(pFile);
	}

	return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, int id)
{
	Passenger* unPasajero;
	char idStr[10];
	char nombreStr[50];
	char apellidoStr[50];
	char tipoPasajeroStr[10];
	char precioStr[10];
	char codigoVueloStr[8];
	char statusFlightStr[20];
	int retorno = 0;

	if(pArrayListPassenger!=NULL)
	{
		if(Passenger_PedirDatos(idStr, nombreStr, apellidoStr, tipoPasajeroStr, precioStr, codigoVueloStr, statusFlightStr) && id>1000)
		{
			itoa(id, idStr, 10);
			unPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, tipoPasajeroStr, precioStr, codigoVueloStr, statusFlightStr);
			if(unPasajero!=NULL)
			{
				if(ll_add(pArrayListPassenger, unPasajero) == 0)
				{
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero=NULL;
	int index;
	int len;
	int retorno = 0;
	char opcion;
	int option;

	len = ll_len(pArrayListPassenger);

	utn_getNumero(&index, "\nIngrese una posicion de la lista: ", "\nError. Por favor, ingrese una posicion valida de la lista (mayor a 0). ", 0, len-1, 5);

	if(index>=len || index<0)
	{
		printf("\nPosicion no valida de la lista. Volviendo al menu principal...");
	}
	else
	{
		do
		{
			if(utn_getCaracter(&opcion, "\nPosicion de la lista encontrada. Desea continuar con la modificacion?(s/n): ", "\nError. Por favor, ingrese una opcion valida(s/n). ", 5)==0)
			{
				fflush(stdin);
				switch(opcion)
				{
					case 's':
						unPasajero = (Passenger*) ll_get(pArrayListPassenger, index);
						if(utn_getNumero(&option, "\n1.Modificar nombre del pasajero.\n2.Modificar apellido del pasajero.\n3.Modificar precio del vuelo.\n4.Modificar codigo de vuelo.\n5.Modificar tipo de pasajero.\n6.Modificar estado del vuelo.\nSeleccione el campo a modificar: ", "\nError. Por favor, seleccione una opcion disponible. ", 1, 6, 10)==0)
						{
							switch(option)
							{
								case 1:
									Passenger_ModificarNombre(unPasajero);
								break;
								case 2:
									Passenger_ModificarApellido(unPasajero);
								break;
								case 3:
									Passenger_ModificarPrecio(unPasajero);
								break;
								case 4:
									Passenger_ModificarCodigoVuelo(unPasajero);
								break;
								case 5:
									Passenger_ModificarTipoPasajero(unPasajero);
								break;
								case 6:
									Passenger_ModificarFlightStatus(unPasajero);
								break;
							}
						}
						else
						{
							printf("\nNumero de intentos agotados. Intente nuevamente en breve. ");
						}
					break;
					case 'n':
						printf("\nModificacion cancelada. Volviendo al menu principal...");
					break;
				}
			}
			retorno = 1;
		}while(opcion!='s' && opcion!='n');
	}

	return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int index;
	int len;
	int retorno = 0;
	char opcion;

	len = ll_len(pArrayListPassenger);

	utn_getNumero(&index, "\nIngrese una posicion de la lista: ", "\nError. Por favor, ingrese una posicion valida de la lista (mayor a 0). ", 0, len-1, 5);

	if(index>=len || index<0)
	{
		printf("\nPosicion no valida de la lista. Volviendo al menu principal...");
	}
	else
	{
		do
		{
			Passenger_ListarUnPasajero(pArrayListPassenger, index);
			utn_getCaracter(&opcion, "\nPosicion de la lista encontrada. Desea continuar con la baja?(s/n): ", "\nError. Por favor, ingrese una opcion valida(s/n). ", 5);
			fflush(stdin);
			switch(opcion)
			{
				case 's':
					ll_remove(pArrayListPassenger, index);
				break;
				case 'n':
					printf("\nBaja cancelada. Volviendo al menu principal...");
				break;
			}
			retorno = 1;
		}while(opcion!='s' && opcion!='n');
	}

    return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{

	int retorno = 0;
	int lenLista;

	if(pArrayListPassenger!=NULL)
	{
		lenLista = ll_len(pArrayListPassenger);

		printf("ID  | Nombre       | Apellido      | Precio   | Tipo de pasajero | Codigo  | Estado      |\n----|--------------|---------------|----------|------------------|---------|-------------|\n");
		for(int i=0; i<lenLista; i++)
		{
			if(Passenger_ListarUnPasajero(pArrayListPassenger, i))
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}

    return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	LinkedList* copiaListPassenger;
	int opcion;
	int order;
	int retorno=0;

	if(pArrayListPassenger!=NULL)
	{
		copiaListPassenger = ll_clone(pArrayListPassenger);
		do
		{
			utn_getNumero(&opcion, "\n1. Ordenar por ID.\n2. Ordenar por nombre.\n3. Ordenar por apellido.\n4. Ordenar por precio.\n5. Ordenar por codigo de vuelo."
									"\n6. Ordenar por tipo de pasajero\n7. Ordenar por estado del vuelo.\n8. Salir al menu principal.\nElija una opcion: ",
									"Error. Por favor, ingrese una opcion disponible. ", 1, 8, 5);
			if(opcion!=8)
			{
				utn_getNumero(&order, "\n1. Orden ascendente.\n2. Orden descendente.\nElija el criterio de ordenamiento: ", "Error. Por favor, ingrese una opcion disponible.", 1, 2, 5);
				switch(order)
				{
					case 1:
						order = 1;
					break;
					case 2:
						order = 0;
					break;
				}
				printf("Ordenando los pasajeros... Aguarde, por favor.\n");
			}

			switch(opcion)
			{
				case 1:
					ll_sort(copiaListPassenger, Passenger_CompareById, order);
				break;
				case 2:
					ll_sort(copiaListPassenger, Passenger_CompareByName, order);
				break;
				case 3:
					ll_sort(copiaListPassenger, Passenger_CompareByLastName, order);
				break;
				case 4:
					ll_sort(copiaListPassenger, Passenger_CompareByPrice, order);
				break;
				case 5:
					ll_sort(copiaListPassenger, Passenger_CompareByFlightCode, order);
				break;
				case 6:
					ll_sort(copiaListPassenger, Passenger_CompareByPassengerType, order);
				break;
				case 7:
					ll_sort(copiaListPassenger, Passenger_CompareByFlightStatus, order);
				break;
				case 8:
					printf("\nSaliendo al menu principal...\n");
				break;
			}

			if(opcion!=8)
			{
				controller_ListPassenger(copiaListPassenger);
				retorno = 1;
			}

		}while(opcion!=8);
	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile=NULL;
	int retorno = 0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL && parser_PassengerToText(pFile, pArrayListPassenger))
		{
			retorno = 1;
		}
		fclose(pFile);
	}

	return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile=NULL;

	int retorno = 0;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{

		pFile = fopen(path, "wb");
		if(pFile!=NULL && parser_PassengerToBinary(pFile, pArrayListPassenger))
		{
			retorno = 1;
		}
		fclose(pFile);
	}

	return retorno;
}

int Controller_GenerarId(char* path)
{
	FILE* pFile;
	int id;
	char idStr[10];
	int lastId;

	if(path!=NULL)
	{
		pFile = fopen(path, "r");
		if(pFile!=NULL)
		{
			fscanf(pFile, "%s", idStr);
			lastId = atoi(idStr);
			lastId++;
			id = lastId;
		}
		fclose(pFile);
	}

	return id;
}

int Controller_GuardarLastId(char* path, int lastId)
{
	FILE* pFile;
	int retorno = 0;

	if(path!=NULL)
	{
		pFile = fopen(path, "w");
		if(pFile!=NULL)
		{
			fprintf(pFile, "%d", lastId);
			retorno = 1;
		}

		fclose(pFile);
	}
	return retorno;
}
