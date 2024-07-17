#include <stdio.h>
#include <stdlib.h>

#include "ModularArithmetic.h"


int main() {
    int n, *factor = FermatFactorisation(111546435, &n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", factor[i]);
    }
    printf("\n");


    free(factor);
    return 0;
}