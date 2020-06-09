/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Factorial number recursive algorithm
 * 
 * In mathematics, the factorial of a positive integer n, denoted by n!,
 * is the product of all positive integers less than or equal to n:
 * 
 * n! = n × (n − 1) × (n − 2) × (n − 3) × ⋯ × 3 × 2 × 1
 *
 * Source: https://en.wikipedia.org/wiki/Factorial
 */

#pragma once
#include <cstdint>

inline int64_t factorial(int64_t n)
{
	if (n == 1)
		return 1;

	if (n == 0)
		return 1;
	
	n *= factorial(n - 1);

	return n;
}