#include <iostream>

using namespace std;

class Solution
{
public:
	bool isMatch(const char *s, const char *p)
	{
		//递归基
		if (*p == '\0')
			return (*s == '\0');

		//如果下一个字符不是'*'
		if (*(p+1) != '*')
			return (*s != '\0') && (*s == *p || *p == '.') && isMatch(s+1, p+1);

		//如果下一个字符是'*'
		if (isMatch(s, p+2))
			return true;
		while ((*s != '\0') && (*s == *p || *p == '.')) 
		{
			s++;
			if (isMatch(s, p+2))
				return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.isMatch("ab", ".*b") << endl;

	return 0;
}
