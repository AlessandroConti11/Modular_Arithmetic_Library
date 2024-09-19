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
 * @param m the module value.
 * @return the sum modulo m.
 */
long long int sum(long long int a, long long int b, long long int m) {
    a = a < 0 ? modularReduction(mod(a, m), m) : mod(a, m);
    b = b < 0 ? modularReduction(mod(b, m), m) : mod(b, m);

    return (a + b) % m;
}

/**
 * Computes the difference modulo m.
 * @details res = a - b (mod m).
 *
 * @param a the minuend.
 * @param b the subtrahend.
 * @param m the module value.
 * @return the difference modulo m.
 */
long long int sub(long long int a, long long int b, long long int m) {
    a = a < 0 ? modularReduction(mod(a, m), m) : mod(a, m);
    b = b < 0 ? modularReduction(mod(b, m), m) : mod(b, m);

    b = modularReduction(-b, m);

    return sum(a, b, m);
}

/**
 * Computes the product modulo m.
 * @details res = a * b (mod m).
 *
 * @param a the first factor.
 * @param b the second factor.
 * @param m the module value.
 * @return the product modulo m.
 */
long long int product(long long int a, long long int b, long long int m) {
    a = a < 0 ? modularReduction(mod(a, m), m) : mod(a, m);
    b = b < 0 ? modularReduction(mod(b, m), m) : mod(b, m);

    return a * b % m;
}

/**
 * Computes the division modulo m.
 * @details res = a / b (mod m).
 * @warning b and m must be coprime.
 *
 * @param a the dividend.
 * @param b the divisor.
 * @param m the module value.
 * @return the quotient.
 */
long long int division(long long int a, long long int b, long long int m) {
    a = a < 0 ? modularReduction(mod(a, m), m) : mod(a, m);
    b = b < 0 ? modularReduction(mod(b, m), m) : mod(b, m);

    //The first number of Bézout's identity - the modular inverse.
    long long int x;
    //The second number of Bézout's identity.
    long long int y;
    //The gcd between b and m.
    long long int gcd = extendedGCD(b, m, &x, &y);
    //the inverse exists iff gcd(b, m) == 1
    assert(gcd == 1 && "b must be coprime with m");

    return product(a, x, m);
}

/**
 * Computes the power elevation modulo m.
 * @details Square and Multiply algorithm.
 * @details res = a^exp (mod m).
 *
 * @param a the base.
 * @param exp the exponent.
 * @param m the module value.
 * @return the power elevation modulo m.
 */
