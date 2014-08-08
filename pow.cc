#include <iostream>

using namespace std;

class Solution 
{
public:
	double pow(double x, int n) 
	{
		double res;

		if (n >= 0)
		{
			res = pow2(x, n);
		}
		else
		{
			res = 1.0 / pow2(x, -n);
		}
		
		return res;
    }

	double pow2(double x, int n)
	{
		double tmp;

		if (n == 0)
		{
			return 1;
		}


		tmp = pow2(x, n/2);
		if (n % 2 == 0)
		{
			return tmp * tmp;
		}
		else 
		{
			return tmp * tmp  * x; 
		}
	}
};

int main()
{
	Solution s;
	double res = s.pow(0.00001, 2147483647);

	cout << res << endl;

	return 0;
}
