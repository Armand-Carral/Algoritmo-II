#include <assert.h>
#include "change_making.h"
#include "amount.h"
#include "set.h"
#include "currency.h"


/** Calculate the minimum
@param x A given amount
@param y A given amount

@return x if is less to y, otherwise  return y
*/
static amount_t min(amount_t x, amount_t y){
	amount_t minimum = 0u;
	if(amount_lt(x, y)){
		minimum = x;
	} else{
		minimum = y;
	}
	return minimum;
}

/** Change-Making Algorithm
@param charge    A given price money to pay with coins
@param coins     A set of coin denominations

@return The minimun amount of coins needed for pay the charge
*/
amount_t change_making(currency_t charge, set coins) {
    set_elem c;
    set coins_aux = set_empty();
    amount_t S = amount_inf();
    if(charge == 0u){
    	S = 0u;
    } else if(set_is_empty(coins)){
    	S = amount_inf();
    } else {
    	coins_aux = set_clone(coins);
        c = set_get(coins_aux);
    	coins_aux = set_elim(coins_aux,c);
    	if(c <= charge && c != 0u){
    		S = min(1 + change_making((charge-c), coins), change_making(charge, coins_aux));
    	} else{
    		S = change_making(charge, coins_aux);
    	}
        coins_aux = set_destroy(coins_aux);
    }
    return S;
}

