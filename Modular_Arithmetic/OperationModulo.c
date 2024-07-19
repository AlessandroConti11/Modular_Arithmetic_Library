#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdarg.h>

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


/**
 * Computes the solution of the system of modular linear equations.
 * @details Chinese Reminder Theorem.
 * @example x = a1 (mod m1)
 * @example ...
 * @example x = ai (mod mi)
 *
 * @param numberOfEquation the number of equations of the linear system.
 * @param ... the equation values - ai, mi.
 * @return the solution of the system of modular linear equations.
 */
int chineseRemainderTheorem(int numberOfEquation, ...) {
    //The congruence values.
    int *a = malloc(numberOfEquation * sizeof(int));
    //The modulo values.
    int *m = malloc(numberOfEquation * sizeof(int));
    //The result.
    int res = 0;
    //Equations value.
    va_list elements;

    //initialize a, m
    va_start(elements, numberOfEquation);
    for (int i = 0; i < numberOfEquation; ++i) {
        a[i] = va_arg(elements, int);
        m[i] = va_arg(elements, int );
    }
    va_end(elements);

    //check if all modulo values are coprime
    for (int i = 0; i < numberOfEquation; ++i) {
        for (int j = 0; j < numberOfEquation; ++j) {
            if (i != j) {
                assert(areCoPrime(m[i], m[j]));
            }
        }
    }

    //The final modulo value.
    int M = 1;
    //M / mi.
    int mi = 0;
    //mi inverse.
    int miInverse = 0;

    //compute the final modulo value
    for (int i = 0; i < numberOfEquation; ++i) {
        M *= m[i];
    }

    //compute the mi values.
    for (int i = 0; i < numberOfEquation; ++i) {
        mi = M / m[i];
        miInverse = modularInverse(mi, m[i]);
        res = (res + a[i] * mi * miInverse) % M;
    }

    free(a);
    free(m);
    return res;
}

/**
 * Computes the linear diophantine equation.
 * @details ax + by = c
 * @details all value are integer.
 *
 * @param a the first parameter of the diophantine equation.
 * @param x the value of the first unknown to be computed.
 * @param b the second parameter of the diophantine equation.
 * @param y the value of the second unknown to be calculated
 * @param c the third parameter of the diophantine equation.
 */
void linearDiophantineEquation(int a, int *x, int b, int *y, int c) {
    assert(isDivisor(gcd(a, b), c));

    //TODO
}