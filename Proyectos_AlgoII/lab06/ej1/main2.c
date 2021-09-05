#include <stdio.h>
#include "abb.h"
#include <stdbool.h>

int main(){

	abb tree = abb_empty();

	if(abb_is_empty(tree)){
		printf("Se creo el arbol\n");
	}
	else{
		printf("No se creo el arbol\n");
	}

	tree = abb_add(tree, 10); //RAIZ
	tree = abb_add(tree, 5);
	tree = abb_add(tree, 20);
	abb_dump(tree);
	printf("\n");
	printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                   abb_min(tree),
                                                   abb_max(tree));

	tree = abb_remove(tree, 20);
	abb_dump(tree);
	printf("\n");
	printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                   abb_min(tree),
                                                   abb_max(tree));

	tree = abb_add(tree, 15);
	abb_dump(tree);
	printf("\n");
	printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                   abb_min(tree),
                                                   abb_max(tree));

	tree = abb_add(tree, 1);
	abb_dump(tree);
	printf("\n");
	printf("raiz: %d\n minimo: %d\n maximo: %d\n", abb_root(tree),
                                                   abb_min(tree),
                                                   abb_max(tree));

	tree = abb_destroy(tree);
	if(abb_is_empty(tree)){
		printf("Se elimino el arbol\n");
	}
	else{
		printf("No se elimino el arbol\n");
	}

	
	/*
	tree = abb_add(tree, b); 
	printf("Es vacia: %d %d\n", abb_is_empty(tree), true);
	printf("Existe: %d %d \n", abb_exists(tree, 3), true);
	b = 5;
	tree = abb_add(tree, b); 
	b = 7;
	tree = abb_add(tree, b); 
	b = 9;
	tree = abb_add(tree, b);
	b = 1;
	tree = abb_add(tree, b); 
	tree = abb_remove(tree, 1); 
	printf("Elementos: %u\n", abb_length(tree) );
	printf("max: %d\n", abb_max(tree) );
	printf("min: %d\n", abb_min(tree) );
	*/

	/*b = 4;
	tree = abb_remove(tree, b);
	printf("Elementos: %u\n", abb_length(tree) );
	printf("Elemento: %d\n", abb_root(tree) );
	b = 3;
	tree = abb_add(tree, b);
	b = 7;
	tree = abb_add(tree, b);
	printf("max: %d\n", abb_max(tree) );
	printf("min: %d\n", abb_min(tree) );
	printf("Elemento: %d\n", abb_root(tree) );
	*/

	return 0; 
}
