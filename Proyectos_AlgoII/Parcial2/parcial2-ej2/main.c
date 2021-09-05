#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "truco.h"



int main(void){

	int valor;
	char palo;
	truco_card card1 = NULL;
	truco_card card2 = NULL;
	
	printf("ingrese una carta\n");
	scanf("%d", &valor);
	printf("Ingrese su palo\n");
	scanf("%s", &palo);
	card1 = truco_card_new(valor, palo);
	
	printf("ingrese la otra carta\n");
	scanf("%d", &valor);
	printf("Ingrese su palo\n");
	scanf("%s", &palo);
	card2 = truco_card_new(valor, palo);

	if(truco_card_win(card1, card2)){
		truco_card_dump(card1);
	} else if(!truco_card_win(card1,card2)){
		truco_card_dump(card2);
	}else if(truco_card_tie(card1, card2)){
		printf("¡Las mano estan parda!\n");
		truco_card_dump(card1);
		printf("\n");
		truco_card_dump(card2);
	}

	card1 = truco_card_destroy(card1);
	card2 = truco_card_destroy(card2);
	
	return (EXIT_SUCCESS);
}
