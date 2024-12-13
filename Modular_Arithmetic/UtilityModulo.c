#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../ModularArithmetic.h"


/**
 * Checks if a number is a perfect square.
 * @details x = sqrt(n)
 * @details if n == x * x --> n is a perfect square
 *
 * @param n the number.
 * @return 1 if the number is a perfect square, 0 otherwise.
 */
long long int isPerfectSquare(long long int n) {
    //The integer part of square root.
    long long int sq = (long long int) sqrt(n);

    return sq * sq == n;
}

/**
 * Checks if a number is in a list.
 * @warning list must be not NULL.
 *
 * @param list the list to check.
 * @param listSize the list size.
 * @param value the number to be found.
 * @param position the location where the searched value is - NOT necessary.
 * @return 1 if the value was found, 0 otherwise.
 */
long long int isListed(long long int *list, long long int listSize, long long int value, long long int *position) {
    assert(list != NULL);
    assert(listSize >= 0);
    
    for (long long int i = 0; i < listSize; ++i) {
        if (list[i] == value) {
            if (position != NULL) {
                *position = i;
            }
            return 1;
        }
    }

    if (position != NULL) {
        *position = -1;
    }
    return 0;
}


/**
 * Computes the Greatest Common Divisor.
 * @details Euclid's Algorithm.
 *
 * @param n the first number.
 * @param m the second number.
 * @return the gcd between n and m.
 */
