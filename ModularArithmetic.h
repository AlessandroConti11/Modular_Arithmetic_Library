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

/**
 * Computes the square root modulo p of a number.
 * @details Tonelli-Shanks algorithm
 * @warning work iff the modulo value is a prime number.
 *
 * @param a the number whose square root is to be calculated.
 * @param p the modulo value - must be a prime number.
 * @return the square roots modulo p of the number.
 */
int *TonelliShanksAlgorithm(int a, int p);

/**
 * Computes the square roots modulo n of a number.
 *
 * @param a the number whose square root is to be calculated.
 * @param n the modulo value.
 * @param numberOfSquareRoots the number of square roots.
 * @return the square roots modulo n of the number.
 */
int *squareRoot(int a, int n, int *numberOfSquareRoots);

/**
 * Computes the discrete logarithm modulo n of a number.
 * @details Baby-Step Giant-Step algorithm.
 * @details b = a^x (mod n) where x = Log_(a) (b).
 *
 * @param a the logarithm base.
 * @param b the number.
 * @param n the modulo value.
 * @return the discrete logarithm modulo n.
 */
int discreteLogarithm(int a, int b, int n);


//******************************************************************************************************************//


//*******************//
//  EQUATION MODULO  //
//*******************//


/**
 * Computes the solution of a system of modular linear equations.
 * @details Chinese Reminder Theorem.
 * @example x = a1 (mod m1)
 * @example ...
 * @example x = ai (mod mi)
 *
 * @param numberOfEquation the number of equations of the linear system.
 * @param ... the equation values - ai, mi.
 * @return the solution of the system of modular linear equations.
 */
int chineseRemainderTheorem(int numberOfEquation, ...);

/**
 * Computes the solution of a linear diophantine equation.
 * @details ax + by = c
 * @details all value are integer.
 *
 * @param a the first parameter of the diophantine equation.
 * @param x the value of the first unknown to be computed.
 * @param b the second parameter of the diophantine equation.
 * @param y the value of the second unknown to be calculated
 * @param c the third parameter of the diophantine equation.
 */
void diophantineEquation(int a, int *x, int b, int *y, int c);


//******************************************************************************************************************//


//***************//
//  TEST MODULO  //
//***************//


/**
 * Checks if two numbers are congruent modulo m.
 * @details a == b (mod m).
 *
 * @param a the first number.
 * @param b the second number.
 * @param m the modulo value.
 * @return 1 if the 2 number are congruent, 0 otherwise.
 */
int areCongruent(int a, int b, int m);

/**
 * Checks if two numbers are coprime
 * @details a ⟂ n iff gcd(a, n) == 1.
 *
 * @param a the first number.
 * @param n the second number.
 * @return 1 if the 2 number are coprime, 0 otherwise.
 */
int areCoPrime(int a, int n);

/**
 * Checks if the first number is a divisor of the second number.
 *
 * @param n the first number.
 * @param m the second number.
 * @return 1 if the first number is a divisor of the second number, 0 otherwise.
 */
int isDivisor(int n, int m);

/**
 * Checks if a number is Fermat's Pseuodoprime to a.
 * @details let a ⟂ n
 * @if a^(n - 1) (mod n) == 1 --> n is Fermat's Pseudoprime
 * @else n is NOT prime
 * @endif
 *
 * @param a the first number.
 * @param n the second number.
 * @returns 1 if the number is Fermat's Pseuodprime to a, 0 otherwise.
 */
int isFermatPseudoPrime(int a, int n);

/**
 * Checks if a number is a prime number.
 * @details Eratosthenes sieve.
 *
 * @param n the number whose primality is to be tested.
 * @return 1 if the number is prime, 0 otherwise.
 */
int isPrime(int n);

/**
 * Checks if a number admits the square root in modulus n.
 * @details a is a quadratic residue modulo n
 * @details if: exist x st x^2 = a (mod n).
 *
 * @param a the number whose square root we want to know if it is possible to calculate.
 * @param n the modulo value.
 * @return 1 if the number allows for the square root, 0 otherwise.
 */
int isSquareNumber(int a, int n);

