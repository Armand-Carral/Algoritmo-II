#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
    unsigned int j;
    j = i;
    while(j > 0u && goes_before(a[j], a[j-1])){
        swap(a,j-1, j);
        j = j-1;
    }

}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
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
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
        if(der > izq){
            //f(a[izq] != a[der]){  /ESTE ME ASEGURABA QUE LOS ELEMENTOS IGUALES NO TENGAN PROBLEMAS, PERO NO MANTENIA EL ORDEN/
        unsigned int ppiv = partition(a, izq, der);
            //array_dump(a,(der + 1u));
            //printf("el pivote era: %d, ahora esta en la posicion: %u\n", a[ppiv], ppiv);
            
        if(ppiv > izq){   //ME ASEGURA QUE EL ORDEN y QUE NO HAYA PROBLEMAS CUANDO DOS ELEMENTOS SON IGUALES
            quick_sort_rec(a, izq, ppiv - 1u);
        }

        if(der > ppiv){    //ME ASEGURA QUE EL ORDEN y QUE NO HAYA PROBLEMAS CUANDO DOS ELEMENTOS SON IGUALES
            quick_sort_rec(a,ppiv + 1u, der);
        }
        //}
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
