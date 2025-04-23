
#ifndef StackList_hpp
#define StackList_hpp

#include "Stack.hpp"
#include "List.hpp"
class StackList : public Stack
{
public:
	StackList();
	StackList(const StackList&);
	// Stack operations
	void clear()override;
	bool isEmpty() const override;
	int pop()override;
	void push(int value) override;
	int top()override;
protected:
	// data fields
	List data;
};

//function that moves values from one stack and places them in another stack, (in reverse order)
//recieves pointers to stacks
void trade (Stack*, Stack*);

#endif
