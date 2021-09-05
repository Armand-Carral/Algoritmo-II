#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE 5

/*
* ¿Funciona bien stack_pop() para pilas de tamaño 1? Si funciona para pila de tamaño 1.

* Si la pila queda vacía, ¿puedo volver a insertar elementos? Se puede volver a insertar nuevos elementos.

* ¿La función stack_to_array() devuelve NULL para una pila vacía?  Si devuelve NULL.
  ¿Devuelve los elementos en el orden correcto? No sé.
*/

int main() {
	stack_elem s_array[SIZE]; // = {6};
	//stack_elem e;
	stack new_s = stack_empty();
	
	if(stack_is_empty(new_s)){
		printf("Se creo la pila.\n");
		//printf("Y su tamaño es: %d\n", stack_size(new_s));
	}
	else{
		printf("No se creó la pila.\n");
	}

	
	for(unsigned int i=0; i < SIZE; ++i) {
		printf("Ingrese un elemento:\n");
		scanf("%d", &s_array[i]);
		new_s = stack_push(new_s, s_array[i]);
	}

	//printf("Agregue un elemnto\n");
	//scanf("%d", &e);
	//new_s = stack_push(new_s,e);

	if(stack_is_empty(new_s)){
		printf("No se cargo el/los elemento/s.\n");
	}
	else{
		printf("Si se cargo el/los elemento/s.\n");
		printf("Y el tamaño de la pila es: %d\n", stack_size(new_s));
	}

/*	while(!stack_is_empty(new_s)){
		printf("El elemento en la pila es: %d\n", stack_top(new_s));
		new_s = stack_pop(new_s);
	}*/

	new_s = stack_destroy(new_s);

/*	if(stack_is_empty(new_s)){
		printf("La pila esta vacía.\n");
	}
	else{
		printf("La pila No está vacia.\n");
	}
*/


/*
	int *new_array = NULL;
	new_array = stack_to_array(new_s);
	printf("La pila guardada en el arreglo dinamico:\n");
	for (unsigned int i = 0u; i < stack_size(new_s); ++i) {
		printf(" %d ", new_array[i]);
	}
	new_array = NULL;
	
	if(stack_to_array(new_s) == NULL) {
		printf("\nDevuelve NULL \n");
	}
	else {
		printf("\nNo devuelve NULL\n");
	}
*/

	
	
	return (EXIT_SUCCESS);
}

