#include "../queue.h"
#include "gtest/gtest.h"

namespace QueueTest
{
	TEST(QueueTest, QueueCreatesEmpty)
	{
		Queue<int16_t> queue;
		EXPECT_TRUE(queue.isEmpty());
		EXPECT_THROW(queue.dequeue(), QueueEmptyException);
	}
	
	TEST(QueueTest, QueueClears)
	{
		Queue<int16_t> queue;
		queue.enqueue(16);
		queue.enqueue(32);
		queue.enqueue(48);
		queue.enqueue(64);
		EXPECT_FALSE(queue.isEmpty());
		queue.clear();
		EXPECT_TRUE(queue.isEmpty());
		EXPECT_THROW(queue.dequeue(), QueueEmptyException);
	}

	TEST(QueueTest, QueueEnqueueDequeue)
	{
		Queue<int16_t> queue;
		for (int i = 0; i < 256; ++i)
			queue.enqueue(i);

		EXPECT_FALSE(queue.isEmpty());
		
		for (int i = 0; i < 256; ++i)
			EXPECT_EQ(queue.dequeue(), i);

		EXPECT_TRUE(queue.isEmpty());
	}

	TEST(QueueTest, QueueFrontBack)
	{
		Queue<int16_t> queue;
		queue.enqueue(128);
		EXPECT_EQ(queue.front(), 128);
		EXPECT_EQ(queue.back(), 128);

		queue.enqueue(256);
		EXPECT_EQ(queue.front(), 128);
		EXPECT_EQ(queue.back(), 256);
	}
	
	TEST(QueueTest, QueueCopyConstructor)
	{
		Queue<int16_t> queue;
		queue.enqueue(256);
		queue.enqueue(512);
		queue.enqueue(768);
		queue.enqueue(1024);

		Queue<int16_t> queue1(queue);

		queue.clear();

		EXPECT_TRUE(queue.isEmpty());
		EXPECT_FALSE(queue1.isEmpty());
		EXPECT_EQ(queue1.dequeue(), 256);
		EXPECT_EQ(queue1.dequeue(), 512);
		EXPECT_EQ(queue1.dequeue(), 768);
		EXPECT_EQ(queue1.dequeue(), 1024);
		
		EXPECT_TRUE(queue1.isEmpty());
		queue.enqueue(256);
		Queue<int16_t> queue2(queue);
		EXPECT_EQ(queue.dequeue(), 256);
	}

	TEST(QueueTest, QueueGetSize)
	{
		Queue<int16_t> queue;
		for (int i = 0; i < 8; ++i)
			queue.enqueue(i * i);
		EXPECT_EQ(queue.getSize(), 8);
	}
	
	TEST(QueueTest, QueueCopyOperator)
	{
		Queue<int16_t> queue;
		
		queue.enqueue(256);
		queue.enqueue(512);
		queue.enqueue(768);
		queue.enqueue(1024);
		
		Queue<int16_t> queue1 = queue;
		
		queue.clear();

		EXPECT_TRUE(queue.isEmpty());
		EXPECT_FALSE(queue1.isEmpty());
		EXPECT_EQ(queue1.dequeue(), 256);
		EXPECT_EQ(queue1.dequeue(), 512);
		EXPECT_EQ(queue1.dequeue(), 768);
		EXPECT_EQ(queue1.dequeue(), 1024);

		EXPECT_TRUE(queue1.isEmpty());
		queue.enqueue(256);
		Queue<int16_t> queue2 = queue;
		EXPECT_EQ(queue.dequeue(), 256);
	}
}