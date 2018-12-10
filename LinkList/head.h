#pragma once
#include <iostream>
#include <vector>
using namespace std;
//Definition for singly linked list:
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkList {
public:
	LinkList()
	{
		head = NULL;
	}
	void insert(ListNode* node, int position);
	void delete_node(int position);
	void print();
	void print(ListNode* head);
	ListNode* reverseKGroup(ListNode* head, int k);//25
	ListNode* reverseOneGroup(ListNode* head, ListNode* last);
	ListNode* reverse();//206反转链表，head置为空指针
	ListNode* swapPairs();//24成对交换链表中结点
private:
	ListNode *head;
};


bool hasCycle(ListNode *head);//141
ListNode *detectCycle(ListNode *head);//142
