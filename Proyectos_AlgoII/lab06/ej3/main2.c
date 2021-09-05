/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "dict.h"
#include "dict_helpers.h"
#include "helpers.h"
#include "string.h"

#define RESULT_PREFIX "\t-> "

string get_input(const char *message) {
    string result = NULL;
    printf("\t%s: ", message);
    result = readstring_from_stdin();
    assert(result != NULL);
    return (result);
}

dict_t on_add(dict_t current) {
    string definition = NULL;
    string word = NULL;
    word = get_input("Please enter the word to add into the dict");
    if (dict_exists(current, word)) {
        printf(RESULT_PREFIX "The word is already in the dict.\n");
        word = string_destroy(word);
    } else {
        definition = get_input("Please enter the definition");
        current = dict_add(current, word, definition);
        printf(RESULT_PREFIX "The word and definition were added.\n");
    }
    return (current);
}

dict_t on_remove(dict_t current) {
    string word =
            get_input("Please enter the word to delete from the dict");
    if (!dict_exists(current, word)) {
        printf(RESULT_PREFIX "The word does not exist in the dict.\n");
    } else {
        current = dict_remove(current, word);
        printf(RESULT_PREFIX "The word was removed.\n");
    }
    word = string_destroy(word);
    return (current);
}

int main(void){

	dict_t current = dict_empty();

	printf("ingrese una palabra:\n");
	current = on_add(current);

	printf("\ningrese otra palabra:\n");
	current = on_add(current);

	printf("\ningrese otra palabra:\n");
	const char *word1 = "jirafa";
	const char *def1 = "animal";
	string word2 = string_create(word1);
	string def2 = string_create(def1);

	current = dict_add(current, word2, def2);

    dict_dump(current, stdout);
    
    current = on_remove(current);

    dict_dump(current, stdout);
    

	return(EXIT_SUCCESS);
}