#include <iostream>

using namespace std;

class Solution
{
public:
	int search(int A[], int n, int target)
	{
		if (n <= 0)
			return -1;
		int l = 0;
		int r = n - 1;
		int m;

		while (l <= r)
		{
			m = (l + r) / 2;
			if (A[m] == target)
				return m;
			else if (A[l] <= A[m])
			{
				if (A[l] <= target && target < A[m])
					r = m - 1;
				else
					l = m + 1;
			}
			else
			{
				if (A[m] < target && target <= A[r])
					l = m + 1;
				else
					r = m - 1;
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	int A[] = {3, 1};
	cout << s.search(A, 2, 1) << endl;

	return 0;
}
