cmake_minimum_required(VERSION 3.22)
project(counting_stars)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ../bin/)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add_executable(counting_stars main.cpp src/StringInt/StringInt.cpp src/StringInt/StringInt.h src/Rational_number/Rational_number.cpp src/Rational_number/Rational_number.h src/exceptions/exceptions.h src/exceptions/IllegalSignException.h src/exceptions/IllegalDigitException.h src/exceptions/DivisionByZeroException.h)

add_executable(Rational_number_constructor_test src/StringInt/StringInt.cpp src/StringInt/StringInt.h src/Rational_number/Rational_number.cpp src/Rational_number/Rational_number.h src/Rational_number/tests/Rational_number_constructor_test.cpp)
target_link_libraries(Rational_number_constructor_test gtest_main)
add_test(NAME Rational_number_constructor_test COMMAND Rational_number_constructor_test)

add_executable(Rational_number_operators_test src/Rational_number/Rational_number.cpp src/Rational_number/Rational_number.h src/Rational_number/tests/Rational_number_operators_test.cpp src/StringInt/StringInt.cpp src/StringInt/StringInt.h)
target_link_libraries(Rational_number_operators_test gtest_main)
add_test(NAME Rational_number_operators_test COMMAND Rational_number_operators_test)


add_executable(StringInt_constructor_test src/StringInt/StringInt.cpp src/StringInt/StringInt.h src/StringInt/tests/StringInt_constructor_test.cpp src/exceptions/IllegalSignException.h)
target_link_libraries(StringInt_constructor_test gtest_main)
add_test(NAME StringInt_constructor_test COMMAND StringInt_constructor_test)

add_executable(StringInt_operators_test src/StringInt/StringInt.cpp src/StringInt/StringInt.h src/StringInt/tests/StringInt_operators_test.cpp src/exceptions/IllegalSignException.h)
target_link_libraries(StringInt_operators_test gtest_main)
add_test(NAME StringInt_operators_test COMMAND StringInt_operators_test)

add_executable(StringInt_cast_test src/StringInt/StringInt.cpp src/StringInt/StringInt.h src/StringInt/tests/StringInt_cast_test.cpp)
target_link_libraries(StringInt_cast_test gtest_main)
add_test(NAME StringInt_cast_test COMMAND StringInt_cast_test)

add_executable(Proxy_test src/Proxy/tests/Proxy_test.cpp src/Proxy/ValProxy.h)
target_link_libraries(Proxy_test gtest_main)
add_test(NAME Proxy_test COMMAND Proxy_test)

add_executable(Matrix_test src/Matrix/tests/Matrix_test.cpp src/Matrix/matrix.h)
target_link_libraries(Matrix_test gtest_main)
add_test(NAME Matrix_test COMMAND Matrix_test)