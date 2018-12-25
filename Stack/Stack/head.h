#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
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
};//232//225
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
};//225//232
class KthLargest {
	//703�����������е�K���Ԫ�أ������ȶ��У�ѡ��С���ѡ��Ѷ�Ԫ��Ϊ������Сֵ��Ҳ�����������е�k���ֵ������һ����������Ѷ�Ԫ�رȽϣ������ڶѶ�Ԫ������롣
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
vector<vector<int>> fourSumRecursive(vector<int>& nums, int target);//�ݹ�
vector<vector<int>> fourSum(vector<int>& nums, int target);//18.�ֶ�ȥ��
bool isValid(string s);//20.����ƥ��
int trap(vector<int>& height);//42.�ռ���ˮ
int calculate(string s);//224.����������
vector<int> maxSlidingWindow(vector<int>& nums, int k);//239.�����������ֵ
bool isAnagram(string s, string t);//242.valid anagram
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);//454.4 sum II
int fourSumCountHash(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);//454 ��ϣ��ⷨ
int maxWidthRamp(vector<int>& A);//962.����