#include <iostream>
#include "Queue.h"


int main()
{

	AQueue<char> qu(7);
	
	qu.enqueue(4);
	qu.enqueue(8);
	qu.enqueue('4');
	qu.enqueue('8');
	qu.enqueue('y');
	qu.enqueue('i');
	
	qu.dequeue();
	qu.dequeue();	
	qu.dequeue();
	qu.enqueue('#');
	qu.enqueue('8');
	qu.enqueue('y');
	qu.enqueue('%');
	qu.Clear();
	std::cout<<qu.isEmpty() << std::endl;
	qu.enqueue('n');
	char ch = qu.Front();
	std::cout << ch << std::endl;
}
