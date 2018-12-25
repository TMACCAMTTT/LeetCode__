#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

class MyQueue {
//232, 用两个栈实现队列，考虑stackOut是否为空，而不是stackIn;
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
};//232//225
class MyStack {
	//225,用队列实现栈：queue_b为辅助队列。
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
};//225//232
class KthLargest {
	//703返回数据流中第K大的元素，用优先队列，选择小顶堆。堆顶元素为堆中最小值，也就是数据流中第k大的值。新来一个数将其与堆顶元素比较，若大于堆顶元素则插入。
public:
	KthLargest(int k, vector<int> nums) {
		size = k;
		for (int i = 0; i < nums.size(); i++)
		{
			pq.push(nums[i]);
			if (pq.size() > size) {
				pq.pop();
			}
		}
	}

	int add(int val) {
		if (pq.size() < size || val > pq.top()) {
			pq.push(val);
		}
		if (pq.size() > size) {
			pq.pop();
		}
		return pq.top();
	}
private:
	priority_queue<int, vector<int>, greater<int> > pq;
	int size;
};//703//703

vector<int> twoSum(vector<int>& nums, int target);//1.two sum
vector<vector<int>> threeSum(vector<int>& nums);//15.three sum
int threeSumClosest(vector<int>& nums, int target);//16.three sum closet
vector<vector<int>> kSum(vector<int>& nums, int k, int index, int target);//kSum
vector<vector<int>> fourSumRecursive(vector<int>& nums, int target);//递归
vector<vector<int>> fourSum(vector<int>& nums, int target);//18.手动去重
bool isValid(string s);//20.括号匹配
int trap(vector<int>& height);//42.收集雨水
int calculate(string s);//224.基本计算器
vector<int> maxSlidingWindow(vector<int>& nums, int k);//239.滑动窗口最大值
bool isAnagram(string s, string t);//242.valid anagram
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);//454.4 sum II
int fourSumCountHash(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);//454 哈希表解法
int maxWidthRamp(vector<int>& A);//962.待定