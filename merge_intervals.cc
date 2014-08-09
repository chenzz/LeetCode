#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//   Definition for an interval.
struct Interval 
{
	int start;
	int end;

	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval i1, Interval i2)
{
	return i1.start < i2.start;
}


class Solution 
{
public:
	vector<Interval> merge(vector<Interval> &intervals) 
	{
		if (intervals.size() < 2)
			return intervals;
		
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> res;
		
		Interval temp(intervals[0].start, intervals[0].end);
		res.push_back(temp);

		int i, j;
		for (i = 1, j = 0; i < intervals.size(); i++)
		{
			if (intervals[i].start <= res[j].end)
			{
				res[j].end = max(intervals[i].end, res[j].end);
			}
			else
			{
				res.push_back(intervals[i]);
				j++;
			}
		}

		return res;
	}
};

int main()
{
	vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), 
		Interval(8, 10), Interval(15, 18)};
	Solution s;

	for (auto i : s.merge(intervals))
		cout << "[" << i.start << ", " << i.end << "]" << endl;

	return 0;
}
