/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Slow Fibonacci algorithm realization
 * Time complexity:
 * O(2^n)
 *
 * In mathematics, the Fibonacci numbers, commonly denoted F(n),
 * form a sequence, called the Fibonacci sequence, such that
 * each number is the sum of the two preceding ones, starting from 0 and 1. That is,
 * F(0) = 0, F(1) = 1,
 * and
 * F(n) = F(n − 1) + F(n − 2),
 * for n > 1.
 * Source: https://en.wikipedia.org/wiki/Fibonacci_number
 */

#pragma once
#include <cstdint>

int64_t fibonacciNumber(int16_t n)
{
	if (n <= 1)
		return n;
	
	return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}