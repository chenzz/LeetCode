/*
 * Reference
 * http://blog.csdn.net/havenoidea/article/details/11848921
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	string intToRoman(int num)
	{
		vector<string> roman= {"M", "CM", "D", "CD", "C", "XC", 
			"L", "XL", "X", "IX", "V", "IV", "I"};
		vector<int> integer= {1000, 900, 500, 400, 100, 90, 50, 40, 
			10, 9, 5, 4, 1};

		string res;
		for (int i = 0; num != 0; )
		{
			if (num >= integer[i])
			{
				num -= integer[i];
				res += roman[i];
			}
			else
			{
				i++;
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	cout << s.intToRoman(2344);

	return 0;
}

