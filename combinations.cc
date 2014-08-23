/*
 *  分析:
 *	Permutations那道题的简化版.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<int> solution;
		generate(n, k, solution, 1);

		return res;
	}

	void generate(int n, int k, vector<int> &solution, int step)
	{
		if (k == 0)
			res.push_back(solution);
		else
		{
			for (int i = step; i <= n-k+1; i++)
			{
				solution.push_back(i);
				generate(n, k-1, solution, i+1);
				solution.pop_back();
			}
		}

		return;
	}

	vector<vector<int>> res;
};

int main()
{
	Solution s;
	for (auto &i : s.combine(4, 2))
	{
		for (auto &j : i)
			cout << j << ' ';
		cout << endl;
	}

	return 0;
}
