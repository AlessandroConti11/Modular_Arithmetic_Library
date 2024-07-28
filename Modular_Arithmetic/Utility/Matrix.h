#ifndef CIPHER_MATRIX_H

    #define CIPHER_MATRIX_H


    /**
     * Struct --> represents an n x m matrix.
     *
     * @details matrix - M: n x m.
     * @details n - number of row.
     * @details m - number of column.
     */
    typedef struct Matrix {
        double **matrix;
        int n;
        int m;
    }matrix;


//******************************************************************************************************************//


    //*****************//
    //  MANAGE MATRIX  //
    //*****************//


    /**
     * Creates a matrix - M: n x m.
     *
     * @param n the number of row.
     * @param m the number of column.
     * @return the matrix - M: n x m.
     */
    matrix *createMatrix(int n, int m);

    /**
     * Creates an identity matrix - M: n x n.
     *
     * @param n the matrix order.
     * @return the identity matrix - M: n x n.
     */
    matrix *createIdentityMatrix(int n);

    /**
     * Creates a null matrix - M: n x n.
     *
     * @param n the number of row.
     * @param m the number of column.
     * @return the null matrix - M: n x n.
     */
    matrix *createNullMatrix(int n, int m);

    /**
     * Initializes a matrix.
     *
     * @param a the matrix to initialize - M: n x m.
     * @param ... the matrix elements.
     */
    void initializeMatrix(matrix *a, ...);

    /**
     * Copies a matrix.
     *
     * @param a the matrix to be copied - M: n x m.
     * @param b the copied matrix - M: p x q with p>=n && q>=m.
     */
    void copyMatrix(matrix *a, matrix *b);

    /**
     * Deletes a matrix.
     *
     * @param a the matrix to be deleted - M: n x m.
     */
    void deleteMatrix(matrix *a);

    /**
     * Prints a matrix.
     *
     * @details digits integer part: 5
     * @details digits decimal part: 5
     * @param a the matrix to print - M: n x m.
     */
    void printMatrix(matrix *a);


//******************************************************************************************************************//


    //***************//
    //  MATRIX TYPE  //
    //***************//


    /**
     * Checks if a matrix is an identity matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is an identity, 0 otherwise.
     */
    int isIdentityMatrix(matrix *a);

    /**
     * Checks if a matrix is a null matrix.
     *
     * @param a the matrix - M: n x m.
     * @return 1 if the matrix is a null matrix, 0 otherwise.
     */
    int isNullMatrix(matrix *a);

    /**
     * Checks if a matrix is diagonal matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is diagonal, 0 otherwise.
     */
    int isDiagonalMatrix(matrix *a);

    /**
     * Checks if a matrix is anti-diagonal matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is anti-diagonal, 0 otherwise.
     */
    int isAntidiagonalMatrix(matrix *a);

    /**
     * Checks if a matrix is an upper diagonal matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is upper diagonal, 0 otherwise.
     */
    int isUpperDiagonalMatrix(matrix *a);

    /**
     * Checks if a matrix is a lower diagonal matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is lower diagonal, 0 otherwise.
     */
    int isLowerDiagonalMatrix(matrix *a);

    /**
     * Checks if a matrix is a symmetric matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is symmetric, 0 otherwise.
     */
    int isSymmetricMatrix(matrix *a);

    /**
     * Checks if a matrix is a antisymmetric matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is antisymmetric, 0 otherwise.
     */
    int isAntisymmetricMatrix(matrix *a);

    /**
     * Checks if a matrix is invertible.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is invertible, 0 otherwise.
     */
    int isInvertibleMatrix(matrix *a);

    /**
     * Checks if a matrix is a row-echelon matrix.
     *
     * @param a the matrix - M: n x m.
     * @return 1 if the matrix is a row-echelon matrix, 0 otherwise.
     */
    int isRowEchelonMatrix(matrix *a);

    /**
     * Checks if a matrix is an Hankel matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is an Hankel matrix, 0 otherwise.
     */
    int isHankelMatrix(matrix *a);

    /**
     * Checks if a matrix is a Toeplitz matrix.
     *
     * @param a the matrix - M: n x n.
     * @return 1 if the matrix is a Toeplitz matrix, 0 otherwise.
     */
    int isToeplitzMatrix(matrix *a);


    /**
     * Matrix transposition.
     *
     * @param a the matrix - M: n x m.
     * @param trans the the transposed matrix: [a]^T - M: m x n.
     */
    void transposingMatrix(matrix *a, matrix *trans);

    /**
     * Matrix inversion - cofactor matrix method.
     *
     * @param a the matrix - M: n x n.
     * @param inv the inverse of the matrix: [a]^-1 - M: n x n.
     */
    void inverseMatrix(matrix *a, matrix *inv);

    /**
     * Transform a matrix to a row-echelon matrix - Gaussian elimination method.
     *
     * @param a the matrix - M: n x m.
     * @param step the row-echelon transformed matrix - M: n x m.
     */
    void rowEchelonMatrix(matrix *a, matrix *step);

    /**
     * Absolute value matrix.
     *
     * @param a the matrix - M: n x m.
     * @param abs the absolute value matrix - M: n x m.
     */
    void absMatrix(matrix *a, matrix *abs);


