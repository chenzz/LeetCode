#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> paths(m, vector<int>(n, 1));

		int firstRowFirstObstacle = -1;
		int firstColFirstObstacle = -1;
		//get first obstacle position in first col and first row 
		for (int i = 0; i < m; i++)
			if (obstacleGrid[i][0] == 1)
			{
				firstColFirstObstacle = i;
				break;
			}
		for (int i = 0; i < n; i++)
			if (obstacleGrid[0][i] == 1)
			{
				firstRowFirstObstacle = i;
				break;
			}

		//assign 0 where firstObstacle and after that in first row and col
		if (firstColFirstObstacle != -1)
			for (int i = firstColFirstObstacle; i < m; i++)
				paths[i][0] = 0;
		if (firstRowFirstObstacle != -1)
			for (int i = firstRowFirstObstacle; i < n; i++)
				paths[0][i] = 0;

		//calculate paths
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					paths[i][j] = 0;
					continue;
				}
				paths[i][j] = paths[i-1][j] + paths[i][j-1];
			}
		}

		return paths[m-1][n-1];
	}
};

int main()
{
	Solution s;
	vector<vector<int>> obstacleGrid = {{0, 1}};
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

	return 0;
}
