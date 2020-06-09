#include "../binary_search.h"
#include <gtest/gtest.h>

namespace BinarySearchTest
{
	TEST(BinarySearchTest, BinarySearchMainTest)
	{
		auto* array = new int64_t[33];
		for (int64_t i = 0; i <= 32; ++i)
			array[i] = i * i * i * i;

		//0^4 = 0
		EXPECT_EQ(binarySearch(array, 0, 0, 33), 0);

		// 16^4 = 65536
		EXPECT_EQ(binarySearch(array, 65536, 0, 33), 16);

		// 32^4 = 1048576
		EXPECT_EQ(binarySearch(array, 1048576, 0, 33), 32);
	}
}