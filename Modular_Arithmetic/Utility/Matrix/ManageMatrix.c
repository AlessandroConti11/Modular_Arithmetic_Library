#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

#include "../Matrix.h"


/**
 * Creates a matrix - M: n x m.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @return the matrix - M: n x m.
 */
matrix *createMatrix(int n, int m) {
    assert(n > 0);
    assert(m > 0);

    //The matrix to create.
    matrix *a = (matrix *) malloc(sizeof(matrix));
    assert(a != NULL);

    a->matrix = (float **) malloc(n * sizeof(float *));
    assert(a->matrix != NULL);
    for (int i = 0; i < n; ++i) {
        a->matrix[i] = (float *) malloc(m * sizeof(float));
        assert(a->matrix[i] != NULL);
    }

    a->n = n;
    a->m = m;

    return a;
}

/**
 * Creates a identity matrix - M: n x n.
 *
 * @param n the matrix order.
 * @return the identity matrix - M: n x n.
 */
matrix *createIdentityMatrix(int n) {
    assert(n > 0);

    //The matrix to create.
    matrix *a = (matrix *) malloc(sizeof(matrix));
    assert(a != NULL);

    a->matrix = (float **) malloc(n * sizeof(float *));
    assert(a->matrix != NULL);

    for (int i = 0; i < n; ++i) {
        a->matrix[i] = (float *) calloc(n, sizeof(float));
        assert(a->matrix[i] != NULL);

        a->matrix[i][i] = 1;
    }

    a->n = n;
    a->m = n;

    return a;
}

/**
 * Creates a null matrix - M: n x n.
 *
 * @param n the number of row.
 * @param m the number of column.
 * @return the null matrix - M: n x n.
 */
matrix *createNullMatrix(int n, int m) {
    assert(n > 0);

    //The matrix to create.
    matrix *a = (matrix *) malloc(sizeof(matrix));
    assert(a != NULL);

    a->matrix = (float **) malloc(n * sizeof(float *));
    assert(a->matrix != NULL);

    for (int i = 0; i < n; ++i) {
        a->matrix[i] = (float *) calloc(m, sizeof(float));
        assert(a->matrix[i] != NULL);
    }

    a->n = n;
    a->m = m;

    return a;
}

/**
 * Initializes a matrix.
 *
 * @param a the matrix to initialize - M: n x m.
 * @param ... the matrix elements.
 */
void initializeMatrix(matrix *a, ...) {
    assert(a->n > 0);
    assert(a->m > 0);

    //Matrix elements.
    va_list elements;

    va_start(elements, a);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            a->matrix[i][j] = va_arg(elements, double);
        }
    }

    va_end(elements);
}

/**
 * Copies a matrix.
 *
 * @param a the matrix to be copied - M: n x m.
 * @param b the copied matrix - M: p x q with p>=n && q>=m.
 */
void copyMatrix(matrix *a, matrix *b) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(a->n <= b->n);
    assert(a->m <= b->m);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            b->matrix[i][j] = a->matrix[i][j];
        }
    }
}

/**
 * Deletes a matrix.
 *
 * @param a the matrix to be deleted - M: n x m.
 */
void deleteMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);

    if (a == NULL || a->matrix == NULL) {
        return;
    }

    //for each row
    for (int i = 0; i < a->n; i++) {
        free(a->matrix[i]);
        assert(a->matrix[i] != NULL);
    }

    free(a->matrix);
    assert(a->matrix != NULL);

    free(a);
    assert(a != NULL);
}

/**
 * Prints a matrix.
 *
 * @details digits integer part: 5
 * @details digits decimal part: 5
 * @param a the matrix to print - M: n x m.
 */
void printMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            printf("%5.5f ", a->matrix[i][j]);
        }
        printf("\n");
    }
}