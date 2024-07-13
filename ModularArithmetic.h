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

/**
 * Computes the division modulo m - res = a / b (mod m).
 * @param a the dividend.
 * @param b the divisor.
 * @param m the modulo value.
 * @return the quotient.
 */
int division(int a, int b, int m);


//******************************************************************************************************************//


//*******************************************//
//  UTILITY FUNCTION FOR MODULAR ARITHMETIC  //
//*******************************************//


/**
 * Computes the Greatest Common Divisor - Euclid's Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @return the gcd between n and m.
 */
int gcd(int n, int m);

/**
 * Computes the Greatest Common Divisor - Extended Euclidean Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @param x the first number of Bézout's identity.
 * @param y the second number of Bézout's identity.
 * @return the gcd between n and m.
 */
int extendedGCD(int n, int m, int *x, int *y);


/**
* Computes the modulus of 2 integers - res = n (mod m).
*
* @param n the dividend.
* @param m the divisor.
* @return the reminder of the division of n by m.
*/
int mod(int n, int m);

/**
 * Checks if 2 number are congruent modulo m - a == b (mod m).
 *
 * @param a the first number.
 * @param b the second number.
 * @param m the modulo value.
 * @return 1 if the 2 number are congruent, 0 otherwise.
 */
int areCongruent(int a, int b, int m);


/**
* Computes the modular reduction - (-n) (mod m) --> k (mod m) s.t. -n == k (mod m).
*
* @param n
* @param m
* @return
*/
int modularReduction(int n, int m);

/**
 * Computes the modular inversion - n (mod m) --> k (mod m) s.t. k == 1/n (mod m).
 *
 * @param n the number to be calculated the inverse.
 * @param m the modulo value.
 * @return the modular inverse.
 */
int modularInverse(int n, int m);


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
