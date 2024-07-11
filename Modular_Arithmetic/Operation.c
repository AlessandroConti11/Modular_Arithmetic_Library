#include <stdio.h>

// #include "../ModularArithmetic.h"


/**
 * Computes the modulus of 2 integers - res = n (mod m).
 *
 * @param n the dividend.
 * @param m the divisor.
 * @return the reminder of the division of n by m.
 */
int mod(int n, int m) {
    return n % m;
}


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


int sub(int a, int b, int m) {
    //TODO
    // -b --> k (mod m)
    // return sum(a, k, m);
    return -1;
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

int division(int a, int b, int m) {
    //TODO
    // 1/b --> k (mod m)
    // product(a, k, m);

    return -1;
}

int power(int a, int exp, int m) {
    //TODO

    return -1;
}

int discreteLogarithm(int a, int base, int m) {
    //TODO

    return -1;
}