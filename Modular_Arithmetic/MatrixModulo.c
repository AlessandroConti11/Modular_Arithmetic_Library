#include <assert.h>
#include <stdio.h>

#include "Utility/Matrix.h"
#include "../ModularArithmetic.h"


/**
 * Prints a matrix modulo n.
 *
 * @param a the matrix to prlong long int - M: k x m.
 * @param n the module value.
 */
void printMatrixModulo(matrix *a, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->m; ++j) {
            printf("%lld ", mod((int) a->matrix[i][j], n));
        }
        printf("\n");
    }
}


/**
 * Checks if a matrix has all integer elements.
 *
 * @param a the matrix - M: k x m.
 * @return 1 if the matrix has all integer elements, 0 otherwise.
 */
long long int isIntegerMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->m; ++j) {
            if (a->matrix[i][j] != (int) a->matrix[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}


/**
 * Matrix modulo n.
 *
 * @param a the matrix - M: k x m.
 * @param modMatrix the matrix modulo n - M: k x m.
 * @param n the module value.
 */
void modularMatrix(matrix *a, matrix *modMatrix, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");

    printf("ciao %d\n", modMatrix == NULL);
    if (modMatrix == NULL) {
        modMatrix = createMatrix(a->n, a->m);
    }
    assert(modMatrix->n == a->n);
    assert(modMatrix->m == a->m);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->m; ++j) {
            modMatrix->matrix[i][j] = mod((int) a->matrix[i][j], n);
            modMatrix->matrix[i][j] = modMatrix->matrix[i][j] < 0 ? modularReduction((int) modMatrix->matrix[i][j], n) : modMatrix->matrix[i][j];
        }
    }
}

/**
 * Matrix inversion modulo n - cofactor matrix method.
 * @warning a must have all integer elements.
 *
 * @param a the matrix - M: n x n.
 * @param inv the inverse of the matrix: [a]^-1 - M: n x n.
 * @param n the module value.
 */
void inverseMatrixModulo(matrix *a, matrix *inv, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");
    assert(isInvertibleMatrix(a) == 1);

    if (inv == NULL) {
        inv = createMatrix(a->n, a->m);
    }
    assert(inv->n == a->n);
    assert(inv->m == a->m);

    //Inverse of the determinant.
    long long int invDet = modularInverse((int) determinantMatrix(a), n);
    //Temporary matrix.
    matrix *tmp = createMatrix(a->n, a->m);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->n; ++j) {
            tmp->matrix[j][i] = product(invDet, (int) cofactor(a, i, j), n);
            tmp->matrix[i][j] = tmp->matrix[i][j] < 0 ? modularReduction((int) tmp->matrix[i][j], n) : tmp->matrix[i][j];
        }
    }

    copyMatrix(tmp, inv);
    deleteMatrix(tmp);
}


/**
 * Computes the sum of matrices modulo n.
 * @warning a and b must have all integer elements.
 *
 * @param a the first matrix - M: k x m.
 * @param b the second matrix - M: k x m.
 * @param res the result: [a] + [b] - M: k x m.
 * @param n the module value.
 */
void sumMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(b->n == a->n);
    assert(b->m == a->m);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");
    assert(isIntegerMatrix(b) && "the matrix must have all element integer");

    if (res == NULL) {
        res = createMatrix(a->n, a->m);
    }
    assert(res->n == a->n);
    assert(res->m == a->m);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->m; ++j) {
            res->matrix[i][j] = sum((int) a->matrix[i][j], (int) b->matrix[i][j], n);
            res->matrix[i][j] = res->matrix[i][j] < 0 ? modularReduction((int) res->matrix[i][j], n) : res->matrix[i][j];
        }
    }
}

/**
 * Computes the difference of matrices modulo n.
 * @warning a and b must have all integer elements.
 *
 * @param a the first matrix - M: k x m.
 * @param b the second matrix - M: k x m.
 * @param res the result: [a] - [b] - M: k x m.
 * @param n the module value.
 */
void subMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(b->n == a->n);
    assert(b->m == a->m);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");
    assert(isIntegerMatrix(b) && "the matrix must have all element integer");

    if (res == NULL) {
        res = createMatrix(a->n, a->m);
    }
    assert(res->n == a->n);
    assert(res->m == a->m);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->m; ++j) {
            res->matrix[i][j] = sum((int) a->matrix[i][j], modularReduction((int) b->matrix[i][j], n), n);
            res->matrix[i][j] = res->matrix[i][j] < 0 ? modularReduction((int) res->matrix[i][j], n) : res->matrix[i][j];
        }
    }
}

