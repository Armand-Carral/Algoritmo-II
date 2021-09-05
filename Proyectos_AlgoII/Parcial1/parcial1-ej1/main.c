#include <stdio.h>
#include <stdbool.h>

#include "pivot.h"
#include "odd.h"

#define LONGITUD 2

int main (){

    int array [LONGITUD] = {6,1};
    /*unsigned int pivot;
    printf("ingrese el arreglo:\n");
    for (unsigned int i = 0; i < LONGITUD; ++i){
        scanf("%d" , &array[i]);
    }
    printf("ingrese el pivot\n");
    scanf("%u", &pivot);
    */

    //bool res = is_pivot(array, LONGITUD, pivot);
    bool res = is_odd_sorted(array, LONGITUD)
    if(res == 1){
        printf("cumple la ordenacion\n");
    }
    else if (res == 0) {
        printf("No cumple la ordenacion\n");
    }

    return 0;
}
