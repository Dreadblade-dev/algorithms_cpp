#include "../fibonacci_number.h"
#include <gtest/gtest.h>

namespace FibonacciNumberTest
{
	TEST(FibonacciNumberTest, FibonacciZero)
	{
		EXPECT_EQ(fibonacciNumber(0), 0);
	}

	TEST(FibonacciNumberTest, FibonacciFirst)
	{
		EXPECT_EQ(fibonacciNumber(1), 1);
	}

	TEST(FibonacciNumberTest, FibonacciNth)
	{
		EXPECT_EQ(fibonacciNumber(2), 1);
		EXPECT_EQ(fibonacciNumber(3), 2);
		EXPECT_EQ(fibonacciNumber(4), 3);
		EXPECT_EQ(fibonacciNumber(13), 233);
		EXPECT_EQ(fibonacciNumber(17), 1597);
		EXPECT_EQ(fibonacciNumber(20), 6765);
	}
}