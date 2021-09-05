#include "array_helpers.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    //your code here!!!
    FILE * archive;
    archive = fopen(filepath, "r");

    unsigned int size;
    size = max_size;

    fscanf(archive, "%u", &size);
    if(size <=0 ){
    	printf("El tamaño del arreglo es cero, es decir, no contiene datos almacenado.\n\n");
    	// "The size of the array is zero, that is, it does not contain stored data."
    	assert(size >0);
    }
    else{
    	for(unsigned int i = 0; i < size; i++){
    		fscanf(archive, "%d", &array[i]);
    	}
    }

  fclose(archive);
  return size;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
  assert(length > 0);
  
  printf("[");
  for(unsigned i = 0; i < length; i++){
    if(i != length-1){
      printf(" %d,", a[i]);
    }

    else{
      printf(" %d", a[i]);
    }
  }
  printf("]\n");
}

bool array_is_sorted(int a[], unsigned int max_size){
	int size = max_size;
	bool yes = true;

	for(int i=0; i < size; i++){
		for(int j=0; j<i; j++){
			if(a[j] <= a[i]){
				yes = true;
			}
			else{
				yes = false;
			}
		}
	}

	return yes;
}

bool array_swap(int a[], unsigned int i, unsigned int j){
  bool check;
  check = true;




}



