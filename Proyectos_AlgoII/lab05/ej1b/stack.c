#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
	stack_elem elem;
	unsigned int size;
	stack next;
};


static bool invrep(stack s) {
	bool s_check = true;
	if(s != NULL) {
		s_check = s->size > 0u; 
	}
	return s_check;
}

stack stack_empty() {
	return NULL;
}

stack stack_push(stack s, stack_elem e) {
	if(s==NULL){
		s = malloc(sizeof(struct _s_stack));
		s->elem = e;
		s->size = 1u;
		s->next = NULL;
	}
	else if(s != NULL) {
		stack s_aux = malloc(sizeof(struct _s_stack));
		s_aux->elem = e;
		s_aux->size = s->size + 1u;
		s_aux->next = s;
		s = s_aux;
	}
	assert(invrep(s)); //Aqui va la invariante: s != NULL && s->size > 0
	return s;
}

stack stack_pop(stack s) {
	assert(!stack_is_empty(s) && invrep(s)); //Aquí la invrep: s != NULL && s->size > 0 
	stack s_aux = s;
	s->size = s->size - 1u;
	s = s->next;
	free(s_aux);
	return s;
}

unsigned int stack_size(stack s) { 
	assert(invrep(s));
	unsigned int size = 0u;
	if(s != NULL) {
		size = s->size;
	}
	return size;	
}

stack_elem stack_top(stack s) {
	assert(!stack_is_empty(s) && invrep(s));
	return s->elem;
}

bool stack_is_empty(stack s) {
	return s == NULL;
}

stack_elem *stack_to_array(stack s) {
	assert(invrep(s)); //Aqui la invariante: s != NULL && s->size > 0.
	stack s_aux = s;
	stack_elem *array = NULL;
	if(!stack_is_empty(s)) {
		array = calloc(stack_size(s), sizeof(int));
		for(int i = stack_size(s)-1u; i >= 0; --i) {
			array[i] = s_aux->elem;
			s_aux = s_aux->next;    
		}
	}
	assert(invrep(s)); 	//Aqui la invariante: s != NULL && s->size > 0.
	return array;
}

stack stack_destroy(stack s) {
	assert(invrep(s)); 	//Aqui va la invariante es: s != NULL && s->size > 0.
	stack s_aux = NULL;
	s_aux = s;
	while(!stack_is_empty(s_aux)) {
		s = s_aux;
		s_aux = s_aux->next;
		free(s);
		s = NULL;
	}
	
	return s;
}
