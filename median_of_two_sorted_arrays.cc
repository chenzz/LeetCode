#include <iostream>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		if ((m + n) & 0x01)
			return findKth(A, m, B, n, (m + n) / 2 + 1);
		else
			return (findKth(A, m, B, n, (m + n) / 2) 
					+ findKth(A, m, B, n, (m + n) / 2 + 1)) / 2;
	}

	double findKth(int A[], int m, int B[], int n, int k)
	{
		if (m > n)
			return findKth(B, n, A, m, k);
		else if (m == 0)
			return B[k-1];
		else if (k == 1)
			return min(A[0], B[0]);
		else
		{
			int ALeftCount = min(k / 2, m);
			int BLeftCount = k - ALeftCount;

			if (A[ALeftCount-1] == B[BLeftCount-1])
				return A[ALeftCount-1];
			else if (A[ALeftCount-1] < B[BLeftCount-1])
				return findKth(A+ALeftCount, m-ALeftCount, 
						B, n, k-ALeftCount);
			else//A[ALeftCount-1] > B[BLeftCount-1]]
				return findKth(A, m, 
						B+BLeftCount, n-BLeftCount, k-BLeftCount);
		}
	}
};

int main()
{
	int A[] = {1};
	int B[] = {1};
	Solution s;
	cout << s.findMedianSortedArrays(A, 1, B, 1) << endl;

	return 0;
}
