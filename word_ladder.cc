/* 写了篇博文
 * http://blog.csdn.net/timberwolf_2012/article/details/38867667
 * */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//Solution1:
//创建了邻接矩阵.
//此方法不行，会超时.
class Solution
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		dict.insert(start);
		dict.insert(end);

		vector<string> newDict(dict.begin(), dict.end());
		vector<vector<bool>> matrix(dict.size(), vector<bool>(dict.size(), false));
		int startNum, endNum;
		queue<int> que;
		queue<int> depth;
		vector<bool> visited(dict.size());

		for (startNum = 0; newDict[startNum] != start; startNum++);
		for (endNum = 0; newDict[endNum] != end; endNum++);
		makeMatrix(newDict, matrix);
		que.push(startNum);
		depth.push(1);


		while (!que.empty())
		{
			int ver = que.front();
			que.pop();

			int len = depth.front();
			depth.pop();

			if (matrix[ver][endNum] == true)
				return len+1;
			for (int i = 0; i < newDict.size(); i++)
			{
				if (matrix[ver][i] == true && visited[i] == false)
				{
					visited[ver] = true;
					que.push(i);
					depth.push(len+1);
				}
			}
		}

		return 0;
	}

	void makeMatrix(vector<string> dict, vector<vector<bool>> &matrix)
	{
		int wordLength;

		wordLength = dict[0].size();
		for (int i = 0; i < dict.size(); i++)
		{
			for (int j = 0; j < dict.size(); j++)
			{
				int num = 0;
				for (int k = 0; k < wordLength; k++)
					if (dict[i][k] == dict[j][k])
						num++;
				if (1 == wordLength-num)
					matrix[i][j] = true;
			}
		}

		return;
	}
};

//Solution2:
//没有创建邻接矩阵.
//可行.
class Solution2
{
public:
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		dict.insert(end);
		queue<string> que;
		queue<int> depth;
		que.push(start);
		depth.push(2);
		int len;

		while (!que.empty())
		{
			string ver = que.front();
			que.pop();
			len = depth.front();
			depth.pop();

			vector<string> res;
			adjacency(ver, dict, res);
			for (auto &r : res)
			{
				if (r == end)
					return len;
				else
				{
					dict.erase(r);
					que.push(r);
					depth.push(len+1);
				}
			}
		}

		return 0;
	};

	void adjacency(const string &ver, const unordered_set<string> &dict, vector<string> &res)
	{
		for (int i = 0; i < ver.size(); i++)
		{
			string temp = ver;
			for (int j = 'a'; j <= 'z'; j++)
			{
				temp[i] = j;
				if (temp != ver && dict.find(temp) != dict.end())
					res.push_back(temp);
			}
		}

		return;
	}
};

int main()
{
	unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
	Solution s;

	cout << s.ladderLength("hit", "cog", dict) << endl;

	return 0;
}
