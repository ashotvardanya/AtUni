#pragma once
#include <iostream>
template <typename T>
struct Node {
	int data;
	struct Node<T>* next;

	Node(T var)
		: data(var)
		, next(nullptr)
	{}
	Node():Node(0)
	{}
	~Node(){}
};


template <typename T>
class LQueue:public Node<T>
{
public:
	LQueue();	
	bool isEmpty();
	void enqueue(T val);
	void dequeue();
	void clear();
	T Front();
	unsigned int length();
	~LQueue();
private:
	Node<T>* front;
	Node<T>* rear;
};

template<typename T>
LQueue<T>::LQueue()
	: front(nullptr) 
	, rear (nullptr)
{}

template<typename T>
void LQueue<T>::enqueue(T val)

{
	if (!isEmpty())
	{
		Node<T> * p = new Node<T>(val);
		rear->next = p;
		rear = p;
	}
	else
	{
		Node<T>* p = new Node<T>(val);
		rear = p;
		front = p;
	}
}

template<typename T>
void LQueue<T>::dequeue()

{
	Node<T>* temp = front;
	front = front->next;
	delete temp;
}

template<typename T>
bool LQueue<T>::isEmpty()
{
	return front == nullptr && rear == nullptr;
}

template<typename T>
void LQueue<T>::clear()
{
	while (front != nullptr)
	{
		Node<T>* temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
}

template <typename T>
T LQueue<T>::Front()
{
	return front->data;
}

template <typename T>
unsigned int LQueue<T>::length()
{
	if (isEmpty())
		return 0;
	unsigned int count = 0;
	Node<T>* p = front;
	while (p != nullptr)
	{
		p = p->next;
		count++;
	}
	return count;
}

template<typename T>
LQueue<T>::~LQueue()
{
	if (!isEmpty())
		clear();
}