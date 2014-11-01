#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<int> solution(n);
		helper(solution, 0, n);

		return res;
	}

	void helper(vector<int>& solution, int row, int n)
	{
		if (row == n)
		{
			vector<string> solution_2d(n, string(n, '.'));
			for (int i = 0; i < n; i++)
				solution_2d[i][solution[i]] = 'Q';

			res.push_back(solution_2d);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (isValid(solution, row, i))
				{
					solution[row] = i;
					helper(solution, row + 1, n);
				}
			}
		}
	}

	bool isValid(vector<int>& solution, int row, int col)
	{
		for (int i = 0; i < row; i++)
			if (solution[i] == col || abs(i-row) == abs(solution[i]-col))
				return false;
		return true;
	}

private:
	vector<vector<string>> res;
};

int main()
{
	Solution s;

	vector<vector<string>> res = s.solveNQueens(8);
	cout << res.size() << endl;

	/*
	for (auto &i : res)
	{
		for (auto &j : i)
			cout << j << endl;

		cout << "\n\n\n\n";
	}
	*/

	return 0;
}

