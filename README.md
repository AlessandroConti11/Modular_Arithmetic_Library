# Modular_Arithmetic_Library


Author: Alessandro Conti - [AlessandroConti11](https://github.com/AlessandroConti11)

License: [MIT license](LICENSE).


Tags: `#C`, `#Baby-Step_Giant-Step`, `#Chinese_Reminder_Theorem`, `#discrete_logarithm`, `#Extended_Euclidean_Algorithm`, `#factorisation`, `#Fermat_Pseudoprime`, `#Jacobi_Symbol`, `#Legendre_Symbol`, `#linear_diophantine_equation`, `#modular_arithmetic`, `#modular_matrix`, `#modular_square_root`, `#prime_number`, `#Tonelli-Shanks`.


## Specification

The project aims to create a library that contains all useful functions for modular arithmetic.
<br>
<br>

| **Operation**                                                                                | **Function**                                                                                                    | **Description** | **Order of the Matrices** | **Example of Mathematical Representation** |
|----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------|-----------------|---------------------------|--------------------------------------------|
| compute the sum modulo m                                                                     | long long int sum(long long int a, long long int b, long long int m)                                            |                 |                           |                                            |
| compute the difference modulo m                                                              | long long int sub(long long int a, long long int b, long long int m)                                            |                 |                           |                                            |
| compute the product modulo m                                                                 | long long int product(long long int a, long long int b, long long int m)                                        |                 |                           |                                            |
| compute the division modulo m                                                                | long long int division(long long int a, long long int b, long long int m)                                       |                 |                           |                                            |
| compute the power modulo m                                                                   | long long int power(long long int a, long long int exp, long long int m)                                        |                 |                           |                                            |
| compute the square root modulo a prime number                                                | long long int *TonelliShanksAlgorithm(long long int a, long long int p)                                         |                 |                           |                                            |
| compute the square root modulo m                                                             | long long int *squareRoot(long long int a, long long int n, long long int *numberOfSquareRoots)                 |                 |                           |                                            |
| compute the discrete logarithm modulo m                                                      | long long int discreteLogarithm(long long int base, long long int b, long long int n)                           |                 |                           |                                            |
| compute the solution of a system of modular linear equation - Chinese Reminder Theorem       | long long int chineseReminderTheorem(long long int numberOfEquation, long long int *a, long long int *m)        |                 |                           |                                            |
| compute the solution of a linear diophantine equation                                        | void diophantineEquation(long long int a, long long int *x, long long int b, long long int *y, long long int c) |                 |                           |                                            |
| check if two numbers are congruent modulo m                                                  | long long int areCongruent(long long int a, long long int b, long long int m)                                   |                 |                           |                                            |
| check if two numbers are coprime                                                             | long long int areCoPrime(long long int a, long long int n)                                                      |                 |                           |                                            |
| check if the first number is a divisor of the second number                                  | long long int isDivisor(long long int n, long long int m)                                                       |                 |                           |                                            |
| check if a number is Fermat's Pseudoprime to a                                               | long long int isFermatPseudoPrime(long long int a, long long int n)                                             |                 |                           |                                            |
| check if a number is a prime number                                                          | long long int isPrime(long long int n)                                                                          |                 |                           |                                            |
| check if a number admits the square root modulo n                                            | long long int isSquareNumber(long long int a, long long int n)                                                  |                 |                           |                                            |
| check if a number is a primitive root modulo n                                               | long long int isPrimitiveRoot(long long int a, long long int n)                                                 |                 |                           |                                            |
| check if a number is a perfect square                                                        | long long int isPerfectSquare(long long int n)                                                                  |                 |                           |                                            |
| compute the Greatest Common Divisor                                                          | long long int gcd(long long int n, long long int m)                                                             |                 |                           |                                            |
| compute the Greatest Common Divisor using the Extended Euclidean algorithm                   | long long int extendedGCD(long long int n, long long int m, long long int *x, long long int *y)                 |                 |                           |                                            |
| compute the modulus of two integer                                                           | long long int mod(long long int n, long long int m)                                                             |                 |                           |                                            |
| compute a number congruent with the one given                                                | long long int congruentNumber(long long int a, long long int m)                                                 |                 |                           |                                            |
| compute the modular reduction                                                                | long long int modularReduction(long long int n, long long int m)                                                |                 |                           |                                            |
| compute the modular inversion                                                                | long long int modularInverse(long long int n, long long int m)                                                  |                 |                           |                                            |
| factorize a number by splitting it into two of its dividends - Fermat's Factorization Method | long long int *realFermatFactorisation(long long int n)                                                         |                 |                           |                                            |
| factorize a number by splitting it into all of its dividends                                 | long long int *factorisation(long long int n, long long int *factors)                                           |                 |                           |                                            |
| compute the value of Euler Function for the given number                                     | long long int EulerFunction(long long int n)                                                                    |                 |                           |                                            |
| compute the list of prime numbers up to the n-th                                             | long long int *primeNumberList(long long int n, long long int *primeSize)                                       |                 |                           |                                            |
| search for the n-th prime number                                                             | long long int nthPrimeNumber(long long int n)                                                                   |                 |                           |                                            |
| found the prime number following a given number                                              | long long int nextPrimeNumber(long long int n)                                                                  |                 |                           |                                            |
| compute the list of primitive roots modulo n                                                 | long long int *primitiveRoots(long long int n, long long int *primitiveRootsSize)                               |                 |                           |                                            |
| compute the list of quadratic residual modulo n                                              | long long int *quadraticResiduals(long long int n, long long int *quadraticResidualSize)                        |                 |                           |                                            |
| compute the Legendre Symbol                                                                  | long long int LegendreSymbol(long long int a, long long int p)                                                  |                 |                           |                                            |
| compute the Jacobi Symbol                                                                    | long long int JacobiSymbol(long long int a, long long int n)                                                    |                 |                           |                                            |
| print matrix modulo n                                                                        | void printMatrixModulo(matrix *a, long long int n)                                                              |                 |                           |                                            |
| check if a matrix has all integer elements                                                   | long long int isIntegerMatrix(matrix *a)                                                                        |                 |                           |                                            |
| compute the matrix modulo n                                                                  | void modularMatrix(matrix *a, matrix *modMatrix, long long int n)                                               |                 |                           |                                            |
| compute the matrix inversion modulo n                                                        | void inverseMatrixModulo(matrix *a, matrix *inv, long long int n)                                               |                 |                           |                                            |
| compute the sum of matrices modulo n                                                         | void sumMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n)                                        |                 |                           |                                            |
| compute the difference of matrices modulo n                                                  | void subMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n)                                        |                 |                           |                                            |
| compute the scalar product of matrix modulo n                                                | void scalarProductModulo(long long int scalar, matrix *a, matrix *res, long long int n)                         |                 |                           |                                            |
| compute the product of matrices modulo n                                                     | void productMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n)                                    |                 |                           |                                            |
| compute the power elevation of a matrix modulo n                                             | void powerMatrixModulo(matrix *a, long long int k, matrix *res, long long int n)                                |                 |                           |                                            |
| compute the Kronecker product of matrices modulo n                                           | void kroneckerProductMatrixModulo(matrix *a, matrix *b, matrix *res, long long int n)                           |                 |                           |                                            |