long long int gcd(long long int n, long long int m) {
    if (n == 0) {
        return m;
    }
    if (m == 0) {
        return n;
    }

    //Temporal variable used to save the remainder of the division.
    long long int tmp = 0;

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
long long int extendedGCD(long long int n, long long int m, long long int *x, long long int *y) {
    //Temporal variable use for compute the first number of Bézout's identity.
    long long int xTemp = 0;
    //Temporal variable used for compute the second number of Bézout's identity.
    long long int yTemp = 1;
    //Quotient between n and m.
    long long int q = 0;
    //Temporal variable used in the switch procedure.
    long long int temp = 0;

    *x = 1;
    *y = 0;

    while (m != 0) {
        q = n / m;

        temp = n % m;
        n = m;
        m = temp;

        temp = (*x) - q * xTemp;
        *x = xTemp;
        xTemp = temp;

        temp = (*y) - q * yTemp;
        *y = yTemp;
        yTemp = temp;
    }

    return n;
}



/**
 * Computes the modulus of two integers.
 * @details res = n (mod m).
 *
 * @param n the dividend.
 * @param m the divisor.
 * @return the reminder of the division of n by m.
 */
long long int mod(long long int n, long long int m) {
    return n % m;
}

/**
 * Computes a number congruent with the one given.
 * @details res == a (mod m).
 *
 * @param a the number.
 * @param m the module value.
 * @return a number congruent with the one given.
 */
long long int congruentNumber(long long int a, long long int m) {
    srand(time(NULL));
    return a + rand() * m;
}


/**
 * Computes the modular reduction.
 * @details (-n) (mod m) --> k (mod m) s.t. -n == k (mod m).
 *
 * @param n the number to transform.
 * @param m the module value.
 * @return the modular reduction.
 */
long long int modularReduction(long long int n, long long int m) {
    while (n < 0) {
        n += m;
    }

    return n;
}

/**
 * Computes the modular inversion.
 * @details n (mod m) --> k (mod m) s.t. k == 1/n (mod m).
 * @warning n and m must be coprime.
 *
 * @param n the number to be calculated the inverse.
 * @param m the module value.
 * @return the modular inverse.
 */
long long int modularInverse(long long int n, long long int m) {
    //The first number of Bézout's identity - the modular inverse.
    long long int x;
    //The second number of Bézout's identity.
    long long int y;
    //The gcd between n and m.
    long long int gcd = extendedGCD(n, m, &x, &y);
    assert(gcd == 1 && "n must be coprime with m");

    return x;
}


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


/**
 * Factorizes a number by splitting it into two of its dividends.
 * @details Fermat's factorisation method.
 * @warning n must be an odd number.
 *
 * @param n the number.
 * @return the two factors that make up the number.
 */
long long int *realFermatFactorisation(long long int n) {
    assert(n % 2 != 0 && "the number must be odd");
    n = n < 0 ? -n : n;
    if (n == 1) {
        long long int *res = malloc(2 * sizeof(long long int));
        res[0] = 1;
        res[1] = 1;
        return res;
    }

    //The factors.
    long long int *res = malloc(2 * sizeof(long long int));
    //The first factor.
    long long int x = (long long int) ceil(sqrt(n));
    //The second factor.
    long long int y = x * x - n;

    while (!isPerfectSquare(y)) {
        x++;
        y = x * x - n;
    }

    y = (long long int) sqrt(y);
    res[0] = x - y;
    res[1] = x + y;

    return res;
}

/**
 * Factorizes a number by splitting it into all of its dividends.
 * @details Fermat's factorization method.
 * @warning n must be an odd number.
 *
 * @param n the number.
 * @param factors the number of factors.
 * @return the factors that make up the number.
 */
long long int *FermatFactorisation(long long int n, long long int *factors) {
    assert(n % 2 != 0 && "the number must be odd");

    n = n < 0 ? -n : n;
    (*factors) = 0;

    if (n == 1) {
        //The factors.
        long long int *res = malloc(sizeof(long long int));
        res[0] = 1;
        (*factors)++;
        return res;
    }

    //The factors.
    long long int *res = malloc(2 * sizeof(long long int));
    //Temporal factors.
    long long int *tmpRes = NULL;
    //The stack that contains all the factors not simplified yet.
    long long int *stack = malloc(2 * sizeof(long long int));
    //The number of element in the stack.
    long long int stackSize = 2;
    //The stack dimension.
    long long int reallocSize = stackSize;

    //initialize the stack
    tmpRes = realFermatFactorisation(n);
    stack[0] = tmpRes[0];
    stack[1] = tmpRes[1];

    //compute the factorisation of the last element in the stack
    free(tmpRes);
    tmpRes = realFermatFactorisation(stack[1]);
    stackSize--;

    do {
        //the number analyzed is a prime number
        if (tmpRes[0] == 1) {
            if ((*factors) % 2 == 0 ) {
                res = realloc(res, (*factors + 2) * sizeof(long long int));
                assert(res != NULL);
            }
            //add it to the list of prime factors
            if (!isListed(res, *factors, stack[stackSize], NULL)) {
                if (stack[stackSize] != 1) {
                    res[(*factors)++] = stack[stackSize];
                }
            }
        }
        //the number analyzed is NOT a prime number
        else {
            if (stackSize == (reallocSize - 1)) {
                reallocSize += 2;
                stack = realloc(stack, (reallocSize) * sizeof(long long int));
                assert(stack != NULL);
            }
            //add the factors to the stack
            stack[stackSize++] = tmpRes[0];
            stack[stackSize++] = tmpRes[1];
        }

        //select the next element in the stack
        if (stackSize > 0) {
            free(tmpRes);
            tmpRes = realFermatFactorisation(stack[stackSize - 1]);
        }
        stackSize--;

    }
    while (stackSize != -1);

    free(tmpRes);
    free(stack);
    res = realloc(res, *factors * sizeof(long long int));
    assert(res != NULL);
    qsort(res, (*factors), sizeof(long long int), compare);
    return res;
}

/**
 * Factorizes a number by splitting it into all of its dividends.
 *
 * @param n the number.
 * @param factors the number of factors.
 * @return the factors that make up the number.
 */
long long int *factorisation(long long int n, long long int *factors) {
    //The factors.
    long long int *res = NULL;
    //Save if the number is even or odd.
    long long int isEven = 0;

    (*factors) = 0;

    while (n % 2 == 0) {
        isEven = 1;
        n /= 2;
    }

    if (n != 1) {
        res = FermatFactorisation(n, factors);
    }

    if (isEven) {
        if (res == NULL) {
            res = malloc(sizeof(long long int));
        }
        res = realloc(res, ((*factors) + 1) * sizeof(long long int));
        assert(res != NULL);
        res[(*factors)++] = 2;
    }

    qsort(res, (*factors), sizeof(long long int), compare);
    return res;
}


/**
 * Computes the value of the Euler function for the given number.
 * @details φ(n).
 *
 * @param n the number.
 * @return the value of Euler's function.
 */
long long int EulerFunction(long long int n) {
    //The number of factors.
    long long int factors = 0;
    //List of factors of n.
    long long int *nFactors = factorisation(n, &factors);
    //Euler function result.
    float res = (float) n;

    for (long long int i = 0; i < factors; ++i) {
        if (nFactors[i] != 1) {
            res *= (1.0 - 1.0 / ((float) nFactors[i]));
        }
    }

    free(nFactors);
    return (long long int) res;
}


/**
 * Computes the list of prime numbers up to the n-th.
 * @details Eratosthenes sieve.
 *
 * @param n the maximum number within which to search for prime numbers.
 * @param primeSize the number of prime numbers found up to the n-th number.
 * @return the list of prime numbers up to the n-th.
 */
long long int *primeNumberList(long long int n, long long int *primeSize) {
    //The list of all prime numbers.
    long long int *primes = malloc((n + 1) * sizeof(long long int));
    //The index of the last prime number found.
    long long int primeIndex = 0;
    //The list of all number until n.
    long long int *numbers = malloc((n + 1) * sizeof(long long int));

    //array initialization: assume that all numbers are primes
    for (long long int i = 0; i < n + 1; ++i) {
        numbers[i] = 1;
    }
    numbers[0] = 0;
    numbers[1] = 0;

    for (long long int i = 2; (i * i) < ((n + 1) * (n + 1)); ++i) {
        //check if i is prime
        if (numbers[i]) {
            //i is a prime number
            primes[primeIndex++] = i;

            //updates all multiples of i as non-prime
            for (long long int j = (i * i); j < (n + 1); j += i) {
                numbers[j] = 0;
            }
        }
    }

    free(numbers);
    primes = realloc(primes, primeIndex * sizeof(long long int));
    *primeSize = primeIndex;
    return primes;
}

/**
 * Searches for the n-th prime number.
 * @details Eratosthenes sieve.
 *
 * @param n the n-th prime number to be found.
 * @return the n-th prime number.
 */
long long int nthPrimeNumber(long long int n) {
    //Upper boundary within which the n-th prime number lies.
    long long int upperBound = (n + 1) * (log(n + 1) + log(log(n + 1)));
    //The number of prime numbers found.
    long long int primeIndex;
    //The list of prime numbers up to the limit-th.
    long long int *primes = primeNumberList(upperBound, &primeIndex);
    //The n-th prime number.
    long long int res = primes[n - 1];

    free(primes);
    return res;
}

/**
 * Founds the prime number following a given number.
 *
 * @param n the number whose next prime number is to be found.
 * @return the prime number following the given number.
 */
long long int nextPrimeNumber(long long int n) {
    do {
        n++;
        if (areCoPrime(2, n) && (isFermatPseudoPrime(2, n) && isPrime(n))) {
            return n;
        }
    }while(1);
}


/**
 * Computes the list of primitive roots modulo n.
 *
 * @param n the module value.
 * @param primitiveRootsSize the number of primitive root modulo n.
 * @return the list of primitive roots modulo n.
 */
long long int *primitiveRoots(long long int n, long long int *primitiveRootsSize) {
    //The list of primitive roots.
    long long int *primitiveRoots = malloc(n * sizeof(long long int));
    //The number of primitive roots.
    long long int primitiveSize = 0;

    for (long long int i = 1; i < n; ++i) {
        if (isPrimitiveRoot(i, n)) {
            primitiveRoots[primitiveSize++] = i;
        }
    }

    (*primitiveRootsSize) = primitiveSize;
    primitiveRoots = realloc(primitiveRoots, (*primitiveRootsSize) * sizeof(long long int));
    assert(primitiveRoots != NULL);
    return primitiveRoots;
}

/**
 * Computes the list of quadratic residuals modulo n.
 *
 * @param n the module value.
 * @param quadraticResidualSize the number of quadratic residuals modulo n.
 * @return the list of quadratic residuals modulo n.
 */
long long int *quadraticResiduals(long long int n, long long int *quadraticResidualSize) {
    //The quadratic residuals.
    long long int *res = malloc(n * sizeof(long long int));
    //The quadratic residuals size.
    long long int resSize = 0;

    for (long long int i = 0; i < n; ++i) {
        if (isSquareNumber(i, n)) {
            res[resSize++] = i;
        }
    }

    *quadraticResidualSize = resSize;
    res = realloc(res, resSize * sizeof(long long int));
    return res;
}


/**
 * Computes the Legendre symbol.
 * @warning p must be an odd prime number.
 *
 * @param a the number.
 * @param p the odd prime number.
 * @return 1 if a is a quadratic residue modulo p, -1 if a is a quadratic non-residue modulo p, 0 if a is a divisor of p.
 */
long long int LegendreSymbol(long long int a, long long int p) {
    assert(p % 2 != 0);
    assert(isPrime(p));

    a = mod(a, p);

    //a|p - a is a divisor of p
    if (areCongruent(a, 0, p)) {
        return 0;
    }

    //a is a quadratic residue modulo p
    if (isSquareNumber(a, p)) {
        return 1;
    }

    //a is a quadratic non-residue modulo p
    return -1;
}

/**
 * Computes the Jacobi symbol.
 * @details Jacobi symbol is a generalization of the Legendre symbol.
 * @warning n must be an odd number.
 *
 * @param a the number.
 * @param n the odd number.
 * @return 1 if for some integer x: a==x^2 (mod n), -1 if there is no such x, 0 if a is a divisior of p.
 */
long long int JacobiSymbol(long long int a, long long int n) {
    assert(n % 2 != 0 && "the number must be odd");

    a = mod(a, n);

    //Temporary n.
    long long int nTmp = n;
    //The number of factors.
    long long int factorSize = 0;
    //The factors that make up n.
    long long int *factors = factorisation(n, &factorSize);
    //The Jacobi symbol.
    long long int res = 1;

    for (long long int i = 0; i < factorSize; ++i) {
        do {
            //producer(LegendreSymbol(a, factor_i)^(factor_exponent))
            res *= LegendreSymbol(a, factors[i]);
            if (res == 0) {
                free(factors);
                return 0;
            }
            nTmp /= factors[i];
        } while (nTmp % factors[i] == 0);
    }

    free(factors);
    return res;
}
