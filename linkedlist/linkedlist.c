#include "linkedlist.h"     // Estructuras de LinkedList
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

/* Crear Nodo con el valor value, y retorna un puntero al nodo. */
Node* node_init(int value)
{
    Node* node = malloc(sizeof(Node));  // Creo el Nodo asignandole espacio de memoria
    
    node -> value = value;              // Le asigno value al atributo value
    node -> next = NULL;                // Le asigno next como NULL

    return node;                        // Retorno el Nodo
}

/* Crea un listaligada vacia */
LinkedList* linkedlist_init()
{
    LinkedList* list = malloc(sizeof(LinkedList)); // Creo el Nodo asignandole espacio de memoria

    list -> first = NULL;   // Le asigno al atributo first NULL
    list -> last = NULL;    // Le asigno al atributo last NULL
    list -> count = 0;      // Le asigno al atributo count como 0

    return list;
}

/* Append alfinal de la lista ligada */
void linkedlist_append(LinkedList* list, int value)
{
    Node* node = node_init(value);      // Creo el Nodo a apendear
    
    if (list -> count == 0) {           // Si la lista esta vacia
        list -> first = node;           // El Nodo que ingresa es el primero
    }
    else {
        list -> last -> next = node;    // El Nodo que ingresa es el despues del ultimo
    }

    list -> last = node;                // El Nodo que ingresa es el ultimo

    list -> count++;                    // Se aumenta la cuenta de la lista
}

/* Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, int value, int position)
{
    Node* node = node_init(value);          // Creo el Nodo a apendear

    if (position == 0) {                    // Si la posicion es la 0
        node -> next = list -> first;       // El siguiente del Nodo a ingresar es el primero de la lista
        list -> first = node;               // El Nodo a ingresar es el primero de la lista
    }
    else if(position == list -> count) {    // Si la posicion es la cola de la lista
        list -> last -> next = node;        // El siguiente de la cola es el Nodo a ingresar
        list -> last = node;                // Nodo a ingresar es ahora la cola
    }
    else {                                  // La posicion es al medio de la lista
        Node* actual = list -> first;       // Nodo anterior a la insetion
        for(int i = 1; i < position; i++)
        {
            node -> next = actual -> next;  
            actual -> next = node;
        }

    list -> count++;                        // Se aumenta la cuenta de la lista
    }
}

/* Elimina el elemento de la posicion indicada y retorna el valor */
int linkedlist_delete(LinkedList* list, int position)
{
    int value;                              // Valor a retornar

    if (position == 0) {                    // Si la posicion es la 0
        value = list -> first -> value;     // El valor a retornar toma el valor de la cabeza de la lista
        
        Node* node = list -> first;         // Guardo el Nodo a eliminar
        list -> first = node -> next;
        
        free(node);                         // Libero memoria del Nodo a eliminar
    }
    else {
        Node* actual = list -> first;       // Nodo anterior a la eliminacion
        
        for(int i = 1; i < position; i++)
        {
            actual = actual -> next;
        }
        
        Node* node = actual -> next;        // Guardo el Nodo a eliminar
        value = node -> value;              // El valor a retormar toma el valor del a eliminar

        actual -> next = node -> next;      // Saltamos el a eliminar

        free(node);                         // Libero memoria del Nodo a eliminar

        if (position == list -> count -     // Si el a eliminar era la cola
            list -> last = actual;
        }
    }

    list -> count--;                        // Disminuyo la cuenta de la lista

    return value;
}

/* Retorna el valor del elemento en la posicion dada */
int linkedlist_get(LinkedList *list, int position)
{
    Node* actual = list -> first;       // Nodo buscado
    
    for(int i = 0; i < position; i++)
    {
        actual = actual -> next;
    }

    return actual -> value;             // Retorno el valor del Nodo buscado
}

/* Concatena la segunda lista a la primera lista */
void linkedlist_concatenate(LinkedList* list1, LinkedList* list2)
{
    if (list1 -> count == 0) {                      // Si la list1 esta vacia
        list1 -> first = list2 -> first;            // El primero de list1 es el primero de la list2
        list1 -> last = list2 -> last;              // La cola de list1 es la cola de la list2
    }
    else if(list2 -> count == 0) {                  // Si la list2 esta vacia
        // No se hace nada 
    }
    else {
        list1 -> last -> next = list2 -> first;     // Cocateno la list2 a la list1
        list1 -> last = list2 -> last;              // Actualizo el ultimo de la list1
    }

    list1 -> count += list2 -> count;               // Actualizo el count de la list1

    free(list2);                                    // Libero la memoria de list2
}

/* Libera los nodos de una lista recursivamente */
void recursive_destroy(Node* node){
	if (node -> next) {		// Si el Nodo tiene next, llamo recursivamente
		recursive_destroy(node -> next);
	}
	free(node);				// Libero la memoria del Nodo
}

/* Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list)
{	
	recursive_destroy(list -> first);		// Libero la memoria de todos los nodos de la lista

	free(list);								// Libero la memoria de la lista
}
