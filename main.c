#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ModularArithmetic.h"
#include "Modular_Arithmetic/Utility/Matrix.h"


/**
 * Generates a matrix - M: row x column.
 *
 * @param row the number of row.
 * @param column the number of column.
 * @return the matrix - M: row x column.
 */
matrix *generateMatrixNxM(long long int *row, long long int *column) {
    //Matrix.
    matrix *matrix = NULL;
    //Return scanf value.
    int returnScanf = 0;

    printf("Enter the number of row: ");
    returnScanf = scanf("%lld", row);
    assert(returnScanf > 0);
    printf("Enter the number of column: ");
    returnScanf = scanf("%lld", column);
    assert(returnScanf > 0);

    matrix = createMatrix(*row, *column);

    for (long long int i = 0; i < *row; ++i) {
        for (long long int j = 0; j < *column; ++j) {
            printf("Insert the value for position (%lld; %lld): ", i, j);
            returnScanf = scanf("%lf", &matrix->matrix[i][j]);
            assert(returnScanf > 0);
        }
    }
    printf("\n");

    return matrix;
}

/**
 * Generates a matrix - M: row x row.
 * @param row the matrix order.
 * @return the matrix - M: row x row.
 */
matrix *generateMatrixNxN(long long int *row) {
    //Matrix.
    matrix *matrix = NULL;
    //Return scanf value.
    int returnScanf = 0;

    printf("Enter the matrix order: ");
    returnScanf = scanf("%lld", row);
    assert(returnScanf > 0);

    matrix = createMatrix(*row, *row);

    for (long long int i = 0; i < *row; ++i) {
        for (long long int j = 0; j < *row; ++j) {
            printf("Insert the value for position (%lld; %lld): ", i, j);
            returnScanf = scanf("%lf", &matrix->matrix[i][j]);
            assert(returnScanf > 0);
        }
    }
    printf("\n");

    return matrix;
}


/**
 * Prints all possible choices.
 */
void printChoice() {
    printf("Choose which operation you want to perform from the following ones:\n"
           " 1. compute the sum modulo m\n"
           " 2. compute the difference modulo m\n"
           " 3. compute the product modulo m\n"
           " 4. compute the division modulo m\n"
           " 5. compute the power elevation modulo m\n"
           " 6. compute the square roots modulo p using the Tonelli-Shanks algorithm\n"
           " 7. compute the square roots modulo n\n"
           " 8. compute the discrete logarithm modulo n\n"
           " 9. compute the solution of a system of modular linear equations\n"
           "10. compute the solution of a linear diophantine equation\n"
           "11. check if 2 numbers are congruent modulo m\n"
           "12. check if 2 numbers are coprime\n"
           "13. check if a number is a divisor of another one\n"
           "14. check if a number is NOT prime using the Fermat's Pseudoprime to a assumption\n"
           "15. check if a number is prime\n"
           "16. check if a number admits the square root modulo n - quadratic residue\n"
           "17. check if a number is a primitive root modulo n\n"
           "18. compute the gcd - greatest common divisor using the Euclid's algorithm\n"
           "19. compute the gcd - greatest common divisor using the Extended Euclid's algorithm\n"
           "20. compute the module of 2 numbers\n"
           "21. compute a number congruent with the one given\n"
           "22. compute the modular reduction\n"
           "23. compute the modular inversion\n"
           "24. factorize an odd number using the Fermat Factorization method\n"
           "25. factorize a number\n"
           "26. compute the Euler function\n"
           "27. compute the list of prime number up to the n-th\n"
           "28. search for the n-th prime number\n"
           "29. search the prime number following the given one\n"
           "30. compute the list of primitive roots modulo n\n"
           "31. compute the list of quadratic residual modulo n\n"
           "32. compute the Legendre symbol\n"
           "33. compute the Jacobi symbol\n"
           "34. check if a matrix has all integer elements\n"
           "35. compute matrix modulo n\n"
           "36. compute the matrix inversion modulo n\n"
           "37. compute the sum of 2 matrices modulo n\n"
           "38. compute the difference of 2 matrices modulo n\n"
           "39. compute the scalar product modulo n\n"
           "40. compute the product of matrices modulo n\n"
           "41. compute the power elevation of matrices modulo n\n"
           "42. compute the Kronecker product of matrices modulo n\n"
           "43. quit\n\n");
}

/**
 * Handles the user's choice.
 *
 * @param choice the choice.
 */
