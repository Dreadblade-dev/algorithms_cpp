/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Queue realization
 *
 * In computer science, a queue is a collection of entities
 * that are maintained in a sequence and can be modified
 * by the addition of entities at one end of the sequence
 * and the removal of entities from the other end of the
 * sequence.
 *
 * By convention, the end of the sequence at which elements
 * are added is called the back, tail, or rear of the queue,
 * and the end at which elements are removed is called the
 * head or front of the queue, analogously to the words
 * used when people line up to wait for goods or services.
 *
 * Time complexity:
 * ┌──────────────┬───────────┬──────────┐
 * │			  │ Insertion │ Deletion │
 * │──────────────┼───────────┼──────────│
 * │ At the start │	   O(1)	  │   O(1)   │
 * │──────────────┼───────────┼──────────│
 * │  At the end  │    O(1)   │   O(1)	 │
 * └──────────────┴───────────┴──────────┘
 * Source: https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
 */

#pragma once
#include "stack.h"
#include "exceptions.h"

template <class T>
class Queue
{
private:
	Stack<T> m_front;
	Stack<T> m_back;
	
public:
	Queue();
	Queue(const Queue<T>& queue);
	Queue(Queue<T>&& queue) noexcept;
	~Queue();
	bool isEmpty() const noexcept;
	void clear() noexcept;
	void enqueue(const T& item) noexcept;
	T dequeue();
	T front();
	T back();
	std::size_t getSize() const noexcept;
	
	Queue<T>& operator=(const Queue<T>& queue);
	Queue<T>& operator=(Queue<T>&& queue) noexcept;

	friend void swap(Queue<T>& l, Queue<T>& r) noexcept
	{
		std::swap(l.m_front, r.m_front);
		std::swap(l.m_back, r.m_back);
	}
};

/**
 * Default constructor, creates queue
 */
template <class T>
Queue<T>::Queue() : m_front(), m_back()
{
	
}

/**
 * Copy assignment constructor
 */
template <class T>
Queue<T>::Queue(const Queue<T>& queue)
{
	m_front = queue.m_front;
	m_back = queue.m_back;
}

/**
 * Move assignment constructor
 */
template <class T>
Queue<T>::Queue(Queue<T>&& queue) noexcept
{
	swap(*this, queue);
}

/**
 * Destructor
 */
template <class T>
Queue<T>::~Queue()
{
	m_front.clear();
	m_back.clear();
}

/**
 * Returns @true if the queue is empty
 */
template <class T>
bool Queue<T>::isEmpty() const noexcept
{
	return (m_front.isEmpty() && m_back.isEmpty());
}

/**
 * Clears the queue
 */
template <class T>
void Queue<T>::clear() noexcept
{
	if (isEmpty())
		return;
	
	m_front.clear();
	m_back.clear();
}

/**
 * Adds @item to the end of the queue
 */
template <class T>
void Queue<T>::enqueue(const T& item) noexcept
{
	m_back.push_back(item);
}

/**
 * Removes the first item from the queue and returns it
 */
template <class T>
T Queue<T>::dequeue()
{
	if (m_front.isEmpty() && m_back.isEmpty())
		throw QueueEmptyException();

	if (m_front.isEmpty())
	{
		if (m_back.getSize() > 1)
		{
			while (m_back.getSize() != 1)
				m_front.push_back(m_back.pop());
		}
		
		if (m_back.getSize() == 1)
			m_front.push_back(m_back.pop());
	}

	return m_front.pop();
}

/**
 * Returns the first item from the queue 
 */
template <class T>
T Queue<T>::front()
{
	if (m_front.isEmpty() && m_back.isEmpty())
		throw QueueEmptyException();

	if (m_front.isEmpty())
	{
		if (m_back.getSize() > 1)
		{
			while (m_back.getSize() != 1)
				m_front.push_back(m_back.pop());
		}

		if (m_back.getSize() == 1)
			m_front.push_back(m_back.pop());
	}

	return m_front.peek();
}

/**
 * Returns the last item from the queue 
 */
template <class T>
T Queue<T>::back()
{
	if (m_front.isEmpty() && m_back.isEmpty())
		throw QueueEmptyException();

	if (m_back.isEmpty())
	{
		while (!m_front.isEmpty())
			m_back.push_back(m_front.pop());
	}

	return m_back.peek();
}

/**
 * Returns queue size
 */
template <class T>
std::size_t Queue<T>::getSize() const noexcept
{
	return m_front.getSize() + m_back.getSize();
}

/**
 * Copy assignment operator
 */
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
	if (this == &queue)
		return *this;
	
	m_front = queue.m_front;
	m_back = queue.m_back;

	return *this;
}

/**
 * Move assignment operator
 */
template <class T>
Queue<T>& Queue<T>::operator=(Queue<T>&& queue) noexcept
{
	if (this == &queue)
		return *this;

	swap(*this, queue);
	return *this;
}