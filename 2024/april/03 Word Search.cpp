// 79. Word Search
// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j< cols; j++) {
                if (dfs(board, word,i,j,0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private:
    bool dfs(
        vector<vector<char>>& board, 
        string word,
        int r,
        int c,
        int start
    ) {
        if (start >= word.size()) {
            return true;
        }

        if (
            r < 0 || c < 0 ||
            r >= board.size() ||
            c >= board[0].size() ||
            word[start] != board[r][c] 
        ) {
            return false;
        }

        board[r][c] = '#';
        bool result = dfs(board, word, r - 1, c, start + 1)
                    || dfs(board, word, r, c - 1, start + 1)
                    || dfs(board, word, r + 1, c, start + 1)
                    || dfs(board, word, r, c + 1, start + 1);
        board[r][c] = word[start];
        return result;
    }
};
