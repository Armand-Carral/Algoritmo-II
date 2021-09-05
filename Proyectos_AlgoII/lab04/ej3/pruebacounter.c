#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Then, this project's includes, alphabetically ordered */
//#include "array_helpers.h"
#include "list.h"
#define TAM 6

void show_lista(list l) {
	bool vacio = is_empty(l);
	if(vacio) {
		printf("La lista es vacia\n");
	}
	else{
		printf("La lista NO es vacía\n");
	}
}

list agregar_elemetos(list l) {
	list_elem a[TAM] = {9, 8, 7, 5, 6, 10};
	//list_elem a[TAM];
	for(unsigned int i = 0u; i < TAM; ++i) {
		//printf("posicion de i: %d\n", i);
		//scanf("%d", &a[i]);
		l = addl(a[i], l);
	}

	return l;
}

list show_elem_list(list l) {
	list l2 = copy_list(l);
	printf("Los elementos de la lista son:");
	while(length(l2) > 0u) {
		printf(" %d ", head(l2));
		l2 = tail(l2);
	}
	printf("\n");
	return l;
}

int main(void){
	list l1 = NULL;
	l1 = empty();
	show_lista(l1);
	
	printf("Agrego los elemento\n");
	l1 = agregar_elemetos(l1);
	show_lista(l1);

	//l1 = addr(l1, 12);

	printf("el tamaño de la lista es %d\n", length(l1));

	printf("el elemento en la posicion n = 0 es: %d\n", index(l1, 0));

	printf("devuelve el primer elemento:\n");
	l1 = take(l1, 1);
	while(length(l1) > 0u) {
		printf("%d ", head(l1));
		l1 = tail(l1);
	}
	printf("\n");
	//l1 = show_elem_list(l1);
	show_lista(l1);

	return (EXIT_SUCCESS);
}

	/*l1 = addl(5, l1);
	show_lista(l1);
	printf("Elementos de la lista: %d\n", head(l1));
	printf("Elimino elemento\n");
	l1 = tail(l1);*/