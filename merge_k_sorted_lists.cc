/*
 * Reference:
 * http://blog.csdn.net/linhuanmars/article/details/19899259
 */

#include <iostream>
#include <vector>

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
    ListNode *mergeKLists(vector<ListNode *> &lists) 
	{
		if (lists.size() == 0 )
			return NULL;
		f(lists, 0, lists.size()-1);
    }

	ListNode *f(vector<ListNode *> &lists, int p, int r)
	{
		if (p < r) {
			int q = (p + r) / 2;
			return merge(f(lists, p, q), f(lists, q+1, r));
		}

		return lists[p];
	}

	ListNode *merge(ListNode *a, ListNode *b)
	{

		ListNode *res = new ListNode(0);
		ListNode *p = res;

		/*
		cout << "raw a:";
		for (p = a; p != NULL; p = p->next)
			cout << p->val << " ";
		cout << endl;

		cout << "raw b:";
		for (p = b; p != NULL; p = p->next)
			cout << p->val << " ";
		cout << endl;

		p = res;
		*/

		while (a!=NULL && b!=NULL) {
			if (a->val <= b->val) {
				p->next = a;
				a = a->next;
			} else {
				p->next = b;
				b = b->next;
			}
			p = p->next;
		}

		p->next = a!=NULL ? a : b;

		p = res;
		res = res->next;
		delete p;

		/*
		cout << "Result:";
		for (p = res; p != NULL; p = p->next)
			cout << p->val << " ";
		cout << endl;
		*/

		return res;
	}
};

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(5);

	ListNode *l2 = new ListNode(2);
	l2->next = new ListNode(3);
	
	vector<ListNode *> lists;
	lists.push_back(l1);
	lists.push_back(l2);

	Solution s;
	ListNode *p = s.mergeKLists(lists);

	for (; p != NULL; p = p->next)
		cout << p->val << " ";
	cout << endl;

	return 0;
}
