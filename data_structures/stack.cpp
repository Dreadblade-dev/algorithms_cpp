#include "stack.h"
#include <iostream>
#include <cassert>
#include <cstdint>

template <class T>
Stack<T>::Stack(std::size_t capacity): m_capacity(capacity), m_size(0)
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
bool Stack<T>::isEmpty()
{
	return (m_size == 0);
}

template <class T>
void Stack<T>::clear()
{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <class T>
void Stack<T>::reallocate(std::size_t capacity)
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
void Stack<T>::push_back(const T& item)
{
	if (m_size == m_capacity)
		reallocate(m_size + constants::extendedCapacity);
	m_data[m_size] = item;
	++m_size;
}

template <class T>
T& Stack<T>::pop()
{
	if (isEmpty())
		throw StackEmptyException();

	T tmp = m_data[m_size - 1];
	--m_size;

	return tmp;
}

template <class T>
T& Stack<T>::top()
{
	if (isEmpty())
		throw StackEmptyException();

	return m_data[m_size - 1];
}

template <class T>
std::size_t Stack<T>::getSize()
{
	return m_size;
}

template <class T>
std::size_t Stack<T>::getCapacity()
{
	return m_capacity;
}

template <class T>
Stack<T>& Stack<T>::operator=(Stack<T>& s)
{
	if (this == &s)
		return *this;

	this->clear();
	m_capacity = s.m_capacity;
	m_size = s.m_size;

	m_data = new T[m_capacity];
	for (int count = 0; count < m_size; ++count)
	{
		m_data[count] = s.m_data[count];
	}

	return *this;
}

int main()
{
	Stack<int16_t> stack(16);

	for (int16_t count = 0; count < 105; ++count)
		stack.push_back(count);


	for (int16_t count = 0; count < 85; ++count)
	{
		try
		{
			std::cout << stack.pop() << '\n';
		}
		catch (std::exception& exc)
		{
			std::cout << "Exception was caught: " << exc.what() << '\n';
		}
	}

	std::cout << "Before reallocate:\nCapacity:" << stack.getCapacity() <<
		"\nSize: " << stack.getSize() << '\n';
		
	stack.reallocate(constants::defaultCapacity);

	std::cout << "After reallocate:\nCapacity:" << stack.getCapacity() <<
		"\nSize: " << stack.getSize() << '\n';
	
	for (int16_t count = 0; count < 17; ++count)
	{
		try
		{
			std::cout << stack.pop() << '\n';
		}
		catch (std::exception& exc)
		{
			std::cout << "Exception was caught: " << exc.what() << '\n';
		}
	}

	return 0;
	
}