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

			//test if it's overflow.
			if (sign==1 && result>INT_MAX)
				return INT_MAX;

			if (sign==-1 && -result < INT_MIN)
				return INT_MIN;
		}

		if (sign == -1)
				result *= -1;

		return result;
	}

};

int main()
{
	Solution s;
	cout << s.atoi("-893489eb") << endl;;

	return 0;
}
