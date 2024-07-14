#include <stdio.h>
#include <assert.h>

#include "../ModularArithmetic.h"


/**
 * Computes the Greatest Common Divisor.
 * @details Euclid's Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @return the gcd between n and m.
 */
int gcd(int n, int m) {
    if (n == 0) {
        return m;
    }
    if (m == 0) {
        return n;
    }

    //Temporal variable used to save the remainder of the division.
    int tmp = 0;

    do {
        tmp = n % m;
        n = m;
        m = tmp;
    } while (m != 0);

    return n;
}

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
int extendedGCD(int n, int m, int *x, int *y) {
    if (n == 0) {
        *x = 0;
        *y = 1;
        return m;
    }
    if (m == 0) {
        *x = 0;
        *y = 1;
        return n;
    }

    int xNEW;
    int yNEW;
    int gcd = extendedGCD(m % n, n, &xNEW, &yNEW);

    *x = yNEW - (m / n) * xNEW;
    *y = xNEW;

    if (*x < 0) {
        *x = modularReduction(*x, m);
    }

    return gcd;
}


/**
 * Computes the modulus of 2 integers.
 * @details res = n (mod m).
 *
 * @param n the dividend.
 * @param m the divisor.
 * @return the reminder of the division of n by m.
 */
int mod(int n, int m) {
    return n % m;
}


/**
 * Computes the modular reduction .
 * @details (-n) (mod m) --> k (mod m) s.t. -n == k (mod m).
 *
 * @param n the number to transform.
 * @param m the modulo value.
 * @return the modular reduction.
 */
int modularReduction(int n, int m) {
    while (n < 0) {
        n += m;
    }

    return n;
}

/**
 * Computes the modular inversion.
 * @details n (mod m) --> k (mod m) s.t. k == 1/n (mod m).
 *
 * @param n the number to be calculated the inverse.
 * @param m the modulo value.
 * @return the modular inverse.
 */
int modularInverse(int n, int m) {
    assert(areCoPrime(n, m) == 1);

    //the first number of Bézout's identity - the modular inverse.
    int x;
    //the second number of Bézout's identity.
    int y;
    //the gcd between n and m.
    int gcd = extendedGCD(n, m, &x, &y);
    assert(gcd == 1);
    
    return x;
}


int main() {
    int x, y, gcd;

    gcd = extendedGCD(11, 5, &x, &y);
    printf("%d - %d\n", gcd, x);

    x = power(7, 11, 26);
    printf("%d\n", x);
}