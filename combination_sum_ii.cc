#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int> &num, int target)
	{
		vector<int> solution;
		this->num = num;
		sort(this->num.begin(), this->num.end());

		DFS(solution, target, 0);

		return res;
	}

	void DFS(vector<int> &solution, int target, int start)
	{
		if (target == 0)
		{
			res.push_back(solution);
		}
		else
		{
			for (int i = start; i < num.size() && num[i] <= target; i++)
			{
				if (i > 0 && num[i] == num[i-1] && num[i-1] != solution.back())
					continue;
				solution.push_back(num[i]);
				DFS(solution, target - num[i], i + 1);
				solution.pop_back();
			}
		}
	}

private:
	vector<int> num;
	vector<vector<int>> res;
};

int main()
{
	Solution s;
	vector<int> num = {10, 1, 2, 7, 6, 1, 5};

	for (auto &i : s.combinationSum2(num, 8))
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
