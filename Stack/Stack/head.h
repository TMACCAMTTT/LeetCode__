#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

class MyQueue {
	//232, ������ջʵ�ֶ��У�����stackOut�Ƿ�Ϊ�գ�������stackIn;
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stackIn.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stackOut.empty()) {
			while (!stackIn.empty()) {
				stackOut.push(stackIn.top());
				stackIn.pop();
			}
		}
		int y = stackOut.top();
		stackOut.pop();
		return y;
	}

	/** Get the front element. */
	int peek() {
		if (stackOut.empty()) {
			while (!stackIn.empty()) {
				stackOut.push(stackIn.top());
				stackIn.pop();
			}
		}
		return stackOut.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stackIn.empty() && stackOut.empty();
	}

private:
	stack<int> stackIn, stackOut;
};
class MyStack {
	//225,�ö���ʵ��ջ��queue_bΪ�������С�
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		queue_a.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (queue_a.size() > 1) {
			queue_b.push(queue_a.front());
			queue_a.pop();
		}
		int y = queue_a.front();
		queue_a.pop();
		while (!queue_b.empty()) {
			queue_a.push(queue_b.front());
			queue_b.pop();
		}
		return y;
	}

	/** Get the top element. */
	int top() {
		while (queue_a.size() > 1) {
			queue_b.push(queue_a.front());
			queue_a.pop();
		}
		int y = queue_a.front();
		queue_a.pop();
		queue_b.push(y);
		while (!queue_b.empty()) {
			queue_a.push(queue_b.front());
			queue_b.pop();
		}
		return y;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return queue_a.empty();
	}
private:
	queue<int> queue_a, queue_b;
};


bool isValid(string s);//20����ƥ��
