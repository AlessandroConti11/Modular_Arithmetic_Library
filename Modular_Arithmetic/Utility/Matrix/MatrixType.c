#include <string.h>
#include <assert.h>

#include "../Matrix.h"


/**
 * Checks if a matrix is an identity matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is an identity, 0 otherwise.
 */
int isIdentityMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            //the matrix is NOT the identity if it does NOT have all 1's on the main diagonal
            if (i == j && a->matrix[i][j] != 1) {
                //matrix is NOT the identity
                return 0;
            }
            //the matrix is NOT the identity if it does not have all 0s outside the main diagonal
            if (i != j && a->matrix[i][j] != 0) {
                //matrix is NOT the identity
                return 0;
            }
        }
    }

    //matrix is the identity
    return 1;
}

/**
 * Checks if a matrix is a null matrix.
 *
 * @param a the matrix - M: n x m.
 * @return 1 if the matrix is a null matrix, 0 otherwise.
 */
int isNullMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            //the matrix is NOT the null matrix iff it has a value different from 0
            if (a->matrix[i][j] != 0) {
                //matrix is NOT the null
                return 0;
            }
        }
    }

    //matrix is the null
    return 1;
}

/**
 * Checks if a matrix is diagonal matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is diagonal, 0 otherwise.
 */
int isDiagonalMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            //the matrix is NOT diagonal iff a[i][j]!=0, i!=j
            if (i != j && a->matrix[i][j] != 0) {
                //matrix is NOT diagonal
                return 0;
            }
        }
    }

    //matrix is diagonal
    return 1;
}

/**
 * Checks if a matrix is anti-diagonal matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is anti-diagonal, 0 otherwise.
 */
int isAntidiagonalMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            //the matrix is NOT antidiagonal iff a[i][j]!=0, i+j!=n-1
            if (i + j != a->n - 1 && a->matrix[i][j] != 0) {
                //matrix is NOT antidiagonal
                return 0;
            }
        }
    }
    //matrix is antidiagonal
    return 1;
}

/**
 * Checks if a matrix is an upper diagonal matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is upper diagonal, 0 otherwise.
 */
int isUpperDiagonalMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (i > j && a->matrix[i][j] != 0) {
                //matrix is NOT the upper diagonal
                return 0;
            }
        }
    }

    //matrix is upper diagonal
    return 1;
}

/**
 * Checks if a matrix is a lower diagonal matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is lower diagonal, 0 otherwise.
 */
int isLowerDiagonalMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (i < j && a->matrix[i][j] != 0) {
                //matrix is NOT the lower diagonal
                return 0;
            }
        }
    }

    //matrix is lower diagonal
    return 1;
}

/**
 * Checks if a matrix is a symmetric matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is symmetric, 0 otherwise.
 */
int isSymmetricMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (a->matrix[i][j] != a->matrix[j][i]) {
                //matrix is NOT symmetric diagonal
                return 0;
            }
        }
    }

    //matrix is symmetric diagonal
    return 1;
}

/**
 * Checks if a matrix is a antisymmetric matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is antisymmetric, 0 otherwise.
 */
int isAntisymmetricMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            if (a->matrix[j][i] != -a->matrix[i][j]) {
                //matrix is NOT symmetric diagonal
                return 0;
            }
        }
    }

    //matrix is symmetric diagonal
    return 1;
}

/**
 * Checks if a matrix is invertible.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is invertible, 0 otherwise.
 */
int isInvertibleMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    //matrix is NOT invertible if the determinant is equal to 0
    if (determinantMatrix(a) == 0) {
        //matrix is NOT invertible
        return 0;
    }

    //matrix is invertible
    return 1;
}

/**
 * Checks if a matrix is a row-echelon matrix.
 *
 * @param a the matrix - M: n x m.
 * @return 1 if the matrix is a row-echelon matrix, 0 otherwise.
 */
int isRowEchelonMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m > 0);

    //Last column position different from 0.
    int index = -1;
    //First non-zero element in the current row.
    int firstNonZero = -1;

    for (int i = 0; i < a->n; ++i) {
        firstNonZero = -1;
        for (int j = 0; j < a->m; ++j) {
            //all positions before the last index whose value is different from 0 must be 0
            if (a->matrix[i][j] != 0) {
                firstNonZero = j;
                break;
            }
        }

        //the whole row consists of 0
        if (firstNonZero == -1) {
            continue;
        }

        //the first non-zero element of the current row is in a column later than the previous row
        if (firstNonZero <= index) {
            //matrix is NOT step matrix
            return 0;
        }

        index = firstNonZero;
    }

    //matrix is step matrix
    return 1;
}

/**
 * Checks if a matrix is an Hankel matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is an Hankel matrix, 0 otherwise.
 */
int isHankelMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 1; i < a->n; ++i) {
        for (int j = 0; j < a->m - 1; ++j) {
            //a[i][j] == a[i-1][j+1]
            if (a->matrix[i][j] != a->matrix[i - 1][j + 1]) {
                //matrix is NOT Hankel matrix
                return 0;
            }
        }
    }
    //matrix is Hankel matrix
    return 1;
}

/**
 * Checks if a matrix is a Toeplitz matrix.
 *
 * @param a the matrix - M: n x n.
 * @return 1 if the matrix is a Toeplitz matrix, 0 otherwise.
 */
int isToeplitzMatrix(matrix *a) {
    assert(a->n > 0);
    assert(a->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            //a[i][j] == a[i-1][j-1]
            if (i - 1 >= 0 && j - 1 >= 0 && a->matrix[i][j] != a->matrix[i - 1][j - 1]) {
                //matrix is NOT Toeplitz matrix
                return 0;
            }
        }
    }
    //matrix is Toeplitz matrix
    return 1;
}


/**
 * Matrix transposition.
 *
 * @param a the matrix - M: n x m.
 * @param trans the the transposed matrix - M: m x n.
 */
void transposingMatrix(matrix *a, matrix *trans) {
    assert(a->n > 0);
    assert(a->m > 0);

    if (trans == NULL) {
        trans = createMatrix(a->m, a->n);
    }
    assert(trans->n == a->m);
    assert(trans->m == a->n);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            trans->matrix[j][i] = a->matrix[i][j];
        }
    }
}

/**
 * Matrix inversion - cofactor matrix method.
 * @warning the matrix a must be invertible
 *
 * @param a the matrix - M: n x n.
 * @param inv the inverse of the matrix - M: n x n.
 */
void inverseMatrix(matrix *a, matrix *inv) {
    assert(a->n > 0);
    assert(a->m > 0);
    assert(a->m == a->n);
    assert(isInvertibleMatrix(a) == 1);

    if (inv == NULL) {
        inv = createMatrix(a->n, a->m);
    }
    assert(inv->n == a->n);
    assert(inv->m == a->m);

    //Inverse of the determinant
    double invDet = (double) 1 / determinantMatrix(a);
    //Temporary matrix.
    matrix *tmp = createMatrix(a->n, a->m);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->n; ++j) {
            tmp->matrix[j][i] = invDet * cofactor(a, i, j);
        }
    }

    copyMatrix(tmp, inv);
    deleteMatrix(tmp);
}


/**
 * Transform a matrix to a row-echelon matrix - Gaussian elimination method.
 *
 * @param a the matrix - M: n x m.
 * @param step the row-echelon transformed matrix - M: n x m.
 */
void rowEchelonMatrix(matrix *a, matrix *step) {
    assert(a->n > 0);
    assert(a->m > 0);

    if (step == NULL) {
        step = createMatrix(a->n, a->m);
    }
    assert(step->n == a->n);
    assert(step->m == a->m);

    //Pivot row position.
    int elX = 0;
    //Pivot column position.
    int elY = 0;
    //Counter for rows.
    int counter = 0;
    //Cofactor.
    double cofactor = 0;
    //First non-null position.
    int pivotFound = 0;

    copyMatrix(a, step);

    while (elX < a->n && elY < a->m) {
        pivotFound = 0;
        for (int j = elY; j < a->m && !pivotFound; ++j) {
            for (int i = elX; i < a->n && !pivotFound; ++i) {
                if (step->matrix[i][j] != 0) {
                    elX = i;
                    elY = j;
                    pivotFound = 1;
                }
            }
        }

        //exit if no pivot found
        if (!pivotFound) {
            break;
        }

        //swap the current row with the one that has the first element different from 0
        swapRowMatrix(step, elX, counter, step);

        //eliminate all elements below the pivot
        for (int i = counter + 1; i < a->n; ++i) {
            if (step->matrix[i][elY] != 0) {
                cofactor = step->matrix[i][elY];
                for (int j = elY; j < a->m; ++j) {
                    step->matrix[i][j] -= cofactor * step->matrix[counter][j];
                }
            }
        }

        elX = counter + 1;
        elY++;
        counter++;
    }
}

/**
 * Absolute value matrix.

 * @param a the matrix - M: n x m.
 * @param abs the absolute value matrix - M: n x m.
 */
void absMatrix(matrix *a, matrix *abs) {
    assert(a->n > 0);
    assert(a->m > 0);

    if (abs == NULL) {
        abs = createMatrix(a->n, a->m);
    }
    assert(abs->n == a->n);
    assert(abs->m == a->m);

    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            abs->matrix[i][j] = a->matrix[i][j] < 0 ? -a->matrix[i][j] : a->matrix[i][j];
        }
    }
}