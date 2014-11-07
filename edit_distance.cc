#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> res(m + 1, vector<int>(n + 1));

		for (int i = 0; i <= m; i++)
			res[i][0] = i;
		for (int i = 0; i <= n; i++)
			res[0][i] = i;

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				res[i][j] = min(res[i-1][j] + 1, res[i][j-1] + 1);
				if (word1[i-1] == word2[j-1])
					res[i][j] = min(res[i][j], res[i-1][j-1]);
				else
					res[i][j] = min(res[i-1][j-1] + 1, res[i][j]);
		}

		return res[m][n];
	}
};

int main()
{
	Solution s;
	string word1 = "a";
	string word2 = "b";
	cout << s.minDistance(word1, word2) << endl;

	return 0;
}
