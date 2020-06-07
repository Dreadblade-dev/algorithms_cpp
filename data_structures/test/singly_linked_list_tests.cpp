#include "../singly_linked_list.h"
#include <gtest/gtest.h>

namespace SinglyLinkedListTest
{
	TEST(SinglyLinkedListTest, SinglyLinkedListCreatesEmpty)
	{
		SinglyLinkedList<int16_t> list;
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(SinglyLinkedListTest, SinglyLinkedListTestClear)
	{
		SinglyLinkedList<int16_t> list;

		list.insertAtEnd(25);
		list.insertAtStart(15);
		list.insertAtEnd(45);
		list.insertAtStart(35);
		
		list.clear();
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(SinglyLinkedListTest, SinglyLinkedListTestContains)
	{
		SinglyLinkedList<int16_t> list;
		
		list.insertAtEnd(25);
		list.insertAtStart(15);
		list.insertAtEnd(45);
		list.insertAtStart(35);
		
		EXPECT_FALSE(list.contains(0));
		EXPECT_FALSE(list.contains(10));
		EXPECT_FALSE(list.contains(20));
		
		EXPECT_TRUE(list.contains(15));
		EXPECT_TRUE(list.contains(25));
		EXPECT_TRUE(list.contains(35));
		EXPECT_TRUE(list.contains(45));

		EXPECT_FALSE(list.contains(55));
		EXPECT_FALSE(list.contains(-32768));
		EXPECT_FALSE(list.contains(32767));
	}

	TEST(SinglyLinkedListTest, SignlyLinkedListRemove)
	{
		SinglyLinkedList<int16_t> list;
		list.insertAtEnd(25);
		list.insertAtStart(15);
		list.insertAtEnd(45);
		list.insertAtStart(35);

		// At the start
		EXPECT_TRUE(list.contains(35));
		list.remove(35);
		EXPECT_FALSE(list.contains(35));


		// At the middle
		EXPECT_TRUE(list.contains(15));
		list.remove(15);
		EXPECT_FALSE(list.contains(15));

		EXPECT_TRUE(list.contains(25));
		list.remove(25);
		EXPECT_FALSE(list.contains(25));
		
		// At the end
		EXPECT_TRUE(list.contains(45));
		list.remove(45);
		EXPECT_FALSE(list.contains(45));
	}
	
	TEST(SinglyLinkedListTest, SinglyLinkedListInsertAtStart)
	{
		SinglyLinkedList<int16_t> list;
		list.insertAtStart(256);
		EXPECT_TRUE(list.contains(256));
		EXPECT_FALSE(list.isEmpty());
		list.remove(256);
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(SinglyLinkedListTest, SinglyLinkedListInsertAtEnd)
	{
		SinglyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		EXPECT_TRUE(list.contains(256));
		EXPECT_FALSE(list.isEmpty());
		list.remove(256);
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(SinglyLinkedListTest, SinglyLinkedListDeleteAtStart)
	{
		SinglyLinkedList<int16_t> list;
		list.insertAtStart(256);
		list.insertAtStart(512);
		EXPECT_FALSE(list.isEmpty());
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(512));
		EXPECT_TRUE(list.contains(256));
	}

	TEST(SinglyLinkedListTest, SinglyLinkedListDeleteAtEnd)
	{
		SinglyLinkedList<int16_t> list;
		list.insertAtStart(256);
		list.insertAtStart(512);
		EXPECT_FALSE(list.isEmpty());
		list.deleteAtEnd();
		EXPECT_FALSE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
	}
}