/**
 * Computes the scalar product of matrix modulo n.
 * @warning a must have all integer elements.
 *
 * @param scalar the scalar integer number.
 * @param a the first matrix - M: k x m.
 * @param res the result: scalar * [a] - M: k x m.
 * @param n the module value.
 */
void scalarProductModulo(long long int scalar, matrix *a, matrix *res, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");

    if (res == NULL) {
        res = createMatrix(a->n, a->m);
    }
    assert(res->n == a->n);
    assert(res->m == a->m);

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < a->m; ++j) {
            res->matrix[i][j] = product(scalar, (int) a->matrix[i][j], n);
            res->matrix[i][j] = res->matrix[i][j] < 0 ? modularReduction((int) res->matrix[i][j], n) : res->matrix[i][j];
        }
    }
}

/**
 * Computes the product of matrices modulo n.
 * @warning a and b must have all integer elements.
 *
 * @param a the first matrix - M: k x p.
 * @param b the second matrix - M: p x m.
 * @param res the result: [a] x [b] - M: k x m.
 * @param n the module value.
 */
void productMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(b->n == a->m);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");
    assert(isIntegerMatrix(b) && "the matrix must have all element integer");

    if (res == NULL) {
        res = createMatrix(a->n, b->m);
    }
    assert(res->n == a->n);
    assert(res->m == b->m);

    //Temporary variable used to save the product in position (i; j).
    long long int tmp = 0;

    for (long long int i = 0; i < a->n; ++i) {
        for (long long int j = 0; j < b->m; ++j) {
            res->matrix[i][j] = 0;
            for (long long int k = 0; k < a->m; ++k) {
                tmp = sum(tmp, product((int) a->matrix[i][j], (int) b->matrix[i][j], n), n);
            }
            res->matrix[i][j] = tmp;
            res->matrix[i][j] = res->matrix[i][j] < 0 ? modularReduction((int) res->matrix[i][j], n) : res->matrix[i][j];
        }
    }
}

/**
 * Computes the power elevation of a matrix modulo n.
 * @warning a must have all integer elements.
 *
 * @param a the first matrix - M: m x m.
 * @param k the exponent.
 * @param res the result: [a]^k - M: m x m.
 * @param n the module value.
 */
void powerMatrixModulo(matrix *a, long long int k, matrix *res, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);
    assert(k >= 0);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");

    //Temporary matrix used for compute the product.
    matrix *tmp = createMatrix(a->n, a->m);
    //Temporary matrix.
    matrix *aTmp = createMatrix(a->n, a->m);
    copyMatrix(a, aTmp);
    assert(tmp->n == a->n);
    assert(tmp->m == a->m);

    //initialize the res matrix
    copyMatrix(createIdentityMatrix(a->n), res);
    assert(res->n == a->n);
    assert(res->m == a->m);

    //compute the power
    for (long long int i = 0; i < k; ++i) {
        productMatrixModulo(res, aTmp, tmp, n);
        copyMatrix(tmp, res);
    }

    //delete
    deleteMatrix(tmp);
    deleteMatrix(aTmp);
}

/**
 * Computes the Kronecker product of matrices modulo n.
 * @warning a and b must have all integer elements.
 *
 * @param a the first matrix - M: k x m.
 * @param b the second matrix - M: p x q.
 * @param res the result: [a] (x) [b] - M: k*p x m*q.
 * @param n the module value,
 */
void kroneckerProductMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(isIntegerMatrix(a) && "the matrix must have all element integer");
    assert(isIntegerMatrix(b) && "the matrix must have all element integer");

    if (res == NULL) {
        res = createMatrix(a->n * b->n, a->m * b->m);
    }
    assert(res->n == a->n * b->n);
    assert(res->m == a->m * b->m);

    for (long long int i = 0; i < a->n * b->n; ++i) {
        for (long long int j = 0; j < a->m * b->m; ++j) {
            res->matrix[i][j] = product((int) a->matrix[i / b->n][j / b->m], (int) b->matrix[i % b->n][j % b->m], n);
            res->matrix[i][j] = res->matrix[i][j] < 0 ? modularReduction((int) res->matrix[i][j], n) : res->matrix[i][j];
        }
    }
}