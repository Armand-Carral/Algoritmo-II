#include <stdbool.h>

#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    bool res = true;      //caso base arreglo vacio
    for (unsigned int i = 0; i < length; i++) {   //caso recursivo
    	if (i < piv){
    		if(array[i] > array[piv]) {
    			res = false;
    		}
    	}
    	if(i > piv) {
    		if(array[i] <= array[piv]) {
    			res = false;
    		}
    	}
    }

    return res;
}
