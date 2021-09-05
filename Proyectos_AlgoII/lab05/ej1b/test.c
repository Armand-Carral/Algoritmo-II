#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE 15

/*
* ¿Funciona bien stack_pop() para pilas de tamaño 1? Si funciona para pila de tamaño 1.

* Si la pila queda vacía, ¿puedo volver a insertar elementos? Se puede volver a insertar nuevos elementos.

* ¿La función stack_to_array() devuelve NULL para una pila vacía?  Si devuelve NULL.
  ¿Devuelve los elementos en el orden correcto? No sé.
*/
int main() {
	stack_elem s_array[SIZE]; // = {6};
	stack new_s = stack_empty();
	
	
	for(unsigned int i=0; i < SIZE; ++i) {
		printf("Ingrese un elemento:\n");
		scanf("%d", &s_array[i]);
		new_s = stack_push(new_s, s_array[i]);
	}
	
	if(!stack_is_empty(new_s)){
		printf("Si se cargaron los elementos en la pila.\n");
		printf("Y su tamaño es: %d\n", stack_size(new_s));
	}
	else{
		printf("No se cargaron los elementos en la pila..\n");
	}

	while(!stack_is_empty(new_s)) {
		printf("%d ", stack_top(new_s));
		new_s = stack_pop(new_s);
	}

	/*
	unsigned int size_s = stack_size(new_s);
	
	printf("El/Los elemento/s de la pila es/son:\n");
	for(unsigned int i = 0u; i < size_s; ++i) {
		printf("%d ", stack_top(new_s));
		new_s = stack_pop(new_s);
	}
	*/

	new_s = stack_destroy(new_s);
	if(stack_is_empty(new_s)){
		printf("\nLa pila está vacía.\n");
	}
	else{
		printf("\nLa pila NO está vacía.\n");
	}
	

	
	stack_elem f;
	printf("Ingrese un elemento:\n");
	scanf("%d", &f);
	new_s = stack_push(new_s, f);
	if(!stack_is_empty(new_s)) { 
		printf("El nuevo elemento de la pila es: %d\n", stack_top(new_s));
	}
	else{
		printf("El elemtno no se guardo.\n");
	}
	
	new_s = stack_destroy(new_s);

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

