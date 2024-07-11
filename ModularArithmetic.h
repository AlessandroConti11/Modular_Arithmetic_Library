#ifndef MODULARARITHMETIC_H

#define MODULARARITHMETIC_H


//*********************//
//  MODULAR OPERATION  //
//*********************//


/**
 * Computes the sum modulo m - res = a + b (mod m).
 *
 * @param a the first addend.
 * @param b the second addend.
 * @param m the modulo value.
 * @return the sum modulo m.
 */
int sum(int a, int b, int m);

/**
 * Computes the difference modulo m - res = a - b (mod m).
 *
 * @param a the minuendo.
 * @param b the subtrahend.
 * @param m the modulo value.
 * @return the difference modulo m.
 */
int sub(int a, int b, int m);

/**
 * Computes the product modulo m - res = a * b (mod m).
 *
 * @param a the first factor.
 * @param b the second factor.
 * @param m the modulo value.
 * @return the product modulo m.
 */
int product(int a, int b, int m);


//******************************************************************************************************************//


//*******************************************//
//  UTILITY FUNCTION FOR MODULAR ARITHMETIC  //
//*******************************************//


/**
 * Compute the Greatest Common Divisor - Euclid's Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @return the gcd between n and m.
 */
int gcd(int n, int m);

/**
* Computes the modulus of 2 integers - res = n (mod m).
*
* @param n the dividend.
* @param m the divisor.
* @return the reminder of the division of n by m.
*/
int mod(int n, int m);

/**
* Computes the modular reduction - (-n) (mod m) --> k (mod m) s.t. -n == k (mod m).
*
* @param n
* @param m
* @return
*/
int modularReduction(int n, int m);


//******************************************************************************************************************//


/*
 * numeri primi
 * più piccolo primo dopo x
 * test di primalità
 * funzione di eulero
 * funzione di eulero-fermat
 * th fermat
 * th cinese del resto
 * funzione zeta di rieman
 * equazioni dioofantine
 * congruenze
 * residui di gauss
 *
 * matrici:
 *  somma
 *  differenza
 *  prodotto
 *  inverso
 *
 */

#endif
