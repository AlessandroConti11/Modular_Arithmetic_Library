#include <string.h>
#include <assert.h>

#include "../Matrix.h"


/**
 * Computes the minor of a matrix.
 *
 * @param a the matrix - M: n x n.
 * @param row the row of the matrix to be deleted.
 * @param column the column of the matrix to be deleted.
 * @return the minor of the matrix.
 */
double minor(matrix *a, int row, int column) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);
    assert(row >= 0);
    assert(row < a->n);
    assert(column >= 0);
    assert(column < a->m);

    //Minor row position.
    int minorRow = 0;
    //Minor column position.
    int minorColumn = 0;
    //Minor.
    matrix *minor = createMatrix(a->n - 1, a->m - 1);
    assert(minor->n == a->n-1);
    assert(minor->m == a->m-1);

    for (int i = 0; i < a->n; ++i) {
        if (i != row) {

            minorColumn = 0;
            for (int j = 0; j < a->m; ++j) {
                if (j != column) {
                    minor->matrix[minorRow][minorColumn] = a->matrix[i][j];
                    minorColumn++;
                }
            }
            minorRow++;
        }
    }

    return determinantMatrix(minor);
}

/**
 * Computes the cofactor of a matrix.
 *
 * @param a the matrix - M: n x n.
 * @param row the row of the matrix to be deleted.
 * @param column the column of the matrix to be deleted.
 * @return the cofactor of the matrix.
 */
double cofactor(matrix *a, int row, int column) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);
    assert(row >= 0);
    assert(row < a->n);
    assert(column >= 0);
    assert(column < a->m);

    //Cofactor row position.
    int cofRow = 0;
    //Cofactor column position.
    int cofColumn = 0;
    //Cofactor.
    matrix *cof = createMatrix(a->n - 1, a->m - 1);
    assert(cof->n == a->n-1);
    assert(cof->m == a->m-1);

    for (int i = 0; i < a->n; ++i) {
        if (i != row) {

            cofColumn = 0;
            for (int j = 0; j < a->m; ++j) {
                if (j != column) {
                    cof->matrix[cofRow][cofColumn] = a->matrix[i][j];
                    cofColumn++;
                }
            }
            cofRow++;
        }
    }

    return (row + column) % 2 == 0 ? determinantMatrix(cof) : -determinantMatrix(cof);
}

/**
 * Computes the determinant of the matrix.
 *
 * @param a the matrix n x n.
 * @return the determinant of the matrix.
 */
double determinantMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);

    //M: 1 x 1
    if (a->n == 1) {
        return a->matrix[0][0];
    }

    //M: 2 x 2
    if (a->n == 2) {
        return a->matrix[0][0] * a->matrix[1][1] - a->matrix[0][1] * a->matrix[1][0];
    }

    //M: n x n with n > 2
    //Determinant to compute.
    double det = 0;

    //det = SUM(a[0][i] * Cof(a[0][i]))
    for (int i = 0; i < a->n; i++) {
        //compute the cofactor
        det += i % 2 == 0
               ? a->matrix[0][i] * minor(a, 0, i)
               : -a->matrix[0][i] * minor(a, 0, i);
    }
    return det;
}

/**
 * Computes the rank of a matrix - minor method.
 *
 * @param a the matrix - M: n x m.
 * @return the rank of the matrix.
 */
int rankMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);

    if (a->n == a->m) {
        //if [A] is a square matrix, detA is different from 0 so the rank is the matrix order
        if (determinantMatrix(a) != 0) {
            return a->n;
        }
    }

    //general case for non-square matrices or square matrices with zero determinant

    //The maximum possible rank is the smaller dimension.
    int order = a->n < a->m ? a->n : a->m;

    for (int k = order; k > 0; --k) {
        //check all k x k minors
        for (int i = 0; i <= a->n - k; ++i) {
            for (int j = 0; j <= a->m - k; ++j) {
                //Extracts k x k minor starting at (i, j)
                matrix *minorMatrix = createMatrix(k, k);
                assert(minorMatrix->n == k);
                assert(minorMatrix->m == k);

                for (int row = 0; row < k; ++row) {
                    for (int col = 0; col < k; ++col) {
                        minorMatrix->matrix[row][col] = a->matrix[i + row][j + col];
                    }
                }
                //check if this minor has a non-zero determinant
                if (determinantMatrix(minorMatrix) != 0) {
                    return k;
                }
                deleteMatrix(minorMatrix);
            }
        }
    }

    //if no non-zero determinant minor found, the rank is 0
    return 0;
}


/**
 * Computes the sum of matrices.
 *
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: n x m.
 * @param res the result: [a] + [b] - M: n x m.
 */
