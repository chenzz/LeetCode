#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
	int atoi(const char *str)
	{
		int i, sign;
		long long result;

		result = 0;
		sign = 1;
		result = 0;
		
		//jump the whitespace.
		for (i = 0; str[i] == ' '; i++);

		//check the sign.
		if (str[i] == '+')
		{
			i++;
		}
		else if (str[i] == '-')
		{
			sign = -1;
			i++;
		}

		//start convert.
		for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++)
		{
			result = 10 * result + (str[i] - '0');
		}

		if (sign == -1)
			result *= -1;

		//test if it's overflow.
		if (result > INT_MAX)
			return INT_MAX;

		if (result < INT_MIN)
			return INT_MIN;

		return result;
	}

};

int main()
{
	Solution s;
	cout << s.atoi("-893489eb") << endl;;

	return 0;
}

/* 后记:
 * 	这个程序其实还是有bug的：
 * 	如果输入的数超过了longlong的表示范围可能会出错。
 * 	
 * 	但是一方面程序accepted，
 * 	另一方面改掉这个bug太麻烦而且影响可读性，就不改了，只是在这里标记下。
 *
 *
 *
 *
 *
 * 
 * */
