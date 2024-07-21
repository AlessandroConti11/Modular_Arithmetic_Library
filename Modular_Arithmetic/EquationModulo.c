#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>

#include "../ModularArithmetic.h"


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
void diophantineEquation(int a, int *x, int b, int *y, int c) {
    assert(isDivisor(gcd(a, b), c));

    //The gcd between a and b.
    int gcdAB = gcd(a, b);

    a = a / gcdAB;
    b = b / gcdAB;
    c = c / gcdAB;

    extendedGCD(a, b, x, y);

    *x *= c;
    *y *= c;
}