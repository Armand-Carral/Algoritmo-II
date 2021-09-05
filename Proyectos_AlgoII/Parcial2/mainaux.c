#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"


int main(void){

	int num;
	printf("ingrese un valor\n");
	scanf("%d", &num);
	printf("hola mundo, son las %d a.m\n", num);

	return (EXIT_SUCCESS);
}