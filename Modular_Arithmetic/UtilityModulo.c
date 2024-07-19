#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "../ModularArithmetic.h"


/**
 * Checks if a number is a perfect square.
 * @details x = sqrt(n)
 * @details if n == x * x --> n is a perfect square
 *
 * @param n the number.
 * @return 1 if the number is a perfect quare, 0 otherwise.
 */
int isPerfectSquare(int n) {
    int sq = (int) sqrt(n);

    return sq * sq == n;
}

/**
 * Checks if a a number is in a list.
 *
 * @param list the list to check.
 * @param listSize the list size.
 * @param value the number to be found.
 * @return 1 if the value was found, 0 otherwise.
 */
int isListed(int *list, int listSize, int value) {
    assert(list != NULL);
    assert(listSize >= 0);
    
    for (int i = 0; i < listSize; ++i) {
        if (list[i] == value) {
            return 1;
        }
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
    //Temporal variable use for compute the first number of Bézout's identity.
    int xTemp = 0;
    //Temporal variable used for compute the second number of Bézout's identity.
    int yRefactor = 1;
    //Quotient between n and m.
    int q;
    //Temporal variable used in the switch procedure.
    int temp;

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

        temp = (*y) - q * yRefactor;
        *y = yRefactor;
        yRefactor = temp;
    }

    return n;
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
 * Computes a number congruent with the one given.
 * @details res == a (mod m).
 *
 * @param a the number.
 * @param m the modulo value.
 * @return a number congruent with the one given.
 */
int congruentNumber(int a, int m) {
    srand(time(NULL));
    return a + rand() * m;
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


/**
 * Factors a number by splitting it into 2 of its dividends.
 * @details Fermat's factorisation method.
 *
 * @param n the number.
 * @return the 2 factors that make up the number.
 */
int *realFermatFactorisation(int n) {
    assert(n % 2 != 0);
    n = n < 0 ? -n : n;

    //The factors
    int *res = malloc(2 * sizeof(int));
    int x = (int) ceil(sqrt(n));
    int y = x * x - n;

    while (!isPerfectSquare(y)) {
        x++;
        y = x * x - n;
    }

    y = (int) sqrt(y);
    res[0] = x - y;
    res[1] = x + y;

    return res;
}

/**
 * Factors a number by splitting it into all of its dividends.
 * @details Fermat's factorization method.
 *
 * @param n the number.
 * @param factors the number of factors.
 * @return the factors that make up the number.
 */
int *FermatFactorisation(int n, int *factors) {
    assert(n % 2 != 0);
    n = n < 0 ? -n : n;

    //The factors
    int *res = malloc(2 * sizeof(int));
    //Temporal factors.
    int *tmpRes = NULL;
    //The stack that contains all the factors not simplified yet.
    int *stack = malloc(2 * sizeof(int));
    //The number of element in the stack.
    int stackSize = 2;
    //The stack dimension.
    int reallocSize = stackSize;

    //initialize the stack
    *factors = 0;
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
            if (*factors % 2 == 0 ) {
                res = realloc(res, (*factors + 2) * sizeof(int));
            }
            //add it to the list of prime factors
            if (!isListed(res, *factors, stack[stackSize])) {
                res[(*factors)++] = stack[stackSize];
            }
        }
        //the number analyzed is NOT a prime number
        else {
            if (stackSize == (reallocSize - 1)) {
                reallocSize += 2;
                stack = realloc(stack, (reallocSize) * sizeof(int));
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
    res = realloc(res, *factors * sizeof(int));
    return res;
}


/**
 * Computes the value of the Euler function for the given number.
 *
 * @param n the number.
 * @return the value of Euler's function.
 */
float EulerFunction(int n) {
    //The number of factors.
    int factors = 0;
    //List of factors of n.
    int *nFactors = FermatFactorisation(n, &factors);
    //Euler function result.
    float res = n;

    for (int i = 0; i < factors; ++i) {
        printf("%d(%d) ", nFactors[i], i);
    }
    printf("\n");

    for (int i = 0; i < factors; ++i) {
        res *= (1.0 - 1.0 / ((float) nFactors[i]));
    }

    free(nFactors);
    return res;
}