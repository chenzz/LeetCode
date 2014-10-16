#include <iostream>

using namespace std;

class Solution
{
public:
	bool search(int A[], int n, int target)
	{
		int l = 0;
		int r = n - 1;
		int m;

		while (l <= r)
		{
			m = (l + r) >> 1;
			if (A[m] == target)
				return true;
			else
			{
				if (A[m] == A[l])
					l++;
				else if (A[m] > A[l])
				{
					if (target >= A[l] && target < A[m])
						r = m - 1;
					else
						l = m + 1;
				}
				else
				{
					if (target > A[m] && target <= A[r])
						l = m + 1;
					else
						r = m - 1;
				}
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	int A[] = {4, 5, 7, 9, 11, 1, 3, 3, 5};

	cout << s.search(A, sizeof(A)/4, 12);

	return 0;
}
