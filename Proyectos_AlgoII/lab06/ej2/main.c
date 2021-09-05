#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"


int main(){

	char *cadena1 = calloc(4,sizeof(char)); 
	char *cadena2 = calloc(6,sizeof(char));

	printf("ingrese una palabra\n");
	fflush(stdin);
	scanf("%s\n", cadena1);
	string word1 = string_create(cadena1);
	printf("El tamaño de la cadena1: %u\n", string_length(word1));

	printf("Ingrese otra palabra\n");
	fflush(stdin);
	scanf("%s\n", cadena2);
	string word2 = string_create(cadena2);
	printf("El tamaño de la cadena2: %u\n", string_length(word2));

	if(string_less(word1, word2)){
		printf("cadena1 es menor que cadena2\n");
	}
	else if(string_eq(word1, word2)){
		printf("cadena1 y cadena2 son iguales\n");
	}
	else{
		printf("cadena1 es mayor que cadena2\n");
	}

	word1 = string_destroy(word1);
	word2 = string_destroy(word2);


	return(EXIT_SUCCESS);
}

/*
int main(){

	char *cadena1 = "armand"; 
	char *cadena2 = "armand";

	string word1 = string_create(cadena1);
	string word2 = string_create(cadena2);

	printf("El tamaño de la cadena1: %u\n", string_length(word1));

	printf("El tamaño de la cadena2: %u\n", string_length(word2));

	if(string_less(word1, word2)){
		printf("cadena1 es menor que cadena2\n");
	}
	else if(string_eq(word1, word2)){
		printf("cadena1 y cadena2 son iguales\n");
	}
	else{
		printf("cadena1 es mayor que cadena2\n");
	}

	word1 = string_destroy(word1);
	word2 = string_destroy(word2);


	return(EXIT_SUCCESS);
}
*/