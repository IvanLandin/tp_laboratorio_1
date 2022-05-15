#include "utn.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int limiteInferior, int limiteSuperior, int reintentos)
{
	int bufferInt;
	int retorno;

	retorno = -1;

	while(reintentos > 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getInt(&bufferInt) == 0)
		{
			if(bufferInt >= limiteInferior && bufferInt <= limiteSuperior)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}

	return retorno;
}
int esNumerica(char* cadena)
{
	int i;
	int retorno;

	i = 0;
	retorno = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}

	return retorno;
}
int getInt(int* pResultado)
{
	int retorno;
	char buffer[64];

	retorno = -1;

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}

	return retorno;
}
int myGets(char* cadena, int len)
{
	int retorno;
	retorno = -1;
	fgets(cadena, len, stdin);

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);

		if (cadena[strlen (cadena)-1] == '\n')
		{
			cadena[strlen (cadena)-1] = '\0';
		}

		retorno = 0;
	}
	return retorno;
}
float utn_getNumeroDecimal(float* pResultado, char* mensaje, char* mensajeError, float limiteInferior, float limiteSuperior, int reintentos)
{
	float bufferFloat;
	int retorno;

	retorno = -1;

	while(reintentos > 0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= limiteInferior && bufferFloat <= limiteSuperior)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}

	return retorno;
}
int getFloat(float* pResultado)
{
	int retorno;
	char buffer[64];

	retorno = -1;

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esDecimal(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}

	return retorno;
}
int esDecimal(char* cadena)
{
	int i;
	int retorno;
	int banderaPunto;

	i = 0;
	retorno = 0;
	banderaPunto = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] == '.' && banderaPunto == 1) || esNumerica(cadena))
			{
				if(cadena[i] == '.')
				{
					banderaPunto = 0;
				}
				retorno = 1;
			}
			i++;
		}
	}
	return retorno;
}
int utn_getCaracter(char* pResultado, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno;
	char bufferChar;

	retorno = -1;

	while(reintentos > 0)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
		{
			reintentos--;
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(esNumerica(&bufferChar) == 0)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
		}
	}

	return retorno;
}
int utn_getAlfaNumerico(char* pResultado, char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior)
{
	int retorno;
	int retornoMyGets;
	char bufferString[64];
	int len;

	retorno = -1;

	printf(mensaje);
	fflush(stdin);
	retornoMyGets = myGets(bufferString, sizeof(bufferString));

	len = strlen(bufferString);

	for(int i=0; i<len; i++)
	{
		while(!isalnum(bufferString[i]))
		{
			printf("%s", mensajeError);
			printf("%s", mensaje);
			fflush(stdin);
			retornoMyGets = myGets(bufferString, sizeof(bufferString));
		}
	}

	if(retornoMyGets == 0 && len >= limiteInferior && len <= limiteSuperior)
	{
		strcpy(pResultado, bufferString);
		retorno = 0;
	}

	return retorno;
}
int utn_getTexto(char* pResultado, char mensaje[], char mensajeError[], int limiteInferior, int limiteSuperior)
{
	int retorno;
	int retornoMyGets;
	char bufferString[64];
	int len;

	retorno = -1;

	printf(mensaje);
	fflush(stdin);
	retornoMyGets = myGets(bufferString, sizeof(bufferString));

	while(!getString(bufferString))
	{
		printf("%s", mensajeError);
		printf("%s", mensaje);
		fflush(stdin);
		retornoMyGets = myGets(bufferString, sizeof(bufferString));
	}

	len = strlen(bufferString);

	if(retornoMyGets == 0 && len >= limiteInferior && len <= limiteSuperior)
	{
		strcpy(pResultado, bufferString);
		retorno = 0;
	}

	return retorno;
}

int getString(char* cadena)
{
	int retorno;
	int len;
	int i;

	retorno = 1;

	if(cadena!=NULL)
	{
		len = strlen(cadena);

		for(i=0; i<len; i++)
		{
			if(!isprint(cadena[i]) || ispunct(cadena[i]) || (!isalpha(cadena[i]) && cadena[i] != ' '))
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
