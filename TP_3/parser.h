#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/// \fn int parser_PassengerFromText(FILE*, LinkedList*)
/// \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
/// \param pFile FILE* Puntero a estructura FILE
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/// \fn int parser_PassengerFromBinary(FILE*, LinkedList*)
/// \brief Parsea los datos de los pasajeros desde el archivo data.bin (modo binario).
/// \param pFile FILE* Puntero a estructura FILE
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return int Retorna 1 en caso de exito, 0 en caso de error.
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

/// \fn int parser_PassengerToText(FILE*, LinkedList*)
/// \brief Parsea los datos de los pasajeros de lista dinamica para guardarlos en el archivo data.csv
/// \param pFile FILE* Puntero a estructura FILE
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return Retorna 1 en caso de exito, 0 en caso de error.
int parser_PassengerToText(FILE* pFile, LinkedList* pArrayListPassenger);

/// \fn int parser_PassengerToBinary(FILE*, LinkedList*)
/// \brief Parsea los datos de los pasajeros de lista dinamica para guardarlos en el archivo data.bin
/// \param pFile FILE* Puntero a estructura FILE
/// \param pArrayListPassenger LinkedList* Lista dinámica de pasajeros
/// \return Retorna 1 en caso de exito, 0 en caso de error.
int parser_PassengerToBinary(FILE* pFile, LinkedList* pArrayListPassenger);
