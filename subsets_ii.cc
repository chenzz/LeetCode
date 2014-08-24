#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Reference:
//	http://blog.csdn.net/lanxu_yy/article/details/11885289
class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S)
	{
		sort(S.begin(), S.end());

		generate(S, 0);

		return res;
	}

	void generate(vector<int> &S, int index)
	{
		if (index == S.size())
		{
			for (auto &r : res)
				if (r == solution)
					return;

			res.push_back(solution);
		}
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
	vector<int> S = {1, 1};

	Solution s;
	for (auto &i : s.subsetsWithDup(S))
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}

	return 0;
}
