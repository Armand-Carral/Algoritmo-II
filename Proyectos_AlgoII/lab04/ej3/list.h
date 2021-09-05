#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct _node * list;
typedef int list_elem;

/* Consturctors */
list empty(void);
/* 
	crea una lista vacía. 
*/

list addl(list_elem e, list l);
/*
	agrega el elemento e al comienzo de la lista.
*/

/* Operations */
bool is_empty(list l);
/*
	Devuelve True si la lista es vacía.
*/

list_elem head(list l);
/* 
    Devuelve el primer elemento de la lista.
    PRE: not is_empty(l).
*/
list tail(list l);
/*
    Elimina el primer elemento de la lista.
    PRE: not is_empty(l)
*/

list addr (list l, list_elem e);
/* 
    agrega el elemento e al final de la lista. 
*/

unsigned int length(list l);
/*
    Devuelve la cantidad de elementos de la lista.
*/

list concat(list l,list l0);
/*
    Agrega al final de l todos los elementos de l0 en el mismo orden.
*/

list_elem index(list l, unsigned int n );
/*
	Devuelve el n-ésimo elemento de la lista l -}
	PRE: length(l) > n
*/

list take(list l, unsigned int n);
/*
	Deja en l sólo los primeros n elementos, eliminando el resto.
*/

list drop(list l, unsigned int n);
/*
	Elimina los primeros n elementos de la lista.
*/

list copy_list(list l1);
/*
	Copia todos los elementos de l1 en la nueva lista l2.
*/

/* Destroy */
list destroy (list l);
/*
	Libera memoria en caso que sea necesario.
*/

#endif