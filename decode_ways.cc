/* Blog
 * http://blog.csdn.net/timberwolf_2012/article/details/38902215
 */
#include <iostream>

using namespace std;


class Solution
{
public:
	int numDecodings(string s)
	{
		if (s.empty())
			return 0;
		if (s[0] == '0')
			return 0;
		if (s.size() == 1)
			return 1;

		int a, b, c;
		a = 1;
		b = 1; 
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i] == '0' && s[i-1] == '0')
				return 0;
			if (s[i] == '0' && s[i-1] > '2')
				return 0;

			if (stoi(s.substr(i-1, 2)) > 26)
				c = b;
			else if (s[i] == '0')
				c = a;
			else if (s[i-1] == '0')
				c = b;
			else
				c = a + b;

			a = b;
			b = c;
		}

		return c;
	}
};

int main()
{
	Solution s;
	cout << s.numDecodings("30") << endl;

	return 0;
}
