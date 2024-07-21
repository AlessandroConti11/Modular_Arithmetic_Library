cmake_minimum_required(VERSION 3.28)
project(modularArithmetic C)

set(CMAKE_C_STANDARD 11)

add_executable(ModularArithmetic main.c
        ModularArithmetic.h
        Modular_Arithmetic/OperationModulo.c
        Modular_Arithmetic/UtilityModulo.c
        Modular_Arithmetic/TestModulo.c
        Modular_Arithmetic/EquationModulo.c)
