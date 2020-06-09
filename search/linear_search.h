/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 *
 * In computer science, a linear search or sequential search is a method for
 * finding an element within a list. It sequentially checks each element
 * of the list until a match is found or the whole list has been searched
 *
 * Time complexity:
 * ┌────────────────┬────────────────┬───────────────┐
 * │   Worst-case   │  Average-case  │   Best-case   │
 * ├────────────────┼────────────────┼───────────────┤
 * │      O(n)      │      O(n)      │     O(1)      │
 * └────────────────┴────────────────┴───────────────┘
 *
 * Source: https://en.wikipedia.org/wiki/Linear_search
 */

#pragma once
#include <cstdint>

template <typename T_ARRAY, typename T_SIZE, typename T_KEY>
int64_t linearSearch(const T_ARRAY* array, const T_SIZE& size, const T_KEY& key)
{
	for (int count = 0; count < size; ++count)
		if (array[count] == key)
			return count;

	return -1;
}