#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// \fn int utn_getNumero(int*, char*, char*, int, int, int)
/// \brief
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param limiteInferior
/// \param limiteSuperior
/// \param reintentos
/// \return
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int limiteInferior, int limiteSuperior, int reintentos);

/// \fn int esNumerica(char*)
/// \brief
/// \param cadena
/// \return
int esNumerica(char* cadena);

/// \fn int getInt(int*)
/// \brief
/// \param pResultado
/// \return
int getInt(int* pResultado);

/// \fn int myGets(char*, int)
/// \brief
/// \param cadena
/// \param len
/// \return
int myGets(char* cadena, int len);

/// \fn float utn_getNumeroDecimal(float*, char*, char*, float, float, int)
/// \brief
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param limiteInferior
/// \param limiteSuperior
/// \param reintentos
/// \return
float utn_getNumeroDecimal(float* pResultado, char* mensaje, char* mensajeError, float limiteInferior, float limiteSuperior, int reintentos);

/// \fn int getFloat(float*)
/// \brief
/// \param pResultado
/// \return
int getFloat(float* pResultado);

/// \fn int esDecimal(char*)
/// \brief
/// \param cadena
/// \return
int esDecimal(char* cadena);

/// \fn int utn_getCaracter(char*, char[], char[], int)
/// \brief
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param reintentos
/// \return
int utn_getCaracter(char* pResultado, char mensaje[], char mensajeError[], int reintentos);

/// \fn int utn_getAlfaNumerico(char*, char[], char[], int, int)
/// \brief
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param limiteInferior
/// \param limiteSuperior
/// \return
int utn_getAlfaNumerico(char* pResultado, char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior);

/// \fn int utn_getTexto(char*, char[], char[], int, int)
/// \brief
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param limiteInferior
/// \param limiteSuperior
/// \return
int utn_getTexto(char* pResultado, char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior);

/// \fn int getString(char*)
/// \brief
/// \param cadena
/// \return
int getString(char* cadena);
