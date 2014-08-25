#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0])
					if (search(board, i, j, word, 0, visited))
						return true;
			}
		}
		return false;
	}

	bool search(vector<vector<char>> &board, int i, int j, string word, int index, vector<vector<bool>> &visited)
	{
		if (index == word.size())
			return true;
		else if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
			return false;
		else if (visited[i][j] == true)
			return false;
		else if (board[i][j] != word[index])
			return false;
		else
		{
			visited[i][j] = true;
			if (search(board, i-1, j, word, index+1, visited)) return true;
			if (search(board, i+1, j, word, index+1, visited)) return true;
			if (search(board, i, j-1, word, index+1, visited)) return true;
			if (search(board, i, j+1, word, index+1, visited)) return true;
			visited[i][j] = false;
		}

		return false;
	}
};

int main()
{
	vector<vector<char>> board = 
	{   
		{'A', 'B', 'C', 'E'}, 
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};  
	Solution s;

	cout << s.exist(board, "ABCCED") << endl;
	cout << s.exist(board, "SEE") << endl;
	cout << s.exist(board, "ABCB") << endl;

	return 0;
}
