#include "../ValProxy.h"
#include "gtest/gtest.h"

class Proxy_test : public testing::Test
{
};

TEST(Proxy_test, all_tests)
{
    std::map<int, double> m = {{3, 7.5}};
    ValProxy v(m, 3, 1e-7);

    ASSERT_EQ(v, 7.5);
    v = 1e-8;
    ASSERT_EQ(v, 0.0);
    ASSERT_EQ(m.size(), 0);
    v = 4.0;
    ASSERT_EQ(v, 4.0);
    ASSERT_EQ(m.size(), 1);
}