/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

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

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* create a copy of the array, to do some checks later */
    int copy[MAX_SIZE];
    array_copy(copy, array, length);

    /* reset counters and set time */ //restablecer el contador y configura el timepo
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();
    
    /* do the actual sorting */
    selection_sort(copy, length);

    /* show statistics for selection_sort */
    printf("statistics for selection_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());
    
    /* all the same for insertion_sort */
    /* Usando la idea de las líneas de códigos anteriores
       muestre las estadísticas (tiempo de ejecución, número de comparaciones e 
       intercambios realizados) para insertion_sort. No te olvides que antes debes
       copiar el arreglo original, resetear los contadores y setear el tiempo.  
    */
    /* needs implementation */
    array_copy(copy, array, length);

    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    insertion_sort(copy, length);

    printf("statistics for insertion_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());
    
    /* all the same for quick_sort */
    /* Usando la idea de las líneas de códigos anteriores
       muestre las estadísticas (tiempo de ejecución, número de comparaciones e 
       intercambios realizados) para quick_sort. No te olvides que antes debes
       copiar el arreglo original, resetear los contadores y setear el tiempo.  
    */
    /* needs implementation */
    array_copy(copy, array, length);

    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();

    quick_sort(copy, length);

    printf("statistics for quick_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());
    
    /* check if it is sorted */
    assert(array_is_sorted(copy, length));

    /* check if it is a permutation of original */
    assert(array_is_permutation_of(copy, array, length));
    return (EXIT_SUCCESS);
}
