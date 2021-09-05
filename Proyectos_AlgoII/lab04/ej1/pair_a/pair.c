#include "pair.h"

pair_t pair_new(int x, int y)
{
	pair_t new_pair = {x, y};
	return new_pair;
}

int pair_first(pair_t p)
{
	return p.fst;
}

int pair_second(pair_t p)
{
	return p.snd;
}

pair_t pair_swapped(pair_t p)
{
	pair_t swap = {p.fst, p.snd};
	return swap;
}

pair_t pair_destroy(pair_t p)
{
	return p;
}