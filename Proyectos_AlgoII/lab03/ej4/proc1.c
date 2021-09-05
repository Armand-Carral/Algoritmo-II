#include <stdio.h>

void absolute(int x, int y) {
	if(x >= 0)
		y = x; 
	else
		y = -x; 
}

int main(void) {
    int res = 0;
    int a = -98;

    absolute(a, res);
    printf("res: %d\n", res);
    res = 0;
    /* Respuesta a la 1°pregunta(T/P): Deberia mostra res = 98
       Respuesta a la 2°pregunta: Se muetra res = 0,
       lo cual no coincide con el lenguaje del teorico.
    */
    return 0;
}

