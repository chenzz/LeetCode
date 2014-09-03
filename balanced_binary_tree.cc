#include <iostream>

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
	bool isBalanced(TreeNode *root)
	{
		if (root == NULL)
			return true;

		int l = depth(root->left);
		int r = depth(root->right);

		if (l-r > -2 && l-r < 2 
				&& isBalanced(root->left)
				&& isBalanced(root->right))
			return true;
		else
			return false;
	}

	int depth(TreeNode *root)
	{
		if (!root)
			return -1;
		else
			return max(depth(root->left), depth(root->right)) + 1;
	}
};

class Solution2
{
public:
	bool isBalanced(TreeNode *root)
	{
		if (root == NULL)
			return true;
		else if (depth(root) == -2)
			return false;
		else
			return true;
	}

	int depth(TreeNode *node)
	{
		if (node == NULL)
			return -1;

		int left = depth(node->left);
		if (left == -2)
			return -2;

		int right = depth(node->right);
		if (right == -2)
			return -2;

		if (left-right>1 || left-right<-1)
			return -2;

		return max(left, right) + 1;
	}
};

int main()
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	a->right = b;
	b->right = c;

	Solution2 s;
	cout << s.isBalanced(a) << endl;

	return 0;
}
