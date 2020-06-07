#pragma once
#include <iostream>
#include <exception>

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
 * Source: https://en.wikipedia.org/wiki/Linked_list
 */

template <class T>
struct Node
{
	Node<T>* next;
	T data;
};

template <class T>
class SinglyLinkedList
{
private:
	Node<T>* m_head;
public:
	SinglyLinkedList();
	SinglyLinkedList(SinglyLinkedList& list);
	~SinglyLinkedList();
	bool isEmpty() noexcept;
	bool contains(const T& item) noexcept;
	void clear() noexcept;
	void remove(const T& item);
	void insertAtStart(const T& item) noexcept;
	void insertAtEnd(const T& item) noexcept;
	void deleteAtStart();
	void deleteAtEnd();

	SinglyLinkedList& operator=(SinglyLinkedList& list);
	
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, SinglyLinkedList<T>& list);
};

class ListEmptyException : public std::exception
{
public:
	const char* what() const override
	{
		return "List is empty";
	}
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(): m_head(nullptr)
{

}

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

template <class T>
bool SinglyLinkedList<T>::isEmpty() noexcept
{
	return (m_head == nullptr);
}

template <class T>
bool SinglyLinkedList<T>::contains(const T& item) noexcept
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

template <class T>
void SinglyLinkedList<T>::deleteAtStart()
{
	if (isEmpty())
		throw ListEmptyException();

	auto tmp = m_head->next;
	delete m_head;
	m_head = tmp;
}

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


template <class T>
std::ostream& operator<<(std::ostream& out, SinglyLinkedList<T>& list)
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

template <class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList& list)
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
