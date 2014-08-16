
/*
 * Reference
 * http://www.cnblogs.com/TenosDoIt/p/3793503.html
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		map<char, int> romanInt = {
			{'M', 1000},  {'D', 500}, {'C', 100}, {'L', 50},  
			{'X', 10},  {'V', 5}, {'I', 1}
		};

		int lastInt = 0;
		int res = 0;
		for (auto it = s.rbegin(); it != s.rend(); it++)
		{
			if (romanInt[*it] >= lastInt)
			{
				res += romanInt[*it];
				lastInt = romanInt[*it];
			}
			else
			{
				res -= romanInt[*it];
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	cout << s.romanToInt("MCDI");

	return 0;
}

