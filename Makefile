CC=g++
FLAGS=-std=c++2a -Wall -pedantic -Wextra -Werror
TEST_LIBS=-lgtest_main -lgtest -lpthread

EXCEPTIONS=./src/exceptions/*

.PHONY: test clean

all: test clean

Vector.o: ./src/Vector/Vector.cpp ./src/Vector/Vector.h
	$(CC) $(FLAGS) ./src/Vector/Vector.cpp -c

Rational_number.o: ./src/Rational_number/Rational_number.cpp ./src/Rational_number/Rational_number.h
	$(CC) $(FLAGS) ./src/Rational_number/Rational_number.cpp -c

StringInt.o: ./src/StringInt/StringInt.cpp ./src/StringInt/StringInt.h
	$(CC) $(FLAGS) ./src/StringInt/StringInt.cpp -c

test_rational_constructor: Rational_number.o ./src/Rational_number/tests/Rational_number_constructor_test.cpp StringInt.o
	$(CC) $(FLAGS) Rational_number.o StringInt.o ./src/Rational_number/tests/Rational_number_constructor_test.cpp -o test_rational_constructor $(TEST_LIBS)

test_rational_operators: Rational_number.o ./src/Rational_number/tests/Rational_number_operators_test.cpp StringInt.o
	$(CC) $(FLAGS) Rational_number.o StringInt.o ./src/Rational_number/tests/Rational_number_operators_test.cpp -o test_rational_operators $(TEST_LIBS)

test_rational: test_rational_constructor test_rational_operators

test_vector_constructor: Vector.o Rational_number.o ./src/Vector/tests/Vector_constructor_test.cpp StringInt.o
	$(CC) $(FLAGS) Vector.o Rational_number.o StringInt.o ./src/Vector/tests/Vector_constructor_test.cpp -o test_vector_constructor $(TEST_LIBS)

test_vector_operators: Vector.o Rational_number.o ./src/Vector/tests/Vector_operators_test.cpp StringInt.o
	$(CC) $(FLAGS) Vector.o Rational_number.o StringInt.o ./src/Vector/tests/Vector_operators_test.cpp -o test_vector_operators $(TEST_LIBS)

test: test_rational_constructor test_rational_operators test_vector_constructor test_vector_operators
	./test_rational_constructor
	./test_rational_operators
	./test_vector_constructor
	./test_vector_operators

clean:
	rm -f *.o test_*