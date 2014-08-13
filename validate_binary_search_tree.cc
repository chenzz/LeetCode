#include <iostream>
#include <climits>

using namespace std;

// Definition for binary tree
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
    bool isValidBST(TreeNode *root) 
	{
		isValidBST(root, INT_MIN, INT_MAX);
    }

	bool isValidBST(TreeNode *root, int min, int max)
	{
		if (!root)
			return true;

		return ((root->val > min)
			&& (root->val < max)
			&& isValidBST(root->left, min, root->val)
			&& isValidBST(root->right, root->val, max));
	}
};

int main()
{
	TreeNode *root = new TreeNode(0);
	TreeNode *right = new TreeNode(-1);

	root->left = NULL;
	root->right = right;

	Solution s;
	cout << s.isValidBST(root) << endl;

	return 0;
}

