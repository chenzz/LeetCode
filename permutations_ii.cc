/*
 * Reference:
 * http://fisherlei.blogspot.co.uk/2012/12/leetcode-permutations-ii.html
 * (已被墙，需翻墙访问)
 *
 * 要点：
 * 		这道题基本和permutations那道题类似，不过有重复的元素。
 * 		关键在于， 如果一个数和它前一个数相等，则只有在它前一个元素被访问的情况下，这个数才可以被访问。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int> &num)
	{
		if (num.size() == 0)
			return res;

		vector<bool> visited(num.size(), false);
		vector<int> solution;
		sort(num.begin(), num.end());
		generate(num, visited, solution, 0);

		return res;
	}

	void generate(vector<int> &num, vector<bool> &visited, vector<int>& solution, int step)
	{
		if (step == num.size())
		{
			res.push_back(solution);
		}
		else
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (visited[i] == false)
				{
					if (i > 0 && num[i] == num[i-1] && visited[i-1] == false)
						continue;
					visited[i] = true;
					solution.push_back(num[i]);
					generate(num, visited, solution, step+1);
					solution.pop_back();
					visited[i] = false;
				}
			}
		}
	}

private:
	vector<vector<int>> res;
};

int main()
{
	vector<int> num = {2, 1, 1};

	Solution s;
	for (auto &i : s.permuteUnique(num))
	{
		for (auto &j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
