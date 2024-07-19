#include <assert.h>

#include "../ModularArithmetic.h"


/**
 * Checks if 2 number are congruent modulo m.
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
 * Checks if 2 number are coprime
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
 * Checks if n is Fermat's Pseuodoprime to a.
 * @details let a ⟂ n
 * @if a^(n - 1) (mod n) == 1 --> n is Fermat's Pseudoprime
 * @else n is NOT prime
 *
 * @param a the first number.
 * @param n the second number.
 * @returns 1 if n is Fermat's Pseuodprime to a, 0 otherwise.
 */
int isFermatPseudoprime(int a, int n) {
    assert(areCoPrime(a, n) == 1);

    return power(a, n - 1, n) == 1;
}