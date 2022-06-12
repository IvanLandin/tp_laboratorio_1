#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"
#include "procesoDeStrings.h"

/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
/// \param path char* Ruta de acceso al archivo
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
/// \param path char* Ruta de acceso al archivo
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/// \fn int controller_addPassenger(LinkedList*, int)
/// \brief Alta de pasajero
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \param id int Numero id generado por controlador
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_addPassenger(LinkedList* pArrayListPassenger, int id);

/// \fn int controller_editPassenger(LinkedList*)
/// \brief Modificar datos de pasajero
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_editPassenger(LinkedList* pArrayListPassenger);

/// \fn int controller_removePassenger(LinkedList*)
/// \brief Baja de pasajero
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_removePassenger(LinkedList* pArrayListPassenger);

/// \fn int controller_ListPassenger(LinkedList*)
/// \brief Listar pasajeros
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/// \fn int controller_sortPassenger(LinkedList*)
/// \brief Ordenar pasajeros
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
/// \param path char* Ruta de acceso al archivo
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
/// \param path char* Ruta de acceso al archivo
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/// \fn int Controller_GenerarId(char*)
/// \brief Genera numero id a partir del ultimo id guardado
/// \param path char* Ruta de acceso al archivo
/// \return Retorna 1 en caso de exito, 0 en caso de error.
int Controller_GenerarId(char* path);

/// \fn int Controller_GuardarLastId(char*, int)
/// \brief Guarda en un archivo de texto el ultimo id generado
/// \param path char* Ruta de acceso al archivo
/// \param lastId int Ultimo id generado
/// \return Retorna 1 en caso de exito, 0 en caso de error.
int Controller_GuardarLastId(char* path, int lastId);
