/*
 * Reference
 * http://blog.csdn.net/havenoidea/article/details/11848921
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	string intToRoman(int num)
	{
		vector<int> integer= {1000, 900, 500, 400, 100, 90, 50, 40, 
			10, 9, 5, 4, 1};
		vector<string> roman= {"M", "CM", "D", "CD", "C", "XC", 
			"L", "XL", "X", "IX", "V", "IV", "I"};

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

//Solution2.
//	采用pair作为数组元素，逻辑上更清晰。
class Solution2
{
public:
	string intToRoman(int num)
	{
		vector<pair<int, string>> intRoman = {
			{1000, "M"}, {900, "CM"}, {500, "D"}, 
			{400, "CD"}, {100, "C"}, {90, "XC"}, 
			{50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, 
			{5, "V"}, {4, "IV"}, {1, "I"}
		};
		string res;

		for (auto it = intRoman.begin(); num != 0;)
		{
			if (num >= it->first)
			{
				num -= it->first;
				res += it->second;
			}
			else
			{
				it++;
			}
		}

		return res;
	}
};

int main()
{
	Solution2 s;
	cout << s.intToRoman(2344);

	return 0;
}

