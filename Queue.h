#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int numberOfElements;
	T* data;
	void reSize(int);
public:
	Queue();
	~Queue();
	void enQueue(T);
	T deQueue();
	T getElemetAtFront();
	bool isEmpty();
	bool isFull();
	int getNumberOfElements();
	int getCapacity();
};
#endif // !QUEUE_H
