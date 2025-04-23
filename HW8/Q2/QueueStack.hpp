
#ifndef QueueStack_hpp
#define QueueStack_hpp
#include "Queue.hpp"
#include "StackList.hpp"
class QueueStack : public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	~QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};

#endif


