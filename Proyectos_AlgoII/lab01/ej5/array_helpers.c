#include "array_helpers.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    //your code here!!!
  FILE * archive;
  archive = fopen(filepath, "r");

  int size;
  size = max_size;

  fscanf(archive, "%d", &size);
  if(size <0 ){
    printf("El tamaño del arreglo es incorrecto.\n\n");
    assert(size >=0);
  }
  
  else{
      for(int i = 0; i < size; i++){
      fscanf(archive, "%d", &array[i]);
    }
  }

  fclose(archive);
  return size;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
  int tam = length;
  assert(tam >= 0);
  
  printf("El tamaño del arreglo es %d. \n", tam);

  printf("[");
  for(int i = 0; i < tam; i++){
    if(i != tam-1){
      printf(" %d,", a[i]);
    }

    else{
      printf(" %d", a[i]);
    }
  }
  printf("]\n");
}


boolean array_is_sorted(int a[], unsigned int max_size){
	int size = max_size;
	boolean yes = true;

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