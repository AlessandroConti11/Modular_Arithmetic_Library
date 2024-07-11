cmake_minimum_required(VERSION 3.28)
project(modularArithmetic C)

set(CMAKE_C_STANDARD 11)

add_executable(modularArithmetic main.c
        modularArithmetic.h
        Modular_Arithmetic/Operation.c
        Modular_Arithmetic/UtilityModulo.c)
