#include "../matrix.h"
#include "gtest/gtest.h"

#include <iostream>

class Matrix_test : testing::Test
{
};

TEST(Matrix_test, test_all)
{
    Matrix<double> m(100, 100, 1e-6);

    m(3, 15) = 30.0;
    m.addValues({
        {{6, 6}, 12.4},
        {{54, 34}, 45.45},
    });
    ASSERT_EQ(m(3, 15), 30.0);
    ASSERT_EQ(m(6, 6), 12.4);
    ASSERT_EQ(m(54, 34), 45.45);

    auto v = m + m;
    ASSERT_EQ(v(3, 15), 2.0 * m(3, 15));

    Matrix<double> m1(3, 2);
    m1.addValues({
        {{2, 2}, 4.0},
        {{3, 1}, 1.0},
    });
    Matrix<double> m2(2, 3);
    m2.addValues({
        {{1, 1}, 3.0},
        {{1, 2}, 5.0},
        {{2, 3}, 3.0},
    });
    auto m3 = m1 * m2;
    Matrix<double> m4(3, 3);
    m4.addValues({
        {{2, 3}, 12.0},
        {{3, 1}, 3.0},
        {{3, 2}, 5.0},
    });
    ASSERT_EQ(m3, m4);
    Matrix<double> m5(3, 3);
    m5.addValues({
        {{3, 2}, 12.0},
        {{1, 3}, 3.0},
        {{2, 3}, 5.0},
    });
    m4.transpose();
    ASSERT_EQ(m4, m5);
    // std::cout << m4;
}