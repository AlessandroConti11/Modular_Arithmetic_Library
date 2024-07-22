#include <assert.h>
#include <stdlib.h>

#include "../ModularArithmetic.h"


/**
 * Checks if two numbers are congruent modulo m.
 * @details a == b (mod m).
 *
 * @param a the first number.
 * @param b the second number.
 * @param m the modulo value.
 * @return 1 if the 2 number are congruent, 0 otherwise.
 */
int areCongruent(int a, int b, int m) {
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
int areCoPrime(int a, int n) {
    return gcd(a, n) == 1;
}

/**
 * Checks if the first number is a divisor of the second number.
 *
 * @param n the first number.
 * @param m the second number.
 * @return 1 if the first number is a divisor of the second number, 0 otherwise.
 */
int isDivisor(int n, int m) {
    return (m % n == 0);
}

/**
 * Checks if a number is Fermat's Pseuodoprime to a.
 * @details let a ⟂ n
 * @if a^(n - 1) (mod n) == 1 --> n is Fermat's Pseudoprime
 * @else n is NOT prime
 *
 * @param a the first number.
 * @param n the second number.
 * @returns 1 if the number is Fermat's Pseuodprime to a, 0 otherwise.
 */
int isFermatPseudoPrime(int a, int n) {
    assert(areCoPrime(a, n) == 1);

    return power(a, n - 1, n) == 1;
}

/**
 * Checks if a number is a prime number.
 * @details Eratosthenes sieve.
 *
 * @param n the number whose primality is to be tested.
 * @return 1 if the number is prime, 0 otherwise.
 */
int isPrime(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }

    //The list of all prime numbers.
    int *primes = malloc((n + 1) * sizeof(int));
    //The index of the last prime number found.
    int primeIndex = 0;
    //The list of all number until n.
    int *numbers = malloc((n + 1) * sizeof(int));

    //array initialization: assume that all numbers are primes
    for (int i = 0; i < n + 1; ++i) {
        numbers[i] = 1;
    }
    numbers[0] = 0;
    numbers[1] = 0;

    for (int i = 2; (i * i) < ((n + 1) * (n + 1)); ++i) {
        //check if i is prime
        if (numbers[i]) {
            //i is a prime number
            primes[primeIndex++] = i;

            //updates all multiples of i as non-prime
            for (int j = (i * i); j < (n + 1); j += i) {
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

int isSquareNumber(int a, int n) {
    //TODO residuo quadratico
    return -1;
}

int isPrimitiveRoot(int a, int n) {
    //TODO radice primitiva
    return -1;
}