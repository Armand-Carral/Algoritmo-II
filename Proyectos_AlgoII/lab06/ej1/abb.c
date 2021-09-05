#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"


struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool check_great (abb_elem e, abb tree){
    bool res = true;
    if(tree != NULL){
    res = elem_less(tree->elem, e) && 
          check_great(e, tree->left) &&
          check_great(e, tree->right);
    }
    return res;
}

static abb_elem check_small (abb_elem e, abb tree){
    bool res = true;
    if(tree != NULL){
    res = elem_less(e, tree->elem) &&
          check_small(e, tree->left) &&
          check_small(e, tree->right);
    }
    return res;
}


static bool invrep(abb tree) {
    bool res = true;
    if(tree == NULL){
        res = true;
    }
    else{
        res = check_great(tree->elem, tree->left) &&
              check_small(tree->elem, tree->right) &&
              invrep(tree->left) && invrep(tree->right);
    }
    return res;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if(tree == NULL){       /* Si cumple la condicion, entonces creo un nuevo arbol. */
        tree = malloc(sizeof(struct _s_abb));
        tree->elem = e;
        tree->left = NULL;
        tree->right = NULL;
    }
    else{
        if(elem_less(e, tree->elem)) {         /* si cumple la condicion lo agrego a la izquuierda del nodo. */
            tree->left = abb_add(tree->left, e);
        }
        else if(elem_less(tree->elem, e)){     /* entonces lo agrego a la derecha del nodo. */
            tree->right = abb_add(tree->right, e);
        }
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = tree == NULL;
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists= false;
    assert(invrep(tree));
    exists = (tree != NULL) && (elem_eq(e, tree->elem) ||
                               (elem_less(tree->elem, e) && abb_exists(tree->right,e)) || 
                               (elem_less(e, tree->elem) && abb_exists(tree->left, e)));
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length = 0;
    assert(invrep(tree));
    if(tree != NULL){
        length = 1u + abb_length(tree->left) + abb_length(tree->right); 
    }
    assert(invrep(tree) && (abb_is_empty(tree) ||  length > 0u));
    return length;
}


abb abb_remove(abb tree, abb_elem e) {  // e = 37
    assert(invrep(tree));
    if(tree->elem == e){ //tengo que eliminar 37 de la raiz entonces ahora
        if(tree->left == NULL && tree->right == NULL){
            free(tree);
            tree = NULL;
        }
        else if(tree->left == NULL){
            tree = tree->right;
        }
        else if(tree->right == NULL){
            tree = tree->left;
        }
        else{
            tree->elem = abb_max(tree->left);
            tree = abb_remove(tree->left, tree->elem);
        }
    }
    else if(e < tree->elem){      /* Ingreso al nodo izquierdo. */
        tree->left = abb_remove(tree->left, e);
    }
    else if(e > tree->elem){      /* Ingreso al nodo derecho. */
        tree->right = abb_remove(tree->right, e);
    }
    
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    max_e = tree->elem;
    if(tree->right != NULL){
        max_e = abb_max(tree->right);
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    min_e = tree->elem;
    if(tree->left != NULL){
        min_e = abb_min(tree->left);
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if(tree->left != NULL){
        tree->left = abb_destroy(tree->left);
        //free(tree->left);
        //tree->left = NULL;
    }
    if(tree->right != NULL){
        tree->right = abb_destroy(tree->right);
        //free(tree->right);
        //tree->right = NULL;
    }
    free(tree);
    tree = NULL; 
    assert(tree == NULL);
    return tree;
}

/*
void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}
*/

