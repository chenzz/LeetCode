#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		vector<int> temp_res(num1.size() + num2.size(), 0);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for (int i = 0; i < num1.size(); i++)
			for (int j = 0; j < num2.size(); j++)
				temp_res[i + j] += (num1[i]-'0') * (num2[j]-'0');

		int carry = 0;
		for (int i = 0; i < temp_res.size(); i++)
		{
			int temp = temp_res[i] + carry;
			temp_res[i] = temp % 10;
			carry = temp / 10;
		}

		for (int i = temp_res.size() - 1; i >= 0; i--)
		{
			if (temp_res[i] != 0)
				break;
			temp_res.pop_back();
		} 
		reverse(temp_res.begin(), temp_res.end());
		string res;
		for (int i = 0; i < temp_res.size(); i++)
			res += temp_res[i] + '0';

		return res.size() != 0 ? res : string("0");
	}
};

int main()
{
	Solution s;
	string num1("9");
	string num2("9");
	cout << s.multiply(num1, num2) << endl;

	return 0;
}
