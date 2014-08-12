#include <iostream>
#include <vector>

using namespace std;

//Solution 1.
//Space complexity: O(m+n)
class Solution
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		vector<int> rowFlags(m);
		vector<int> colFlags(n);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					rowFlags[i] = 1;
					colFlags[j] = 1;
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (rowFlags[i] || colFlags[j])
					matrix[i][j] = 0;
			}
		}
	}
};

//Solution 2.
//Space complexity: O(2)
class Solution2
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		bool rowFlag = false;
		bool colFlag = false;

		for (int i = 0; i < matrix.size() && !colFlag; i++)
			if (matrix[i][0] == 0)
				colFlag = true;

		for (int i = 0; i < matrix[0].size() && !rowFlag; i++)
			if (matrix[0][i] == 0)
				rowFlag = true;

		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}

		for (int i = 1; i < matrix.size(); i++)
			for (int j = 1; j < matrix[0].size(); j++)
				if (!matrix[0][j] || !matrix[i][0])
					matrix[i][j] = 0;

		if (rowFlag)
			for (auto &r : matrix[0])
				r = 0;

		if (colFlag)
			for (auto &r : matrix)
				r[0] = 0;
	}
};

int main()
{
	vector<int> v0;
	v0.push_back(0);
	v0.push_back(1);
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(3);
	vector<vector<int>> matrix;
	matrix.push_back(v0);
	matrix.push_back(v1);

	for (auto &i : matrix)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}

	Solution2 s;
	s.setZeroes(matrix);

	cout << endl;
	for (auto &i : matrix)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}


	return 0;
}
