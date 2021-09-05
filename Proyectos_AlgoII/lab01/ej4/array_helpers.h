#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath);

bool array_is_sorted(int a[], unsigned int max_size);

void array_dump(int a[], unsigned int length);




