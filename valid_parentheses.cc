#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	bool match(char a, char b)
	{
		return (a=='(' && b==')' 
				|| (a=='[') && (b==']') 
				|| (a=='{') && (b=='}'));
	}

	bool isValid(string s)
	{
		stack<char> left;

		for (auto i : s)
		{
			if (i=='(' || i=='[' || i=='{')
				left.push(i);
			else if (i==')' || i==']' || i=='}')
			{
				if (!left.empty() && match(left.top(), i))
				{
					left.pop();
					continue;
				}
				else
					return false;
			}
			else
				return false;
		}

		if (left.empty())
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;

	if (s.isValid("[{()}()[]]"))
//	if (s.isValid("["))
		cout << "valid." << endl;
	else
		cout << "not valid." << endl;

	return 0;
}
