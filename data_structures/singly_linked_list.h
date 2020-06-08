/**
 * @author Dreadblade- (https://github.com/Dreadblade-dev)
 * Singly linked list realization
 *
 * In computer science, a linked list is a linear collection of data elements,
 * whose order is not given by their physical placement in memory.
 * 
 * Instead, each element points to the next.
 * 
 * It is a data structure consisting of a collection of nodes which
 * together represent a sequence.
 * 
 * In its most basic form, each node contains: data, and a reference
 * (in other words, a link) to the next node in the sequence.
 * 
 * Time complexity:
 * ┌───────────────┬───────────┬──────────┐
 * │	    	   │ Insertion │ Deletion │
 * │───────────────┼───────────┼──────────│
 * │  At the start │	O(1)   │   O(1)   │
 * │───────────────┼───────────┼──────────│
 * │ In the middle │		   │		  │
 * │───────────────┼───────────┼──────────│
 * │  At the end   │    O(1)   │   O(1)   │
 * └───────────────┴───────────┴──────────┘
 * 
 * Source: https://en.wikipedia.org/wiki/Linked_list
 */

#pragma once
#include <iostream>
#include "exceptions.h"

template <class T>
class SinglyLinkedList
{
private:
	template <class T>
	struct Node
	{
		Node<T>* next;
		T data;
	};
	
	Node<T>* m_head;
public:
	SinglyLinkedList();
	SinglyLinkedList(SinglyLinkedList<T>& list);
	SinglyLinkedList(SinglyLinkedList<T>&& list) noexcept;
	~SinglyLinkedList();
	bool isEmpty() const noexcept;
	bool contains(const T& item) const noexcept;
	void clear() noexcept;
	void remove(const T& item);
	void insertAtStart(const T& item) noexcept;
	void insertAtEnd(const T& item) noexcept;
	void deleteAtStart();
	void deleteAtEnd();

	SinglyLinkedList<T>& operator=(const SinglyLinkedList& list);
	SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&& list) noexcept;

	friend void swap(SinglyLinkedList<T>& l, SinglyLinkedList<T>& r) noexcept
	{
		std::swap(l.m_head, r.m_head);
	}
	
	friend std::ostream& operator<<(std::ostream& out, SinglyLinkedList<T>& list)
	{
		if (list.isEmpty())
			throw ListEmptyException();

		auto currentNode = list.m_head;
		while (currentNode->next != nullptr)
		{
			out << currentNode->data << ' ';
			currentNode = currentNode->next;
		}

		out << currentNode->data;

		return out;
	}
};

/**
 * Default constructor, creates empty list
 */
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(): m_head(nullptr)
{

}

/**
 * Copy constructor
 */
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList& list)
{
	if (list.isEmpty())
	{
		m_head = nullptr;
		return;
	}
	
	auto currentNode = new Node<T>;
	auto prevNode = currentNode;
	auto nodeToCopy = list.m_head;

	m_head = currentNode;
	
	currentNode->data = nodeToCopy->data;
	prevNode->next = currentNode;
	nodeToCopy = nodeToCopy->next;
	
	while (nodeToCopy != nullptr)
	{
		currentNode = new Node<T>;
		currentNode->data = nodeToCopy->data;
		prevNode->next = currentNode;
		prevNode = currentNode;
		nodeToCopy = nodeToCopy->next;
	}
	currentNode->next = nullptr;
}

/**
 * Move assignment constructor
 */
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T>&& list) noexcept
{
	swap(*this, list);
}

/**
 * Destructor
 */
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	if (!isEmpty())
	{
		auto currentNode = m_head;
		auto nodeToDelete = m_head;
		
		while (currentNode->next != nullptr)
		{
			currentNode = currentNode->next;
			delete nodeToDelete;
			nodeToDelete = currentNode;
		}
		delete currentNode;
	}
}

/**
 * Returns @true if the list is empty
 */
template <class T>
bool SinglyLinkedList<T>::isEmpty() const noexcept
{
	return (m_head == nullptr);
}

/**
 * Returns @true if the list contains @item
 */
