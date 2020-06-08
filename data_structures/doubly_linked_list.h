/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Doubly linked list realization
 *
 * In computer science, a doubly linked list is a linked data structure
 * that consists of a set of sequentially linked records called nodes.
 *
 * Each node contains three fields: two link fields (references
 * to the previous and to the next node in the sequence of nodes)
 * and one data field.
 *
 * The beginning and ending nodes' previous and next links, respectively,
 * point to some kind of terminator, typically a sentinel node or null,
 * to facilitate traversal of the list.
 *
 * Time complexity:
 * ┌───────────────┬───────────┬──────────┐
 * │	    	   │ Insertion │ Deletion │
 * │───────────────┼───────────┼──────────│
 * │  At the start │	O(1)   │   O(1)   │
 * │───────────────┼───────────┼──────────│
 * │ In the middle │	O(1)   │   O(1)	  │
 * │───────────────┼───────────┼──────────│
 * │  At the end   │    O(1)   │   O(1)   │
 * └───────────────┴───────────┴──────────┘
 *
 * Source: https://en.wikipedia.org/wiki/Doubly_linked_list
 */

#pragma once
#include <iostream>
#include "exceptions.h"

template <class T>
class DoublyLinkedList
{
private:
	template <class T>
	struct Node
	{
		Node<T>* prev;
		T data;
		Node<T>* next;
	};
	
	Node<T>* m_head;
	Node<T>* m_tail;
	

public:
	DoublyLinkedList();
	DoublyLinkedList(DoublyLinkedList<T>& list);
	DoublyLinkedList(DoublyLinkedList<T>&& list) noexcept;
	~DoublyLinkedList();
	bool isEmpty() const noexcept;
	bool contains(const T& item) const noexcept;
	void clear() noexcept;
	void remove(const T& item); 
	void insertAtStart(const T& item) noexcept;
	void insertAtEnd(const T& item) noexcept;
	void insertAfter(const T& itemBefore, const T& item);
	void insertBefore(const T& itemAfter, const T& item);
	void deleteAtStart();
	void deleteAtEnd();
	void reverse();

	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& list);
	DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& list) noexcept;

	friend void swap(DoublyLinkedList<T>& l, DoublyLinkedList<T>& r) noexcept
	{
		std::swap(l.m_head, r.m_head);
		std::swap(l.m_tail, r.m_tail);
	}
	
	friend std::ostream& operator<<(std::ostream& out, DoublyLinkedList<T>& list)
	{
		if (list.isEmpty())
			throw ListEmptyException();

		auto currentNode = list.m_head;
		while (currentNode != nullptr)
		{
			out << currentNode->data << ' ';
			currentNode = currentNode->next;
		}

		return out;
	}
};

/**
 * Default constructor, creates empty list
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(): m_head(nullptr), m_tail(nullptr)
{

}

/**
 * Copy assignment constructor
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>& list)
{
	if (list.isEmpty())
	{
		m_head = nullptr;
		m_tail = nullptr;
		return;
	}

	auto currentNode = new Node<T>;
	auto nodeToCopy = list.m_head;

	currentNode->prev = nullptr;
	currentNode->data = nodeToCopy->data;
	m_head = currentNode;

	nodeToCopy = nodeToCopy->next;

	while (nodeToCopy != nullptr)
	{
		currentNode->next = new Node<T>;
		currentNode->next->prev = currentNode;
		currentNode = currentNode->next;
		currentNode->data = nodeToCopy->data;

		nodeToCopy = nodeToCopy->next;
	}
	currentNode->next = nullptr;
	m_tail = currentNode;
}

/**
 * Move assignment constructor
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& list) noexcept
{
	swap(*this, list);
}

/**
 * Destructor
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (isEmpty())
		return;

	auto currentNode = m_head;
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		delete currentNode->prev;
	}

	delete currentNode;
}

/**
 * Returns @true if the list is empty
 */
template <class T>
bool DoublyLinkedList<T>::isEmpty() const noexcept
{
	return (m_head == nullptr);
}

