/*
36. Valid Sudoku
https://leetcode.com/problems/valid-sudoku/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:


Input: board =
[{'5','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}]
Output: true
Example 2:

Input: board =
[{'8','3','.','.','7','.','.','.','.'}
,{'6','.','.','1','9','5','.','.','.'}
,{'.','9','8','.','.','.','.','6','.'}
,{'8','.','.','.','6','.','.','.','3'}
,{'4','.','.','8','.','3','.','.','1'}
,{'7','.','.','.','2','.','.','.','6'}
,{'.','6','.','.','.','.','2','8','.'}
,{'.','.','.','4','1','9','.','.','5'}
,{'.','.','.','.','8','.','.','7','9'}]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
	class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] != '.') {
						if (isValid(board, i, j) == false)
							return false;
					}
				}
			}
			return true;
		}

	private:
		bool isValid(vector<vector<char>>& board, int row, int col) {
			char ch = board[row][col];

			// check all rows
			for (int i = 0; i < 9; ++i) {
				if (i != row) {
					if (board[i][col] == ch)
						return false;
				}
			}

			// check all columns
			for (int i = 0; i < 9; ++i) {
				if (i != col) {
					if (board[row][i] == ch)
						return false;
				}
			}

			// check every 3x3 square
			int k = (row / 3) * 3;
			int l = (col / 3) * 3;
			for (int i = k; i < k + 3; i++) {
				for (int j = l; j < l + 3; j++) {
					if (i != row && j != col) {
						if (board[i][j] == ch) {
							return false;
						}
					}
				}
			}
			return true;
		}
	};
} // namespace

void testValidSudoku() {
	vector<vector<char>> board =
	{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
		,{'6', '.', '.', '1', '9', '5', '.', '.', '.'}
		,{'.', '9', '8', '.', '.', '.', '.', '6', '.'}
		,{'8', '.', '.', '.', '6', '.', '.', '.', '3'}
		,{'4', '.', '.', '8', '.', '3', '.', '.', '1'}
		,{'7', '.', '.', '.', '2', '.', '.', '.', '6'}
		,{'.', '6', '.', '.', '.', '.', '2', '8', '.'}
		,{'.', '.', '.', '4', '1', '9', '.', '.', '5'}
		,{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

	cout <<"Valid Sudoku: " << Solution().isValidSudoku(board) << endl;


	board =
	{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
	, { '6','.','.','1','9','5','.','.','.'}
	,{'.','9','8','.','.','.','.','6','.'}
	,{'8','.','.','.','6','.','.','.','3'}
	,{'4','.','.','8','.','3','.','.','1'}
	,{'7','.','.','.','2','.','.','.','6'}
	,{'.','6','.','.','.','.','2','8','.'}
	,{'.','.','.','4','1','9','.','.','5'}
	,{'.','.','.','.','8','.','.','7','9'} };

	cout << "Valid Sudoku: " << Solution().isValidSudoku(board) << endl;
}
