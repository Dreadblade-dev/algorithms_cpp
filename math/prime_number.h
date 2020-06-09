/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 *
 * A prime number (or a prime) is a natural number greater than 1 that
 * is not a product of two smaller natural numbers. A natural number
 * greater than 1 that is not prime is called a composite number.
 * 
 * For example, 5 is prime because the only ways of writing it as a
 * product, 1 × 5 or 5 × 1, involve 5 itself.
 *
 * Source: https://en.wikipedia.org/wiki/Prime_number
 */

#pragma once
#include <cstdint>

inline bool isPrimeNumber(int64_t n)
{
	if (n == 1)
		return false;
	
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;	
}