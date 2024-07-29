#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
            returnScanf = scanf("%f", &matrix->matrix[i][j]);
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
            returnScanf = scanf("%f", &matrix->matrix[i][j]);
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
           "20. compute the modulus of 2 numbers\n"
           "21. compute a number congruent with the one given\n"
           "22. compute the modular reduction\n"
           "23. compute the modular inversion\n"
           "24. factorize an odd number\n"
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
           "37. compute the sum of matrices modulo n\n"
           "38. compute the difference of matricies modulo n\n"
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
    //The module value.
    int module;
    //The first unknown parameter.
    int x1;
    //The second unknown parameter.
    int y1;
    //The 2 square roots.
    int *squareRoots = NULL;
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

            squareRoots = TonelliShanksAlgorithm(x, module);
            printf("sqrt(%d) (mod %d) = %d (mod %d) %d (mod %d)\n\n\n", x, module, squareRoots[0], module, squareRoots[1], module);
            free(squareRoots);
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
            squareRoots = squareRoot(x, module, &y);
            printf("sqrt(%d) (mod %d) = ", x, module);
            for (int i = 0; i < y; ++i) {
                printf("%d (mod %d) ", squareRoots[i], module);
            }
            free(squareRoots);
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
            printf("You chose to compute the solution of a system of modular linear equation\n\n");
            //TODO
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
            printf("&dx + %dy = %d --> x = %d, y = %d\n\n\n", x, y, module, x1, y1);
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

            printf("%d %d= %d (mod %d)\n\n\n", x, areCongruent(x, y, module) == 1 ? '=' : '!', y, module);
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

            printf("%d (mod %d ) %s\n\n\n", x, module, isSquareNumber(x, module) == 1 ? "admits the square root" : "does not admits the square root");
            break;
        case 17:
            printf("You chose to check if a number is a primitive root modulo n\n\n"
                   "Insert the number: ");
            returnScanf = scanf("%d", &x);
            assert(returnScanf > 0);
            printf("Insert the module value: ");
            returnScanf = scanf("%d", &module);
            assert(returnScanf > 0);

            printf("%d (mod %d ) %s\n\n\n", x, module, isPrimitiveRoot(x, module) == 1 ? "is a primitive root" : "is not a primitive root");
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
            printf("the gcd(%d, %d) = %d\n\n\n", x, y, module); //TODO Bezout id
            break;
        case 20:

            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
        case 25:
            break;
        case 26:
            break;
        case 27:
            break;
        case 28:
            break;
        case 29:
            break;
        case 30:
            break;
        case 31:
            break;
        case 32:
            break;
        case 33:
            break;
        case 34:
            break;
        case 35:
            break;
        case 36:
            break;
        case 37:
            break;
        case 38:
            break;
        case 39:
            break;
        case 40:
            break;
        case 41:
            break;
        case 42:
            break;
        default:
            printf("Exit\n");
            *choice = 39;
            printf("\n\n\n");
            break;
    }
}


int main() {

    return 0;
}