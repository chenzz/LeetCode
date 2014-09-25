#include <iostream>
using namespace std;

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if (n < 1)
			return n;
		int count = 1;
		int dup_times = 1;
		for (int i = 1; i < n; i++)
		{
			if (A[i] == A[i-1])
				dup_times++;
			else
				dup_times = 1;

			if (dup_times <= 2)
				A[count++] = A[i];
		}
		return count;
	}
};

int main()
{
	Solution s;
	int A[] = {1, 1, 1, 2, 2, 3};
	int n = s.removeDuplicates(A, 6);

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
