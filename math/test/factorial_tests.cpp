#include "../factorial.h"
#include <gtest/gtest.h>

namespace FibonacciNumberTest
{
	TEST(FactorialTest, FactorialZero)
	{
		EXPECT_EQ(factorial(0), 1);
	}

	TEST(FactorialTest, FactorialNth)
	{
		EXPECT_EQ(factorial(1), 1);
		EXPECT_EQ(factorial(2), 2);
		EXPECT_EQ(factorial(3), 6);
		EXPECT_EQ(factorial(4), 24);
		EXPECT_EQ(factorial(5), 120);
		EXPECT_EQ(factorial(6), 720);
		EXPECT_EQ(factorial(7), 5040);
		EXPECT_EQ(factorial(8), 40320);
		EXPECT_EQ(factorial(12), 479001600);
	}
}