/**
 * Returns @true if the list contains @item
 */
template <class T>
bool DoublyLinkedList<T>::contains(const T& item) const noexcept
{
	if (isEmpty())
		return false;
	
	auto currentNode = m_head;
	while (currentNode != nullptr)
	{
		if (currentNode->data == item)
			return true;
		
		currentNode = currentNode->next;
	}

	return false;
}

/**
 * Clears the list
 */
template <class T>
void DoublyLinkedList<T>::clear() noexcept
{
	if (isEmpty())
		return;
	
	auto currentNode = m_head;
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		delete currentNode->prev;
	}

	delete currentNode;
	
	m_head = nullptr;
	m_tail = nullptr;
}

/**
 * Removes a node with @item from the list
 */
template <class T>
void DoublyLinkedList<T>::remove(const T& item)
{
	if (isEmpty())
		throw ListEmptyException();

	auto currentNode = m_head;
	while (currentNode != nullptr)
	{
		if (currentNode->data == item)
		{
			if (currentNode == m_head)
			{
				if (m_head->next == nullptr)
				{
					delete m_head;
					m_head = nullptr;
					return;
				}
				auto head = m_head;
				m_head = m_head->next;
				delete head;
				m_head->prev = nullptr;
				return;
			}
			if (currentNode == m_tail)
			{
				m_tail = m_tail->prev;
				delete m_tail->next;
				m_tail->next = nullptr;
				return;
			}
			if (currentNode->prev != nullptr)
				currentNode->prev->next = currentNode->next;
			
			if(currentNode->next != nullptr)
				currentNode->next->prev = currentNode->prev;
			
			delete currentNode;
			return;
		}
		currentNode = currentNode->next;
	}
}

/**
 * Inserts a new node with @item at the start
 */
template <class T>
void DoublyLinkedList<T>::insertAtStart(const T& item) noexcept
{
	if (!isEmpty())
	{
		auto newHead = new Node<T>;
		newHead->prev = nullptr;
		newHead->next = m_head;
		newHead->data = item;

		m_head->prev = newHead;
		
		m_head = newHead;
		return;
	}
	
	if (isEmpty())
	{
		m_head = new Node<T>;
		m_head->prev = nullptr;
		m_head->next = nullptr;
		m_head->data = item;
	}
}

/**
 * Inserts a new node with @item at the end
 */
template <class T>
void DoublyLinkedList<T>::insertAtEnd(const T& item) noexcept
{
	if (m_tail != nullptr)
	{
		auto newTail = new Node<T>;
		newTail->prev = m_tail;
		newTail->next = nullptr;
		newTail->data = item;
		m_tail->next = newTail;

		m_tail = newTail;
		return;
	}
	
	if (m_tail == nullptr && m_head != nullptr)
	{
		m_tail = new Node<T>;
		m_tail->prev = m_head;
		m_tail->next = nullptr;
		m_tail->data = item;
		m_head->next = m_tail;
		return;
	}
	
	if (isEmpty())
	{
		m_head = new Node<T>;
		m_head->prev = nullptr;
		m_head->next = nullptr;
		m_head->data = item;
	}
}

/**
 * Inserts a new node with @item after node with data @itemBefore
 */
template <class T>
void DoublyLinkedList<T>::insertAfter(const T& itemBefore, const T& item)
{
	if (isEmpty())
		throw ListEmptyException();

	auto currentNode = m_head;
	while (currentNode != nullptr)
	{
		if (currentNode->data == itemBefore)
		{
			if (currentNode == m_head)
			{
				if (m_tail == nullptr)
					insertAtEnd(item);
				else
				{
					auto nodeToInsert = new Node<T>;
					nodeToInsert->data = item;
					nodeToInsert->prev = m_head;
					nodeToInsert->next = m_head->next;
					m_head->next->prev = nodeToInsert;
					m_head->next = nodeToInsert;
				}
				return;
			}

			if (currentNode == m_tail)
			{
				insertAtEnd(item);
				return;
			}

			auto nodeToInsert = new Node<T>;
			nodeToInsert->data = item;
			nodeToInsert->prev = currentNode;
			nodeToInsert->next = currentNode->next;
			currentNode->next->prev = nodeToInsert;
			currentNode->next = nodeToInsert;
		}
		currentNode = currentNode->next;
	}
}

