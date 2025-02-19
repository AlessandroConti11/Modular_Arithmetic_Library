#include <assert.h>
#include <stdlib.h>

#include "../ModularArithmetic.h"


/**
 * Checks if two numbers are congruent modulo m.
 * @details a == b (mod m).
 *
 * @param a the first number.
 * @param b the second number.
 * @param m the module value.
 * @return 1 if the 2 number are congruent, 0 otherwise.
 */
long long int areCongruent(long long int a, long long int b, long long int m) {
    return a % m == b % m;
}

/**
 * Checks if two numbers are coprime
 * @details a ⟂ n iff gcd(a, n) == 1.
 *
 * @param a the first number.
 * @param n the second number.
 * @return 1 if the 2 number are coprime, 0 otherwise.
 */
long long int areCoPrime(long long int a, long long int n) {
    return gcd(a, n) == 1;
}

/**
 * Checks if the first number is a divisor of the second number.
 *
 * @param n the first number.
 * @param m the second number.
 * @return 1 if the first number is a divisor of the second number, 0 otherwise.
 */
long long int isDivisor(long long int n, long long int m) {
    return m % n == 0;
}

/**
 * Checks if a number is Fermat's Pseuodoprime to a.
 * @details let a ⟂ n
 * @if a^(n - 1) (mod n) == 1 --> n is Fermat's Pseudoprime
 * @else n is NOT prime
 * @endif
 * @warning a and n must be coprime.
 *
 * @param a the first number.
 * @param n the second number.
 * @returns 1 if the number is Fermat's Pseuodprime to a, 0 otherwise.
 */
long long int isFermatPseudoPrime(long long int a, long long int n) {
    assert(areCoPrime(a, n) == 1 && "a must be coprime with n");

    return power(a, n - 1, n) == 1;
}

/**
 * Checks if a number is a prime number.
 * @details Eratosthenes sieve.
 *
 * @param n the number whose primality is to be tested.
 * @return 1 if the number is prime, 0 otherwise.
 */
long long int isPrime(long long int n) {
    if (n == 0 || n == 1) {
        return 0;
    }

    //The list of all prime numbers.
    long long int *primes = malloc((n + 1) * sizeof(int));
    //The index of the last prime number found.
    long long int primeIndex = 0;
    //The list of all number until n.
    long long int *numbers = malloc((n + 1) * sizeof(int));

    //array initialization: assume that all numbers are primes
    for (long long int i = 0; i < n + 1; ++i) {
        numbers[i] = 1;
    }
    numbers[0] = 0;
    numbers[1] = 0;

    for (long long int i = 2; (i * i) < ((n + 1) * (n + 1)); ++i) {
        //check if i is prime
        if (numbers[i]) {
            //i is a prime number
            primes[primeIndex++] = i;

            //updates all multiples of i as non-prime
            for (long long int j = (i * i); j < (n + 1); j += i) {
                numbers[j] = 0;
                if (j == n) {
                    free(numbers);
                    free(primes);
                    return 0;
                }
            }
        }
    }

    free(numbers);
    free(primes);
    return 1;

}

/**
 * Checks if a number admits the square root modulo n.
 * @details a is a quadratic residue modulo n.
 * @details if: exist x st x^2 = a (mod n).
 *
 * @param a the number whose square root we want to know if it is possible to calculate.
 * @param n the module value.
 * @return 1 if the number allows for the square root, 0 otherwise.
 */
long long int isSquareNumber(long long int a, long long int n) {
    a = mod(a, n);

    //Euler's criterion
    if (isPrime(n)) {
        return power(a, (int) ((n - 1) / 2), n) == 1;
    }

    for (long long int i = 0; i < (int) ((n - 1) / 2); ++i) {
        if (product(i, i, n) == a) {
            return 1;
        }
    }
    return 0;
}

/**
 * Checks is a number is a primitive root modulo n.
 * @details an integer whose powers modulo n are congruent with numbers coprime to n.
 *
 * @param a the number to check if it is primitive root modulo n.
 * @param n the module value.
 * @return 1 if the number is a primitive root modulo n, 0 otherwise.
 */
long long int isPrimitiveRoot(long long int a, long long int n) {
    //The value of Euler function of n.
    long long int phi = EulerFunction(n);
    //The number of factor.
    long long int factorPhiSize = 0;
    //The list of factors of phi.
    long long int *factorsPhi = factorisation(phi, &factorPhiSize);

    for (long long int i = 0; i < factorPhiSize; ++i) {
        if (power(a, (int) (phi / factorsPhi[i]), n) == 1) {
            free(factorsPhi);
            return 0;
        }
    }

    free(factorsPhi);
    return 1;
}