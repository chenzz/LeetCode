#include <iostream>

using namespace std;

//Solution 1: 
//Isn't accepted: time limit exceeded.
class Solution
{
public:
	int climbStairs(int n)
	{
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else
			return climbStairs(n - 1) + climbStairs(n - 2);
	}
};

//Solution 2: Dynamic Programming.
class Solution2
{
public:
	int climbStairs(int n)
	{
		int res[n];

		res[0] = 1;
		res[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			res[i] = res[i-1] + res[i-2];
		}

		return res[n];
	}
};

//Solution 3: 
//Improve solution 2 to save memory.
class Solution3
{
public:
	int climbStairs(int n)
	{
		int res[3];

		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			res[i%3] = res[(i-1)%3] + res[(i-2)%3];
		}

		return res[n%3];
	}
};

//Solution 4:
//Similar to solution3, use three values instead of array.
class Solution4
{
public:
	int climbStairs(int n)
	{
		int a, b, c;

		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;

		a = 1;
		b = 2;
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}

		return c;
	}
};

int main()
{
	Solution4 s;
	cout << s.climbStairs(5) << endl;

	return 0;
}

// Reference:
// http://blog.csdn.net/kenden23/article/details/17377869
