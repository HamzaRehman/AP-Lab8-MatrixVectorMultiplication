CXX = gcc
OUTPUT_FLAGS = -o
COMPILE_FLAGS = -c
LIBS = -pthread
OBJS = Vector.o Matrix.o Main.o
PHONY_FILES = *.o

matrix : ${OBJS}
	${CXX} ${LIBS} ${OUTPUT_FLAGS} $@ ${OBJS}
	make clean

Vector.o : Vector.c
	${CXX} ${COMPILE_FLAGS} Vector.c

Matrix.o : Matrix.c
	${CXX} ${COMPILE_FLAGS} Matrix.c

Main.o : Main.c
	${CXX} ${COMPILE_FLAGS} Main.c

clean :
	rm -rf ${PHONY_FILES}
