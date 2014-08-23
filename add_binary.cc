/*
 * Reference:
 * http://huntfor.iteye.com/blog/2061827
 * http://fisherlei.blogspot.com/2013/01/leetcode-add-binary.html (被墙了)
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
	{
		string res;
		if (a.size() > b.size())
			b.insert(b.begin(), a.size()-b.size(), '0');
		else
			a.insert(a.begin(), b.size()-a.size(), '0');

		int carry = 0; 
		for (int i = a.size()-1; i >= 0; i--)
		{
			int sum;
			sum = a[i] - '0' + b[i] - '0' + carry;
			if (sum < 2)
			{
				res.insert(res.begin(), sum + '0');
				carry = 0;
			}
			else
			{
				carry = 1;
				res.insert(res.begin(), sum % 2 + '0');
			}
		}

		if (carry == 1)
			res.insert(res.begin(), '1');

		return res;
	}
};

class Solution2
{
public:
	string addBinary(string a, string b)
	{
		string res;

		int i = a.size() - 1;
	   	int j = b.size() - 1; 
		int carry = 0;
		for (; i >= 0 || j >= 0; i--, j--)
		{
			int ia = i >= 0 ? a[i]-'0' : 0;
			int ib = j >= 0 ? b[j]-'0' : 0;
			res.push_back((ia+ib+carry) % 2 + '0');
			carry = (ia+ib+carry) / 2;
		}

		if (carry == 1)
			res.push_back('1');

		reverse(res.begin(), res.end());

		return res;
	}	
};


int main()
{
	Solution2 s;

	cout << s.addBinary("11", "1") << endl;

	return 0;
}
