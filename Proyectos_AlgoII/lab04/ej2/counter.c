#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
	counter c;
	c = malloc(sizeof(struct _counter));
	c->count = 0u;
	return c;
}

void counter_inc(counter c) {
	c->count = c->count + 1u;
}

bool counter_is_init(counter c) {
	bool initial_value = c->count == 0u;
	return initial_value; 
}

void counter_dec(counter c) {
	assert(!(counter_is_init(c)));
	c->count = c->count - 1;
}

counter counter_copy(counter c) {
	counter count_copy;
	count_copy = malloc(sizeof(struct _counter));
	count_copy = c;
	return count_copy;
}

void counter_destroy(counter c) {
	free(c);
	c = NULL;
}
