#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		preorder(root);

		return res;
	}
	
	void preorder(TreeNode *root)
	{
		if (!root)
			return;
			
		res.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
private:
	vector<int> res;
};

class Solution2
{
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		while (true)
		{
			preorder(root);
			if (stk.empty())
				break;
			root = stk.top();
			stk.pop();
		}
		return res;
	}
	void preorder(TreeNode *root)
	{
		while (root)
		{
			res.push_back(root->val);
			if (root->right)
				stk.push(root->right);
			root = root->left;
		}
	}

private:
	vector<int> res;
	stack<TreeNode *> stk;
};

int main()
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
//	TreeNode *c = new TreeNode(3);

	a->left = b;
//	b->right = c;

	Solution2 s;
	for (auto &r : s.preorderTraversal(a))
		cout << r << " ";
	cout << endl;

	return 0;
}
