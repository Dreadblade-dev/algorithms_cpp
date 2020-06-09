/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 *
 * In computer science, binary search, also known as half-interval search,
 * logarithmic search, or binary chop, is a search algorithm that finds
 * the position of a target value within a sorted array.
 *
 * Time complexity:
 * ┌────────────────┬────────────────┬───────────────┐
 * │   Worst-case   │  Average-case  │   Best-case   │
 * ├────────────────┼────────────────┼───────────────┤
 * │    O(log n)    │    O(log n)    │     O(1)      │
 * └────────────────┴────────────────┴───────────────┘
 * 
 * Source: https://en.wikipedia.org/wiki/Binary_search_algorithm
 */

#pragma once
#include <cstdint>

template <typename T_SORTED_ARRAY, typename T_KEY, typename T_SIZE>
int64_t binarySearch(const T_SORTED_ARRAY* array, const T_KEY key, 
	const T_SIZE left, const T_SIZE right) 
{
	T_SIZE middle = (left + right) / 2;


	if (array[middle] == key)
		return middle;
	if (array[middle] > key)
		return binarySearch(array, key, left, middle);
	if (array[middle] < key)
		return binarySearch(array, key, middle, right);
	
	return -1;
}