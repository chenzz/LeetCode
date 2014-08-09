/* 思路：
 * 		先插入，再合并。
 *
 * 		先把newInterval添加到intervals的尾部，
 * 		然后直接调用Merge Intervals那道题中的merge函数进行合并。
 * */

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

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
		intervals.push_back(newInterval);
		
		return merge(intervals);
	}
};

int main()
{
	vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7), 
		Interval(8, 10), Interval(12, 16)};
	Solution s;

	for (auto i : s.insert(intervals, Interval(4, 9)))
		cout << "[" << i.start << ", " << i.end << "]" << endl;

	return 0;
}
