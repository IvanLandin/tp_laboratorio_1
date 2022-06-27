#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "procesoDeStrings.h"
#include "passengerType.h"
#include "flightStatus.h"

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define EMPTY 0
#define FULL 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flightCode[10];
	int idPassangerType;
	int isEmpty;
}sPassenger;

/// \fn int initPassengers(sPassenger*, int)
/// \brief Incializa la lista de tipo sPassenger* para que el isEmpty de los datos que la componen sean EMPTY
/// \param sPassenger*
/// \param int
/// \return int Retorna 0 en caso de exito y -1 en caso de error
int initPassengers(sPassenger*, int);

/// \fn sPassenger ingresarPassenger(sPassenger*, int, sPassangerType*, int)
/// \brief Pide al usuario el ingreso de datos. Carga lo ingresado en los campos correspondientes en la estructura sPassenger
/// \param listPassenger sPassenger*
/// \param lenPassenger int
/// \param listType sPassangerType*
/// \param lenType int
/// \return Retorna Retorna un dato de tipo sPassenger con sus campos cargados
sPassenger ingresarPassenger(sPassenger* listPassenger, int lenPassenger, sPassangerType* listType, int lenType);

/// \fn int addPassengerToArray(sPassenger*, int, int, char[], char[], float, int, char[])
/// \brief Recibe los datos correspondientes a un pasajero y los guarda en una posicion de la lista de tipo sPassenger*
/// \param list sPassenger*
/// \param len int
/// \param id int
/// \param name char[]
/// \param lastName char[]
/// \param price float
/// \param typePassenger int
/// \param flightCode char[]
/// \return int Retorna 0 en caso de exito y -1 en caso de error
int addPassengerToArray(sPassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flightCode[]);

/// \fn int BuscarLibre(sPassenger*, int)
/// \brief Recorre la lista de tipo sPassenger* en busca de una posicion EMPTY
/// \param list sPassenger*
/// \param len int
/// \return int Retorna el indice de la lista en caso de exito y -1 en caso de error
int BuscarLibre(sPassenger* list, int len);

/// \fn int findPassengerById(sPassenger*, int, int)
/// \brief Busca a un pasajero recorriendo la lista y buscando la igualdad del campo id y el id ingresado por el usuario
/// \param list sPassenger*
/// \param len int
/// \param id int
/// \return int Retorna el indice de la lista en caso de exito y -1 en caso de error
int findPassengerById(sPassenger* list, int len,int idIngresado);

/// \fn int removePassenger(sPassenger*, int, int, int)
/// \brief Realiza una baja logica del dato si el campo id del indice de la lista ingresado por el usuario es igual al id ingresado por el usuario
/// \param list sPassenger*
/// \param len int
/// \param id int
/// \param index int
/// \return int Retorna 0 en caso de exito y -1 en caso de error
int removePassenger(sPassenger* list, int len, int id, int index);

/// \fn int modificarNombre(sPassenger*, int)
/// \brief Modifica el campo nombre del dato guardado en la posicion index de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param index int
/// \return int Retorna 1 en caso de exito y 0 en caso de error
int modificarNombre(sPassenger* listPassenger, int index);

/// \fn int modificarApellido(sPassenger*, int)
/// \brief Modifica el campo apellido del dato guardado en la posicion index de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param index int
/// \return int Retorna 1 en caso de exito y 0 en caso de error
int modificarApellido(sPassenger* listPassenger, int index);

/// \fn int modificarPrecio(sPassenger*, int)
/// \brief Modifica el campo precio del dato guardado en la posicion index de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param index int
/// \return int Retorna 1 en caso de exito y 0 en caso de error
int modificarPrecio(sPassenger* listPassenger, int index);

/// \fn int modificarTipoPasajero(sPassenger*, sPassangerType*, int, int)
/// \brief Modifica el campo tipo de pasajero del dato guardado en la posicion index de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param listTypePassenger sPassangerType*
/// \param lenType int
/// \param index int
/// \return int Retorna 1 en caso de exito y 0 en caso de error
int modificarTipoPasajero(sPassenger* listPassenger, sPassangerType* listTypePassenger, int lenType, int index);

/// \fn int modificarflightCode(sPassenger*, int)
/// \brief Modifica el campo codigo de vuelo del dato guardado en la posicion index de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param index int
/// \return int Retorna 1 en caso de exito y 0 en caso de error
int modificarflightCode(sPassenger* listPassenger, int index);

