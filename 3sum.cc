/*
 * 思路：
 *
 * 1. 对数列排序.
 * 2. 遍历数列,对其中的每个数a, 
 * 		在它后面的数中找出两个数，使其和为 -a
 * 		(这一步就是Two Sum那道题)
 *
 * 3. 为了保证每个都是 unique triplet, 
 * 	  在第二步中，3.1 遍历时如果这个数和它前一个数一样大，则跳过。
 * 	  			  3.2 找剩下两个数时，如果前下标和它前一个相同则直接跳过。
 * 	  			  	  后下标同理。
 */
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > threeSum(vector<int> &num) 
    {
		vector<vector<int>> res;

		if (num.size() < 3)
			return res;

		//1.
		sort(num.begin(), num.end());
		
		//2.
		for (int i = 0; i != num.size()-2; i++)
		{
			//3.
			if (i>0 && num[i]==num[i-1])
				continue;

			int j = i + 1;
			int k = num.size() - 1;

			while (j < k)
			{
				int sum = num[j] + num[k];

				if (sum < -num[i])		//sum < -num[i]
					j++;
				else if (sum > -num[i])	//sum > -num[i]
					k--;
				else 					//sum == -num[i]
				{
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[k]);
					res.push_back(temp);
					j++;
					k--;

					while (j<k && num[j]==num[j-1])
					{
						j++;
					}
					while (j<k && num[k]==num[k+1] && k<num.size())
					{
						k--;
					}

				}
			}
		}
		
		return res;
    }
};

int main()
{
	Solution s;
	vector<int> num = {-2, -1, 0, 1, 2, 3, -1, -4, 5};
	
	for (auto i : s.threeSum(num))
	{
		for (auto j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
	
	return 0;
}
