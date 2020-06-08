#include "../stack.h"
#include <gtest/gtest.h>

namespace StackTest
{
	TEST(StackTest, StackCreatesEmpty)
	{
		Stack<int16_t> stack;
		EXPECT_EQ(stack.getSize(), 0);
		EXPECT_TRUE(stack.isEmpty());
		EXPECT_THROW(stack.pop(), StackEmptyException);
	}

	TEST(StackTest, StackCreatesWithNoData)
	{
		Stack<int16_t> stack;
		EXPECT_THROW(stack.pop(), StackEmptyException);
	}

	TEST(StackTest, StackClears)
	{
		Stack<int16_t> stack;
		for (int i = 0; i < 256; i++)
		{
			stack.push_back(i);
		}
		stack.clear();
		EXPECT_TRUE(stack.isEmpty());
	}
	
	TEST(StackTest, StackReallocate)
	{
		Stack<int16_t> stack;
		for (int i = 0; i < 31; i++)
		{
			stack.push_back(i);
		}
		EXPECT_EQ(stack.getCapacity(), 32);
		stack.push_back(1);
		EXPECT_EQ(stack.getSize(), 32);
		stack.push_back(1);
		EXPECT_EQ(stack.getCapacity(), 48);
	}

	TEST(StackTest, StackReallocateExpand)
	{
		Stack<int16_t> stack;
		for (int i = 0; i < 32; i++)
		{
			stack.push_back(i);
		}

		stack.reallocate(256);
		EXPECT_EQ(stack.getSize(), 32);
		EXPECT_EQ(stack.getCapacity(), 256);
	}

	TEST(StackTest, StackReallocateNarrow)
	{
		Stack<int16_t> stack;
		for (int i = 0; i < 256; i++)
		{
			stack.push_back(i);
		}

		stack.reallocate(16);
		EXPECT_EQ(stack.getCapacity(), 16);
		EXPECT_EQ(stack.getSize(), 16);
		EXPECT_EQ(stack.peek(), 15);
	}

	TEST(StackTest, StackDecreasingCapacityAfterReallocating)
	{
		Stack<int16_t> stack;
		for (int i = 0; i < 32; i++)
		{
			stack.push_back(i);
		}

		stack.reallocate(256);
		EXPECT_EQ(stack.getCapacity(), 256);
		stack.pop();
		EXPECT_EQ(stack.getCapacity(), 128);
		EXPECT_EQ(stack.getSize(), 31);
		stack.pop();
		EXPECT_EQ(stack.getCapacity(), 64);
	}
	TEST(StackTest, StackPushBack)
	{
		Stack<int16_t> stack;

		for (int i = 0; i <= 64; i++)
		{
			stack.push_back(i);
			EXPECT_EQ(stack.pop(), i);
		}
			

		EXPECT_TRUE(stack.isEmpty());
	}

	TEST(StackTest, StackPeek)
	{
		Stack<int16_t> stack;

		for (int i = 0; i <= 64; i++)
		{
			stack.push_back(i);
		}

		for (int i = 64; i >= 0; i--)
		{
			stack.reallocate(i + 1);
			EXPECT_EQ(stack.peek(), i);
		}

		stack.pop();
		
		EXPECT_TRUE(stack.isEmpty());
	}

	TEST(StackTest, StackEqualOperator)
	{
		Stack<int16_t> stack1;
		Stack<int16_t> stack2 = stack1;
		EXPECT_EQ(stack1.isEmpty(), stack2.isEmpty());
		for (int i = 0; i < 256; i++)
		{
			stack1.push_back(i);
		}

		stack2 = stack1;

		EXPECT_EQ(stack1.getSize(), stack2.getSize());
		EXPECT_EQ(stack1.getCapacity(), stack2.getCapacity());
		EXPECT_EQ(stack1.peek(), stack2.peek());
	}

	TEST(StackTest, StackCopyConstructor)
	{
		Stack<int16_t> stack1;
		Stack<int16_t> stack2(stack1);
		EXPECT_EQ(stack1.isEmpty(), stack2.isEmpty());
		for (int i = 0; i < 256; i++)
		{
			stack1.push_back(i);
		}

		Stack<int16_t> stack3(stack1);

		EXPECT_EQ(stack3.getSize(), stack1.getSize());
		EXPECT_EQ(stack3.getCapacity(), stack1.getCapacity());
		EXPECT_EQ(stack3.peek(), stack1.peek());
	}
}