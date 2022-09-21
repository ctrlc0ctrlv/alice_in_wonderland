CC=g++
FLAGS=-std=c++2a -Wall -pedantic -Wextra -Werror
TEST_LIBS=-lgtest_main -lgtest -lpthread

EXCEPTIONS=./src/exceptions/*

.PHONY: test clean build

all: build

Rational_number.o: ./src/Rational_number/Rational_number.cpp ./src/Rational_number/Rational_number.h
	$(CC) $(FLAGS) ./src/Rational_number/Rational_number.cpp -c

StringInt.o: ./src/StringInt/StringInt.cpp ./src/StringInt/StringInt.h
	$(CC) $(FLAGS) ./src/StringInt/StringInt.cpp -c

test_rational_constructor: Rational_number.o ./src/Rational_number/tests/Rational_number_constructor_test.cpp StringInt.o
	$(CC) $(FLAGS) Rational_number.o StringInt.o ./src/Rational_number/tests/Rational_number_constructor_test.cpp -o test_rational_constructor $(TEST_LIBS)

test_rational_operators: Rational_number.o ./src/Rational_number/tests/Rational_number_operators_test.cpp StringInt.o
	$(CC) $(FLAGS) Rational_number.o StringInt.o ./src/Rational_number/tests/Rational_number_operators_test.cpp -o test_rational_operators $(TEST_LIBS)

test_vector_constructor: ./src/Vector/vector.h ./src/TypeName/TypeName.h Rational_number.o ./src/Vector/tests/Vector_constructor_test.cpp StringInt.o
	$(CC) $(FLAGS) ./src/Vector/vector.h ./src/TypeName/TypeName.h Rational_number.o StringInt.o ./src/Vector/tests/Vector_constructor_test.cpp -o test_vector_constructor $(TEST_LIBS)

test_vector_operators: ./src/Vector/vector.h ./src/TypeName/TypeName.h Rational_number.o ./src/Vector/tests/Vector_operators_test.cpp StringInt.o
	$(CC) $(FLAGS) ./src/Vector/vector.h ./src/TypeName/TypeName.h Rational_number.o StringInt.o ./src/Vector/tests/Vector_operators_test.cpp -o test_vector_operators $(TEST_LIBS)

test_matrix: ./src/Matrix/matrix.h ./src/Matrix/tests/Matrix_test.cpp
	$(CC) $(FLAGS) ./src/Matrix/matrix.h ./src/Matrix/tests/Matrix_test.cpp -o test_matrix $(TEST_LIBS)

test_proxy: ./src/Proxy/ValProxy.h ./src/Proxy/tests/Proxy_test.cpp
	$(CC) $(FLAGS) ./src/Proxy/ValProxy.h ./src/Proxy/tests/Proxy_test.cpp -o test_proxy $(TEST_LIBS)

build: Rational_number.o StringInt.o

test: test_rational_constructor test_rational_operators test_vector_constructor test_vector_operators test_matrix test_proxy
	./test_rational_constructor
	./test_rational_operators
	./test_vector_constructor
	./test_vector_operators
	./test_matrix
	./test_proxy

clean:
	rm -f *.o test_* *.out