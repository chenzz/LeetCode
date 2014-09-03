#include <iostream>
#include <vector>

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
	vector<int> postorderTraversal(TreeNode *root)
	{
		postorder(root);

		return res;
	}

	void postorder(TreeNode *root)
	{
		if (!root)
			return;
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		res.push_back(root->val);

		return;
	}

private:
	vector<int> res;
};

int main()
{
	
	return 0;
}
