#include <iostream>

#include "LQueue.h"


int main()
{
	LQueue<char> qu= LQueue<char>();
	qu.enqueue(5);
	qu.enqueue('8');
	qu.enqueue('j');
	qu.enqueue(7);
	qu.dequeue();
	//qu.clear();
	std::cout<<qu.length()<<'\n';
	//std::cin.get();
	LQueue<char>* p = new LQueue<char>;
	p->enqueue('h');
	std::cout << p->length() << '\n';
	delete p;
}

