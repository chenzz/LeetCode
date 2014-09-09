#include <iostream>

using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		bool minus = false;
		int res = 0;

		if (x < 0)
		{
			x = -x;
			minus = true;
		}
		while (x != 0)
		{
			int t;
			t = x % 10;
			x = x / 10;
			res = res * 10 + t;
		}
		if (minus)
			res = -res;

		return res;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(-123) << endl;

	return 0;
}
