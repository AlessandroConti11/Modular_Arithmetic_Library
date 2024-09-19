# Modular_Arithmetic_Library


Author: Alessandro Conti - [AlessandroConti11](https://github.com/AlessandroConti11)

License: [MIT license](LICENSE).


Tags: `#C`, `#Baby-Step_Giant-Step`, `#Chinese_Reminder_Theorem`, `#discrete_logarithm`, `#Extended_Euclidean_Algorithm`, `#factorisation`, `#Fermat_Pseudoprime`, `#Jacobi_Symbol`, `#Legendre_Symbol`, `#linear_diophantine_equation`, `#modular_arithmetic`, `#modular_matrix`, `#modular_square_root`, `#prime_number`, `#Tonelli-Shanks`.


## Specification

The project aims to create a library that contains all useful functions for modular arithmetic.
<br>
<br>

| **Operation** | **Function** | **Description** | **Order of the Matrices** | **Example of Mathematical Representation** |
|---------------|--------------|-----------------|---------------------------|--------------------------------------------|
|               |              |                 |                           |                                            |

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
