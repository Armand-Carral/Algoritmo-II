#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */
    unsigned int ppiv1 = izq;
    unsigned int i = izq + 1u;
    unsigned int j = der;
    
    while(i <= j){
    	if(goes_before(a[i], a[ppiv1])){
    		i = i + 1u;
    	}
    	else if(goes_before(a[ppiv1], a[j])){
    		j = j - 1u;
    	}
    	else{/*(a[ppiv1] < a[i] && a[j] < a[ppiv1])*/
    		swap(a,i,j);
    		i = i + 1u;
    		j = j - 1u;
    	}
    }
    swap(a, ppiv1, j);
    ppiv1 = j;

    return ppiv1;
    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
	//array_dump(a, der);
	if(der > izq){
		unsigned int ppiv = partition(a, izq, der);
		//printf("El pivote es: %d, y su posicion es: %u \n", a[ppiv], ppiv);
		if(ppiv > izq){   //ME ASEGURA QUE SIGA EL ORDEN y QUE NO HAYA PROBLEMAS CUANDO DOS ELEMENTOS SON IGUALES
			quick_sort_rec(a, izq, ppiv - 1u);
		}
		if(der > ppiv){   //ME ASEGURA QUE SIGA EL ORDEN y QUE NO HAYA PROBLEMAS CUANDO DOS ELEMENTOS SON IGUALES
			quick_sort_rec(a, ppiv + 1u, der);
		}
	}

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

