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

		DFS(solution, target, 0);

		return res;
	}
	void DFS(vector<int> &solution, int target, int start)
	{
		if (target == 0)
			res.push_back(solution);
		else
		{
			for (int i = start; i < candidates.size() && candidates[i] <= target; i++)
			{
				solution.push_back(candidates[i]);
				DFS(solution, target-candidates[i], i);
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
	for (auto &i : s.combinationSum(candidates, 7))
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
