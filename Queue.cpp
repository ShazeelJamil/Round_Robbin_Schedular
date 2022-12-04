#include"Queue.h"
#include<iostream>
using namespace std;
template<typename T>
Queue<T>::Queue()
{
	data = nullptr;
	rear = 0;
	front = 0;
	numberOfElements = 0;
	capacity = 0;
}
template<typename T>
Queue<T>::~Queue()
{
	if (data)
		delete[] data;
	data = nullptr;
	rear = 0;
	front = 0;
	numberOfElements = 0;
	capacity = 0;
}
template<typename T>
void Queue<T>::enQueue(T p)
{
	if (isEmpty())
		reSize(1);
	if (isFull())
		reSize(capacity * 2);
	if (front == capacity && rear > 0)
	{
		front = 0;
		data[front] = p;
		front++;
		numberOfElements++;
	}
	else
	{
		data[front] = p;
		front++;
		numberOfElements++;
	}
	
}
template<typename T>
T Queue<T>::deQueue()
{
	if (!data)
		exit(0);
	if (rear == capacity && front < rear)
	{
		rear = 0;
		numberOfElements--;
		return data[numberOfElements];
	}
	else
	{
		rear++;
		numberOfElements--;
		return data[rear - 1];
	}
}
template<typename T>
T Queue<T>::getElemetAtFront()
{
	return data[front - 1];
}
template<typename T>
bool Queue<T>::isEmpty()
{
	return (numberOfElements == 0 ? true : false);
}
template<typename T>
bool Queue<T>::isFull()
{
	return(numberOfElements == capacity ? true : false);
}
template<typename T>
int Queue<T>::getNumberOfElements()
{
	return numberOfElements;
}
template<typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}
template<typename T>
void Queue<T>::reSize(int ns)
{
	if (ns <= 0)
	{
		this->~Queue();
		return;
	}
	T* temp = new T[ns];
	int j = 0;
	for (int i = rear; i < numberOfElements; i++)
	{
		temp[j] = data[i % capacity];
		j++;
	}
	/*if (front > rear)
	{
		for (int i = rear; i < front; i++)
			temp[i] = data[i];
	}
	else
	{
		int j = 0;
		for (int i = rear; i < capacity; i++, j++)
			temp[j] = data[i];
		for (int i = 0; i < rear; i++, j++)
			temp[j] = data[i];
	}*/
	rear = 0;
	front = numberOfElements;
	capacity = ns;
	delete[] data;
	data = temp;
	temp = nullptr;
}