//******************************************************************************************************************//


    //********************//
    //  MATRIX OPERATION  //
    //********************//


    /**
     * Computes the minor of a matrix.
     *
     * @param a the matrix - M: n x n.
     * @param row the row of the matrix to be deleted.
     * @param column the column of the matrix to be deleted.
     * @return the minor of the matrix.
     */
    double minor(matrix *a, int row, int column);

    /**
     * Computes the cofactor of a matrix.
     *
     * @param a the matrix - M: n x n.
     * @param row the row of the matrix to be deleted.
     * @param column the column of the matrix to be deleted.
     * @return the cofactor of the matrix.
     */
    double cofactor(matrix *a, int row, int column);

    /**
     * Computes the determinant of the matrix.
     *
     * @param a the matrix n x n.
     * @return the determinant of the matrix.
     */
    double determinantMatrix(matrix *a);

    /**
     * Computes the rank of a matrix - minor method.
     *
     * @param a the matrix - M: n x m.
     * @return the rank of the matrix.
     */
    int rankMatrix(matrix *a);


    /**
     * Computes the sum of matrices.
     *
     * @param a the first matrix - M: n x m.
     * @param b the second matrix - M: n x m.
     * @param res the result: [a] + [b] - M: n x m.
     */
    void sumMatrix(matrix *a, matrix *b, matrix *res);

    /**
     * Computes the difference of matrices.
     *
     * @param a the first matrix - M: n x m.
     * @param b the second matrix - M: n x m.
     * @param res the result: [a] + [b] - M: n x m.
     */
    void subMatrix(matrix *a, matrix *b, matrix *res);

    /**
     * Computes the scalar product of a matrix.
     *
     * @param scalar the scalar number.
     * @param a the matrix - M: n x m.
     * @param res the result: scalar * [a] - M: n x m.
     */
    void scalarProductMatrix(double scalar, matrix *a, matrix *res);

    /**
     * Computes the product of matrices.
     *
     * @param a the first matrix - M: n x p.
     * @param b the second matrix - M: p x m.
     * @param res the result: [a] x [b] - M: n x m.
     */
    void productMatrix(matrix *a, matrix *b, matrix *res);

    /**
     * Computes the power elevation of a matrix.
     *
     * @param a the matrix - M: n x n.
     * @param k the exponent.
     * @param res the result: [a]^k - M: n x n.
     */
    void powerMatrix(matrix *a, int k, matrix *res);

    /**
     * Computes the direct sum of matrices.
     *
     * @param a the first matrix - M: n x m.
     * @param b the second matrix - M: p x q.
     * @param res the result: [a] (+) [b] - M: n+p x m+q.
     */
    void directSumMatrix(matrix *a, matrix *b, matrix *res);

    /**
     * Computes the Kronecker product of matrices.
     *
     * @param a the first matrix - M: n x m.
     * @param b the second matrix - M: p x q.
     * @param res the result: [a] (x) [b] - M: n*p x m*q.
     */
    void kroneckerProductMatrix(matrix *a, matrix *b, matrix *res);


//******************************************************************************************************************//


    //***************************//
    //  MATRIX UTILITY FUNCTION  //
    //***************************//


    /**
     * Swaps 2 rows of a matrix.
     *
     * @param a the matrix - M: n x m.
     * @param row1 the first row to be swapped.
     * @param row2 the second row to be swapped.
     * @param swap the swapped matrix.
     */
    void swapRowMatrix(matrix *a, int row1, int row2, matrix *swap);

    /**
     * Swaps 2 columns of a matrix.
     *
     * @param a the matrix - M: n x m.
     * @param col1 the first column to be swapped.
     * @param col2 the second column to be swapped.
     * @param swap the swapped matrix.
     */
    void swapColumnMatrix(matrix *a, int col1, int col2, matrix *swap);

    /**
     * Finds the maximum value in a matrix.
     *
     * @param a the matrix - M: n x m.
     * @param rowPos the row containing the position with the maximum value.
     * @param colPos the column containing the position with the maximum value.
     * @return the maximum value in the matrix.
     */
    double findMaxMatrix(matrix *a, int *rowPos, int *colPos);

    /**
     * Finds the minimum value in a matrix.
     *
     * @param a the matrix - M: n x m.
     * @param rowPos the row containing the position with the minimum value.
     * @param colPos the column containing the position with the minimum value.
     * @return the minimum value in the matrix.
     */
    double findMinMatrix(matrix *a, int *rowPos, int *colPos);

    /**
     * Finds the elements on the diagonal of a matrix.
     *
     * @param a the matrix - M: n x m.
     * @param numberOfElements the number of elements on the diagonal.
     * @return the list of elements on the diagonal of the matrix.
     */
    double *diagonalMatrix(matrix *a, int *numberOfElements);

    /**
     * Finds the pivots in a matrix.
     *
     * @param a the matrix - M: n x m.
     * @param pivotsNumber the number of pivots.
     * @return the list of pivots.
     */
    double *pivot(matrix *a, int *pivotsNumber);

    /**
     * Decomposition of a matrix using Lower-Upper Decomposition - [A]=[L]*[U].
     *
     * @param a the matrix - M: n x n.
     * @param l the lower triangular matrix - M: n x n.
     * @param u the upper triangular matrix - M: n x n.
     */
    void luDecomposition(matrix *a, matrix *l, matrix *u);

#endif