## How to run

0. install gcc
    ```bash
    sudo apt-get install gcc 
    ```
1. compile the project
    ```bash
    gcc -Wall -Werror -O2 -g3 main.c -o EXECUTABLE 
    ```
2. run the project
    ```bash
    ./EXECUTABLE
    ```


<br>

The Makefile in the repository can also be used to compile the code.
- this option allows you to compile with the following tags: *-Wall -Werror -O2 -g3*
   ```bash
   make compile
   ```
- if you want to specify different tags, you can set them
   ```bash
   make compile CFLAGS=YOUR_FLAGS
   ```
- if you want to use Address SANitizer
   ```bash
   make asan
   ```
- if you want to delete some file - default is the executable file
   ```bash
   make clean
   ```


## Contribute

- If you find a security vulnerability, do NOT open an issue. Email [Alessandro Conti](mailto:ale.conti.1101@gmail.com) instead.
- If you find a bug or error or want to add some other function that is not implemented yet
    1. **FORK** the repo
    2. **CLONE** the project to your own machine
    3. **COMMIT** to your own branch
    4. **PUSH** your work back up to your fork
    5. submit a **PULL REQUEST** so that I can review your changes
  > NOTE: Be sure to merge the latest from "upstream" before making a pull request!

### Code Style

Each new function must be documented using the following style:
- *Short function description*: A brief description explaining what the function does.
- *@details*: A detailed section describing how the function works, explaining the algorithms and logic used.
- *@warning*: A section listing all the assumptions made by the function, such as the preconditions that the parameters must fulfil.
- *Blank line*: Add a blank line to separate the documentation sections.
- *@param*: A list of the parameters required by the function, each accompanied by a brief description of its role and type.
- *@return*: A description of what the function returns, including the data type.

Within the function, *each variable* must be commented out to explain its purpose.
In general, any additional comments that might improve understanding of the code are welcome. 😃
