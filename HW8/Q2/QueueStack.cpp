#include "QueueStack.hpp"

QueueStack::QueueStack()
{
	data = new StackList;
}

//destructor
QueueStack::~QueueStack()
{
	delete data;
}

//clear
void QueueStack::clear()
{
	data->clear();
}

//remove first element
int QueueStack::dequeue()
{
	int val;
	
	//try obtaining first element and assigning it to val
	try
	{
		val = front();
	}
	catch (const char*)
	{
		throw;
	}

	//create a helper stack
	Stack* helper = new StackList; //this implementation for easy if we decided to use a different implementation
	
	//try trade function
	try
	{
		trade(data, helper);
	}
	catch (const char*)
	{
		delete helper;
		throw;
	}
	 //pop from helper to remove first element
	 helper->pop();

	//return values into data
	//try trade function
	 try
	 {
		 trade(helper, data);
	 }
	 catch (const char*)
	 {
		 delete helper;
		 throw;
	 }

	//delete helper and return val
	delete helper;
	
	return val;
}

//add values to the stack
void QueueStack::enqueue(int value)
{
	//simply push the value onto the stack
	try
	{
		data->push(value);
	}
	catch (const char*)
	{
		throw;
	}

	return;
}

//return the first element 
int QueueStack::front()
{
	int val;
	Stack* helper = new StackList;

	//try trade function
	try
	{
		trade(data, helper);
	}
	catch (const char*)
	{
		delete helper;
		throw;
	}

	//try to obtain first element by using top method of stack
	try
	{
		val = helper->top();
	}
	catch (const char*)
	{
		delete helper;
		throw;
	}

	//return values into data
	//try trade function
	try
	{
		trade(helper, data);
	}
	catch (const char*)
	{
		delete helper;
		throw;
	}

	delete helper;
	return val;

}

//return if stack has values or not
bool QueueStack::isEmpty() const
{
	//use the stack isempty method
	return data->isEmpty();
}

