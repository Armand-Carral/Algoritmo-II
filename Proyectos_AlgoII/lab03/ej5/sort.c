/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    bool before = x->rank <= y->rank;
    return before;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}
void swap(player_t a[], unsigned int i, unsigned int j){
    player_t temp = 0;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
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
        else{ /*(a[ppiv1] < a[i] && a[j] < a[ppiv1])*/
            swap(a,i,j);
            i = i + 1u;
            j = j - 1u;
        }
    }
    swap(a, ppiv1, j);
    ppiv1 = j;

    return ppiv1;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
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
void sort(player_t a[], unsigned int length) {
    // completar aquí
        quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

