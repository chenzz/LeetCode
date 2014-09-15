#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		string solution;
		dfs(digits, 0, solution);

		return res;
	}
	void dfs(string &digits, int index, string &solution)
	{
		if (index == digits.size())
		{
			res.push_back(solution);
			return;
		}
		else
		{
			for (auto &r : key[digits[index] - '0'])
			{
				solution.push_back(r);
				dfs(digits, index+1, solution);
				solution.pop_back();
			}
		}
	}
	vector<string> res;
	string key[10] = {"", 
		"", "abc", "def", 
		"ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz"};
};

int main()
{
	Solution s;
	for (auto &r : s.letterCombinations("23"))
		cout << r << " ";
	cout << endl;

	return 0;
}
