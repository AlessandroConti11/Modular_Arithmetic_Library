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
matrix *generateMatrixNxM(int *row, int *column) {
    //Matrix.
    matrix *matrix = NULL;
    //Return scanf value.
    int returnScanf = 0;

    printf("Enter the number of row: ");
    returnScanf = scanf("%d", row);
    assert(returnScanf > 0);
    printf("Enter the number of column: ");
    returnScanf = scanf("%d", column);
    assert(returnScanf > 0);

    matrix = createMatrix(*row, *column);

    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j < *column; ++j) {
            printf("Insert the value for position (%d; %d): ", i, j);
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
matrix *generateMatrixNxN(int *row) {
    //Matrix.
    matrix *matrix = NULL;
    //Return scanf value.
    int returnScanf = 0;

    printf("Enter the matrix order: ");
    returnScanf = scanf("%d", row);
    assert(returnScanf > 0);

    matrix = createMatrix(*row, *row);

    for (int i = 0; i < *row; ++i) {
        for (int j = 0; j < *row; ++j) {
            printf("Insert the value for position (%d; %d): ", i, j);
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
    int x;
    //The second number.
    int y;
    //The third number.
    int x1;
    //The fourth number.
    int y1;
    //The module value.
    int module;
    //The list.
    int *list = NULL;
    //Matrices.
    matrix *matrix1 = NULL, *matrix2 = NULL, *res = NULL;
    //Return scanf value.
    int returnScanf = 0;

    switch (*choice) {
        case 1:
            printf("You chose to compute the sum modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d + %d (mod %d) = %d (mod %d)\n\n\n", x, y, module, sum(x, y, module), module);
            break;
        case 2:
            printf("You chose to compute the difference modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d - %d (mod %d) = %d (mod %d)\n\n\n", x, y, module, sub(x, y, module), module);
            break;
        case 3:
            printf("You chose to compute the product modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d * %d (mod %d) = %d (mod %d)\n\n\n", x, y, module, product(x, y, module), module);
            break;
        case 4:
            printf("You chose to compute the division modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d / %d (mod %d) = %d (mod %d)\n\n\n", x, y, module, division(x, y, module), module);
            break;
        case 5:
            printf("You chose to compute the power elevation modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the exponent: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d^%d (mod %d) = %d (mod %d)\n\n\n", x, y, module, power(x, y, module), module);
            break;
        case 6:
            printf("You chose to compute the square roots modulo p using the Tonelli-Shanks algorithm\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the module value - prime number: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            list = TonelliShanksAlgorithm(x, module);
            printf("sqrt(%d) (mod %d) = %d (mod %d) %d (mod %d)\n\n\n", x, module, list[0], module, list[1], module);
            free(list);
            break;
        case 7:
            printf("You chose to compute the square roots modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            //The 2 square roots.
            list = squareRoot(x, module, &y);
            printf("sqrt(%d) (mod %d) = ", x, module);
            for (int i = 0; i < y; ++i) {
                printf("%d (mod %d) ", list[i], module);
            }
            free(list);
            printf("\n\n\n");
            break;
        case 8:
            printf("You chose to compute the discrete logarithm modulo n\n\n"
                   "Insert the base: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d^x = %d (mod %d) --> x = %d\n\n\n", x, y, module, discreteLogarithm(x, y, module));
            break;
        case 9:
            printf("You chose to compute the solution of a system of modular linear equation\n\n"
                   "Insert the number of equation: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            //The list of parameters.
            int *parameter = malloc(x * sizeof(int));
            //The list of modules.
            int *modules = malloc(x * sizeof(int));

            for (int i = 0; i < x; ++i) {
                printf("Insert the %d-%s parameter: ", (i + 1),
                       ((i + 1) == 1 ? "st" : ((i + 1) == 2 ? "nd" : ((i + 1) == 3 ? "rd" : "th"))));
                returnScanf = scanf("%d", (parameter + i));
                assert(returnScanf > 0);

                printf("Insert the %d-%s module: ", (i + 1),
                       ((i + 1) == 1 ? "st" : ((i + 1) == 2 ? "nd" : ((i + 1) == 3 ? "rd" : "th"))));
                returnScanf = scanf("%d", (modules + i));
                assert(returnScanf > 0);
            }

            y = chineseReminderTheorem(x, parameter, modules);

            for (int i = 0; i < x; ++i) {
                printf("x = %d (mod %d)\n", parameter[i], modules[i]);
            }
            printf("--> x = %d\n\n\n", y);

            free(parameter);
            free(modules);
            break;
        case 10:
            printf("You chose to compute the solution of a linear diophantine equation\n\n"
                   "Insert the first parameter: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second parameter: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the third parameter: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            diophantineEquation(x, &x1, y, &y1, module);
            printf("%dx + %dy = %d --> x = %d, y = %d\n\n\n", x, y, module, x1, y1);
            break;
        case 11:
            printf("You chose to check if 2 numbers are congruent modulo m\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d %c= %d (mod %d)\n\n\n", x, areCongruent(x, y, module) == 1 ? '=' : '!', y, module);
            break;
        case 12:
            printf("You chose to check if 2 numbers are coprime\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("%d %s coprime %d\n\n\n", x, areCoPrime(x, y) == 1 ? "are" : "are not", y);
            break;
        case 13:
            printf("You chose to check if a number is a divisor of another one\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("%d %s %d \n\n\n", x, isDivisor(x, y) == 1 ? "|" : "!|", y);
            break;
        case 14:
            printf("You chose to check if a number is NOT prime using the Fermat's Pseudoprime assumption\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            printf("%d %s prime\n\n\n", x, isFermatPseudoPrime(2, x) == 1 ? "is" : "is NOT");
            break;
        case 15:
            printf("You chose to check if a number is prime\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            printf("%d %s prime\n\n\n", x, isPrime(x) == 1 ? "is" : "is NOT");
            break;
        case 16:
            printf("You chose to check if a number admits the square root modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d (mod %d) %s\n\n\n", x, module, isSquareNumber(x, module) == 1 ? "admits the square root" : "does NOT admit the square root");
            break;
        case 17:
            printf("You chose to check if a number is a primitive root modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d (mod %d) %s\n\n\n", x, module, isPrimitiveRoot(x, module) == 1 ? "is a primitive root" : "is not a primitive root");
            break;
        case 18:
            printf("You chose to compute the gcd\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("the gcd(%d, %d) = %d\n\n\n", x, y, gcd(x, y));
            break;
        case 19:
            printf("You chose to compute the gcd using the Extended Euclid's algorithm\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            module = extendedGCD(x, y, &x1, &y1);
            printf("The gcd(%d, %d) = %d --> %d * %d + %d * %d = %d\n\n\n", x, y, module, x, x1, y, y1, module);
            break;
        case 20:
            printf("You chose to compute the module of 2 numbers\n\n"
                   "Insert the first number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the second number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("%d (mod %d) = %d\n\n\n", x, y, mod(x, y));
            break;
        case 21:
            printf("You chose to compute a number congruent with the one given\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("A number congruent with %d is %d\n\n\n", x, congruentNumber(x, y));
            break;
        case 22:
            printf("You chose to compute the modular reduction of a number\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("%d = %d (mod %d)\n\n\n", x, modularReduction(x, y), y);
            break;
        case 23:
            printf("You chose to compute the modular inversion of a number\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the modulo value: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("1/%d = %d (mod %d)\n\n\n", x, modularInverse(x, y), y);
            break;
        case 24:
            printf("You chose to factorize an odd number\n\n"
                   "Insert the odd number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            list = FermatFactorisation(x, &y);
            printf("The factors of %d %s: ", x, y == 1 ? "is" : "are");
            for (int i = 0; i < y; ++i) {
                printf("%d ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 25:
            printf("You chose to factorize a number\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            list = factorisation(x, &y);
            printf("The factors of %d %s: ", x, y == 1 ? "is" : "are");
            for (int i = 0; i < y; ++i) {
                printf("%d ", list[i]);
            }
            free(list);
            printf("\n\n\n");
            break;
        case 26:
            printf("You chose to compute the Euler function\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            printf("Euler_function(%d) = %d\n\n\n", x, EulerFunction(x));
            break;
        case 27:
            printf("You chose to compute the list of prime number up to the n-th\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            list = primeNumberList(x, &y);
            printf("The first %d prime number %s: ", x, x == 1 ? "is" : "are");
            for (int i = 0; i < y; ++i) {
                printf("%d ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 28:
            printf("You chose to compute the n-th prime number\n\n"
                   "Inset the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            printf("The %d-%s prime number is %d\n\n\n", x,
                   (x == 1 ? "st" : (x == 2 ? "nd" : (x == 3 ? "rd" : "th"))), nthPrimeNumber(x));
            break;
        case 29:
            printf("You chose to compute the next prime number from the one given\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            printf("The next prime number from %d is %d\n\n\n", x, nextPrimeNumber(x));
            break;
        case 30:
            printf("You chose to compute the list of primitive roots modulo n\n\n"
                   "Insert the modulo value: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            list = primitiveRoots(x, &y);
            printf("The primitive roots modulo %d %s: ", x, x == 1 ? "is" : "are");
            for (int i = 0; i < y; ++i) {
                printf("%d ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 31:
            printf("You chose to compute the list of quadratic residual modulo n\n\n"
                   "Insert the modulo value: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);

            list = quadraticResiduals(x, &y);
            printf("The quadratic residual modulo %d %s: ", x, x == 1 ? "is" : "are");
            for (int i = 0; i < y; ++i) {
                printf("%d ", list[i]);
            }
            printf("\n\n\n");
            free(list);
            break;
        case 32:
            printf("You chose to compute the Legendre symbol\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the odd prime number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("The Legendre_symbol(%d, %d) = %d\n\n\n", x, y, LegendreSymbol(x, y));
            break;
        case 33:
            printf("You chose to compute the Jacobi symbol\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the odd number: ");
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("The Jacobi_symbol(%d, %d) = %d\n\n\n", x, y, JacobiSymbol(x, y));
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
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(matrix1->n, matrix1->m);
            assert(res != NULL);
            modularMatrix(matrix1, res, module);
            printf("The matrix:\n");
            printMatrix(matrix1);
            printf("The matrix modulo %d:\n", module);
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
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, x);
            assert(res != NULL);

            res = createMatrix(matrix1->n, matrix1->m);
            assert(res != NULL);
            inverseMatrixModulo(matrix1, res, module);
            printf("The matrix:\n");
            printMatrix(matrix1);
            printf("The matrix inverse modulo %d:\n", module);
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
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y);
            assert(res != NULL);
            sumMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("+\n");
            printMatrix(matrix2);
            printf("(mod %d)\n"
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
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y);
            assert(res != NULL);
            subMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("-\n");
            printMatrix(matrix2);
            printf("(mod %d) =\n", module);
            printMatrix(res);

            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(res);
            printf("\n\n\n");
            break;
        case 39:
            printf("You chose to compute the scalar product modulo n\n\n"
                   "Insert the K value: ");
            returnScanf = scanf("%d", &x1);
            assert(returnScanf > 0);

            printf("Insert the matrix: \n");
            matrix1 = generateMatrixNxM(&x, &y);
            assert(matrix1 != NULL);

            printf("Insert the modulo value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y);
            assert(res != NULL);
            scalarProductModulo(x1, matrix1, res, module);

            printf("%d\n"
                   "*\n", x1);
            printMatrix(matrix1);
            printf("(mod %d) =\n", module);
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
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, y1);
            assert(res != NULL);
            productMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("*\n");
            printMatrix(matrix2);
            printf("(mod %d)\n"
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
            returnScanf = scanf("%d", &y);
            assert(returnScanf > 0);

            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x, x);
            assert(res != NULL);
            printf("res\n");
            printMatrix(res);
            powerMatrixModulo(matrix1, y, res, module);

            printMatrix(matrix1);
            printf("^%d\n"
                   "(mod %d)\n"
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
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            res = createMatrix(x * x1, y * y1);
            kroneckerProductMatrixModulo(matrix1, matrix2, res, module);

            printMatrix(matrix1);
            printf("(*)\n");
            printMatrix(matrix2);
            printf("(mod %d)\n"
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