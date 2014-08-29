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
	int sumNumbers(TreeNode *root)
	{
		int solution = 0;

		if (!root)
			return 0;
		dfs(root, solution);

		return sum;
	}

	void dfs(TreeNode *root, int solution)
	{
		if (!root->left && !root->right)
		{
			solution = solution * 10 + root->val;
			sum += solution;
		}
		else
		{
			solution = solution * 10 + root->val;
			if (root->left)
				dfs(root->left, solution);
			if (root->right)
				dfs(root->right, solution);
		}
	}

private:
	int sum = 0;
};

int main()
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	a->left = b;
	a->right = c;

	Solution s;
	cout << s.sumNumbers(a) << endl;

	return 0;
}
