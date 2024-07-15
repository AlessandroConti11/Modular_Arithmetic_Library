// // #include <stdio.h>
// //
// // int main(void) {
// //     printf("Hello, World!\n");
// //     return 0;
// // }
//
//
// #include <stdio.h>
// #include <math.h>
//
// // Funzione per controllare se un numero è un quadrato perfetto
// int isPerfectSquare(int n) {
//     int sqrtN = (int)sqrt(n);
//     return (sqrtN * sqrtN == n);
// }
//
// // Funzione per eseguire la fattorizzazione di Fermat
// void fermatFactorization(int N) {
//     if (N % 2 == 0) {
//         printf("Il numero non è dispari.\n");
//         return;
//     }
//
//     int x = (int)ceil(sqrt(N));
//     int x2 = (int)ceil(sqrt(2*N));
//     int y2 = x * x - N;
//     int y = 0;
//     printf("x = %d\n", x);
//     printf("y = %d\n", y2);
//
//
//     while (!isPerfectSquare(y2)) {
//         x++;
//         y2 = x * x - N;
//         printf("x = %d\n", x);
//         printf("y = %d\n", y2);
//     }
//
//     y = (int)sqrt(y2);
//
//     int factor1 = x - y;
//     int factor2 = x + y;
//
//     printf("I fattori di %d sono %d e %d.\n", N, factor1, factor2);
// }
//
// int main() {
//     int N;
//     printf("Inserisci un numero dispari: ");
//     scanf("%d", &N);
//
//     fermatFactorization(N);
//
//     return 0;
// }
