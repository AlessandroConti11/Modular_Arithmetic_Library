#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#include "../ModularArithmetic.h"


/**
 * Computes the sum modulo m.
 * @details res = a + b (mod m).
 *
 * @param a the first addend.
 * @param b the second addend.
 * @param m the modulo value.
 * @return the sum modulo m.
 */
int sum(int a, int b, int m) {
    a = mod(a, m);
    b = mod(b, m);

    return (a + b) % m;
}

/**
 * Computes the difference modulo m.
 * @details res = a - b (mod m).
 *
 * @param a the minuendo.
 * @param b the subtrahend.
 * @param m the modulo value.
 * @return the difference modulo m.
 */
int sub(int a, int b, int m) {
    a = mod(a, m);
    b = mod(b, m);

    if (a < 0) {
        a = modularReduction(a, m);
        assert(a >= 0);
    }
    if (b < 0) {
        b = modularReduction(b, m);
        assert(b >= 0);
    }

    b = modularReduction(-b, m);

    return sum(a, b, m);
}

/**
 * Computes the product modulo m.
 * @details res = a * b (mod m).
 *
 * @param a the first factor.
 * @param b the second factor.
 * @param m the modulo value.
 * @return the product modulo m.
 */
int product(int a, int b, int m) {
    a = mod(a, m);
    b = mod(b, m);

    return a * b % m;
}

/**
 * Computes the division modulo m.
 * @details res = a / b (mod m).
 *
 * @param a the dividend.
 * @param b the divisor.
 * @param m the modulo value.
 * @return the quotient.
 */
int division(int a, int b, int m) {
    a = mod(a, m);
    b = mod(b, m);

    if (a < 0) {
        a = modularReduction(a, m);
        assert(a >= 0);
    }
    if (b < 0) {
        b = modularReduction(b, m);
        assert(b >= 0);
    }

    //The first number of Bézout's identity - the modular inverse.
    int x;
    //The second number of Bézout's identity.
    int y;
    //The gcd between n and m.
    int gcd = extendedGCD(b, m, &x, &y);
    //the inverse exists iff gcd(b, m) == 1
    assert(gcd == 1);

    return product(a, x, m);
}

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
int power(int a, int exp, int m) {
    a = mod(a, m);

    //The result a^exp (mod m).
    int res = 1;

    while (exp > 0) {
        //if exp bit is 1, multiplies the result by the base
        if (exp % 2 == 1) {
            res = product(res, a, m);
        }

        //shifted to the next bit
        exp >>= 1;

        //square of the base
        a = product(a, a, m);
    }

    return res;
}

int squareRoot(int a, int m) {
    //TODO

    return -1;
}

int discreteLogarithm(int a, int base, int m) {
    //TODO

    return -1;
}