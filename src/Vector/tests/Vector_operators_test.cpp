#include "gtest/gtest.h"
#include "./../../Rational_number/Rational_number.h"
#include "./../vector.h"

class Vector_operators_test : public testing::Test
{
};

TEST(Vector_operators_test, unary_int_minus)
{
    int value = 10;
    size_t size = 3;
    Vector<int> int_vector(size, value);
    ASSERT_EQ(int_vector.size(), size) << "Size of vector should be " << size << ", got " << int_vector.size();
    Vector<int> minus_vector = -int_vector;
    for (size_t i = 1; i <= minus_vector.size(); i++)
    {
        ASSERT_EQ(minus_vector(i), -value) << "Vector element at " << i << " should be " << -value << ", got " << minus_vector(i);
    }
}

TEST(Vector_operators_test, binary_int_minus)
{
    int value = 10;
    size_t size = 3;
    Vector<int> int_vector(size, value);
    ASSERT_EQ(int_vector.size(), size) << "Size of vector should be " << size << ", got " << int_vector.size();

    int another_value = 20;
    size = 3;
    Vector<int> another_int_vector(size, another_value);
    ASSERT_EQ(another_int_vector.size(), size) << "Size of vector should be " << size << ", got " << another_int_vector.size();

    Vector<int> binary_minus_vector = int_vector - another_int_vector;
    ASSERT_EQ(binary_minus_vector.size(), size) << "Size of vector should be " << size << ", got " << binary_minus_vector.size();
    for (size_t i = 1; i <= binary_minus_vector.size(); i++)
    {
        ASSERT_EQ(value - another_value, binary_minus_vector(i)) << "Vector element at " << i << " should be " << -value << ", got " << binary_minus_vector(i);
    }
}

TEST(Vector_operators_test, binary_int_plus)
{
    int value = 10;
    size_t size = 3;
    Vector<int> int_vector(size, value);
    ASSERT_EQ(int_vector.size(), size) << "Size of vector should be " << size << ", got " << int_vector.size();

    int another_value = 20;
    size = 3;
    Vector<int> another_int_vector(size, another_value);
    ASSERT_EQ(another_int_vector.size(), size) << "Size of vector should be " << size << ", got " << another_int_vector.size();

    Vector<int> binary_plus_vector = int_vector + another_int_vector;
    ASSERT_EQ(binary_plus_vector.size(), size) << "Size of vector should be " << size << ", got " << binary_plus_vector.size();
    for (size_t i = 1; i <= binary_plus_vector.size(); i++)
    {
        ASSERT_EQ(value + another_value, binary_plus_vector(i)) << "Vector element at " << i << " should be " << -value << ", got " << binary_plus_vector(i);
    }
}

TEST(Vector_operators_test, binary_int_multiplication)
{
    int value = 10;
    size_t size = 3;
    Vector<int> int_vector(size, value);
    ASSERT_EQ(int_vector.size(), size) << "Size of vector should be " << size << ", got " << int_vector.size();

    int another_value = 20;

    Vector<int> binary_mult_vector = int_vector * another_value;
    ASSERT_EQ(binary_mult_vector.size(), size) << "Size of vector should be " << size << ", got " << binary_mult_vector.size();
    for (size_t i = 1; i <= binary_mult_vector.size(); i++)
    {
        ASSERT_EQ(value * another_value, binary_mult_vector(i)) << "Vector element at " << i << " should be " << -value << ", got " << binary_mult_vector(i);
    }
}

TEST(Vector_operators_test, binary_int_map_multiplication)
{
    std::map<size_t, int> arr{{1, 10}, {3, 15}, {5, 20}};
    Vector<int> map_int_vector(arr);
    ASSERT_EQ(map_int_vector.size(), 3) << "Size of vector should be 3, got " << map_int_vector.size();

    int another_value = 20;

    Vector<int> binary_mult_vector = map_int_vector * another_value;
    ASSERT_EQ(binary_mult_vector.size(), map_int_vector.size()) << "Size of vector should be " << map_int_vector.size() << ", got " << binary_mult_vector.size();

    std::map<size_t, int>::iterator it;
    for (it = binary_mult_vector.begin(); it != binary_mult_vector.end(); it++)
    {
        ASSERT_EQ(arr.at(it->first) * another_value, binary_mult_vector(it->first)) << "Vector element at " << it->first << " should be " << arr.at(it->first) * another_value << ", got " << binary_mult_vector(it->first);
    }
}

// example of usage:

// int main(){
// std::cout << "vec" << std::endl;
// Vector<int> vec(3, 228);
// std::string out = vec.to_string();
// std::cout << out << std::endl;

// std::cout << "vec(2) = 13" << std::endl;
// vec(2) = 13;
// out = vec.to_string();
// std::cout << out << std::endl;

// std::cout << "vec2" << std::endl;
// Vector<int> vec2(3, 112);
// out = vec2.to_string();
// std::cout << out << std::endl;

// std::cout << "vec += vec2" << std::endl;
// vec += vec2;
// out = vec.to_string();
// std::cout << out << std::endl;

// std::cout << "res = vec + vec2" << std::endl;
// Vector<int> res = vec + vec2;
// out = res.to_string();
// std::cout << out << std::endl;

// std::cout << "res2 = -res" << std::endl;
// Vector<int> res2 = -res;
// out = res2.to_string();
// std::cout << out << std::endl;

// std::cout << "res3 = res2 - res2" << std::endl;
// Vector<int> res3 = res2 - res2;
// out = res3.to_string();
// std::cout << out << std::endl;

// std::cout << "res4 = vec * 1.5" << std::endl;
// Vector<int> res4 = vec * 1.5;
// out = res4.to_string();
// std::cout << out << std::endl;

// Vector<double> d_vec(3, 33.33);
// std::cout << "res5 = d_vec / 1.33" << std::endl;
// Vector<double> res5 = d_vec / 1.33;
// out = res5.to_string();
// std::cout << out << std::endl;
// }
