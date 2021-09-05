#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "truco.h"

struct _s_truco_card {
    int carta;
    char palo;
};

#define ESPADA "ESPADA"
#define BASTO  "BASTO"
#define ORO    "ORO"
#define COPA   "COPA"

static const char *suit_str(char p) {
    const char *str;
    if (p == 'e') {
        str = ESPADA;
    } else if (p=='b') {
        str = BASTO;
    } else if (p=='o') {
        str = ORO;
    } else if (p=='c') {
        str = COPA;
    }
    return str;
}

static void dump(int num, char suit) {
    printf(" ----------------\n"
           " : %2d           :\n"
           " :              :\n"
           " :              :\n"
           " :    ""%-7s""   :\n"
           " :              :\n"
           " :              :\n"
           " :              :\n"
           " :           %2d :\n"
           " ----------------\n",
           num, suit_str(suit), num);
}

static int card_rank(int num, char suit) {
    int rank=0;

    if (4 <= num && num <= 12) { // 4 ~ 12
        rank = num;
    } else { // 1 ~ 3
        if(num == 1 && (suit == 'c' || suit == 'o')){
            rank = num;
        }
        else if(2 <= num && num <= 3){
            rank = num;
        }
    }
    // 0 <= rank <= 11
    if (num==1 && suit == 'e') {      // Ancho de espadas
        rank = num;
    } else if (num==1 && suit=='b') { // Ancho de bastos
        rank = num;
    } else if (num==7 && suit=='e') { // Siete de espadas
        rank = num;
    } else if (num==7 && suit=='o') { // Siete de oro
        rank = num;
    }
    return rank;
}

static bool invrep(truco_card c) {
    bool valid_card=false;
    if((1 <= c->carta && c->carta <= 12) && (c->carta != 8) && (c->carta != 9)){
        if( c->palo== 'e' || c->palo=='o' || c->palo=='c' || c->palo == 'b'){
            valid_card = true;
        }
    }
    return valid_card;
}

truco_card truco_card_new(int num, char p) {
    truco_card card;
    card = malloc(sizeof(struct _s_truco_card));
    card->carta = num;
    card->palo = p;
    assert(invrep(card));
    return card;
}

bool truco_card_win(truco_card a, truco_card b) {
    bool card_a_win = card_rank(a->carta, a->palo) > card_rank(b->carta, b->palo);
    return card_a_win;
}

bool truco_card_tie(truco_card a, truco_card b) {
    bool is_a_tie = card_rank(a->carta, a->palo) == card_rank(b->carta, b->palo);
    return is_a_tie;
}

void truco_card_dump(truco_card c) {
    dump(c->carta, c->palo);
}

truco_card truco_card_destroy(truco_card c) {
    free(c);
    c = NULL;
    return c;
}
