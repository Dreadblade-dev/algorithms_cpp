#include "../doubly_linked_list.h"
#include <gtest/gtest.h>

namespace DoublyLinkedListTest
{
	TEST(DoublyLinkedListTest, DoublyLinkedListCreatesEmpty)
	{
		DoublyLinkedList<int16_t> list;
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListClear)
	{
		DoublyLinkedList<int16_t> list;
		EXPECT_TRUE(list.isEmpty());
		list.insertAtEnd(8);
		list.insertAtEnd(16);
		list.insertAtEnd(24);
		list.insertAtEnd(32);
		list.insertAtEnd(40);
		list.insertAtEnd(48);
		list.insertAtEnd(56);
		list.insertAtEnd(64);
		EXPECT_TRUE(list.contains(8));
		EXPECT_TRUE(list.contains(16));
		EXPECT_TRUE(list.contains(24));
		EXPECT_TRUE(list.contains(32));
		EXPECT_TRUE(list.contains(40));
		EXPECT_TRUE(list.contains(48));
		EXPECT_TRUE(list.contains(56));
		EXPECT_TRUE(list.contains(64));
		EXPECT_FALSE(list.isEmpty());
		list.clear();
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListTestContains)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(8);
		list.insertAtEnd(16);
		list.insertAtEnd(24);
		list.insertAtEnd(32);
		list.insertAtEnd(40);
		list.insertAtEnd(48);
		list.insertAtEnd(56);
		list.insertAtEnd(64);
		EXPECT_TRUE(list.contains(8));
		EXPECT_TRUE(list.contains(16));
		EXPECT_TRUE(list.contains(24));
		EXPECT_TRUE(list.contains(32));
		EXPECT_TRUE(list.contains(40));
		EXPECT_TRUE(list.contains(48));
		EXPECT_TRUE(list.contains(56));
		EXPECT_TRUE(list.contains(64));

