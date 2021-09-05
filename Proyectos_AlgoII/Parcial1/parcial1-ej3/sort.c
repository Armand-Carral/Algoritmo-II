/*
  @file sort.c
  @brief sort functions implementation
*/
#include <stdbool.h>
#include "helpers.h"
#include "sort.h"
#include "song.h"


bool goes_before(song_t s1, song_t s2) {
    return s1.seconds <= s2.seconds;
}

bool array_is_sorted(song_t playlist[], unsigned int length) {
    unsigned int i = 0u;
    bool sorted = true;
    while (i + 1 < length && sorted) {
        sorted = goes_before(playlist[i], playlist[i + 1]);
        i = i + 1;
    }
    return sorted;
}

bool array_is_odd_sorted(song_t playlist[], unsigned int length) {
    // -- Completar --
    unsigned int i = 1u;
    bool odd_sorted = true;
    while(i + 2 < length && odd_sorted) {
        odd_sorted = goes_before(playlist[i], playlist[i + 2]);
        i = i + 2;
    }
    return odd_sorted;
}

