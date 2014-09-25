#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution
{
public:
	int divide(long long dividend, long long divisor)
	{
		int res = 0;
		int sign = (dividend>0 && divisor>0) || (dividend<0 && divisor<0);
		dividend = dividend > 0 ? dividend : -dividend;
		divisor = divisor > 0 ? divisor : -divisor;

		while (dividend >= divisor)
		{
			long long res_temp = 1;
			while (res_temp * divisor <= dividend)
				res_temp <<= 1;
			res_temp >>= 1;
			res += res_temp;
			dividend -= res_temp * divisor;
		}
		return sign ? res : -res;
	}
};

int main()
{
	Solution s;
	cout << s.divide(-1010369383, -2147483648) << endl;

	return 0;
}
