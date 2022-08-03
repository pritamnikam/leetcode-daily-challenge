/*
Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally 
or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board.


*/

using namespace std;

#include <vector>
#include <string>
#include <queue>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (word[0] == board[i][j]) {
                    // perform BFS
                    if (exist(board, word, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board,
        string word,
        int r, int c) {

        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));


        int currentLevel = 0;
        queue<pair<int, int>> queue;
        queue.push({ r, c });
        visited[r][c] = true;

        while (!queue.empty()) {
            int levelSize = queue.size();
            currentLevel++;

            if (currentLevel == word.size())
                return true;

            for (int k = 0; k < levelSize; ++k) {
                pair<int, int> loc = queue.front();
                queue.pop();

                int i = loc.first;
                int j = loc.second;

                if (isRange(rows, cols, i, j+1) &&
                    !visited[i][j + 1] &&
                    word[currentLevel] == board[i][j + 1]) {
                    visited[i][j + 1] = true;
                    queue.push({ i, j + 1 });
                }

                if (isRange(rows, cols, i, j - 1) &&
                    !visited[i][j - 1] &&
                    word[currentLevel] == board[i][j - 1]) {
                    visited[i][j - 1] = true;
                    queue.push({ i, j - 1 });
                }

                if (isRange(rows, cols, i+1, j) &&
                    !visited[i + 1][j] &&
                    word[currentLevel] == board[i + 1][j]) {
                    visited[i + 1][j] = true;
                    queue.push({ i + 1, j });
                }

                if (isRange(rows, cols, i - 1, j) &&
                    !visited[i - 1][j] &&
                    word[currentLevel] == board[i - 1][j]) {
                    visited[i - 1][j] = true;
                    queue.push({ i - 1, j });
                }
            } // for
        } // while

        return false;
    }

    bool isRange(int rows, int cols, int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
};

class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int start) {
        if (start >= word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || word[start] != board[i][j]) return false;
        board[i][j] = '#';
        bool retVal = dfs(board, word, i + 1, j, start + 1) ||
            dfs(board, word, i - 1, j, start + 1) ||
            dfs(board, word, i, j + 1, start + 1) ||
            dfs(board, word, i, j - 1, start + 1);
        board[i][j] = word[start];
        return retVal;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};


class Solution {
public:

    const vector<int> ROW{ 0, 0, -1, 1 };
    const vector<int> COL{ 1, -1, 0, 0 };

    const int MAX_POSSIBLE_PATHS = 4;

    // check if a given cell is valid
    bool is_valid(const int row, const int col, const board_t& board)
    {
        const auto ROW_MAX = board.size();
        const auto COL_MAX = board[0].size();

        return row < ROW_MAX&& col < COL_MAX&& row >= 0 && col >= 0;
    }

    // recursively check if the next characted in the word if found
    bool solve(const board_t& board, vector<vector<bool>>& visited,
        const string& word, const int index, const int curr_row, const int curr_col)
    {
        if (index == word.length()) return true;

        for (int i = 0; i < MAX_POSSIBLE_PATHS; i++)
        {
            const int new_row = curr_row + ROW[i];
            const int new_col = curr_col + COL[i];

            if (is_valid(new_row, new_col, board) && !visited[new_row][new_col]
                && (board[new_row][new_col] == word[index]))
            {
                visited[new_row][new_col] = true;
                if (solve(board, visited, word, index + 1, new_row, new_col)) return true;
                visited[new_row][new_col] = false;
            }
        }

        return false;
    }

    bool exist(const board_t& board, const string& word)
    {
        const auto ROW_MAX = board.size();
        const auto COL_MAX = board[0].size();

        // maintain a tracker for all the visited cells
        auto visited = vector<vector<bool>>(ROW_MAX, vector<bool>(COL_MAX, false));

        for (int row = 0; row < ROW_MAX; row++)
        {
            for (int col = 0; col < COL_MAX; col++)
            {
                if (board[row][col] == word[0])
                {
                    visited[row][col] = true;
                    if (solve(board, visited, word, 1, row, col)) return true;
                    visited[row][col] = false;
                }
            }
        }

        return false;
    }
};
