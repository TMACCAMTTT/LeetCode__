#include "head.h"

int main()
{
	string s = { '(', ')', '[', ']', '{'};
	/*MyQueue queue;
	queue.push(1);
	queue.push(2);
	cout << queue.peek() << endl;//1
	cout << queue.pop() << endl;//1
	queue.push(3);
	cout << queue.peek() << endl;//2*/
	//vector<int> vec = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	//cout << trap(vec) << endl;
	vector<int> vec = { 1, 3, -1, -3, 5, 3, 6, 7 };
	maxSlidingWindow(vec, 3);
	return 0;
}