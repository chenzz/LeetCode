/*
 * 关于该题写了一篇博文:
 * http://blog.csdn.net/timberwolf_2012/article/details/38756403#
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string> &strs)
	{
		vector<string> res;
		map<string, int> anagram;

		for (int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];

			sort(s.begin(), s.end());
			if (anagram.find(s) == anagram.end())
				anagram[s] = i;
			else
			{
				//如果是第二个anagram
				if (anagram[s] > -1)
				{
					res.push_back(strs[anagram[s]]);
					anagram[s] = -1;
				}
				res.push_back(strs[i]);
			}
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector<string> strs = {"cat", "rye", "aye", "dog", "god",
		"cud", "cat", "old", "fop", "bra"};
	vector<string> strs2 = {"tea", "and", "ate", "eat", "den"};

	for (auto &r : s.anagrams(strs))
		cout << r << " ";
	cout << endl;

	for (auto &r : s.anagrams(strs2))
		cout << r << " ";
	cout << endl;

	return 0;
}