		EXPECT_FALSE(list.contains(0));
		EXPECT_FALSE(list.contains(72));
		EXPECT_FALSE(list.contains(80));
		EXPECT_FALSE(list.contains(88));
		EXPECT_FALSE(list.contains(96));
		EXPECT_FALSE(list.contains(104));
		EXPECT_FALSE(list.contains(112));
		EXPECT_FALSE(list.contains(120));
		EXPECT_FALSE(list.contains(128));
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListRemove)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(8);
		list.insertAtEnd(16);
		list.insertAtEnd(24);

		EXPECT_TRUE(list.contains(8));
		EXPECT_TRUE(list.contains(16));
		EXPECT_TRUE(list.contains(24));

		list.remove(8);
		EXPECT_FALSE(list.contains(8));
		
		list.remove(24);
		EXPECT_FALSE(list.contains(24));
		
		list.remove(16);
		EXPECT_FALSE(list.contains(16));
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListInsertAtStart)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtStart(256);
		list.insertAtStart(512);
		list.insertAtStart(1024);
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_FALSE(list.isEmpty());
		list.remove(256);
		list.remove(512);
		list.remove(1024);
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListInsertAtEnd)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_FALSE(list.isEmpty());
		list.remove(256);
		list.remove(512);
		list.remove(1024);
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListInsertAfter)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		list.insertAfter(256, 384);
		list.insertAfter(512, 768);
		list.insertAfter(1024, 1152);
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(384));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(768));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_TRUE(list.contains(1152));
		list.deleteAtStart();
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(384));
		list.deleteAtStart();
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(768));
		list.deleteAtEnd();
		EXPECT_FALSE(list.contains(1152));
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListInsertBefore)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		list.insertBefore(256, 128);
		list.insertBefore(512, 384);
		list.insertBefore(1024, 768);
		EXPECT_TRUE(list.contains(128));
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(384));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(768));
		EXPECT_TRUE(list.contains(1024));
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(128));
		list.deleteAtStart();
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(384));
		list.deleteAtEnd();
		list.deleteAtEnd();
		EXPECT_FALSE(list.contains(768));
	}
	TEST(DoublyLinkedListTest, DoublyLinkedListDeleteAtStart)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		EXPECT_FALSE(list.isEmpty());
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(256));
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(512));
		list.deleteAtStart();
		EXPECT_FALSE(list.contains(1024));
		EXPECT_TRUE(list.isEmpty());
	}
	
	TEST(DoublyLinkedListTest, DoublyLinkedListDeleteAtEnd)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		EXPECT_FALSE(list.isEmpty());
		list.deleteAtEnd();
		EXPECT_FALSE(list.contains(1024));
		list.deleteAtEnd();
		EXPECT_FALSE(list.contains(512));
		list.deleteAtEnd();
		EXPECT_FALSE(list.contains(256));
		EXPECT_TRUE(list.isEmpty());
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListReverse)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		list.insertAtEnd(1536);
		list.insertAtEnd(2048);
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_TRUE(list.contains(1536));
		EXPECT_TRUE(list.contains(2048));
		list.reverse();
		list.deleteAtStart();
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_TRUE(list.contains(1536));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtEnd();
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_TRUE(list.contains(1536));
		EXPECT_FALSE(list.contains(256));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtStart();
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_FALSE(list.contains(256));
		EXPECT_FALSE(list.contains(1536));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtEnd();
		EXPECT_TRUE(list.contains(1024));
		EXPECT_FALSE(list.contains(256));
		EXPECT_FALSE(list.contains(512));
		EXPECT_FALSE(list.contains(1536));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtStart();
		EXPECT_TRUE(list.isEmpty());

		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(1024);
		list.insertAtEnd(2048);
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_TRUE(list.contains(2048));
		list.reverse();
		list.deleteAtStart();
		EXPECT_TRUE(list.contains(256));
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtEnd();
		EXPECT_TRUE(list.contains(512));
		EXPECT_TRUE(list.contains(1024));
		EXPECT_FALSE(list.contains(256));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtStart();
		EXPECT_TRUE(list.contains(512));
		EXPECT_FALSE(list.contains(256));
		EXPECT_FALSE(list.contains(1024));
		EXPECT_FALSE(list.contains(2048));
		list.deleteAtStart();
		EXPECT_TRUE(list.isEmpty());
	}
	
	TEST(DoublyLinkedListTest, DoublyLinkedListCopyConstructor)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(768);
		list.insertAtEnd(1024);

		DoublyLinkedList<int16_t> list1(list);

		list.clear();
		
		EXPECT_TRUE(list.isEmpty());
		EXPECT_FALSE(list1.isEmpty());
		EXPECT_TRUE(list1.contains(256));
		EXPECT_TRUE(list1.contains(512));
		EXPECT_TRUE(list1.contains(768));
		EXPECT_TRUE(list1.contains(1024));

		list.insertAtEnd(128);
		DoublyLinkedList<int16_t> list2(list);
		EXPECT_TRUE(list2.contains(128));
	}

	TEST(DoublyLinkedListTest, DoublyLinkedListEqualOperator)
	{
		DoublyLinkedList<int16_t> list;
		list.insertAtEnd(256);
		list.insertAtEnd(512);
		list.insertAtEnd(768);
		list.insertAtEnd(1024);
		EXPECT_FALSE(list.isEmpty());
		
		auto list1 = list;
		
		list.clear();

		EXPECT_TRUE(list.isEmpty());
		EXPECT_FALSE(list1.isEmpty());
		EXPECT_TRUE(list1.contains(256));
		EXPECT_TRUE(list1.contains(512));
		EXPECT_TRUE(list1.contains(768));
		EXPECT_TRUE(list1.contains(1024));

		list1.clear();
		list.insertAtEnd(128);
		list1 = list;
		EXPECT_TRUE(list1.contains(128));
	}
}