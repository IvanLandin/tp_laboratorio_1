/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
/// \fn LinkedList ll_newLinkedList*(void)
/// \brief Constructor. Crea una lista en el heap
/// \return LinkedList*
LinkedList* ll_newLinkedList(void);

/// \fn int ll_len(LinkedList*)
/// \brief Cuantos elementos hay en la lista
/// \param this LinkedList*
/// \return int
int ll_len(LinkedList* this);

/// \fn Node test_getNode*(LinkedList*, int)
/// \brief
/// \param this LinkedList*
/// \param nodeIndex int
/// \return Node*
Node* test_getNode(LinkedList* this, int nodeIndex);

/// \fn int test_addNode(LinkedList*, int, void*)
/// \brief
/// \param this LinkedList*
/// \param nodeIndex int
/// \param pElement void*
/// \return int
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/// \fn int ll_add(LinkedList*, void*)
/// \brief Agrega un elemento a la lista
/// \param this LinkedList*
/// \param pElement void*
/// \return int
int ll_add(LinkedList* this, void* pElement);

/// \fn void ll_get*(LinkedList*, int)
/// \brief Devuelve un elemento por medio de un indice
/// \param this LinkedList*
/// \param index int
void* ll_get(LinkedList* this, int index);

/// \fn int ll_set(LinkedList*, int, void*)
/// \brief Reemplaza un elemento de un indice especifico
/// \param this LinkedList*
/// \param index int
/// \param pElement void*
/// \return int
int ll_set(LinkedList* this, int index,void* pElement);

/// \fn int ll_remove(LinkedList*, int)
/// \brief Saca un pasajero de la lista
/// \param this LinkedList*
/// \param index int
/// \return int
int ll_remove(LinkedList* this,int index);

/// \fn int ll_clear(LinkedList*)
/// \brief Vacia la lista
/// \param this LinkedList*
/// \return int
int ll_clear(LinkedList* this);

/// \fn int ll_deleteLinkedList(LinkedList*)
/// \brief Borra de memoria toda la lista
/// \param this LinkedList*
/// \return int
int ll_deleteLinkedList(LinkedList* this);

/// \fn int ll_indexOf(LinkedList*, void*)
/// \brief Devuelve el indice de un elemento en particular
/// \param this LinkedList*
/// \param pElement void*
/// \return int
int ll_indexOf(LinkedList* this, void* pElement);

/// \fn int ll_isEmpty(LinkedList*)
/// \brief Determina si la lista esta llena o no
/// \param this LinkedList*
/// \return int
int ll_isEmpty(LinkedList* this);

/// \fn int ll_push(LinkedList*, int, void*)
/// \brief Inserta un elemento entre dos posiciones de la lista, a partir de un indice
/// \param this LinkedList*
/// \param index int
/// \param pElement void*
/// \return int
int ll_push(LinkedList* this, int index, void* pElement);

/// \fn void ll_pop*(LinkedList*, int)
/// \brief Saca un elemento de la lista y lo devuelve
/// \param this LinkedList*
/// \param index int
void* ll_pop(LinkedList* this,int index);

/// \fn int ll_contains(LinkedList*, void*)
/// \brief Determina si un elemento esta contendio dentro de la lista
/// \param this LinkedList*
/// \param pElement void*
/// \return int
int ll_contains(LinkedList* this, void* pElement);

/// \fn int ll_containsAll(LinkedList*, LinkedList*)
/// \brief Determina si una lista esta contenida dentro de otra
/// \param this LinkedList*
/// \param this2 LinkedList*
/// \return int
int ll_containsAll(LinkedList* this,LinkedList* this2);

/// \fn LinkedList ll_subList*(LinkedList*, int, int)
/// \brief Devuelve una sublista
/// \param this LinkedList*
/// \param from int
/// \param to int
/// \return LinkedList*
LinkedList* ll_subList(LinkedList* this,int from,int to);

/// \fn LinkedList ll_clone*(LinkedList*)
/// \brief Crea una copia en memoria de la lista
/// \param this LinkedList*
/// \return LinkedList*
LinkedList* ll_clone(LinkedList* this);

/// \fn int ll_sort(LinkedList*, int(*)(void*, void*), int)
/// \brief Ordena la lista
/// \param this LinkedList*
/// \param pFunc int
/// \param order int 1: de menor a mayor. 0: de mayor a menor
/// \return int
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
