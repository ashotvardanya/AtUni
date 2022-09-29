#pragma once
#include <iostream>

template<typename T>
class AQueue
{
private:
	unsigned int maxSize;
	unsigned int rear;
	unsigned int front;
	T* arr;
public:
	AQueue();
	AQueue(unsigned int max_val);
	~AQueue();	
	void enqueue(T val);
	void dequeue();
	bool isEmpty();
	bool isFull();
	void Clear();
	T Front();
	unsigned int length();

};

template<typename T>
 AQueue<T>::AQueue(unsigned int max_val)
	: rear(0)
	, front(1)
	, maxSize(max_val)

{
	arr = (new T[maxSize]);
}

template<typename T>
AQueue<T>::AQueue()
	: AQueue(100)
{
	std::cout << "Creating a queue with 99 bins!\n";
	
}

template<typename T>
AQueue<T>::~AQueue()
{
	delete[] arr;
}

template<typename T>
void AQueue<T>::enqueue(T val)
{
	if (this->isEmpty())
	{
		rear = (rear + 1) % (maxSize );
		arr[rear] = val;
	}
	else if (!isFull())
	{
		rear= (rear + 1) % (maxSize );
		arr[rear] = val;
		
		
	}
	else
		std::cerr << "Your queue is full!\n";
}

template<typename T>
void AQueue<T>::dequeue()
{
	if (!isEmpty())
	{
		
		front= (front+1) % (maxSize-1);
		
	}
}

template<typename T>
bool AQueue<T>::isEmpty()
{
	return rear == front - 1;
}

template<typename T>
bool AQueue<T>::isFull()
{
	return ((rear + 2) % maxSize == front);
}

template<typename T>
void AQueue<T>::Clear() 
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template<typename T>
T AQueue<T>::Front()
{
	if (isEmpty())
	{
		std::cerr << "Queue is empty!\n";
		exit(0);
	}
	return arr[rear];
}

template<typename T>
unsigned int  AQueue<T>::length()
	{
	return (rear - front + 1 + maxSize)%maxSize;
	 
	}

