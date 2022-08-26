/*
37. Sudoku Solver
https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.



Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:




Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/


using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        // flatten the matrix and solve
        void solveSudoku(vector<vector<char>>& board) {
            solve(board, 0);
        }

    private:
        bool solve(vector<vector<char>>& board, int s) {
            // last entry
            if (s == 81)
                return true;

            const int i = s / 9;
            const int j = s % 9;

            // recurrsively solve/fill non-empty cells first
            if (board[i][j] != '.')
                return solve(board, s + 1);

            // recurrsively solve/fill empty cell
            for (char ch = '1'; ch <= '9'; ++ch) {
                if (isSafeToFill(board, i, j, ch)) {
                    // try placing number in cell
                    board[i][j] = ch;

                    // see whether we get the answer
                    if (solve(board, s + 1))
                        return true;

                    // backtrack
                    board[i][j] = '.';
                }
            }

            return false;
        }

        bool isSafeToFill(vector<vector<char>>& board, int row, int col, char ch) {
            for (int i = 0; i < 9; ++i) {
                if (!isSafeToFillRow(board, i, col, ch) ||
                    !isSafeToFillColumn(board, row, i, ch) ||
                    !isSafeToFillBox(board, row, col, i, ch)) {
                    return false;
                }
            }

            return true;
        }

        bool isSafeToFillRow(vector<vector<char>>& board, int r, int c, char ch) {
            return board[r][c] != ch;
        }

        bool isSafeToFillColumn(vector<vector<char>>& board, int r, int c, char ch) {
            return board[r][c] != ch;
        }

        bool isSafeToFillBox(vector<vector<char>>& board, int r, int c, int i, char ch) {
            int x = 3 * (r / 3) + i / 3;
            int y = 3 * (c / 3) + i % 3;
            return board[x][y] != ch;
        }
    };
} // namespace