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

	ListNode* addTwoNumbers(LinkList l1, LinkList l2);//2�������
	ListNode* removeNthFromEnd(int n);//19�Ƴ�������n�����
	ListNode* reverseKGroup(ListNode* head, int k);//25��K��Ϊһ�鷭ת����
	ListNode* reverseOneGroup(ListNode* head, ListNode* last);//��תһ������
	ListNode* reverse();//206��ת����head��Ϊ��ָ��
	ListNode* swapPairs();//24�ɶԽ��������н��
private:
	ListNode *head;
};


bool hasCycle(ListNode *head);//141����Ƿ��л�
ListNode *detectCycle(ListNode *head);//142����Ƿ��л��������ػ��ĵ�һ�����
