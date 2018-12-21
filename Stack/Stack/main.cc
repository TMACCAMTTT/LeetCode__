#include "head.h"

int main()
{
	string s = { '(', ')', '[', ']', '{'};
	//cout << isValid(s) << endl;
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	cout << queue.peek() << endl;//1
	cout << queue.pop() << endl;//1
	queue.push(3);
	cout << queue.peek() << endl;//2
	return 0;
}