template <class T>
bool SinglyLinkedList<T>::contains(const T& item) const noexcept
{
	if (isEmpty())
		return false;

	auto currentNode = m_head;
	
	while (currentNode->next != nullptr)
	{
		
			if (currentNode->data == item)
				return true;
			
		currentNode = currentNode->next;
	}

	if (currentNode->data == item)
		return true;

	return false;
}

/**
 * Clears the list
 */
template <class T>
void SinglyLinkedList<T>::clear() noexcept
{
	if (isEmpty())
		return;

	auto currentNode = m_head;
	auto nodeToDelete = m_head;

	do
	{
		currentNode = currentNode->next;
		delete nodeToDelete;
		nodeToDelete = currentNode;
	} while (currentNode->next != nullptr);

	m_head = nullptr;
}

/**
 * Removes a node with @item from the list
 */
template <class T>
void SinglyLinkedList<T>::remove(const T& item)
{
	if (isEmpty())
		throw ListEmptyException();

	auto nodeToRemove = m_head;
	auto nodeToChangeNext = m_head;

	while (nodeToRemove->next != nullptr)
	{
		if (nodeToRemove->data == item)
		{
			if (nodeToRemove == m_head)
				m_head = nodeToRemove->next;
			else
				nodeToChangeNext->next = nodeToRemove->next;
			
			delete nodeToRemove;
			return;
		}
		nodeToChangeNext = nodeToRemove;
		nodeToRemove = nodeToRemove->next;
	}
	
	if (nodeToRemove->data == item)
	{
		if (nodeToRemove == m_head && m_head->next == nullptr)
		{
			delete m_head;
			m_head = nullptr;
			return;
		}
		nodeToChangeNext->next = nullptr;
		delete nodeToRemove;
	}
}

/**
 * Inserts a new node with @item at the start
 */
template <class T>
void SinglyLinkedList<T>::insertAtStart(const T& item) noexcept
{
	if (!isEmpty())
	{
		auto head = new Node<T>;
		head->data = item;
		head->next = m_head;
		m_head = head;
	}
	
	if (isEmpty())
	{
		auto head = new Node<T>;
		head->data = item;
		head->next = nullptr;
		m_head = head;
	}
}

/**
 * Inserts a new node with @item at the end
 */
template <class T>
void SinglyLinkedList<T>::insertAtEnd(const T& item) noexcept
{
	if (!isEmpty())
	{
		auto tail = new Node<T>;
		tail->data = item;
		tail->next = nullptr;

		auto currentNode = m_head;
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		currentNode->next = tail;
	}
	else
		insertAtStart(item);
}

/**
 * Deletes the node at the start of the list
 */
template <class T>
void SinglyLinkedList<T>::deleteAtStart()
{
	if (isEmpty())
		throw ListEmptyException();

	auto tmp = m_head->next;
	delete m_head;
	m_head = tmp;
}

/**
 * Deletes the node at the end of the list
 */
template <class T>
void SinglyLinkedList<T>::deleteAtEnd()
{
	if (isEmpty())
		throw ListEmptyException();

	if (m_head->next == nullptr)
	{
		delete m_head;
		m_head = nullptr;
		return;
	}
	
	auto currentNode = m_head;
	while (currentNode->next->next != nullptr)
		currentNode = currentNode->next;

	delete currentNode->next;
	currentNode->next = nullptr;
}

/**
 * Copy assignment operator
 */
template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList& list)
{
	if (this == &list)
		return *this;

	if (list.isEmpty())
	{
		m_head = nullptr;
		return *this;
	}

	auto currentNode = new Node<T>;
	auto prevNode = currentNode;
	auto nodeToCopy = list.m_head;

	m_head = currentNode;

	currentNode->data = nodeToCopy->data;
	prevNode->next = currentNode;
	nodeToCopy = nodeToCopy->next;

	while (nodeToCopy != nullptr)
	{
		currentNode = new Node<T>;
		currentNode->data = nodeToCopy->data;
		prevNode->next = currentNode;
		prevNode = currentNode;
		nodeToCopy = nodeToCopy->next;
	}
	currentNode->next = nullptr;

	return *this;
}

/**
 * Move assignment operator
 */
template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T>&& list) noexcept
{
	if (this == &list)
		return *this;

	swap(*this, list);
	return *this;
}