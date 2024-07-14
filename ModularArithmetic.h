#ifndef MODULARARITHMETIC_H

#define MODULARARITHMETIC_H


//*********************//
//  MODULAR OPERATION  //
//*********************//


/**
 * Computes the sum modulo m.
 * @details res = a + b (mod m).
 *
 * @param a the first addend.
 * @param b the second addend.
 * @param m the modulo value.
 * @return the sum modulo m.
 */
int sum(int a, int b, int m);

/**
 * Computes the difference modulo m.
 * @details res = a - b (mod m).
 *
 * @param a the minuendo.
 * @param b the subtrahend.
 * @param m the modulo value.
 * @return the difference modulo m.
 */
int sub(int a, int b, int m);

/**
 * Computes the product modulo m.
 * @details res = a * b (mod m).
 *
 * @param a the first factor.
 * @param b the second factor.
 * @param m the modulo value.
 * @return the product modulo m.
 */
int product(int a, int b, int m);

/**
 * Computes the division modulo m.
 * @details res = a / b (mod m).
 *
 * @param a the dividend.
 * @param b the divisor.
 * @param m the modulo value.
 * @return the quotient.
 */
int division(int a, int b, int m);

/**
 * Computes the power elevation modulo m.
 * @details Square and Multiply algorithm.
 * @details res = a^exp (mod m).
 *
 * @param a the base.
 * @param exp the exponent.
 * @param m the modulo value.
 * @return the power elevation modulo m.
 */
int power(int a, int exp, int m);


//******************************************************************************************************************//


//*******************************************//
//  UTILITY FUNCTION FOR MODULAR ARITHMETIC  //
//*******************************************//


/**
 * Computes the Greatest Common Divisor.
 * @details Euclid's Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @return the gcd between n and m.
 */
int gcd(int n, int m);

/**
 * Computes the Greatest Common Divisor.
 * @details Extended Euclidean Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @param x the first number of Bézout's identity.
 * @param y the second number of Bézout's identity.
 * @return the gcd between n and m.
 */
int extendedGCD(int n, int m, int *x, int *y);


/**
 * Computes the modulus of 2 integers.
 * @details res = n (mod m).
 *
 * @param n the dividend.
 * @param m the divisor.
 * @return the reminder of the division of n by m.
 */
int mod(int n, int m);


/**
 * Computes the modular reduction .
 * @details (-n) (mod m) --> k (mod m) s.t. -n == k (mod m).
 *
 * @param n the number to transform.
 * @param m the modulo value.
 * @return the modular reduction.
 */
int modularReduction(int n, int m);

/**
 * Computes the modular inversion.
 * @details n (mod m) --> k (mod m) s.t. k == 1/n (mod m).
 *
 * @param n the number to be calculated the inverse.
 * @param m the modulo value.
 * @return the modular inverse.
 */
int modularInverse(int n, int m);


//******************************************************************************************************************//


//***************//
//  TEST MODULO  //
//***************//


/**
 * Checks if 2 number are congruent modulo m.
 * @details a == b (mod m).
 *
 * @param a the first number.
 * @param b the second number.
 * @param m the modulo value.
 * @return 1 if the 2 number are congruent, 0 otherwise.
 */
int areCongruent(int a, int b, int m);

/**
 * Checks if 2 number are coprime
 * @details a ⟂ n iff gcd(a, n) == 1.
 *
 * @param a the first number.
 * @param n the second number.
 * @return 1 if the 2 number are coprime, 0 otherwise.
 */
int areCoPrime(int a, int n);

/**
 * Checks if n is Fermat's Pseuodoprime to a.
 * @details let a ⟂ n
 * @details if a^(n - 1) (mod n) == 1 --> n is Fermat's Pseudoprime
 * @details otherwise --> n is NOT prime
 *
 * @param a the first number.
 * @param n the second number.
 * @returns 1 if n is Fermat's Pseuodprime to a, 0 otherwise.
 */
int FermatPseudoprime(int a, int n);


/*
 * numeri primi
 * fattorizzazione
 *  fattorizzazione di Fermat
 *  algoritmo di fattorizzazione p-1
 * più piccolo primo dopo x
 * funzione di eulero
 * funzione di eulero-fermat
 * th fermat
 * th cinese del resto
 * funzione zeta di rieman
 * equazioni dioofantine
 * congruenze
 * residui di gauss
 * radici primitive
 * residuo quadratico
 *
 * matrici:
 *  somma
 *  differenza
 *  prodotto
 *  inverso
 *  determinante
 */

#endif
