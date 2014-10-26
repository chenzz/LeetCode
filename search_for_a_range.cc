#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> searchRange(int A[], int n, int target)
	{
		vector<int> res;
		int l, r, m;

		l = 0;
		r = n - 1;
		while (l <= r)
		{
			m = (l + r) >> 1;
			if ((A[m]==target) && (m==0 || A[m-1]!=target))
			{
				res.push_back(m);
				break;
			}
			else if (A[m] > target || A[m-1] == target)
				r = m - 1;
			else
				l = m + 1;
		}
		if (res.size() == 0)
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}

		l = 0;
		r = n - 1;
		while (l <= r)
		{
			m = (l + r) >> 1;
			if ((A[m]==target) && (m==n-1 || A[m+1]!=target))
			{
				res.push_back(m);
				break;
			}
			else if (A[m] < target || A[m+1] == target)
				l = m + 1;
			else 
				r = m - 1;
		}
		return res;
	}
};

int main()
{
	Solution s;
	int A[] = {5, 7, 7, 8, 8, 10};
	for (auto &r : s.searchRange(A, sizeof(A) / sizeof(int), 8))
		cout << r << " ";
	cout << endl;

	return 0;
}
