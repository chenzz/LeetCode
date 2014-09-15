#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *l, *r;

		l = head;
		r = head;
		for (int i = 0; i < n; i++)
			r = r->next;

		if (r == NULL)
		{
			ListNode *t = head;
			head = head->next;
			delete t;
		}
		else
		{
			while (r->next != NULL)
			{
				l = l->next;
				r = r->next;
			}
			ListNode *t = l->next;
			l->next = t->next;
			delete(t);
		}
		return head;
	}
};

int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;

	Solution s;
	ListNode *p = s.removeNthFromEnd(p1, 5);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}
