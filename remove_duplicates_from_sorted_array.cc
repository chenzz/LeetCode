#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if (n < 1) 
			return n;
		int count = 1;
		for (int i = 1; i < n; i++)
			if (A[i] != A[i-1])
				A[count++] = A[i];
		return count;
	}
};

int main()
{
	int A[] = {1, 1, 2};
	Solution s;

	cout << s.removeDuplicates(A, 3) << endl;
	for (int i = 0; i < 3; i++)
		cout << A[i] << " ";
	return 0;
}
