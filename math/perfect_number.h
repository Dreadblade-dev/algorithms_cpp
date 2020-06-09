/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * 
 * In number theory, a perfect number is a positive integer
 * that is equal to the sum of its positive divisors,
 * excluding the number itself.
 *
 * For instance, 6 has divisors 1, 2 and 3 (excluding itself),
 * and 1 + 2 + 3 = 6, so 6 is a perfect number.
 *
 * Perfect number form a sequence:
 * 6,
 * 28,
 * 496,
 * 8128,
 * 33 550 336,
 * 8 589 869 056,
 * 137 438 691 328,
 * 2 305 843 008 139 952, 128,
 * ...
 * 
 * 
 * Source: https://en.wikipedia.org/wiki/Perfect_number
 */

#pragma once
#include <cstdint>

inline bool isPerfectNumber(int64_t n)
{
	int64_t sumOfPositiveDivs(0);
	
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			sumOfPositiveDivs += i;

	if (sumOfPositiveDivs == n)
		return true;

	return false;
}