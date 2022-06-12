/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* pasajero = NULL;
	pasajero = (Passenger*) calloc(sizeof(Passenger), 1);
	return pasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* precioStr, char* codigoVueloStr, char* statusFlightStr)
{
	Passenger* pasajero = NULL;
	int id;
	int tipoPasajero;
	float precio;
	int r=0;

	pasajero = Passenger_new();
	if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && tipoPasajeroStr!=NULL && precioStr!= NULL && codigoVueloStr != NULL && statusFlightStr != NULL)
	{
		id = atoi(idStr);
		r += Passenger_setId(pasajero, id);
		r += Passenger_setNombre(pasajero, nombreStr);
		r += Passenger_setApellido(pasajero, apellidoStr);
		tipoPasajero = atoi(tipoPasajeroStr);
		r += Passenger_setTipoPasajero(pasajero, tipoPasajero);
		precio = atof(precioStr);
		r += Passenger_setPrecio(pasajero, precio);
		r += Passenger_setCodigoVuelo(pasajero, codigoVueloStr);
		r += Passenger_setStatusFlight(pasajero, statusFlightStr);

		if(r!=7)
		{
			Passenger_delete(pasajero);
		}
	}

	return pasajero;
}

void Passenger_delete(Passenger* pasajero)
{
	if(pasajero != NULL)
	{
		free(pasajero);
		pasajero = NULL;
	}
}

