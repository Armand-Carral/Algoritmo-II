#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
	stack_elem elem;
	stack next; 
};


stack stack_empty() {
	return NULL;
}


stack stack_push(stack s, stack_elem e) {
	stack s_aux = malloc(sizeof(struct _s_stack));
	s_aux->elem = e;
	s_aux->next = s;
	s = s_aux;
	s_aux = NULL;
	return s;
}

stack stack_pop(stack s) {
	assert(!stack_is_empty(s));
	stack s_aux = s;
	s = s->next;
	free(s_aux);
	s_aux = NULL;
	return s;
}

unsigned int stack_size(stack s) {
	stack s_aux = NULL;
	unsigned int size = 0u;
	s_aux = s;
	while(s_aux != NULL) {
		size = size + 1u;
		s_aux = s_aux->next;
	}
	s_aux = NULL;
	return size;
}

stack_elem stack_top(stack s) {
	assert(!stack_is_empty(s));
	return s->elem;
}

bool stack_is_empty(stack s) {
	return s == NULL;
}

stack_elem *stack_to_array(stack s) {
	stack s_aux = s;
	stack_elem *array = NULL;
	if(!stack_is_empty(s)) {
		array = calloc(stack_size(s), sizeof(int));
		for(int i = stack_size(s)-1u; i >= 0; --i) {
			array[i] = s_aux->elem;
			s_aux = s_aux->next;    
		}
		s_aux = NULL;
	}

	return array;
}

stack stack_destroy(stack s) {
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
