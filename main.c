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
           "14. check if a mumber is NOT prime using the Fermat's Pseudoprime to a assumption\n"
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


int main() {

    return 0;
}