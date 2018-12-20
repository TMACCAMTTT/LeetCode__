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
	//
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

ListNode* LinkList::addTwoNumbers(LinkList l1, LinkList l2) {
	//12������ӣ�carry��ʾ��λ��ȡֵ0��1��������ָ��ͬʱ������ֻҪ����ȫΪ�գ��Ͱ�λ��ӣ���ǰ���ֵΪsum%10����λΪsum/10��������һ��Ϊ��ʱ����ֵΪ0��������ӣ�
	//ÿһ�ֵ���֮�����pq����ȫΪ�գ����ʾ��һλ������ֵ�����Ǵ����½�㣬������һ�ֵ���������ֵ��
	ListNode* dummyHead = new ListNode(-1);
	int carry = 0;
	ListNode* curr = dummyHead;
	ListNode* p = l1.head;
	ListNode* q = l2.head;
	while (p != NULL || q != NULL)
	{
		int x = p ? p->val : 0;
		int y = q ? q->val : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		curr->val = sum % 10;
		if (p) {
			p = p->next;
		}
		if (q) {
			q = q->next;
		}
		if (!(!p && !q)) {
			curr->next = new ListNode(-1);
			curr = curr->next;
		}
		
	}
	if (carry == 1) {
		curr->next = new ListNode(1);
	}
	return dummyHead;
}

ListNode* LinkList::removeNthFromEnd(int n) {
	//19ɾ����������n����㣬�ÿ���ָ�룡��������ָ������n������ʱ��ָ��Ҳ�ߣ�����ָ�뵽��β���ʱ����ָ�뵽���ɾ������ǰ����㡣
	//��ͨ�㷨
	/*ListNode* curr = head;
	int length = 0;
	while (curr != NULL) {
		curr = curr->next;
		length++;
	}
	curr = head;
	if (length == n) {
		return curr->next;
	}
	for (int i = 1; i < length - n; i++)
	{
		curr = curr->next;
	}
	curr->next = curr->next->next;
	return head;*/
	//����ָ�룬ע����������Ĵ���ɾ����һ�����ʱ��
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* res = new ListNode(-1);
	res->next = slow;
	for (int i = 0; i < n; i++)
	{
		fast = fast->next;
	}
	if (!fast) {
		return head->next;
	}
	while (fast->next) {
		fast = fast->next;
		slow = slow->next;
	}
	slow->next = slow->next->next;
	return res->next;
}

ListNode* LinkList::reverseKGroup(ListNode* head, int k) 
{
	//25   ��countΪk�ı���ʱ����ʼ��ת��һ�飻���ȱ�����һ���ͷ��㣬Ȼ��ת��һ�飬���ط�ת���ͷ��㣬
	//����ͷ���������dummy��Ȼ�����dummyΪ�ѷ�ת����������һ����㣬Ҳ������������תǰ��ͷ��㣻����currΪ��һ���ͷ��㣬
	//����headΪ��һ���ͷ��㣻ȡ��һ�������β�����Ϊ��󷵻صĽ�㡣
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
			dummy = head;//����dummy
			if (count / k == 1)
			{
				HEAD = curr;
			}
			curr = nextHead;//����currΪ��һ�������ͷ���
			head = curr;//����headΪ��һ�������ͷ���
		}
		else {
			curr = curr->next;
		}
	}
	return HEAD;
}

ListNode* LinkList::reverseOneGroup(ListNode* head, ListNode* last)
{
	//��ÿ������ת������Ϊ��ǰ���������ͷ����β���

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


