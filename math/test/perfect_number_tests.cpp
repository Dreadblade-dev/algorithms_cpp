#include "../perfect_number.h"
#include <gtest/gtest.h>

namespace PerfectNumberTest
{
	TEST(PerfectNumberTest, PerfectNumberMainTest)
	{
		for (int16_t i = 1; i < 6; ++i)
			EXPECT_FALSE(isPerfectNumber(i));
		EXPECT_TRUE(isPerfectNumber(6));
		for (int16_t i = 7; i < 28; ++i)
			EXPECT_FALSE(isPerfectNumber(i));
		EXPECT_TRUE(isPerfectNumber(28));
		EXPECT_TRUE(isPerfectNumber(496));
		EXPECT_TRUE(isPerfectNumber(8128));
		EXPECT_TRUE(isPerfectNumber(33550336));
	}
}