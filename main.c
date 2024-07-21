#include <stdio.h>
#include <stdlib.h>

#include "ModularArithmetic.h"


int main() {
    int n, *factor = FermatFactorisation(99, &n), x, y, res;
    for (int i = 0; i < n; ++i) {
        printf("%d ", factor[i]);
    }
    printf("\n");

    printf("euler %f\n", EulerFunction(99));

    printf("Th %d\n", chineseRemainderTheorem(3,
        3,4,
        2,3,
        4,5));

    res = extendedGCD(2, 6, &x, &y);
    printf("gcd: %d, %d - %d\n", res, x, y);

    printf("divisor %d\n", isDivisor(2,4));

    diophantineEquation(122, &x, 184, &y, 42);
    printf("sol diophantine: %d, %d\n", x, y);

    free(factor);
    factor = EratosthenesSieve(5000, &x);
    printf("prime number: ");
    for (int i = 0; i < x; ++i) {
        printf("%d\n ", factor[i]);
    }
    printf("\n");

    printf("the n-th prime number %d\n", nthPrimeNumber(10));

    free(factor);
    return 0;
}