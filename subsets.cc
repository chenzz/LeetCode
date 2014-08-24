#include <iostream>
#include <algorithm>

using namespace std;

//Solution 1: 麻烦点，不推荐
//和combinations那道很类似
//subsets = c(n, 0) + c(n, 1) + …… c(n, n)
class Solution
{
public:
	vector<vector<int>> subsets(vector<int> &S)
	{
		sort(S.begin(), S.end());

		for (int i = 0; i <= S.size(); i++)
			combinations(S, i, 0);

		return res;
	}

	void combinations(vector<int> &S, int k, int step)
	{
		if (k == 0)
			res.push_back(solution);
		else
		{
			for (int i = step; i <= S.size() - k; i++)
			{
				solution.push_back(S[i]);
				combinations(S, k-1, i+1);
				solution.pop_back();
			}
		}

		return;
	}

	vector<vector<int>> res;
	vector<int> solution;
};

//Solution 2: 推荐
//递归求解，递归的函数是从当前位置往后求幂集。
//	http://blog.csdn.net/tuantuanls/article/details/8751495
class Solution2
{
public:
	vector<vector<int>> subsets(vector<int> &S)
	{
		vector<int> solution;

		sort(S.begin(), S.end());
		generate(S, 0);

		return res;
	}

	void generate(vector<int> &S, int index)
	{
		if (index == S.size())
			res.push_back(solution);
		else
		{
			generate(S, index+1);

			solution.push_back(S[index]);
			generate(S, index+1);

			solution.pop_back();
		}
	}

private:
	vector<vector<int>> res;
	vector<int> solution;
};

int main()
{
	vector<int> S = {7, 8, 9, 1};
	Solution2 s;

	cout << "Output:" << endl;
	for (auto &i : s.subsets(S))
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
