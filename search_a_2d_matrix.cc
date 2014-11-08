#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int h = matrix.size();
		int w = matrix[0].size();


		int l = 0;
		int r = h - 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (matrix[mid][0] < target)
				l = mid + 1;
			else if (matrix[mid][0] > target)
				r = mid - 1;
			else
				return true;
		}

		int row = r;
		if (row < 0)
			return false;

		l = 0;
		r = w - 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (matrix[row][mid] < target)
				l = mid + 1;
			else if (matrix[row][mid] > target)
				r = mid - 1;
			else
				return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> matrix = {{1, 3}};

	cout << s.searchMatrix(matrix, 2) << endl;

	return 0;
}
