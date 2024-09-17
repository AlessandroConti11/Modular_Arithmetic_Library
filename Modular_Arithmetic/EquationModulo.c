#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "../ModularArithmetic.h"


/**
 * Computes the solution of a system of modular linear equations.
 * @details Chinese Reminder Theorem.
 * @example x = a1 (mod m1)
 * @example ...
 * @example x = ai (mod mi)
 * @warning all mi value must be coprime.
 *
 * @param numberOfEquation the number of equations of the linear system.
 * @param a the parameters.
 * @param m the module values.
 * @return the solution of the system of modular linear equations.
 */
long long int chineseReminderTheorem(long long int numberOfEquation, long long int *a, long long int *m) {
    //check if all modulo values are coprime
    for (long long int i = 0; i < numberOfEquation; ++i) {
        for (long long int j = 0; j < numberOfEquation; ++j) {
            if (i != j) {
                assert(areCoPrime(m[i], m[j]) && "all module value must be coprime");
            }
        }
    }

    //The final modulo value.
    long long int M = 1;
    //M / mi.
    long long int mi = 0;
    //mi inverse.
    long long int miInverse = 0;
    //The result.
    long long int res = 0;

    //compute the final modulo value
    for (long long int i = 0; i < numberOfEquation; ++i) {
        M *= m[i];
    }

    //compute the mi values.
    for (long long int i = 0; i < numberOfEquation; ++i) {
        mi = M / m[i];
        miInverse = modularInverse(mi, m[i]);
        res = (res + a[i] * mi * miInverse) % M;
    }

    return res;
}

/**
 * Computes the solution of a linear diophantine equation.
 * @details ax + by = c
 * @details all value are integer.
 * @warning gcd between a and b must be a divisor of c.
 *
 * @param a the first parameter of the diophantine equation.
 * @param x the value of the first unknown to be computed.
 * @param b the second parameter of the diophantine equation.
 * @param y the value of the second unknown to be calculated
 * @param c the third parameter of the diophantine equation.
 */
void diophantineEquation(long long int a, long long int *x, long long int b, long long int *y, long long int c) {
    assert(isDivisor(gcd(a, b), c));

    //The gcd between a and b.
    long long int gcdAB = gcd(a, b);

    a = a / gcdAB;
    b = b / gcdAB;
    c = c / gcdAB;

    extendedGCD(a, b, x, y);

    *x *= c;
    *y *= c;
}