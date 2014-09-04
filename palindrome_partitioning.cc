#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		if (s.empty())
			return res;

		dfs(s, 0);

		return res;
	}

	void dfs(const string &s, int index)
	{
		if (index == s.size())
			res.push_back(solution);
		else
		{
			for (int i = index; i < s.size(); i++)
			{
				string substr = s.substr(index, i-index+1);
				if (isPalindrome(substr))
				{
					solution.push_back(substr);
					dfs(s, i+1);
					solution.pop_back();
				}
			}
		}
	}
		
	bool isPalindrome(const string &s)
	{
		int left = 0;
		int right = s.size() - 1;

		while (left <= right)
		{
			if (s[left] != s[right])
				return false;
			left++;
			right--;
		}
		return true;
	}

	vector<vector<string>> res;
	vector<string> solution;
};

int main()
{
	Solution s;

	for (auto &i : s.partition("aab"))
	{
		for (auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}
