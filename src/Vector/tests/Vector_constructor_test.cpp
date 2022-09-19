#include "gtest/gtest.h"
#include "./../../Rational_number/Rational_number.h"
#include "./../vector.h"

class Vector_constructor_test : public testing::Test
{
};

TEST(Vector_constructor_test, null_is_null)
{
    Vector<int> null_vector;
    ASSERT_EQ(null_vector.size(), 0) << "Size of vector should be 0, got " << null_vector.size();
}

TEST(Vector_constructor_test, simple_int_check)
{
    Vector<int> int_vector(3);
    // even if we set size to 3, after removing zeros size should be 0
    ASSERT_EQ(int_vector.size(), 0) << "Size of vector should be 0, got " << int_vector.size();
}

TEST(Vector_constructor_test, default_int_check)
{
    Vector<int> default_int_vector(3, 14);
    ASSERT_EQ(default_int_vector.size(), 3) << "Size of vector should be 3, got " << default_int_vector.size();
    for (size_t i = 1; i <= 3; i++)
    {
        ASSERT_EQ(default_int_vector(i), 14) << "Vector element at " << i << " should be 14, got " << default_int_vector(i);
    }

    for (size_t i = 1; i <= 3; i++)
    {
        default_int_vector(i) = i;
        ASSERT_EQ(default_int_vector(i), i) << "Vector element at " << i << " should be " << i << ", got " << default_int_vector(i);
    }
}

TEST(Vector_constructor_test, default_float_check)
{
    Vector<float> default_float_vector(3, 0.3f);
    ASSERT_EQ(default_float_vector.size(), 3) << "Size of vector should be 3, got " << default_float_vector.size();
    for (size_t i = 1; i <= 3; i++)
    {
        ASSERT_FLOAT_EQ(default_float_vector(i), 0.3f) << "Vector element at " << i << " should be 0.3f, got " << default_float_vector(i);
    }

    for (size_t i = 1; i <= 3; i++)
    {
        float val = float(i) / 10.f;
        default_float_vector(i) = val;
        ASSERT_FLOAT_EQ(default_float_vector(i), val) << "Vector element at " << i << " should be " << val << ", got " << default_float_vector(i);
    }
}

TEST(Vector_constructor_test, default_double_check)
{
    Vector<double> default_double_vector(3, 0.3);
    ASSERT_EQ(default_double_vector.size(), 3) << "Size of vector should be 3, got " << default_double_vector.size();
    for (size_t i = 1; i <= 3; i++)
    {
        ASSERT_DOUBLE_EQ(default_double_vector(i), 0.3) << "Vector element at " << i << " should be 0.3, got " << default_double_vector(i);
    }

    for (size_t i = 1; i <= 3; i++)
    {
        double val = double(i) / 10.;
        default_double_vector(i) = val;
        ASSERT_DOUBLE_EQ(default_double_vector(i), val) << "Vector element at " << i << " should be " << val << ", got " << default_double_vector(i);
    }
}

TEST(Vector_constructor_test, default_file_check)
{
    Vector<int> file_vector("vector_test.txt");
    ASSERT_EQ(file_vector.size(), 5) << "Size of vector should be 5, got " << file_vector.size();
    ASSERT_EQ(file_vector(1), 14);
    ASSERT_EQ(file_vector(2), 38);
    ASSERT_EQ(file_vector(3), 17);
    ASSERT_EQ(file_vector(4), 10);
    ASSERT_EQ(file_vector(11), 1);
    file_vector.to_file("out_vector.txt");
}

// TODO: make double(Rational_number) work better

// TEST(Vector_constructor_test, default_rational_check)
// {
// Rational_number ratio(1, 10);
// Vector<Rational_number> default_rational_vector(3, ratio);
// // ASSERT_EQ(default_rational_vector.size(), 3) << "Size of vector should be 3, got " << default_rational_vector.size();
// for (size_t i = 1; i <= 3; i++)
// {
// // ASSERT_EQ(default_rational_vector(i), ratio) << "Vector element at " << i << " should be " << ratio << ", got " << default_rational_vector(i);
// }
//
// for (size_t i = 1; i <= 3; i++)
// {
// Rational_number val("-111/123");
// default_rational_vector(i) = val;
// // ASSERT_EQ(default_rational_vector(i), val) << "Vector element at " << i << " should be " << val << ", got " << default_rational_vector(i);
// }
// }

TEST(Vector_constructor_test, map_int_check)
{
    std::map<size_t, int> arr{{1, 10}, {3, 15}, {5, 20}};
    Vector<int> map_int_vector(arr);
    ASSERT_EQ(map_int_vector.size(), 3) << "Size of vector should be 3, got " << map_int_vector.size();

    for (size_t i = 1; i <= 5; i += 2)
    {
        ASSERT_EQ(map_int_vector(i), arr.at(i)) << "Vector element at " << i << " should be " << arr.at(i) << ", got " << map_int_vector(i);
    }
}

TEST(Vector_constructor_test, map_double_filter_check)
{
    std::map<size_t, double> arr{{1, 1.0}, {3, 1e-9}, {5, 1e-100}};
    Vector<double> map_double_vector(arr);

    ASSERT_EQ(map_double_vector.size(), 1) << "Size of vector should be 1, got " << map_double_vector.size();
    ASSERT_EQ(map_double_vector(1), 1.0);
}

TEST(Vector_constructor_test, map_int_filter_check)
{
    std::map<size_t, int> arr{{1, 0}, {3, 1}, {5, -1}};
    Vector<int> map_int_vector(arr);

    ASSERT_EQ(map_int_vector.size(), 2) << "Size of vector should be 2, got " << map_int_vector.size();
    ASSERT_EQ(map_int_vector(3), 1);
    ASSERT_EQ(map_int_vector(5), -1);
}