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
	//nextTemp的定义不能放在循环内，否则很慢。
	//迭代法：需要一个指针存储当前结点的后继结点，还需要一个指针存储当前结点的前驱结点。
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
	//递归法：最后head要指向NULL。
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
	//12两数相加，carry表示进位，取值0或1；用两个指针同时迭代，只要不是全为空，就按位相加，当前结点值为sum%10，进位为sum/10；当其中一个为空时，设值为0，虚拟相加；
	//每一轮迭代之后，如果pq不是全为空，则表示下一位还会有值，于是创建新结点，并在下一轮迭代给它赋值。
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
	//19删除链表倒数第n个结点，用快慢指针！！！！快指针先走n步，此时慢指针也走，当快指针到达尾结点时，慢指针到达待删除结点的前驱结点。
	//普通算法
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
	//快慢指针，注意特殊情况的处理：删除第一个结点时。
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
	//25   当count为k的倍数时，开始翻转这一组；首先保存下一组的头结点，然后翻转这一组，返回翻转后的头结点，
	//并将头结点链接至dummy；然后更新dummy为已翻转的链表的最后一个结点，也就是这组链表翻转前的头结点；更新curr为下一组的头结点，
	//更新head为下一组的头结点；取第一组链表的尾结点作为最后返回的结点。
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
			nextHead = curr->next;//保存下一组的头结点
			dummy->next = reverseOneGroup(head, curr);
			dummy = head;//更新dummy
			if (count / k == 1)
			{
				HEAD = curr;
			}
			curr = nextHead;//更新curr为下一组链表的头结点
			head = curr;//更新head为下一组链表的头结点
		}
		else {
			curr = curr->next;
		}
	}
	return HEAD;
}

ListNode* LinkList::reverseOneGroup(ListNode* head, ListNode* last)
{
	//对每组链表反转，输入为当前这组链表的头结点和尾结点

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
	//141仅有一个节点则为环,经典快慢指针思想，先更新再判断
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
	//142方法一，快慢指针：当快慢指针相遇时，当前节点到环中第一个节点距离与
	//头节点到环中第一个节点的距离相等。
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
	//方法二：将走过的所有结点值置为最大，若再次遇到则为环的第一个结点。
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


