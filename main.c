#include <stdio.h>
#include <stdlib.h>

#include "ModularArithmetic.h"


int main() {
    int n, *factor = FermatFactorisation(99, &n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", factor[i]);
    }
    printf("\n");

    printf("euler %f\n", EulerFunction(99));

    printf("Th %d\n", chineseRemainderTheorem(3,
        3,4,
        2,3,
        4,5));


    free(factor);
    return 0;
}