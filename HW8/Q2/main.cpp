//Avi Soclof 674098915 Homework 8 Question 2
//Purpose is to implement a stack using a queue

#include "List.hpp"
#include "QueueStack.hpp"

using namespace std;
int main() {
	Queue* Q;
	int num;
	Q = new QueueStack();
	cout << "enter 5 numbers: " << endl;
	try {
		for (int i = 0; i < 5; i++) {
			cin >> num;
			Q->enqueue(num);
		}
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first in queue is: " << Q->front() << endl;
	cout << "removing first 2 elements:" << endl;
	cout << Q->dequeue() << ' ';
	cout << Q->dequeue() << endl;
	cout << "first in queue is: " << Q->front() << endl;

	cout << "emptying out the queue: " <<  endl;
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	cout << endl;
	delete Q;
	return 0;
}
/*
 sample output
 enter 5 numbers:
100 200 300 400 500
first in queue is: 1
removing first 2 elements:
100 200
first in queue is: 3
emptying out the queue: 
300 400 500

*/
