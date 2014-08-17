#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
		generate(n, 0, 0, "");

		return res;
    }

	void generate(int n, int left, int right, string s)
	{
		if (right == n)
			res.push_back(s);

		if (left < n)
			generate(n, left + 1, right, s + '(');

		if (right < left)
			generate(n, left, right + 1, s + ')');
	}

private:
	vector<string> res;
};

int main()
{
	Solution s;
	for (auto &r : s.generateParenthesis(3))
		cout << r << " " << endl;

	return 0;
}
