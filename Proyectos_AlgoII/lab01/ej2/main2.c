/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

unsigned int array_from_file(int array[], unsigned int max_size) {
    //your code here!!!
  FILE * archive;
  archive = stdin;

  printf("Ingrese el tamaño del arreglo mayor a cero: \n");
  fscanf(archive, "%u", &max_size);

  //verificamos que el tamaño del arreglo sea mayor cero.
  if(max_size <=0){
    printf("El tamaño del arreglo es incorrecto.\n");
    //"The size of the array is zero."
    assert(max_size >0);
  }
  
  else{
    printf("ingrese los valores\n");
    for(unsigned int i = 0; i < max_size; i++){
      fscanf(archive, " %d", &array[i]);
    }
  }

  fclose(archive);
  return max_size;

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


int main() {  /*int argc, char *argv[]*/
    //har *filepath = NULL;

    /* parse the filepath given in command line arguments */
    //filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return (EXIT_SUCCESS);
}
