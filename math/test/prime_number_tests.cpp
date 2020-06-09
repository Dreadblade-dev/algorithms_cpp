#include "../prime_number.h"
#include <gtest/gtest.h>

namespace PrimeNumberTest
{
	TEST(PrimeNumberTest, PrimeNumberMainTest)
	{
		EXPECT_FALSE(isPrimeNumber(1));
		EXPECT_TRUE(isPrimeNumber(2));
		EXPECT_TRUE(isPrimeNumber(3));
		EXPECT_FALSE(isPrimeNumber(4));
		EXPECT_TRUE(isPrimeNumber(5));
		EXPECT_TRUE(isPrimeNumber(7));
		EXPECT_FALSE(isPrimeNumber(9));
		EXPECT_TRUE(isPrimeNumber(11));
		EXPECT_TRUE(isPrimeNumber(13));
		EXPECT_FALSE(isPrimeNumber(16));
		EXPECT_TRUE(isPrimeNumber(17));
		EXPECT_FALSE(isPrimeNumber(24));
		EXPECT_TRUE(isPrimeNumber(47));
		EXPECT_FALSE(isPrimeNumber(64));
		EXPECT_TRUE(isPrimeNumber(97));
	}
}