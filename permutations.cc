/*
 * Reference:
 * http://fisherlei.blogspot.com/2012/12/leetcode-permutations.html
 * (这网址被墙了)
 *
 * 要点:
 * 		1. 循环中嵌套一个递归
 * 		2. 每次循环完之后都要把数据恢复原样，不能影响下一循环中的递归。
 * 		3. 用标志位记录已访问的数字。
 * 		4. 用一个step来记录步长，最后判断递归基。
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> permute(vector<int> &num) 
	{
		if (num.size() == 0)
			return res;
		vector<int> solution;
		vector<bool> visited(num.size(), false);
		generate(num, 0, visited, solution);

		return res;
    }

	void generate(vector<int> &num, int step, vector<bool> &visited, 
			vector<int> &solution)
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
					visited[i] = true;
					solution.push_back(num[i]);
					generate(num, step+1, visited, solution);
					solution.pop_back();
					visited[i] = false;
				}
			}
		}

		return;
	}

private:
	vector<vector<int>> res;
};

int main()
{
	vector<int> num = {1, 2, 3};
	Solution s;
	for (auto &i : s.permute(num))
	{
		for (auto &j : i)
			cout << j << ' ';
		cout << endl;
	}

	return 0;
}
