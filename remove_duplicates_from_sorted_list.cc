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
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *p = head;
		while (p != NULL && p->next != NULL)
		{
			if (p->val == p->next->val)
			{
				ListNode *temp = p->next;
				p->next = p->next->next;
				delete temp;
			}
			else
				p = p->next;
		}
		return head;
	}
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(1);
	ListNode *c = new ListNode(1);
	ListNode *d = new ListNode(3);
	ListNode *e = new ListNode(3);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;

	Solution s;
	a = s.deleteDuplicates(a);
	while (a != NULL)
	{
		cout << a->val << " ";
		a = a->next;
	}

	return 0;
}
