#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>

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
 * @warning b and m must be coprime.
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
    //The gcd between b and m.
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

/**
 * Computes the square roots modulo p of a number.
 * @details Tonelli-Shanks algorithm
 * @warning p must be a prime number.
 *
 * @param a the number whose square root is to be calculated.
 * @param p the modulo value.
 * @return the square roots modulo p of the number.
 */
int *TonelliShanksAlgorithm(int a, int p) {
    assert(p != 2);
    assert(isPrime(p));

    //The number of factors.
    int factorSize = 0;
    //The list of factors of n-1.
    int *factor = factorisation(p - 1, &factorSize);
    assert(factorSize == 2);
    assert(factor[0] == 2 || factor[1] == 2);
    //The modulo value.
    int nTmp = p;
    //The q number st n-1 = q*2^s.
    int q = 0;
    //The s number st n-1 = q*2^s.
    int s = 0;
    //The non-residual quadratic.
    int z = 0;
    //The c number st initialize as z^q and is updated as b^2.
    int c = 0;
    //The r number st initialize as a^((q+1)/2) and is updated as r*b.
    int r = 0;
    //The t number st initialize as a^q and is updated as t*b^2.
    int t = 0;
    //The m number st initialize as s and is updated as i.
    int m = 0;
    //t^(2^i) (mod n).
    int t2i = 0;
    //The smallest i st t^(2^i) == 1 (mod n).
    int i = 0;
    //The b number.
    int b = 0;

    //define q & s
    for (int j = 0; j < factorSize; ++j) {
        if (factor[j] != 2) {
            q = factor[j];
        }
        else {
            nTmp -= 1;
            while (nTmp % 2 == 0) {
                s++;
                nTmp /= 2;
            }
        }
    }

    //find a non-residual quadratic number
    for (int j = 2; j < p; ++j) {
        if (LegendreSymbol(j, p) == -1) {
            z = j;
            break;
        }
    }

    //initial value
    c = power(z, q, p); //c = z^q (mod n)
    r = power(a, (q + 1) / 2, p); //r = a^((q+1)/2) (mod n)
    t = power(a, q, p); //t = a^q (mod n)
    m = s;

    //find the square root
    while (1) {
        if (t == 0) {
            free(factor);

            //The 2 square roots.
            int *res = malloc(2 * sizeof(int));
            res[0] = 0;
            res[1] = 0;
            return res;
        }
        if (t == 1) {
            free(factor);

            //The 2 square roots.
            int *res = malloc(2 * sizeof(int));
            res[0] = r;
            res[1] = modularReduction(-r, p);
            return res;
        }

        //find the smallest i st t^(2^i) == 1 (mod n).
        t2i = t;
        for (i = 0; i < m; ++i) {
            t2i = power(t, pow(2, i), p);
            if (t2i == 1) {
                break;
            }
        }

        //update the variable
        b = power(c, (1 << (m - i - 1)), p); //b = c^(2^(m-i-1)) (mod n)
        r = product(r, b, p); //r = r*b (mod n)
        t = product(t, power(b, 2, p), p); //t = t*b^2 (mod n)
        c = power(b, 2, p); //c = b^2 (mod n)
        m = i;
    }
}

/**
 * Computes the square roots modulo n of a number.
 * @warning a must be a quadratic residue modulo n.
 *
 * @param a the number whose square root is to be calculated.
 * @param n the modulo value.
 * @param numberOfSquareRoots the number of square roots.
 * @return the square roots modulo n of the number.
 */
