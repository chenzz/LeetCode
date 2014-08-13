#include <iostream>
#include <algorithm>

using namespace std;

//Solution 1.
//把第二个数组元素追加到第一个数组后面，然后进行排序
class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
	{
		for (int i = 0; i < n; i++)
			A[m+i] = B[i];
		
		sort(A, A+m+n);
    }
};

//Solution 2.
//相比较时间复杂度更低。
class Solution2
{
public:
	void merge(int A[], int m, int B[], int n)
	{
		int i, j, k;

		i = m - 1;
		j = n - 1;
		k = m + n -1;
		while (i >= 0 && j >= 0)
		{
			if (A[i] >= B[j])
			{
				A[k] = A[i];
				i--;
			}
			else
			{
				A[k] = B[j];
				j--;
			}
			k--;
		}

		while (j >= 0)
		{
			A[k] = B[j];
			k--;
			j--;
		}
	}
};

int main()
{
	int A[7] = {2, 4, 6, 7};
	int B[3] = {1, 3, 5};
	Solution2 s;
	s.merge(A, 4, B, 3);

	for (auto &i : A)
		cout << i << ' ';

	return 0;
}
