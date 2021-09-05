#include <stdio.h>
#include <assert.h>
#include "boolean.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath);

boolean array_is_sorted(int a[], unsigned int max_size);

void array_dump(int a[], unsigned int length);



