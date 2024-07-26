cmake_minimum_required(VERSION 3.28)
project(modularArithmetic C)

set(CMAKE_C_STANDARD 11)

add_executable(ModularArithmetic main.c
        ModularArithmetic.h
        Modular_Arithmetic/OperationModulo.c
        Modular_Arithmetic/UtilityModulo.c
        Modular_Arithmetic/TestModulo.c
        Modular_Arithmetic/EquationModulo.c
        Modular_Arithmetic/MatrixModulo.c
        Modular_Arithmetic/Utility/Matrix.h
        Modular_Arithmetic/Utility/Matrix/ManageMatrix.c
        Modular_Arithmetic/Utility/Matrix/MatrixOperation.c
        Modular_Arithmetic/Utility/Matrix/MatrixType.c
        Modular_Arithmetic/Utility/Matrix/UtilityMatrix.c)
