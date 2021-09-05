#include <stdbool.h>

#include "odd.h"


bool is_odd_sorted(int array[], unsigned int length) {
    bool res = true;
    int aux = array[1]; 
    for(unsigned int i = 0; i < length; ++i) {
    	if(i%2 == 1) {
    		if(aux > array[i]) {
    			res = false;
    		}
    	}
    }
    return res;
}
