#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void reverseWords(string &s)
	{
		if (s.empty())
			return;

		string word;
		stack<string> stk;
		s.push_back(' ');
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
				word.push_back(s[i]);
			else if (i > 0 && s[i] == ' ' && s[i-1] != ' ')
			{
				stk.push(word);
				word.clear();
			}
		}

		s.clear();
		if (stk.empty())
			return;
		while (true)
		{
			s += stk.top();
			stk.pop();
			if (stk.empty())
				break;
			else
				s.push_back(' ');
		}
		return;
	}
};

class Solution2
{
public:
	void reverseWords(string &s)
	{
		string res;

		int i = s.size() - 1;
		while (true)
		{
			while (s[i] == ' ' && i >= 0) 
				i--;
			if (i < 0) break;

			if (!res.empty())
				res.push_back(' ');

			string temp;
			while (s[i] != ' ' && i >= 0) 
			{
				temp.push_back(s[i]);
				i--;
			}
			reverse(temp.begin(), temp.end());
			res += temp;
			if (i < 0) break;
		}
		s = res;
	}
};


int main()
{
	Solution s;
	string words;

//	words = "the sky is blue";
//	words = " hello  world";
	words = " ";
	s.reverseWords(words);
	cout << words << endl;

	return 0;
}
