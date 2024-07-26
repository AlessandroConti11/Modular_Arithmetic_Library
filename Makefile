#To change the value of a variable: make VARIABLE="..."

#Compilation flags
CFLAGS = -Wall -Werror -std=gnu11 -O2
ASANFLAGS = -fsanitize=address -lm


#Source files
SOURCE = ${SRC} ${MOD} ${MATRIX}

#source code
SRC = main.c

#ModularArithmetic.h
MOD = \
		Modular_Arithmetic/EquationModulo.c \
		Modular_Arithmetic/MatrixModulo.c \
		Modular_Arithmetic/OperationModulo.c \
		Modular_Arithmetic/TestModulo.c \
		Modular_Arithmetic/UtilityModulo.c \

#Matrix.h
MATRIX = \
		Modular_Arithmetic/Utility/Matrix/ManageMatrix.c \
		Modular_Arithmetic/Utility/Matrix/MatrixOperation.c \
		Modular_Arithmetic/Utility/Matrix/MatrixType.c \
		Modular_Arithmetic/Utility/Matrix/UtilityMatrix.c \


#Output
OUTPUT = output


compile:
	gcc ${CFLAGS} ${SOURCE} -o ${OUTPUT} -lm

asan:
	gcc ${ASANFLAGS} ${SOURCE} -o ${OUTPUT} -lm

clean:
	rm -ri ${OUTPUT}