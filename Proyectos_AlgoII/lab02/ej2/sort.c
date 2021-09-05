#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */
	if(der > izq){
		    //f(a[izq] != a[der]){  /ME ASEGURA QUE LOS ELEMENTOS IGUALES NO TENGAN PROBLEMAS, PERO NO ASEGURA EL ORDEN/
		unsigned int ppiv = partition(a, izq, der);
			//array_dump(a,(der + 1u));
			//printf("el pivote era: %d, ahora esta en la posicion: %u\n", a[ppiv], ppiv);
			
		if(ppiv > izq){   //ME ASEGURA QUE SIGA EL ORDEN y QUE NO HAYA PROBLEMAS CUANDO DOS ELEMENTOS SON IGUALES.
			quick_sort_rec(a, izq, ppiv - 1u);
		}

		if(der > ppiv){    //ME ASEGURA QUE SIGA EL ORDEN y QUE NO HAYA PROBLEMAS CUANDO DOS ELEMENTOS SON IGUALES.
			quick_sort_rec(a,ppiv + 1u, der);
		}
			//quick_sort_rec(a, izq, ppiv);
			//quick_sort_rec(a, ppiv + 1u, der);
		//}
	}
    /* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

