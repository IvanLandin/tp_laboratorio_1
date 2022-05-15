#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "procesoDeStrings.h"

#define EMPTY 0
#define FULL 1

typedef struct
{
	char flightCode[10];
	int idStatus;
	char descripcionStatus[20];
	int isEmpty;
}sFlightStatus;
typedef struct
{
	int idPassangerType;
	char descripcionPassangerType[20];
}sPassangerType;
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
/// \brief
/// \param
/// \param
/// \return
int initPassengers(sPassenger*, int);

/// \fn int initFlightStatus(sFlightStatus*, int)
/// \brief
/// \param list
/// \param len
/// \return
int initFlightStatus(sFlightStatus* list, int len);

/// \fn int obtenerId(sPassenger*, int)
/// \brief
/// \param list
/// \param len
/// \return
int obtenerId(sPassenger* list, int len);

/// \fn sPassenger ingresarPassenger(sPassenger*, int, sPassangerType*, int)
/// \brief
/// \param listPassenger
/// \param lenPassenger
/// \param listType
/// \param lenType
/// \return
sPassenger ingresarPassenger(sPassenger* listPassenger, int lenPassenger, sPassangerType* listType, int lenType);

/// \fn int addPassengerToArray(sPassenger*, int, int, char[], char[], float, int, char[])
/// \brief
/// \param list
/// \param len
/// \param id
/// \param name
/// \param lastName
/// \param price
/// \param typePassenger
/// \param flightCode
/// \return
int addPassengerToArray(sPassenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flightCode[]);

/// \fn int addFlightCodeToArray(sFlightStatus*, int, char*)
/// \brief
/// \param listFlightStatus
/// \param lenFlightStatus
/// \param flightCodeIngresado
/// \return
int addFlightCodeToArray(sFlightStatus* listFlightStatus, int lenFlightStatus, char* flightCodeIngresado);

/// \fn int menuBaja(sPassenger*, int)
/// \brief
/// \param listPassenger
/// \param lenPassenger
/// \return
int menuBaja(sPassenger* listPassenger, int lenPassenger);

/// \fn int listarPassengerTypes(sPassangerType*, int)
/// \brief
/// \param listType
/// \param lenType
/// \return
int listarPassengerTypes(sPassangerType* listType, int lenType);

/// \fn int BuscarLibre(sPassenger*, int)
/// \brief
/// \param list
/// \param len
/// \return
int BuscarLibre(sPassenger* list, int len);

/// \fn int findPassengerById(sPassenger*, int, int)
/// \brief
/// \param list
/// \param len
/// \param id
/// \return
int findPassengerById(sPassenger* list, int len,int idIngresado);

/// \fn int removePassenger(sPassenger*, int, int, int)
/// \brief
/// \param list
/// \param len
/// \param id
/// \param index
/// \return
int removePassenger(sPassenger* list, int len, int id, int index);

/// \fn int menuModificar(sPassenger*, int, sPassangerType*, int)
/// \brief
/// \param listPassenger
/// \param lenPassenger
/// \param listTypePassenger
/// \param lenType
/// \return
int menuModificar(sPassenger* listPassenger, int lenPassenger, sPassangerType* listTypePassenger, int lenType);

/// \fn int modificarPassenger(sPassenger*, char[])
/// \brief
/// \param listPassenger
/// \param mensaje
/// \return
int modificarPassenger(sPassenger* listPassenger, char mensaje[]);

/// \fn int modificarNombre(sPassenger*, int)
/// \brief
/// \param listPassenger
/// \param index
/// \return
int modificarNombre(sPassenger* listPassenger, int index);

/// \fn int modificarApellido(sPassenger*, int)
/// \brief
/// \param listPassenger
/// \param index
/// \return
int modificarApellido(sPassenger* listPassenger, int index);

/// \fn int modificarPrecio(sPassenger*, int)
/// \brief
/// \param listPassenger
/// \param index
/// \return
int modificarPrecio(sPassenger* listPassenger, int index);

/// \fn int modificarTipoPasajero(sPassenger*, sPassangerType*, int, int)
/// \brief
/// \param listPassenger
/// \param listTypePassenger
/// \param lenType
/// \param index
/// \return
int modificarTipoPasajero(sPassenger* listPassenger, sPassangerType* listTypePassenger, int lenType, int index);

/// \fn int modificarflightCode(sPassenger*, int)
/// \brief
/// \param listPassenger
/// \param index
/// \return
int modificarflightCode(sPassenger* listPassenger, int index);

/// \fn int menuDeOrden()
/// \brief
/// \return
int menuDeOrden();


int sortPassengersByName(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType);


int ordenarAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order, sPassangerType* listType, int lenType);


int swap(sPassenger* listPassenger, int indexI, int indexJ);


int compararTipoDePasajero(sPassenger* listPassenger, sPassangerType* listType, int lenType, int index, char* pDescripcion);


int listPassengersAbovePriceAverage(sPassenger* list, int length, sPassangerType* listType, int lenType);


int calcularPromedioPrecios(sPassenger* list, int length, float* promedioPrecio);


int sortPassengersByCode(sPassenger* list, int len, int order, sFlightStatus* listStatus, int lenStatus);


int ordenarCogidosAlfabeticamente(sPassenger* listPassenger, int lenPassenger, int order);


int buscarEstadoActivo(sPassenger* listPassenger, sFlightStatus* listStatus, int lenStatus, int index);


int menuListar(sPassenger* listPassengers, int lenPassengers, sPassangerType* listType, int lenType, sFlightStatus* listFlightStatus, int lenStatus);


int cargaForzada();
