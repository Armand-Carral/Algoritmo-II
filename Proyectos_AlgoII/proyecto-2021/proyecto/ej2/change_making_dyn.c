#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "currency.h"
#include "amount.h"

static coin_t **create_array(currency_t charge, unsigned int n_coins) {
    coin_t **cam = NULL;
    n_coins = n_coins + 1u;
    charge = charge + 1u;  
    cam = (coin_t ** ) malloc (n_coins * sizeof(coin_t * ));
    for(unsigned int i = 0u; i < n_coins; ++i)
    {
        cam[i] = (coin_t * ) malloc (charge * sizeof(coin_t));
    }
    assert(cam != NULL);
    return cam;
}

static coin_t **complete_zero(coin_t **cam, unsigned int n_coins) {
    n_coins = n_coins + 1u;
    for(unsigned int i = 0u; i < n_coins; ++i)
    {
        cam[i][0] = 0u;
    }
    assert(cam != NULL);
    return cam;
}

static coin_t **complete_inf(coin_t **cam, currency_t charge) { 
    charge = charge + 1u;
    for(unsigned int j = 1u; j < charge; ++j)
    {
        cam[0][j] = amount_inf();
    }
    assert(cam != NULL);
    return cam;
}

static amount_t min2(amount_t x, amount_t y){
    amount_t minimum = 0u;
    if(amount_lt(x, y))
    {
        minimum = x;
    } else{
        minimum = y;
    }
    return minimum;
}

static coin_t **array_destroy(coin_t **cam, unsigned int n_coins){
    assert(cam != NULL);
    n_coins = n_coins + 1u;
    for(unsigned int i = 0; i < n_coins; ++i)
    {
        free(cam[i]);
        cam[i] = NULL;
    }
    free(cam);
    cam = NULL;
    return cam;
}

/** Change-Making Dynamic
@param charge    A given price money to pay with coins
@param coins     An array of coin denominations

@return The minimun amount of coins needed for pay the charge

*/
amount_t change_making_dyn(currency_t charge, coin_t *coins, unsigned int n_coins) {
    amount_t turned = amount_inf(); 
    coin_t **cam = create_array(charge, n_coins);  //El arreglo bidimensional
    cam = complete_zero(cam, n_coins);  		   //relleno el array con cero.
    cam = complete_inf(cam, charge);    		   //relleno el array con #(infinitos).
    assert(cam != NULL);
    for(unsigned int i = 1u; i < n_coins + 1u; ++i)
    {
    	for (unsigned int j = 1u; j < charge + 1u; ++j)
    	{
    		if(coins[i-1u] > j || coins[i-1u] == 0u)
    		{
    			cam[i][j] = cam[i-1u][j]; 
    		}
    		else
    		{
    			cam[i][j] = min2(cam[i-1u][j], 1u + cam[i][j-coins[i-1u]]);
    		}
    	}
    }
    turned = cam[n_coins][charge];
    cam = array_destroy(cam, n_coins);
    return turned;
}
