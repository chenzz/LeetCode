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
	ListNode *partition(ListNode *head, int x)
	{
		struct ListNode *less = new struct ListNode(0);
		struct ListNode *equal_or_greater = new struct ListNode(0);
		struct ListNode *ph, *pl, *pe;

		ph = head;
		pl = less;
		pe = equal_or_greater;
		//partition list into the two lists
		while (ph != NULL)
		{
			if (ph->val < x)
			{
				pl->next = ph;
				pl = pl->next;
				ph = ph->next;
			}
			else
			{
				pe->next = ph;
				pe = pe->next;
				ph = ph->next;
			}
		}

		//link the two lists
		pl->next = equal_or_greater->next;
		pe->next = NULL;

		//delete first node of the two lists
		struct ListNode *temp;
		temp = less;
		less = less->next;
		delete temp;
		delete equal_or_greater;
	
		return less;
	}
};

int main()
{
	struct ListNode *a = new struct ListNode(1);
	struct ListNode *b = new struct ListNode(4);
	struct ListNode *c = new struct ListNode(3);
	struct ListNode *d = new struct ListNode(2);
	struct ListNode *e = new struct ListNode(5);
	struct ListNode *f = new struct ListNode(2);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = NULL;
	Solution s;

	for (struct ListNode *p = s.partition(a, 3); p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;

	return 0;
}
