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
		if (head == NULL)
			return head;

		ListNode *pre_head = new ListNode(0);
		pre_head->next = head;

		ListNode *pl, *pr;
		pl = pre_head;
		pr = head;
		while (pr != NULL)
		{
			if (pr->next != NULL && pr->val == pr->next->val)
			{
				pl = pl->next;
				pr = pr->next;
			}
			else
			{
				while (pr->next != NULL && pr->val == pr->next->val)
				{
					ListNode *temp = pr;
					pr = pr->next;
					delete temp;
				}
				pr = pr->next;
			}
		}

		ListNode *temp = pre_head;
		pre_head = pre_head->next;
		delete temp;
		return pre_head;
	}
};

int main()
{
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(3);
	ListNode *e = new ListNode(4);
	ListNode *f = new ListNode(4);
	ListNode *g = new ListNode(5);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	
	ListNode *p = a;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	Solution s;
	ListNode *res = s.deleteDuplicates(a);

	p = res;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}
