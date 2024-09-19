#ifndef MODULARARITHMETIC_H

    #define MODULARARITHMETIC_H

    #include "Modular_Arithmetic/Utility/Matrix.h"


    //*********************//
    //  MODULAR OPERATION  //
    //*********************//


    /**
     * Computes the sum modulo m.
     * @details res = a + b (mod m).
     *
     * @param a the first addend.
     * @param b the second addend.
     * @param m the module value.
     * @return the sum modulo m.
     */
    long long int sum(long long int a, long long int b, long long int m);

    /**
     * Computes the difference modulo m.
     * @details res = a - b (mod m).
     *
     * @param a the minuend.
     * @param b the subtrahend.
     * @param m the module value.
     * @return the difference modulo m.
     */
    long long int sub(long long int a, long long int b, long long int m);

    /**
     * Computes the product modulo m.
     * @details res = a * b (mod m).
     *
     * @param a the first factor.
     * @param b the second factor.
     * @param m the module value.
     * @return the product modulo m.
     */
    long long int product(long long int a, long long int b, long long int m);

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
    long long int division(long long int a, long long int b, long long int m);

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
    long long int power(long long int a, long long int exp, long long int m);

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
    long long int *TonelliShanksAlgorithm(long long int a, long long int p);

    /**
     * Computes the square roots modulo n of a number.
     * @warning a must be a quadratic residue modulo n.
     *
     * @param a the number whose square root is to be calculated.
     * @param n the module value.
     * @param numberOfSquareRoots the number of square roots.
     * @return the square roots modulo n of the number.
     */
    long long int *squareRoot(long long int a, long long int n, long long int *numberOfSquareRoots);

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
    long long int discreteLogarithm(long long int base, long long int b, long long int n);


    //******************************************************************************************************************//


    //*******************//
    //  EQUATION MODULO  //
    //*******************//


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
    long long int chineseReminderTheorem(long long int numberOfEquation, long long int *a, long long int *m);

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
    void diophantineEquation(long long int a, long long int *x, long long int b, long long int *y, long long int c);


    //******************************************************************************************************************//


    //***************//
    //  TEST MODULO  //
    //***************//


    /**
     * Checks if two numbers are congruent modulo m.
     * @details a == b (mod m).
     *
     * @param a the first number.
     * @param b the second number.
     * @param m the module value.
     * @return 1 if the 2 number are congruent, 0 otherwise.
     */
    long long int areCongruent(long long int a, long long int b, long long int m);

    /**
     * Checks if two numbers are coprime
     * @details a ⟂ n iff gcd(a, n) == 1.
     *
     * @param a the first number.
     * @param n the second number.
     * @return 1 if the 2 number are coprime, 0 otherwise.
     */
    long long int areCoPrime(long long int a, long long int n);

    /**
     * Checks if the first number is a divisor of the second number.
     *
     * @param n the first number.
     * @param m the second number.
     * @return 1 if the first number is a divisor of the second number, 0 otherwise.
     */
    long long int isDivisor(long long int n, long long int m);

    /**
     * Checks if a number is Fermat's Pseuodoprime to a.
     * @details let a ⟂ n
     * @if a^(n - 1) (mod n) == 1 --> n is Fermat's Pseudoprime
     * @else n is NOT prime
     * @endif
     * @warning a and n must be coprime.
     *
     * @param a the first number.
     * @param n the second number.
     * @returns 1 if the number is Fermat's Pseuodprime to a, 0 otherwise.
     */
    long long int isFermatPseudoPrime(long long int a, long long int n);

    /**
     * Checks if a number is a prime number.
     * @details Eratosthenes sieve.
     *
     * @param n the number whose primality is to be tested.
     * @return 1 if the number is prime, 0 otherwise.
     */
    long long int isPrime(long long int n);

    /**
     * Checks if a number admits the square root modulo n.
     * @details a is a quadratic residue modulo n.
     * @details if: exist x st x^2 = a (mod n).
     *
     * @param a the number whose square root we want to know if it is possible to calculate.
     * @param n the module value.
     * @return 1 if the number allows for the square root, 0 otherwise.
     */
    long long int isSquareNumber(long long int a, long long int n);

    /**
     * Checks is a number is a primitive root modulo n.
     * @details an integer whose powers modulo n are congruent with numbers coprime to n.
     *
     * @param a the number to check if it is primitive root modulo n.
     * @param n the module value.
     * @return 1 if the number is a primitive root modulo n, 0 otherwise.
     */
    long long int isPrimitiveRoot(long long int a, long long int n);


    //******************************************************************************************************************//


    //*******************************************//
    //  UTILITY FUNCTION FOR MODULAR ARITHMETIC  //
    //*******************************************//


    /**
     * Checks if a number is a perfect square.
     * @details x = sqrt(n)
     * @details if n == x * x --> n is a perfect square
     *
     * @param n the number.
     * @return 1 if the number is a perfect square, 0 otherwise.
     */
    long long int isPerfectSquare(long long int n);

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
    long long int isListed(long long int *list, long long int listSize, long long int value, long long int *position);


    /**
     * Computes the Greatest Common Divisor.
     * @details Euclid's Algorithm.
     *
     * @param n the first number.
     * @param m the second number.
     * @return the gcd between n and m.
     */
    long long int gcd(long long int n, long long int m);

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
    long long int extendedGCD(long long int n, long long int m, long long int *x, long long int *y);


    /**
     * Computes the modulus of two integers.
     * @details res = n (mod m).
     *
     * @param n the dividend.
     * @param m the divisor.
     * @return the reminder of the division of n by m.
     */
    long long int mod(long long int n, long long int m);

    /**
     * Computes a number congruent with the one given.
     * @details res == a (mod m).
     *
     * @param a the number.
     * @param m the module value.
     * @return a number congruent with the one given.
     */
    long long int congruentNumber(long long int a, long long int m);


    /**
     * Computes the modular reduction.
     * @details (-n) (mod m) --> k (mod m) s.t. -n == k (mod m).
     *
     * @param n the number to transform.
     * @param m the module value.
     * @return the modular reduction.
     */
    long long int modularReduction(long long int n, long long int m);

    /**
     * Computes the modular inversion.
     * @details n (mod m) --> k (mod m) s.t. k == 1/n (mod m).
     * @warning n and m must be coprime.
     *
     * @param n the number to be calculated the inverse.
     * @param m the module value.
     * @return the modular inverse.
     */
    long long int modularInverse(long long int n, long long int m);


    /**
     * Factorizes a number by splitting it into two of its dividends.
     * @details Fermat's factorisation method.
     * @warning n must be an odd number.
     *
     * @param n the number.
     * @return the two factors that make up the number.
     */
    long long int *realFermatFactorisation(long long int n);

    /**
     * Factorizes a number by splitting it into all of its dividends.
     * @details Fermat's factorization method.
     * @warning n must be an odd number.
     *
     * @param n the number.
     * @param factors the number of factors.
     * @return the factors that make up the number.
     */
    long long int *FermatFactorisation(long long int n, long long int *factors);

    /**
     * Factorizes a number by splitting it into all of its dividends.
     *
     * @param n the number.
     * @param factors the number of factors.
     * @return the factors that make up the number.
     */
    long long int *factorisation(long long int n, long long int *factors);


    /**
     * Computes the value of the Euler function for the given number.
     * @details φ(n).
     *
     * @param n the number.
     * @return the value of Euler's function.
     */
    long long int EulerFunction(long long int n);


    /**
     * Computes the list of prime numbers up to the n-th.
     * @details Eratosthenes sieve.
     *
     * @param n the maximum number within which to search for prime numbers.
     * @param primeSize the number of prime numbers found up to the n-th number.
     * @return the list of prime numbers up to the n-th.
     */
    long long int *primeNumberList(long long int n, long long int *primeSize);

    /**
     * Searches for the n-th prime number.
     * @details Eratosthenes sieve.
     *
     * @param n the n-th prime number to be found.
     * @return the n-th prime number.
     */
    long long int nthPrimeNumber(long long int n);

    /**
     * Founds the prime number following a given number.
     *
     * @param n the number whose next prime number is to be found.
     * @return the prime number following the given number.
     */
    long long int nextPrimeNumber(long long int n);


    /**
     * Computes the list of primitive roots modulo n.
     *
     * @param n the module value.
     * @param primitiveRootsSize the number of primitive root modulo n.
     * @return the list of primitive roots modulo n.
     */
    long long int *primitiveRoots(long long int n, long long int *primitiveRootsSize);

    /**
     * Computes the list of quadratic residuals modulo n.
     *
     * @param n the module value.
     * @param quadraticResidualSize the number of quadratic residuals modulo n.
     * @return the list of quadratic residuals modulo n.
     */
    long long int *quadraticResiduals(long long int n, long long int *quadraticResidualSize);


    /**
     * Computes the Legendre symbol.
     * @warning p must be an odd prime number.
     *
     * @param a the number.
     * @param p the odd prime number.
     * @return 1 if a is a quadratic residue modulo p, -1 if a is a quadratic non-residue modulo p, 0 if a is a divisor of p.
     */
    long long int LegendreSymbol(long long int a, long long int p);

    /**
     * Computes the Jacobi symbol.
     * @details Jacobi symbol is a generalization of the Legendre symbol.
     * @warning n must be an odd number.
     *
     * @param a the number.
     * @param n the odd number.
     * @return 1 if for some integer x: a==x^2 (mod n), -1 if there is no such x, 0 if a is a divisior of p.
     */
    long long int JacobiSymbol(long long int a, long long int n);


    //******************************************************************************************************************//


    //*****************//
    //  MATRIX MODULO  //
    //*****************//


    /**
     * Prints a matrix modulo n.
     *
     * @param a the matrix to print - M: k x m.
     * @param n the module value.
     */
    void printMatrixModulo(matrix *a, long long int n);


    /**
     * Checks if a matrix has all integer elements.
     *
     * @param a the matrix - M: k x m.
     * @return 1 if the matrix has all integer elements, 0 otherwise.
     */
    long long int isIntegerMatrix(matrix *a);

    /**
     * Matrix modulo n.
     *
     * @param a the matrix - M: k x m.
     * @param modMatrix the matrix modulo n - M: k x m.
     * @param n the module value.
     */
    void modularMatrix(matrix *a, matrix *modMatrix, long long int n);

    /**
     * Matrix inversion modulo n - cofactor matrix method.
     * @warning a must have all integer elements.
     *
     * @param a the matrix - M: n x n.
     * @param inv the inverse of the matrix: [a]^-1 - M: n x n.
     * @param n the module value.
     */
    void inverseMatrixModulo(matrix *a, matrix *inv, long long int n);


    /**
     * Computes the sum of matrices modulo n.
     * @warning a and b must have all integer elements.
     *
     * @param a the first matrix - M: k x m.
     * @param b the second matrix - M: k x m.
     * @param res the result: [a] + [b] - M: k x m.
     * @param n the module value.
     */
    void sumMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n);

    /**
     * Computes the difference of matrices modulo n.
     * @warning a and b must have all integer elements.
     *
     * @param a the first matrix - M: k x m.
     * @param b the second matrix - M: k x m.
     * @param res the result: [a] - [b] - M: k x m.
     * @param n the module value.
     */
    void subMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n);

    /**
     * Computes the scalar product of matrix modulo n.
     * @warning a must have all integer elements.
     *
     * @param scalar the scalar integer number.
     * @param a the first matrix - M: k x m.
     * @param res the result: scalar * [a] - M: k x m.
     * @param n the module value.
     */
    void scalarProductModulo(long long int scalar, matrix *a, matrix *res, long long int n);

    /**
     * Computes the product of matrices modulo n.
     * @warning a and b must have all integer elements.
     *
     * @param a the first matrix - M: k x m.
     * @param b the second matrix - M: k x m.
     * @param res the result: [a] x [b] - M: k x m.
     * @param n the module value.
     */
    void productMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n);

    /**
     * Computes the power elevation of a matrix modulo n.
     * @warning a must have all integer elements.
     *
     * @param a the first matrix - M: m x m.
     * @param k the exponent.
     * @param res the result: [a]^k - M: m x m.
     * @param n the module value.
     */
    void powerMatrixModulo(matrix *a, long long int k, matrix *res, long long int n);

    /**
     * Computes the Kronecker product of matrices modulo n.
     * @warning a and b must have all integer elements.
     *
     * @param a the first matrix - M: k x m.
     * @param b the second matrix - M: p x q.
     * @param res the result: [a] (x) [b] - M: k*p x m*q.
     * @param n the module value.
     */
    void kroneckerProductMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n);

#endif
