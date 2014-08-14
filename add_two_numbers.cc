#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		ListNode *res = new ListNode(0);
		ListNode *p = res;
		int carry = 0;
		int sum = 0;
		
		for (; l1!=NULL && l2!=NULL; l1 = l1->next, l2 = l2->next)
		{
			sum = l1->val + l2->val + carry;
			carry = sum / 10;
			sum = sum % 10;

			p->next = new ListNode(sum);
			p = p->next;
		}

		ListNode *l3 = NULL;
		if (l1 != NULL)
			l3 = l1;
		if (l2 != NULL)
			l3 = l2;
		for (; l3 != NULL; l3 = l3->next)
		{
			sum = l3->val + carry;
			carry = sum / 10;
			sum = sum % 10;
			p->next = new ListNode(sum);
			p = p->next;
		}

		if (carry == 1)
			p->next = new ListNode(1);
		
		ListNode *temp = res;
		res = res->next;
		delete temp;

		return res;
    }
};

int main()
{
	ListNode *l1 = new ListNode(5);
	ListNode *l2 = new ListNode(5);
	Solution s;
	ListNode *p;

	for (p = s.addTwoNumbers(l1, l2); p != NULL; p = p->next)
		cout << p->val << ' ';
	cout << endl;

	return 0;
}
