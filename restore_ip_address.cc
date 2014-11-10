#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		s_ = s;
		helper("", 1, 0);

		return res_;
	}

	void helper(string ip, int segment_num, int index)
	{
		if (segment_num == 4)
		{
			string ip_segment = s_.substr(index, s_.size() - index);
			if (!ip_segment.empty() && ip_segment.length() <= 3 
					&& isValid(ip_segment))
			{
				ip += ip_segment;
				res_.push_back(ip);
			}
		}
		else
		{
			for (int i = 1; i <= 3 && i <= s_.size() - index; i++)
			{
				string ip_segment = s_.substr(index, i);
				if (isValid(ip_segment))
					helper(ip + ip_segment + '.', segment_num + 1, index + i);
			}
		}
	}

	bool isValid(string ip_segment)
	{
		if (ip_segment[0] == '0')
			return (ip_segment == "0");
		if (stoi(ip_segment) <= 255)
			return true;
		else
			return false;
	}

private:
	string s_;
	vector<string> res_;
};


int main()
{
	Solution s;
	for (auto &r : s.restoreIpAddresses("0279245587303"))
		cout << r << " ";
	cout << endl;

	return 0;
}
