#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		if (candidates.size() == 0)
			return res;
		this->candidates = candidates;
		sort(this->candidates.begin(), this->candidates.end());
		vector<int> solution;

		DFS(solution, 0, target);

		return res;
	}
	void DFS(vector<int> &solution, int start, int target)
	{
		if (target == 0)
			res.push_back(solution);
		else
		{
			for (int i = start; i < candidates.size() && candidates[i] <= target; i++)
			{
				solution.push_back(candidates[i]);
				DFS(solution, i, target-candidates[i]);
				solution.pop_back();
			}
		}
	}
private:
	vector<int> candidates;
	vector<vector<int>> res;
};

int main()
{
	Solution s;
	vector<int> candidates = {2, 3, 6, 7};
	for (auto &x : s.combinationSum(candidates, 7))
	{
		for (auto &y : x)
			cout << y << " ";
		cout << endl;
	}

	return 0;
}
