/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "procesoDeStrings.h"
#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	char statusFlight[15];
}Passenger;

/// \fn Passenger Passenger_new*()
/// \brief Asigna espacio en memoria a un puntero del tipo Passenger
/// \return Retorna el puntero a Passenger
Passenger* Passenger_new();

/// \fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*)
/// \brief Asigna Los datos recibidos por parametros, convirtiendolos al tipo adecuado en caso de ser necesario, al Passenger de la lista dinamica
/// \param idStr char*
/// \param nombreStr char*
/// \param apellidoStr char*
/// \param tipoPasajeroStr char*
/// \param precioStr char*
/// \param codigoVueloStr char*
/// \param statusFlightStr char*
/// \return Passenger* Retorna un puntero a Passenger
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* precioStr, char* codigoVueloStr, char* statusFlightStr);

/// \fn void Passenger_delete(Passenger*)
/// \brief Libera el espacio en memoria señalado y apunta el puntero a NULL
/// \param pasajero Passenger*
void Passenger_delete(Passenger* pasajero);

/*****************************************************************************************************************************************************************************/

/// \fn int Passenger_setId(Passenger*, int)
/// \brief Asigna el numero id al campo correspondiente del elemento tipo Passenger
/// \param this Passenger*
/// \param id int
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setId(Passenger* this,int id);

/// \fn int Passenger_getId(Passenger*, int*)
/// \brief Obtiene el dato del campo id del elemento de tipo Passenger
/// \param this Passenger*
/// \param id int*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getId(Passenger* this,int* id);

/// \fn int Passenger_setNombre(Passenger*, char*)
/// \brief Asigna una cadena de caracteres al campo nombre del elemento de tipo Passenger
/// \param this Passenger*
/// \param nombre char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setNombre(Passenger* this,char* nombre);

/// \fn int Passenger_getNombre(Passenger*, char*)
/// \brief Obtiene el dato del campo nombre del elemento de tipo Passenger
/// \param this Passenger*
/// \param nombre char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getNombre(Passenger* this,char* nombre);

/// \fn int Passenger_setApellido(Passenger*, char*)
/// \brief Asigna una cadena de caracteres al campo apellido del elemento de tipo Passenger
/// \param this Passenger*
/// \param apellido char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setApellido(Passenger* this,char* apellido);

/// \fn int Passenger_getApellido(Passenger*, char*)
/// \brief Obtiene el dato del campo apellido del elemento de tipo Passenger
/// \param this Passenger*
/// \param apellido char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getApellido(Passenger* this,char* apellido);

/// \fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// \brief Asigna una cadena de caracteres al campo codigoVuelo del elemento de tipo Passenger
/// \param this Passenger*
/// \param codigoVuelo char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// \fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// \brief Obtiene el dato del campo codigoVuelo del elemento de tipo Passenger
/// \param this Passenger*
/// \param codigoVuelo char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// \fn int Passenger_setTipoPasajero(Passenger*, int)
/// \brief Asigna una cadena de caracteres al campo tipoPasajero del elemento de tipo Passenger
/// \param this Passenger*
/// \param tipoPasajero int
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// \fn int Passenger_getTipoPasajero(Passenger*, int*)
/// \brief Obtiene el dato del campo tipoPasajero del elemento de tipo Passenger
/// \param this Passenger*
/// \param tipoPasajero int*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// \fn int Passenger_setPrecio(Passenger*, float)
/// \brief Asigna una cadena de caracteres al campo precio del elemento de tipo Passenger
/// \param this Passenger*
/// \param precio float
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setPrecio(Passenger* this,float precio);

/// \fn int Passenger_getPrecio(Passenger*, float*)
/// \brief  Obtiene el dato del campo precio del elemento de tipo Passenger
/// \param this Passenger*
/// \param precio float*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getPrecio(Passenger* this,float* precio);

/// \fn int Passenger_setStatusFlight(Passenger*, char*)
/// \brief Asigna una cadena de caracteres al campo statusFlight del elemento de tipo Passenger
/// \param this Passenger*
/// \param statusFlight char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_setStatusFlight(Passenger* this, char* statusFlight);

/// \fn int Passenger_getStatusFlight(Passenger*, char*)
/// \brief  Obtiene el dato del campo statusFlight del elemento de tipo Passenger
/// \param this Passenger*
/// \param statusFlight char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_getStatusFlight(Passenger* this, char* statusFlight);

/*****************************************************************************************************************************************************************************/

/// \fn int Passenger_CompareById(void*, void*)
/// \brief Compara dos numeros id
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna 1 para indicar que el primer valor es mayor que el segundo y -1 para indicar que el segundo es mayor que el primero
int Passenger_CompareById(void* passenger1, void* passenger2);

