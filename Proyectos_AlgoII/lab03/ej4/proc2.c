#include <stdio.h>

void absolute(int x, int *y) {	//int *y, recibe un puntero a un entero.
	if(x >= 0)
		*y = x; 			// *Y valor de la variable apuntada por y.
	else
		*y = -x; 
}

int main(void) {
	int res = 0;
    int a = -98;

    absolute(a, &res);         // &res, Envio la direccion de la variable (un puntero). 
    printf("res: %d\n", res);
    res = 0;
    return 0;
}

/*
void cuadrado(int *);
int main(){
	int a = 5;
	printf("Valor original = %d\n", a);

	cuadrado(&a);
	printf("Valor al cuadrado = %d\n", a);

	return 0;
}

void cuadrado(int * nro){
	*nro = *nro * *nro;
}
*/
