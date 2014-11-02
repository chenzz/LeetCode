#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int totalNQueens(int n)
	{
		vector<int> solution(n);
		helper(solution, 0, n);

		return res;
	}
	void helper(vector<int> &solution, int row, int n)
	{
		if (row == n)
			res++;
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
	bool isValid(vector<int> &solution, int row, int col)
	{
		for (int i = 0; i < row; i ++)
			if (solution[i] == col || abs(i-row) == abs(solution[i]-col))
				return false;
		return true;
	}
	
private:
	int res = 0;
};

int main() 
{
	Solution s;
	cout << s.totalNQueens(8);

	return 0;
}
