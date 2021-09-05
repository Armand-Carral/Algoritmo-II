#include <stdio.h>
#include <stdlib.h>

int main(){
	int var = 7;
	int var2 = 3;
	int *p = NULL;
	printf("Valores inciales: \n");
	printf("var: %d\n", var);
	printf("var2: %d\n", var2);
	printf("p: %p\n", p);
	p = &var2;
	*p = var;
	printf("\nCambiamos el valor de var2 por el valor de var usando el puntero p, luego nos queda\n");
	printf("var: %d\n", var);
	printf("var2: %d\n", var2);
	printf("direccion de var: %p\n", &var);
	printf("direccion de var2: %p\n", &var2);
	printf("Aqui vemos que p tiene la direccion de var2: \n");
	printf("p: %p\n", p);
	printf("Fue a está direccion y cambio el valor de var2 \n");
	printf("\nAhora a p le asigno devuelta la direccion NULL, para que no quede a la deriva\n");
	p = NULL;
	printf("p: %p\n", p);
	

	int x = 3;
	int y = 10;
	/* en 'y' se va a guardar el valor de x, 
	porque primero obtiene la direccion de 'x' con el &, es decir '&x', 
	luego con '*' le asigno el valor que está en la drieccion de &x a la variable 'y',
	enotnces 'y' va a valer '3' */
	y = *(&x);
	printf("x vale: %d;\ny vale: %d \n", x, y);

	return (EXIT_SUCCESS);
}