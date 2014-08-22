/*
 * Reference:
 * http://blog.csdn.net/algorithmengine/article/details/8263123
 * http://www.cnblogs.com/remlostime/archive/2012/11/18/2775730.html
 *
 * */

#include <iostream>
#include <cmath>

using namespace std;

//二分法
class Solution
{
public:
	int sqrt(int x)
	{
		long long left = 0;
		long long right = x;

		while (left <= right)
		{
			long long mid = left + (right-left) / 2;

			if (mid * mid <= x && (mid+1) * (mid+1) > x)
				return mid;
			else if (mid * mid < x)
				left = mid + 1;
			else if (mid * mid > x)
				right = mid - 1;
		}

		return -1;
	}
};

//牛顿迭代法
class Solution2
{
public:
	int sqrt(int x)
	{
		double res = x;

		while (abs(res * res - x) > 0.0001)
			res = (res + x / res) / 2;

		return (int)res;
	}
};

int main()
{
	Solution2 s;
	cout << s.sqrt(989848863) << endl;

	return 0;
}
