#Robert O’Neill – Assignment 5 - makefile
#format is target-name: target dependencies
#{-tab-}actions
# MACRO definitions
CC  = gcc
CFLAG = -std=c99

# All Targets
all: operation

#Executable operation depends on the files operation.o operation_functions.o
operation: operation.o operation_functions.o
	$(CC) $(CFLAG) -o operation operation.o operation_functions.o

# operation.o depends on the source and header files
operation.o: operation.c operation_functions.h
	$(CC) $(CFLAG) -c operation.c

# operation_functions.o depends on the source and header files
operation_functions.o: operation_functions.c operation_functions.h
	$(CC) $(CFLAG) -c operation_functions.c

# test cases
test: operation
	./operation 1 2 3 4
	./operation 5 0 7 0
	./operation 0 3 0 4
	./operation 6 0 0 3
	./operation 0 5 6 0
	./operation 0 0 5 3
	./operation 3 5 0 0
	./operation 1 2 3 5 6

#Clean the build directory
clean:
	rm -f *.o operation