int Passenger_setId(Passenger* this, int id)
{
	int retorno;
	retorno = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getId(Passenger* this, int* id)
{
	int retorno;
	retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this, char* nombre)
{
	int retorno;
	retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this, char* nombre)
{
	int retorno;
	retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this, char* apellido)
{
	int retorno;
	retorno = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno;
	retorno = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno;
	retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this, char* codigoVuelo)
{
	int retorno;
	retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this, int tipoPasajero)
{
	int retorno;
	retorno = 0;
	if(this != NULL && tipoPasajero != 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this, int* tipoPasajero)
{
	int retorno;
	retorno = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno;
	retorno = 0;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno;
	retorno = 0;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setStatusFlight(Passenger* this, char* statusFlight)
{
	int retorno;
	retorno = 0;
	if(this != NULL && statusFlight != NULL)
	{
		strcpy(this->statusFlight, statusFlight);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getStatusFlight(Passenger* this, char* statusFlight)
{
	int retorno;
	retorno = 0;
	if(this != NULL && statusFlight != NULL)
	{
		strcpy(statusFlight, this->statusFlight);
		retorno = 1;
	}
	return retorno;
}

int Passenger_CompareById(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	int id1;
	int id2;
	int retorno = 0;
	int comparacion;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getId(pasajero1, &id1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getId(pasajero2, &id2);
		if(retorno == 2)
		{
			if(id1>id2)
			{
				comparacion = 1;
			}
			else
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}

int Passenger_CompareByName(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	char nombre1[50];
	char nombre2[50];
	int comparacion;
	int retorno = 0;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getNombre(pasajero1, nombre1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getNombre(pasajero2, nombre2);
		if(retorno == 2)
		{
			comparacion = strcmp(nombre1, nombre2);
		}
	}

	return comparacion;
}

int Passenger_CompareByLastName(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	char apellido1[50];
	char apellido2[50];
	int comparacion;
	int retorno = 0;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getApellido(pasajero1, apellido1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getApellido(pasajero2, apellido2);
		if(retorno == 2)
		{
			comparacion = strcmp(apellido1, apellido2);
		}
	}

	return comparacion;
}

int Passenger_CompareByPrice(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	float precio1;
	float precio2;
	int retorno = 0;
	int comparacion;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getPrecio(pasajero1, &precio1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getPrecio(pasajero2, &precio2);
		if(retorno == 2)
		{
			if(precio1>precio2)
			{
				comparacion = 1;
			}
			else
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}

int Passenger_CompareByFlightCode(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	char flightCode1[50];
	char flightCode2[50];
	int comparacion;
	int retorno = 0;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getCodigoVuelo(pasajero1, flightCode1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getCodigoVuelo(pasajero2, flightCode2);
		if(retorno == 2)
		{
			comparacion = strcmp(flightCode1, flightCode2);
		}
	}

	return comparacion;
}

int Passenger_CompareByPassengerType(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	int passengerType1;
	int passengerType2;
	int retorno = 0;
	int comparacion;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getTipoPasajero(pasajero1, &passengerType1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getTipoPasajero(pasajero2, &passengerType2);
		if(retorno == 2)
		{
			if(passengerType1>passengerType2)
			{
				comparacion = 1;
			}
			else
			{
				comparacion = -1;
			}
		}
	}

	return comparacion;
}

int Passenger_CompareByFlightStatus(void* passenger1, void* passenger2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	char flightStatus1[50];
	char flightStatus2[50];
	int comparacion;
	int retorno = 0;

	if(passenger1 != NULL && passenger2 != NULL)
	{
		pasajero1 = (Passenger*) passenger1;
		retorno += Passenger_getStatusFlight(pasajero1, flightStatus1);
		pasajero2 = (Passenger*) passenger2;
		retorno += Passenger_getStatusFlight(pasajero2, flightStatus2);
		if(retorno == 2)
		{
			comparacion = strcmp(flightStatus1, flightStatus2);
		}
	}

	return comparacion;
}

int Passenger_PedirDatos(char* idStr, char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* precioStr, char* codigoVueloStr, char* statusFlightStr)
{
	float precio;
	int tipoPasajero;
	int statusFlight;
	int retorno = 0;
	int r=0;

	if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && tipoPasajeroStr!=NULL && precioStr!=NULL && codigoVueloStr!=NULL && statusFlightStr!=NULL)
	{
		r += utn_getTexto(nombreStr, "\nIngrese el nombre del pasajero: ", "\nError. Por favor no ingrese numeros, signos de puntuacion, o mas de 50 caracteres. ", 1, 50);
		FormatearCadena(nombreStr);
		r += utn_getTexto(apellidoStr, "\nIngrese el apellido del pasajero: ", "\nError. Por favor no ingrese numeros, signos de puntuacion, o mas de 50 caracteres. ", 1, 50);
		FormatearCadena(apellidoStr);
		r += utn_getNumeroDecimal(&precio, "\nIngrese el precio del vuelo: ", "\nError. El precio no puede ser menor a 100 o mayor a 50000", 100.00, 50000.00, 5);
		gcvt(precio, 10, precioStr);
		r += utn_getAlfaNumerico(codigoVueloStr, "\nIngrese un codigo de vuelo: ", "\nError. El codigo de vuelo debe estar compuesto de 7 caracteres alfanumericos. ", 7, 7);
		strupr(codigoVueloStr);
		r += utn_getNumero(&tipoPasajero, "\n1.Economy Class\n2.Executive Class\n3.First Class\nSeleccione el tipo de pasajero: ", "\nError. Seleccione un tipo de pasajero disponible. ", 1, 3, 5);
		itoa(tipoPasajero, tipoPasajeroStr, 10);
		r += utn_getNumero(&statusFlight, "\n1.En horario\n2.En vuelo\n3.Demorado\n4.Aterrizado\nSeleccione el estado del vuelo: ", "\nError. Seleccione un estado de vuelo disponible. ", 1, 4, 5);
		switch(statusFlight)
		{
			case 1:
				strcpy(statusFlightStr, "En horario");
			break;
			case 2:
				strcpy(statusFlightStr, "En vuelo");
			break;
			case 3:
				strcpy(statusFlightStr, "Demorado");
			break;
			case 4:
				strcpy(statusFlightStr, "Aterrizado");
			break;
		}

		if(r==0)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_GetData(Passenger* unPasajero, int* id, char* nombre, char* apellido, int* tipoPasajero, float* precio, char* codigoVuelo, char* flightStatus)
{
	int retorno = 0;
	int r = 0;

	if(unPasajero!=NULL && id!=NULL &&  nombre!=NULL && apellido!=NULL && tipoPasajero!=NULL && precio!=NULL && codigoVuelo!=NULL && flightStatus!=NULL)
	{
		r += Passenger_getId(unPasajero, id);
		r += Passenger_getNombre(unPasajero, nombre);
		r += Passenger_getApellido(unPasajero, apellido);
		r += Passenger_getPrecio(unPasajero, precio);
		r += Passenger_getTipoPasajero(unPasajero, tipoPasajero);
		r += Passenger_getCodigoVuelo(unPasajero, codigoVuelo);
		r += Passenger_getStatusFlight(unPasajero, flightStatus);
		if(r==7)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int Passenger_ConversorTipoPasajero(int tipoPasajero, char* passengerType)
{
	int retorno = 0;

	if(passengerType!=NULL)
	{
		switch(tipoPasajero)
		{
			case 1:
				strcpy(passengerType, "Economy Class");
			break;
			case 2:
				strcpy(passengerType, "Executive Class");
			break;
			case 3:
				strcpy(passengerType, "First Class");
			break;
		}
		retorno = 1;
	}

	return retorno;
}

int Passenger_ListarUnPasajero(LinkedList* pArrayListPassenger, int index)
{
	int retorno = 0;
	Passenger* unPasajero=NULL;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char flightStatus[15];
	char passengerType[20];

	if(pArrayListPassenger!=NULL && index>=0)
	{
		unPasajero = (Passenger*)ll_get(pArrayListPassenger, index);
		if(unPasajero!=NULL)
		{
			if(Passenger_GetData(unPasajero, &id, nombre, apellido, &tipoPasajero, &precio, codigoVuelo, flightStatus))
			{
				Passenger_ConversorTipoPasajero(tipoPasajero, passengerType);
				printf("%-4d| %-13s| %-14s| %-9.2f| %-17s| %-8s| %-11s |\n", id, nombre, apellido, precio, passengerType, codigoVuelo, flightStatus);
				retorno = 1;
			}
			else
			{
				printf("\nOcurrio un error al listar los pasajeros.\n\n");
			}

		}
	}

	return retorno;
}

int Passenger_ModificarNombre(Passenger* unPasajero)
{
	int retorno=0;
	char nombreStr[50];

	if(unPasajero!=NULL)
	{
		if(utn_getTexto(nombreStr, "\nIngrese el nombre del pasajero: ", "\nError. Por favor no ingrese numeros, signos de puntuacion, o mas de 50 caracteres. ", 1, 50)==0)
		{
			FormatearCadena(nombreStr);
			if(Passenger_setNombre(unPasajero, nombreStr))
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Passenger_ModificarApellido(Passenger* unPasajero)
{
	int retorno=0;
	char apellidoStr[50];

	if(unPasajero!=NULL)
	{
		if(utn_getTexto(apellidoStr, "\nIngrese el apellido del pasajero: ", "\nError. Por favor no ingrese numeros, signos de puntuacion, o mas de 50 caracteres. ", 1, 50)==0)
		{
			FormatearCadena(apellidoStr);
			if(Passenger_setApellido(unPasajero, apellidoStr))
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Passenger_ModificarPrecio(Passenger* unPasajero)
{
	int retorno=0;
	float precio;

	if(unPasajero!=NULL)
	{
		if(utn_getNumeroDecimal(&precio, "\nIngrese el precio del vuelo: ", "\nError. El precio no puede ser menor a 100 o mayor a 50000", 100.00, 50000.00, 5)==0)
		{
			if(Passenger_setPrecio(unPasajero, precio))
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Passenger_ModificarTipoPasajero(Passenger* unPasajero)
{
	int retorno = 0;
	int tipoPasajero;

	if(unPasajero!=NULL)
	{
		if( utn_getNumero(&tipoPasajero, "\n1.Economy Class\n2.Executive Class\n3.First Class\nSeleccione el tipo de pasajero: ", "\nError. Seleccione un tipo de pasajero disponible. ", 1, 3, 5)==0)
		{
			if(Passenger_setTipoPasajero(unPasajero, tipoPasajero))
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Passenger_ModificarCodigoVuelo(Passenger* unPasajero)
{
	int retorno = 0;
	char codigoVueloStr[8];

	if(unPasajero!=NULL)
	{
		if(utn_getAlfaNumerico(codigoVueloStr, "\nIngrese un codigo de vuelo: ", "\nError. El codigo de vuelo debe estar compuesto de 7 caracteres alfanumericos. ", 7, 7)==0)
		{
			strupr(codigoVueloStr);
			if(Passenger_setCodigoVuelo(unPasajero, codigoVueloStr))
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int Passenger_ModificarFlightStatus(Passenger* unPasajero)
{
	int retorno = 0;
	char statusFlightStr[20];
	int statusFlight;

	if(unPasajero!=NULL)
	{
		if(utn_getNumero(&statusFlight, "\n1.En horario\n2.En vuelo\n3.Demorado\n4.Aterrizado\nSeleccione el estado del vuelo: ", "\nError. Seleccione un estado de vuelo disponible. ", 1, 4, 5)==0)
		{
			switch(statusFlight)
			{
				case 1:
					strcpy(statusFlightStr, "En horario");
				break;
				case 2:
					strcpy(statusFlightStr, "En vuelo");
				break;
				case 3:
					strcpy(statusFlightStr, "Demorado");
				break;
				case 4:
					strcpy(statusFlightStr, "Aterrizado");
				break;
			}
			if(Passenger_setStatusFlight(unPasajero, statusFlightStr))
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}