/// \fn int Passenger_CompareByName(void*, void*)
/// \brief Compara dos nombres
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna el valor de strcmp de ambas cadenas de caracteres
int Passenger_CompareByName(void* passenger1, void* passenger2);

/// \fn int Passenger_CompareByLastName(void*, void*)
/// \brief Compara dos apellidos
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna el valor de strcmp de ambas cadenas de caracteres
int Passenger_CompareByLastName(void* passenger1, void* passenger2);

/// \fn int Passenger_CompareByPrice(void*, void*)
/// \brief Compara dos valores de precio
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna 1 para indicar que el primer valor es mayor que el segundo y -1 para indicar que el segundo es mayor que el primero
int Passenger_CompareByPrice(void* passenger1, void* passenger2);

/// \fn int Passenger_CompareByFlightCode(void*, void*)
/// \brief Compara dos codigos de vuelo
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna el valor de strcmp de ambas cadenas de caracteres
int Passenger_CompareByFlightCode(void* passenger1, void* passenger2);

/// \fn int Passenger_CompareByPassengerType(void*, void*)
/// \brief Compara dos tipos de pasajeros
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna 1 para indicar que el primer valor es mayor que el segundo y -1 para indicar que el segundo es mayor que el primero
int Passenger_CompareByPassengerType(void* passenger1, void* passenger2);

/// \fn int Passenger_CompareByFlightStatus(void*, void*)
/// \brief Compara dos estados de vuelo
/// \param passenger1 void*
/// \param passenger2 void*
/// \return int Retorna el valor de strcmp de ambas cadenas de caracteres
int Passenger_CompareByFlightStatus(void* passenger1, void* passenger2);

/*****************************************************************************************************************************************************************************/

/// \fn int Passenger_PedirDatos(char*, char*, char*, char*, char*, char*, char*)
/// \brief Pide al usuario el ingreso de datos para completar la totalidad de campos del pasajero tipo Passenger
/// \param idStr char*
/// \param nombreStr char*
/// \param apellidoStr char*
/// \param tipoPasajeroStr char*
/// \param precioStr char*
/// \param codigoVueloStr char*
/// \param statusFlightStr char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_PedirDatos(char* idStr, char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* precioStr, char* codigoVueloStr, char* statusFlightStr);

/// \fn int Passenger_GetData(Passenger*, int*, char*, char*, int*, float*, char*, char*)
/// \brief Obtiene los datos de todos los campos del pasajero apuntado en la lista dinamica
/// \param unPasajero Passenger*
/// \param id int*
/// \param nombre char*
/// \param apellido char*
/// \param tipoPasajero int*
/// \param precio float*
/// \param codigoVuelo char*
/// \param flightStatus char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_GetData(Passenger* unPasajero, int* id, char* nombre, char* apellido, int* tipoPasajero, float* precio, char* codigoVuelo, char* flightStatus);

/// \fn int Passenger_ConversorTipoPasajero(int, char*)
/// \brief Convierte el numero ingresado de tipo de pasajero a una cadena de caracteres relacionada
/// \param tipoPasajero int
/// \param passengerType char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ConversorTipoPasajero(int tipoPasajero, char* passengerType);

/// \fn int Passenger_ListarUnPasajero(LinkedList*, int)
/// \brief Lista un pasajero de la lista dinamica
/// \param pArrayListPassenger LinkedList*
/// \param index int
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ListarUnPasajero(LinkedList* pArrayListPassenger, int index);

/*****************************************************************************************************************************************************************************/

/// \fn int Passenger_ModificarNombre(Passenger*)
/// \brief Modifica el campo nombre del pasajero apuntado
/// \param unPasajero Passenger*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ModificarNombre(Passenger* unPasajero);

/// \fn int Passenger_ModificarApellido(Passenger*)
/// \brief Modifica el campo apellido del pasajero apuntado
/// \param unPasajero Passenger*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ModificarApellido(Passenger* unPasajero);

/// \fn int Passenger_ModificarPrecio(Passenger*)
/// \brief Modifica el campo precio del pasajero apuntado
/// \param unPasajero Passenger*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ModificarPrecio(Passenger* unPasajero);

/// \fn int Passenger_ModificarTipoPasajero(Passenger*)
/// \brief Modifica el campo tipoPasajero del pasajero apuntado
/// \param unPasajero Passenger*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ModificarTipoPasajero(Passenger* unPasajero);

/// \fn int Passenger_ModificarCodigoVuelo(Passenger*)
/// \brief Modifica el campo codigoVuelo del pasajero apuntado
/// \param unPasajero Passenger*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ModificarCodigoVuelo(Passenger* unPasajero);

/// \fn int Passenger_ModificarFlightStatus(Passenger*)
/// \brief Modifica el campo statusFlight del pasajero apuntado
/// \param unPasajero Passenger*
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int Passenger_ModificarFlightStatus(Passenger* unPasajero);

#endif /* PASSENGER_H_ */
