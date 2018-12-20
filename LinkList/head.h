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

	ListNode* addTwoNumbers(LinkList l1, LinkList l2);//2两数相加
	ListNode* removeNthFromEnd(int n);//19移除倒数第n个结点
	ListNode* reverseKGroup(ListNode* head, int k);//25以K个为一组翻转链表
	ListNode* reverseOneGroup(ListNode* head, ListNode* last);//翻转一组链表
	ListNode* reverse();//206反转链表，head置为空指针
	ListNode* swapPairs();//24成对交换链表中结点
private:
	ListNode *head;
};


bool hasCycle(ListNode *head);//141检测是否有环
ListNode *detectCycle(ListNode *head);//142检测是否有环，并返回环的第一个结点
