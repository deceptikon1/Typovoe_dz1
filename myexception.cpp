// Copyright 2015 <Sergey Fedotov>
#include <iostream>
#include <exception>

class myexception : public std::exception
{
public:
	myexception(const char *str) : std::exception(str)
	{
	}	
};