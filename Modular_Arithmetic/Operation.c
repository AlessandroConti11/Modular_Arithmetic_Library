#include <stdio.h>
#include <assert.h>

#include "../ModularArithmetic.h"


/**
 * Computes the sum modulo m - res = a + b (mod m).
 *
 * @param a the first addend.
 * @param b the second addend.
 * @param m the modulo value.
 * @return the sum modulo m.
 */
int sum(int a, int b, int m) {
    return (a + b) % m;
}

/**
 * Computes the difference modulo m - res = a - b (mod m).
 *
 * @param a the minuendo.
 * @param b the subtrahend.
 * @param m the modulo value.
 * @return the difference modulo m.
 */
int sub(int a, int b, int m) {
    if (a < 0) {
        a = modularReduction(a, m);
        assert(a >= 0);
    }
    if (b < 0) {
        b = modularReduction(b, m);
        assert(b >= 0);
    }

    return sum(a, b, m);
}

/**
 * Computes the product modulo m - res = a * b (mod m).
 *
 * @param a the first factor.
 * @param b the second factor.
 * @param m the modulo value.
 * @return the product modulo m.
 */
int product(int a, int b, int m) {
    return a * b % m;
}

/**
 * Computes the division modulo m - res = a / b (mod m).
 * @param a the dividend.
 * @param b the divisor.
 * @param m the modulo value.
 * @return the quotient.
 */
int division(int a, int b, int m) {
    if (a < 0) {
        a = modularReduction(a, m);
        assert(a >= 0);
    }
    if (b < 0) {
        b = modularReduction(b, m);
        assert(b >= 0);
    }

    //the first number of Bézout's identity - the modular inverse.
    int x;
    //the second number of Bézout's identity.
    int y;
    //the gcd between n and m.
    int gcd = extendedGCD(b, m, &x, &y);
    //the inverse exists iff gcd(b, m) == 1
    assert(gcd == 1);

    return product(a, x, m);
}

int power(int a, int exp, int m) {
    //TODO

    return -1;
}

int discreteLogarithm(int a, int base, int m) {
    //TODO

    return -1;
}