/// \fn int sortPassengersByName(sPassenger*, int, int, sPassangerType*, int)
/// \brief Lista los pasajeros de la lista de tipo sPassenger* por nombre alfabeticamente
/// \param listPassenger sPassenger*
/// \param lenPassenger int
/// \param order int
/// \param listType sPassangerType*
/// \param lenType int
/// \return int Retorna 1 en caso de exito, 0 en caso de error y -1 si la lista es NULL
int sortPassengersByName(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType);

/// \fn int ordenarAlfabeticamente(sPassenger*, int, int, sPassangerType*, int)
/// \brief Ordena los pasajeros de la lista de tipo sPassenger* por nombre alfabeticamente
/// \param listPassenger sPassenger*
/// \param lenPassenger int
/// \param order int
/// \param listType sPassangerType*
/// \param lenType int
/// \return int Retorna 1 en caso de exito, 0 en caso de error y -1 si la lista es NULL
int ordenarAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType);

/// \fn int swap(sPassenger*, int, int)
/// \brief Intercambia las posiciones de dos datos de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param indexI int
/// \param indexJ int
/// \return int Retorna 1 en caso de exito, 0 en caso de error
int swap(sPassenger* listPassenger, int indexI, int indexJ);

/// \fn int compararTipoDePasajero(sPassenger*, sPassangerType*, int, int, char*)
/// \brief Compara los campos tipo de pasajero de dos pasajeros de la lista de tipo sPassenger*
/// \param listPassenger sPassenger*
/// \param listType sPassangerType*
/// \param lenType int
/// \param index int
/// \param pDescripcion char*
/// \return int Retorna 1 en caso de exito, 0 en caso de error
int compararTipoDePasajero(sPassenger* listPassenger, sPassangerType* listType, int lenType, int index, char* pDescripcion);

/// \fn int listPassengersAbovePriceAverage(sPassenger*, int, sPassangerType*, int)
/// \brief Lista los pasajeros cuyo campo precio exceda el precio promedio de todos los pasajeros
/// \param list sPassenger*
/// \param length int
/// \param listType sPassangerType*
/// \param lenType int
/// \return int Retorna 1 en caso de exito, 0 en caso de error y -1 si la lista es NULL
int listPassengersAbovePriceAverage(sPassenger* list, int length, sPassangerType* listType, int lenType);

/// \fn int calcularPromedioPrecios(sPassenger*, int, float*, float*)
/// \brief Calcula el promedio y el total de precios
/// \param list sPassenger*
/// \param length int
/// \param promedioPrecio float*
/// \param totalPrecios float*
/// \return int Retorna 1 en caso de exito, 0 en caso de error y -1 si la lista es NULL
int calcularPromedioPrecios(sPassenger* list, int length, float* promedioPrecio, float* totalPrecios);

/// \fn int sortPassengersByCode(sPassenger*, int, int, sFlightStatus*, int)
/// \brief Ordena los pasajeros por codigo de vuelo alfabeticamente, solo listando los que tengan el estado de vuelo activo
/// \param list sPassenger*
/// \param len int
/// \param order int
/// \param listStatus sFlightStatus*
/// \param lenStatus int
/// \return int Retorna 1 en caso de exito, 0 en caso de error y -1 si la lista es NULL
int sortPassengersByCode(sPassenger* list, int len, int order, sFlightStatus* listStatus, int lenStatus);

/// \fn int ordenarCogidosAlfabeticamente(sPassenger*, int, int)
/// \brief Ordena alfabeticamente los codigos de vuelo
/// \param listPassenger sPassenger*
/// \param lenPassenger int
/// \param order int
/// \return int Retorna 1 en caso de exito, 0 en caso de error
int ordenarCogidosAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order);

/// \fn int cargaForzada(sPassenger*, int, sFlightStatus*)
/// \brief Carga de manera hardcodeada pasajeros a la lista de tipo sPassenger*
/// \param listaDePasajeros sPassenger*
/// \param len int
/// \param listaDeFlightCodes sFlightStatus*
/// \return int Retorna 1 en caso de exito, 0 en caso de error y -1 si la lista es NULL
int cargaForzada(sPassenger* listaDePasajeros, int len, sFlightStatus* listaDeFlightCodes);

#endif
