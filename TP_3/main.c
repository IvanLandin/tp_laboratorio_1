#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int retorno;
    int banderaGuardado = 1;
    int banderaCarga = 0;
    char opcion;
    int id;

    LinkedList* listaPasajeros = ll_newLinkedList();
    id = Controller_GenerarId("id.txt");
    do{

    	retorno = utn_getNumero(&option, "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    							"2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n"
    							"3. Alta de pasajero.\n4. Modificar datos de pasajero.\n5. Baja de pasajero.\n6. Listar pasajeros.\n7. Ordenar pasajeros.\n"
    							"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    							"9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n10. Salir.\nElija una opcion: ",
								"Error. Por favor, seleccione una de las opciones disponibles. \n", 1, 10, 5);
    	if(retorno == 0)
    	{
			switch(option)
			{
				case 1:
					if(banderaCarga==1)
					{
						do
						{
							utn_getCaracter(&opcion, "\nYa se efectuo la carga de un archivo. Desea limpiar la lista y volver a cargar?: ", "\nError. Por favor ingrese s/n.", 10);
							fflush(stdin);
							switch(opcion)
							{
								case 's':
									ll_clear(listaPasajeros);
									if(controller_loadFromText("data.csv", listaPasajeros))
									{
										printf("\nDatos cargados...\n\n");
										banderaCarga = 1;
									}
								break;
								case 'n':
									printf("\nVolviendo al menu principal...\n");
								break;
							}
						}while(opcion!='s' && opcion!='n');
					}
					else
					{
						if(controller_loadFromText("data.csv", listaPasajeros))
						{
							printf("\nDatos cargados...\n\n");
							banderaCarga = 1;
						}
					}
				break;
				case 2:
					if(banderaCarga==1)
					{
						do
						{
							utn_getCaracter(&opcion, "\nYa se efectuo la carga de un archivo. Desea limpiar la lista y volver a cargar?: ", "\nError. Por favor ingrese s/n.", 10);
							fflush(stdin);
							switch(opcion)
							{
								case 's':
									ll_clear(listaPasajeros);
									if(controller_loadFromBinary("data.bin", listaPasajeros))
									{
										printf("\nDatos cargados...\n\n");
										banderaCarga = 1;
									}
								break;
								case 'n':
									printf("\nVolviendo al menu principal...\n");
								break;
							}
						}while(opcion!='s' && opcion!='n');
					}
					else
					{
						if(controller_loadFromBinary("data.bin", listaPasajeros))
						{
							printf("\nDatos cargados...\n\n");
							banderaCarga = 1;
						}
					}
				break;
				case 3:
					if(controller_addPassenger(listaPasajeros, id))
					{
						printf("\nPasajero ingresado correctamente...\n\n");
						banderaGuardado = 0;
						Controller_GuardarLastId("id.txt", id);
						id++;
					}
				break;
				case 4:
					if(!ll_isEmpty(listaPasajeros))
					{
						if(controller_editPassenger(listaPasajeros))
						{
							printf("\nPasajero modificado correctamente...\n\n");
							banderaGuardado = 0;
						}
					}
					else
					{
						printf("\nError, la lista de pasajeros esta vacia. \n\n");
					}
				break;
				case 5:
					if(!ll_isEmpty(listaPasajeros))
					{
						if(controller_removePassenger(listaPasajeros))
						{
							printf("\nPasajero eliminado correctamente...\n\n");
							banderaGuardado = 0;
						}
					}
					else
					{
						printf("\nError, la lista de pasajeros esta vacia. \n\n");
					}
				break;
				case 6:
					if(!ll_isEmpty(listaPasajeros))
					{
						controller_ListPassenger(listaPasajeros);
					}
					else
					{
						printf("\nError, la lista de pasajeros esta vacia. \n\n");
					}
				break;
				case 7:
					if(!ll_isEmpty(listaPasajeros))
					{
						controller_sortPassenger(listaPasajeros);
					}
					else
					{
						printf("\nError, la lista de pasajeros esta vacia. \n\n");
					}
				break;
				case 8:
				case 9:
					if(!ll_isEmpty(listaPasajeros))
					{
						if(controller_saveAsBinary("data.bin", listaPasajeros) && controller_saveAsText("data.csv", listaPasajeros))
						{
							printf("\nDatos guardados. \n\n");
							banderaGuardado = 1;
						}
					}
					else
					{
						printf("\nError, la lista de pasajeros esta vacia. \n\n");
					}
				break;
				case 10:
					if((!ll_isEmpty(listaPasajeros) && banderaGuardado) || (ll_isEmpty(listaPasajeros)))
					{
						printf("\nSaliendo. Gracias por utilizar nuestra app!");
					}
					else
					{
						printf("\nPor favor, guarde los cambios efectuados antes de salir.\n\n");
					}
				break;
			}
    	}
    }while(option != 10 || !banderaGuardado);
    return 0;
}
