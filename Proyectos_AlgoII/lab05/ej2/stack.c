#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};


static bool invrep(stack s) {
	bool s_check = true;
	if(s != NULL){
		s_check = s->size <= s->capacity;
	}
	return s_check;
}

// TENGO QUE VER LOS INVARIANTES
stack stack_empty() {
	stack new_stack = malloc(sizeof(struct _s_stack));
	new_stack->elems = NULL;
	new_stack->size = 0u;
	new_stack->capacity = 0u;
	assert(invrep(new_stack));
	return new_stack;
}

stack stack_push(stack s, stack_elem e) {
	assert(invrep(s));
	if(s->elems == NULL){
		s->capacity = 100u;
		s->elems = calloc(s->capacity, sizeof(stack_elem));
	}
	else if(s->size == s->capacity){
		s->capacity = 2 * s->capacity;
		s->elems = realloc(s->elems, (s->capacity) * sizeof(stack_elem));
	}
	s->elems[s->size] = e;
	s->size = s->size + 1u; 
	assert(invrep(s));
	return s;
}

stack stack_pop(stack s) {
	assert(!(stack_is_empty(s)) && invrep(s));
	s->size = s->size - 1u;
	if(s->size == 0u){
		s->elems = NULL;
	}
	assert(invrep(s));
	return s;
}

unsigned int stack_size(stack s) {
	assert(invrep(s));
	return s->size;
}

stack_elem stack_top(stack s) {
	stack_elem e;
	assert((!stack_is_empty(s)) && invrep(s)); // AQUÍ VA UNA INVARIANTE.
	e = s->elems[s->size - 1u];
	assert(invrep(s));
	return e;
}

bool stack_is_empty(stack s) {
	assert(invrep(s));
	return s->elems == NULL; //verificar esto
}

stack_elem *stack_to_array(stack s) {
	assert(invrep(s));
	stack_elem *array = NULL;
	if(!stack_is_empty(s)) {
		array = calloc(s->size, sizeof(int));
		for(unsigned int i = 0; i < s->size; ++i) {
			array[i] = s->elems[i];
		}
	}
	assert(invrep(s));
	return array;
}

stack stack_destroy(stack s) {
	assert(invrep(s)); // Aquí iria una invariante
	free(s->elems);
	s->elems = NULL;
	s->size = 0u;
	s->capacity = 0u;
	free(s);
	return s;
}

/*
stack stack_push(stack s, stack_elem e) {
	assert(invrep(s));
	if(s == NULL) {
		s = malloc(sizeof(struct _s_stack));
		s->capacity = 1u;
		s->size = 0u;
		s->elems = calloc(s->capacity, sizeof(stack_elem));
	}
	else if(s->size == s->capacity) {
		s->capacity = 2 * s->capacity;
		s->elems = realloc(s->elems, s->capacity);
	}
	s->elems[s->size] = e;
	s->size = s->size + 1u;
	assert(invrep(s));
	return s;
}

*/