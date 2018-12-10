#include "head.h"
void LinkList::insert(ListNode* node, int position)
{
	if (head == NULL) {
		head = node;
		return;
	}
	if (position == 0) {
		node->next = head;
		head = node;
		return;
	}
	ListNode* curr = head;
	int i = 0;
	while (curr->next != NULL && i < position - 1)
	{
		curr = curr->next;
		i++;
	}
	if (i == position - 1) {
		node->next = curr->next;
		curr->next = node;
		return;
	}
}

void LinkList::print()
{
	ListNode* curr = head;
	while (curr != NULL)
	{
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
	cout << "print done" << endl;
}

void LinkList:: print(ListNode* head)
{
	ListNode* curr = head;
	while (curr != NULL)
	{
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
	cout << "print done" << endl;
}

ListNode* LinkList::reverse()
{
	//nextTemp�Ķ��岻�ܷ���ѭ���ڣ����������
	//����������Ҫһ��ָ��洢��ǰ���ĺ�̽�㣬����Ҫһ��ָ��洢��ǰ����ǰ����㡣
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* nextTemp = NULL;
	while(curr != NULL)
	{
		nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	head = prev;
	return head;
	//�ݹ鷨�����headҪָ��NULL��
	/*ListNode *newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;*/
}

ListNode* LinkList::swapPairs() {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* curr = head;
	head = curr->next;
	ListNode* nextTemp = head;
	ListNode* prevTemp = head;
	while (curr != NULL && curr->next != NULL)
	{
		nextTemp = curr->next->next;//save the node curr->next->next;
		prevTemp->next = curr->next;//link the rest to prevTemp;
		curr->next->next = curr;//swap
		prevTemp = curr;//save prevTemp;
		curr->next = nextTemp;
		curr = nextTemp;
	}
	return head;
}

ListNode* LinkList::reverseKGroup(ListNode* head, int k) {
	//25��תÿһ��ǰ��������һ���ǰ����㣬Ȼ�󽫷�ת�����һ��������ǰ�����,������ǰ�����Ϊ��������תǰ��ͷ���,�ұ�����һ�������ͷ��㡣
	int count = 0;
	ListNode* curr = head;
	ListNode* dummy = new ListNode(-1);
	
	ListNode* nextHead = curr;
	ListNode* HEAD = NULL;
	while (curr != NULL)
	{
		//curr = curr->next;
		count++;
		if (count % k == 0) {
			nextHead = curr->next;//������һ���ͷ���
			dummy->next = reverseOneGroup(head, curr);
			dummy = head;
			if (count / k == 1)
			{
				HEAD = curr;
			}
			curr = nextHead;
			head = curr;//����head
		}
		else {
			curr = curr->next;
		}
	}
	return HEAD;
}

ListNode* LinkList::reverseOneGroup(ListNode* head, ListNode* last)
{
	//��ÿ������ת��������ת���������������תǰ����ͷ�ڵ��ǰ���ڵ��

	ListNode* curr = head;
	ListNode* prev = NULL;
	ListNode* nextTemp = NULL;
	ListNode* stop = last->next;
	while (curr != stop)
	{
		nextTemp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextTemp;
	}
	return last;
}

bool hasCycle(ListNode *head) {
	//141����һ���ڵ���Ϊ��,�������ָ��˼�룬�ȸ������ж�
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

ListNode *detectCycle(ListNode *head) {
	//142����һ������ָ�룺������ָ������ʱ����ǰ�ڵ㵽���е�һ���ڵ������
	//ͷ�ڵ㵽���е�һ���ڵ�ľ�����ȡ�
	/*ListNode* fast = head;
	ListNode* slow = head;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow){
			 while(head != slow)
			 {
				head = head->next;
				slow = slow->next;
			 }
			 return head;
		}
	}
	return NULL;*/
	//�����������߹������н��ֵ��Ϊ������ٴ�������Ϊ���ĵ�һ����㡣
	while (head != NULL)
	{
		if (head->val == INT_MAX) {
			return head;
		}
		head->val = INT_MAX;
		head = head->next;
	}
	return NULL;
}


