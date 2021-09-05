#include <stdlib.h>
#include <assert.h>
#include "item.h"
#include "knapsack.h"
#include "set.h"

struct _s_knap {
    set packed_items;
    weight_t weight_total;
    value_t value_total;
    weight_t capacity;
};

static bool invrep(knapsack k) {
    bool check = false;
    if(k != NULL){
        check = k->weight_total <= k->capacity;
    }
    return check;
}


knapsack knapsack_empty(unsigned int capacity) {
    knapsack k = calloc(1, sizeof(struct _s_knap));
    k->packed_items = set_empty();
    k->weight_total = 0u;
    k->value_total = 0u;
    k->capacity = capacity;
    assert(invrep(k));
    return k;
}

knapsack knapsack_clone(knapsack k) {
    assert(invrep(k));
    knapsack k_copy = knapsack_empty(k->capacity);
    k_copy->packed_items = set_clone(k->packed_items);
    k_copy->weight_total += k->weight_total;
    k_copy->value_total += k->value_total;
    assert(invrep(k));
    return k_copy;
}

knapsack knapsack_pack(knapsack k, item_t item) {
    assert(invrep(k) && knapsack_can_hold(k, item));
    k->packed_items = set_add(k->packed_items, item);
    k->weight_total = k->weight_total + item_weight(item);
    k->value_total = k->value_total + item_value(item);
    assert(invrep(k));
    return k;
}

bool knapsack_greater_value(knapsack k1, knapsack k2) {
    assert(invrep(k1) && invrep(k2));
    return k2->value_total < k1->value_total;
}

bool knapsack_is_full(knapsack k) {
    assert(invrep(k));
    return k->capacity == k->weight_total;
}

bool knapsack_can_hold(knapsack k, item_t item) {
    assert(invrep(k));
    weight_t sum = k->weight_total + item_weight(item);
    return sum <= k->capacity;   // retorna true si sum no excede k->capacity, caso contrario es false.
}

weight_t knapsack_capacity(knapsack k) {
    assert(invrep(k));
    return k->capacity;
}

weight_t knapsack_weight(knapsack k) {
    assert(invrep(k));
    return k->weight_total;
}

value_t knapsack_value(knapsack k) {
    assert(invrep(k));
    return k->value_total;
}

void knapsack_dump(knapsack k) {
    weight_t capacity, remind;
    assert(invrep(k));
    capacity = knapsack_capacity(k);
    remind = capacity - knapsack_weight(k);
    printf("knapsack value   : $%u\n", knapsack_value(k));
    printf("knapsack capacity: %u\n", capacity);
    printf("knapsack remind  : %u\n", remind);
    printf("**** packed items ****\n");
    set_dump(k->packed_items);
}

knapsack knapsack_destroy(knapsack k) {
    assert(invrep(k));
    k->packed_items = set_destroy(k->packed_items);
    free(k);
    k = NULL;
    return k;
}

