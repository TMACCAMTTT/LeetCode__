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
	//25翻转每一组前，保存这一组的前驱结点，然后将翻转后的这一组链接至前驱结点,并更新前驱结点为这组链表翻转前的头结点,且保存下一组链表的头结点。
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
			dummy = head;
			if (count / k == 1)
			{
				HEAD = curr;
			}
			curr = nextHead;
			head = curr;//更新head
		}
		else {
			curr = curr->next;
		}
	}
	return HEAD;
}

ListNode* LinkList::reverseOneGroup(ListNode* head, ListNode* last)
{
	//对每组链表反转，并将反转后的链表链接至反转前链表头节点的前驱节点后；

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


