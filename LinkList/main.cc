#include "head.h"

int main()
{
	LinkList L;
	LinkList L2;
	vector<int> vec = { 1, 2, 3, 4, 5, 6 };
	for (int i = 0; i < vec.size(); i++)
	{
		ListNode *node = new ListNode(vec[i]);
		L.insert(node, i);
	}
	ListNode* head = L.reverse();
	//ListNode* head = L.swapPairs();
	//reverseKGroup()
	//L.print(head);
	ListNode* HEAD = L.reverseKGroup(head, 3);
	L.print(HEAD);
	//L.print(L.removeNthFromEnd(3));
	return 0;
}