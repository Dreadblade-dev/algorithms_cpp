#pragma once
#include <exception>

class StackEmptyException : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Stack is empty";
	}
};

class ListEmptyException : public std::exception
{
public:
	const char* what() const override
	{
		return "List is empty";
	}
};