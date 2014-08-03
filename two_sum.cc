#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
	public:
		vector<int> TwoSum(vector<int> &numbers, int target) 
		{
			vector<int> num = numbers;
			sort(num.begin(), num.end());

			int left = 0;
			int right = num.size() - 1;
			int sum;
			vector<int> index;

			while (left < right)
			{
				sum = num[left] + num[right];
				if (sum == target)
				{
					for (int i = 0; i != numbers.size(); i++)
				{
						if ((numbers[i]==num[left]) 
								|| (numbers[i]==num[right]))
						{
							index.push_back(i+1);
						}
						if (index.size() == 2)
						{
							return index;
						}
					}
				}
				else if (sum < target)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
};



int main()
{
	vector<int> num = {2, 7, 11, 5};
	vector<int> index;

	Solution s;

	index = s.TwoSum(num, 9);
	for (auto &r : index)
	{
		cout << r << endl;
	}

	return 0;
}
