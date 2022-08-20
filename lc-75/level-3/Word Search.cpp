/*
79. Word Search
https://leetcode.com/problems/word-search/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board?


*/


using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

namespace {

    class Solution {
        // DFS
        bool dfs(vector<vector<char>>& board, string word, int i, int j, int start) {
            // base case:
            if (start >= word.size()) {
                return true;
            }

            // corner cases:
            if (i < 0 || j < 0 ||
                i >= board.size() ||
                j >= board[i].size() ||
                word[start] != board[i][j]) {
                return false;
            }

            // mark visited:
            board[i][j] = '#';

            // DFS on all neighbours:
            bool retVal = dfs(board, word, i + 1, j, start + 1) ||
                dfs(board, word, i - 1, j, start + 1) ||
                dfs(board, word, i, j + 1, start + 1) ||
                dfs(board, word, i, j - 1, start + 1);

            // mark unvisited for next iteration
            board[i][j] = word[start];

            // return result
            return retVal;
        }
    public:
        bool exist(vector<vector<char>>& board, string word) {

            int rows = board.size();
            int cols = board[0].size();

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (word[0] == board[i][j]) {
                        /*
                        // perform BFS
                        if (exist(board, word, i, j))
                            return true;
                        */

                        if (dfs(board, word, i, j, 0))
                            return true;
                    }
                }
            }
            return false;
        }

        // BFS
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

                    if (isRange(rows, cols, i, j + 1) &&
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

                    if (isRange(rows, cols, i + 1, j) &&
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
            return i >= 0 && i < rows&& j >= 0 && j < cols;
        }
    };
}