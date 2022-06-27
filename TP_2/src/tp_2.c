/*
 ============================================================================
Tp 2
Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
número de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Precio o Tipo de pasajero o Código de vuelo
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún pasajero.
2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.

Landín Ivan Lautaro. Div C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utn.h"
#include "arrayPassenger.h"
#include "passengerType.h"
#include "flightStatus.h"
#include "menu.h"

#define LEN 2000

int main(void)
{
	setbuf(stdout,NULL);
	sPassenger listaDePasajeros[LEN];
	sPassenger auxiliarPasajero;
	sPassangerType listaTipoPasajeros[3] = {{1, "Primera Clase"}, {2, "Clase Ejecutiva"}, {3, "Clase Economica"}};
	sFlightStatus listaDeFlightCodes [LEN];
	int opcionDelMenu;
	int retorno;
	int retornoFlightStatus;
	int banderaAlta;


	retorno = initPassengers(listaDePasajeros, LEN);
	retornoFlightStatus = initFlightStatus(listaDeFlightCodes, LEN);
	srand(getpid());
	banderaAlta = 0;

	if(retorno == 0 && retornoFlightStatus == 0)
	{
		do
		{
			retorno = utn_getNumero(&opcionDelMenu, "1. ALTA DE PASAJEROS.\n2. MODIFICAR PASAJEROS.\n3. BAJA DE PASAJEROS.\n4. INFORMAR.\n5. CARGA FORZADA DE DATOS.\n6. SALIR.\nSELECCIONE UNA OPCION: ",
									"\nERROR. INGRESE UNA OPCION DISPONIBLE DEL MENU...\n\n",
									1, 6, 10);

			if(retorno == 0)
			{
				switch(opcionDelMenu)
				{
					case 1:
						auxiliarPasajero = ingresarPassenger(listaDePasajeros, LEN, listaTipoPasajeros, 3);
						banderaAlta = addPassengerToArray(listaDePasajeros, LEN, auxiliarPasajero.id, auxiliarPasajero.name, auxiliarPasajero.lastName, auxiliarPasajero.price, auxiliarPasajero.idPassangerType, auxiliarPasajero.flightCode);
						addFlightCodeToArray(listaDeFlightCodes, LEN, auxiliarPasajero.flightCode);
						if(banderaAlta != -1)
						{
							printf("\nCarga exitosa.\n\n");
							banderaAlta = 1;
						}
						else
						{
							printf("\nERROR. \n\n");
						}
					break;
					case 2:
						if(banderaAlta)
						{
							if(menuModificar(listaDePasajeros, LEN, listaTipoPasajeros, 3))
							{
								printf("\nPasajero modificado exitosamente.\n\n");
							}
						}
						else
						{
							printf("\nPara acceder al menu, primero debe ingresar un pasajero.\n\n");
						}
					break;
					case 3:
						if(banderaAlta)
						{
							menuBaja(listaDePasajeros, LEN);
						}
						else
						{
							printf("\nPara acceder al menu, primero debe ingresar un pasajero.\n\n");
						}
					break;
					case 4:
						if(banderaAlta)
						{
							menuListar(listaDePasajeros, LEN, listaTipoPasajeros, 3, listaDeFlightCodes, LEN);
						}
						else
						{
							printf("\nPara acceder al menu, primero debe ingresar un pasajero.\n\n");
						}

					break;
					case 5:
						if(cargaForzada(listaDePasajeros, LEN, listaDeFlightCodes))
						{
							banderaAlta = 1;
							printf("\nLa carga forzosa se realizo exitosamente.\n\n");
						}
					break;
					case 6:
						printf("\nGracias por usar nuestra app!");
					break;
					default:
						printf("\nOPCION NO DISPONIBLE.\n\n");
					break;
				}
			}


		}while(opcionDelMenu != 6);
	}

	return EXIT_SUCCESS;
}
