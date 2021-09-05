#include <assert.h>
#include <stdlib.h>
#include "dict.h"
#include "key_value.h"

struct _node_t {
    dict_t left;
    dict_t right;
    key_t key;
    value_t value;
};

static bool check_great (key_t k, dict_t d){
    bool check = true;
    if(d != NULL){
    check = string_less(d->key, k) && 
          check_great(k, d->left) &&
          check_great(k, d->right);
    }
    return check;
}

static bool check_small (key_t k, dict_t d){
    bool check = true;
    if(d != NULL){
    check = string_less(k, d->key) &&
          check_small(k, d->left) &&
          check_small(k, d->right);
    }
    return check;
}


static bool invrep(dict_t d) {
    bool check = true;
    if(d == NULL){
        check = true;
    }
    else{
        check = check_great(d->key, d->left) &&    //subarbol izquierdo
              check_small(d->key, d->right) &&    //subarbol derecho
              invrep(d->left) && invrep(d->right);
    }
    return check;    
}

key_t dict_max(dict_t d) {
    key_t max_key;
    assert(invrep(d));
    max_key = d->key;
    if(d->right != NULL){
        max_key = dict_max(d->right);
    }
    assert(invrep(d) && dict_exists(d, max_key));
    return max_key;
}

dict_t dict_empty(void) {
    dict_t dict = NULL;
    assert(invrep(dict) && dict_length(dict) == 0u);
    return dict;
}

dict_t dict_add(dict_t dict, key_t word, value_t def) {
    //PRE: {dict --> dict_t /\ word --> key_t /\ def --> value_t}
    assert(invrep(dict));
    if(dict == NULL){       /* Si cumple la condicion, entonces creo un nuevo arbol. */
        dict = malloc(sizeof(struct _node_t));
        dict->key = word;
        dict->value = def;
        dict->left = NULL;
        dict->right = NULL;
    }
    else{
        if(key_eq(word, dict->key)){
            dict->value = string_destroy(dict->value);
            dict->value = def;
        }
        else if(key_less(word, dict->key)) {         /* si cumple la condicion lo agrego a la izquuierda del nodo.*/
            dict->left = dict_add(dict->left, word, def);
        }
        else if(key_less(dict->key, word)){     /* entonces lo agrego a la derecha del nodo. */
            dict->right = dict_add(dict->right, word, def);
        }
    }
    //POS: {dict --> dict_t /\ key_eq(def, dict_search(dict, word))}
    assert(invrep(dict) && key_eq(def, dict_search(dict, word)));
    return dict;
}

value_t dict_search(dict_t dict, key_t word) {
    key_t def = NULL;
    //PRE: {dict --> dict_t /\ word --> key_t}
    assert(invrep(dict));
    if(dict != NULL){
        if(key_eq(word, dict->key)){
            def = dict->value;
        }
        else if(key_less(word, dict->key)){
            def = dict_search(dict->left, word);
        }
        else if(key_less(dict->key, word)){
            def = dict_search(dict->right, word);
        }
    }
    //POS: {(def != NULL) == dict_exists(dict, word)}
    assert((def != NULL) == dict_exists(dict,word));
    return def;
}

bool dict_exists(dict_t dict, key_t word) {
    bool exists = false;
    //PRE: {dict --> dict_t /\ word --> key_t}
    assert(invrep(dict));
    exists = (dict != NULL) && (key_eq(word, dict->key) ||
                               (key_less(dict->key, word) && dict_exists(dict->right,word)) || 
                               (key_less(word, dict->key) && dict_exists(dict->left, word)));
    //POS: {dict --> dict_t}
    assert(invrep(dict));
    return exists;
}

unsigned int dict_length(dict_t dict) {
    unsigned int length = 0u;
    assert(invrep(dict));
    if(dict != NULL){
        length = 1u + dict_length(dict->left) + dict_length(dict->right); 
    }
    assert(invrep(dict));
    return length;
}

dict_t dict_remove(dict_t dict, key_t word) {
    //PRE: {dict --> dict_t /\ word --> key_t}
    assert(invrep(dict));
    if(key_eq(dict->key, word)){ //tengo que eliminar 37 de la raiz entonces ahora
        if(dict->left == NULL && dict->right == NULL){
            //dict->value = value_destroy(dict->value);
            //dict->key = key_destroy(dict->key);
            free(dict);
            dict = NULL;
        }
        else if(dict->left == NULL){
            dict = dict->right;
        }
        else if(dict->right == NULL){
            dict = dict->left;
        }
        else{
            dict->key = dict_max(dict->left);           //Como reemplazar abb_max
            dict = dict_remove(dict->left, dict->key);
        }
    }
    else if(key_less(word, dict->key)){                // Ingreso al nodo izquierdo.
        dict->left = dict_remove(dict->left, word);
    }
    else if(key_less(dict->key, word)){                // Ingreso al nodo derecho.
        dict->right = dict_remove(dict->right, word);
    }
    //POS: {dict --> dict_t /\ !dict_exists(dict, word)}
    assert(invrep(dict) && !dict_exists(dict, word));
    return dict;
}

// Removes all the words from the dictionary.
dict_t dict_remove_all(dict_t dict) {
    //PRE: {dict --> dict_t}
    assert(invrep(dict));
    if(dict != NULL){           //
        if(dict->left != NULL){
            dict->left = dict_remove_all(dict->left);
        }
        if(dict->right != NULL){
            dict->right = dict_remove_all(dict->right);
        }
        free(dict);
        dict = NULL;
    }    
    assert(invrep(dict) && dict_length(dict) == 0u);
    //POS: {dict --> dict_t /\ dict_length(dict) == 0}
    return dict;
}

void dict_dump(dict_t dict, FILE *file) {
    assert(invrep(dict) && file != NULL);
    if (dict != NULL) {
        printf("%s : %s\n\n", string_ref(dict->key), string_ref(dict->value));
        dict_dump(dict->left, stdout);
        dict_dump(dict->right, stdout);
    }
}

dict_t dict_destroy(dict_t dict) {
    assert(invrep(dict));
    if(dict != NULL ){
        if(dict->left != NULL){
            dict->left = dict_destroy(dict->left);
        }
        if(dict->right != NULL){
            dict->right = dict_destroy(dict->right);
        }
    }
    free(dict);
    dict = NULL; 

    assert(dict == NULL);
    return dict;
}

