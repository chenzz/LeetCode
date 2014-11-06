#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minPathSum(vector<vector<int>> &grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> res(grid);

		//First row and first col 's Minimum Path Sum
		for (int i = 1; i < m; i++)
			res[i][0] += res[i-1][0];
		for (int i = 1; i < n; i++)
			res[0][i] += res[0][i-1];

		//Other points's Minimum Path Sum
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				res[i][j] += min(res[i-1][j], res[i][j-1]);

		return res[m-1][n-1];
	}
};

int main()
{
	vector<vector<int>> grid = {{1,2}, {3, 4}};
	Solution s;
	cout << s.minPathSum(grid) << endl;

	return 0;
}
