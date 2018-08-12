#pragma once

/* Estructura de un nodo de la lista */
struct node
{
    int value;              // El valor del Nodo
    struct node* next;      // Puntero al siguiente Nodo

};

typedef struct node Node;

/* Estructura de la lista ligada */
struct linked_list
{
    Node* first;    // Puntero al primer Nodo
    Node* last;     // Puntero al ultimo Nodo
    int count;      // Cantidad de Nodos
};

typedef struct linked_list LinkedList;


//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

/* Crea un listaligada vacia */
LinkedList* linkedlist_init();

/* Append alfinal de la lista ligada */
void linkedlist_append(LinkedList *list, int value);

/* Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, int element, int position);

/* Elimina el elemento de la posicion indicada y retorna el valor */
int linkedlist_delete(LinkedList* list, int position);

/* Retorna el valor del elemento en la posicion dada */
int linkedlist_get(LinkedList* list, int position);

/* Concatena la segunda lista a la primera lista */
void linkedlist_concatenate(LinkedList* list1, LinkedList* list2);

/* Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list);