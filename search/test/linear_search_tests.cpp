#include "../linear_search.h"
#include <gtest/gtest.h>

namespace LinearSearchTest
{
	TEST(LinearSearchTest, LinearSearchMainTest)
	{
		auto* array = new int64_t[33];
		for (int64_t i = 0; i <= 32; ++i)
			array[i] = i * i * i * i;

		// 0^4 = 0
		EXPECT_EQ(linearSearch(array, 33, 0), 0);

		// 16^4 = 65536
		EXPECT_EQ(linearSearch(array, 33, 65536), 16);

		// 32^4 = 1048576
		EXPECT_EQ(linearSearch(array, 33, 1048576), 32); 
	}
}