long long int power(long long int a, long long int exp, long long int m) {
    a = a < 0 ? modularReduction(mod(a, m), m) : mod(a, m);

    //The result a^exp (mod m).
    long long int res = 1;

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
 * @details two different result (+res && -res)
 * @warning p must be a prime number.
 *
 * @param a the number whose square root is to be calculated.
 * @param p the module value.
 * @return the square roots modulo p of the number.
 */
long long int *TonelliShanksAlgorithm(long long int a, long long int p) {
    assert(p != 2);
    assert(isPrime(p));

    //The number of factors.
    long long int factorSize = 0;
    //The list of factors of n-1.
    long long int *factor = factorisation(p - 1, &factorSize);
    assert(factor[0] == 2 || factor[1] == 2);
    //The module value.
    long long int nTmp = p;
    //The q number st n-1 = q*2^s.
    long long int q = 0;
    //The s number st n-1 = q*2^s.
    long long int s = 0;
    //The non-residual quadratic.
    long long int z = 0;
    //The c number st initialize as z^q and is updated as b^2.
    long long int c = 0;
    //The r number st initialize as a^((q+1)/2) and is updated as r*b.
    long long int r = 0;
    //The t number st initialize as a^q and is updated as t*b^2.
    long long int t = 0;
    //The m number st initialize as s and is updated as i.
    long long int m = 0;
    //t^(2^i) (mod n).
    long long int t2i = 0;
    //The smallest i st t^(2^i) == 1 (mod n).
    long long int i = 0;
    //The b number.
    long long int b = 0;

    //define q & s
    for (long long int j = 0; j < factorSize; ++j) {
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
    for (long long int j = 2; j < p; ++j) {
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
            long long int *res = malloc(2 * sizeof(long long int));
            res[0] = 0;
            res[1] = 0;
            return res;
        }
        if (t == 1) {
            free(factor);

            //The 2 square roots.
            long long int *res = malloc(2 * sizeof(long long int));
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
 * @param n the module value.
 * @param numberOfSquareRoots the number of square roots.
 * @return the square roots modulo n of the number.
 */
long long int *squareRoot(long long int a, long long int n, long long int *numberOfSquareRoots) {
    assert(isSquareNumber(a, n) && "a must be a quadratic residue modulo n");

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
            long long int r = power(a, (long long int) ((n + 1) / 4), n);
            //The 2 square roots.
            long long int *res = malloc(2 * sizeof(long long int));
            res[0] = r;
            res[1] = modularReduction(-r, n);

            *numberOfSquareRoots = 2;
            return res;
        }

        //n == 5 (mod 8)
        if (areCongruent(n, 5, 8)) {
            //The d value.
            long long int d = power(a, ((n - 1) / 4), n);

            if (d == 1) {
                //The root square.
                long long int r = power(a, ((n + 3) / 8), n);
                //The 2 square roots.
                long long int *res = malloc(2 * sizeof(long long int));
                res[0] = r;
                res[1] = modularReduction(-r, n);

                *numberOfSquareRoots = 2;
                return res;
            }
            if (d == (n - 1)) {
                //The root square.
                long long int r = power((4 * a), ((n - 5) / 8), n);
                r = product((2 * a), r, n);
                //The 2 square roots.
                long long int *res = malloc(2 * sizeof(long long int));
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
    long long int factorSize = 0;
    //The factors that make up the number.
    long long int *factor = factorisation(n, &factorSize);

    //n = p*q
    if (factorSize == 2 && (factor[0] * factor[1]) == n) {
        //The number of square roots.
        long long int squareRootPSize = 0;
        //The square roots of a (mod p).
        long long int *squareRootP = squareRoot(a, factor[0], &squareRootPSize);
        //The number of square roots.
        long long int squareRootQSize = 0;
        //The square roots of a (mod p).
        long long int *squareRootQ = squareRoot(a, factor[1], &squareRootQSize);
        //The c value - p*c + q*d = 1.
        long long int c = 0;
        //The d value - p*c + q*d = 1.
        long long int d = 0;
        //The first root square.
        long long int x = 0;
        //The second root square.
        long long int y = 0;
        //The 4 square roots.
        long long int *res = malloc(4 * sizeof(long long int));

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
    long long int resultSize = 0;
    //The square roots.
    long long int *result = calloc(2, sizeof(long long int));

    for (long long int i = 0; i < n; ++i) {
        if (power(i, 2, n) == a) {
            result[resultSize++] = i;
            result[resultSize++] = modularReduction(-i, n);
            result = realloc(result, (resultSize + 2) * sizeof(long long int));
        }
    }

    free(factor);
    result = realloc(result, resultSize);
    return result;
}

/**
 * Computes the discrete logarithm modulo n of base number.
 * @details Baby-Step Giant-Step algorithm.
 * @details b = base^x (mod n) where x = Log_(base) (b).
 * @warning base must be base primitive root modulo n.
 *
 * @param base the logarithm base.
 * @param b the number.
 * @param n the module value.
 * @return the discrete logarithm modulo n.
 */
long long int discreteLogarithm(long long int base, long long int b, long long int n) {
    assert(isPrimitiveRoot(base, n));

    //The square root of n rounded up.
    long long int N = ceil(sqrt(n));
    //The first component to check - base^j (mod n) 0<=j<N.
    long long int *aj = malloc(N * sizeof(long long int));
    //The value of base^(-N) (mod n).
    long long int aN = 0;
    //The second component to check - b*base^(-Nk) (mod n) 0<=k<N.
    long long int baNk = b;
    //The position in the first component.
    long long int ajPos = 0;

    //compute the first component
    for (long long int i = 0; i < N; ++i) {
        aj[i] = power(base, i, n);
    }

    //base^(-N) (mod n)
    aN = modularInverse(base, n);
    aN = power(aN, N, n);

    for (long long int i = 0; i < N; ++i) {
        if (isListed(aj, N, baNk, &ajPos)) {
            free(aj);
            return ajPos + N * i;
        }
        baNk = product(baNk, aN, n);
    }

    free(aj);
    //this case cannot happen because base is base primitive root modulo n
    return -1;
}