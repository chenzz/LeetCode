#include <iostream>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
	{
		string ss;

		for (auto &r : s)
		{
			if (r>='0'&&r<='9' || r>='a'&&r<='z' || r>='A'&&r<='Z')
				ss.push_back(toLower(r));
		}

		int i = 0; 
		int j = ss.size() - 1;
		while (i < j)
		{
			if (ss[i] != ss[j])
				return false;
			i++;
			j--;
		}

		return true;
    }

	char toLower(char c)
	{
		if (c>='A' && c<='Z')
			c += 'a' - 'A';

		return c;
	}
};

int main()
{
	Solution s;
	cout << s.isPalindrome("aA") << endl;

	return 0;
}
