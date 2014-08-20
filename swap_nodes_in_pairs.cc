/*
 * Reference:
 * http://www.cnblogs.com/TenosDoIt/p/3793641.html
 */

#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode *swapPairs(ListNode *head) 
	{
		ListNode tmpHead(0);
		tmpHead.next = head;

		ListNode *p = &tmpHead;
		ListNode *q = head;

		while (q != NULL && q->next != NULL)
		{
			p->next = q->next;
			q->next = q->next->next;
			p->next->next = q;

			p = q;
			q = q->next;
		}

		return tmpHead.next;
	}
};

int main()
{
	ListNode no1(1);
	ListNode no2(2);
	ListNode no3(3);
	ListNode no4(4);

	ListNode *head = &no1;
	no1.next = &no2;
	no2.next = &no3;
	no3.next = &no4;

	Solution s;

	ListNode *p;
	for (p = s.swapPairs(head); p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;

	return 0;
}