/**
 * Checks is a number is a primitive root modulo n.
 * @details an integer whose powers modulo n are congruent with numbers coprime to n.
 *
 * @param a the number to check if it is primitive root modulo n.
 * @param n the modulo value.
 * @return 1 if the number is a primitive root modulo n, 0 otherwise.
 */
int isPrimitiveRoot(int a, int n);


//******************************************************************************************************************//


//*******************************************//
//  UTILITY FUNCTION FOR MODULAR ARITHMETIC  //
//*******************************************//


/**
 * Checks if a number is a perfect square.
 * @details x = sqrt(n)
 * @details if n == x * x --> n is a perfect square
 *
 * @param n the number.
 * @return 1 if the number is a perfect quare, 0 otherwise.
 */
int isPerfectSquare(int n);

/**
 * Checks if a number is in a list.
 *
 * @param list the list to check.
 * @param listSize the list size.
 * @param value the number to be found.
 * @param position the location where the searched value is - NOT necessary.
 * @return 1 if the value was found, 0 otherwise.
 */
int isListed(int *list, int listSize, int value, int *position);


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
 * Computes the modulus of two integers.
 * @details res = n (mod m).
 *
 * @param n the dividend.
 * @param m the divisor.
 * @return the reminder of the division of n by m.
 */
int mod(int n, int m);

/**
 * Computes a number congruent with the one given.
 * @details res == a (mod m).
 *
 * @param a the number.
 * @param m the modulo value.
 * @return a number congruent with the one given.
 */
int congruentNumber(int a, int m);


/**
 * Computes the modular reduction.
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


/**
 * Factorizes a number by splitting it into two of its dividends.
 * @details Fermat's factorisation method.
 *
 * @param n the number.
 * @return the two factors that make up the number.
 */
int *realFermatFactorisation(int n);

/**
 * Factorizes a number by splitting it into all of its dividends.
 * @details Fermat's factorization method.
 *
 * @param n the number.
 * @param factors the number of factors.
 * @return the factors that make up the number.
 */
int *FermatFactorisation(int n, int *factors);

/**
 * Factorizes a number by splitting it into all of its dividends.
 *
 * @param n the number.
 * @param factors the number of factors.
 * @return the factors that make up the number.
 */
int *factorisation(int n, int *factors);


/**
 * Computes the value of the Euler function for the given number.
 * @details φ(n).
 *
 * @param n the number.
 * @return the value of Euler's function.
 */
int EulerFunction(int n);


/**
 * Computes the list of prime numbers up to the n-th.
 * @details Eratosthenes sieve.
 *
 * @param n the maximum number within which to search for prime numbers.
 * @param primeSize the number of prime numbers found up to the n-th number.
 * @return the list of prime numbers up to the n-th.
 */
int *EratosthenesSieve(int n, int *primeSize);

/**
 * Searches for the n-th prime number.
 * @details Eratosthenes sieve.
 *
 * @param n the n-th prime number to be found.
 * @return the n-th prime number.
 */
int nthPrimeNumber(int n);

/**
 * Founds the prime number following a given number.
 *
 * @param n the number whose next prime number is to be found.
 * @return the prime number following the given number.
 */
int nextPrimeNumber(int n);


/**
 * Computes the list of primitive roots modulo n.
 *
 * @param n the modulo value.
 * @param primitiveRootsSize the number of primitive root modulo n.
 * @return the list of primitive roots modulo n.
 */
int *primitiveRoots(int n, int *primitiveRootsSize);

/**
 * Computes the list of quadratic residuals modulo n.
 *
 * @param n the modulo value.
 * @param quadraticResidualSize the number of quadratic residuals modulo n.
 * @return the list of quadratic residuals modulo n.
 */
int *quadraticResiduals(int n, int *quadraticResidualSize);


//******************************************************************************************************************//


/*
 * residui di gauss
 * simbolo di legendre a, n
 *  0 se a|p
 *  1 a residuo quadratico
 *  -1 a non-residuo quadratico
 * simbolo di Jacobi
 *  fattori di n
 *  productory (simboli di legendre a, factor_i)^#di_volte_che_compare_fattore
 *
 * matrici:
 *  somma
 *  differenza
 *  prodotto
 *  inverso
 *  determinante
 */

#endif
