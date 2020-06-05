#pragma once
#include <exception>
#include "stack_empty_exception.h"

namespace constants
{
	static const std::size_t defaultCapacity = 16;
	static const std::size_t extendedCapacity = 16;
}

template <class T>
class Stack
{
private:

	std::size_t m_capacity;
	std::size_t m_size;
	T* m_data;
	
public:
	Stack(std::size_t capacity);
	Stack(Stack<T>& stack);
	~Stack();

	bool isEmpty();

	void clear();

	void reallocate(std::size_t capacity);

	void push_back(const T& item);

	T& pop();

	T& top();

	std::size_t getSize();

	std::size_t getCapacity();

	Stack<T>& operator=(Stack<T>& s);
};