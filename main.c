#include <stdio.h>
#include <stdlib.h>

#include "ModularArithmetic.h"
#include "Modular_Arithmetic/Utility/Matrix.h"


int main() {
    int n, *factor = FermatFactorisation(99, &n), x, y, res;
    matrix *a = NULL;
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", factor[i]);
    // }
    // printf("\n");
    //
    // factor = factorisation(198, &n);
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", factor[i]);
    // }
    // printf("\n");
    //
    //
    // printf("euler %d\n", EulerFunction(99));
    //
    // printf("Th %d\n", chineseRemainderTheorem(3,
    //     3,4,
    //     2,3,
    //     4,5));
    //
    // res = extendedGCD(2, 6, &x, &y);
    // printf("gcd: %d, %d - %d\n", res, x, y);
    //
    // printf("divisor %d\n", isDivisor(2,4));
    //
    // diophantineEquation(122, &x, 184, &y, 42);
    // printf("sol diophantine: %d, %d\n", x, y);
    //
    // free(factor);
    // factor = EratosthenesSieve(10, &x);
    // printf("prime number: ");
    // for (int i = 0; i < x; ++i) {
    //     printf("%d ", factor[i]);
    // }
    // printf("\n");
    //
    // printf("the n-th prime number %d\n", nthPrimeNumber(10));
    //
    // printf("the next prime number %d\n", nextPrimeNumber(51));
    //
    // printf("is a square number %d\n", isSquareNumber(5, 11));
    //
    // printf("is primitive root %d\n", isPrimitiveRoot(2,13));
    //
    // factor = primitiveRoots(7, &n);
    // printf("primitive roots: ");
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", factor[i]);
    // }
    // printf("\n");
    // for (int i = 1; i < 7; ++i) {
    //     printf("%d ", power(3, i, 7));
    // }
    // printf("\n");

    // factor = TonelliShanksAlgorithm(5, 41);
    // printf("%d, %d\n", factor[0], factor[1]);

    // printf("QR: ");
    // factor = quadraticResiduals(13, &n);
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", factor[i]);
    // }
    // printf("\n");
    //
    // printf("SR: ");
    // factor = squareRoot(9, 13, &n);
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", factor[i]);
    // }
    // printf("\n");

    // printf("%d\n", power(3, 5, 17));
    // printf("%d\n", discreteLogarithm(3, 5, 17));

    // printf("%d\n", LegendreSymbol(3, 5));
    // printf("%d\n", JacobiSymbol(3, 3));

    a = createMatrix(2, 2);
    initializeMatrix(a, 1.0, 1.0,
                        1.00005, 1.0);
    printf("%d\n", isIntegerMatrix(a));

    free(factor);
    return 0;
}