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