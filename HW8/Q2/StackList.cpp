

#include "StackList.hpp"

StackList::StackList() :data()
{
	// create and initialize a Stack based on Lists
}
StackList::StackList(const StackList& lst) : data(lst.data)
{ /* copy constructor*/
}
void StackList::clear()
{
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}
bool StackList::isEmpty() const
{ // return true if Stack is empty
	return data.isEmpty();
}
int StackList::pop()
{
	int result;
	// return and remove the intopmost element in the Stack
	// get first element in List
	try
	{
		result = data.firstElement();
	}
	catch(const char *)
	{
		throw;
	}
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}
void StackList::push(int val)
{
	// push new value onto Stack
	try 
	{
		data.add(val);
	}
	catch (const char*)
	{
		throw;
	}
}
int StackList::top()
{
	try
	{
		return data.firstElement();
	}
	catch (const char*)
	{
		throw;
	}
}

//function that moves values from one stack and places them in another stack, (in reverse order)
//recieves pointers to stacks
void trade(Stack* src, Stack* dest)
{
	//while src is not empty continue trade
	while (!src->isEmpty())
	{
		try
		{
			//push onto dest what we popped off src
			dest->push(src->pop());
		}
		catch (const char*)
		{
			throw;
		}

	}
}