void sumMatrix(matrix *a, matrix *b, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(b->n == a->n);
    assert(b->m == a->m);

    if (res == NULL) {
        res = createMatrix(a->n, a->m);
    }
    assert(res->n == a->n);
    assert(res->m == a->m);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            res->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
}

/**
 * Computes the difference of matrices.
 *
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: n x m.
 * @param res the result: [a] + [b] - M: n x m.
 */
void subMatrix(matrix *a, matrix *b, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(b->n == a->n);
    assert(b->m == a->m);

    if (res == NULL) {
        res = createMatrix(a->n, a->m);
    }
    assert(res->n == a->n);
    assert(res->m == a->m);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            res->matrix[i][j] = a->matrix[i][j] - b->matrix[i][j];
        }
    }
}

/**
 * Computes the scalar product of a matrix.
 *
 * @param scalar the scalar number.
 * @param a the matrix - M: n x m.
 * @param res the result: scalar * [a] - M: n x m.
 */
void scalarProductMatrix(double scalar, matrix *a, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);

    if (res == NULL) {
        res = createMatrix(a->n, a->m);
    }
    assert(res->n == a->n);
    assert(res->m == a->m);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            res->matrix[i][j] = scalar * a->matrix[i][j];
        }
    }
}

/**
 * Computes the product of matrices.
 *
 * @param a the first matrix - M: n x p.
 * @param b the second matrix - M: p x m.
 * @param res the result: [a] x [b] - M: n x m.
 */
void productMatrix(matrix *a, matrix *b, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);
    assert(b->n == a->m);

    if (res == NULL) {
        res = createMatrix(a->n, b->m);
    }
    assert(res->n == a->n);
    assert(res->m == b->m);

    //Temporary variable used to save the product in position (i; j).
    double tmp = 0;

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < b->m; ++j) {
            res->matrix[i][j] = 0;
            for (int k = 0; k < a->m; ++k) {
                tmp += a->matrix[i][k] * b->matrix[k][j];
            }
            res->matrix[i][j] = tmp;
        }
    }
}

/**
 * Computes the power elevation of a matrix.
 *
 * @param a the matrix - M: n x n.
 * @param k the exponent.
 * @param res the result: [a]^k - M: n x n.
 */
void powerMatrix(matrix *a, int k, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);
    assert(k >= 0);

    //Temporary matrix used for compute the product.
    matrix *tmp = createMatrix(a->n, a->m);
    //Temporary matrix used if res is a.
    matrix *aTmp = createMatrix(a->n, a->m);
    copyMatrix(a, aTmp);
    assert(tmp->n == a->n);
    assert(tmp->m == a->m);

    //initialize the res matrix
    deleteMatrix(res);
    res = createIdentityMatrix(a->n);
    assert(res->n == a->n);
    assert(res->m == a->m);

    //compute the power
    for (int i = 0; i < k; ++i) {
        productMatrix(res, aTmp, tmp);
        copyMatrix(tmp, res);
    }

    //delete
    deleteMatrix(tmp);
    deleteMatrix(aTmp);
}

/**
 * Computes the direct sum of matrices.
 *
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: p x q.
 * @param res the result: [a] (+) [b] - M: n+p x m+q.
 */
void directSumMatrix(matrix *a, matrix *b, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);

    if (res == NULL) {
        res = createMatrix(a->n + b->n, a->m + b->m);
    }
    assert(res->n == a->n + b->n);
    assert(res->m == a->m + b->m);

    for (int i = 0; i < a->n + b->n; ++i) {
        for (int j = 0; j < a->m + b->m; ++j) {
            //upper left corner - first matrix
            if (i < a->n && j < a->m) {
                res->matrix[i][j] = a->matrix[i][j];
            }
                //bottom right corner - second matrix
            else if (i >= a->n && j >= a->m) {
                res->matrix[i][j] = b->matrix[i - a->n][j - a->m];
            }
                //other position - 0
            else {
                res->matrix[i][j] = 0;
            }
        }
    }
}

/**
 * Computes the Kronecker product of matrices.
 *
 * @param a the first matrix - M: n x m.
 * @param b the second matrix - M: p x q.
 * @param res the result: [a] (x) [b] - M: n*p x m*q.
 */
void kroneckerProductMatrix(matrix *a, matrix *b, matrix *res) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(b->n > 0);
    assert(b->m > 0);

    if (res == NULL) {
        res = createMatrix(a->n * b->n, a->m * b->m);
    }
    assert(res->n == a->n * b->n);
    assert(res->m == a->m * b->m);

    for (int i = 0; i < a->n * b->n; ++i) {
        for (int j = 0; j < a->m * b->m; ++j) {
            res->matrix[i][j] = a->matrix[i / b->n][j / b->m] * b->matrix[i % b->n][j % b->m];
        }
    }
}