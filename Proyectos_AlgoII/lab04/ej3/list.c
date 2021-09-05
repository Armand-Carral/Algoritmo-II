#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "list.h"

struct _node {
	list_elem elem;
	list next;
};


/* Constructors */
list empty(void) {
	return NULL;
}

list addl(list_elem e, list l) {
	list p = malloc(sizeof(struct _node));
	p->elem = e;
	p->next = l;
	l = p;
	return l;
}

/* Operations */
bool is_empty(list l) {
	return l == NULL;
}

list_elem head(list l) {
	assert(!is_empty(l));
	list_elem e = l->elem;
	return e;
}

list tail(list l) {
	assert(!is_empty(l));
	list p = NULL;
	p = l;
	l = l->next;
	free(p);
	p = NULL;
	return l;
}

list addr(list l, list_elem e) {
	list p = NULL;
	list q = malloc(sizeof(struct _node));
	q->elem = e;
	q->next = NULL;
	if(!is_empty(l)) {
		p = l;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = q;	
	}
	else {
		l = q;
	}
	p = NULL;
	return l;
}

unsigned int length(list l) {
	list p = NULL;
	unsigned int n = 0u;
	p = l;
	while(p != NULL) {
		n = n + 1u;
		p = p->next;
	}
	return n;
}

list concat(list l,list l0) {
	list p = NULL;
	p = l0;
	while(p->next != NULL) {
		addr(l, p->elem);
		p = p->next;
	}
	return l;
}

list_elem index(list l, unsigned int n) {
	assert(length(l) > n);
	list p = NULL;
	unsigned int position = 0u;
	p = l;
	list_elem e = p->elem;
	while(p->next != NULL && position < n) {
		p = p->next;
		e = p->elem;
		position = position + 1u;
	}
	return e;
}

list take(list l, unsigned int n) {
	unsigned int pos = 0u;
	list p = NULL;
	p = l;
	if(is_empty(l) || n == 0u) {
		l = NULL;
	}
	else {
		while(pos < n - 1u && p->next != NULL) {
			p = p->next;
			pos = pos + 1u; 
		}
		p = NULL;
	}
	return l;
}

list drop(list l, unsigned int n) {
	list p = NULL;
	unsigned int pos = 0u;
	while(l->next != NULL && pos < n) {
		p = l;
		l = l->next;
		pos = pos + 1u;
	}
	free(p);
	p = NULL;
	return l;
}

list copy_list(list l1) {
	list p = NULL;
	list l2 = empty(); 
	p = l1;
	while(!is_empty(p)){
		l2 = addr(l2, p->elem);
		p = p->next;
	}
	return l2;
}

/* Destroy */
list destroy (list l) {
	list p = NULL;
	p = l;
	while(!is_empty(p)) {
		l = p;
		p = p->next;
		free(l);
	}
	l = NULL;
	return l;
}