void manageChoice(int *choice) {
    //The first number.
    long long int x;
    //The second number.
    long long int y;
    //The third number.
    long long int x1;
    //The fourth number.
    long long int y1;
    //The module value.
    long long int module;
    //The list.
    long long int *list = NULL;
    //Matrices.
    matrix *matrix1 = NULL, *matrix2 = NULL, *res = NULL;
    //Return scanf value.
    int returnScanf = 0;

    switch (*choice) {
        case 1:
            printf("You chose to compute the sum modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld + %lld (mod %lld) = %lld (mod %lld)\n\n\n", x, y, module, sum(x, y, module), module);
            break;
        case 2:
            printf("You chose to compute the difference modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld - %lld (mod %lld) = %lld (mod %lld)\n\n\n", x, y, module, sub(x, y, module), module);
            break;
        case 3:
            printf("You chose to compute the product modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld * %lld (mod %lld) = %lld (mod %lld)\n\n\n", x, y, module, product(x, y, module), module);
            break;
        case 4:
            printf("You chose to compute the division modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld / %lld (mod %lld) = %lld (mod %lld)\n\n\n", x, y, module, division(x, y, module), module);
            break;
        case 5:
            printf("You chose to compute the power elevation modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the exponent: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld^%lld (mod %lld) = %lld (mod %lld)\n\n\n", x, y, module, power(x, y, module), module);
            break;
        case 6:
            printf("You chose to compute the square roots modulo p using the Tonelli-Shanks algorithm\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the module value - prime number: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            list = TonelliShanksAlgorithm(x, module);
            printf("sqrt(%lld) (mod %lld) = %lld (mod %lld) %lld (mod %lld)\n\n\n", x, module, list[0], module, list[1], module);
            free(list);
            break;
        case 7:
            printf("You chose to compute the square roots modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            //The 2 square roots.
            list = squareRoot(x, module, &y);
            printf("sqrt(%lld) (mod %lld) = ", x, module);
            for (long long int i = 0; i < y; ++i) {
                printf("%lld (mod %lld) ", list[i], module);
            }
            free(list);
            printf("\n\n\n");
            break;
        case 8:
            printf("You chose to compute the discrete logarithm modulo n\n\n"
                   "Insert the base: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld^x = %lld (mod %lld) --> x = %lld\n\n\n", x, y, module, discreteLogarithm(x, y, module));
            break;
        case 9:
            printf("You chose to compute the solution of a system of modular linear equation\n\n"
                   "Insert the number of equation: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            //The list of parameters.
            long long int *parameter = malloc(x * sizeof(int));
            //The list of modules.
            long long int *modules = malloc(x * sizeof(int));

            for (long long int i = 0; i < x; ++i) {
                printf("Insert the %lld-%s parameter: ", (i + 1),
                       ((i + 1) == 1 ? "st" : ((i + 1) == 2 ? "nd" : ((i + 1) == 3 ? "rd" : "th"))));
                returnScanf = scanf("%lld", (parameter + i));
                assert(returnScanf > 0);

                printf("Insert the %lld-%s module: ", (i + 1),
                       ((i + 1) == 1 ? "st" : ((i + 1) == 2 ? "nd" : ((i + 1) == 3 ? "rd" : "th"))));
                returnScanf = scanf("%lld", (modules + i));
                assert(returnScanf > 0);
            }

            y = chineseReminderTheorem(x, parameter, modules);

            for (long long int i = 0; i < x; ++i) {
                printf("x = %lld (mod %lld)\n", parameter[i], modules[i]);
            }
            printf("--> x = %lld\n\n\n", y);

            free(parameter);
            free(modules);
            break;
        case 10:
            printf("You chose to compute the solution of a linear diophantine equation\n\n"
                   "Insert the first parameter: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second parameter: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the third parameter: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            diophantineEquation(x, &x1, y, &y1, module);
            printf("%lldx + %lldy = %lld --> x = %lld, y = %lld\n\n\n", x, y, module, x1, y1);
            break;
        case 11:
            printf("You chose to check if 2 numbers are congruent modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld %c= %lld (mod %lld)\n\n\n", x, areCongruent(x, y, module) == 1 ? '=' : '!', y, module);
            break;
        case 12:
            printf("You chose to check if 2 numbers are coprime\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("%lld %s coprime %lld\n\n\n", x, areCoPrime(x, y) == 1 ? "are" : "are not", y);
            break;
        case 13:
            printf("You chose to check if a number is a divisor of another one\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("%lld %s %lld \n\n\n", x, isDivisor(x, y) == 1 ? "|" : "!|", y);
            break;
        case 14:
            printf("You chose to check if a number is NOT prime using the Fermat's Pseudoprime assumption\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            printf("%lld %s prime\n\n\n", x, isFermatPseudoPrime(2, x) == 1 ? "is" : "is NOT");
            break;
        case 15:
            printf("You chose to check if a number is prime\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            printf("%lld %s prime\n\n\n", x, isPrime(x) == 1 ? "is" : "is NOT");
            break;
        case 16:
            printf("You chose to check if a number admits the square root modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld (mod %lld) %s\n\n\n", x, module, isSquareNumber(x, module) == 1 ? "admits the square root" : "does NOT admit the square root");
            break;
        case 17:
            printf("You chose to check if a number is a primitive root modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            printf("%lld (mod %lld) %s\n\n\n", x, module, isPrimitiveRoot(x, module) == 1 ? "is a primitive root" : "is not a primitive root");
            break;
        case 18:
            printf("You chose to compute the gcd\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("the gcd(%lld, %lld) = %lld\n\n\n", x, y, gcd(x, y));
            break;
        case 19:
            printf("You chose to compute the gcd using the Extended Euclid's algorithm\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            module = extendedGCD(x, y, &x1, &y1);
            printf("The gcd(%lld, %lld) = %lld --> %lld * %lld + %lld * %lld = %lld\n\n\n", x, y, module, x, x1, y, y1, module);
            break;
        case 20:
            printf("You chose to compute the module of 2 numbers\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("%lld (mod %lld) = %lld\n\n\n", x, y, mod(x, y));
            break;
        case 21:
            printf("You chose to compute a number congruent with the one given\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("A number congruent with %lld is %lld\n\n\n", x, congruentNumber(x, y));
            break;
        case 22:
            printf("You chose to compute the modular reduction of a number\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("%lld = %lld (mod %lld)\n\n\n", x, modularReduction(x, y), y);
            break;
        case 23:
            printf("You chose to compute the modular inversion of a number\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("1/%lld = %lld (mod %lld)\n\n\n", x, modularInverse(x, y), y);
            break;
        case 24:
            printf("You chose to factorize an odd number\n\n"
                   "Insert the odd number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            list = FermatFactorisation(x, &y);
            printf("The factors of %lld %s: ", x, y == 1 ? "is" : "are");
            for (long long int i = 0; i < y; ++i) {
                printf("%lld ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 25:
            printf("You chose to factorize a number\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            list = factorisation(x, &y);
            printf("The factors of %lld %s: ", x, y == 1 ? "is" : "are");
            for (long long int i = 0; i < y; ++i) {
                printf("%lld ", list[i]);
            }
            free(list);
            printf("\n\n\n");
            break;
        case 26:
            printf("You chose to compute the Euler function\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            printf("Euler_function(%lld) = %lld\n\n\n", x, EulerFunction(x));
            break;
        case 27:
            printf("You chose to compute the list of prime number up to the n-th\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            list = primeNumberList(x, &y);
            printf("The first %lld prime number %s: ", x, x == 1 ? "is" : "are");
            for (long long int i = 0; i < y; ++i) {
                printf("%lld ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 28:
            printf("You chose to compute the n-th prime number\n\n"
                   "Inset the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            printf("The %lld-%s prime number is %lld\n\n\n", x,
                   (x == 1 ? "st" : (x == 2 ? "nd" : (x == 3 ? "rd" : "th"))), nthPrimeNumber(x));
            break;
        case 29:
            printf("You chose to compute the next prime number from the one given\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            printf("The next prime number from %lld is %lld\n\n\n", x, nextPrimeNumber(x));
            break;
        case 30:
            printf("You chose to compute the list of primitive roots modulo n\n\n"
                   "Insert the modulo value: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            list = primitiveRoots(x, &y);
            printf("The primitive roots modulo %lld %s: ", x, x == 1 ? "is" : "are");
            for (long long int i = 0; i < y; ++i) {
                printf("%lld ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 31:
            printf("You chose to compute the list of quadratic residual modulo n\n\n"
                   "Insert the modulo value: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);

            list = quadraticResiduals(x, &y);
            printf("The quadratic residual modulo %lld %s: ", x, x == 1 ? "is" : "are");
            for (long long int i = 0; i < y; ++i) {
                printf("%lld ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 32:
            printf("You chose to compute the Legendre symbol\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the odd prime number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("The Legendre_symbol(%lld, %lld) = %lld\n\n\n", x, y, LegendreSymbol(x, y));
            break;
        case 33:
            printf("You chose to compute the Jacobi symbol\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%lld", &x);
            assert(returnScanf > 0);
            printf("Insert the odd number: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("The Jacobi_symbol(%lld, %lld) = %lld\n\n\n", x, y, JacobiSymbol(x, y));
            break;
        case 34:
            printf("You chose to check if a matrix has all integer elements\n\n"
                   "Insert the matrix to check: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("The matrix:\n");
            printMatrix(matrix1);

            printf("The matrix insert %s all integer elements", isIntegerMatrix(matrix1) == 1 ? "has" : "has NOT");

            deleteMatrix(matrix1);
            printf("\n\n\n");
            break;
        case 35:
            printf("You chose to compute the matrix modulo n\n\n"
                   "Insert the matrix to compute the module: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(matrix1->n, matrix1->m);
            assert(res != NULL);
            modularMatrix(matrix1, res, module);
            printf("The matrix:\n");
            printMatrix(matrix1);
            printf("The matrix modulo %lld:\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 36:
            printf("You chose to compute the inversion modulo n\n\n"
                   "Insert the matrix to invert: \n");
            matrix1 = generateMatrixNxN(&x);
            assert(matrix1 != NULL);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, x);
            assert(res != NULL);

            res = createMatrix(matrix1->n, matrix1->m);
            assert(res != NULL);
            inverseMatrixModulo(matrix1, res, module);
            printf("The matrix:\n");
            printMatrix(matrix1);
            printf("The matrix inverse modulo %lld:\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 37:
            printf("You chose to compute the sum of 2 matrices modulo n\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&x1, &y1);
            assert(matrix2 != NULL);
            assert(x == x1);
            assert(y == y1);

            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y);
            assert(res != NULL);
            sumMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("+\n");
            printMatrix(matrix2);
            printf("(mod %lld)\n"
                   "=\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 38:
            printf("You chose to compute the difference of 2 matrices modulo n\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&x1, &y1);
            assert(matrix2 != NULL);
            assert(x == x1);
            assert(y == y1);

            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y);
            assert(res != NULL);
            subMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("-\n");
            printMatrix(matrix2);
            printf("(mod %lld) =\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 39:
            printf("You chose to compute the scalar product modulo n\n\n"
                   "Insert the K value: ");
            returnScanf = scanf("%lld", &x1);
            assert(returnScanf > 0);

            printf("Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("Insert the modulo value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y);
            assert(res != NULL);
            scalarProductModulo(x1, matrix1, res, module);

            printf("%lld\n"
                   "*\n", x1);
            printMatrix(matrix1);
            printf("(mod %lld) =\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 40:
            printf("You chose to compute the product of 2 matrices modulo n\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&x1, &y1);
            assert(matrix2 != NULL);
            assert(y == x1);

            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y1);
            assert(res != NULL);
            productMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("*\n");
            printMatrix(matrix2);
            printf("(mod %lld)\n"
                   "=\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 41:
            printf("You chose to compute the power elevation modulo n\n\n"
                   "Insert the matrix: \n");
            matrix1 = generateMatrixNxN(&x);
            assert(matrix1 != NULL);

            printf("Insert the exponent: ");
            returnScanf = scanf("%lld", &y);
            assert(returnScanf > 0);

            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, x);
            assert(res != NULL);
            printf("res\n");
            printMatrix(res);
            powerMatrixModulo(matrix1, y, res, module);

            printMatrix(matrix1);
            printf("^%lld\n"
                   "(mod %lld)\n"
                   "=\n", y, module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 42:
            printf("You chose to compute the Kronecker product of 2 matrices modulo n\n\n"
                   "Insert the first matrix: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("Insert the second matrix: \n");
            matrix2 = generateMatrixNxM(&x1, &y1);
            assert(matrix2 != NULL);

            printf("Insert the module value: ");
            returnScanf = scanf("%lld", &module);
            assert(returnScanf > 0);

            res = createMatrix(x * x1, y * y1);
            kroneckerProductMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("(*)\n");
            printMatrix(matrix2);
            printf("(mod %lld)\n"
                   "=\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        default:
            printf("Exit\n");
            *choice = 43;
            printf("\n\n\n");
            break;
    }
}


/**
 * Program Main.
 *
 * @return 0 if the program finished execution successfully.
 */
int main() {
    //The user choice.
    int choice = -1;
    //Return scanf value.
    int returScanf = 0;

    do {
        //print all the possible choice
        printChoice();

        //read the choice insert from the user
        printf("Insert your choice: ");
        returScanf = scanf("%d", &choice);
        assert(returScanf > 0);

        //manage the choice
        manageChoice(&choice);

        sleep(5);

    } while (choice != 43);

    return 0;
}