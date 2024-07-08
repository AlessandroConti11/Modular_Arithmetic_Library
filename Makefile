#To change the value of a variable: make VARIABLE="..."

#Compilation flags
CFLAGS = -Wall -Werror -std=gnu11 -O2


#Source files
SOURCE = ${SRC} ${MOD}
#source code
SRC = main.c
#ModularArithmetic.h
MOD = \
		Modular_Arithmetic/


#Output
OUTPUT = output


compile:
	gcc ${CFLAGS} ${SOURCE} -o ${OUTPUT}

asan:
	gcc ${SOURCE} -o ${OUTPUT} -fsanitize=address

clean:
	rm -ri ${OUTPUT}