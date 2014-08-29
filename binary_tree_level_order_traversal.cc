#include <iostream>
#include <vector>
#include <queue>

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
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		queue<TreeNode*> nodeQue;
		queue<int> depQue;
		TreeNode *node;
		int dep;
		int depBefore;
		vector<vector<int>> res;
		vector<int> solution;

		if (!root)
			return res;

		nodeQue.push(root);
		depQue.push(1);
		depBefore = 1;
		while (!nodeQue.empty())
		{
			node = nodeQue.front();
			nodeQue.pop();
			dep = depQue.front();
			depQue.pop();

			if (dep == depBefore)
				solution.push_back(node->val);
			else
			{
				res.push_back(solution);
				depBefore = dep;
				solution.clear();
				solution.push_back(node->val);
			}

			if (node->left)
			{
				nodeQue.push(node->left);
				depQue.push(dep + 1);
			}
			if (node->right)
			{
				nodeQue.push(node->right);
				depQue.push(dep + 1);
			}
		}
		res.push_back(solution);
		return res;
	}
};

int main()
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	a->left = b;
	a->right = c;

	Solution s;
	for (auto &i : s.levelOrder(a))
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	

	return 0;
}
