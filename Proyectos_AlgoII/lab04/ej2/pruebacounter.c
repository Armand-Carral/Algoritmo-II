#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "counter.h"

int main(void){
	counter c1, c2;
	c1 = counter_init();
	c2 = counter_init();
	if(counter_is_init(c1) && counter_is_init(c2))
		printf("Estado inicial de los contadores: c1 = 0 y c2 = 0\n");
	else
		printf("Estados no inicializados\n");
	unsigned int stadeds_c = 0u;
	printf("Incretamos 3 unidades a c1, entonces los nuevos estados de c1 y c2 son:\n");
	for(unsigned int i = 0u; i<3; ++i) {
		counter_inc(c1);
		stadeds_c = stadeds_c + 1;
	}
	if(!counter_is_init(c1) && counter_is_init(c2))
		printf("Estado de los contadores: c1 = %u y c2 = 0\n", stadeds_c);
	
	printf("decrementamos 2 unidades a c1, entonces los nuevos estados de c1 y c2 son:\n");
	for(unsigned int i = 0u; i<2; ++i) {
		counter_dec(c1);
		stadeds_c = stadeds_c - 1;
	}
	if(!counter_is_init(c1) && counter_is_init(c2))
		printf("Estado de los contadores: c1 = %u y c2 = 0\n", stadeds_c);

	printf("copiamos en c2 el estado actual de c1:\n");
	c2 = counter_copy(c1);
	if(!counter_is_init(c1) && !counter_is_init(c2))
		printf("Estado de los contadores: c1 = %u y c2 = %u\n", stadeds_c, stadeds_c);
	else
		printf("No se copio el valore de c1 a  c2\n");

	return (EXIT_SUCCESS);
}