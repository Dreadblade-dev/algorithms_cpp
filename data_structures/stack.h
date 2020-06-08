/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Stack realization
 * 
 * In computer science, a stack is an abstract data type that serves as a collection
 * of elements, with two principal operations:
 *  • push, which adds an element to the collection, and
 *  • pop, which removes the most recently added element that was not yet removed.
 *
 * The order in which elements come off a stack gives rise to its alternative name,
 * LIFO (last in, first out). Additionally, a peek operation may give access to the
 * top without modifying the stack.
 *
 * Time complexity:
 * ┌───────────┬──────────┐
 * │ Insertion │ Deletion │
 * │───────────┼──────────│
 * │    O(1)   │   O(1)   │ 
 * │───────────┼──────────│
 * │    O(1)   │   O(1)   │
 * └───────────┴──────────┘
 *
 * Source: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

#pragma once
#include <iostream>
#include "exceptions.h"

template <class T>
class Stack
{
private:
	std::size_t m_capacity;
	std::size_t m_size;
	T* m_data;
	struct constants
	{
		static const std::size_t default_capacity = 16;
		static const std::size_t extended_capacity = 16;
	};
public:
	Stack(std::size_t capacity = constants::default_capacity);
	Stack(Stack<T>& s);
	Stack(Stack<T>&& s) noexcept;
	~Stack();
	bool isEmpty() const noexcept;
	void clear() noexcept;
	void reallocate(std::size_t capacity) noexcept;
	void push_back(const T& item) noexcept;
	T pop();
	T peek();
	std::size_t getSize() const noexcept;
	std::size_t getCapacity() const noexcept;
	
	Stack& operator=(const Stack<T>& s) noexcept;
	Stack& operator=(Stack<T>&& s) noexcept;

	friend void swap(Stack<T>& l, Stack<T>& r) noexcept
	{
		std::swap(l.m_capacity, r.m_capacity);
		std::swap(l.m_size, r.m_size);
		std::swap(l.m_data, r.m_data);
	}
};

/** 
 * Default constructor
 */
template <class T>
Stack<T>::Stack(std::size_t capacity) : m_capacity(capacity), m_size(0)
{
	m_data = new T[capacity];
}

/**
 * Copy constructor
 */
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

/**
 * Move assignment constructor
 */
template <class T>
Stack<T>::Stack(Stack<T>&& s) noexcept
{
	swap(*this, s);
}

/**
 * Destructor
 */
template <class T>
Stack<T>::~Stack()
{
	delete[] m_data;
}

/**
 * Returns @true if the stack is empty
 */
template <class T>
bool Stack<T>::isEmpty() const noexcept
{
	return (m_size == 0);
}

/**
 * Clears the stack
 */
template <class T>
void Stack<T>::clear() noexcept
{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
	m_capacity = 0;
}

/**
 * Reallocates memory for data without data loss
 */
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

/**
 * Adds an @item to the stack
 */
template <class T>
void Stack<T>::push_back(const T& item) noexcept
{
	if ((m_size + 1) == m_capacity || m_size == m_capacity)
		reallocate(m_capacity + constants::extended_capacity);
	m_data[m_size] = item;
	++m_size;
}

/**
 * Deletes the last added item from the stack and returns it
 * Makes auto reallocate when capacity is four times the size
 */
template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
		throw StackEmptyException();

	T tmp = m_data[m_size - 1];
	--m_size;

	if (m_size < m_capacity / 4)
	{
		reallocate(m_capacity / 2);
	}
	
	return tmp;
}

/**
 * Returns the last added item from the stack
 */
template <class T>
T Stack<T>::peek()
{
	if (isEmpty())
		throw StackEmptyException();

	return m_data[m_size - 1];
}

/**
 * Returns stack size
 */
template <class T>
std::size_t Stack<T>::getSize() const noexcept
{
	return m_size;
}

/**
 * Returns stack capacity
 */
template <class T>
std::size_t Stack<T>::getCapacity() const noexcept
{
	return m_capacity;
}

/**
 * Copy assignment operator
 */
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) noexcept
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

/**
 * Move assignment operator
 */
template <class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& s) noexcept
{
	if (this == &s)
		return *this;

	swap(*this, s);
	return *this;
}