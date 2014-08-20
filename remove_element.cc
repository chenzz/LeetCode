#include <iostream>

using namespace std;

class Solution 
{
public:
    int removeElement(int A[], int n, int elem) 
    {
		int i, num;

		num = 0;
		for (i = 0; i < n; i++)
		{
			if (A[i] != elem)
				A[num++] = A[i];
		}

		return num;
    }
};

int main()
{

	return 0;
}