/**
 * Inserts a new node with @item before node with data @itemAfter
 */
template <class T>
void DoublyLinkedList<T>::insertBefore(const T& itemAfter, const T& item)
{
	if (isEmpty())
		throw ListEmptyException();

	auto currentNode = m_head;
	while (currentNode != nullptr)
	{
		if (currentNode->data == itemAfter)
		{
			auto nodeToInsert = new Node<T>;
			nodeToInsert->data = item;
			nodeToInsert->next = currentNode;
			

			if (currentNode == m_head)
			{
				nodeToInsert->prev = nullptr;
				m_head->prev = nodeToInsert;
				m_head = nodeToInsert;
			}
			else
			{
				nodeToInsert->prev = currentNode->prev;
				currentNode->prev->next = nodeToInsert;
				currentNode->prev = nodeToInsert;
			}
			return;
		}
		currentNode = currentNode->next;
	}
}

/**
 * Deletes the node at the start of the list
 */
template <class T>
void DoublyLinkedList<T>::deleteAtStart()
{
	if (isEmpty())
		throw ListEmptyException();

	if (m_tail != nullptr && m_head != nullptr && m_head != m_tail)
	{
		m_head = m_head->next;
		delete m_head->prev;
		m_head->prev = nullptr;
	}
	else
	{
		delete m_head;
		m_head = nullptr;
	}
}

/**
 * Deletes the node at the end of the list
 */
template <class T>
void DoublyLinkedList<T>::deleteAtEnd()
{
	if (isEmpty())
		throw ListEmptyException();

	if (m_tail != nullptr)
	{
		if (m_tail->prev == m_head)
		{
			delete m_tail;
			m_tail = nullptr;
			m_head->next = nullptr;
		}
		else
		{
			m_tail = m_tail->prev;
			delete m_tail->next;
			m_tail->next = nullptr;
		}
	}
	else
	{
		delete m_head;
		m_head = nullptr;
	}
	
}

/**
 * Reverses the list
 */
template <class T>
void DoublyLinkedList<T>::reverse()
{
	if (isEmpty())
		throw ListEmptyException();

	auto nodeFromStart = m_head;
	auto nodeFromEnd = m_tail;
	while (nodeFromStart != nodeFromEnd && nodeFromStart->prev != nodeFromEnd)
	{
		auto tmp = nodeFromEnd->data;
		nodeFromEnd->data = nodeFromStart->data;
		nodeFromStart->data = tmp;
		
		nodeFromStart = nodeFromStart->next;
		nodeFromEnd = nodeFromEnd->prev;
	}
}

/**
 * Copy assignment operator
 */
template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& list)
{
	if (this == &list)
		return *this;

	if (list.isEmpty())
	{
		m_head = nullptr;
		m_tail = nullptr;
		return *this;
	}

	auto currentNode = new Node<T>;
	auto nodeToCopy = list.m_head;

	currentNode->prev = nullptr;
	currentNode->data = nodeToCopy->data;
	m_head = currentNode;

	nodeToCopy = nodeToCopy->next;

	while (nodeToCopy != nullptr)
	{
		currentNode->next = new Node<T>;
		currentNode->next->prev = currentNode;
		currentNode = currentNode->next;
		currentNode->data = nodeToCopy->data;

		nodeToCopy = nodeToCopy->next;
	}
	currentNode->next = nullptr;
	m_tail = currentNode;

	return *this;
}

/**
 * Move assignment operator
 */
template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& list) noexcept
{
	if (this == &list)
		return *this;

	swap(*this, list);
	return *this;
}