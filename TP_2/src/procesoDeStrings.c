#include "procesoDeStrings.h"

void FormatearCadena(char cadena[])
{
	int tamanio;
	int i;

	tamanio = strlen(cadena);
	strlwr(cadena);

	for(i=0; i<tamanio; i++)
	{
		if(cadena[i-1] == ' ' || i==0)
		{
			cadena[i] = toupper(cadena[i]);
		}
	}
}
void ConcatenarStrings(char nombre[], char apellido[], char nombreCompleto[])
{
	strcpy (nombreCompleto, apellido);
	strcat (nombreCompleto, ", ");
	strcat (nombreCompleto, nombre);
}
