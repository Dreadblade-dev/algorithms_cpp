#pragma once
#include <iostream>
#include "exceptions.h"

/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Stack realization
 * 
 * In computer science, a stack is an abstract data type that serves as a collection of elements, with two principal operations:
 *  • push, which adds an element to the collection, and
 *  • pop, which removes the most recently added element that was not yet removed.
 *
 * The order in which elements come off a stack gives rise to its alternative name, LIFO (last in, first out). Additionally, a peek operation may give access to the top without modifying the stack.
 *
 * Source: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */



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
	Stack(std::size_t capacity = constants::defaultCapacity);
	Stack(Stack& stack);
	~Stack();
	bool isEmpty() noexcept;
	void clear() noexcept;
	void reallocate(std::size_t capacity) noexcept;
	void push_back(const T& item) noexcept;
	T pop();
	T peek();
	std::size_t getSize() noexcept;
	std::size_t getCapacity() noexcept;
	
	Stack& operator=(Stack& s) noexcept;
};



template <class T>
Stack<T>::Stack(std::size_t capacity) : m_capacity(capacity), m_size(0)
{
	m_data = new T[capacity];
}

template <class T>
Stack<T>::Stack(Stack<T>& s)
{
	m_size = s.m_size;
	m_capacity = s.m_capacity;
	m_data = new T[m_capacity];

	for (std::size_t count = 0; count < m_size; ++count)
	{
		m_data[count] = s.m_data[count];
	}
}

template <class T>
Stack<T>::~Stack()
{
	delete[] m_data;
}

template <class T>
bool Stack<T>::isEmpty() noexcept
{
	return (m_size == 0);
}

template <class T>
void Stack<T>::clear() noexcept
{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <class T>
void Stack<T>::reallocate(std::size_t capacity) noexcept
{
	if (m_capacity == capacity)
		return;

	if (m_data == nullptr)
	{
		m_data = new T[capacity];
		m_capacity = capacity;
	}
	else
	{
		T* data = new T[capacity];

		if (m_capacity < capacity)
		{
			for (std::size_t count = 0; count < m_capacity; ++count)
			{
				data[count] = m_data[count];
			}
		}
		else
			if (m_capacity > capacity)
			{
				if (m_size > capacity)
					m_size = capacity;
				for (std::size_t count = 0; count < capacity; ++count)
				{
					data[count] = m_data[count];
				}
			}


		m_capacity = capacity;
		delete[] m_data;
		m_data = data;
	}
}

template <class T>
void Stack<T>::push_back(const T& item) noexcept
{
	if ((m_size + 1) == m_capacity)
		reallocate(m_capacity + constants::extendedCapacity);
	m_data[m_size] = item;
	++m_size;
}

template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
		throw StackEmptyException();

	T tmp = m_data[m_size - 1];
	--m_size;

	return tmp;
}

template <class T>
T Stack<T>::peek()
{
	if (isEmpty())
		throw StackEmptyException();

	return m_data[m_size - 1];
}

template <class T>
std::size_t Stack<T>::getSize() noexcept
{
	return m_size;
}

template <class T>
std::size_t Stack<T>::getCapacity() noexcept
{
	return m_capacity;
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T>& s) noexcept
{
	if (this == &s)
		return *this;

	this->clear();
	m_capacity = s.m_capacity;
	m_size = s.m_size;

	m_data = new T[m_capacity];
	for (std::size_t count = 0; count < m_size; ++count)
	{
		m_data[count] = s.m_data[count];
	}

	return *this;
}