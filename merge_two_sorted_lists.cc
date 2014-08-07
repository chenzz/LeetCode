#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

//Solution 1: Most clumsy and ugly solution, isn't recommended.
//Don't use any skill.
class Solution
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode*l2)
	{
		ListNode *l3 = NULL;

		if (l1 == NULL)
		{
			l3 = l2;
			return l3;
		}
		if (l2 == NULL)
		{
			l3 = l1;
			return l3;
		}
		
		if (l1->val < l2->val)
		{
			l3 = l1;
			l1 = l1->next;
		}
		else
		{
			l3 = l2;
			l2 = l2->next;
		}

		ListNode *p = l3;
		while (l1!=NULL && l2!=NULL)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}

		p->next = l1!=NULL ? l1:l2;

		return l3;
	}
};

//Solution 2 : smarter solution
//Create a head node first to decrease the complexity.
//Remove the head node at last.
class Solution2
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
	{
		ListNode *l3 = new ListNode(0);
		ListNode *p = l3;

		while (l1!=0 && l2!=0)
		{
			if (l1->val <= l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}

		p->next = l1 != NULL ? l1 : l2;

		p = l3;
		l3 = l3->next;
		delete p;
		
		return l3;
	}
};


//Solution 3 : most smart solution.
//Use the second level pointer to solve the problem.
class Solution3
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode *l3;
		ListNode **pp = &l3;

		while (l1!=NULL && l2!=NULL)
		{
			if (l1->val < l2->val)
			{
				*pp = l1;
				l1 = l1->next;
			}
			else
			{
				*pp = l2;
				l2 = l2->next;
			}
			pp = &((*pp)->next);
		}

		*pp = l1!=NULL ? l1:l2;

		return l3;
	}
};

int main()
{

	return 0;
}
