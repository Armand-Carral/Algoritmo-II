/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};
    
    int *p = NULL;
    person_t *k = NULL;
    p = &x;                    // Aquí p obtiene la direccion de x.
    k = &m;                    // Aquí k obtiene la direccion de m
    *p = (*k).age / 10;        // Cambio el valor de x direcciones que tiene p y k.
    (*k).age = (*k).age + 10;  // Cambio el valor de age con la direccion que tiene k.
    (*k).name_initial = 'F';   // Cambio el valor de name con la direccion que tiene k.
    p = &a[1];                 // Obtengo la direccion de a[1].
    *p = 42;                   // Cambio el valor de a[1].

    free(p);
    free(k);

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);
}