int *squareRoot(int a, int n, int *numberOfSquareRoots) {
    assert(isSquareNumber(a, n));

    //n is prime
    if (isPrime(n)) {
        //n == 1 (mod 4)
        if (areCongruent(n, 1, 4)) {
            *numberOfSquareRoots = 2;
            return TonelliShanksAlgorithm(a, n);
        }

        //n == 3 (mod 4)
        if (areCongruent(n, 3, 4)) {
            //The root square.
            int r = power(a, ((n + 1) / 4), n);
            //The 2 square roots.
            int *res = malloc(2 * sizeof(int));
            res[0] = r;
            res[1] = modularReduction(-r, n);

            *numberOfSquareRoots = 2;
            return res;
        }

        //n == 5 (mod 8)
        if (areCongruent(n, 5, 8)) {
            //The d value.
            int d = power(a, ((n - 1) / 4), n);

            if (d == 1) {
                //The root square.
                int r = power(a, ((n + 3) / 8), n);
                //The 2 square roots.
                int *res = malloc(2 * sizeof(int));
                res[0] = r;
                res[1] = modularReduction(-r, n);

                *numberOfSquareRoots = 2;
                return res;
            }
            if (d == (n - 1)) {
                //The root square.
                int r = power((4 * a), ((n - 5) / 8), n);
                r = product((2 * a), r, n);
                //The 2 square roots.
                int *res = malloc(2 * sizeof(int));
                res[0] = r;
                res[1] = modularReduction(-r, n);

                *numberOfSquareRoots = 2;
                return res;
            }

            //this case cannot happen
            return NULL;
        }
    }

    //n is NOT prime

    //The number of factors.
    int factorSize = 0;
    //The factors that make up the number.
    int *factor = factorisation(n, &factorSize);

    //n = p*q
    if (factorSize == 2 && (factor[0] * factor[1]) == n) {
        //The number of square roots.
        int squareRootPSize = 0;
        //The square roots of a (mod p).
        int *squareRootP = squareRoot(a, factor[0], &squareRootPSize);
        //The number of square roots.
        int squareRootQSize = 0;
        //The square roots of a (mod p).
        int *squareRootQ = squareRoot(a, factor[1], &squareRootQSize);
        //The c value - p*c + q*d = 1.
        int c = 0;
        //The d value - p*c + q*d = 1.
        int d = 0;
        //The first root square.
        int x = 0;
        //The second root square.
        int y = 0;
        //The 4 square roots.
        int *res = malloc(4 * sizeof(int));

        //find c & d
        diophantineEquation(factor[0], &c, factor[1], &d, 1);

        //compute the root square
        //r*d*q
        d = product(squareRootP[0], d, n);
        d = product(d, factor[1], n);
        //s*c*p
        c = product(squareRootQ[0], c, n);
        c = product(c, factor[0], n);
        //x = rdq + scp
        x = sum(d, c, n);
        //y = rdq - scp
        y = sub(d, c, n);

        //save all solution
        res[0] = x;
        res[1] = modularReduction(-x, n);
        res[2] = y;
        res[3] = modularReduction(-y, n);

        *numberOfSquareRoots = 4;
        free(factor);
        free(squareRootP);
        free(squareRootQ);
        return res;
    }

    //n has more than 2 factors

    //The number of square roots.
    int resultSize = 0;
    //The square roots.
    int *result = calloc(2, sizeof(int));

    for (int i = 0; i < n; ++i) {
        if (power(i, 2, n) == a) {
            result[resultSize++] = i;
            result[resultSize++] =modularReduction(-i, n);
            result = realloc(result, (resultSize + 2) * sizeof(int));
        }
    }

    free(factor);
    result = realloc(result, resultSize);
    return result;
}

/**
 * Computes the discrete logarithm modulo n of a number.
 * @details Baby-Step Giant-Step algorithm.
 * @details b = a^x (mod n) where x = Log_(a) (b).
 * @warning a must be a primitive root modulo n.
 *
 * @param a the logarithm base.
 * @param b the number.
 * @param n the modulo value.
 * @return the discrete logarithm modulo n.
 */
int discreteLogarithm(int a, int b, int n) {
    assert(isPrimitiveRoot(a, n));

    //The square root of n rounded up.
    int N = ceil(sqrt(n));
    //The first component to check - a^j (mod n) 0<=j<N.
    int *aj = malloc(N * sizeof(int));
    //The value of a^(-N) (mod n).
    int aN = 0;
    //The second component to check - b*a^(-Nk) (mod n) 0<=k<N.
    int baNk = b;
    //The position in the first component.
    int ajPos = 0;

    //compute the first component
    for (int i = 0; i < N; ++i) {
        aj[i] = power(a, i, n);
    }

    //a^(-N) (mod n)
    aN = modularInverse(a, n);
    aN = power(aN, N, n);

    for (int i = 0; i < N; ++i) {
        if (isListed(aj, N, baNk, &ajPos)) {
            return ajPos + N * i;
        }
        baNk = product(baNk, aN, n);
    }

    //this case cannot happen because a is a primitive root modulo n
    return -1;
}