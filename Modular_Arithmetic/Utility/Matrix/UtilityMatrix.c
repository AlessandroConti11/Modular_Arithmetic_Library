#include <assert.h>
#include <stdlib.h>

#include "../Matrix.h"


/**
 * Swaps 2 rows of a matrix.
 *
 * @param a the matrix - M: n x m.
 * @param row1 the first row to be swapped.
 * @param row2 the second row to be swapped.
 * @param swap the swapped matrix.
 */
void swapRowMatrix(matrix *a, int row1, int row2, matrix *swap) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(row1 <= a->n);
    assert(row2 <= a->n);

    if (swap == NULL) {
        swap = createMatrix(a->n, a->m);
    }
    assert(swap->n >= a->n);
    assert(swap->m >= a->m);
    
    //Temporary variable used for the swap procedure.
    float tmp = 0;

    copyMatrix(a, swap);

    for (int i = 0; i < a->m; ++i) {
        tmp = a->matrix[row1][i];
        swap->matrix[row1][i] = a->matrix[row2][i];
        swap->matrix[row2][i] = tmp;
    }
}

/**
 * Swaps 2 columns of a matrix.
 *
 * @param a the matrix - M: n x m.
 * @param col1 the first column to be swapped.
 * @param col2 the second column to be swapped.
 * @param swap the swapped matrix.
 */
void swapColumnMatrix(matrix *a, int col1, int col2, matrix *swap) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(col1 <= a->n);
    assert(col2 <= a->n);

    if (swap == NULL) {
        swap = createMatrix(a->n, a->m);
    }
    assert(swap->n >= a->n);
    assert(swap->m >= a->m);
    
    //Temporary variable used for the swap procedure.
    float tmp = 0;

    copyMatrix(a, swap);

    for (int i = 0; i < a->n; ++i) {
        tmp = a->matrix[i][col1];
        swap->matrix[i][col1] = a->matrix[i][col2];
        swap->matrix[i][col2] = tmp;
    }
}

/**
 * Finds the maximum value in a matrix.
 *
 * @param a the matrix - M: n x m.
 * @param rowPos the row containing the position with the maximum value.
 * @param colPos the column containing the position with the maximum value.
 * @return the maximum value in the matrix.
 */
float findMaxMatrix(matrix *a, int *rowPos, int *colPos) {
    //Initialize the maximum value.
    float max = a->matrix[0][0];
    *rowPos = 0;
    *colPos = 0;
    
    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (a->matrix[i][j] > max) {
                max = a->matrix[i][j];
                *rowPos = i;
                *colPos = j;
            }
        }
    }
    return max;
}

/**
 * Finds the minimum value in a matrix.
 *
 * @param a the matrix - M: n x m.
 * @param rowPos the row containing the position with the minimum value.
 * @param colPos the column containing the position with the minimum value.
 * @return the minimum value in the matrix.
 */
float findMinMatrix(matrix *a, int *rowPos, int *colPos) {
    //Initialize the maximum value.
    float min = a->matrix[0][0];
    *rowPos = 0;
    *colPos = 0;
    
    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (a->matrix[i][j] < min) {
                min = a->matrix[i][j];
                *rowPos = i;
                *colPos = j;
            }
        }
    }
    return min;
}

/**
 * Finds the elements on the diagonal of a matrix.
 *
 * @param a the matrix - M: n x m.
 * @param numberOfElements the number of elements on the diagonal.
 * @return the list of elements on the diagonal of the matrix.
 */
float *diagonalMatrix(matrix *a, int *numberOfElements) {
    assert(a->n > 0);
    assert(a->m > 0);

    *numberOfElements = a->n < a->m ? a->n : a->m;
    float* diagonalValues = malloc(*numberOfElements * sizeof(float));

    for (int i = 0; i < *numberOfElements; ++i) {
        diagonalValues[i] = a->matrix[i][i];
    }

    return diagonalValues;
}


/**
 * Finds the pivots in a matrix.
 *
 * @param a the matrix - M: n x m.
 * @param pivotsNumber the number of pivots.
 * @return the list of pivots.
 */
float *pivot(matrix *a, int *pivotsNumber) {
    assert(a->n > 0);
    assert(a->m > 0);

    //The step matrix.
    matrix *step = createMatrix(a->n, a->m);
    //The pivot list.
    float *pivots = malloc((a->n < a->m ? a->n : a->m) * sizeof(float));
    //The counter of pivots found.
    int pivotCounter = 0;

    rowEchelonMatrix(a, step);
    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (step->matrix[i][j] != 0) {
                pivots[pivotCounter] = step->matrix[i][j];
                pivotCounter++;
                break;
            }
        }
    }

    *pivotsNumber = pivotCounter;
    deleteMatrix(step);
    return pivots;
}

/**
 * Decomposition of a matrix using Lower-Upper Decomposition - [A]=[L]*[U].
 *
 * @param a the matrix - M: n x n.
 * @param l the lower triangular matrix - M: n x n.
 * @param u the upper triangular matrix - M: n x n.
 */
void luDecomposition(matrix *a, matrix *l, matrix *u) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->n == a->m);

    if (l == NULL) {
        l = createMatrix(a->n, a->m);
    }
    assert(l->n == a->n);
    assert(l->m == a->m);
    if (u == NULL) {
        u = createMatrix(a->n, a->m);
    }
    assert(u->n == a->n);
    assert(u->m == a->m);

    //Used to compute the elements of the matrix U.
    float sum = 0;

    //initialize L and U matrix
    deleteMatrix(l);
    l = createNullMatrix(a->n, a->m);
    deleteMatrix(u);
    u = createNullMatrix(a->n, a->m);

    for (int i = 0; i < a->n; ++i) {
        //compute U matrix
        for (int j = 0; j < a->m; ++j) {
            sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += l->matrix[i][k] * u->matrix[k][j];
            }
            u->matrix[i][j] = a->matrix[i][j] - sum;
        }

        //compute L matrix
        for (int k = 0; k < a->n; ++k) {
            if (i==k) {
                l->matrix[i][i] = 1;
            }
            else {
                sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum += l->matrix[k][j] * u->matrix[j][i];
                }
                l->matrix[k][i] = (float) (a->matrix[k][i] - sum) / u->matrix[i][i];
                if (l->matrix[k][i] == -0) {
                    l->matrix[k][i] = 0;
                }
            }
        }
    }
}