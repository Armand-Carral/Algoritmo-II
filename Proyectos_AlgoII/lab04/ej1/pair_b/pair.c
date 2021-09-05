#include <stdlib.h>
#include "pair.h"

pair_t pair_new(int x, int y) {
	pair_t new_pair;	//esto es un "puntero de esctrutura" ya no es una estructura misma.
	new_pair = malloc(sizeof(struct s_pair_t));
	//Hasta ahora defini un puntero y, pedi memoria de tamañano del tipo struct s_pair_t.
	new_pair->fst = x;
	new_pair->snd = y;
	return new_pair;
	//Ahora rellene mi puntero con la variable que me dieron, es decir 'x'e 'y', y por fin arme mi puntero de estructura.
}

int pair_first(pair_t p) {
	return p->fst;
}

int pair_second(pair_t p) {
	return p->snd;
}

pair_t pair_swapped(pair_t p) {
	return pair_new(p->snd, p->fst);
}


pair_t pair_destroy(pair_t p) {
	free(p);
	p = NULL;
	return p;
}